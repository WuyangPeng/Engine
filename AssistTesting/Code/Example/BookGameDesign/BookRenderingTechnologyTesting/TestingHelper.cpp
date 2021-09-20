// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 20:50)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookRenderingTechnology, TestingHelper, "�鼮 ��Ⱦ����")

void BookRenderingTechnology::TestingHelper
	::AddSuites()
{
	AddGPUGemsSuite();
	AddGraphicsShadersSuite();
}

void BookRenderingTechnology::TestingHelper
	::AddGPUGemsSuite()
{
	ADD_TEST_BEGIN(gpuGemsSuite, "GPU����");

	AddGPUGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite(gpuGemsSuite);
	AddGPUGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite(gpuGemsSuite);
	AddGPUGems3Suite(gpuGemsSuite);

	ADD_TEST_END(gpuGemsSuite);
}

void BookRenderingTechnology::TestingHelper
	::AddGPUGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite(Suite& gpuGemsSuite)
{
	ADD_TEST_BEGIN(gpuGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite, "GPU���� ʵʱͼ�α�̵ļ��������ɺͼ���");



	gpuGemsSuite.AddSuite(gpuGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite);
}

void BookRenderingTechnology::TestingHelper
	::AddGPUGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite(Suite& gpuGemsSuite)
{
	ADD_TEST_BEGIN(gpuGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite, "GPU���� ������ͼ��оƬ��ͨ�ü����̼���");



	gpuGemsSuite.AddSuite(gpuGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite);
}

void BookRenderingTechnology::TestingHelper
	::AddGPUGems3Suite(Suite& gpuGemsSuite)
{
	ADD_TEST_BEGIN(gpuGems3Suite, "GPU���� GPU 3D��ͨ�ñ�̼���");



	gpuGemsSuite.AddSuite(gpuGems3Suite);
}

void BookRenderingTechnology::TestingHelper
	::AddGraphicsShadersSuite()
{
	ADD_TEST_BEGIN(graphicsShadersSuite, "ͼ����ɫ������������ʵ��");

	 

	ADD_TEST_END(graphicsShadersSuite);
}

