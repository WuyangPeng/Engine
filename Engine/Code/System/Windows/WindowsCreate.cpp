/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/26 13:03)

#include "System/SystemExport.h"

#include "WindowsCreate.h"
#include "Flags/WindowsCreateFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"

namespace System
{
    /// ��ȡָ�����ڵ���Ϣ��
    ///
    /// @param hWnd ���ھ����
    /// @param result �洢������Ϣ���ַ�����
    /// @param getWindowsInformationFunction ���ڻ�ȡ������Ϣ�ĺ���ָ�롣
    /// @return ����ɹ���ȡ������Ϣ���򷵻�true�����򷵻�false��
    bool GetWindowsInformation(WindowsHWnd hWnd, String& result, GetWindowsInformationFunction getWindowsInformationFunction)
    {
        TCharContainer name{};

        if (getWindowsInformationFunction != nullptr && getWindowsInformationFunction(hWnd, name.data(), gMaxPath) == 0)
        {
            result.clear();
            return false;
        }
        else
        {
            result = name.data();
            return true;
        }
    }
}

bool System::AdjustSystemWindowRect(WindowsRect* rect, WindowsStyles styles) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::AdjustWindowRect(rect, EnumCastUnderlying(styles), gFalse) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(rect, styles);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHWnd System::CreateSystemWindow(const String& className,
                                               const String& windowsName,
                                               WindowsStyles styles,
                                               int x,
                                               int y,
                                               WindowsRect rect,
                                               WindowsHWnd parent,
                                               WindowsHMenu menu,
                                               WindowsHInstance instance) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateWindow(className.c_str(),
                          windowsName.c_str(),
                          EnumCastUnderlying(styles),
                          x,
                          y,
                          rect.right - rect.left + 1,
                          rect.bottom - rect.top + 1,
                          parent,
                          menu,
                          instance,
                          nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(className,
                   windowsName,
                   styles,
                   x,
                   y,
                   rect,
                   parent,
                   menu,
                   instance);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemClassName(WindowsHWnd hWnd, String& className)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return GetWindowsInformation(hWnd, className, ::GetClassName);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    className.clear();

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetWindowTextString(WindowsHWnd hWnd, String& windowText)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return GetWindowsInformation(hWnd, windowText, ::GetWindowText);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    windowText.clear();

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHInstance System::GetHInstance() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetModuleHandle(nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveMenuCloseButton(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto menu = GetWindowSystemMenu(hWnd);

    return menu != nullptr && RemoveSystemMenu(menu, SystemMenuCommand::Close, MenuItem::ByCommand);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHMenu System::GetWindowSystemMenu(WindowsHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetSystemMenu(hWnd, gFalse);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hWnd);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveSystemMenu(WindowsHMenu menu, SystemMenuCommand position, MenuItem flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::RemoveMenu(menu, EnumCastUnderlying(position), EnumCastUnderlying(flags)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(menu, position, flags);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
