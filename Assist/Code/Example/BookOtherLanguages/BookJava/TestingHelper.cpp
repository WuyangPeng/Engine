// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/29 21:18)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookJava, TestingHelper, "书籍 Java")

void BookJava::TestingHelper
	::AddSuites()
{
	AddThinkingInJavaSuite();
	AddCoreJavaSuite(); 
	AddEffectiveJavaSuite();
	AddJavaConcurrencyInPracticeSuite();
}

void BookJava::TestingHelper
	::AddThinkingInJavaSuite()
{
	ADD_TEST_BEGIN(thinkingInJavaSuite, "Java 编程思想");



	ADD_TEST_END(thinkingInJavaSuite);
}

void BookJava::TestingHelper
	::AddCoreJavaSuite()
{
	ADD_TEST_BEGIN(coreJavaSuite, "Java 核心技术");

	AddCoreJavaFundamentalsSuite(coreJavaSuite);
	AddCoreJavaAdvancedFeaturesSuite(coreJavaSuite);

	ADD_TEST_END(coreJavaSuite);
}

void BookJava::TestingHelper
	::AddCoreJavaFundamentalsSuite(Suite& coreJava)
{
	ADD_TEST_BEGIN(coreJavaFundamentalsSuite, "Java 核心技术 基础知识");



	coreJava.AddSuite(coreJavaFundamentalsSuite);
}

void BookJava::TestingHelper
	::AddCoreJavaAdvancedFeaturesSuite(Suite& coreJava)
{
	ADD_TEST_BEGIN(coreJavaAdvancedFeaturesSuite, "Java 核心技术 高级特征");



	coreJava.AddSuite(coreJavaAdvancedFeaturesSuite);
}

void BookJava::TestingHelper
	::AddEffectiveJavaSuite()
{
	ADD_TEST_BEGIN(effectiveJavaSuite, "Effective Java");



	ADD_TEST_END(effectiveJavaSuite);
}

void BookJava::TestingHelper
	::AddJavaConcurrencyInPracticeSuite()
{
	ADD_TEST_BEGIN(javaConcurrencyInPracticeSuite, "Java 并发编程实战");



	ADD_TEST_END(javaConcurrencyInPracticeSuite);
}

