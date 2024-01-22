/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:21)

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
