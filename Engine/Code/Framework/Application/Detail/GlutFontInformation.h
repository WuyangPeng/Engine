///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/05 19:15)

#ifndef FRAMEWORK_APPLICATION_GLUT_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_GLUT_FONT_INFORMATION_H

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

        NODISCARD int GetStringWidth(const String& text) const final;
        NODISCARD int GetCharacterWidth(const TChar character) const noexcept final;
        NODISCARD int GetFontHeight() const noexcept final;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_FONT_INFORMATION_H
