/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 00:00)

#include "Mathematics/MathematicsExport.h"

#include "SqrtEstimateDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    void SqrtEstimateInstance()
    {
        MAYBE_UNUSED const auto sinEstimate = SqrtEstimate<float, 5>(0.0f);
        MAYBE_UNUSED const auto sinEstimateReal = SqrtEstimateReal<float, 5>(0.0f);
        MAYBE_UNUSED constexpr auto maxError = GetSqrtEstimateMaxError<float, 5>();
    }
}

#endif  // MATHEMATICS_TEMPLATE_TEST
