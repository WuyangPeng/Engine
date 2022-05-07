///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:46)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoop.h"
#include "Detail/WindowMessageLoopImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_unique;
using std::move;

Framework::WindowMessageLoop::WindowMessageLoop(Display function)
    : impl{ function }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageLoop)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, WindowMessageLoop, EnterMessageLoop, HWnd, System::WindowsWParam)
