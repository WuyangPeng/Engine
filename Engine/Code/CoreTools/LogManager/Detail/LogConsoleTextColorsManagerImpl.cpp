///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:55)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorConsoleTextColorsManager.h"
#include "LogConsoleTextColorsManagerImpl.h"
#include "OutputConsoleTextColorsManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogConsoleTextColorsManagerImpl::LogConsoleTextColorsManagerImpl(LogLevel logLevel) noexcept
    : logLevel{ logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogConsoleTextColorsManagerImpl)

CoreTools::LogLevel CoreTools::LogConsoleTextColorsManagerImpl::GetLogLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return logLevel;
}

CoreTools::TextColour CoreTools::LogConsoleTextColorsManagerImpl::GetTextColor(LogLevel logLevel) noexcept
{
    switch (logLevel)
    {
        case LogLevel::Trace:
            return System::TextColour::White;
        case LogLevel::Debug:
            return System::TextColour::Cyan;
        case LogLevel::Info:
            return System::TextColour::Green;
        case LogLevel::Warn:
            return System::TextColour::Yellow;
        case LogLevel::Error:
            return System::TextColour::Red;
        case LogLevel::Fatal:
            return System::TextColour::Red;
        default:
            return System::TextColour::White;
    }
}

bool CoreTools::LogConsoleTextColorsManagerImpl::GetIntensified(LogLevel logLevel) noexcept
{
    if (logLevel == LogLevel::Fatal)
        return true;
    else
        return false;
}
