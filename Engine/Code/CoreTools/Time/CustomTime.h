/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:28)

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
        NODISCARD int64_t GetThisElapsedTime() noexcept;
        NODISCARD int64_t GetNowTime() noexcept;

        NODISCARD int64_t GetThisElapsedMillisecondTime() noexcept;
        NODISCARD int64_t GetNowMillisecondTime() noexcept;

        NODISCARD static String GetSystemTimeDescribe();
        NODISCARD static String GetSystemTimeDescribe(const String& dateFormat);

    private:
        void MarkTimeThisTick() noexcept;

    private:
        int64_t startTime;
        int64_t currentTime;
        int64_t timeLastTick;
    };
}

#endif  // CORE_TOOLS_TIME_CUSTOM_TIME_H
