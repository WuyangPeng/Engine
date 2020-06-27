// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 15:46)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_DETAIL_H

#include "Vector2DInformation.h"
#include "AxesAlignBoundingBox2D.h"
#include "Vector2DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Vector2DInformation<Real>
	::Vector2DInformation(const std::vector<Vector2D>& points, Real epsilon)
	:m_Points{ points }, m_Epsilon{ epsilon }, m_Dimension{ -1 }, m_AABBPtr{}, m_MaxRange{ Math::sm_Zero }, m_Origin{},
	 m_DirectionX{}, m_DirectionY{}, m_MinExtreme{ -1 }, m_MaxExtreme{ -1 }, m_PerpendicularExtreme{ -1 }, m_ExtremeCCW{ false }
{
	MATHEMATICS_ASSERTION_0(0 < m_Points.size() && Math::sm_Zero <= m_Epsilon, "无效输入在Vector2DInformation\n");

	m_IndexMin[0] = 0;
	m_IndexMin[1] = 0;
	m_IndexMax[0] = 0;
	m_IndexMax[1] = 0;

	Init();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Vector2DInformation<Real>
	::Init()
{
	// 计算输入点的轴对齐包围盒。跟踪“points”当前最小值和最大值的索引。
	ComputeAxisAlignedBoundingBox();

	// 确定边界框的最大范围。
	DetermineMaximumRange();

	// 原点是最小x值的点或最小y值的点。
	m_Origin = m_Points[m_MinExtreme];

	// 测试点集是否是（几乎）一个点或一个线段
	if (!(TestPointSetIsNearlyAPoint() || TestPointSetIsNearlyALineSegment()))
	{
		m_Dimension = 2;
	}
}

// private
template <typename Real>
void Mathematics::Vector2DInformation<Real>
	::ComputeAxisAlignedBoundingBox()
{
	auto min = m_Points[0];
	auto max = min;

	for (auto pointsIndex = 1u; pointsIndex < m_Points.size(); ++pointsIndex)
	{
		const auto& eachVector = m_Points[pointsIndex];

		for (auto directionIndex = 0u; directionIndex < 2; ++directionIndex)
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

	m_AABBPtr = std::make_shared<AxesAlignBoundingBox2D>(min, max);
}

// private
template <typename Real>
void Mathematics::Vector2DInformation<Real>
	::DetermineMaximumRange()
{
	auto maxPoint = m_AABBPtr->GetMaxPoint();
	auto minPoint = m_AABBPtr->GetMinPoint();

	auto maxXRange = maxPoint[0] - minPoint[0];
	auto maxYRange = maxPoint[1] - minPoint[1];

	if (maxXRange < maxYRange)
	{
		m_MaxRange = maxYRange;
		m_MinExtreme = m_IndexMin[1];
		m_MaxExtreme = m_IndexMax[1];
	}
	else
	{
		m_MaxRange = maxXRange;
		m_MinExtreme = m_IndexMin[0];
		m_MaxExtreme = m_IndexMax[0];
	}
}

// private
template <typename Real>
bool Mathematics::Vector2DInformation<Real>
	::TestPointSetIsNearlyAPoint()
{
	if (m_MaxRange <= m_Epsilon)
	{
		m_Dimension = 0;

		m_MaxExtreme = m_MinExtreme;
		m_PerpendicularExtreme = m_MinExtreme;

		m_DirectionX[0] = Math::sm_Zero;
		m_DirectionY[1] = Math::sm_Zero;

		return true;
	}

	return false;
}

template <typename Real>
bool Mathematics::Vector2DInformation<Real>
	::TestPointSetIsNearlyALineSegment()
{
	m_DirectionX = m_Points[m_MaxExtreme] - m_Origin;
	m_DirectionX.Normalize(m_Epsilon);
	m_DirectionY = -Vector2DTools::GetPerp(m_DirectionX);

	auto maxDistance = Math::sm_Zero;
	auto maxSign = NumericalValueSymbol::Zero;
	m_PerpendicularExtreme = m_MinExtreme;
	for (auto index = 0u; index < m_Points.size(); ++index)
	{
		auto difference = m_Points[index] - m_Origin;
		auto distance = Vector2DTools::DotProduct(m_DirectionY, difference);
		auto sign = Math::Sign(distance);
		distance = Math::FAbs(distance);
		if (maxDistance < distance)
		{
			maxDistance = distance;
			maxSign = sign;
			m_PerpendicularExtreme = index;
		}
	}

	if (maxDistance <= m_Epsilon * m_MaxRange)
	{
		m_Dimension = 1;
		m_PerpendicularExtreme = m_MaxExtreme;

		return true;
	}

	m_ExtremeCCW = (maxSign == NumericalValueSymbol::Positive);

	return false;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector2DInformation<Real>
	::IsValid() const noexcept
{
	auto pointsSize = static_cast<int>(m_Points.size());

	if (0 <= m_Dimension && m_Dimension <= 2 && m_AABBPtr != nullptr && 0 <= m_MaxRange && 0 <= m_MinExtreme &&
		0 <= m_MaxExtreme && 0 <= m_PerpendicularExtreme && m_MinExtreme < pointsSize && m_MaxExtreme < pointsSize && m_PerpendicularExtreme < pointsSize)
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
int Mathematics::Vector2DInformation<Real>
	::GetDimension() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Dimension;
}

template <typename Real>
typename Mathematics::Vector2DInformation<Real>::AxesAlignBoundingBox2DPtr
Mathematics::Vector2DInformation<Real>
	::GetAABBPtr() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_AABBPtr;
}

template <typename Real>
Real Mathematics::Vector2DInformation<Real>
	::GetMaxRange() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxRange;
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>
	::GetOrigin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Origin;
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>
	::GetDirectionX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionX;
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>
	::GetDirectionY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionY;
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>
	::GetMinExtreme() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Points[m_MinExtreme];
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>
	::GetMaxExtreme() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Points[m_MaxExtreme];
}

template <typename Real>
typename const Mathematics::Vector2DInformation<Real>::Vector2D Mathematics::Vector2DInformation<Real>
	::GetPerpendicularExtreme() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Points[m_PerpendicularExtreme];
}

template <typename Real>
bool Mathematics::Vector2DInformation<Real>
	::IsExtremeCCW() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_ExtremeCCW;
}

template <typename Real>
int Mathematics::Vector2DInformation<Real>
	::GetMinExtremeIndex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinExtreme;
}

template <typename Real>
int Mathematics::Vector2DInformation<Real>
	::GetPerpendicularExtremeIndex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_PerpendicularExtreme;
}

template <typename Real>
int Mathematics::Vector2DInformation<Real>
	::GetMaxExtremeIndex() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MaxExtreme;
}

template <typename Real>
int Mathematics::Vector2DInformation<Real>
	::GetIndexMin(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < 2)
	{
		return m_IndexMin[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"));
	}
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_DETAIL_H