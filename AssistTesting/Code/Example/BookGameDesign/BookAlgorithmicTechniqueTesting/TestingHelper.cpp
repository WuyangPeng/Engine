// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 16:49)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookAlgorithmicTechnique, TestingHelper, "�鼮 �㷨����")

void BookAlgorithmicTechnique::TestingHelper
	::AddSuites()
{
	AddRealTimeCollisionDetectionSuite();
	AddRayTracingFromTheGroundUpSuite();
	AddRealTimeCamerasSuite();
	AddRealTimeShadowsSuite();
	AddComputerAnimationAlgorithmsAndTechniquesSuite();
}

void BookAlgorithmicTechnique::TestingHelper
	::AddRealTimeCollisionDetectionSuite()
{
	ADD_TEST_BEGIN(realTimeCollisionDetectionSuite, "ʵʱ��ײ����㷨����");



	ADD_TEST_END(realTimeCollisionDetectionSuite);
}

void BookAlgorithmicTechnique::TestingHelper
	::AddRayTracingFromTheGroundUpSuite()
{
	ADD_TEST_BEGIN(rayTracingFromTheGroundUpSuite, "���߸����㷨����");



	ADD_TEST_END(rayTracingFromTheGroundUpSuite);
}

void BookAlgorithmicTechnique::TestingHelper
	::AddRealTimeCamerasSuite()
{
	ADD_TEST_BEGIN(realTimeCamerasSuite, "ʵʱ���������");



	ADD_TEST_END(realTimeCamerasSuite);
}

void BookAlgorithmicTechnique::TestingHelper
	::AddRealTimeShadowsSuite()
{
	ADD_TEST_BEGIN(realTimeShadowsSuite, "ʵʱ��Ӱ����");



	ADD_TEST_END(realTimeShadowsSuite);
}

void BookAlgorithmicTechnique::TestingHelper
	::AddComputerAnimationAlgorithmsAndTechniquesSuite()
{
	ADD_TEST_BEGIN(computerAnimationAlgorithmsAndTechniquesSuite, "����������㷨�뼼��");



	ADD_TEST_END(computerAnimationAlgorithmsAndTechniquesSuite);
}

