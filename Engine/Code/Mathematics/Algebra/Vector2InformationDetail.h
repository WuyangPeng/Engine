/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/29 17:30)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_INFORMATION_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_INFORMATION_DETAIL_H

#include "AxesAlignBoundingBox2.h"
#include "Vector/VectorDetail.h"
#include "Vector2Information.h"
#include "Vector2ToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2Information<Real>::Vector2Information(const ContainerType& points, Real epsilon)
    : points{ points },
      epsilon{ epsilon },
      dimension{ -1 },
      axesAlignBoundingBox{},
      maxRange{},
      origin{},
      directionX{},
      directionY{},
      minExtreme{ -1 },
      maxExtreme{ -1 },
      perpendicularExtreme{ -1 },
      extremeCCW{ false },
      indexMin{},
      indexMax{}
{
    if (points.empty() || epsilon < MathType::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入在Vector2Information\n"s));
    }

    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2Information<Real>::Vector2Information(const AlgebraContainerType& points, Real epsilon)
    : Vector2Information{ GetContainer(points), epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Information<Real>::ContainerType Mathematics::Vector2Information<Real>::GetContainer(const AlgebraContainerType& points)
{
    ContainerType result{};

    for (const auto& element : points)
    {
        result.emplace_back(element[0], element[1]);
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2Information<Real>::Init()
{
    /// 计算输入点的轴对齐包围盒。跟踪“points”当前最小值和最大值的索引。
    ComputeAxisAlignedBoundingBox();

    /// 确定边界框的最大范围。
    DetermineMaximumRange();

    /// 原点是最小x值的点或最小y值的点。
    origin = points.at(minExtreme);

    /// 测试点集是否是（几乎）一个点或一个线段
    if (!(TestPointSetIsNearlyAPoint() || TestPointSetIsNearlyALineSegment()))
    {
        dimension = 2;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2Information<Real>::ComputeAxisAlignedBoundingBox()
{
    Vector2Type min{ MathType::maxReal, MathType::maxReal };
    Vector2Type max{ MathType::minReal, MathType::minReal };

    auto pointsIndex = 0;
    for (const auto& point : points)
    {
        for (auto directionIndex = 0u; directionIndex < Vector2Type::pointSize; ++directionIndex)
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

    axesAlignBoundingBox = AxesAlignBoundingBox2Type{ min, max };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector2Information<Real>::DetermineMaximumRange() noexcept
{
    const auto maxPoint = axesAlignBoundingBox.GetMaxPoint();
    const auto minPoint = axesAlignBoundingBox.GetMinPoint();

    const auto maxXRange = maxPoint.GetX() - minPoint.GetX();
    const auto maxYRange = maxPoint.GetY() - minPoint.GetY();

    if (maxXRange < maxYRange)
    {
        maxRange = maxYRange;

        minExtreme = indexMin.at(Vector2Type::yIndex);
        maxExtreme = indexMax.at(Vector2Type::yIndex);
    }
    else
    {
        maxRange = maxXRange;

        minExtreme = indexMin.at(Vector2Type::xIndex);
        maxExtreme = indexMax.at(Vector2Type::xIndex);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2Information<Real>::TestPointSetIsNearlyAPoint() noexcept
{
    if (maxRange <= epsilon)
    {
        dimension = 0;

        maxExtreme = minExtreme;
        perpendicularExtreme = minExtreme;

        directionX.ZeroOut();
        directionY.ZeroOut();

        return true;
    }

    return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2Information<Real>::TestPointSetIsNearlyALineSegment()
{
    /// 测试向量集是否（几乎）是线段。我们需要directionY来跨越directionX的正交补码。
    directionX = points.at(maxExtreme) - origin;
    directionX.Normalize(epsilon);
    directionY = -Vector2ToolsType::GetPerp(directionX);

    /// 计算点与直线的最大距离origin + t * directionX.
    auto maxDistance = MathType::GetValue(0);
    auto maxSign = NumericalValueSymbol::Zero;
    perpendicularExtreme = minExtreme;

    auto index = 0;
    for (const auto& point : points)
    {
        auto difference = point - origin;
        auto distance = Vector2ToolsType::DotProduct(directionY, difference);
        const auto sign = MathType::Sign(distance);
        distance = MathType::FAbs(distance);
        if (maxDistance < distance)
        {
            maxDistance = distance;
            maxSign = sign;
            perpendicularExtreme = index;
        }

        ++index;
    }

    if (maxDistance <= epsilon * maxRange)
    {
        /// 这些点（几乎）在直线 origin + t * directionX。
        dimension = 1;
        perpendicularExtreme = maxExtreme;

        return true;
    }

    extremeCCW = (maxSign == NumericalValueSymbol::Positive);

    return false;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2Information<Real>::IsValid() const noexcept
{
    const auto pointsSize = gsl::narrow_cast<int>(points.size());

    if (0 <= dimension &&
        dimension <= 2 &&
        0 <= maxRange &&
        0 <= minExtreme &&
        0 <= maxExtreme &&
        0 <= perpendicularExtreme &&
        minExtreme < pointsSize &&
        maxExtreme < pointsSize &&
        perpendicularExtreme < pointsSize)
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
int Mathematics::Vector2Information<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Information<Real>::AxesAlignBoundingBox2Type Mathematics::Vector2Information<Real>::GetAxesAlignBoundingBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axesAlignBoundingBox;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Vector2Information<Real>::GetMaxRange() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxRange;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Information<Real>::Vector2Type Mathematics::Vector2Information<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Information<Real>::Vector2Type Mathematics::Vector2Information<Real>::GetDirectionX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Information<Real>::Vector2Type Mathematics::Vector2Information<Real>::GetDirectionY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Information<Real>::Vector2Type Mathematics::Vector2Information<Real>::GetMinExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(minExtreme);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Information<Real>::Vector2Type Mathematics::Vector2Information<Real>::GetMaxExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(maxExtreme);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Vector2Information<Real>::Vector2Type Mathematics::Vector2Information<Real>::GetPerpendicularExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(perpendicularExtreme);
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector2Information<Real>::IsExtremeCCW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extremeCCW;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Vector2Information<Real>::GetMinExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return minExtreme;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Vector2Information<Real>::GetPerpendicularExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return perpendicularExtreme;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Vector2Information<Real>::GetMaxExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxExtreme;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::Vector2Information<Real>::GetIndexMin(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return indexMin.at(index);
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_INFORMATION_DETAIL_H