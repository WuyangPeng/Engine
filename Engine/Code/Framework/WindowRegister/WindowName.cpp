// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:36)

#include "Framework/FrameworkExport.h"

#include "WindowName.h"
#include "Detail/WindowNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::WindowName ::WindowName(const String& className, const String& menuName)
    : impl{ className, menuName }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowName)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowName, GetWindowClassName, const System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowName, GetWindowMenuName, const System::String)
