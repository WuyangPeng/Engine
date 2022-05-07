// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.4 (2019/09/09 20:05)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

// private
ArtificialIntellegence::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�˹����ܿ�" }
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
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

void ArtificialIntellegence::TestingHelper ::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("����");

    AddSuite(miscellaneousSuite);
}

void ArtificialIntellegence::TestingHelper ::AddPathSearchSuite()
{
    auto pathSearchSuite = GenerateSuite("Ѱ·");

    AddSuite(pathSearchSuite);
}

void ArtificialIntellegence::TestingHelper ::AddFiniteStateMachineSuite()
{
    auto finiteStateMachineSuite = GenerateSuite("����״̬��");

    AddSuite(finiteStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper ::AddFuzzyStateMachineSuite()
{
    auto fuzzyStateMachineSuite = GenerateSuite("ģ��״̬��");

    AddSuite(fuzzyStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper ::AddGeneticAlgorithmSuite()
{
    auto geneticAlgorithmSuite = GenerateSuite("�Ŵ��㷨");

    AddSuite(geneticAlgorithmSuite);
}

void ArtificialIntellegence::TestingHelper ::AddNeuralNetworkSuite()
{
    auto neuralNetworkSuite = GenerateSuite("������");

    AddSuite(neuralNetworkSuite);
}
