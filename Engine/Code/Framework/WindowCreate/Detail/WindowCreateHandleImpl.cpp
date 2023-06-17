///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:13)

#include "Framework/FrameworkExport.h"

#include "WindowCreateHandleImpl.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using namespace std::literals;

Framework::WindowCreateHandleImpl::WindowCreateHandleImpl(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size)
    : windowInstanceParameter{ windowInstanceParameter }, windowCreateParameter{ windowCreateParameter }, size{ size }, hwnd{ nullptr }
{
    InitInstance();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::WindowCreateHandleImpl::InitInstance()
{
    // Ҫ�󴰿���ָ���Ŀͻ�����С��
    System::WindowsRect rect{ 0, 0, size.GetWindowWidth() - 1, size.GetWindowHeight() - 1 };

    if (!System::AdjustSystemWindowRect(&rect, windowCreateParameter.GetStyle()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���ڴ�Сʧ�ܣ�"s));
    }

    auto windowClassName = windowInstanceParameter.GetWindowClassName();
    auto windowsName = windowCreateParameter.GetWindowsName();

    // ����Ӧ�ó��򴰿ڡ�
    hwnd = System::CreateSystemWindow(windowClassName.c_str(),
                                      windowsName.c_str(),
                                      windowCreateParameter.GetStyle(),
                                      windowCreateParameter.GetLeftTopCorner().GetWindowX(),
                                      windowCreateParameter.GetLeftTopCorner().GetWindowY(),
                                      rect,
                                      windowCreateParameter.GetParent(),
                                      windowCreateParameter.GetMenu(),
                                      windowInstanceParameter.GetHInstance());

    if (hwnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������ʧ�ܣ�"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowCreateHandleImpl::IsValid() const noexcept
{
    if (hwnd != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Framework::WindowCreateHandleImpl::WindowsHWnd Framework::WindowCreateHandleImpl::GetHwnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return hwnd;
}

void Framework::WindowCreateHandleImpl::SetMainWindow()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHwnd(hwnd);
}
