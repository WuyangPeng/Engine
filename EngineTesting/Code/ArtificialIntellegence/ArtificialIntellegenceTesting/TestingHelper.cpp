// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.4 (2019/09/09 20:05)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(ArtificialIntellegence, TestingHelper, "人工智能库")

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
	ADD_TEST_BEGIN(macroSuite, "宏"); 

	ADD_TEST_END(macroSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddMiscellaneousSuite()
{
	ADD_TEST_BEGIN(miscellaneousSuite, "杂项"); 

	ADD_TEST_END(miscellaneousSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddPathSearchSuite()
{
	ADD_TEST_BEGIN(pathSearchSuite, "寻路"); 

	ADD_TEST_END(pathSearchSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddFiniteStateMachineSuite()
{
	ADD_TEST_BEGIN(finiteStateMachineSuite, "有限状态机"); 

	ADD_TEST_END(finiteStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddFuzzyStateMachineSuite()
{
	ADD_TEST_BEGIN(fuzzyStateMachineSuite, "模糊状态机"); 

	ADD_TEST_END(fuzzyStateMachineSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddGeneticAlgorithmSuite()
{
	ADD_TEST_BEGIN(geneticAlgorithmSuite, "遗传算法"); 

	ADD_TEST_END(geneticAlgorithmSuite);
}

void ArtificialIntellegence::TestingHelper
	::AddNeuralNetworkSuite()
{
	ADD_TEST_BEGIN(neuralNetworkSuite, "神经网络"); 

	ADD_TEST_END(neuralNetworkSuite);
}

