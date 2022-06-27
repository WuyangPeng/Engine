///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/21 18:02)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

UserInterface::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "用户界面库" }
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

void UserInterface::TestingHelper::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void UserInterface::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("配置");

    AddSuite(configurationSuite);
}

void UserInterface::TestingHelper::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("接口");

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
