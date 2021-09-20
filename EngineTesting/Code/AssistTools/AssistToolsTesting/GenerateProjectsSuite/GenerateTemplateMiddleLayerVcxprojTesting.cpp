// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:59)

#include "GenerateTemplateMiddleLayerVcxprojTesting.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMiddleLayerVcxproj.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateMiddleLayerVcxproj)

void AssistTools::GenerateTemplateMiddleLayerVcxprojTesting
    ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest);
}

void AssistTools::GenerateTemplateMiddleLayerVcxprojTesting
	::GenerateToTest()
{	 
	const System::String newIncludeName(SYSTEM_TEXT("GameTemplateInclude")); 
	const System::String fileName(GetResourceDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMiddleLayerVcxproj.txt"));
	const System::String projectName(SYSTEM_TEXT("DllProjectName"));
	const System::String includeName(SYSTEM_TEXT("IncludeName"));	
	const System::String extension(SYSTEM_TEXT(".vcxproj")); 
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + GetMiddleLayerName());

	int projectNameCount = GetContentFindCount(fileName, projectName);
	int coreNameCount = GetContentFindCount(fileName, includeName);

	TestingType generateTemplateSolution(fileName, projectName, GetDefaultManagerName(), includeName);

	generateTemplateSolution.GenerateTo(fullDirectory, GetSolutionName(), GetMiddleLayerName(), newIncludeName);

	System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + GetMiddleLayerName() + extension;

	ContentCountTest(fullName, GetSolutionName(), projectNameCount, __FUNCTION__, 0);
	ContentCountTest(fullName, newIncludeName, coreNameCount, __FUNCTION__, 1);

	ContentCountTest(fullName, projectName, 0, __FUNCTION__, 2);
	ContentCountTest(fullName, includeName, 0, __FUNCTION__, 3); 
}
 
