// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:22)

#include "Framework/FrameworkExport.h"

#include "Detail/FontInformationImpl.h"
#include "FontInformation.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::FontInformation
	::FontInformation(PlatformTypes type)
	:m_Impl(FontInformationImpl::CreateFontInformation(type))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::FontInformation
	::FontInformation( HWND hwnd )
	:m_Impl(FontInformationImpl::CreateWindowFontInformation(hwnd))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,FontInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework,FontInformation,GetStringWidth,System::String,int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework,FontInformation,GetCharacterWidth,const TCHAR,int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,FontInformation,GetFontHeight,int);
