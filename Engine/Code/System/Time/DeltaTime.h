/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 16:36)

#ifndef SYSTEM_TIME_DELTA_TIME_H
#define SYSTEM_TIME_DELTA_TIME_H

#include "System/SystemDll.h"

#include "Data/DeltaTimeValueData.h"

namespace System
{
    /// ��ȡ��ǰʱ��
    NODISCARD SYSTEM_DEFAULT_DECLARE int64_t GetTimeInMicroseconds(const DeltaTimeValueData& deltaTime) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE int64_t GetTimeInSeconds(const DeltaTimeValueData& deltaTime) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE int64_t GetTimeInMicroseconds() noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE int64_t GetTimeInSeconds() noexcept;

    /// ��ͣ����̨
    SYSTEM_DEFAULT_DECLARE void SystemPause() noexcept;
}

#endif  // SYSTEM_TIME_DELTA_TIME_H
