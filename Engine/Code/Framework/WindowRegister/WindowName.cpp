// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:46)

#include "Framework/FrameworkExport.h"

#include "WindowName.h"
#include "Detail/WindowNameImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowName
	::WindowName(const System::String& className, const System::String& menuName)
	:m_Impl(new ImplType(className,menuName))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,WindowName)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowName,GetWindowClassName,const System::String&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowName,GetWindowMenuName,const System::String&)
