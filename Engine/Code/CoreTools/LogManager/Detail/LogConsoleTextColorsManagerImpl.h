///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 16:14)

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
