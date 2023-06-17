///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 19:33)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

// private
ArtificialIntelligence::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�˹����ܿ�" }
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
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void ArtificialIntelligence::TestingHelper::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("����");

    AddSuite(miscellaneousSuite);
}

void ArtificialIntelligence::TestingHelper::AddPathSearchSuite()
{
    auto pathSearchSuite = GenerateSuite("Ѱ·");

    AddSuite(pathSearchSuite);
}

void ArtificialIntelligence::TestingHelper::AddFiniteStateMachineSuite()
{
    auto finiteStateMachineSuite = GenerateSuite("����״̬��");

    AddSuite(finiteStateMachineSuite);
}

void ArtificialIntelligence::TestingHelper::AddFuzzyStateMachineSuite()
{
    auto fuzzyStateMachineSuite = GenerateSuite("ģ��״̬��");

    AddSuite(fuzzyStateMachineSuite);
}

void ArtificialIntelligence::TestingHelper::AddGeneticAlgorithmSuite()
{
    auto geneticAlgorithmSuite = GenerateSuite("�Ŵ��㷨");

    AddSuite(geneticAlgorithmSuite);
}

void ArtificialIntelligence::TestingHelper::AddNeuralNetworkSuite()
{
    auto neuralNetworkSuite = GenerateSuite("������");

    AddSuite(neuralNetworkSuite);
}
