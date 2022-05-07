///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 11:19)

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

int Framework::GlutFontInformation::GetCharacterWidth(MAYBE_UNUSED const TChar character) const noexcept
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
