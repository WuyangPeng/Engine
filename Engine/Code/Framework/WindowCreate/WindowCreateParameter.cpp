// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:40)

#include "Framework/FrameworkExport.h"

#include "WindowCreateParameter.h"
#include "Detail/WindowCreateParameterImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowCreateParameter
	::WindowCreateParameter(const System::String& windowsName,
	                        WindowStylesFlags style, HWnd parent, HMenu menu,
							const WindowPoint& leftTopCorner)
	:m_Impl(new ImplType(windowsName,style,parent,menu,leftTopCorner))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,WindowCreateParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowCreateParameter,GetWindowsName,System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowCreateParameter,GetStyle,System::WindowStyles)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowCreateParameter,GetLeftTopCorner,Framework::WindowPoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowCreateParameter,GetParent,Framework::WindowCreateParameter::HWnd)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowCreateParameter,GetMenu,Framework::WindowCreateParameter::HMenu)
