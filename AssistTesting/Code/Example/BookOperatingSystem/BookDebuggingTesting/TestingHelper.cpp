// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 0:06)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookDebugging, TestingHelper, "�鼮 ����ϵͳ ����")

void BookDebugging::TestingHelper
	::AddSuites()
{
	AddDebuggingCppSuite();
	AddAdvancedWindowsDebuggingSuite();
	AddTheDevelopersGuideToDebuggingSuite();
}

void BookDebugging::TestingHelper
	::AddDebuggingCppSuite()
{
	ADD_TEST_BEGIN(debuggingCppSuite, "C++ �������ʵ���ֲ�");

 
	ADD_TEST_END(debuggingCppSuite);
}

void BookDebugging::TestingHelper
	::AddAdvancedWindowsDebuggingSuite()
{
	ADD_TEST_BEGIN(advancedWindowsDebuggingSuite, "Windows �߼�����");


	ADD_TEST_END(advancedWindowsDebuggingSuite);
}

void BookDebugging::TestingHelper
	::AddTheDevelopersGuideToDebuggingSuite()
{
	ADD_TEST_BEGIN(theDevelopersGuideToDebuggingSuite, "�������ʵս ");


	ADD_TEST_END(theDevelopersGuideToDebuggingSuite);
}

