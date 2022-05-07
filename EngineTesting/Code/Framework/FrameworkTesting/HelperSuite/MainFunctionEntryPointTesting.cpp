// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.1 (2020/05/26 09:48)

#include "MainFunctionEntryPointTesting.h"  
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/FileManager/Directory.h"

Framework::MainFunctionEntryPointTesting
	::MainFunctionEntryPointTesting(const OStreamShared& stream)
	:ParentType{ stream } 
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainFunctionEntryPointTesting)

void Framework::MainFunctionEntryPointTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MainFunctionEntryPointTesting
	::MainTest()
{	
	CoreTools::Directory directory{ System::GetEngineeringDirectory() };

	// ��ڵ㺯��WinMainEntryPoint��MainEntryPoint��GlutMainEntryPoint��AndroidMainEntryPointʹ�ù�������ã�
	// �޷��������е�Ԫ���ԡ�

	ASSERT_NOT_THROW_EXCEPTION_0(WinMainEntryPoint1Test);
	ASSERT_NOT_THROW_EXCEPTION_0(WinMainEntryPoint2Test);
	ASSERT_NOT_THROW_EXCEPTION_0(MainEntryPoint1Test);
	ASSERT_NOT_THROW_EXCEPTION_0(GlutMainEntryPoint1Test);
	ASSERT_NOT_THROW_EXCEPTION_0(AndroidMainEntryPoint1Test);	
}

void Framework::MainFunctionEntryPointTesting
	::WinMainEntryPoint1Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("WinMainEntryPoint1")));
}

void Framework::MainFunctionEntryPointTesting
	::WinMainEntryPoint2Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("WinMainEntryPoint2")));
}

void Framework::MainFunctionEntryPointTesting
	::MainEntryPoint1Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("MainEntryPoint1")));
}

void Framework::MainFunctionEntryPointTesting
	::GlutMainEntryPoint1Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("GlutMainEntryPoint1")));
}

void Framework::MainFunctionEntryPointTesting
	::AndroidMainEntryPoint1Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("AndroidMainEntryPoint1")));
}
