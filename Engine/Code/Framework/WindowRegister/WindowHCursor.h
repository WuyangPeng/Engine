///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/03 19:58)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_H_CURSOR_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_H_CURSOR_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsPictorialUsing.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowHCursor
    {
    public:
        using ClassType = WindowHCursor;

        using TChar = System::TChar;
        using HCursor = System::WindowsHCursor;
        using HInstance = System::WindowsHInstance;

    public:
        explicit WindowHCursor(const TChar* cursor = System::gArrow) noexcept;
        WindowHCursor(HInstance instance, int cursor);

        NODISCARD static WindowHCursor Create(HInstance instance, bool isDefaultCursor, int cursor);

        CLASS_INVARIANT_DECLARE;

        NODISCARD HCursor GetHCursor() const noexcept;

    private:
        void CheckUpHCursor() noexcept;

    private:
        HCursor hCursor;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_H_CURSOR_H
