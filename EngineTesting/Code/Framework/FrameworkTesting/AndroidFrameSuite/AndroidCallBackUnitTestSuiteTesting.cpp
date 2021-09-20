// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/12 19:12)

#include "AndroidCallBackUnitTestSuiteTesting.h"
#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuite.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/Contract/Noexcept.h"

Framework::AndroidCallBackUnitTestSuiteTesting
::AndroidCallBackUnitTestSuiteTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidCallBackUnitTestSuiteTesting)

void Framework::AndroidCallBackUnitTestSuiteTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::AndroidCallBackUnitTestSuiteTesting
	::MainTest()
{
	CoreTools::DisableNoexcept();
}


