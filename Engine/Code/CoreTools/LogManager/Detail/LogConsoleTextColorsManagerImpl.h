///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 15:24)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H

#include "CoreTools/Console/ConsoleFwd.h"
#include "CoreTools/LogManager/LogManagerInternalFwd.h"

namespace CoreTools
{
    class LogConsoleTextColorsManagerImpl
    {
    public:
        using ClassType = LogConsoleTextColorsManagerImpl;
        using FactoryType = LogConsoleTextColorsManagerFactory;

    public:
        explicit LogConsoleTextColorsManagerImpl(LogLevel logLevel) noexcept;
        virtual ~LogConsoleTextColorsManagerImpl() noexcept = default;

        LogConsoleTextColorsManagerImpl(const LogConsoleTextColorsManagerImpl&) = delete;
        LogConsoleTextColorsManagerImpl& operator=(const LogConsoleTextColorsManagerImpl&) = delete;
        LogConsoleTextColorsManagerImpl(LogConsoleTextColorsManagerImpl&&) noexcept = delete;
        LogConsoleTextColorsManagerImpl& operator=(LogConsoleTextColorsManagerImpl&&) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD LogLevel GetLogLevel() const noexcept;

    protected:
        NODISCARD static TextColour GetTextColor(LogLevel logLevel) noexcept;
        NODISCARD static bool GetIntensified(LogLevel logLevel) noexcept;

    private:
        LogLevel logLevel;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_CONSOLE_TEXT_COLOR_MANAGER_IMPL_H
