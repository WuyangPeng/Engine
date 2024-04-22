/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:03)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorConsoleTextColorsManager.h"
#include "LogConsoleTextColorsManagerImpl.h"
#include "OutputConsoleTextColorsManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"

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
            return TextColour::White;
        case LogLevel::Debug:
            return TextColour::Cyan;
        case LogLevel::Info:
            return TextColour::Green;
        case LogLevel::Warn:
            return TextColour::Yellow;
        case LogLevel::Error:
            return TextColour::Red;
        case LogLevel::Fatal:
            return TextColour::Red;
        default:
            return TextColour::White;
    }
}

bool CoreTools::LogConsoleTextColorsManagerImpl::GetIntensified(LogLevel logLevel) noexcept
{
    if (logLevel == LogLevel::Fatal)
        return true;
    else
        return false;
}
