/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:27)

#include "Framework/FrameworkExport.h"

#include "WindowMousePosition.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

Framework::WindowMousePosition::WindowMousePosition(WindowsHWnd hWnd) noexcept
    : hWnd{ hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowMousePosition::IsValid() const noexcept
{
    if (ParentType::IsValid() && hWnd != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Framework::WindowPoint Framework::WindowMousePosition::GetMousePosition() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    System::WindowsPoint point{};

    if (!System::GetCursorClientPos(hWnd, point))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("GetCursorClientPos ʧ�ܡ�"));
    }

    return WindowPoint{ point };
}

void Framework::WindowMousePosition::SetMousePosition(const WindowPoint& windowPoint) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const System::WindowsPoint point{ windowPoint.GetWindowX(), windowPoint.GetWindowY() };

    if (!System::SetCursorClientPos(hWnd, point))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("SetCursorClientPos ʧ�ܡ�"));
    }
}

Framework::WindowMousePosition::MousePositionImplSharedPtr Framework::WindowMousePosition::Clone() const
{
    return std::make_shared<ClassType>(hWnd);
}
