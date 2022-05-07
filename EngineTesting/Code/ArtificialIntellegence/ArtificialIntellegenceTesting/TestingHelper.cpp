// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.4 (2019/09/09 20:05)

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
void ArtificialIntellegence::TestingHelper ::InitSuite()
{
    AddMacroSuite();
    AddMiscellaneousSuite();
    AddPathSearchSuite();
    AddFiniteStateMachineSuite();
    AddFuzzyStateMachineSuite();
    AddGeneticAlgorithmSuite();
    AddNeuralNetworkSuite();
}

void ArtificialIntellegence::TestingHelper ::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void ArtificialIntellegence::TestingHelper ::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("杂项");

    AddSuite(miscellaneousSuite);
}

void ArtificialIntellegence::TestingHelper ::AddPathSearchSuite()
{
    auto pathSearchSuite = GenerateSuite("寻路");

    AddSuite(pathSearchSuite);
}

void ArtificialIntellegence::TestingHelper ::AddFiniteStateMachineSuite()
{
    auto finiteStateMachineSuite = GenerateSuite("有限状态机");

    AddSuite(finiteStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper ::AddFuzzyStateMachineSuite()
{
    auto fuzzyStateMachineSuite = GenerateSuite("模糊状态机");

    AddSuite(fuzzyStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper ::AddGeneticAlgorithmSuite()
{
    auto geneticAlgorithmSuite = GenerateSuite("遗传算法");

    AddSuite(geneticAlgorithmSuite);
}

void ArtificialIntellegence::TestingHelper ::AddNeuralNetworkSuite()
{
    auto neuralNetworkSuite = GenerateSuite("神经网络");

    AddSuite(neuralNetworkSuite);
}
