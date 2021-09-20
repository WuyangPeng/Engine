// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 20:50)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookRenderingTechnology, TestingHelper, "书籍 渲染技术")

void BookRenderingTechnology::TestingHelper
	::AddSuites()
{
	AddGPUGemsSuite();
	AddGraphicsShadersSuite();
}

void BookRenderingTechnology::TestingHelper
	::AddGPUGemsSuite()
{
	ADD_TEST_BEGIN(gpuGemsSuite, "GPU精粹");

	AddGPUGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite(gpuGemsSuite);
	AddGPUGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite(gpuGemsSuite);
	AddGPUGems3Suite(gpuGemsSuite);

	ADD_TEST_END(gpuGemsSuite);
}

void BookRenderingTechnology::TestingHelper
	::AddGPUGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite(Suite& gpuGemsSuite)
{
	ADD_TEST_BEGIN(gpuGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite, "GPU精粹 实时图形编程的技术、技巧和技艺");



	gpuGemsSuite.AddSuite(gpuGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite);
}

void BookRenderingTechnology::TestingHelper
	::AddGPUGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite(Suite& gpuGemsSuite)
{
	ADD_TEST_BEGIN(gpuGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite, "GPU精粹 高性能图形芯片和通用计算编程技巧");



	gpuGemsSuite.AddSuite(gpuGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite);
}

void BookRenderingTechnology::TestingHelper
	::AddGPUGems3Suite(Suite& gpuGemsSuite)
{
	ADD_TEST_BEGIN(gpuGems3Suite, "GPU精粹 GPU 3D和通用编程技巧");



	gpuGemsSuite.AddSuite(gpuGems3Suite);
}

void BookRenderingTechnology::TestingHelper
	::AddGraphicsShadersSuite()
{
	ADD_TEST_BEGIN(graphicsShadersSuite, "图形着色器——理论与实践");

	 

	ADD_TEST_END(graphicsShadersSuite);
}

