// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 14:49)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DETAIL_H

#include "Minimize1.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::Minimize1<Real, UserDataType>
	::Minimize1(Function function, int maxLevel, int maxBracket, const UserDataType* userData)
	:m_Function{ function }, m_MaxLevel{ maxLevel }, m_MaxBracket{ maxBracket }, m_UserData{ userData }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename UserDataType>
Mathematics::Minimize1<Real, UserDataType>
	::~Minimize1()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::Minimize1<Real, UserDataType>
	::IsValid() const noexcept
{
	if (m_Function != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>
	::SetUserData(const UserDataType* userData)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_UserData = userData;
}

template <typename Real, typename UserDataType>
typename const UserDataType* Mathematics::Minimize1<Real, UserDataType>
	::GetUserData() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_UserData;
}

template <typename Real, typename UserDataType>
typename const Mathematics::Minimize1<Real, UserDataType>::Minimize1Data Mathematics::Minimize1<Real, UserDataType>
	::GetMinimum(Real begin, Real end, Real initial) const
{
	MATHEMATICS_CLASS_IS_VALID_1;

	MATHEMATICS_ASSERTION_1(begin <= initial && initial <= end, "无效的初始t值\n");

	Minimize1Data minimize1Data;

	auto beginFunction = m_Function(begin, m_UserData);
	minimize1Data.CompareData(begin, beginFunction);

	auto initialFunction = m_Function(initial, m_UserData);
	minimize1Data.CompareData(initial, initialFunction);

	auto endFunction = m_Function(end, m_UserData);
	minimize1Data.CompareData(end, endFunction);

	CompareMinimum(begin, beginFunction, initial, initialFunction, end, endFunction, m_MaxLevel, minimize1Data);

	return minimize1Data;
}

template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>
	::CompareMinimum(Real begin, Real beginFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const
{
	if (level-- == 0)
	{
		return;
	}

	auto middle = static_cast<Real>(0.5) * (begin + end);
	auto middleFunction = m_Function(middle, m_UserData);
	minimize1Data.CompareData(middle, middleFunction);

	if (Math<Real>::GetValue(0) < beginFunction - (static_cast<Real>(2) * middleFunction + endFunction))
	{
		// 二次拟合具有中点正二阶导数。
		if (beginFunction < endFunction)
		{
			if (beginFunction <= middleFunction)
			{
				// 增加，重复在 [begin,middle]。
				CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
			}
			else
			{
				// 不单调，有一个括号
				CompareBracketedMinimum(begin, beginFunction, middle, middleFunction, end, endFunction, level, minimize1Data);
			}
		}
		else if (endFunction < beginFunction)
		{
			if (endFunction <= middleFunction)
			{
				// 减少, 重复在 [middle,end].
				CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
			}
			else
			{
				// 不单调，有一个括号
				CompareBracketedMinimum(begin, beginFunction, middle, middleFunction, end, endFunction, level, minimize1Data);
			}
		}
		else
		{
			// 常数，重复在[begin,middle] 和  [middle,end]。
			CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
			CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
		}
	}
	else
	{
		// 二次拟合具有中点非正数二阶导数。

		if (beginFunction < endFunction)
		{
			// 重复在  [begin,middle]。
			CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
		}
		else if (endFunction < beginFunction)
		{
			// 重复在 [middle,end]。
			CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
		}
		else
		{
			// 重复在[begin,middle] 和  [middle,end]。
			CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
			CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
		}
	}
}

// private
template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>
	::CompareMinimum(Real begin, Real beginFunction, Real middle, Real middleFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const
{
	if (level-- == 0)
	{
		return;
	}

	if ((middle - begin) * (middleFunction - endFunction) < (end - middle) * (beginFunction - middleFunction))
	{
		// 二次拟合具有中点正二阶导数。
		if (beginFunction < endFunction)
		{
			if (beginFunction <= middleFunction)
			{
				// 增加，重复在[begin,middle]。
				CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
			}
			else
			{
				// 不单调，有一个括号
				CompareBracketedMinimum(begin, beginFunction, middle, middleFunction, end, endFunction, level, minimize1Data);
			}
		}
		else if (endFunction < beginFunction)
		{
			if (endFunction <= middleFunction)
			{
				// 减少, 重复在[middle,end].
				CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
			}
			else
			{
				// 不单调，有一个括号
				CompareBracketedMinimum(begin, beginFunction, middle, middleFunction, end, endFunction, level, minimize1Data);
			}
		}
		else
		{
			// 常数，重复在[begin,middle] 和 [middle,end]。
			CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
			CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
		}
	}
	else
	{
		// 二次拟合具有中点非正数二阶导数。
		if (beginFunction < endFunction)
		{
			// 重复在[begin,middle] .
			CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
		}
		else if (endFunction < beginFunction)
		{
			// 重复在 [middle,end].
			CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
		}
		else
		{
			// 重复在 [begin,middle]  和[middle,end]
			CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
			CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
		}
	}
}

template <typename Real, typename UserDataType>
void Mathematics::Minimize1<Real, UserDataType>
	::CompareBracketedMinimum(Real begin, Real beginFunction, Real middle, Real middleFunction, Real end, Real endFunction, int level, Minimize1Data& minimize1Data) const
{
	for (auto i = 0; i < m_MaxBracket; ++i)
	{
		// 更新最小值。
		minimize1Data.CompareData(middle, middleFunction);

		// 测试收敛。

		if (Math<Real>::FAbs(end - begin) <= static_cast<Real>(2) * Math<Real>::GetZeroTolerance() * Math<Real>::FAbs(middle) + Math<Real>::sm_Epsilon)
		{
			break;
		}

		// 插值计算抛物线的顶点。
		auto beginMinusMiddle = begin - middle;
		auto endMinusMiddle = end - middle;
		auto beginFunctionMinusMiddleFunction = beginFunction - middleFunction;
		auto endFunctionMinusMiddleFunction = endFunction - middleFunction;
		auto firstProduct = beginMinusMiddle * endFunctionMinusMiddleFunction;
		auto secondProduct = endMinusMiddle * beginFunctionMinusMiddleFunction;
		auto denom = secondProduct - firstProduct;
		if (Math<Real>::FAbs(denom) < Math<Real>::sm_Epsilon)
		{
			return;
		}

		auto vertex = static_cast<Real>(0.5) * (endMinusMiddle * secondProduct - beginMinusMiddle * firstProduct) / denom + middle;

		MATHEMATICS_ASSERTION_1(begin <= vertex && vertex <= end, "顶点不在区间\n");

		auto vertexFunction = m_Function(vertex, m_UserData);
		minimize1Data.CompareData(vertex, vertexFunction);

		if (vertex < middle)
		{
			if (vertexFunction < middleFunction)
			{
				end = middle;
				endFunction = middleFunction;
				middle = vertex;
				middleFunction = vertexFunction;
			}
			else
			{
				begin = vertex;
				beginFunction = vertexFunction;
			}
		}
		else if (middle < vertex)
		{
			if (vertexFunction < middleFunction)
			{
				begin = middle;
				beginFunction = middleFunction;
				middle = vertex;
				middleFunction = vertexFunction;
			}
			else
			{
				end = vertex;
				endFunction = vertexFunction;
			}
		}
		else
		{
			// 抛物线的顶点为中间的采样点。
			CompareMinimum(begin, beginFunction, middle, middleFunction, level, minimize1Data);
			CompareMinimum(middle, middleFunction, end, endFunction, level, minimize1Data);
		}
	}
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZE1_DETAIL_H


