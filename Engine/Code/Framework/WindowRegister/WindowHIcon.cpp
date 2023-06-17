///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:02)

#include "Framework/FrameworkExport.h"

#include "WindowHIcon.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

Framework::WindowHIcon::WindowHIcon(const TChar* icon) noexcept
    : hIcon{ System::LoadSystemIcon(nullptr, icon) }
{
    CheckUpHIcon();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowHIcon::WindowHIcon(HInstance instance, int icon)
    : hIcon{ System::LoadSystemIcon(instance, System::MakeIntreSource(boost::numeric_cast<System::WindowsWord>(icon))) }
{
    CheckUpHIcon();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::WindowHIcon::CheckUpHIcon() noexcept
{
    if (hIcon == nullptr)
    {
        hIcon = System::LoadSystemIcon(nullptr, System::gApplication);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework, SYSTEM_TEXT("加载图标失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowHIcon)

System::WindowsHIcon Framework::WindowHIcon::GetHIcon() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return hIcon;
}

Framework::WindowHIcon Framework::WindowHIcon::Create(HInstance instance, bool isDefaultIcon, int icon)
{
    if (isDefaultIcon)
    {
        if (icon == 0)
            return WindowHIcon{};
        else
            return WindowHIcon{ nullptr, icon };
    }
    else
    {
        return WindowHIcon{ instance, icon };
    }
}
