//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/24 12:47)

#ifndef SYSTEM_TIME_CURRENT_DELTA_TIME_H
#define SYSTEM_TIME_CURRENT_DELTA_TIME_H

#include "System/SystemDll.h"

#include "DeltaTimeValueData.h"
#include "System/Time/Using/DeltaTimeUsing.h"

namespace System
{
    // ��ȡ��ǰʱ��
    class SYSTEM_DEFAULT_DECLARE CurrentDeltaTime
    {
    public:
        using ClassType = CurrentDeltaTime;

    public:
        CurrentDeltaTime() noexcept;

        [[nodiscard]] const DeltaTimeValueData GetDeltaTimeValueData() const noexcept;

    public:
        DeltaTimeB m_CurrentTime;
    };
}

#endif  // SYSTEM_TIME_CURRENT_DELTA_TIME_H