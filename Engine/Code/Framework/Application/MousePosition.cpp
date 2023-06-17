///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:50)

#include "Framework/FrameworkExport.h"

#include "MousePosition.h"
#include "Detail/MousePositionImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::MousePosition::MousePosition(HWnd hwnd)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Framework, MousePosition)
CLASS_INVARIANT_STUB_DEFINE(Framework, MousePosition)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, MousePosition, SetMousePosition, WindowPoint, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, MousePosition, GetMousePosition, Framework::WindowPoint);
