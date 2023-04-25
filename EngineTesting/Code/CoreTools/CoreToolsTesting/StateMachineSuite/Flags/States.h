///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 10:48)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STATES_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STATES_H

namespace CoreTools
{
    enum class States
    {
        Empty,
        Open,
        Stopped,
        Playing,
        Paused,
        Previous,
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STATES_H