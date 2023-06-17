///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 20:08)

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
    AddHelperSuite();
    AddConfigurationSuite();
    AddInputInterfaceSuite();
    AddOutputInterfaceSuite();
}

void InputOutput::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void InputOutput::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("����");

    AddSuite(configurationSuite);
}

void InputOutput::TestingHelper::AddInputInterfaceSuite()
{
    auto inputInterfaceSuite = GenerateSuite("����ӿ�");

    AddSuite(inputInterfaceSuite);
}

void InputOutput::TestingHelper::AddOutputInterfaceSuite()
{
    auto outputInterfaceSuite = GenerateSuite("����ӿ�");

    AddSuite(outputInterfaceSuite);
}
