// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:54)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoop.h"
#include "Detail/WindowMessageLoopImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::move;
using std::make_unique;

Framework::WindowMessageLoop
	::WindowMessageLoop(Display function)
	:m_Impl{ make_unique<ImplType>(function) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowMessageLoop
	::WindowMessageLoop(WindowMessageLoop&& rhs) noexcept
	:m_Impl{ move(rhs.m_Impl) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowMessageLoop& Framework::WindowMessageLoop
	::operator=(WindowMessageLoop&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Impl = move(rhs.m_Impl);

	return *this;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, WindowMessageLoop)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, WindowMessageLoop, EnterMessageLoop, HWnd, System::WindowWParam)

 
