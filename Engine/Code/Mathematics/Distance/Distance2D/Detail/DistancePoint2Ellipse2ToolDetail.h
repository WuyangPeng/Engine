///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:15)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_DETAIL_H

#include "DistancePoint2Ellipse2Tool.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"

template <typename Real>
Mathematics::DistancePoint2Ellipse2Tool<Real>::DistancePoint2Ellipse2Tool(Real extent0, Real extent1, const Vector2& vector, Real zeroThreshold)
    : extent{ extent0, extent1 }, inputVector{ vector }, outputVector{}, squaredDistance{ Math::GetValue(0) }, zeroThreshold{ zeroThreshold }
{
    ComputeSquaredDistance();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::DistancePoint2Ellipse2Tool<Real>::ComputeSquaredDistance()
{
    constexpr auto size = 2;

    // 确定m_InputVector的反射到第一象限。
    const std::array<bool, size> reflect{ inputVector.GetX() < Math::GetValue(0), inputVector.GetY() < Math::GetValue(0) };

    // 确定递减辐度轴顺序。
    std::array<int, size> permute{};
    if (extent[0] < extent[1])
    {
        permute.at(0) = 1;
        permute.at(1) = 0;
    }
    else
    {
        permute.at(0) = 0;
        permute.at(1) = 1;
    }

    std::array<int, size> invPermute{};
    for (auto index = 0; index < size; ++index)
    {
        invPermute.at(permute.at(index)) = index;
    }

    Vector2 localExtent{};
    Vector2 localQueryPoint{};
    for (auto index = 0; index < size; ++index)
    {
        const auto permuteIndex = permute.at(index);
        localExtent[index] = extent[permuteIndex];
        localQueryPoint[index] = inputVector[permuteIndex];
        if (reflect.at(permuteIndex))
        {
            localQueryPoint[index] = -localQueryPoint[index];
        }
    }

    ComputeSquaredDistanceSpecial(localExtent, localQueryPoint);

    auto local = outputVector;

    // 恢复轴顺序和反射。
    for (auto index = 0; index < size; ++index)
    {
        const auto invPermuteIndex = invPermute.at(index);
        if (reflect.at(index))
        {
            local[invPermuteIndex] = -local[invPermuteIndex];
        }
        outputVector[index] = local[invPermuteIndex];
    }
}

template <typename Real>
void Mathematics::DistancePoint2Ellipse2Tool<Real>::ComputeSquaredDistanceSpecial(const Vector2& localExtent, const Vector2& queryPoint)
{
    if (zeroThreshold < queryPoint[1])
    {
        if (zeroThreshold < queryPoint[0])
        {
            // 平分计算F(t)的根t >= -e1 * e1。
            Vector2 extentSquared{ localExtent[0] * localExtent[0], localExtent[1] * localExtent[1] };
            Vector2 extentMultiplyQueryPoint{ localExtent[0] * queryPoint[0], localExtent[1] * queryPoint[1] };
            auto beginT = -extentSquared[1] + extentMultiplyQueryPoint[1];
            auto endT = -extentSquared[1] + Vector2Tools<Real>::GetLength(extentMultiplyQueryPoint);
            auto middleT = beginT;
            constexpr auto maxLoop = 2 * std::numeric_limits<Real>::max_exponent;
            for (auto i = 0; i < maxLoop; ++i)
            {
                middleT = Math::GetRational(1, 2) * (beginT + endT);
                if (Math::FAbs(middleT - beginT) <= zeroThreshold || Math::FAbs(middleT - endT) <= zeroThreshold)
                {
                    break;
                }

                const Vector2 r{ extentMultiplyQueryPoint[0] / (middleT + extentSquared[0]),
                                 extentMultiplyQueryPoint[1] / (middleT + extentSquared[1]) };
                auto lengthSquaredMinusOne = Vector2Tools<Real>::GetLengthSquared(r) - Math::GetValue(1);

                if (Math::GetValue(0) < lengthSquaredMinusOne)
                {
                    beginT = middleT;
                }
                else if (lengthSquaredMinusOne < Math::GetValue(0))
                {
                    endT = middleT;
                }
                else
                {
                    break;
                }
            }

            outputVector[0] = extentSquared[0] * queryPoint[0] / (middleT + extentSquared[0]);
            outputVector[1] = extentSquared[1] * queryPoint[1] / (middleT + extentSquared[1]);
            const Vector2 distance{ outputVector[0] - queryPoint[0], outputVector[1] - queryPoint[1] };
            squaredDistance = Vector2Tools<Real>::GetLengthSquared(distance);
        }
        else  // y0 == 0
        {
            outputVector[0] = Math::GetValue(0);
            outputVector[1] = localExtent[1];
            const auto difference = queryPoint[1] - localExtent[1];
            squaredDistance = difference * difference;
        }
    }
    else  // y1 == 0
    {
        const auto denom = localExtent[0] * localExtent[0] - localExtent[1] * localExtent[1];
        const auto extentMultiplyQueryPoint = localExtent[0] * queryPoint[0];
        if (extentMultiplyQueryPoint < denom)
        {
            // queryPoint.y为子区间内。
            const auto xDividedExtent = extentMultiplyQueryPoint / denom;
            const auto x0de0squared = xDividedExtent * xDividedExtent;
            outputVector[0] = localExtent[0] * xDividedExtent;
            outputVector[1] = localExtent[1] * Math::Sqrt(Math::FAbs(Math::GetValue(1) - x0de0squared));
            const auto xDifference = outputVector[0] - queryPoint[0];
            squaredDistance = xDifference * xDifference + outputVector[1] * outputVector[1];
        }
        else
        {
            // queryPoint.y为子区间外。
            // 最近的椭圆点有m_OutputVector.y == 0，
            // 在域边界间隔(x0/e0)^2 = 1。
            outputVector[0] = localExtent[0];
            outputVector[1] = Math::GetValue(0);
            const auto difference = queryPoint[0] - localExtent[0];
            squaredDistance = difference * difference;
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint2Ellipse2Tool<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= squaredDistance)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::DistancePoint2Ellipse2Tool<Real>::GetSquaredDistance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return squaredDistance;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Ellipse2Tool<Real>::GetOutputVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return outputVector;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_DETAIL_H
