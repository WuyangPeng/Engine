// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助版本：0.0.0.2 (2019/09/27 21:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookDebugging, TestingHelper, "书籍 操作系统 调试")

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
	ADD_TEST_BEGIN(debuggingCppSuite, "C++ 程序调试实用手册");

 
	ADD_TEST_END(debuggingCppSuite);
}

void BookDebugging::TestingHelper
	::AddAdvancedWindowsDebuggingSuite()
{
	ADD_TEST_BEGIN(advancedWindowsDebuggingSuite, "Windows 高级调试");


	ADD_TEST_END(advancedWindowsDebuggingSuite);
}

void BookDebugging::TestingHelper
	::AddTheDevelopersGuideToDebuggingSuite()
{
	ADD_TEST_BEGIN(theDevelopersGuideToDebuggingSuite, "软件调试实战 ");


	ADD_TEST_END(theDevelopersGuideToDebuggingSuite);
}

