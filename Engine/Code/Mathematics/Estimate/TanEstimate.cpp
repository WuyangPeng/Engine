/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 00:00)

#include "Mathematics/MathematicsExport.h"

#include "TanEstimateDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    void TanEstimateInstance()
    {
        MAYBE_UNUSED const auto tanEstimate = TanEstimate<float, 5>(0.0f);
        MAYBE_UNUSED const auto tanEstimateReal = TanEstimateReal<float, 5>(0.0f);
        MAYBE_UNUSED constexpr auto maxError = GetTanEstimateMaxError<float, 5>();
    }
}

#endif  // MATHEMATICS_TEMPLATE_TEST
