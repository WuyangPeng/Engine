///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/03 14:36)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

Script::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�ű�"s }
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
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void Script::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("����");

    AddSuite(configurationSuite);
}

void Script::TestingHelper::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("�ӿ�");

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
