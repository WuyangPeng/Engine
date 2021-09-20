// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.1.0.0 (2020/04/04 20:34)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/Helper/BookDatabaseClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

BookDatabase::TestingHelper
	::TestingHelper(int argc, char** argv)
	:ParentType{ argc,argv,"【书籍·其他语言·数据库】单元测试套件" }
{
	InitSuite();

	BOOK_DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDatabase, TestingHelper) 

void BookDatabase::TestingHelper
	::InitSuite()
{
	AddAFirstCourseInDatabaseSystemsSuite();
	AddDatabaseSystemConceptsSuite();
	AddDatabaseSystemImplementationSuite();
	AddRefactoringDatabasesEvolutionaryDatabaseDesignSuite();

	AddDatabaseDesignRelationalTheorySuite();
	AddSevenDatabasesInSevenWeeksSuite();
	AddDatabaseSystemsTheCompletsBookSuite();
	AddDataMiningConceptsAndTechniquesSuite();

	AddDataMiningPracticalMachineLearningToolsAndTechniquesSuite();
	AddTransactionProcessingConceptsAndTechniquesSuite();
	AddMiningTheSocialWebSuite();
}

void BookDatabase::TestingHelper
	::AddAFirstCourseInDatabaseSystemsSuite()
{
	auto aFirstCourseInDatabaseSystemsSuite = GenerateSuite("数据库系统基础教程");

	ADD_TEST(aFirstCourseInDatabaseSystemsSuite, AFirstCourseInDatabaseSystemsMainTesting); 

	AddSuite(aFirstCourseInDatabaseSystemsSuite);
}

void BookDatabase::TestingHelper
	::AddDatabaseSystemConceptsSuite()
{
	auto databaseSystemConceptsSuite = GenerateSuite("数据库系统概念");

	ADD_TEST(databaseSystemConceptsSuite, DatabaseSystemConceptsMainTesting);

	AddSuite(databaseSystemConceptsSuite);
}

void BookDatabase::TestingHelper
	::AddDatabaseSystemImplementationSuite()
{
	auto databaseSystemImplementationSuite = GenerateSuite("数据库系统实现");

	ADD_TEST(databaseSystemImplementationSuite, DatabaseSystemImplementationMainTesting);

	AddSuite(databaseSystemImplementationSuite);
}

void BookDatabase::TestingHelper
	::AddRefactoringDatabasesEvolutionaryDatabaseDesignSuite()
{
	auto refactoringDatabasesEvolutionaryDatabaseDesignSuite = GenerateSuite("数据库重构");

	ADD_TEST(refactoringDatabasesEvolutionaryDatabaseDesignSuite, RefactoringDatabasesEvolutionaryMainTesting);

	AddSuite(refactoringDatabasesEvolutionaryDatabaseDesignSuite);
}

void BookDatabase::TestingHelper
	::AddDatabaseDesignRelationalTheorySuite()
{
	auto databaseDesignRelationalTheorySuite = GenerateSuite("数据库设计与关系理论");

	ADD_TEST(databaseDesignRelationalTheorySuite, DatabaseDesignRelationalTheoryMainTesting);

	AddSuite(databaseDesignRelationalTheorySuite);
}

void BookDatabase::TestingHelper
	::AddSevenDatabasesInSevenWeeksSuite()
{
	auto sevenDatabasesInSevenWeeksSuite = GenerateSuite("七周七数据库");

	ADD_TEST(sevenDatabasesInSevenWeeksSuite, SevenDatabasesInSevenWeeksMainTesting);

	AddSuite(sevenDatabasesInSevenWeeksSuite);
}

void BookDatabase::TestingHelper
	::AddDatabaseSystemsTheCompletsBookSuite()
{
	auto databaseSystemsTheCompletsBookSuite = GenerateSuite("数据库系统全书");

	ADD_TEST(databaseSystemsTheCompletsBookSuite, DatabaseSystemsTheCompletsBookMainTesting);

	AddSuite(databaseSystemsTheCompletsBookSuite);
}

void BookDatabase::TestingHelper
	::AddDataMiningConceptsAndTechniquesSuite()
{
	auto dataMiningConceptsAndTechniquesSuite = GenerateSuite("数据挖掘概念与技术");

	ADD_TEST(dataMiningConceptsAndTechniquesSuite, DataMiningConceptsAndTechniquesMainTesting);

	AddSuite(dataMiningConceptsAndTechniquesSuite);
}

void BookDatabase::TestingHelper
	::AddDataMiningPracticalMachineLearningToolsAndTechniquesSuite()
{
	auto dataMiningPracticalMachineLearningToolsAndTechniquesSuite = GenerateSuite("数据挖掘：实用机器学习工具与技术");

	ADD_TEST(dataMiningPracticalMachineLearningToolsAndTechniquesSuite, DataMiningMainTesting);

	AddSuite(dataMiningPracticalMachineLearningToolsAndTechniquesSuite);
}

void BookDatabase::TestingHelper
	::AddTransactionProcessingConceptsAndTechniquesSuite()
{
	auto transactionProcessingConceptsAndTechniquesSuite = GenerateSuite("事务处理：概念与技术");

	ADD_TEST(transactionProcessingConceptsAndTechniquesSuite, TransactionProcessingConceptsAndTechniquesMainTesting);

	AddSuite(transactionProcessingConceptsAndTechniquesSuite);
}

void BookDatabase::TestingHelper
	::AddMiningTheSocialWebSuite()
{
	auto miningTheSocialWebSuite = GenerateSuite("社交网站的数据挖掘与分析");

	ADD_TEST(miningTheSocialWebSuite, MiningTheSocialWebMainTesting);

	AddSuite(miningTheSocialWebSuite);
}

