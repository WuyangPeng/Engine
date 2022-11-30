///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 17:21)

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
    : hCursor{ System::LoadSystemCursor(instance, System::MakeIntreSource(boost::numeric_cast<System::WindowsWord>(cursor))) }
{
    CheckUpHCursor();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::WindowHCursor::CheckUpHCursor() noexcept
{
    if (hCursor == nullptr)
    {
        hCursor = System::LoadSystemCursor(nullptr, System::gArrow);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework)
            << SYSTEM_TEXT("���ع��ʧ�ܣ�")
            << LOG_SINGLETON_TRIGGER_ASSERT;
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
