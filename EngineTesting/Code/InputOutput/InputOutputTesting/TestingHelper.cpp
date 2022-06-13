///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/10 16:13)

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

void InputOutput::TestingHelper::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void InputOutput::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("配置");

    AddSuite(configurationSuite);
}

void InputOutput::TestingHelper::AddInputInterfaceSuite()
{
    auto inputInterfaceSuite = GenerateSuite("输入接口");

    AddSuite(inputInterfaceSuite);
}

void InputOutput::TestingHelper::AddOutputInterfaceSuite()
{
    auto outputInterfaceSuite = GenerateSuite("输出接口");

    AddSuite(outputInterfaceSuite);
}
