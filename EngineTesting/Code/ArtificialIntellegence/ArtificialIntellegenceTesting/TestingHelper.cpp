// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/09 20:05)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(ArtificialIntellegence, TestingHelper, "�˹����ܿ�")

// private
void ArtificialIntellegence::TestingHelper
	::AddSuites()
{
	AddMacroSuite();  
	AddMiscellaneousSuite(); 
	AddPathSearchSuite(); 
	AddFiniteStateMachineSuite();
	AddFuzzyStateMachineSuite(); 
	AddGeneticAlgorithmSuite(); 
	AddNeuralNetworkSuite(); 
}

void ArtificialIntellegence::TestingHelper
	::AddMacroSuite()
{
	ADD_TEST_BEGIN(macroSuite, "��"); 

	ADD_TEST_END(macroSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddMiscellaneousSuite()
{
	ADD_TEST_BEGIN(miscellaneousSuite, "����"); 

	ADD_TEST_END(miscellaneousSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddPathSearchSuite()
{
	ADD_TEST_BEGIN(pathSearchSuite, "Ѱ·"); 

	ADD_TEST_END(pathSearchSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddFiniteStateMachineSuite()
{
	ADD_TEST_BEGIN(finiteStateMachineSuite, "����״̬��"); 

	ADD_TEST_END(finiteStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddFuzzyStateMachineSuite()
{
	ADD_TEST_BEGIN(fuzzyStateMachineSuite, "ģ��״̬��"); 

	ADD_TEST_END(fuzzyStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddGeneticAlgorithmSuite()
{
	ADD_TEST_BEGIN(geneticAlgorithmSuite, "�Ŵ��㷨"); 

	ADD_TEST_END(geneticAlgorithmSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddNeuralNetworkSuite()
{
	ADD_TEST_BEGIN(neuralNetworkSuite, "������"); 

	ADD_TEST_END(neuralNetworkSuite);
}

