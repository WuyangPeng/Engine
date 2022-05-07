///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 11:28)

#include "Framework/FrameworkExport.h"

#include "WindowMousePosition.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::WindowMousePosition::WindowMousePosition(WindowsHWnd hwnd) noexcept
    : hwnd{ hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowMousePosition::IsValid() const noexcept
{
    if (ParentType::IsValid() && hwnd != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Framework::WindowPoint Framework::WindowMousePosition::GetMousePosition() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    System::WindowsPoint point{};

    MAYBE_UNUSED const auto result = System::GetCursorClientPos(hwnd, point);

    return WindowPoint{ point };
}

void Framework::WindowMousePosition::SetMousePosition(const WindowPoint& windowPoint) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::WindowsPoint point{ windowPoint.GetWindowX(), windowPoint.GetWindowY() };

    MAYBE_UNUSED const auto result = System::SetCursorClientPos(hwnd, point);
}

Framework::WindowMousePosition::MousePositionImplSharedPtr Framework::WindowMousePosition::Clone() const
{
    return make_shared<ClassType>(hwnd);
}
