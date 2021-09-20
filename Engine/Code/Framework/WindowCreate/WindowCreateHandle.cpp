// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 09:46)

#include "Framework/FrameworkExport.h"

#include "WindowCreateHandle.h"
#include "Detail/WindowCreateHandleImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::move;
using std::make_shared;

Framework::WindowCreateHandle
	::WindowCreateHandle(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size)
	:impl{  windowInstanceParameter, windowCreateParameter, size  }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowCreateHandle
	::WindowCreateHandle(WindowCreateHandle&& rhs) noexcept
	:impl{ move(rhs.impl) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowCreateHandle& Framework::WindowCreateHandle
	::operator=(WindowCreateHandle&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	impl = move(rhs.impl);

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowCreateHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowCreateHandle, GetHwnd, Framework::WindowCreateHandle::HWnd)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, WindowCreateHandle, SetMainWindow, void)



