// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:46)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameter.h"
#include "Detail/WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::WindowInstanceParameter ::WindowInstanceParameter(HInstance instance, const String& className)
    : impl{ instance, className }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowInstanceParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowInstanceParameter, GetHInstance, Framework::WindowInstanceParameter::HInstance)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowInstanceParameter, GetWindowClassName, const System::String)
