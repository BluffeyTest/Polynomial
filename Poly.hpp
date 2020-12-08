/*****************************************************************//**
 * \file   Poly.hpp
 * \brief  多项式基本文件
 * 
 * \author pc-1
 * \date   December 2020
 *********************************************************************/
#pragma once

#ifndef POLY_HPP
#define POLY_HPP

#include<iostream>

 //polynomial.h
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

/**
 * 单项式.
 */
typedef struct stMonomial
{
    double  dCoefficient;///<系数
    int     nRadix;///<次数

    stMonomial(double _d,int _n):dCoefficient(_d),nRadix(_n){}

    //次数相同的单项式相加
    inline stMonomial operator +(const stMonomial &stM) const
    {
        return stMonomial(this->dCoefficient + stM.dCoefficient, this->dCoefficient);
    }
}Term;



class polynomial
{
private:
    /*std::vector<double> coefficient;
    std::vector<int> radix;*/
    std::vector<Term>   m_Data;
public:
    polynomial(){}
    polynomial(std::vector<Term>   &Data) 
    {
        std::sort(Data.begin(), Data.end(), [](const Term &t1, const Term &t2) { return t1.nRadix > t2.nRadix; });
        m_Data = Data;
    }
    polynomial(const polynomial &poly) { *this = poly; }
    ~polynomial() {}
    void sort(std::vector<Term> &Data);
    friend polynomial operator+(const polynomial &poly1, const polynomial &poly2);
    friend polynomial operator-(const polynomial &poly1, const polynomial &poly2);
    polynomial &operator+=(const polynomial &poly) { *this = *this + poly; return *this; }
    polynomial &operator-=(const polynomial &poly) { *this = *this - poly; return *this; }
    friend polynomial operator*(const polynomial &poly1, const polynomial &poly2);
    friend std::istream &operator>>(std::istream &is, polynomial &poly);
    friend std::ostream &operator<<(std::ostream &os, const polynomial &poly);

    friend polynomial &operator<<(polynomial &poly,Term t);
};

void polynomial::sort(std::vector<Term> &Data)
{
    std::sort(Data.begin(), Data.end(), [](const Term &t1, const Term &t2) { return t1.nRadix > t2.nRadix; });
}

polynomial operator+(const polynomial &poly1, const polynomial &poly2)
{
    polynomial cPolySum;

    int i = 0, j = 0;
    while (i < poly1.m_Data.size() || j < poly2.m_Data.size())
    {
        //only poly1
        if (i < poly1.m_Data.size() && j == poly2.m_Data.size())
        {
            cPolySum.m_Data.push_back(poly1.m_Data[i]);
            i++;
        }
        //only poly2
        else if (j < poly2.m_Data.size() && i == poly1.m_Data.size())
        {
            cPolySum.m_Data.push_back(poly2.m_Data[j]);
            j++;
        }
        //the radix of poly1 greater than poly2
        else if (poly1.m_Data[i].nRadix > poly2.m_Data[j].nRadix)
        {
            cPolySum.m_Data.push_back(poly1.m_Data[i]);
            i++;
        }
        //the radix of poly1 smaller than poly2
        else if (poly1.m_Data[i].nRadix < poly2.m_Data[j].nRadix)
        {
            cPolySum.m_Data.push_back(poly2.m_Data[j]);
            j++;
        }
        //the radix of poly1 equal to poly2
        else
        {
            if (poly1.m_Data[i].dCoefficient + poly2.m_Data[j].dCoefficient != 0)
            {
                cPolySum.m_Data.push_back(poly1.m_Data[i] + poly2.m_Data[j]);
            }
            i++;
            j++;
        }
    }

    return cPolySum;
}

polynomial operator-(const polynomial &poly1, const polynomial &poly2)
{
    polynomial negativePoly;

    negativePoly = poly2;
    for (int i = 0; i < negativePoly.m_Data.size(); i++)
        negativePoly.m_Data[i].dCoefficient = -negativePoly.m_Data[i].dCoefficient;

    return poly1 + negativePoly;
}

polynomial operator*(const polynomial &poly1, const polynomial &poly2)
{
    polynomial mul;

    int i = 0;
    while (i < poly2.m_Data.size())
    {
        polynomial part = poly1;
        double coefficient = poly2.m_Data[i].dCoefficient;
        int radix = poly2.m_Data[i].nRadix;

        for (int j = 0; j < part.m_Data.size(); j++)
        {
            part.m_Data[j].nRadix += radix;
            part.m_Data[j].dCoefficient *= coefficient;
        }
        mul += part;
        i++;
    }

    return mul;
}

std::istream &operator>>(std::istream &is, polynomial &poly)
{
    int k;
    is >> k;
    for (int i = 0; i < k; i++)
    {
        double tmpcoe;
        int tmprad;
        is >> tmprad >> tmpcoe;
        poly.m_Data.push_back(Term(tmprad, tmpcoe));
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, const polynomial &poly)
{
    os << poly.m_Data.size();
    if (poly.m_Data.size() != 0)
        std::cout << " ";
    for (int i = 0; i < poly.m_Data.size(); i++)
    {
        os << poly.m_Data[i].nRadix << " " << std::fixed << std::setprecision(1) << poly.m_Data[i].dCoefficient;
        if (i != poly.m_Data.size() - 1)
            os << " ";
    }

    return os;
}

polynomial &operator<<(polynomial &poly, Term t)
{
    poly.m_Data.push_back(t);
    return poly;
}

#endif //!POLY_HPP



