///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:26)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_DETAIL_H

#include "DistancePoint3Ellipsoid3Tool.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::DistancePoint3Ellipsoid3Tool<Real>::DistancePoint3Ellipsoid3Tool(Real extent0, Real extent1, Real extent2, const Vector3& vector, Real zeroThreshold)
    : toolExtent{ extent0, extent1, extent2 }, inputVector{ vector }, outputVector{}, squaredDistance{ MathType::GetValue(0) }, zeroThreshold{ zeroThreshold }
{
    ComputeSquaredDistance();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::DistancePoint3Ellipsoid3Tool<Real>::ComputeSquaredDistance()
{
    constexpr auto size = 3;

    // 确定m_InputVector的反射到第一象限。
    const std::array<bool, size> reflect{ inputVector.GetX() < MathType::GetValue(0), inputVector.GetY() < MathType::GetValue(0), inputVector.GetZ() < MathType::GetValue(0) };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 确定递减辐度轴顺序。
    std::array<int, size> permute{};
    if (toolExtent[0] < toolExtent[1])
    {
        if (toolExtent[2] < toolExtent[0])
        {
            permute[0] = 1;
            permute[1] = 0;
            permute[2] = 2;
        }
        else if (toolExtent[2] < toolExtent[1])
        {
            permute[0] = 1;
            permute[1] = 2;
            permute[2] = 0;
        }
        else
        {
            permute[0] = 2;
            permute[1] = 1;
            permute[2] = 0;
        }
    }
    else
    {
        if (toolExtent[2] < toolExtent[1])
        {
            permute[0] = 0;
            permute[1] = 1;
            permute[2] = 2;
        }
        else if (toolExtent[2] < toolExtent[0])
        {
            permute[0] = 0;
            permute[1] = 2;
            permute[2] = 1;
        }
        else
        {
            permute[0] = 2;
            permute[1] = 0;
            permute[2] = 1;
        }
    }

#include SYSTEM_WARNING_POP

    std::array<int, size> invPermute{};
    for (auto index = 0; index < size; ++index)
    {
        invPermute.at(permute.at(index)) = index;
    }

    Vector3 localExtent{};
    Vector3 localQueryPoint{};
    for (auto index = 0; index < size; ++index)
    {
        const auto permuteIndex = permute.at(index);
        localExtent[index] = toolExtent[permuteIndex];
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
void Mathematics::DistancePoint3Ellipsoid3Tool<Real>::ComputeSquaredDistanceSpecial(const Vector3& extent, const Vector3& queryPoint)
{
    Container extentPos{};
    Container queryPointPos{};
    Container outputPos{};

    constexpr auto size = 3;

    for (auto i = 0; i < size; ++i)
    {
        if (zeroThreshold < queryPoint[i])
        {
            extentPos.emplace_back(extent[i]);
            queryPointPos.emplace_back(queryPoint[i]);
        }
        else
        {
            outputVector[i] = MathType::GetValue(0);
        }
    }

    if (zeroThreshold < queryPoint[2])
    {
        outputPos = Bisector(extentPos, queryPointPos);
    }
    else  // y[2] = 0
    {
        auto extent2Squared = extent[2] * extent[2];

        MATHEMATICS_ASSERTION_2(extentPos.size() == queryPointPos.size(), "两个数组大小不相等\n");

        const auto numPos = extentPos.size();
        std::array<Real, size> denom{};
        std::array<Real, size> extentMultiplyQueryPoint{};
        for (auto i = 0u; i < numPos && i < denom.size(); ++i)
        {
            denom.at(i) = extentPos.at(i) * extentPos.at(i) - extent2Squared;
            extentMultiplyQueryPoint.at(i) = extentPos.at(i) * queryPointPos.at(i);
        }

        auto inAABBSubEllipse = true;
        for (auto i = 0u; i < numPos; ++i)
        {
            if (denom.at(i) <= extentMultiplyQueryPoint.at(i))
            {
                inAABBSubEllipse = false;
                break;
            }
        }

        squaredDistance = MathType::GetValue(0);

        auto inSubEllipse = false;
        if (inAABBSubEllipse)
        {
            // queryPoint[]在轴对齐包围盒的子椭圆边界框。
            // 这中间测试旨在防范除零错误，当对一些i，extentPos[i] == extent[N - 1]。
            std::array<Real, size> xde{};
            auto discriminant = MathType::GetValue(1);
            for (auto i = 0u; i < numPos; ++i)
            {
                xde.at(i) = extentMultiplyQueryPoint.at(i) / denom.at(i);
                discriminant -= xde.at(i) * xde.at(i);
            }
            if (zeroThreshold < discriminant)
            {
                // queryPoint[]在子椭圆内，最接近椭圆点有outputPos[2] > 0.
                squaredDistance = MathType::GetValue(0);
                for (auto i = 0u; i < numPos; ++i)
                {
                    outputPos.emplace_back(extentPos.at(i) * xde.at(i));
                    auto diff = outputPos.at(i) - queryPoint[i];
                    squaredDistance += diff * diff;
                }
                outputVector[2] = extent[2] * MathType::Sqrt(discriminant);
                squaredDistance += outputVector[2] * outputVector[2];
                inSubEllipse = true;
            }
        }

        if (!inSubEllipse)
        {
            // queryPoint[]在子椭圆之外。最近的椭球点有x[2] == 0，是在域边界椭圆。
            outputVector[2] = MathType::GetValue(0);
            outputPos = Bisector(extentPos, queryPointPos);
        }
    }

    MATHEMATICS_ASSERTION_2(outputPos.size() == 3, "数组大小错误");

    // 填写在最初没有清零的m_OutputVector[]值。
    auto outputVectorIndex = 0;
    for (auto i = 0; i < size; ++i)
    {
        if (zeroThreshold < queryPoint[i])
        {
            outputVector[i] = outputPos.at(outputVectorIndex);
            ++outputVectorIndex;
        }
    }
}

template <typename Real>
typename Mathematics::DistancePoint3Ellipsoid3Tool<Real>::Container Mathematics::DistancePoint3Ellipsoid3Tool<Real>::Bisector(const Container& extent, const Container& queryPoint)
{
    const auto numComponents = extent.size();
    const auto temp = numComponents - 1;
    if (!(0 <= temp && temp < 3))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s));
    }

    std::array<Real, 3> extentSquared{};
    std::array<Real, 3> extentMultiplyQueryPoint{};
    auto argument = MathType::GetValue(0);

    for (auto i = 0u; i < numComponents; ++i)
    {
        extentSquared.at(i) = extent.at(i) * extent.at(i);
        extentMultiplyQueryPoint.at(i) = extent.at(i) * queryPoint.at(i);
        argument += extentMultiplyQueryPoint.at(i) * extentMultiplyQueryPoint.at(i);
    }

    auto beginT = -extentSquared.at(temp) + extentMultiplyQueryPoint.at(temp);
    auto endT = -extentSquared.at(temp) + MathType::Sqrt(argument);
    auto middleT = beginT;
    constexpr auto max = 2 * std::numeric_limits<Real>::max_exponent;
    for (auto index = 0; index < max; ++index)
    {
        middleT = MathType::GetRational(1, 2) * (beginT + endT);
        if (MathType::FAbs(middleT - beginT) <= zeroThreshold || MathType::FAbs(middleT - endT) <= zeroThreshold)
        {
            break;
        }

        auto sum = MathType::GetValue(-1);

        for (auto i = 0u; i < numComponents; ++i)
        {
            auto r = extentMultiplyQueryPoint.at(i) / (middleT + extentSquared.at(i));
            sum += r * r;
        }
        if (zeroThreshold < sum)
        {
            beginT = middleT;
        }
        else if (sum < -zeroThreshold)
        {
            endT = middleT;
        }
        else
        {
            break;
        }
    }

    std::vector<Real> result{};

    squaredDistance = MathType::GetValue(0);
    for (auto i = 0u; i < numComponents; ++i)
    {
        result.emplace_back(extentSquared.at(i) * queryPoint.at(i) / (middleT + extentSquared.at(i)));
        auto diff = result.at(i) - queryPoint.at(i);
        squaredDistance += diff * diff;
    }

    return result;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint3Ellipsoid3Tool<Real>::IsValid() const noexcept
{
    if (MathType::GetValue(0) <= squaredDistance)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::DistancePoint3Ellipsoid3Tool<Real>::GetSquaredDistance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return squaredDistance;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DistancePoint3Ellipsoid3Tool<Real>::GetOutputVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return outputVector;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_DETAIL_H
