/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:25)

#include "Framework/FrameworkExport.h"

#include "GlutFontInformation.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GlutFontInformation)

int Framework::GlutFontInformation::GetStringWidth(const String& text) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(GetCharacterWidth('0') * text.size());
}

int Framework::GlutFontInformation::GetCharacterWidth(MAYBE_UNUSED TChar character) const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    constexpr auto characterWidth = 8;

    return characterWidth;
}

int Framework::GlutFontInformation::GetFontHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    constexpr auto characterHeight = 13;

    return characterHeight;
}
