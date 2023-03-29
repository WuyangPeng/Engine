///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 17:20)

#include "Framework/FrameworkExport.h"

#include "WindowHBrush.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

Framework::WindowHBrush::WindowHBrush(WindowsBrushTypes background) noexcept
    : hBrush{ System::GetSystemStockObject(background) }
{
    CheckUpHBrush();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::WindowHBrush::CheckUpHBrush() noexcept
{
    if (hBrush == nullptr)
    {
        hBrush = System::GetSystemStockObject(WindowsBrushTypes::WhiteBrush);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework, SYSTEM_TEXT("加载背景画刷失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowHBrush)

System::WindowsHBrush Framework::WindowHBrush::GetHBrush() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return static_cast<HBrush>(hBrush);
}
