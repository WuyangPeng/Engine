///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:04)

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