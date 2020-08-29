// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 15:50)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_DETAIL_H

#include "Vector3DInformation.h"
#include "AxesAlignBoundingBox3D.h"
#include "Vector3DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector3DInformation<Real>
	::Vector3DInformation(const std::vector<Vector3D>& points, Real epsilon)
	:m_Points{ points }, m_Epsilon{ epsilon }, m_Dimension{ -1 }, m_AABBPtr{}, m_MaxRange{ Math::GetValue(0) }, m_Origin{}, m_DirectionX{},
	 m_DirectionY{}, m_DirectionZ{}, m_MinExtreme{ -1 }, m_MaxExtreme{ -1 }, m_PerpendicularExtreme{ -1 }, m_TetrahedronExtreme{ -1 }, m_ExtremeCCW{ false }
{
	MATHEMATICS_ASSERTION_0(0 < m_Points.size() && Math::GetValue(0) <= m_Epsilon, "无效输入在Vector3DInformation\n");

	m_IndexMin[0] = 0;
	m_IndexMin[1] = 0;
	m_IndexMin[2] = 0;
	m_IndexMax[0] = 0;
	m_IndexMax[1] = 0;
	m_IndexMax[2] = 0;

	Init();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Vector3DInformation<Real>
	::Init()
{
	// 计算输入点的轴对齐包围盒。跟踪“points”当前最小值和最大值的索引。
	ComputeAxisAlignedBoundingBox();

	// 确定边界框的最大范围。
	DetermineMaximumRange();

	// 原点是最小x值的点或最小y值或最小z值的点。
	m_Origin = m_Points[m_MinExtreme];

	// 测试点集是否是（几乎）一个点或一个线段或一个平面多边形
	if (!(TestPointSetIsNearlyAPoint() || TestPointSetIsNearlyALineSegment() || TestPointSetIsNearlyAPlanarPolygon()))
	{
		m_Dimension = 3;
	}
}

// private
template <typename Real>
void Mathematics::Vector3DInformation<Real>
	::ComputeAxisAlignedBoundingBox()
{
	auto min = m_Points[0];
	auto max = min;

	for (auto pointsIndex = 1u; pointsIndex < m_Points.size(); ++pointsIndex)
	{
		const auto& eachVector = m_Points[pointsIndex];

		for (auto directionIndex = 0u; directionIndex < 3; ++directionIndex)
		{
			if (eachVector[directionIndex] < min[directionIndex])
			{
				min[directionIndex] = eachVector[directionIndex];
				m_IndexMin[directionIndex] = pointsIndex;
			}
			else if (max[directionIndex] < m_Points[pointsIndex][directionIndex])
			{
				max[directionIndex] = eachVector[directionIndex];
				m_IndexMax[directionIndex] = pointsIndex;
			}
		}
	}

	m_AABBPtr = std::make_shared<AxesAlignBoundingBox3D>(min, max);
}

// private
template <typename Real>
void Mathematics::Vector3DInformation<Real>
	::DetermineMaximumRange()
{
	auto maxPoint = m_AABBPtr->GetMaxPoint();
	auto minPoint = m_AABBPtr->GetMinPoint();

	m_MaxRange = maxPoint[0] - minPoint[0];
	m_MinExtreme = m_IndexMin[0];
	m_MaxExtreme = m_IndexMax[0];

	for (auto i = 1; i < 3; ++i)
	{
		auto range = maxPoint[i] - minPoint[i];

		if (m_MaxRange < range)
		{
			m_MaxRange = range;
			m_MinExtreme = m_IndexMin[i];
			m_MaxExtreme = m_IndexMax[i];
		}
	}
}

// private
template <typename Real>
bool Mathematics::Vector3DInformation<Real>
	::TestPointSetIsNearlyAPoint()
{
	if (m_MaxRange < m_Epsilon)
	{
		m_Dimension = 0;

		m_MaxExtreme = m_MinExtreme;
		m_PerpendicularExtreme = m_MinExtreme;
		m_PerpendicularExtreme = m_MinExtreme;

		m_DirectionX[0] = Math::GetValue(0);
		m_DirectionY[1] = Math::GetValue(0);
		m_DirectionY[2] = Math::GetValue(0);

		return true;
	}

	return false;
}

template <typename Real>
bool Mathematics::Vector3DInformation<Real>
	::TestPointSetIsNearlyALineSegment()
{
	m_DirectionX = m_Points[m_MaxExtreme] - m_Origin;
	m_DirectionX.Normalize(m_Epsilon);

	auto maxDistance = Math::GetValue(0);
	m_PerpendicularExtreme = m_MinExtreme;
	for (auto index = 0u; index < m_Points.size(); ++index)
	{
		auto difference = m_Points[index] - m_Origin;
		auto dot = Vector3DTools::DotProduct(m_DirectionX, difference);
		auto proj = difference - dot * m_DirectionX;
		auto distance = Vector3DTools::VectorMagnitude(proj);

		if (maxDistance < distance)
		{
			maxDistance = distance;
			m_PerpendicularExtreme = index;
		}
	}

	if (maxDistance < m_Epsilon * m_MaxRange)
	{
		m_Dimension = 1;
		m_PerpendicularExtreme = m_MaxExtreme;
		m_TetrahedronExtreme = m_MaxExtreme;

		return true;
	}

	return false;
}

template <typename Real>
bool Mathematics::Vector3DInformation<Real>
	::TestPointSetIsNearlyAPlanarPolygon()
{
	m_DirectionY = m_Points[m_PerpendicularExtreme] - m_Origin;
	auto dot = Vector3DTools::DotProduct(m_DirectionX, m_DirectionY);
	m_DirectionY -= dot * m_DirectionX;
	m_DirectionY.Normalize(m_Epsilon);
	m_DirectionZ = Vector3DTools::CrossProduct(m_DirectionX, m_DirectionY);
	auto maxDistance = Math::GetValue(0);
	auto maxSign = NumericalValueSymbol::Zero;
	m_TetrahedronExtreme = m_MinExtreme;

	for (auto index = 0u; index < m_Points.size(); ++index)
	{
		auto diff = m_Points[index] - m_Origin;
		auto distance = Vector3DTools::DotProduct(m_DirectionZ, diff);
		auto sign = Math::Sign(distance);
		distance = Math::FAbs(distance);
		if (maxDistance < distance)
		{
			maxDistance = distance;
			maxSign = sign;
			m_TetrahedronExtreme = index;
		}
	}

	if (maxDistance < m_Epsilon * m_MaxRange)
	{
		m_Dimension = 2;
		m_TetrahedronExtreme = m_PerpendicularExtreme;
		return true;
	}

	m_ExtremeCCW = (maxSign == NumericalValueSymbol::Positive);

	return false;
}


#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector3DInformation<Real>
	::IsValid() const noexcept
{
	int pointsSize = static_cast<int>(m_Points.size());

	if (0 <= m_Dimension && m_Dimension <= 3 && m_AABBPtr != nullptr && 0 <= m_MaxRange &&
		m_MinExtreme < pointsSize && m_MaxExtreme < pointsSize && m_PerpendicularExtreme < pointsSize && m_TetrahedronExtreme < pointsSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Vector3DInformation<Real>
	::GetDimension() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Dimension;
}

template <typename Real>
typename Mathematics::Vector3DInformation<Real>::AxesAlignBoundingBox3DPtr Mathematics::Vector3DInformation<Real>
	::GetAABBPtr() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_AABBPtr;
}

template <typename Real>
Real Mathematics::Vector3DInformation<Real>
	::GetMaxRange() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxRange;
}

template <typename Real>
typename const Mathematics::Vector3DInformation<Real>::Vector3D Mathematics::Vector3DInformation<Real>
	::GetOrigin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Origin;
}

template <typename Real>
typename const Mathematics::Vector3DInformation<Real>::Vector3D Mathematics::Vector3DInformation<Real>
	::GetDirectionX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionX;
}

template <typename Real>
typename const Mathematics::Vector3DInformation<Real>::Vector3D Mathematics::Vector3DInformation<Real>
	::GetDirectionY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionY;
}

template <typename Real>
typename const Mathematics::Vector3DInformation<Real>::Vector3D Mathematics::Vector3DInformation<Real>
	::GetDirectionZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionZ;
}

template <typename Real>
typename const Mathematics::Vector3DInformation<Real>::Vector3D Mathematics::Vector3DInformation<Real>
	::GetMinExtreme() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Points[m_MinExtreme];
}

template <typename Real>
typename const Mathematics::Vector3DInformation<Real>::Vector3D Mathematics::Vector3DInformation<Real>
	::GetMaxExtreme() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Points[m_MaxExtreme];
}

template <typename Real>
typename const Mathematics::Vector3DInformation<Real>::Vector3D Mathematics::Vector3DInformation<Real>
	::GetPerpendicularExtreme() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Points[m_PerpendicularExtreme];
}

template <typename Real>
typename const Mathematics::Vector3DInformation<Real>::Vector3D Mathematics::Vector3DInformation<Real>
	::GetTetrahedronExtreme() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Points[m_TetrahedronExtreme];
}

template <typename Real>
bool Mathematics::Vector3DInformation<Real>
	::IsExtremeCCW() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_ExtremeCCW;
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>
	::GetMinExtremeIndex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinExtreme;
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>
	::GetMaxExtremeIndex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxExtreme;
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>
	::GetPerpendicularExtremeIndex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_PerpendicularExtreme;
}

template <typename Real>
int Mathematics::Vector3DInformation<Real>
	::GetTetrahedronExtremeIndex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_TetrahedronExtreme;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_DETAIL_H