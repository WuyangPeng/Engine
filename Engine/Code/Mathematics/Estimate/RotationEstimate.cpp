/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 00:00)

#include "Mathematics/MathematicsExport.h"

#include "RotationEstimateDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    void RotationInstance()
    {
        MAYBE_UNUSED const auto rotC0Estimate = RotC0Estimate<float, 4>(0.0f);
        MAYBE_UNUSED const auto rotC1Estimate = RotC1Estimate<float, 4>(0.0f);
        MAYBE_UNUSED const auto rotC2Estimate = RotC2Estimate<float, 4>(0.0f);
        MAYBE_UNUSED const auto rotC3Estimate = RotC3Estimate<float, 4>(0.0f);
        MAYBE_UNUSED constexpr auto rotC0EstimateMaxError = GetRotC0EstimateMaxError<float, 4>();
        MAYBE_UNUSED constexpr auto rotC1EstimateMaxError = GetRotC1EstimateMaxError<float, 4>();
        MAYBE_UNUSED constexpr auto rotC2EstimateMaxError = GetRotC2EstimateMaxError<float, 4>();
        MAYBE_UNUSED constexpr auto rotC3EstimateMaxError = GetRotC3EstimateMaxError<float, 4>();
        MAYBE_UNUSED const auto rotationEstimate = RotationEstimate<float, 4>(Vector3{ 1.0f, 2.0f, 3.0f });
        MAYBE_UNUSED const auto rotationDerivativeEstimate = RotationDerivativeEstimate<float, 4>(Vector3{ 1.0f, 2.0f, 3.0f });
    }
}

#endif  // MATHEMATICS_TEMPLATE_TEST
