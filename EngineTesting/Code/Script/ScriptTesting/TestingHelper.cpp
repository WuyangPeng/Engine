// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/17 11:14)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Script, TestingHelper, "Ω≈±æ")

// private
void Script::TestingHelper
	::AddSuites()
{
	AddHelperSuite();
	AddConfigurationSuite();
	AddInterfaceSuite();
	AddJavaSuite();
	AddLuaSuite();
	AddPerlSuite();
	AddPythonSuite();
	AddTCREScriptSuite();
}

void Script::TestingHelper
	::AddHelperSuite()
{
	ADD_TEST_BEGIN(helperSuite, "∞Ô÷˙");

	ADD_TEST_END(helperSuite);
}

void Script::TestingHelper
	::AddConfigurationSuite()
{
	ADD_TEST_BEGIN(configurationSuite, "≈‰÷√");

	ADD_TEST_END(configurationSuite);
}

void Script::TestingHelper
	::AddInterfaceSuite()
{
	ADD_TEST_BEGIN(interfaceSuite, "Ω”ø⁄");

	ADD_TEST_END(interfaceSuite);
}

void Script::TestingHelper
	::AddJavaSuite()
{
	ADD_TEST_BEGIN(javaSuite, "Java");

	ADD_TEST_END(javaSuite);
}

void Script::TestingHelper
	::AddLuaSuite()
{
	ADD_TEST_BEGIN(luaSuite, "lua");

	ADD_TEST_END(luaSuite);
}

void Script::TestingHelper
	::AddPerlSuite()
{
	ADD_TEST_BEGIN(perlSuite, "perl");

	ADD_TEST_END(perlSuite);
}

void Script::TestingHelper
	::AddPythonSuite()
{
	ADD_TEST_BEGIN(pythonSuite, "python");

	ADD_TEST_END(pythonSuite);
}

void Script::TestingHelper
	::AddTCREScriptSuite()
{
	ADD_TEST_BEGIN(tcreScriptSuite, "tcreScript");

	ADD_TEST_END(tcreScriptSuite);
}

