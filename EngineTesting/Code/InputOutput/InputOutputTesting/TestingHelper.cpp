// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/09/02 12:43)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(InputOutput,TestingHelper, "���������") 

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
	ADD_TEST_BEGIN(macroSuite, "��");

	ADD_TEST_END(macroSuite);
}

void InputOutput::TestingHelper
	::AddConfigurationSuite()
{
	ADD_TEST_BEGIN(configurationSuite, "����");

	ADD_TEST_END(configurationSuite);
}

void InputOutput::TestingHelper
	::AddInputInterfaceSuite()
{
	ADD_TEST_BEGIN(inputInterfaceSuite, "����ӿ�");

	ADD_TEST_END(inputInterfaceSuite);
}

void InputOutput::TestingHelper
	::AddOutputInterfaceSuite()
{
	ADD_TEST_BEGIN(outputInterfaceSuite, "����ӿ�");

	ADD_TEST_END(outputInterfaceSuite);
}
 