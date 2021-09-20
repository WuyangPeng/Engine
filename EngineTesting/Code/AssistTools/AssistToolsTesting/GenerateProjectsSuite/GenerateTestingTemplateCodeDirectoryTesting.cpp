// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 11:00)

#include "GenerateTestingTemplateCodeDirectoryTesting.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateCodeDirectory.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTestingTemplateCodeDirectory)

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting
    ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);  

	ASSERT_NOT_THROW_EXCEPTION_1(ManagerExistTest, SYSTEM_TEXT(""));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerExistTest, SYSTEM_TEXT("MiddleLayer")); 
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerExistTest, SYSTEM_TEXT("Core"));
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting
	::GenerateToTest()
{	
	const System::String newCoreName(SYSTEM_TEXT("Core"));
	const System::String newCoreCapitalName(SYSTEM_TEXT("CORE"));

	CopyrightData copyrightData = GetCopyrightData();

	TestingType generateTemplateCodeDirectory(GetResourceDirectory(), "Configuration/StringReplacing.json");

	generateTemplateCodeDirectory.GenerateTo(GetExportDirectory() + GetTesting(), GetSolutionName(), copyrightData, GetProjectCapital(), newCoreName,newCoreCapitalName);
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting
	::ManagerExistTest(const System::String& managerName)
{
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("Testing"));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("TestingHelper"));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerCppExistTest, managerName, SYSTEM_TEXT("TestingHelper"));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerCppExistTest, managerName, SYSTEM_TEXT("TestingMain"));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerCppExistTest, managerName, SYSTEM_TEXT("TestingLib"));
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting
	::ManagerHeaderExistTest(const System::String& managerName, const System::String& resultName)
{
	const System::String newProjectName(GetSolutionName() + managerName);
	const System::String extension(SYSTEM_TEXT(".h"));
	const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + newProjectName + GetTesting());
	
	System::String fullName = fullDirectory + GetForwardSlash() + resultName + extension;
	CopyrightData copyrightData(GetCopyrightData());

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions()); 
	int defaultProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital()); 

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount); 
	ASSERT_LESS(0, defaultProjectCapitalCount); 

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 7);
}

void AssistTools::GenerateTestingTemplateCodeDirectoryTesting
	::ManagerCppExistTest(const System::String& managerName, const System::String& resultName)
{
	const System::String newProjectName(GetSolutionName() + managerName);
	const System::String extension(SYSTEM_TEXT(".cpp"));
	const System::String createDirectory(GetExportDirectory() + GetTesting() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetTesting() + GetForwardSlash() + newProjectName + GetTesting());

	System::String fullName = fullDirectory + GetForwardSlash() + resultName + extension;

	CopyrightData copyrightData(GetCopyrightData());

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions()); 

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount); 

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 7);
}

