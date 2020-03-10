// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:40)

#include "Framework/FrameworkExport.h"

#include "WindowCreateHandle.h"
#include "Detail/WindowCreateHandleImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowCreateHandle
	::WindowCreateHandle(const WindowInstanceParameter& windowInstanceParameter,
						 const WindowCreateParameter& windowCreateParameter,
						 const WindowSize& size)
	:m_Impl(new ImplType(windowInstanceParameter,windowCreateParameter,size))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,WindowCreateHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowCreateHandle,GetHwnd,Framework::WindowCreateHandle::HWnd)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowCreateHandle,SetMainWindow,void)



