// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 19:19)

// 轴对齐包围盒3D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_DETAIL_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_DETAIL_H

#include "AxesAlignBoundingBox3D.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::AxesAlignBoundingBox3D<Real>
	::AxesAlignBoundingBox3D(const Vector3D& minPoint,const Vector3D& maxPoint)
	:m_MinPoint{ minPoint }, m_MaxPoint{ maxPoint }
{	
	Recalculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
template <typename RhsType>
Mathematics::AxesAlignBoundingBox3D<Real>
	::AxesAlignBoundingBox3D(const AxesAlignBoundingBox3D<RhsType>& aabb)
	:m_MinPoint{ aabb.GetMinPoint() }, m_MaxPoint{ aabb.GetMaxPoint() }
{	
	Recalculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


template <typename Real>
Mathematics::AxesAlignBoundingBox3D<Real>
	::AxesAlignBoundingBox3D( Real xMin, Real xMax, Real yMin, Real yMax,Real zMin, Real zMax )
	:m_MinPoint{ xMin,yMin,zMin }, m_MaxPoint{ xMax, yMax, zMax }
{	
	Recalculate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::AxesAlignBoundingBox3D<Real>
	::Recalculate()
{
	if(m_MaxPoint.GetXCoordinate() < m_MinPoint.GetXCoordinate())
	{
		MATHEMATICS_ASSERTION_1(false,"输入的最大点和最小点X坐标错误！");

		std::swap(m_MinPoint[0],m_MaxPoint[0]);
	}

	if(m_MaxPoint.GetYCoordinate() < m_MinPoint.GetYCoordinate())
	{
		MATHEMATICS_ASSERTION_1(false,"输入的最大点和最小点Y坐标错误！");

		std::swap(m_MinPoint[1],m_MaxPoint[1]);
	}

	if(m_MaxPoint.GetZCoordinate() < m_MinPoint.GetZCoordinate())
	{
		MATHEMATICS_ASSERTION_1(false,"输入的最大点和最小点Z坐标错误！");

		std::swap(m_MinPoint[2],m_MaxPoint[2]);
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::AxesAlignBoundingBox3D<Real>
	::IsValid() const noexcept
{
	if (m_MaxPoint.GetXCoordinate() < m_MinPoint.GetXCoordinate() ||
		m_MaxPoint.GetYCoordinate() < m_MinPoint.GetYCoordinate() ||
		m_MaxPoint.GetZCoordinate() < m_MinPoint.GetZCoordinate())
	{
		return false;
	}	   
	else
	{
		return true;
	}		
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::AxesAlignBoundingBox3D<Real>
	::GetMinPoint() const 
{ 
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinPoint;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::AxesAlignBoundingBox3D<Real>
	::GetMaxPoint() const 
{ 
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxPoint;
}


template <typename Real>
typename const Mathematics::AxesAlignBoundingBox3D<Real>::Vector3D Mathematics::AxesAlignBoundingBox3D<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return (m_MaxPoint + m_MinPoint) / static_cast<Real>(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox3D<Real>
	::GetExtentX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return (m_MaxPoint.GetXCoordinate() - m_MinPoint.GetXCoordinate()) / static_cast<Real>(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox3D<Real>
	::GetExtentY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return (m_MaxPoint.GetYCoordinate() - m_MinPoint.GetYCoordinate()) / static_cast<Real>(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox3D<Real>
	::GetExtentZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return (m_MaxPoint.GetZCoordinate() - m_MinPoint.GetZCoordinate()) / static_cast<Real>(2);
}

template <typename Real>
bool Mathematics
	::HasXOverlap( const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs )
{
	return (lhs.GetMinPoint().GetXCoordinate() <= rhs.GetMaxPoint().GetXCoordinate()) &&
		   (rhs.GetMinPoint().GetXCoordinate() <= lhs.GetMaxPoint().GetXCoordinate());		
}

template <typename Real>
bool Mathematics
	::HasYOverlap( const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs )
{
	return (lhs.GetMinPoint().GetYCoordinate() <= rhs.GetMaxPoint().GetYCoordinate()) &&
		   (rhs.GetMinPoint().GetYCoordinate() <= lhs.GetMaxPoint().GetYCoordinate());	
}

template <typename Real>
bool Mathematics
	::HasZOverlap( const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs )
{
	return (lhs.GetMinPoint().GetZCoordinate() <= rhs.GetMaxPoint().GetZCoordinate()) &&
		   (rhs.GetMinPoint().GetZCoordinate() <= lhs.GetMaxPoint().GetZCoordinate());	
}

template <typename Real>
bool Mathematics
	::IsIntersection( const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs )
{
	for (auto i = 0; i < 3; ++i)
	{
		if((lhs.GetMaxPoint()[i] < rhs.GetMinPoint()[i]) ||
		   (rhs.GetMaxPoint()[i] < lhs.GetMinPoint()[i])) 
		{
			return false;
		}
	}

	return true;
}


template <typename Real>
const Mathematics::AxesAlignBoundingBox3D<Real>
	Mathematics::FindIntersection( const AxesAlignBoundingBox3D<Real>& lhs,const AxesAlignBoundingBox3D<Real>& rhs )
{
	if(!IsIntersection(lhs,rhs))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("包围盒不相交！"));
	}

	Vector3D<Real> minPoint;
	Vector3D<Real> maxPoint;

	for (auto i = 0; i < 3; ++i)
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

	return AxesAlignBoundingBox3D<Real>{ minPoint, maxPoint };
}

#endif // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_DETAIL_H