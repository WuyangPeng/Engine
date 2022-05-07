///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 10:17)

#ifndef FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H

#include "FontInformationImpl.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowFontInformation final : public FontInformationImpl
    {
    public:
        using ClassType = WindowFontInformation;
        using ParentType = FontInformationImpl;

    public:
        explicit WindowFontInformation(WindowsHWnd hwnd) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetStringWidth(const String& text) const noexcept final;
        NODISCARD int GetCharacterWidth(const TChar character) const final;
        NODISCARD int GetFontHeight() const noexcept final;

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
