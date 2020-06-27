// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "Detail/FontInformationImpl.h"
#include "FontInformation.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FontInformation
	::FontInformation(PlatformTypes type)
	:m_Impl{ FontInformationImpl::CreateFontInformation(type) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::FontInformation
	::FontInformation(HWnd hwnd)
	:m_Impl{ FontInformationImpl::CreateWindowFontInformation(hwnd) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, FontInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, FontInformation, GetStringWidth, String, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, FontInformation, GetCharacterWidth, const TChar, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, FontInformation, GetFontHeight, int);
