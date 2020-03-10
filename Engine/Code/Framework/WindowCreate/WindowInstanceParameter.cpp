// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:40)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameter.h"
#include "Detail/WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowInstanceParameter
	::WindowInstanceParameter(HInstance hInstance,const System::String& className)
	:m_Impl(new ImplType(hInstance,className))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,WindowInstanceParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowInstanceParameter,GetHInstance,Framework::WindowInstanceParameter::HInstance)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowInstanceParameter,GetWindowClassName,System::String)

