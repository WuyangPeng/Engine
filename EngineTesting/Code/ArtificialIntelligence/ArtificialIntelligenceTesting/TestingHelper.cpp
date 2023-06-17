///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 19:33)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

// private
ArtificialIntelligence::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "人工智能库" }
{
    InitSuite();

    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ArtificialIntelligence, TestingHelper)

// private
void ArtificialIntelligence::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddMiscellaneousSuite();
    AddPathSearchSuite();
    AddFiniteStateMachineSuite();
    AddFuzzyStateMachineSuite();
    AddGeneticAlgorithmSuite();
    AddNeuralNetworkSuite();
}

void ArtificialIntelligence::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void ArtificialIntelligence::TestingHelper::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("杂项");

    AddSuite(miscellaneousSuite);
}

void ArtificialIntelligence::TestingHelper::AddPathSearchSuite()
{
    auto pathSearchSuite = GenerateSuite("寻路");

    AddSuite(pathSearchSuite);
}

void ArtificialIntelligence::TestingHelper::AddFiniteStateMachineSuite()
{
    auto finiteStateMachineSuite = GenerateSuite("有限状态机");

    AddSuite(finiteStateMachineSuite);
}

void ArtificialIntelligence::TestingHelper::AddFuzzyStateMachineSuite()
{
    auto fuzzyStateMachineSuite = GenerateSuite("模糊状态机");

    AddSuite(fuzzyStateMachineSuite);
}

void ArtificialIntelligence::TestingHelper::AddGeneticAlgorithmSuite()
{
    auto geneticAlgorithmSuite = GenerateSuite("遗传算法");

    AddSuite(geneticAlgorithmSuite);
}

void ArtificialIntelligence::TestingHelper::AddNeuralNetworkSuite()
{
    auto neuralNetworkSuite = GenerateSuite("神经网络");

    AddSuite(neuralNetworkSuite);
}
