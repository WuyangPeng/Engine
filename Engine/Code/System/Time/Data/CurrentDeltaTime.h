///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 16:36)

#ifndef SYSTEM_TIME_CURRENT_DELTA_TIME_H
#define SYSTEM_TIME_CURRENT_DELTA_TIME_H

#include "System/SystemDll.h"

#include "DeltaTimeValueData.h"
#include "System/Time/Using/DeltaTimeUsing.h"

namespace System
{
    // ��ȡ��ǰʱ��
    class SYSTEM_DEFAULT_DECLARE CurrentDeltaTime final
    {
    public:
        using ClassType = CurrentDeltaTime;

    public:
        CurrentDeltaTime() noexcept;

        NODISCARD const DeltaTimeValueData GetDeltaTimeValueData() const noexcept;

    public:
        DeltaTimeB currentTime;
    };
}

#endif  // SYSTEM_TIME_CURRENT_DELTA_TIME_H