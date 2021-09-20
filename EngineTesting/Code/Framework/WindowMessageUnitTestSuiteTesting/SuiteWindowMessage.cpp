// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.2 (2020/06/06 21:58)

#include "Testing.h"
#include "SuiteWindowMessage.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

Framework::SuiteWindowMessage
	::SuiteWindowMessage(int64_t delta)
	:ParentType{ delta, "��Window Message Unit Test Suite Testing����Ԫ�����׼�"s }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SuiteWindowMessage)

void Framework::SuiteWindowMessage
	::InitSuite()
{
	auto windowProcessSuite = GenerateSuite("���ڽ���"s);

	ADD_TEST_USE_PARAMETER_1(windowProcessSuite, WindowMessageUnitTestSuiteTesting, shared_from_this());

	AddSuite(windowProcessSuite);
}


