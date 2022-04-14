// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/09/02 12:43)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/InputOutputClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

InputOutput::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "输入输出库"s }
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
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void InputOutput::TestingHelper ::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("配置");

    AddSuite(configurationSuite);
}

void InputOutput::TestingHelper ::AddInputInterfaceSuite()
{
    auto inputInterfaceSuite = GenerateSuite("输入接口");

    AddSuite(inputInterfaceSuite);
}

void InputOutput::TestingHelper ::AddOutputInterfaceSuite()
{
    auto outputInterfaceSuite = GenerateSuite("输出接口");

    AddSuite(outputInterfaceSuite);
}
