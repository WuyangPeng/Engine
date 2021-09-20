//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 18:44)

#ifndef CORE_TOOLS_TIME_CUSTOM_TIME_H
#define CORE_TOOLS_TIME_CUSTOM_TIME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CustomTime final
    {
    public:
        using ClassType = CustomTime;
        using String = System::String;

    public:
        CustomTime() noexcept;

        CLASS_INVARIANT_DECLARE;

        void ResetCustomTime() noexcept;
        [[nodiscard]] int64_t GetThisElapsedTime() noexcept;
        [[nodiscard]] int64_t GetNowTime() noexcept;

        [[nodiscard]] int64_t GetThisElapsedMillisecondTime() noexcept;
        [[nodiscard]] int64_t GetNowMillisecondTime() noexcept;

        [[nodiscard]] static String GetSystemTimeDescribe();
        [[nodiscard]] static String GetSystemTimeDescribe(const String& dateFormat);

    private:
        void MarkTimeThisTick() noexcept;

    private:
        int64_t m_StartTime;
        int64_t m_CurrentTime;
        int64_t m_TimeLastTick;
    };
}

#endif  // CORE_TOOLS_TIME_CUSTOM_TIME_H
