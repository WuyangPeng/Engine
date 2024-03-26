/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 00:00)

#include "Mathematics/MathematicsExport.h"

#include "ChebyshevRatioDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    void ChebyshevRatioInstance()
    {
        MAYBE_UNUSED const auto chebyshevRatio = ChebyshevRatio(0.0f, 1.0f);
        MAYBE_UNUSED const auto chebyshevRatioUsingCosAngle = ChebyshevRatioUsingCosAngle(0.0f, 1.0f);
        MAYBE_UNUSED const auto chebyshevRatios = ChebyshevRatios(0.0f, 1.0f);
        MAYBE_UNUSED const auto chebyshevRatiosUsingCosAngle = ChebyshevRatiosUsingCosAngle(0.0f, 1.0f);
    }
}

#endif  // MATHEMATICS_TEMPLATE_TEST
