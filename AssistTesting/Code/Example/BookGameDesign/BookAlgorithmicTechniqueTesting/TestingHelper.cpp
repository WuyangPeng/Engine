// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.0.0.1 (2019/09/28 16:49)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookAlgorithmicTechnique, TestingHelper, "书籍 算法技术")

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
	ADD_TEST_BEGIN(realTimeCollisionDetectionSuite, "实时碰撞检测算法技术");



	ADD_TEST_END(realTimeCollisionDetectionSuite);
}

void BookAlgorithmicTechnique::TestingHelper
	::AddRayTracingFromTheGroundUpSuite()
{
	ADD_TEST_BEGIN(rayTracingFromTheGroundUpSuite, "光线跟踪算法技术");



	ADD_TEST_END(rayTracingFromTheGroundUpSuite);
}

void BookAlgorithmicTechnique::TestingHelper
	::AddRealTimeCamerasSuite()
{
	ADD_TEST_BEGIN(realTimeCamerasSuite, "实时相机处理技术");



	ADD_TEST_END(realTimeCamerasSuite);
}

void BookAlgorithmicTechnique::TestingHelper
	::AddRealTimeShadowsSuite()
{
	ADD_TEST_BEGIN(realTimeShadowsSuite, "实时阴影技术");



	ADD_TEST_END(realTimeShadowsSuite);
}

void BookAlgorithmicTechnique::TestingHelper
	::AddComputerAnimationAlgorithmsAndTechniquesSuite()
{
	ADD_TEST_BEGIN(computerAnimationAlgorithmsAndTechniquesSuite, "计算机动画算法与技术");



	ADD_TEST_END(computerAnimationAlgorithmsAndTechniquesSuite);
}

