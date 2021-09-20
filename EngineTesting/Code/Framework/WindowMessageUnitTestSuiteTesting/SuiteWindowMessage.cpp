// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.3.0.2 (2020/06/06 21:58)

#include "Testing.h"
#include "SuiteWindowMessage.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

Framework::SuiteWindowMessage
	::SuiteWindowMessage(int64_t delta)
	:ParentType{ delta, "【Window Message Unit Test Suite Testing】单元测试套件"s }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SuiteWindowMessage)

void Framework::SuiteWindowMessage
	::InitSuite()
{
	auto windowProcessSuite = GenerateSuite("窗口进程"s);

	ADD_TEST_USE_PARAMETER_1(windowProcessSuite, WindowMessageUnitTestSuiteTesting, shared_from_this());

	AddSuite(windowProcessSuite);
}


