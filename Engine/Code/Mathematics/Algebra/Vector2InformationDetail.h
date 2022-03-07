///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/03 20:16)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_INFORMATION_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_INFORMATION_DETAIL_H

#include "AxesAlignBoundingBox2.h"
#include "Vector2Information.h"
#include "Vector2ToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>

template <typename Real>
Mathematics::Vector2Information<Real>::Vector2Information(const ContainerType& points, Real epsilon)
    : points{ points },
      epsilon{ epsilon },
      dimension{ -1 },
      aabb{},
      maxRange{ Math::GetValue(0) },
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
    if (points.empty() || epsilon < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ч������Vector2Information\n"s));
    }

    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Vector2Information<Real>::Init()
{
    // ����������������Χ�С����١�points����ǰ��Сֵ�����ֵ��������
    ComputeAxisAlignedBoundingBox();

    // ȷ���߽������Χ��
    DetermineMaximumRange();

    // ԭ������Сxֵ�ĵ����Сyֵ�ĵ㡣
    origin = points.at(minExtreme);

    // ���Ե㼯�Ƿ��ǣ�������һ�����һ���߶�
    if (!(TestPointSetIsNearlyAPoint() || TestPointSetIsNearlyALineSegment()))
    {
        dimension = 2;
    }
}

// private
template <typename Real>
void Mathematics::Vector2Information<Real>::ComputeAxisAlignedBoundingBox()
{
    Vector2 min{ Math::maxReal, Math::maxReal };
    Vector2 max{ Math::minReal, Math::minReal };

    auto pointsIndex = 0;
    for (const auto& point : points)
    {
        for (auto directionIndex = 0u; directionIndex < Vector2::pointSize; ++directionIndex)
        {
            if (point[directionIndex] < min[directionIndex])
            {
                min[directionIndex] = point[directionIndex];

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

                indexMin[directionIndex] = pointsIndex;

#include STSTEM_WARNING_POP
            }

            if (max[directionIndex] < point[directionIndex])
            {
                max[directionIndex] = point[directionIndex];

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

                indexMax[directionIndex] = pointsIndex;

#include STSTEM_WARNING_POP
            }
        }

        ++pointsIndex;
    }

    aabb = AxesAlignBoundingBox2D{ min, max };
}

// private
template <typename Real>
void Mathematics::Vector2Information<Real>::DetermineMaximumRange() noexcept
{
    const auto maxPoint = aabb.GetMaxPoint();
    const auto minPoint = aabb.GetMinPoint();

    const auto maxXRange = maxPoint.GetX() - minPoint.GetX();
    const auto maxYRange = maxPoint.GetY() - minPoint.GetY();

    if (maxXRange < maxYRange)
    {
        maxRange = maxYRange;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        minExtreme = indexMin[Vector2::yIndex];
        maxExtreme = indexMax[Vector2::yIndex];

#include STSTEM_WARNING_POP
    }
    else
    {
        maxRange = maxXRange;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        minExtreme = indexMin[Vector2::xIndex];
        maxExtreme = indexMax[Vector2::xIndex];

#include STSTEM_WARNING_POP
    }
}

// private
template <typename Real>
bool Mathematics::Vector2Information<Real>::TestPointSetIsNearlyAPoint() noexcept
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
bool Mathematics::Vector2Information<Real>::TestPointSetIsNearlyALineSegment()
{
    directionX = points.at(maxExtreme) - origin;
    directionX.Normalize(epsilon);
    directionY = -Vector2Tools::GetPerp(directionX);

    auto maxDistance = Math::GetValue(0);
    auto maxSign = NumericalValueSymbol::Zero;
    perpendicularExtreme = minExtreme;

    auto index = 0;
    for (const auto& point : points)
    {
        auto difference = point - origin;
        auto distance = Vector2Tools::DotProduct(directionY, difference);
        const auto sign = Math::Sign(distance);
        distance = Math::FAbs(distance);
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
        dimension = 1;
        perpendicularExtreme = maxExtreme;

        return true;
    }

    extremeCCW = (maxSign == NumericalValueSymbol::Positive);

    return false;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Vector2Information<Real>::IsValid() const noexcept
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
int Mathematics::Vector2Information<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}

template <typename Real>
typename Mathematics::Vector2Information<Real>::AxesAlignBoundingBox2D Mathematics::Vector2Information<Real>::GetAABB() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return aabb;
}

template <typename Real>
Real Mathematics::Vector2Information<Real>::GetMaxRange() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxRange;
}

template <typename Real>
typename Mathematics::Vector2Information<Real>::Vector2 Mathematics::Vector2Information<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
typename Mathematics::Vector2Information<Real>::Vector2 Mathematics::Vector2Information<Real>::GetDirectionX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionX;
}

template <typename Real>
typename Mathematics::Vector2Information<Real>::Vector2 Mathematics::Vector2Information<Real>::GetDirectionY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return directionY;
}

template <typename Real>
typename Mathematics::Vector2Information<Real>::Vector2 Mathematics::Vector2Information<Real>::GetMinExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(minExtreme);
}

template <typename Real>
typename Mathematics::Vector2Information<Real>::Vector2 Mathematics::Vector2Information<Real>::GetMaxExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(maxExtreme);
}

template <typename Real>
typename Mathematics::Vector2Information<Real>::Vector2 Mathematics::Vector2Information<Real>::GetPerpendicularExtreme() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(perpendicularExtreme);
}

template <typename Real>
bool Mathematics::Vector2Information<Real>::IsExtremeCCW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extremeCCW;
}

template <typename Real>
int Mathematics::Vector2Information<Real>::GetMinExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return minExtreme;
}

template <typename Real>
int Mathematics::Vector2Information<Real>::GetPerpendicularExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return perpendicularExtreme;
}

template <typename Real>
int Mathematics::Vector2Information<Real>::GetMaxExtremeIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxExtreme;
}

template <typename Real>
int Mathematics::Vector2Information<Real>::GetIndexMin(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return indexMin.at(index);
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_TOOLS_INFORMATION_DETAIL_H