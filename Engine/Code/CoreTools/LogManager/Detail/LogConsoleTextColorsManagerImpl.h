//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:02)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H

#include "CoreTools/Console/ConsoleFwd.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

namespace CoreTools
{
    class LogConsoleTextColorsManagerImpl
    {
    public:
        using ClassType = LogConsoleTextColorsManagerImpl;

    public:
        explicit LogConsoleTextColorsManagerImpl(LogLevel logLevel) noexcept;
        virtual ~LogConsoleTextColorsManagerImpl() noexcept = default;

        LogConsoleTextColorsManagerImpl(const LogConsoleTextColorsManagerImpl&) = delete;
        LogConsoleTextColorsManagerImpl& operator=(const LogConsoleTextColorsManagerImpl&) = delete;
        LogConsoleTextColorsManagerImpl(LogConsoleTextColorsManagerImpl&&) noexcept = delete;
        LogConsoleTextColorsManagerImpl& operator=(LogConsoleTextColorsManagerImpl&&) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] LogLevel GetLogLevel() const noexcept;

    protected:
        [[nodiscard]] static TextColour GetTextColor(LogLevel logLevel) noexcept;
        [[nodiscard]] bool GetIntensified(LogLevel logLevel) noexcept;

    private:
        LogLevel m_LogLevel;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H
