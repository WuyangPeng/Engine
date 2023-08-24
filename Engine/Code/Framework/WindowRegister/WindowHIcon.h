///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/03 19:51)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_H_ICON_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_H_ICON_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsPictorialUsing.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowHIcon
    {
    public:
        using ClassType = WindowHIcon;

        using TChar = System::TChar;
        using HIcon = System::WindowsHIcon;
        using HInstance = System::WindowsHInstance;

    public:
        NODISCARD static WindowHIcon Create(HInstance instance, bool isDefaultIcon, int icon);

        explicit WindowHIcon(const TChar* icon = System::gApplication) noexcept;
        WindowHIcon(HInstance instance, int icon);

        CLASS_INVARIANT_DECLARE;

        NODISCARD HIcon GetHIcon() const noexcept;

    private:
        void CheckUpHIcon() noexcept;

    private:
        HIcon hIcon;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_H_ICON_H
