///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 17:53)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_IMPL_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_IMPL_DETAIL_H

#include "Vector3DInformationImpl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"

#include <gsl/gsl_util>

template <typename Real>
Mathematics::Vector3DInformationImpl<Real>::Vector3DInformationImpl(const ContainerType& points, Real epsilon)
    : m_Points{ points },
      m_Epsilon{ epsilon },
      m_Dimension{ -1 },
      m_AABB{},
      m_MaxRange{ Math::GetValue(0) },
      m_Origin{},
      m_DirectionX{},
      m_DirectionY{},
      m_DirectionZ{},
      m_MinExtreme{ -1 },
      m_MaxExtreme{ -1 },
      m_PerpendicularExtreme{ -1 },
      m_TetrahedronExtreme{ -1 },
      m_ExtremeCCW{ false },
      m_IndexMin{},
      m_IndexMax{}
{
    if (m_Points.empty() || m_Epsilon < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入在Vector3DInformation\n"s));
    }

    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Vector3DInformationImpl<Real>::Init()
{
    // 计算输入点的轴对齐包围盒。跟踪“points”当前最小值和最大值的索引。
    ComputeAxisAlignedBoundingBox();

    // 确定边界框的最大范围。
    DetermineMaximumRange();

    // 原点是最小x值的点或最小y值或最小z值的点。
    m_Origin = m_Points.at(m_MinExtreme);

    // 测试点集是否是（几乎）一个点或一个线段或一个平面多边形
    if (!(TestPointSetIsNearlyAPoint() || TestPointSetIsNearlyALineSegment() || TestPointSetIsNearlyAPlanarPolygon()))
    {
        m_Dimension = 3;
    }
}

// private
template <typename Real>
void Mathematics::Vector3DInformationImpl<Real>::ComputeAxisAlignedBoundingBox()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto min = m_Points[0];

#include STSTEM_WARNING_POP

    auto max = min;

    auto pointsIndex = 0;
    for (const auto& point : m_Points)
    {
        for (auto directionIndex = 0u; directionIndex < Vector3D::sm_PointSize; ++directionIndex)
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

    m_AABB = AxesAlignBoundingBox3D{ min, max };
}

// private
template <typename Real>
void Mathematics::Vector3DInformationImpl<Real>::DetermineMaximumRange()
{
    auto maxPoint = m_AABB.GetMaxPoint();
    auto minPoint = m_AABB.GetMinPoint();

    m_MaxRange = maxPoint.GetX() - minPoint.GetX();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    m_MinExtreme = m_IndexMin[Vector3D::sm_X];
    m_MaxExtreme = m_IndexMax[Vector3D::sm_X];

#include STSTEM_WARNING_POP

    for (auto i = Vector3D::sm_Y; i < Vector3D::sm_PointSize; ++i)
    {
        auto range = maxPoint[i] - minPoint[i];

        if (m_MaxRange < range)
        {
            m_MaxRange = range;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

            m_MinExtreme = m_IndexMin[i];
            m_MaxExtreme = m_IndexMax[i];

#include STSTEM_WARNING_POP
        }
    }
}

// private
template <typename Real>
bool Mathematics::Vector3DInformationImpl<Real>::TestPointSetIsNearlyAPoint() noexcept
{
    if (m_MaxRange < m_Epsilon)
    {
        m_Dimension = 0;

        m_MaxExtreme = m_MinExtreme;
        m_PerpendicularExtreme = m_MinExtreme;
        m_TetrahedronExtreme = m_MinExtreme;

        m_DirectionX.SetX(Math::GetValue(0));
        m_DirectionX.SetY(Math::GetValue(0));
        m_DirectionY.SetX(Math::GetValue(0));
        m_DirectionY.SetY(Math::GetValue(0));

        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::Vector3DInformationImpl<Real>::TestPointSetIsNearlyALineSegment()
{
    m_DirectionX = m_Points.at(m_MaxExtreme) - m_Origin;
    m_DirectionX.Normalize(m_Epsilon);

    auto maxDistance = Math::GetValue(0);
    m_PerpendicularExtreme = m_MinExtreme;
    auto index = 0;
    for (const auto& point : m_Points)
    {
        auto difference = point - m_Origin;
        auto dot = Vector3DTools::DotProduct(m_DirectionX, difference);
        auto proj = difference - dot * m_DirectionX;
        auto distance = Vector3DTools::VectorMagnitude(proj);

        if (maxDistance < distance)
        {
            maxDistance = distance;
            m_PerpendicularExtreme = index;
        }

        ++index;
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
bool Mathematics::Vector3DInformationImpl<Real>::TestPointSetIsNearlyAPlanarPolygon()
{
    m_DirectionY = m_Points.at(m_PerpendicularExtreme) - m_Origin;
    auto dot = Vector3DTools::DotProduct(m_DirectionX, m_DirectionY);
    m_DirectionY -= dot * m_DirectionX;
    m_DirectionY.Normalize(m_Epsilon);
    m_DirectionZ = Vector3DTools::CrossProduct(m_DirectionX, m_DirectionY);
    auto maxDistance = Math::GetValue(0);
    auto maxSign = NumericalValueSymbol::Zero;
    m_TetrahedronExtreme = m_MinExtreme;

    auto index = 0;
    for (const auto& point : m_Points)
    {
        auto diff = point - m_Origin;
        auto distance = Vector3DTools::DotProduct(m_DirectionZ, diff);
        const auto sign = Math::Sign(distance);
        distance = Math::FAbs(distance);
        if (maxDistance < distance)
        {
            maxDistance = distance;
            maxSign = sign;
            m_TetrahedronExtreme = index;
        }

        ++index;
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
bool Mathematics::Vector3DInformationImpl<Real>::IsValid() const noexcept
{
    const auto pointsSize = gsl::narrow_cast<int>(m_Points.size());

    if (0 <= m_Dimension && m_Dimension <= 3 && 0 <= m_MaxRange &&
        m_MinExtreme < pointsSize && m_MaxExtreme < pointsSize &&
        m_PerpendicularExtreme < pointsSize && m_TetrahedronExtreme < pointsSize)
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
int Mathematics::Vector3DInformationImpl<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Dimension;
}

template <typename Real>
Mathematics::AxesAlignBoundingBox3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetAABB() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_AABB;
}

template <typename Real>
Real Mathematics::Vector3DInformationImpl<Real>::GetMaxRange() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxRange;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Origin;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetDirectionX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionX;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetDirectionY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionY;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetDirectionZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DirectionZ;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetMinExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points.at(m_MinExtreme);
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetMaxExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points.at(m_MaxExtreme);
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetPerpendicularExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points.at(m_PerpendicularExtreme);
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3DInformationImpl<Real>::GetTetrahedronExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points.at(m_TetrahedronExtreme);
}

template <typename Real>
bool Mathematics::Vector3DInformationImpl<Real>::IsExtremeCCW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ExtremeCCW;
}

template <typename Real>
int Mathematics::Vector3DInformationImpl<Real>::GetMinExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinExtreme;
}

template <typename Real>
int Mathematics::Vector3DInformationImpl<Real>::GetMaxExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxExtreme;
}

template <typename Real>
int Mathematics::Vector3DInformationImpl<Real>::GetPerpendicularExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_PerpendicularExtreme;
}

template <typename Real>
int Mathematics::Vector3DInformationImpl<Real>::GetTetrahedronExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TetrahedronExtreme;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_INFORMATION_IMPL_DETAIL_H