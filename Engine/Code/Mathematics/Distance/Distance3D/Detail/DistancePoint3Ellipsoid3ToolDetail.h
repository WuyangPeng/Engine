///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 19:11)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_DETAIL_H

#include "DistancePoint3Ellipsoid3Tool.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DistancePoint3Ellipsoid3Tool<Real>::DistancePoint3Ellipsoid3Tool(Real extent0, Real extent1, Real extent2, const Vector3D& vector, Real zeroThreshold)
    : m_Extent{ extent0, extent1, extent2 }, m_InputVector{ vector }, m_OutputVector{}, m_SquaredDistance{ Math::GetValue(0) }, m_ZeroThreshold{ zeroThreshold }
{
    ComputeSquaredDistance();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::DistancePoint3Ellipsoid3Tool<Real>::ComputeSquaredDistance()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    constexpr auto size = 3;

    // 确定m_InputVector的反射到第一象限。
    const std::array<bool, size> reflect{ m_InputVector.GetX() < Math::GetValue(0), m_InputVector.GetY() < Math::GetValue(0), m_InputVector.GetZ() < Math::GetValue(0) };

    // 确定递减辐度轴顺序。
    std::array<int, size> permute{};
    if (m_Extent[0] < m_Extent[1])
    {
        if (m_Extent[2] < m_Extent[0])
        {
            permute[0] = 1;
            permute[1] = 0;
            permute[2] = 2;
        }
        else if (m_Extent[2] < m_Extent[1])
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
        if (m_Extent[2] < m_Extent[1])
        {
            permute[0] = 0;
            permute[1] = 1;
            permute[2] = 2;
        }
        else if (m_Extent[2] < m_Extent[0])
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

    std::array<int, size> invPermute{};
    for (auto index = 0; index < size; ++index)
    {
        invPermute[permute[index]] = index;
    }

    Vector3D localExtent{};
    Vector3D localQueryPoint{};
    for (auto index = 0; index < size; ++index)
    {
        const auto permuteIndex = permute[index];
        localExtent[index] = m_Extent[permuteIndex];
        localQueryPoint[index] = m_InputVector[permuteIndex];
        if (reflect[permuteIndex])
        {
            localQueryPoint[index] = -localQueryPoint[index];
        }
    }

    ComputeSquaredDistanceSpecial(localExtent, localQueryPoint);

    auto local = m_OutputVector;

    // 恢复轴顺序和反射。
    for (auto index = 0; index < size; ++index)
    {
        const auto invPermuteIndex = invPermute[index];
        if (reflect[index])
        {
            local[invPermuteIndex] = -local[invPermuteIndex];
        }
        m_OutputVector[index] = local[invPermuteIndex];
    }

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
void Mathematics::DistancePoint3Ellipsoid3Tool<Real>::ComputeSquaredDistanceSpecial(const Vector3D& extent, const Vector3D& queryPoint)
{
    Container extentPos{};
    Container queryPointPos{};
    Container outputPos{};

    constexpr auto size = 3;

    for (auto i = 0; i < size; ++i)
    {
        if (m_ZeroThreshold < queryPoint[i])
        {
            extentPos.emplace_back(extent[i]);
            queryPointPos.emplace_back(queryPoint[i]);
        }
        else
        {
            m_OutputVector[i] = Math::GetValue(0);
        }
    }

    if (m_ZeroThreshold < queryPoint[2])
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
            denom[i] = extentPos[i] * extentPos[i] - extent2Squared;
            extentMultiplyQueryPoint[i] = extentPos[i] * queryPointPos[i];
        }

        auto inAABBSubEllipse = true;
        for (auto i = 0u; i < numPos; ++i)
        {
            if (denom[i] <= extentMultiplyQueryPoint[i])
            {
                inAABBSubEllipse = false;
                break;
            }
        }

        m_SquaredDistance = Math::GetValue(0);

        auto inSubEllipse = false;
        if (inAABBSubEllipse)
        {
            // queryPoint[]在轴对齐包围盒的子椭圆边界框。
            // 这中间测试旨在防范除零错误，当对一些i，extentPos[i] == extent[N - 1]。
            std::array<Real, size> xde{};
            auto discriminant = Math::GetValue(1);
            for (auto i = 0u; i < numPos; ++i)
            {
                xde[i] = extentMultiplyQueryPoint[i] / denom[i];
                discriminant -= xde[i] * xde[i];
            }
            if (m_ZeroThreshold < discriminant)
            {
                // queryPoint[]在子椭圆内，最接近椭圆点有outputPos[2] > 0.
                m_SquaredDistance = Math::GetValue(0);
                for (auto i = 0u; i < numPos; ++i)
                {
                    outputPos.emplace_back(extentPos[i] * xde[i]);
                    auto diff = outputPos[i] - queryPoint[i];
                    m_SquaredDistance += diff * diff;
                }
                m_OutputVector[2] = extent[2] * Math::Sqrt(discriminant);
                m_SquaredDistance += m_OutputVector[2] * m_OutputVector[2];
                inSubEllipse = true;
            }
        }

        if (!inSubEllipse)
        {
            // queryPoint[]在子椭圆之外。最近的椭球点有x[2] == 0，是在域边界椭圆。
            m_OutputVector[2] = Math::GetValue(0);
            outputPos = Bisector(extentPos, queryPointPos);
        }
    }

    MATHEMATICS_ASSERTION_2(outputPos.size() == 3, "数组大小错误");

    // 填写在最初没有清零的m_OutputVector[]值。
    auto outputVectorIndex = 0;
    for (auto i = 0; i < size; ++i)
    {
        if (m_ZeroThreshold < queryPoint[i])
        {
            m_OutputVector[i] = outputPos[outputVectorIndex];
            ++outputVectorIndex;
        }
    }
}

template <typename Real>
const typename Mathematics::DistancePoint3Ellipsoid3Tool<Real>::Container Mathematics::DistancePoint3Ellipsoid3Tool<Real>::Bisector(const Container& extent, const Container& queryPoint)
{
    const auto numComponents = extent.size();
    const auto temp = numComponents - 1;
    if (!(0 <= temp && temp < 3))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s));
    }

    Real extentSquared[3]{};
    Real extentMultiplyQueryPoint[3]{};
    auto argument = Math::GetValue(0);

    for (auto i = 0u; i < numComponents; ++i)
    {
        extentSquared[i] = extent[i] * extent[i];
        extentMultiplyQueryPoint[i] = extent[i] * queryPoint[i];
        argument += extentMultiplyQueryPoint[i] * extentMultiplyQueryPoint[i];
    }

    auto beginT = -extentSquared[temp] + extentMultiplyQueryPoint[temp];
    auto endT = -extentSquared[temp] + Math::Sqrt(argument);
    auto middleT = beginT;
    constexpr auto max = 2 * std::numeric_limits<Real>::max_exponent;
    for (auto index = 0; index < max; ++index)
    {
        middleT = Math::GetRational(1, 2) * (beginT + endT);
        if (Math::FAbs(middleT - beginT) <= m_ZeroThreshold || Math::FAbs(middleT - endT) <= m_ZeroThreshold)
        {
            break;
        }

        auto sum = static_cast<Real>(-1);
        for (auto i = 0u; i < numComponents; ++i)
        {
            auto r = extentMultiplyQueryPoint[i] / (middleT + extentSquared[i]);
            sum += r * r;
        }
        if (m_ZeroThreshold < sum)
        {
            beginT = middleT;
        }
        else if (sum < -m_ZeroThreshold)
        {
            endT = middleT;
        }
        else
        {
            break;
        }
    }

    std::vector<Real> outputVector;

    m_SquaredDistance = Math::GetValue(0);
    for (auto i = 0u; i < numComponents; ++i)
    {
        outputVector.push_back(extentSquared[i] * queryPoint[i] / (middleT + extentSquared[i]));
        auto diff = outputVector[i] - queryPoint[i];
        m_SquaredDistance += diff * diff;
    }

    return outputVector;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Ellipsoid3Tool<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_SquaredDistance)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::DistancePoint3Ellipsoid3Tool<Real>::GetSquaredDistance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SquaredDistance;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DistancePoint3Ellipsoid3Tool<Real>::GetOutputVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_OutputVector;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_TOOL_DETAIL_H
