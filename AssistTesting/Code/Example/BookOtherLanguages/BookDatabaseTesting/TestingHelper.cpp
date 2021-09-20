// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.1.0.0 (2020/04/04 20:34)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/Helper/BookDatabaseClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

BookDatabase::TestingHelper
	::TestingHelper(int argc, char** argv)
	:ParentType{ argc,argv,"���鼮���������ԡ����ݿ⡿��Ԫ�����׼�" }
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
	auto aFirstCourseInDatabaseSystemsSuite = GenerateSuite("���ݿ�ϵͳ�����̳�");

	ADD_TEST(aFirstCourseInDatabaseSystemsSuite, AFirstCourseInDatabaseSystemsMainTesting); 

	AddSuite(aFirstCourseInDatabaseSystemsSuite);
}

void BookDatabase::TestingHelper
	::AddDatabaseSystemConceptsSuite()
{
	auto databaseSystemConceptsSuite = GenerateSuite("���ݿ�ϵͳ����");

	ADD_TEST(databaseSystemConceptsSuite, DatabaseSystemConceptsMainTesting);

	AddSuite(databaseSystemConceptsSuite);
}

void BookDatabase::TestingHelper
	::AddDatabaseSystemImplementationSuite()
{
	auto databaseSystemImplementationSuite = GenerateSuite("���ݿ�ϵͳʵ��");

	ADD_TEST(databaseSystemImplementationSuite, DatabaseSystemImplementationMainTesting);

	AddSuite(databaseSystemImplementationSuite);
}

void BookDatabase::TestingHelper
	::AddRefactoringDatabasesEvolutionaryDatabaseDesignSuite()
{
	auto refactoringDatabasesEvolutionaryDatabaseDesignSuite = GenerateSuite("���ݿ��ع�");

	ADD_TEST(refactoringDatabasesEvolutionaryDatabaseDesignSuite, RefactoringDatabasesEvolutionaryMainTesting);

	AddSuite(refactoringDatabasesEvolutionaryDatabaseDesignSuite);
}

void BookDatabase::TestingHelper
	::AddDatabaseDesignRelationalTheorySuite()
{
	auto databaseDesignRelationalTheorySuite = GenerateSuite("���ݿ�������ϵ����");

	ADD_TEST(databaseDesignRelationalTheorySuite, DatabaseDesignRelationalTheoryMainTesting);

	AddSuite(databaseDesignRelationalTheorySuite);
}

void BookDatabase::TestingHelper
	::AddSevenDatabasesInSevenWeeksSuite()
{
	auto sevenDatabasesInSevenWeeksSuite = GenerateSuite("���������ݿ�");

	ADD_TEST(sevenDatabasesInSevenWeeksSuite, SevenDatabasesInSevenWeeksMainTesting);

	AddSuite(sevenDatabasesInSevenWeeksSuite);
}

void BookDatabase::TestingHelper
	::AddDatabaseSystemsTheCompletsBookSuite()
{
	auto databaseSystemsTheCompletsBookSuite = GenerateSuite("���ݿ�ϵͳȫ��");

	ADD_TEST(databaseSystemsTheCompletsBookSuite, DatabaseSystemsTheCompletsBookMainTesting);

	AddSuite(databaseSystemsTheCompletsBookSuite);
}

void BookDatabase::TestingHelper
	::AddDataMiningConceptsAndTechniquesSuite()
{
	auto dataMiningConceptsAndTechniquesSuite = GenerateSuite("�����ھ�����뼼��");

	ADD_TEST(dataMiningConceptsAndTechniquesSuite, DataMiningConceptsAndTechniquesMainTesting);

	AddSuite(dataMiningConceptsAndTechniquesSuite);
}

void BookDatabase::TestingHelper
	::AddDataMiningPracticalMachineLearningToolsAndTechniquesSuite()
{
	auto dataMiningPracticalMachineLearningToolsAndTechniquesSuite = GenerateSuite("�����ھ�ʵ�û���ѧϰ�����뼼��");

	ADD_TEST(dataMiningPracticalMachineLearningToolsAndTechniquesSuite, DataMiningMainTesting);

	AddSuite(dataMiningPracticalMachineLearningToolsAndTechniquesSuite);
}

void BookDatabase::TestingHelper
	::AddTransactionProcessingConceptsAndTechniquesSuite()
{
	auto transactionProcessingConceptsAndTechniquesSuite = GenerateSuite("�����������뼼��");

	ADD_TEST(transactionProcessingConceptsAndTechniquesSuite, TransactionProcessingConceptsAndTechniquesMainTesting);

	AddSuite(transactionProcessingConceptsAndTechniquesSuite);
}

void BookDatabase::TestingHelper
	::AddMiningTheSocialWebSuite()
{
	auto miningTheSocialWebSuite = GenerateSuite("�罻��վ�������ھ������");

	ADD_TEST(miningTheSocialWebSuite, MiningTheSocialWebMainTesting);

	AddSuite(miningTheSocialWebSuite);
}

