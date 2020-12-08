/*****************************************************************//**
 * \file   Polynomial.h
 * \brief  多项式插值的头文件
 *
 * \author pc-1
 * \date   December 2020
 *********************************************************************/


#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

//多项式的hpp
#include "Poly.hpp"

/**
 * .
 * 
 * \param data			用于插值的数据
 * \param Poly			用于输出的多项式的系数
 * \param nTimes		需要拟合的多项式的最高次数
 * \return		true	拟合成功
 * \return		false	拟合失败，失败原因各有不同
 */
template<typename _T1, typename _T2>
bool PolynomialFit(std::vector<_T1> &data, std::vector<_T2> &Poly, int nTimes = 3)
{


	return true;
}

template<typename _T>
bool Lagrange(std::vector<_T> &data, polynomial poly, int nTimes = 3)
{
	//检查
	if ((data.size() - 1) != nTimes)
	{
		std::cout<<"Lagrange input data size doesn't match need times! ((data.size()-1)!=Times)"
	}
}












#endif // !POLYNOMIAL_H
