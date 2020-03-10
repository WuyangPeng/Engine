// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:23)

#include "Framework/FrameworkExport.h"

#include "Detail/MousePositionImpl.h"
#include "MousePosition.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::MousePosition
	::MousePosition(HWND hwnd)
	:m_Impl(MousePositionImpl::CreateWindowMousePositionPtr(hwnd))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,MousePosition)

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(Framework,MousePosition)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(Framework,MousePosition,SetMousePosition,WindowPoint,void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,MousePosition,GetMousePosition,const Framework::WindowPoint);



