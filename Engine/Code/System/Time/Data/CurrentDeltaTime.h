///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/02/01 23:37)

#ifndef SYSTEM_TIME_CURRENT_DELTA_TIME_H
#define SYSTEM_TIME_CURRENT_DELTA_TIME_H

#include "System/SystemDll.h"

#include "DeltaTimeValueData.h"
#include "System/Time/Using/DeltaTimeUsing.h"

// ��ȡ��ǰʱ��
namespace System
{
    class SYSTEM_DEFAULT_DECLARE CurrentDeltaTime final
    {
    public:
        using ClassType = CurrentDeltaTime;

    public:
        CurrentDeltaTime() noexcept;

        NODISCARD DeltaTimeValueData GetDeltaTimeValueData() const noexcept;

    public:
        DeltaTimeB currentTime;
    };
}

#endif  // SYSTEM_TIME_CURRENT_DELTA_TIME_H