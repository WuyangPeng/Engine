// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "FontInformation.h"
#include "Detail/FontInformationImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::FontInformation ::FontInformation(PlatformTypes type)
    : impl{ CoreTools::ImplCreateUseFactory::Default, type }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::FontInformation ::FontInformation(HWnd hwnd)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FontInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, FontInformation, GetStringWidth, String, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, FontInformation, GetCharacterWidth, const TChar, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, FontInformation, GetFontHeight, int);
