///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:45)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H

#include <ctime>
#include <vector>

namespace CoreTools
{
    struct Play
    {
    };

    struct OpenClose
    {
    };

    struct CdDetected
    {
        CdDetected(const char*, const std::vector<clock_t>&) noexcept;
    };

    struct Pause
    {
    };

    struct Stop
    {
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STATE_H