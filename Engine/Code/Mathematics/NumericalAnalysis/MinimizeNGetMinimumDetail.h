// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 14:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H

#include "MinimizeNGetMinimum.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename UserDataType>
Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::MinimizeNGetMinimum(int dimensions, const RealVector& initial, Function function,
						  const UserDataType* userData, const RealVector& begin, const RealVector& end)
	:m_Dimensions{ dimensions },
	 // ��ʼ������Ϊ��׼ŷ����û�������
	 m_DirectionStorage(dimensions * (static_cast<size_t>(dimensions) + 1)),
	 m_Direction(static_cast<size_t>(dimensions) + 1, nullptr), m_DirectionConjugate{ nullptr }, m_DirectionCurrent{ nullptr },
	 m_Save(initial), m_Function{ function }, m_UserData{ userData },
	 m_MinimizeNData{ initial, m_Function(initial, m_UserData) }, m_Begin(begin), m_End(end)
{
	for (auto i = 0; i <= dimensions; ++i)
	{
		m_Direction[i] = &m_DirectionStorage[i * static_cast<size_t>(dimensions)];
	}

	m_DirectionConjugate = m_Direction[dimensions];

	for (auto i = 0; i < dimensions; ++i)
	{
		m_Direction[i][i] = static_cast<Real>(1);
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::IsValid() const noexcept
{
	if (0 < m_Dimensions)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT  

template <typename Real, typename UserDataType>
int Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::GetDimensions() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Dimensions;
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::CalculateLineArg(int index, Real value) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_Dimensions, "��������");

	return m_MinimizeNData.GetMinLocation(index) + value * m_DirectionCurrent[index];
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::GetFunctionResult(const RealVector& lineArg) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return	m_Function(lineArg, m_UserData);
}

template <typename Real, typename UserDataType>
typename const Mathematics::MinimizeNGetMinimum<Real, UserDataType>::MinimizeNData&	Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::GetMinimizeNData() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinimizeNData;
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::FindEachDirection(int index, int maxLevel, int maxBracket)
{
	m_DirectionCurrent = m_Direction[index];
	Real beginResult = Math<Real>::sm_Zero;
	Real endResult = Math<Real>::sm_Zero;
	ComputeDomain(m_Begin, m_End, &beginResult, &endResult);

	// �� 1D �����ص�
	Minimize1 minimizer{ LineFunction, maxLevel, maxBracket, this };

	auto minimizerData = minimizer.GetMinimum(beginResult, endResult, Math<Real>::sm_Zero);

	auto minLocation = minimizerData.GetMinLocation();

	m_MinimizeNData.Set(minimizerData.GetMinValue(), minLocation, m_DirectionCurrent);
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::EstimateUnitLengthConjugateDirection()
{
	auto length = Math<Real>::sm_Zero;
	for (auto i = 0; i < m_Dimensions; ++i)
	{
		m_DirectionConjugate[i] = m_MinimizeNData.GetMinLocation(i) - m_Save[i];
		length += m_DirectionConjugate[i] * m_DirectionConjugate[i];
	}

	return Math<Real>::Sqrt(length);
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>
::MinimizeConjugateDirection(Real length, int maxLevel, int maxBracket)
{
	for (auto i = 0; i < m_Dimensions; ++i)
	{
		m_DirectionConjugate[i] /= length;
	}

	auto beginResult = Math<Real>::sm_Zero;
	auto endResult = Math<Real>::sm_Zero;

	// ��С�������
	m_DirectionConjugate = m_DirectionConjugate;
	ComputeDomain(m_Begin, m_End, &beginResult, &endResult);

	Minimize1 minimizer{ LineFunction, maxLevel, maxBracket, this };
	auto minimizerData = minimizer.GetMinimum(beginResult, endResult, Math<Real>::sm_Zero);

	m_MinimizeNData.Set(minimizerData.GetMinValue(), minimizerData.GetMinLocation(), m_DirectionCurrent);

	// ѭ�����򣬲���ӹ���򵽼���
	m_DirectionConjugate = m_Direction[0];
	for (auto i = 0; i < m_Dimensions; ++i)
	{
		auto temp = i + 1;
		m_Direction[i] = m_Direction[temp];
	}

	// �����´εĲ�����
	m_Save = m_MinimizeNData.GetMinLocation();
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::ComputeDomain(const RealVector& begin, const RealVector& end, Real* beginResult, Real* endResult)
{
	*beginResult = -Math<Real>::sm_MaxReal;
	*endResult = +Math<Real>::sm_MaxReal;

	for (auto i = 0; i < m_Dimensions; ++i)
	{
		auto beginMinus = begin[i] - m_MinimizeNData.GetMinLocation(i);
		auto endMinus = end[i] - m_MinimizeNData.GetMinLocation(i);

		if (Math<Real>::sm_Zero < m_DirectionCurrent[i])
		{
			// ��Ч�ļ����[b0,b1]��
			beginMinus /= m_DirectionCurrent[i];
			if (*beginResult < beginMinus)
			{
				*beginResult = beginMinus;
			}
			endMinus /= m_DirectionCurrent[i];
			if (endMinus < *endResult)
			{
				*endResult = endMinus;
			}
		}
		else if (m_DirectionCurrent[i] < Math<Real>::sm_Zero)
		{
			// ��Ч�ļ����[b1,b0]��
			beginMinus /= m_DirectionCurrent[i];
			if (beginMinus < *endResult)
			{
				*endResult = beginMinus;
			}
			endMinus /= m_DirectionCurrent[i];
			if (*beginResult < endMinus)
			{
				*beginResult = endMinus;
			}
		}
	}

	// ���ֲ���������ֵ����Ϊ�㡣
	if (Math<Real>::sm_Zero < *beginResult)
	{
		*beginResult = Math<Real>::sm_Zero;
	}
	if (*endResult < Math<Real>::sm_Zero)
	{
		*endResult = Math<Real>::sm_Zero;
	}
}

// static
template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>
	::LineFunction(Real value, const MinimizeNGetMinimum* userData)
{
	auto dimensions = userData->GetDimensions();

	RealVector lineArg;

	for (auto index = 0; index < dimensions; ++index)
	{
		lineArg.push_back(userData->CalculateLineArg(index, value));
	}

	return userData->GetFunctionResult(lineArg);
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H

