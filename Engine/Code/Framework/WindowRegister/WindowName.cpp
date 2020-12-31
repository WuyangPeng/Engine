// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:36)

#include "Framework/FrameworkExport.h"

#include "WindowName.h"
#include "Detail/WindowNameImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::WindowName
	::WindowName(const String& className, const String& menuName)
	:m_Impl{ make_shared<ImplType>(className,menuName) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, WindowName)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowName, GetWindowClassName, const System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowName, GetWindowMenuName, const System::String)
