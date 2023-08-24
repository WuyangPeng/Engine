///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 15:23)

#include "Framework/FrameworkExport.h"

#include "FontInformation.h"
#include "Detail/FontInformationImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::FontInformation::FontInformation(PlatformTypes type)
    : impl{ CoreTools::ImplCreateUseFactory::Default, type }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::FontInformation::FontInformation(WindowsHWnd hWnd)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FontInformation)

int Framework::FontInformation::GetStringWidth(const String& text) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetStringWidth(text);
}

int Framework::FontInformation::GetCharacterWidth(TChar character) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCharacterWidth(character);
}

int Framework::FontInformation::GetFontHeight() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetFontHeight();
}
