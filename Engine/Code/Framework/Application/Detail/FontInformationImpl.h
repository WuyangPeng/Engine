///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 19:14)

#ifndef FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE FontInformationImpl
    {
    public:
        using ClassType = FontInformationImpl;
        using FontInformationImplSharedPtr = std::shared_ptr<ClassType>;
        using TChar = System::TChar;
        using String = System::String;
        using WindowsHWnd = System::WindowsHWnd;
        using FactoryType = FontInformationImpl;

    public:
        FontInformationImpl() noexcept = default;
        virtual ~FontInformationImpl() noexcept = default;
        FontInformationImpl(const FontInformationImpl& rhs) noexcept = default;
        FontInformationImpl(FontInformationImpl&& rhs) noexcept = default;
        FontInformationImpl& operator=(const FontInformationImpl& rhs) noexcept = default;
        FontInformationImpl& operator=(FontInformationImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 字体信息。这些是特定于平台的。
        NODISCARD virtual int GetStringWidth(const String& text) const = 0;
        NODISCARD virtual int GetCharacterWidth(const TChar character) const = 0;
        NODISCARD virtual int GetFontHeight() const = 0;

        NODISCARD static FontInformationImplSharedPtr Create(WindowsHWnd hwnd);
        NODISCARD static FontInformationImplSharedPtr Create(PlatformTypes type);
    };
}

#endif  // FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H
