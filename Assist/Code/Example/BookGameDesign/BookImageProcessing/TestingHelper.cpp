// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/28 16:43)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookImageProcessing, TestingHelper, "书籍 图像处理")

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
	ADD_TEST_BEGIN(imageProcessingTheFundamentalsSuite, "数字图像处理疑难解析");



	ADD_TEST_END(imageProcessingTheFundamentalsSuite);
}

void BookImageProcessing::TestingHelper
	::AddImageProcessingAnalysisAndMachineVisionSuite()
{
	ADD_TEST_BEGIN(imageProcessingAnalysisAndMachineVisionSuite, "图像处理、分析与机器视觉");



	ADD_TEST_END(imageProcessingAnalysisAndMachineVisionSuite);
}

void BookImageProcessing::TestingHelper
	::AddPatternRecognitionWithNeuralNetworksInCppSuite()
{
	ADD_TEST_BEGIN(patternRecognitionWithNeuralNetworksInCppSuite, "神经网络模式识别及其实现");



	ADD_TEST_END(patternRecognitionWithNeuralNetworksInCppSuite);
}

