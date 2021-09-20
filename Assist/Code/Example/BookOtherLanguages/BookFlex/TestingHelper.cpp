// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/29 21:12)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookFlex, TestingHelper, "书籍 Flex")

void BookFlex::TestingHelper
	::AddSuites()
{
	AddAdobeFlex4Suite();
	AddFlex4InActionSuite();
	AddHelloFlex4Suite();
}

void BookFlex::TestingHelper
	::AddAdobeFlex4Suite()
{
	ADD_TEST_BEGIN(adobeFlex4Suite, "Flex4 权威指南");



	ADD_TEST_END(adobeFlex4Suite);
}

void BookFlex::TestingHelper
	::AddFlex4InActionSuite()
{
	ADD_TEST_BEGIN(flex4InActionSuite, "Flex 4 实战");



	ADD_TEST_END(flex4InActionSuite);
}

void BookFlex::TestingHelper
	::AddHelloFlex4Suite()
{
	ADD_TEST_BEGIN(helloFlex4Suite, "Flex4 一学就会");



	ADD_TEST_END(helloFlex4Suite);
}

