/*****************************************************************//**
 * \file   Polynomial.h
 * \brief  ����ʽ��ֵ��ͷ�ļ�
 *
 * \author pc-1
 * \date   December 2020
 *********************************************************************/


#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

//����ʽ��hpp
#include "Poly.hpp"

/**
 * .
 * 
 * \param data			���ڲ�ֵ������
 * \param Poly			��������Ķ���ʽ��ϵ��
 * \param nTimes		��Ҫ��ϵĶ���ʽ����ߴ���
 * \return		true	��ϳɹ�
 * \return		false	���ʧ�ܣ�ʧ��ԭ����в�ͬ
 */
template<typename _T1, typename _T2>
bool PolynomialFit(std::vector<_T1> &data, std::vector<_T2> &Poly, int nTimes = 3)
{


	return true;
}

template<typename _T>
bool Lagrange(std::vector<_T> &data, polynomial poly, int nTimes = 3)
{
	//���
	if ((data.size() - 1) != nTimes)
	{
		std::cout<<"Lagrange input data size doesn't match need times! ((data.size()-1)!=Times)"
	}
}












#endif // !POLYNOMIAL_H
