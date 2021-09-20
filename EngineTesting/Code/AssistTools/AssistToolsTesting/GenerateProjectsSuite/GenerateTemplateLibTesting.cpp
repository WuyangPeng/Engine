// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:58)

#include "GenerateTemplateLibTesting.h"
#include "AssistTools/GenerateProjects/CopyrightData.h" 
#include "AssistTools/GenerateProjects/GenerateTemplateLib.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateLib)

void AssistTools::GenerateTemplateLibTesting
    ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DefaultGenerateToTest);
}

void AssistTools::GenerateTemplateLibTesting
	::GenerateToTest()
{	
	const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Lib"));
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateLibCppSpecial.txt"));
	const System::String extension(SYSTEM_TEXT(".cpp")); 
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

	TestingType::Replace replace = GetSpecialReplace();

	TestingType generateTemplateSolution(fileName, replace); 

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

	int defaultSolutionNameCount = GetContentFindCount(fileName, GetSpecialSolutionName());
	ASSERT_LESS(0, defaultSolutionNameCount);

	CopyrightData copyrightData(GetCopyrightData());

	generateTemplateSolution.GenerateTo(fullDirectory, newProjectName, copyrightData, GetSolutionName());

	System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

	ContentCountTest(fullName, GetSpecialEndYear(), 0, __FUNCTION__, 0);

	ContentCountTest(fullName, GetSpecialProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

	ContentCountTest(fullName, GetSpecialVersions(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

	ContentCountTest(fullName, GetSpecialSolutionName(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetSolutionName(), defaultSolutionNameCount, __FUNCTION__, 6);

	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 7);
}

void AssistTools::GenerateTemplateLibTesting
	::DefaultGenerateToTest()
{	
	const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Lib"));
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateLibCpp.txt"));
	const System::String extension(SYSTEM_TEXT(".cpp")); 
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

	TestingType generateTemplateSolution(fileName, TestingType::Replace());

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

	int defaultSolutionNameCount = GetContentFindCount(fileName, GetDefaultSolutionName());
	ASSERT_LESS(0, defaultSolutionNameCount);

	CopyrightData copyrightData(GetCopyrightData());

	generateTemplateSolution.GenerateTo(fullDirectory, newProjectName, copyrightData, GetSolutionName());

	System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetSolutionName(), defaultSolutionNameCount, __FUNCTION__, 6);

	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 7);
}

