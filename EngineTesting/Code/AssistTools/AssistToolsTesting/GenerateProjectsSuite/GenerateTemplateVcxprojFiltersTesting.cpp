// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 11:00)

#include "GenerateTemplateVcxprojFiltersTesting.h"
#include "AssistTools/GenerateProjects/GenerateTemplateVcxprojFilters.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateVcxprojFilters)

void AssistTools::GenerateTemplateVcxprojFiltersTesting
    ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateVcxprojFiltersTesting
	::GenerateToTest()
{  
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateVcxprojFilters.txt"));
	const System::String projectName(SYSTEM_TEXT("ExeProjectName")); 
	const System::String extension(SYSTEM_TEXT(".vcxproj.filters")); 
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

	int projectNameCount = GetContentFindCount(fileName, projectName); 

	TestingType generateTemplateSolution(fileName, projectName);

	generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName());

	System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;

	ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);

	ContentCountTest(fullName, projectName, 0, __FUNCTION__, 1);

	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 2);
}
 