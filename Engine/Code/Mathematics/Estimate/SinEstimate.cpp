/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 20:17)

#include "Mathematics/MathematicsExport.h"

#include "SinEstimateDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    void SinEstimateInstance()
    {
        MAYBE_UNUSED const auto sinEstimate = SinEstimate<float, 5>(0.0f);
        MAYBE_UNUSED const auto sinEstimateReal = SinEstimateReal<float, 5>(0.0f);
        MAYBE_UNUSED constexpr auto maxError = GetSinEstimateMaxError<float, 5>();
    }
}

#endif  // MATHEMATICS_TEMPLATE_TEST
