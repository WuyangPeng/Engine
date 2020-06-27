// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:46)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameter.h"
#include "Detail/WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::WindowInstanceParameter
	::WindowInstanceParameter(HInstance instance, const String& className)
	:m_Impl{ make_shared<ImplType>(instance, className) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, WindowInstanceParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowInstanceParameter, GetHInstance, Framework::WindowInstanceParameter::HInstance)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowInstanceParameter, GetWindowClassName, const System::String)

