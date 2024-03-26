/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 00:00)

#include "Mathematics/MathematicsExport.h"

#include "Exp2EstimateDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    void Exp2EstimateInstance()
    {
        MAYBE_UNUSED const auto exp2Estimate = Exp2Estimate<float, 4>(0.0f);
        MAYBE_UNUSED const auto exp2EstimateReal = Exp2EstimateReal<float, 4>(0.0f);
        MAYBE_UNUSED constexpr auto maxError = GetExp2EstimateMaxError<float, 4>();
    }

}

#endif  // MATHEMATICS_TEMPLATE_TEST
