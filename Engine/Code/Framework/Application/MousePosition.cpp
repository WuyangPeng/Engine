// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "Detail/MousePositionImpl.h"
#include "MousePosition.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

Framework::MousePosition
	::MousePosition(HWnd hwnd)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hwnd }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Framework, MousePosition)
CLASS_INVARIANT_STUB_DEFINE(Framework, MousePosition)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, MousePosition, SetMousePosition, WindowPoint, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, MousePosition, GetMousePosition, const Framework::WindowPoint);



