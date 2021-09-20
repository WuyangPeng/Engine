// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助测试版本：0.0.0.1 (2019/09/29 13:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookObjectOriented, TestingHelper, "书籍 面向对象")

void BookObjectOriented::TestingHelper
	::AddSuites()
{
	AddObjectOrientedAnalysisAndDesignWithApplicationsSuite();
	AddObjectOrientedAnalysisDesignSuite();
	AddTheObjectOrientedThoughtProcessSuite();
}

void BookObjectOriented::TestingHelper
	::AddObjectOrientedAnalysisAndDesignWithApplicationsSuite()
{
	ADD_TEST_BEGIN(objectOrientedAnalysisAndDesignWithApplicationsSuite, "面向对象分析与设计");

	ADD_TEST_END(objectOrientedAnalysisAndDesignWithApplicationsSuite);
}

void BookObjectOriented::TestingHelper
	::AddObjectOrientedAnalysisDesignSuite()
{
	ADD_TEST_BEGIN(objectOrientedAnalysisDesignSuite, "面向对象分析与设计（UML 2.0版）");

	ADD_TEST_END(objectOrientedAnalysisDesignSuite);
}

void BookObjectOriented::TestingHelper
	::AddTheObjectOrientedThoughtProcessSuite()
{
	ADD_TEST_BEGIN(theObjectOrientedThoughtProcessSuite, "写给大家看的面向对象编程书");

	ADD_TEST_END(theObjectOrientedThoughtProcessSuite);
}

