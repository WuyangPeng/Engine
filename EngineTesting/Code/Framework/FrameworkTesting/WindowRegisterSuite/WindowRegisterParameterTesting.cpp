// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.2 (2020/06/07 10:59)

#include "WindowRegisterParameterTesting.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

Framework::WindowRegisterParameterTesting
	::WindowRegisterParameterTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowRegisterParameterTesting)

void Framework::WindowRegisterParameterTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowRegisterParameterTesting
	::MainTest()
{
	// ������FrameworkWindowTesting�У���Ҫ���ڻ�����

	CoreTools::DisableNoexcept();
}

