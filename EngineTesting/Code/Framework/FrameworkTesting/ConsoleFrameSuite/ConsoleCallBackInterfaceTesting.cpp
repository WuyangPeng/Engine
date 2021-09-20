// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.1 (2020/05/22 23:48)

#include "ConsoleCallBackInterfaceTesting.h"  
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/Contract/Noexcept.h"
Framework::ConsoleCallBackInterfaceTesting
	::ConsoleCallBackInterfaceTesting(const OStreamShared& stream)
	:ParentType{ stream } 
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ConsoleCallBackInterfaceTesting)

void Framework::ConsoleCallBackInterfaceTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ConsoleCallBackInterfaceTesting
	::MainTest()
{
	CoreTools::DisableNoexcept();
}
 