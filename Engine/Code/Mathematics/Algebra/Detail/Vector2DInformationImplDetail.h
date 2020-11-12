///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 18:55)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_IMPL_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_IMPL_DETAIL_H

#include "Vector2DInformationImpl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"

#include <gsl/gsl_util>

template <typename Real>
Mathematics::Vector2DInformationImpl<Real>::Vector2DInformationImpl(const ContainerType& points, Real epsilon)
    : m_Points{ points },
      m_Epsilon{ epsilon },
      m_Dimension{ -1 },
      m_AABB{},
      m_MaxRange{ Math::GetValue(0) },
      m_Origin{},
      m_DirectionX{},
      m_DirectionY{},
      m_MinExtreme{ -1 },
      m_MaxExtreme{ -1 },
      m_PerpendicularExtreme{ -1 },
      m_ExtremeCCW{ false },
      m_IndexMin{},
      m_IndexMax{}
{
    if (m_Points.empty() || m_Epsilon < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入在Vector2DInformation\n"s));
    }

    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Vector2DInformationImpl<Real>::Init()
{
    // 计算输入点的轴对齐包围盒。跟踪“points”当前最小值和最大值的索引。
    ComputeAxisAlignedBoundingBox();

    // 确定边界框的最大范围。
    DetermineMaximumRange();

    // 原点是最小x值的点或最小y值的点。
    m_Origin = m_Points.at(m_MinExtreme);

    // 测试点集是否是（几乎）一个点或一个线段
    if (!(TestPointSetIsNearlyAPoint() || TestPointSetIsNearlyALineSegment()))
    {
        m_Dimension = 2;
    }
}

// private
template <typename Real>
void Mathematics::Vector2DInformationImpl<Real>::ComputeAxisAlignedBoundingBox()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto min = m_Points[0];

#include STSTEM_WARNING_POP

    auto max = min;

    auto pointsIndex = 0;
    for (const auto& point : m_Points)
    {
        for (auto directionIndex = 0u; directionIndex < Vector2D::sm_PointSize; ++directionIndex)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

            if (point[directionIndex] < min[directionIndex])
            {
                min[directionIndex] = point[directionIndex];
                m_IndexMin[directionIndex] = pointsIndex;
            }
            else if (max[directionIndex] < point[directionIndex])
            {
                max[directionIndex] = point[directionIndex];
                m_IndexMax[directionIndex] = pointsIndex;
            }

#include STSTEM_WARNING_POP
        }

        ++pointsIndex;
    }

    m_AABB = AxesAlignBoundingBox2D{ min, max };
}

// private
template <typename Real>
void Mathematics::Vector2DInformationImpl<Real>::DetermineMaximumRange() noexcept
{
    const auto maxPoint = m_AABB.GetMaxPoint();
    const auto minPoint = m_AABB.GetMinPoint();

    auto maxXRange = maxPoint.GetX() - minPoint.GetX();
    auto maxYRange = maxPoint.GetY() - minPoint.GetY();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (maxXRange < maxYRange)
    {
        m_MaxRange = maxYRange;
        m_MinExtreme = m_IndexMin[Vector2D::sm_Y];
        m_MaxExtreme = m_IndexMax[Vector2D::sm_Y];
    }
    else
    {
        m_MaxRange = maxXRange;
        m_MinExtreme = m_IndexMin[Vector2D::sm_X];
        m_MaxExtreme = m_IndexMax[Vector2D::sm_X];
    }

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
bool Mathematics::Vector2DInformationImpl<Real>::TestPointSetIsNearlyAPoint() noexcept
{
    if (m_MaxRange <= m_Epsilon)
    {
        m_Dimension = 0;

        m_MaxExtreme = m_MinExtreme;
        m_PerpendicularExtreme = m_MinExtreme;

        m_DirectionX.ZeroOut();
        m_DirectionY.ZeroOut();

        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::Vector2DInformationImpl<Real>::TestPointSetIsNearlyALineSegment()
{
    m_DirectionX = m_Points.at(m_MaxExtreme) - m_Origin;
    m_DirectionX.Normalize(m_Epsilon);
    m_DirectionY = -Vector2DTools::GetPerp(m_DirectionX);

    auto maxDistance = Math::GetValue(0);
    auto maxSign = NumericalValueSymbol::Zero;
    m_PerpendicularExtreme = m_MinExtreme;

    auto index = 0;
    for (const auto& point : m_Points)
    {
        auto difference = point - m_Origin;
        auto distance = Vector2DTools::DotProduct(m_DirectionY, difference);
        const auto sign = Math::Sign(distance);
        distance = Math::FAbs(distance);
        if (maxDistance < distance)
        {
            maxDistance = distance;
            maxSign = sign;
            m_PerpendicularExtreme = index;
        }

        ++index;
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
bool Mathematics::Vector2DInformationImpl<Real>::IsValid() const noexcept
{
    const auto pointsSize = gsl::narrow_cast<int>(m_Points.size());

    if (0 <= m_Dimension && m_Dimension <= 2 && 0 <= m_MaxRange && 0 <= m_MinExtreme &&
        0 <= m_MaxExtreme && 0 <= m_PerpendicularExtreme && m_MinExtreme < pointsSize &&
        m_MaxExtreme < pointsSize && m_PerpendicularExtreme < pointsSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Vector2DInformationImpl<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Dimension;
}

template <typename Real>
typename Mathematics::Vector2DInformationImpl<Real>::AxesAlignBoundingBox2D Mathematics::Vector2DInformationImpl<Real>::GetAABB() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_AABB;
}

template <typename Real>
Real Mathematics::Vector2DInformationImpl<Real>::GetMaxRange() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxRange;
}

template <typename Real>
typename const Mathematics::Vector2DInformationImpl<Real>::Vector2D Mathematics::Vector2DInformationImpl<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Origin;
}

template <typename Real>
typename const Mathematics::Vector2DInformationImpl<Real>::Vector2D Mathematics::Vector2DInformationImpl<Real>::GetDirectionX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionX;
}

template <typename Real>
typename const Mathematics::Vector2DInformationImpl<Real>::Vector2D Mathematics::Vector2DInformationImpl<Real>::GetDirectionY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionY;
}

template <typename Real>
typename const Mathematics::Vector2DInformationImpl<Real>::Vector2D Mathematics::Vector2DInformationImpl<Real>::GetMinExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points.at(m_MinExtreme);
}

template <typename Real>
typename const Mathematics::Vector2DInformationImpl<Real>::Vector2D Mathematics::Vector2DInformationImpl<Real>::GetMaxExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points.at(m_MaxExtreme);
}

template <typename Real>
typename const Mathematics::Vector2DInformationImpl<Real>::Vector2D Mathematics::Vector2DInformationImpl<Real>::GetPerpendicularExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points.at(m_PerpendicularExtreme);
}

template <typename Real>
bool Mathematics::Vector2DInformationImpl<Real>::IsExtremeCCW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ExtremeCCW;
}

template <typename Real>
int Mathematics::Vector2DInformationImpl<Real>::GetMinExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinExtreme;
}

template <typename Real>
int Mathematics::Vector2DInformationImpl<Real>::GetPerpendicularExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_PerpendicularExtreme;
}

template <typename Real>
int Mathematics::Vector2DInformationImpl<Real>::GetMaxExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxExtreme;
}

template <typename Real>
int Mathematics::Vector2DInformationImpl<Real>::GetIndexMin(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IndexMin.at(index);
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_INFORMATION_IMPL_DETAIL_H