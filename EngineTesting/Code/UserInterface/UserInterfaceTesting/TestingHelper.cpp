///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 20:05)

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
    AddHelperSuite();
    AddConfigurationSuite();
    AddInterfaceSuite();
    AddWxWidgetsSuite();
    AddFLTKSuite();
    AddTrixulSuite();
    AddXFree86Suite();
}

void UserInterface::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void UserInterface::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("����");

    AddSuite(configurationSuite);
}

void UserInterface::TestingHelper::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("�ӿ�");

    AddSuite(interfaceSuite);
}

void UserInterface::TestingHelper::AddWxWidgetsSuite()
{
    auto wxWidgetsSuite = GenerateSuite("wxWidgets");

    AddSuite(wxWidgetsSuite);
}

void UserInterface::TestingHelper::AddFLTKSuite()
{
    auto fLTKSuite = GenerateSuite("FLTK");

    AddSuite(fLTKSuite);
}

void UserInterface::TestingHelper::AddTrixulSuite()
{
    auto trixulSuite = GenerateSuite("Trixul");

    AddSuite(trixulSuite);
}

void UserInterface::TestingHelper::AddXFree86Suite()
{
    auto xFree86Suite = GenerateSuite("XFree86");

    AddSuite(xFree86Suite);
}
