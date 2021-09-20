// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/29 21:20)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookRegularExpression, TestingHelper, "书籍 正则表达式")

void BookRegularExpression::TestingHelper
	::AddSuites()
{
	AddBeginningRegularExpressionsSuite();
	AddSamsTeachYourselfRegularExpressionsIn10MinutesSuite();	
	AddMasteringRegularExpressionsSuite();
	AddRegularExpressionsCookbookSuite();
}

void BookRegularExpression::TestingHelper
	::AddBeginningRegularExpressionsSuite()
{
	ADD_TEST_BEGIN(beginningRegularExpressionsSuite, "正则表达式入门经典");



	ADD_TEST_END(beginningRegularExpressionsSuite);
}

void BookRegularExpression::TestingHelper
	::AddSamsTeachYourselfRegularExpressionsIn10MinutesSuite()
{
	ADD_TEST_BEGIN(samsTeachYourselfRegularExpressionsIn10MinutesSuite, "正则表达式必知必会");



	ADD_TEST_END(samsTeachYourselfRegularExpressionsIn10MinutesSuite);
}

void BookRegularExpression::TestingHelper
	::AddMasteringRegularExpressionsSuite()
{
	ADD_TEST_BEGIN(masteringRegularExpressionsSuite, "精通正则表达式");



	ADD_TEST_END(masteringRegularExpressionsSuite);
}

void BookRegularExpression::TestingHelper
	::AddRegularExpressionsCookbookSuite()
{
	ADD_TEST_BEGIN(regularExpressionsCookbookSuite, "正则表达式经典实例");



	ADD_TEST_END(regularExpressionsCookbookSuite);
}

