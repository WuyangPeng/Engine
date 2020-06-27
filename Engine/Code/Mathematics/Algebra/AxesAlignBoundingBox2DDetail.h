// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 12:22)

// 轴对齐包围盒2D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_DETAIL_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_DETAIL_H

#include "AxesAlignBoundingBox2D.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::AxesAlignBoundingBox2D<Real>
	::AxesAlignBoundingBox2D(const Vector2D& minPoint, const Vector2D& maxPoint)
	:m_MinPoint{ minPoint }, m_MaxPoint{ maxPoint }
{
	Recalculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
template <typename T1>
Mathematics::AxesAlignBoundingBox2D<Real>
	::AxesAlignBoundingBox2D(const AxesAlignBoundingBox2D<T1>& aabb)
	:m_MinPoint{ aabb.GetMinPoint() }, m_MaxPoint{ aabb.GetMaxPoint() }
{
	Recalculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::AxesAlignBoundingBox2D<Real>
	::AxesAlignBoundingBox2D(Real xMin, Real xMax, Real yMin, Real yMax)
	:m_MinPoint{ xMin,yMin }, m_MaxPoint{ xMax, yMax }
{
	Recalculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::AxesAlignBoundingBox2D<Real>
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
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::AxesAlignBoundingBox2D<Real>
	::IsValid() const noexcept
{
	if (m_MaxPoint.GetXCoordinate() < m_MinPoint.GetXCoordinate() || m_MaxPoint.GetYCoordinate() < m_MinPoint.GetYCoordinate())
		return false;
	else
		return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::AxesAlignBoundingBox2D<Real>
	::GetMinPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinPoint;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::AxesAlignBoundingBox2D<Real>
	::GetMaxPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxPoint;
} 

template <typename Real>
typename const Mathematics::AxesAlignBoundingBox2D<Real>::Vector2D Mathematics::AxesAlignBoundingBox2D<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	Vector2D center{ (m_MinPoint.GetXCoordinate() + m_MaxPoint.GetXCoordinate()) / Math::sm_Two,
					 (m_MinPoint.GetYCoordinate() + m_MaxPoint.GetYCoordinate()) / Math::sm_Two };

	return center;
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2D<Real>
	::GetExtentX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return (m_MaxPoint.GetXCoordinate() - m_MinPoint.GetXCoordinate()) / Math::sm_Two;
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2D<Real>
	::GetExtentY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return (m_MaxPoint.GetYCoordinate() - m_MinPoint.GetYCoordinate()) / Math::sm_Two;
}


template <typename Real>
bool Mathematics
	::HasXOverlap(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs)
{
	return (lhs.GetMinPoint().GetXCoordinate() <= rhs.GetMaxPoint().GetXCoordinate()) &&
		   (rhs.GetMinPoint().GetXCoordinate() <= lhs.GetMaxPoint().GetXCoordinate());
}

template <typename Real>
bool Mathematics
	::HasYOverlap(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs)
{
	return (lhs.GetMinPoint().GetYCoordinate() <= rhs.GetMaxPoint().GetYCoordinate()) &&
		   (rhs.GetMinPoint().GetYCoordinate() <= lhs.GetMaxPoint().GetYCoordinate());
}

template <typename Real>
bool Mathematics
	::IsIntersection(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs)
{
	for (auto i = 0; i < 2; ++i)
	{
		if ((lhs.GetMaxPoint()[i] < rhs.GetMinPoint()[i]) ||
			(rhs.GetMaxPoint()[i] < lhs.GetMinPoint()[i]))
		{
			return false;
		}
	}

	return true;
}


template <typename Real>
const Mathematics::AxesAlignBoundingBox2D<Real> Mathematics
	::FindIntersection(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs)
{
	if (!IsIntersection(lhs, rhs))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("包围盒不相交！"));
	}

	Vector2D<Real> minPoint;
	Vector2D<Real> maxPoint;

	for (auto i = 0; i < 2; ++i)
	{
		if (lhs.GetMaxPoint()[i] <= rhs.GetMaxPoint()[i])
		{
			maxPoint[i] = lhs.GetMaxPoint()[i];
		}
		else
		{
			maxPoint[i] = rhs.GetMaxPoint()[i];
		}

		if (lhs.GetMinPoint()[i] <= rhs.GetMinPoint()[i])
		{
			minPoint[i] = rhs.GetMinPoint()[i];
		}
		else
		{
			minPoint[i] = lhs.GetMinPoint()[i];
		}
	}

	return AxesAlignBoundingBox2D<Real>{ minPoint, maxPoint };
}

#endif // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_DETAIL_H