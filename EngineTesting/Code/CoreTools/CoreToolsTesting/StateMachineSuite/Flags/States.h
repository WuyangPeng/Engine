///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:48)

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