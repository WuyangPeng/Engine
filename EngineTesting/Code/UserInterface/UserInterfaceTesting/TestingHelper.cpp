///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/01 19:20)

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
    AddOpenGLSuite();
    AddDirectXSuite();
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

void UserInterface::TestingHelper::AddOpenGLSuite()
{
    auto openGLSuite = GenerateSuite("OpenGL");

    AddSuite(openGLSuite);
}

void UserInterface::TestingHelper::AddDirectXSuite()
{
    auto directXSuite = GenerateSuite("DirectX");

    AddSuite(directXSuite);
}
