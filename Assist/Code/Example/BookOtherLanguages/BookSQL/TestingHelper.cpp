// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.2 (2019/09/29 21:21)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(BookSQL, TestingHelper, "书籍 SQL")

void BookSQL::TestingHelper
	::AddSuites()
{
	AddSamsTeachYourselfSQLIn24HoursSuite();
	AddSamsTeachYourselfSQLIn10MinutesSuite();
	AddSQLTheCompleteReferenceSuite();
	AddSQLCookbookSuite();
}

void BookSQL::TestingHelper
	::AddSamsTeachYourselfSQLIn24HoursSuite()
{
	ADD_TEST_BEGIN(samsTeachYourselfSQLIn24HoursSuite, "SQL 入门经典");



	ADD_TEST_END(samsTeachYourselfSQLIn24HoursSuite);
}

void BookSQL::TestingHelper
	::AddSamsTeachYourselfSQLIn10MinutesSuite()
{
	ADD_TEST_BEGIN(samsTeachYourselfSQLIn10MinutesSuite, "SQL 必知必会");



	ADD_TEST_END(samsTeachYourselfSQLIn10MinutesSuite);
}

void BookSQL::TestingHelper
	::AddSQLTheCompleteReferenceSuite()
{
	ADD_TEST_BEGIN(sqlTheCompleteReferenceSuite, "SQL 完全手册");



	ADD_TEST_END(sqlTheCompleteReferenceSuite);
}

void BookSQL::TestingHelper
	::AddSQLCookbookSuite()
{
	ADD_TEST_BEGIN(sqlCookbookSuite, "SQL Cookbook");



	ADD_TEST_END(sqlCookbookSuite);
}

