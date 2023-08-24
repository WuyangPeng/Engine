///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 15:00)

#ifndef FRAMEWORK_APPLICATION_GLUT_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_GLUT_FONT_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "FontInformationImpl.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE GlutFontInformation final : public FontInformationImpl
    {
    public:
        using ClassType = GlutFontInformation;
        using ParentType = FontInformationImpl;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetStringWidth(const String& text) const override;
        NODISCARD int GetCharacterWidth(TChar character) const noexcept override;
        NODISCARD int GetFontHeight() const noexcept override;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
