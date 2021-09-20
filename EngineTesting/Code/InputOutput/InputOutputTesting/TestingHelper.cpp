// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/09/02 12:43)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(InputOutput,TestingHelper, "输入输出库") 

// private
void InputOutput::TestingHelper ::AddSuites()
{
	AddMacroSuite();
	AddConfigurationSuite();
	AddInputInterfaceSuite();
	AddOutputInterfaceSuite();
}

void InputOutput::TestingHelper
	::AddMacroSuite()
{
	ADD_TEST_BEGIN(macroSuite, "宏");

	ADD_TEST_END(macroSuite);
}

void InputOutput::TestingHelper
	::AddConfigurationSuite()
{
	ADD_TEST_BEGIN(configurationSuite, "配置");

	ADD_TEST_END(configurationSuite);
}

void InputOutput::TestingHelper
	::AddInputInterfaceSuite()
{
	ADD_TEST_BEGIN(inputInterfaceSuite, "输入接口");

	ADD_TEST_END(inputInterfaceSuite);
}

void InputOutput::TestingHelper
	::AddOutputInterfaceSuite()
{
	ADD_TEST_BEGIN(outputInterfaceSuite, "输出接口");

	ADD_TEST_END(outputInterfaceSuite);
}
 