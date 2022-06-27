///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/21 17:13)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

// private
ArtificialIntellegence::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "人工智能库" }
{
    InitSuite();

    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ArtificialIntellegence, TestingHelper)

// private
void ArtificialIntellegence::TestingHelper::InitSuite()
{
    AddMacroSuite();
    AddMiscellaneousSuite();
    AddPathSearchSuite();
    AddFiniteStateMachineSuite();
    AddFuzzyStateMachineSuite();
    AddGeneticAlgorithmSuite();
    AddNeuralNetworkSuite();
}

void ArtificialIntellegence::TestingHelper::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void ArtificialIntellegence::TestingHelper::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("杂项");

    AddSuite(miscellaneousSuite);
}

void ArtificialIntellegence::TestingHelper::AddPathSearchSuite()
{
    auto pathSearchSuite = GenerateSuite("寻路");

    AddSuite(pathSearchSuite);
}

void ArtificialIntellegence::TestingHelper::AddFiniteStateMachineSuite()
{
    auto finiteStateMachineSuite = GenerateSuite("有限状态机");

    AddSuite(finiteStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper::AddFuzzyStateMachineSuite()
{
    auto fuzzyStateMachineSuite = GenerateSuite("模糊状态机");

    AddSuite(fuzzyStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper::AddGeneticAlgorithmSuite()
{
    auto geneticAlgorithmSuite = GenerateSuite("遗传算法");

    AddSuite(geneticAlgorithmSuite);
}

void ArtificialIntellegence::TestingHelper::AddNeuralNetworkSuite()
{
    auto neuralNetworkSuite = GenerateSuite("神经网络");

    AddSuite(neuralNetworkSuite);
}
