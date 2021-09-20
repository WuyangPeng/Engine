// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/09 20:18)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(UserInterface, TestingHelper, "�û������")

// private
void UserInterface::TestingHelper
	::AddSuites()
{
	AddMacroSuite(); 
	AddConfigurationSuite();
	AddInterfaceSuite();
	AddWxWidgetsSuite();
	AddFLTKSuite();
	AddTrixulSuite();
	AddXFree86Suite();
}

void UserInterface::TestingHelper
	::AddMacroSuite()
{
	ADD_TEST_BEGIN(macroSuite, "��"); 

	ADD_TEST_END(macroSuite);
}
 
void UserInterface::TestingHelper
	::AddConfigurationSuite()
{
	ADD_TEST_BEGIN(configurationSuite, "����"); 

	ADD_TEST_END(configurationSuite);
}

void UserInterface::TestingHelper
	::AddInterfaceSuite()
{
	ADD_TEST_BEGIN(interfaceSuite, "�ӿ�"); 

	ADD_TEST_END(interfaceSuite);
}

void UserInterface::TestingHelper
	::AddWxWidgetsSuite()
{
	ADD_TEST_BEGIN(wxWidgetsSuite, "wxWidgets"); 

	ADD_TEST_END(wxWidgetsSuite);
}

void UserInterface::TestingHelper
	::AddFLTKSuite()
{
	ADD_TEST_BEGIN(fLTKSuite, "FLTK"); 

	ADD_TEST_END(fLTKSuite);
}

void UserInterface::TestingHelper
	::AddTrixulSuite()
{
	ADD_TEST_BEGIN(trixulSuite, "Trixul"); 

	ADD_TEST_END(trixulSuite);
}

void UserInterface::TestingHelper
	::AddXFree86Suite()
{
	ADD_TEST_BEGIN(xFree86Suite, "XFree86"); 

	ADD_TEST_END(xFree86Suite);
}

