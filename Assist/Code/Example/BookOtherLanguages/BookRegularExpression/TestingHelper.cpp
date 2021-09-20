// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.2 (2019/09/29 21:20)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookRegularExpression, TestingHelper, "�鼮 ������ʽ")

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
	ADD_TEST_BEGIN(beginningRegularExpressionsSuite, "������ʽ���ž���");



	ADD_TEST_END(beginningRegularExpressionsSuite);
}

void BookRegularExpression::TestingHelper
	::AddSamsTeachYourselfRegularExpressionsIn10MinutesSuite()
{
	ADD_TEST_BEGIN(samsTeachYourselfRegularExpressionsIn10MinutesSuite, "������ʽ��֪�ػ�");



	ADD_TEST_END(samsTeachYourselfRegularExpressionsIn10MinutesSuite);
}

void BookRegularExpression::TestingHelper
	::AddMasteringRegularExpressionsSuite()
{
	ADD_TEST_BEGIN(masteringRegularExpressionsSuite, "��ͨ������ʽ");



	ADD_TEST_END(masteringRegularExpressionsSuite);
}

void BookRegularExpression::TestingHelper
	::AddRegularExpressionsCookbookSuite()
{
	ADD_TEST_BEGIN(regularExpressionsCookbookSuite, "������ʽ����ʵ��");



	ADD_TEST_END(regularExpressionsCookbookSuite);
}

