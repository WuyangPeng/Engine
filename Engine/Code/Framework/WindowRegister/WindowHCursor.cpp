/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:13)

#include "Framework/FrameworkExport.h"

#include "WindowHCursor.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

Framework::WindowHCursor::WindowHCursor(const TChar* cursor) noexcept
    : hCursor{ System::LoadSystemCursor(nullptr, cursor) }
{
    CheckUpHCursor();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowHCursor::WindowHCursor(HInstance instance, int cursor)
    : hCursor{ System::LoadSystemCursor(instance, System::MakeIntResource(boost::numeric_cast<System::WindowsWord>(cursor))) }
{
    CheckUpHCursor();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void Framework::WindowHCursor::CheckUpHCursor() noexcept
{
    if (hCursor == nullptr)
    {
        hCursor = System::LoadSystemCursor(nullptr, System::gArrow);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework, SYSTEM_TEXT("加载光标失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowHCursor)

System::WindowsHCursor Framework::WindowHCursor::GetHCursor() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return hCursor;
}

Framework::WindowHCursor Framework::WindowHCursor::Create(HInstance instance, bool isDefaultCursor, int cursor)
{
    if (isDefaultCursor)
    {
        if (cursor == 0)
            return WindowHCursor{};
        else
            return WindowHCursor{ nullptr, cursor };
    }
    else
    {
        return WindowHCursor{ instance, cursor };
    }
}
