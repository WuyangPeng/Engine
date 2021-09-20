// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助测试版本：0.0.0.1 (2019/09/27 21:53)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookATL, TestingHelper, "书籍 操作系统 ATL")

void BookATL::TestingHelper
	::AddSuites()
{
	AddATLDevelopersGuideSuite();
	AddATLInteranlsSuite();
}

void BookATL::TestingHelper
	::AddATLDevelopersGuideSuite()
{
	ADD_TEST_BEGIN(atlDevelopersGuideSuit, "ATL 开发指南");



	ADD_TEST_END(atlDevelopersGuideSuit);
}

void BookATL::TestingHelper
	::AddATLInteranlsSuite()
{
	ADD_TEST_BEGIN(atlInteranlsSuit, "深入解析 ATL");



	ADD_TEST_END(atlInteranlsSuit);
}

