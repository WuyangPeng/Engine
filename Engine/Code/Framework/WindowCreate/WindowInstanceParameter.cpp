///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:13)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameter.h"
#include "Detail/WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::WindowInstanceParameter::WindowInstanceParameter(WindowsHInstance instance, const String& className)
    : impl{ instance, className }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowInstanceParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowInstanceParameter, GetHInstance, Framework::WindowInstanceParameter::WindowsHInstance)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowInstanceParameter, GetWindowClassName, System::String)
