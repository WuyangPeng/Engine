// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 11:00)

#include "GenerateTestingTemplateEngineTesting.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateEngine.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTestingTemplateEngine)

void AssistTools::GenerateTestingTemplateEngineTesting
    ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);

	ASSERT_NOT_THROW_EXCEPTION_2(DefaultManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateTestingH.txt"), SYSTEM_TEXT("Testing"));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultManagerHeaderGenerateToTest, SYSTEM_TEXT("GameTemplateTestingHelperH.txt"), SYSTEM_TEXT("TestingHelper"));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultManagerCppGenerateToTest, SYSTEM_TEXT("GameTemplateTestingHelperCpp.txt"), SYSTEM_TEXT("TestingHelper"));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultManagerCppGenerateToTest, SYSTEM_TEXT("GameTemplateTestingMainCpp.txt"), SYSTEM_TEXT("TestingMain"));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultManagerCppGenerateToTest, SYSTEM_TEXT("GameTemplateTestingExeLibCpp.txt"), SYSTEM_TEXT("TestingLib"));
	ASSERT_NOT_THROW_EXCEPTION_2(DefaultManagerCppGenerateToTest, SYSTEM_TEXT("GameTemplateTestingLibCpp.txt"), SYSTEM_TEXT("TestingLib"));
}

void AssistTools::GenerateTestingTemplateEngineTesting
	::GenerateToTest()
{	
	const System::String newProjectName(GetSolutionName() + GetInputManagerName()); 
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateTestingHSpecial.txt"));
	const System::String extension(SYSTEM_TEXT(".h"));	  
	const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + newProjectName + GetTesting());
 
	TestingType::Replace replace = GetSpecialReplace();

	TestingType generateTemplateSolution(fileName, extension, replace);

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

	int defaultNameSpaceCount = GetContentFindCount(fileName, GetSpecialSolutionName()); 

	int defaultManagerNameCount = GetContentFindCount(fileName, GetSpecialManagerName()); 

	int defaultProjectCapitalCount = GetContentFindCount(fileName, GetSpecialProjectCapital());
	ASSERT_LESS(0, defaultProjectCapitalCount);

	int defaultManagerCapitalCount = GetContentFindCount(fileName, GetSpecialManagerCapital());
	ASSERT_LESS(0, defaultManagerCapitalCount);

	CopyrightData copyrightData(GetCopyrightData());	

	generateTemplateSolution.GenerateTo(fullDirectory, GetTesting(), copyrightData, GetSolutionName(), GetInputManagerName(),
		                                GetProjectCapital(), GetInputManagerCapitalName() + SYSTEM_TEXT("_"));

	System::String fullName = fullDirectory + GetForwardSlash() + GetTesting() + extension;

	ContentCountTest(fullName, GetSpecialEndYear(), 0, __FUNCTION__, 0);

	ContentCountTest(fullName, GetSpecialProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

	ContentCountTest(fullName, GetSpecialVersions(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

	ContentCountTest(fullName, GetSpecialSolutionName(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetSolutionName(), defaultNameSpaceCount, __FUNCTION__, 6);

	ContentCountTest(fullName, GetSpecialManagerName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetEventManagerName(), defaultManagerNameCount, __FUNCTION__, 8);

	ContentCountTest(fullName, GetSpecialProjectCapital(), 0, __FUNCTION__, 9);
	ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

	ContentCountTest(fullName, GetSpecialManagerCapital(), 0, __FUNCTION__, 11);
	ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 13);
}

void AssistTools::GenerateTestingTemplateEngineTesting
	::DefaultManagerHeaderGenerateToTest(const System::String& testFileName, const System::String& resultName)
{	
	const System::String newProjectName(GetSolutionName() + GetInputManagerName());
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName); 
	const System::String extension(SYSTEM_TEXT(".h"));	
	const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + newProjectName + GetTesting());
	 
	TestingType generateTemplateSolution(fileName, extension, TestingType::Replace());

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

	int defaultNameSpaceCount = GetContentFindCount(fileName, GetDefaultSolutionName());

	int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());

	int defaultProjectCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital());
	ASSERT_LESS(0, defaultProjectCapitalCount);

	int defaultManagerCapitalCount = GetContentFindCount(fileName, GetDefaultManagerCapital());
	ASSERT_LESS(0, defaultManagerCapitalCount);

	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName(resultName);

	generateTemplateSolution.GenerateTo(fullDirectory, resultName, copyrightData, GetSolutionName(), GetInputManagerName(),
		                                GetProjectCapital(), GetInputManagerCapitalName()  + SYSTEM_TEXT("_"));

	System::String fullName = fullDirectory + GetForwardSlash() + resultName + extension;

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetSolutionName(), defaultNameSpaceCount, __FUNCTION__, 6);

	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetInputManagerName(), defaultManagerNameCount, __FUNCTION__, 8);

	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
	ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 11);
	ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 13);
}

void AssistTools::GenerateTestingTemplateEngineTesting
	::DefaultManagerCppGenerateToTest(const System::String& testFileName, const System::String& resultName)
{
	const System::String newProjectName(GetSolutionName() + GetInputManagerName());
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + testFileName); 
	const System::String extension(SYSTEM_TEXT(".cpp"));	
	const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + newProjectName + GetTesting());
	 
	TestingType generateTemplateSolution(fileName, extension, TestingType::Replace());

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

	int defaultNameSpaceCount = GetContentFindCount(fileName, GetDefaultSolutionName());

	int defaultManagerNameCount = GetContentFindCount(fileName, GetDefaultManagerName());

	int defaultProjectCapitalCount = GetContentFindCount(fileName, GetDefaultProjectCapital()); 

	int defaultManagerCapitalCount = GetContentFindCount(fileName, GetDefaultManagerCapital()); 

	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName(resultName);

	generateTemplateSolution.GenerateTo(fullDirectory, resultName, copyrightData, GetSolutionName(), GetInputManagerName(),
		                                GetProjectCapital(), GetInputManagerCapitalName()  + SYSTEM_TEXT("_"));

	System::String fullName = fullDirectory + GetForwardSlash() + resultName + extension;

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);

	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, copyrightData.GetProjectChineseName(), defaultProjectChineseNameCount, __FUNCTION__, 2);

	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, copyrightData.GetVersions(), defaultVersionsCount, __FUNCTION__, 4);

	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetSolutionName(), defaultNameSpaceCount, __FUNCTION__, 6);

	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetInputManagerName(), defaultManagerNameCount, __FUNCTION__, 8);

	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
	ContentCountTest(fullName, GetProjectCapital(), defaultProjectCapitalCount, __FUNCTION__, 10);

	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 11);
	ContentCountTest(fullName, GetInputManagerCapitalName(), defaultManagerCapitalCount, __FUNCTION__, 12);

	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 13);
}
