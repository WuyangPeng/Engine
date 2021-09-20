// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.2 (2019/09/28 16:43)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookImageProcessing, TestingHelper, "�鼮 ͼ����")

void BookImageProcessing::TestingHelper
	::AddSuites()
{
	AddImageProcessingTheFundamentalsSuite();
	AddImageProcessingAnalysisAndMachineVisionSuite();
	AddPatternRecognitionWithNeuralNetworksInCppSuite();
}

void BookImageProcessing::TestingHelper
	::AddImageProcessingTheFundamentalsSuite()
{
	ADD_TEST_BEGIN(imageProcessingTheFundamentalsSuite, "����ͼ�������ѽ���");



	ADD_TEST_END(imageProcessingTheFundamentalsSuite);
}

void BookImageProcessing::TestingHelper
	::AddImageProcessingAnalysisAndMachineVisionSuite()
{
	ADD_TEST_BEGIN(imageProcessingAnalysisAndMachineVisionSuite, "ͼ��������������Ӿ�");



	ADD_TEST_END(imageProcessingAnalysisAndMachineVisionSuite);
}

void BookImageProcessing::TestingHelper
	::AddPatternRecognitionWithNeuralNetworksInCppSuite()
{
	ADD_TEST_BEGIN(patternRecognitionWithNeuralNetworksInCppSuite, "������ģʽʶ����ʵ��");



	ADD_TEST_END(patternRecognitionWithNeuralNetworksInCppSuite);
}

