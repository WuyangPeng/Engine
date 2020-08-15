// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 12:24)

// 轴对齐包围盒4D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_DETAIL_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_DETAIL_H

#include "AxesAlignBoundingBox4D.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::AxesAlignBoundingBox4D<T>
	::AxesAlignBoundingBox4D(const Vector4D& minPoint, const Vector4D& maxPoint)
	:m_MinPoint{ minPoint }, m_MaxPoint{ maxPoint }
{
	Recalculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
template <typename RhsType>
Mathematics::AxesAlignBoundingBox4D<T>
	::AxesAlignBoundingBox4D(const AxesAlignBoundingBox4D<RhsType>& aabb)
	:m_MinPoint{ aabb.GetMinPoint() }, m_MaxPoint{ aabb.GetMaxPoint() }
{
	Recalculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename T>
void Mathematics::AxesAlignBoundingBox4D<T>
	::Recalculate()
{
	if (m_MaxPoint.GetXCoordinate() < m_MinPoint.GetXCoordinate())
	{
		MATHEMATICS_ASSERTION_1(false, "输入的最大点和最小点X坐标错误！");

		std::swap(m_MinPoint[0], m_MaxPoint[0]);
	}

	if (m_MaxPoint.GetYCoordinate() < m_MinPoint.GetYCoordinate())
	{
		MATHEMATICS_ASSERTION_1(false, "输入的最大点和最小点Y坐标错误！");

		std::swap(m_MinPoint[1], m_MaxPoint[1]);
	}

	if (m_MaxPoint.GetZCoordinate() < m_MinPoint.GetZCoordinate())
	{
		MATHEMATICS_ASSERTION_1(false, "输入的最大点和最小点Z坐标错误！");

		std::swap(m_MinPoint[2], m_MaxPoint[2]);
	}

	if (m_MaxPoint.GetWCoordinate() < m_MinPoint.GetWCoordinate())
	{
		MATHEMATICS_ASSERTION_1(false, "输入的最大点和最小点W坐标错误！");

		std::swap(m_MinPoint[3], m_MaxPoint[3]);
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::AxesAlignBoundingBox4D<T>
	::IsValid() const noexcept
{
	try{
	if (m_MaxPoint.GetXCoordinate() < m_MinPoint.GetXCoordinate() ||
		m_MaxPoint.GetYCoordinate() < m_MinPoint.GetYCoordinate() ||
		m_MaxPoint.GetZCoordinate() < m_MinPoint.GetZCoordinate() ||
		m_MaxPoint.GetWCoordinate() < m_MinPoint.GetWCoordinate())
	{
		return false;
	}
	else
	{
		return true;
	}
	}
	catch(...)
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
const Mathematics::Vector4D<T> Mathematics::AxesAlignBoundingBox4D<T>
	::GetMinPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinPoint;
}

template <typename T>
const Mathematics::Vector4D<T> Mathematics::AxesAlignBoundingBox4D<T>
	::GetMaxPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxPoint;
}

#endif // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_DETAIL_H