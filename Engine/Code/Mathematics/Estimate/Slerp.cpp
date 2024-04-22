/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 00:00)

#include "Mathematics/MathematicsExport.h"

#include "SlerpDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    void SlerpInstance()
    {
        constexpr std::array<float, 5> q0{};
        constexpr std::array<float, 5> q1{};
        constexpr std::array<float, 5> qh{};
        MAYBE_UNUSED const auto slerp0 = Slerp(0.0f, q0, q1);
        MAYBE_UNUSED const auto slerp1 = Slerp(0.0f, q0, q1, 0.0f);
        MAYBE_UNUSED const auto slerp2 = Slerp(0.0f, q0, q1, qh, .0f);
    }
}

#endif  // MATHEMATICS_TEMPLATE_TEST
