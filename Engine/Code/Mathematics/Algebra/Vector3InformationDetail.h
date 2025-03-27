/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/30 10:11)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_INFORMATION_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR3_TOOLS_INFORMATION_DETAIL_H

#include "Vector/VectorDetail.h"
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
      axesAlignBoundingBox{},
      maxRange{ MathType::GetValue(0) },
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
    if (points.empty() || epsilon < MathType::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入在Vector3Information\n"s));
    }

    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3Information<Real>::Vector3Information(const AlgebraContainerType& points, Real epsilon)
    : Vector3Information{ GetContainer(points), epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector3Information<Real>::ContainerType Mathematics::Vector3Information<Real>::GetContainer(const AlgebraContainerType& points)
{
    ContainerType result{};

    for (const auto& element : points)
    {
        result.emplace_back(element[0], element[1], element[2]);
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3Information<Real>::Init()
{
    /// 计算输入点的轴对齐包围盒。跟踪“points”当前最小值和最大值的索引。
    ComputeAxisAlignedBoundingBox();

    /// 确定边界框的最大范围。
    DetermineMaximumRange();

    /// 原点是最小x值的点或最小y值或最小z值的点。
    origin = points.at(minExtreme);

    /// 测试点集是否是（几乎）一个点或一个线段或一个平面多边形
    if (!(TestPointSetIsNearlyAPoint() || TestPointSetIsNearlyALineSegment() || TestPointSetIsNearlyAPlanarPolygon()))
    {
        dimension = 3;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3Information<Real>::ComputeAxisAlignedBoundingBox()
{
    Vector3Type min{ MathType::maxReal, MathType::maxReal, MathType::maxReal };
    Vector3Type max{ MathType::minReal, MathType::minReal, MathType::minReal };

    auto pointsIndex = 0;
    for (const auto& point : points)
    {
        for (auto directionIndex = 0u; directionIndex < Vector3Type::pointSize; ++directionIndex)
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

    axesAlignBoundingBox = AxesAlignBoundingBox3Type{ min, max };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3Information<Real>::DetermineMaximumRange()
{
    auto maxPoint = axesAlignBoundingBox.GetMaxPoint();
    auto minPoint = axesAlignBoundingBox.GetMinPoint();

    maxRange = maxPoint.GetX() - minPoint.GetX();

    minExtreme = indexMin.at(Vector3Type::xIndex);
    maxExtreme = indexMax.at(Vector3Type::xIndex);

    for (auto i = Vector3Type::yIndex; i < Vector3Type::pointSize; ++i)
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
    /// 测试向量集是否（几乎）是一个向量。
    if (maxRange < epsilon)
    {
        dimension = 0;

        maxExtreme = minExtreme;
        perpendicularExtreme = minExtreme;
        tetrahedronExtreme = minExtreme;

        directionX.ZeroOut();
        directionY.ZeroOut();
        directionZ.ZeroOut();

        return true;
    }

    return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Information<Real>::TestPointSetIsNearlyALineSegment()
{
    /// 测试向量集是否（几乎）是线段。我们需要{directionY，directionZ}来跨越directionX的正交补码。
    directionX = points.at(maxExtreme) - origin;
    directionX.Normalize(epsilon);
    if (MathType::FAbs(directionX[1]) < MathType::FAbs(directionX[0]))
    {
        directionY[0] = -directionX[2];
        directionY[1] = Real{};
        directionY[2] = +directionX[0];
    }
    else
    {
        directionY[0] = Real{};
        directionY[1] = +directionX[2];
        directionY[2] = -directionX[1];
    }
    directionY.Normalize(epsilon);
    directionZ = Vector3Tools::CrossProduct(directionX, directionY);

    /// 计算点与直线的最大距离
    /// origin + t * directionX
    auto maxDistance = MathType::GetValue(0);
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
        /// 这些点（几乎）在线上
        /// origin + t * directionX
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
    /// 测试向量集是否（几乎）是平面多边形。
    /// 点v[extreme[perpendicularExtreme]离直线最远：origin + t * direction[0]。
    /// 向量v[extreme[perpendicularExtreme]]- origin 不一定垂直于directionX，
    /// 因此投影出directionX分量，使结果垂直于directionX。
    directionY = points.at(perpendicularExtreme) - origin;
    const auto dot = Vector3Tools::DotProduct(directionX, directionY);
    directionY -= dot * directionX;
    directionY.Normalize(epsilon);

    /// 我们需要directionZ来跨越{directionX，directionY}的正交补码。
    directionZ = Vector3Tools::CrossProduct(directionX, directionY);

    /// 计算点与平面的最大距离
    /// origin+t0 * directionX + t1 * directionY
    auto maxDistance = MathType::GetValue(0);
    auto maxSign = NumericalValueSymbol::Zero;
    tetrahedronExtreme = minExtreme;

    auto index = 0;
    for (const auto& point : points)
    {
        const auto diff = point - origin;
        auto distance = Vector3Tools::DotProduct(directionZ, diff);
        const auto sign = MathType::Sign(distance);
        distance = MathType::FAbs(distance);
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
        /// 这些点（几乎）在平面上
        /// origin + t0 * directionX + t1 * directionY
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
Mathematics::AxesAlignBoundingBox3<Real> Mathematics::Vector3Information<Real>::GetAxesAlignBoundingBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axesAlignBoundingBox;
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