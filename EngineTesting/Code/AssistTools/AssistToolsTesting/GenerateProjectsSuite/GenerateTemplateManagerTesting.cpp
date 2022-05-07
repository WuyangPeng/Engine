// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:59)

#include "GenerateTemplateManagerTesting.h"
#include "AssistTools/GenerateProjects/GenerateTemplateManager.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h" 

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateManager)

void AssistTools::GenerateTemplateManagerTesting
   ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateManagerDllH.txt"s), SYSTEM_TEXT("Dll"s));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateManagerExportH.txt"s), SYSTEM_TEXT("Export"s));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateManagerFwdH.txt"s), SYSTEM_TEXT("Fwd"s));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateManagerH.txt"s), SYSTEM_TEXT(""s));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateManagerImportH.txt"s), SYSTEM_TEXT("Import"s));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultGenerateToTest, SYSTEM_TEXT("GameTemplateManagerNoImportH.txt"s), SYSTEM_TEXT("NoImport"s));
}

void AssistTools::GenerateTemplateManagerTesting
	::GenerateToTest()
{	
	const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateManagerHSpecial.txt"));
	const System::String extension(SYSTEM_TEXT(".h"));  
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName);

	TestingType::Replace replace = GetSpecialReplace();

	TestingType generateTemplateSolution(fileName,replace); 

	int defaultEndYearCount = GetContentFindCount(fileName, GetSpecialEndYear());
	ASSERT_EQUAL(defaultEndYearCount, 1);

	int defaultProjectChineseNameCount = GetContentFindCount(fileName, GetSpecialProjectChineseName());
	ASSERT_LESS(0, defaultProjectChineseNameCount);

	int defaultVersionsCount = GetContentFindCount(fileName, GetSpecialVersions());
	ASSERT_LESS(0, defaultVersionsCount);

	int defaultDateCount = GetContentFindCount(fileName, GetSpecialDate());
	ASSERT_EQUAL(defaultDateCount, 1);

	int defaultHourCount = GetContentFindCount(fileName, GetSpecialHour());
	ASSERT_EQUAL(defaultHourCount, 1);

	int defaultMinuteCount = GetContentFindCount(fileName, GetSpecialMinute());
	ASSERT_EQUAL(defaultMinuteCount, 1);

	int defaultCapitalCount = GetContentFindCount(fileName, GetSpecialProjectCapital());
	ASSERT_LESS(0, defaultCapitalCount);

	int defaultManagerCapitalNameCount = GetContentFindCount(fileName, GetSpecialManagerCapital());
	ASSERT_LESS(0, defaultManagerCapitalNameCount);

	CopyrightData copyrightData(GetCopyrightData());

	generateTemplateSolution.GenerateTo(fullDirectory, newProjectName, copyrightData, GetProjectCapital(), GetInputManagerCapitalName());

	System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

	ContentCountTest(fullName, GetSpecialEndYear(), 0, __FUNCTION__, 0);

	ContentCountTest(fullName, GetSpecialProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

	ContentCountTest(fullName, GetSpecialVersions(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

	ContentCountTest(fullName, GetSpecialProjectCapital(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetProjectCapital(), defaultCapitalCount, __FUNCTION__, 6);

	ContentCountTest(fullName, GetSpecialManagerCapital(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalNameCount, __FUNCTION__, 8);

	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 9);
}

void AssistTools::GenerateTemplateManagerTesting
	::DefaultGenerateToTest(const System::String& testFileName, const System::String& resultSuffix)
{	
	const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("InputManager"));
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName);
	const System::String extension(SYSTEM_TEXT(".h"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + newProjectName);

	TestingType generateTemplateSolution(fileName,  TestingType::Replace());  

	int defaultEndYearCount = GetContentFindCount(fileName, GetDefaultEndYear());
	ASSERT_EQUAL(defaultEndYearCount, 1);

	int defaultProjectChineseNameCount = GetContentFindCount(fileName, GetDefaultProjectChineseName());
	ASSERT_LESS(0, defaultProjectChineseNameCount);

	int defaultVersionsCount = GetContentFindCount(fileName, GetDefaultVersions());
	ASSERT_LESS(0, defaultVersionsCount);

	int defaultDateCount = GetContentFindCount(fileName, GetDefaultDate());
	ASSERT_EQUAL(defaultDateCount, 1);

	int defaultHourCount = GetContentFindCount(fileName, GetDefaultHour());
	ASSERT_EQUAL(defaultHourCount, 1);

	int defaultMinuteCount = GetContentFindCount(fileName, GetDefaultMinute());
	ASSERT_EQUAL(defaultMinuteCount, 1);

	int defaultCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital());
	ASSERT_LESS(0, defaultCapitalCount);

	int defaultManagerCapitalNameCount = GetContentFindCount(fileName, GetDefaultManagerCapital());
	ASSERT_LESS(0, defaultManagerCapitalNameCount);

	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName(newProjectName + resultSuffix);

	generateTemplateSolution.GenerateTo(fullDirectory, newFullProjectName, copyrightData, GetProjectCapital(), GetInputManagerCapitalName());

	System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetProjectCapital(), defaultCapitalCount, __FUNCTION__, 6);

	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalNameCount, __FUNCTION__, 8);

	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 9);
}

