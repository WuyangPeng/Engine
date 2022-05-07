// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 11:00)

#include "GenerateTemplateVcxprojTesting.h"
#include "AssistTools/GenerateProjects/GenerateTemplateVcxproj.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateVcxproj)

void AssistTools::GenerateTemplateVcxprojTesting
   ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateVcxprojTesting
	::GenerateToTest()
{	 
	const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude")); 
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateVcxproj.txt"));
	const System::String projectName(SYSTEM_TEXT("ExeProjectName"));
	const System::String includeName(SYSTEM_TEXT("IncludeName"));	
	const System::String extension(SYSTEM_TEXT(".vcxproj"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

 const int projectNameCount = GetContentFindCount(fileName, projectName);
        const int coreNameCount = GetContentFindCount(fileName, includeName);

	TestingType generateTemplateSolution(fileName, projectName, includeName);

	generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), newIncludeName);

	System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

	ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
	ContentCountTest(fullName, newIncludeName, coreNameCount, __FUNCTION__, 1);

	ContentCountTest(fullName, projectName, 0, __FUNCTION__, 2);
	ContentCountTest(fullName, includeName, 0, __FUNCTION__, 3);
} 