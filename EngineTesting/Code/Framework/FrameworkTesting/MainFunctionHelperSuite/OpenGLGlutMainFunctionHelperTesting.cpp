// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.2 (2020/06/02 13:26)

#include "OpenGLGlutMainFunctionHelperTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/FileManager/Directory.h"  

Framework::OpenGLGlutMainFunctionHelperTesting
::OpenGLGlutMainFunctionHelperTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutMainFunctionHelperTesting)

void Framework::OpenGLGlutMainFunctionHelperTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutMainFunctionHelperTesting
	::MainTest()
{
	// �����OpenGLGlutMainFunctionHelperʹ�ù�������ã��޷��������е�Ԫ���ԡ� 

	CoreTools::Directory directory{ System::GetEngineeringDirectory() };

	ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGlutMainFunctionHelper1Test);
}

void Framework::OpenGLGlutMainFunctionHelperTesting
	::OpenGLGlutMainFunctionHelper1Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("OpenGLGlutMainFunctionHelper1")));
}

