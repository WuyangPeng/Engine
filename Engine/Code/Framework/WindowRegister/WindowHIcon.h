///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:00)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H

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
        explicit WindowHIcon(const TChar* icon = System::gApplication) noexcept;
        WindowHIcon(HInstance instance, int icon);

        NODISCARD static WindowHIcon Create(HInstance instance, bool isDefaultIcon, int icon);

        CLASS_INVARIANT_DECLARE;

        NODISCARD HIcon GetHIcon() const noexcept;

    private:
        void CheckUpHIcon() noexcept;

    private:
        HIcon hIcon;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H
