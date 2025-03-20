/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:22)

#ifndef FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "FontInformationImpl.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowFontInformation final : public FontInformationImpl
    {
    public:
        using ClassType = WindowFontInformation;
        using ParentType = FontInformationImpl;

    public:
        explicit WindowFontInformation(WindowsHWnd hWnd) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetStringWidth(const String& text) const override;
        NODISCARD int GetCharacterWidth(const TChar character) const override;
        NODISCARD int GetFontHeight() const override;

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
