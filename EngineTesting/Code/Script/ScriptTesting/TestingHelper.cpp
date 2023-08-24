///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/03 14:36)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

Script::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "脚本"s }
{
    InitSuite();

    SCRIPT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Script, TestingHelper)

void Script::TestingHelper::InitSuite()
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

void Script::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void Script::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("配置");

    AddSuite(configurationSuite);
}

void Script::TestingHelper::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("接口");

    AddSuite(interfaceSuite);
}

void Script::TestingHelper::AddJavaSuite()
{
    auto javaSuite = GenerateSuite("Java");

    AddSuite(javaSuite);
}

void Script::TestingHelper::AddLuaSuite()
{
    auto luaSuite = GenerateSuite("lua");

    AddSuite(luaSuite);
}

void Script::TestingHelper::AddPerlSuite()
{
    auto perlSuite = GenerateSuite("perl");

    AddSuite(perlSuite);
}

void Script::TestingHelper::AddPythonSuite()
{
    auto pythonSuite = GenerateSuite("python");

    AddSuite(pythonSuite);
}

void Script::TestingHelper::AddTCREScriptSuite()
{
    auto tcreScriptSuite = GenerateSuite("tcreScript");

    AddSuite(tcreScriptSuite);
}
