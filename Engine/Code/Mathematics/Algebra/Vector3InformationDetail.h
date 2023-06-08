///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/01 10:21)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_INFORMATION_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_INFORMATION_DETAIL_H

#include "Vector3Information.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox3.h"
#include "Mathematics/Algebra/Vector3Tools.h"

#include <gsl/util>

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3Information<Real>::Vector3Information(const ContainerType& points, Real epsilon)
    : points{ points },
      epsilon{ epsilon },
      dimension{ -1 },
      aabb{},
      maxRange{ Math::GetValue(0) },
      origin{},
      directionX{},
      directionY{},
      directionZ{},
      minExtreme{ -1 },
      maxExtreme{ -1 },
      perpendicularExtreme{ -1 },
      tetrahedronExtreme{ -1 },
      extremeCCW{ false },
      indexMin{},
      indexMax{}
{
    if (points.empty() || epsilon < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入在Vector3Information\n"s));
    }

    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3Information<Real>::Init()
{
    // 计算输入点的轴对齐包围盒。跟踪“points”当前最小值和最大值的索引。
    ComputeAxisAlignedBoundingBox();

    // 确定边界框的最大范围。
    DetermineMaximumRange();

    // 原点是最小x值的点或最小y值或最小z值的点。
    origin = points.at(minExtreme);

    // 测试点集是否是（几乎）一个点或一个线段或一个平面多边形
    if (!(TestPointSetIsNearlyAPoint() || TestPointSetIsNearlyALineSegment() || TestPointSetIsNearlyAPlanarPolygon()))
    {
        dimension = 3;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3Information<Real>::ComputeAxisAlignedBoundingBox()
{
    Vector3 min{ Math::maxReal, Math::maxReal, Math::maxReal };
    Vector3 max{ Math::minReal, Math::minReal, Math::minReal };

    auto pointsIndex = 0;
    for (const auto& point : points)
    {
        for (auto directionIndex = 0u; directionIndex < Vector3::pointSize; ++directionIndex)
        {
            if (point[directionIndex] < min[directionIndex])
            {
                min[directionIndex] = point[directionIndex];

                indexMin.at(directionIndex) = pointsIndex;
            }

            if (max[directionIndex] < point[directionIndex])
            {
                max[directionIndex] = point[directionIndex];

                indexMax.at(directionIndex) = pointsIndex;
            }
        }

        ++pointsIndex;
    }

    aabb = AxesAlignBoundingBox3D{ min, max };
}

// private
template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3Information<Real>::DetermineMaximumRange()
{
    auto maxPoint = aabb.GetMaxPoint();
    auto minPoint = aabb.GetMinPoint();

    maxRange = maxPoint.GetX() - minPoint.GetX();

    minExtreme = indexMin.at(Vector3::xIndex);
    maxExtreme = indexMax.at(Vector3::xIndex);

    for (auto i = Vector3::yIndex; i < Vector3::pointSize; ++i)
    {
        auto range = maxPoint[i] - minPoint[i];

        if (maxRange < range)
        {
            maxRange = range;

            minExtreme = indexMin.at(i);
            maxExtreme = indexMax.at(i);
        }
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Information<Real>::TestPointSetIsNearlyAPoint() noexcept
{
    if (maxRange < epsilon)
    {
        dimension = 0;

        maxExtreme = minExtreme;
        perpendicularExtreme = minExtreme;
        tetrahedronExtreme = minExtreme;

        directionX.SetX(Math::GetValue(0));
        directionX.SetY(Math::GetValue(0));
        directionY.SetX(Math::GetValue(0));
        directionY.SetY(Math::GetValue(0));

        return true;
    }

    return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Information<Real>::TestPointSetIsNearlyALineSegment()
{
    directionX = points.at(maxExtreme) - origin;
    directionX.Normalize(epsilon);

    auto maxDistance = Math::GetValue(0);
    perpendicularExtreme = minExtreme;
    auto index = 0;
    for (const auto& point : points)
    {
        const auto difference = point - origin;
        const auto dot = Vector3Tools::DotProduct(directionX, difference);
        const auto proj = difference - dot * directionX;
        const auto distance = Vector3Tools::GetLength(proj);

        if (maxDistance < distance)
        {
            maxDistance = distance;
            perpendicularExtreme = index;
        }

        ++index;
    }

    if (maxDistance < epsilon * maxRange)
    {
        dimension = 1;
        perpendicularExtreme = maxExtreme;
        tetrahedronExtreme = maxExtreme;

        return true;
    }

    return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Information<Real>::TestPointSetIsNearlyAPlanarPolygon()
{
    directionY = points.at(perpendicularExtreme) - origin;
    const auto dot = Vector3Tools::DotProduct(directionX, directionY);
    directionY -= dot * directionX;
    directionY.Normalize(epsilon);
    directionZ = Vector3Tools::CrossProduct(directionX, directionY);
    auto maxDistance = Math::GetValue(0);
    auto maxSign = NumericalValueSymbol::Zero;
    tetrahedronExtreme = minExtreme;

    auto index = 0;
    for (const auto& point : points)
    {
        const auto diff = point - origin;
        auto distance = Vector3Tools::DotProduct(directionZ, diff);
        const auto sign = Math::Sign(distance);
        distance = Math::FAbs(distance);
        if (maxDistance < distance)
        {
            maxDistance = distance;
            maxSign = sign;
            tetrahedronExtreme = index;
        }

        ++index;
    }

    if (maxDistance < epsilon * maxRange)
    {
        dimension = 2;
        tetrahedronExtreme = perpendicularExtreme;

        return true;
    }

    extremeCCW = (maxSign == NumericalValueSymbol::Positive);

    return false;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Information<Real>::IsValid() const noexcept
{
    const auto pointsSize = gsl::narrow_cast<int>(points.size());

    if (0 <= dimension &&
        dimension <= 3 &&
        0 <= maxRange &&
        minExtreme < pointsSize &&
        maxExtreme < pointsSize &&
        perpendicularExtreme < pointsSize &&
        tetrahedronExtreme < pointsSize)
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
requires std::is_arithmetic_v<Real>
int Mathematics::Vector3Information<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AxesAlignBoundingBox3<Real> Mathematics::Vector3Information<Real>::GetAABB() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return aabb;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector3Information<Real>::GetMaxRange() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxRange;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Information<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Information<Real>::GetDirectionX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Information<Real>::GetDirectionY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Information<Real>::GetDirectionZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Information<Real>::GetMinExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(minExtreme);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Information<Real>::GetMaxExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(maxExtreme);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Information<Real>::GetPerpendicularExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(perpendicularExtreme);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Information<Real>::GetTetrahedronExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(tetrahedronExtreme);
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Information<Real>::IsExtremeCCW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extremeCCW;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Vector3Information<Real>::GetMinExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return minExtreme;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Vector3Information<Real>::GetMaxExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxExtreme;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Vector3Information<Real>::GetPerpendicularExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return perpendicularExtreme;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Vector3Information<Real>::GetTetrahedronExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tetrahedronExtreme;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_INFORMATION_DETAIL_H