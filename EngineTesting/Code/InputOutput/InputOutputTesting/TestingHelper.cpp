// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/09/02 12:43)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

InputOutput::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���������"s }
{
    InitSuite();

    INPUT_OUTPUT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(InputOutput, TestingHelper)

void InputOutput::TestingHelper::InitSuite()
{
    AddMacroSuite();
    AddConfigurationSuite();
    AddInputInterfaceSuite();
    AddOutputInterfaceSuite();
}

void InputOutput::TestingHelper ::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

void InputOutput::TestingHelper ::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("����");

    AddSuite(configurationSuite);
}

void InputOutput::TestingHelper ::AddInputInterfaceSuite()
{
    auto inputInterfaceSuite = GenerateSuite("����ӿ�");

    AddSuite(inputInterfaceSuite);
}

void InputOutput::TestingHelper ::AddOutputInterfaceSuite()
{
    auto outputInterfaceSuite = GenerateSuite("����ӿ�");

    AddSuite(outputInterfaceSuite);
}
