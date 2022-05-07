// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.4 (2019/09/09 20:18)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

UserInterface::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�û������" }
{
    InitSuite();

    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(UserInterface, TestingHelper)

void UserInterface::TestingHelper::InitSuite()
{
    AddMacroSuite();
    AddConfigurationSuite();
    AddInterfaceSuite();
    AddWxWidgetsSuite();
    AddFLTKSuite();
    AddTrixulSuite();
    AddXFree86Suite();
}

void UserInterface::TestingHelper ::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

void UserInterface::TestingHelper ::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("����");

    AddSuite(configurationSuite);
}

void UserInterface::TestingHelper ::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("�ӿ�");

    AddSuite(interfaceSuite);
}

void UserInterface::TestingHelper ::AddWxWidgetsSuite()
{
    auto wxWidgetsSuite = GenerateSuite("wxWidgets");

    AddSuite(wxWidgetsSuite);
}

void UserInterface::TestingHelper ::AddFLTKSuite()
{
    auto fLTKSuite = GenerateSuite("FLTK");

    AddSuite(fLTKSuite);
}

void UserInterface::TestingHelper ::AddTrixulSuite()
{
    auto trixulSuite = GenerateSuite("Trixul");

    AddSuite(trixulSuite);
}

void UserInterface::TestingHelper ::AddXFree86Suite()
{
    auto xFree86Suite = GenerateSuite("XFree86");

    AddSuite(xFree86Suite);
}
