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

Framework::MousePosition
	::MousePosition(HWnd hwnd)
	:m_Impl{ MousePositionImpl::CreateWindowMousePosition(hwnd) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, MousePosition)

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(Framework, MousePosition)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework, MousePosition, SetMousePosition, WindowPoint, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, MousePosition, GetMousePosition, const Framework::WindowPoint);



