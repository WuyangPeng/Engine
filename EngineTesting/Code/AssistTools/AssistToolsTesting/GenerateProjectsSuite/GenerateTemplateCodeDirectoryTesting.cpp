// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:52)

#include "GenerateTemplateCodeDirectoryTesting.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTemplateCodeDirectory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(AssistTools, GenerateTemplateCodeDirectory)

void AssistTools::GenerateTemplateCodeDirectoryTesting
    ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GenerateToTest); 
	ASSERT_NOT_THROW_EXCEPTION_0(HeaderExistTest);
	ASSERT_NOT_THROW_EXCEPTION_1(HelperExistToTest, SYSTEM_TEXT(".h"));
	ASSERT_NOT_THROW_EXCEPTION_1(HelperExistToTest, SYSTEM_TEXT(".cpp"));
	ASSERT_NOT_THROW_EXCEPTION_1(MessageExistToTest, SYSTEM_TEXT(".h"));
	ASSERT_NOT_THROW_EXCEPTION_1(MessageExistToTest, SYSTEM_TEXT(".cpp"));
	ASSERT_NOT_THROW_EXCEPTION_0(LibExistTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MainExistTest);

	ASSERT_NOT_THROW_EXCEPTION_1(ManagerExistTest, SYSTEM_TEXT("MiddleLayer")); 
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerExistTest, SYSTEM_TEXT("Core")); 

	ASSERT_NOT_THROW_EXCEPTION_0(InputManagerEngineExistTest);
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("Network"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("ObjectLogic"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("ArtificialIntellegence"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("PhysicalModelling"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("Message"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("Event"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("System"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("Resource"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("Audio"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("CameraSystems"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("Rendering"));
	ASSERT_NOT_THROW_EXCEPTION_1(ManagerEngineExistTest, SYSTEM_TEXT("GUI"));
	ASSERT_NOT_THROW_EXCEPTION_0(CoreEngineExistTest);
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::GenerateToTest()
{	
	const System::String projectName(SYSTEM_TEXT("Project"));
	CopyrightData copyrightData = GetCopyrightData();

	TestingType generateTemplateCodeDirectory(GetResourceDirectory(), "Configuration/StringReplacing.json");

	generateTemplateCodeDirectory.GenerateTo(GetExportDirectory(), GetSolutionName(), copyrightData, GetProjectCapital(), projectName, SYSTEM_TEXT("Core"), SYSTEM_TEXT("CORE"));
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::HeaderExistTest()
{ 
	const System::String extension(SYSTEM_TEXT(".h"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());

	System::String fullName = fullDirectory + GetForwardSlash() + GetSolutionName() + extension;
	CopyrightData copyrightData = GetCopyrightData();	 

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultProjectCapitalCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2); 
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 3);	 	
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 6); 
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 7);
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::HelperExistToTest(const System::String& extension)
{
	const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Helper"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());
	CopyrightData copyrightData(GetCopyrightData());
	System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
	int defaultProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());
	int defaultSolutionNameCount = GetContentFindCount(fullName, GetSolutionName());

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount);
	if (extension == SYSTEM_TEXT(".h"))
	{
		ASSERT_LESS(0, defaultProjectCapitalCount);
	}	
	ASSERT_LESS(0, defaultSolutionNameCount); 

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 8);	
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::MessageExistToTest(const System::String& extension)
{
	const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Message"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());
	CopyrightData copyrightData(GetCopyrightData());	

	System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
	int defaultProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());
	int defaultSolutionNameCount = GetContentFindCount(fullName, GetSolutionName());

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount);
	if (extension == SYSTEM_TEXT(".h"))
	{
		ASSERT_LESS(0, defaultProjectCapitalCount);
	}
	ASSERT_LESS(0, defaultSolutionNameCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 8); 
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::LibExistTest()
{
	const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Lib"));
	const System::String extension(SYSTEM_TEXT(".cpp"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());
	CopyrightData copyrightData(GetCopyrightData());
	System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions()); 
	int defaultSolutionNameCount = GetContentFindCount(fullName, GetSolutionName());

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount); 
	ASSERT_LESS(0, defaultSolutionNameCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2); 
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 7);
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::MainExistTest()
{
	const System::String newProjectName(GetSolutionName() + SYSTEM_TEXT("Main"));
	const System::String extension(SYSTEM_TEXT(".cpp"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetSpecialCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName());
	const System::String projectName(SYSTEM_TEXT("Project"));	 

	CopyrightData copyrightData(GetCopyrightData());

	System::String fullName = fullDirectory + GetForwardSlash() + newProjectName + extension;

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
	int defaultSolutionNameCount = GetContentFindCount(fullName, GetSolutionName());
	int defaultProjectNameCount = GetContentFindCount(fullName, projectName);

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount);
	ASSERT_LESS(0, defaultSolutionNameCount);
	ASSERT_LESS(0, defaultProjectNameCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultProjectName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 8);
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::ManagerExistTest(const System::String& managerName)
{
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("Dll"));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("Export"));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("Fwd"));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT(""));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("Import"));
	ASSERT_NOT_THROW_EXCEPTION_2(ManagerHeaderExistTest, managerName, SYSTEM_TEXT("NoImport"));

	ASSERT_NOT_THROW_EXCEPTION_1(ManagerLibExistTest, managerName);
	ASSERT_NOT_THROW_EXCEPTION_1(DllMainExistTest, managerName);
	ASSERT_NOT_THROW_EXCEPTION_1(DllLibExistTest, managerName);

	ASSERT_NOT_THROW_EXCEPTION_2(MacroExistTest, managerName, SYSTEM_TEXT("ExportMacro"));
	ASSERT_NOT_THROW_EXCEPTION_2(MacroExistTest, managerName, GetSolutionName() + managerName + SYSTEM_TEXT("ClassInvariantMacro"));
	ASSERT_NOT_THROW_EXCEPTION_2(MacroExistTest, managerName, GetSolutionName() + managerName + SYSTEM_TEXT("CustomAssertMacro"));
	ASSERT_NOT_THROW_EXCEPTION_2(MacroExistTest, managerName, SYSTEM_TEXT("Macro"));
	ASSERT_NOT_THROW_EXCEPTION_2(MacroExistTest, managerName, SYSTEM_TEXT("MacroFwd"));
	ASSERT_NOT_THROW_EXCEPTION_2(MacroExistTest, managerName, SYSTEM_TEXT("UserMacro"));	 
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::ManagerHeaderExistTest(const System::String& managerName, const System::String& resultSuffix)
{ 
	const System::String extension(SYSTEM_TEXT(".h"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + managerName);

	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName(GetSolutionName() + managerName + resultSuffix);

	System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
	int defaultProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount); 
	ASSERT_LESS(0, defaultProjectCapitalCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 8); 
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::ManagerLibExistTest(const System::String& managerName)
{
	const System::String extension(SYSTEM_TEXT(".h"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + managerName);	

	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName(GetSolutionName() + managerName + (SYSTEM_TEXT("Lib")));
	 
	System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
	int defaultProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());
	int defaultSolutionNameCount = GetContentFindCount(fullName, GetSolutionName());
	int defaultManagerNameCount = GetContentFindCount(fullName, managerName);

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount);
	ASSERT_LESS(0, defaultProjectCapitalCount);
	ASSERT_LESS(0, defaultSolutionNameCount);
	ASSERT_LESS(0, defaultManagerNameCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 8);
	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 9);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 10); 
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::DllMainExistTest(const System::String& managerName)
{ 
	const System::String extension(SYSTEM_TEXT(".cpp"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + managerName);	 

	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName((SYSTEM_TEXT("DllMain")));

	System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions()); 
	int defaultSolutionNameCount = GetContentFindCount(fullName, GetSolutionName());
	int defaultManagerNameCount = GetContentFindCount(fullName, managerName);

	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultVersionsCount); 
	ASSERT_LESS(0, defaultSolutionNameCount);
	ASSERT_LESS(0, defaultManagerNameCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2); 
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 5); 
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 8); 
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::DllLibExistTest(const System::String& managerName)
{	 
	const System::String extension(SYSTEM_TEXT(".cpp"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + managerName);
	
	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName((SYSTEM_TEXT("DllLib")));
	System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
	int defaultSolutionNameCount = GetContentFindCount(fullName, GetSolutionName());
	int defaultManagerNameCount = GetContentFindCount(fullName, managerName);

	ASSERT_LESS(0, defaultVersionsCount);
	ASSERT_LESS(0, defaultSolutionNameCount);
	ASSERT_LESS(0, defaultManagerNameCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultManagerChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 8);
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::MacroExistTest(const System::String& managerName, const System::String& resultSuffix)
{
	const System::String extension(SYSTEM_TEXT(".h"));
	const System::String macroDirectory(SYSTEM_TEXT("Macro"));
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + managerName + GetForwardSlash() + macroDirectory);
 
	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName(resultSuffix);	
	System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName + extension;

	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions()); 
	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultGetProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());

	ASSERT_LESS(0, defaultVersionsCount); 
	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultGetProjectCapitalCount);	

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultManagerChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 8);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 10);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 11);  
} 

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::ManagerEngineExistTest(const System::String& managerName)
{
	ASSERT_NOT_THROW_EXCEPTION_2(MiddleLayerEngineExistTest, managerName, managerName + SYSTEM_TEXT(".h"));
	ASSERT_NOT_THROW_EXCEPTION_2(MiddleLayerEngineExistTest, managerName, managerName + SYSTEM_TEXT("Fwd.h"));
	ASSERT_NOT_THROW_EXCEPTION_2(MiddleLayerEngineExistTest, managerName, managerName + SYSTEM_TEXT("Manager") + SYSTEM_TEXT(".h"));
	ASSERT_NOT_THROW_EXCEPTION_2(MiddleLayerEngineExistTest, managerName, managerName + SYSTEM_TEXT("Manager") + SYSTEM_TEXT(".cpp"));
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::InputManagerEngineExistTest()
{
	const System::String managerName = SYSTEM_TEXT("Input");

	ASSERT_NOT_THROW_EXCEPTION_2(MiddleLayerEngineExistTest, managerName, managerName + SYSTEM_TEXT(".h"));
	ASSERT_NOT_THROW_EXCEPTION_2(MiddleLayerEngineExistTest, managerName, managerName + SYSTEM_TEXT("Fwd.h"));
	ASSERT_NOT_THROW_EXCEPTION_2(MiddleLayerEngineExistTest, managerName, managerName + SYSTEM_TEXT("Manager.h"));
	ASSERT_NOT_THROW_EXCEPTION_2(MiddleLayerEngineExistTest, managerName, managerName + SYSTEM_TEXT("ManagerDetail.h"));
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::CoreEngineExistTest()
{
	const System::String managerName = SYSTEM_TEXT("Core");

	ASSERT_NOT_THROW_EXCEPTION_2(EngineExistTest, managerName, SYSTEM_TEXT("Engine.h"));
	ASSERT_NOT_THROW_EXCEPTION_2(EngineExistTest, managerName, SYSTEM_TEXT("EngineFwd.h")); 
	ASSERT_NOT_THROW_EXCEPTION_2(EngineExistTest, managerName, SYSTEM_TEXT("Placeholder.h"));
	ASSERT_NOT_THROW_EXCEPTION_2(EngineExistTest, managerName, SYSTEM_TEXT("Placeholder.cpp"));
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::EngineExistTest(const System::String& managerName, const System::String& resultSuffix)
{
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + managerName + GetForwardSlash() + GetEngineDirectory());
	
	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName(resultSuffix);

	System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName;

	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultGetProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());

	ASSERT_LESS(0, defaultVersionsCount);
	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultGetProjectCapitalCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultManagerChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 8);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 10);
	ContentCountTest(fullName, GetDefaultInterfaceName(), 0, __FUNCTION__, 11);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 12);
}

void AssistTools::GenerateTemplateCodeDirectoryTesting
	::MiddleLayerEngineExistTest(const System::String& managerName, const System::String& resultSuffix)
{
	const System::String createDirectory(GetExportDirectory() + GetForwardSlash() + GetCodeEngineDirectory());
	const System::String fullDirectory(createDirectory + GetForwardSlash() + GetSolutionName() + GetForwardSlash() + GetSolutionName() + SYSTEM_TEXT("MiddleLayer") + GetForwardSlash() + managerName);

	CopyrightData copyrightData(GetCopyrightData());
	const System::String newFullProjectName(resultSuffix);

	System::String fullName = fullDirectory + GetForwardSlash() + newFullProjectName;

	int defaultVersionsCount = GetContentFindCount(fullName, copyrightData.GetVersions());
	int defaultProjectChineseNameCount = GetContentFindCount(fullName, copyrightData.GetProjectChineseName());
	int defaultGetProjectCapitalCount = GetContentFindCount(fullName, GetProjectCapital());

	ASSERT_LESS(0, defaultVersionsCount);
	ASSERT_LESS(0, defaultProjectChineseNameCount);
	ASSERT_LESS(0, defaultGetProjectCapitalCount);

	ContentCountTest(fullName, GetDefaultEndYear(), 0, __FUNCTION__, 0);
	ContentCountTest(fullName, GetDefaultManagerChineseName(), 0, __FUNCTION__, 1);
	ContentCountTest(fullName, GetDefaultVersions(), 0, __FUNCTION__, 2);
	ContentCountTest(fullName, GetDefaultDate(), 0, __FUNCTION__, 3);
	ContentCountTest(fullName, GetDefaultHour(), 0, __FUNCTION__, 4);
	ContentCountTest(fullName, GetDefaultMinute(), 0, __FUNCTION__, 5);
	ContentCountTest(fullName, GetDefaultSolutionName(), 0, __FUNCTION__, 6);
	ContentCountTest(fullName, GetDefaultManagerName(), 0, __FUNCTION__, 7);
	ContentCountTest(fullName, GetDefaultProjectChineseName(), 0, __FUNCTION__, 8);
	ContentCountTest(fullName, GetDefaultProjectCapital(), 0, __FUNCTION__, 9);
	ContentCountTest(fullName, GetDefaultManagerCapital(), 0, __FUNCTION__, 10);
	ContentCountTest(fullName, GetDefaultInterfaceName(), 0, __FUNCTION__, 11);
	ContentCountTest(fullName, GetPercent(), 0, __FUNCTION__, 12);
 
}

