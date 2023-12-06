///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/17 18:15)

#include "AssistTools/AssistToolsExport.h"

#include "CodeModuleTestingGenerate.h"
#include "GenerateEngineBaseDetail.h"
#include "GenerateTestingEngineImpl.h"
#include "WindowsProjectModuleTestingGenerate.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/Replace.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

AssistTools::GenerateTestingEngineImpl::GenerateTestingEngineImpl(const String& input, const String& output)
    : ParentType{ input, output, "Configuration/GameTestingParameter.json" },
      projectName{ GetProjectName() },
      testingName{ GetTestingName() }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingEngineImpl)

void AssistTools::GenerateTestingEngineImpl::GenerateBinaryConfiguration(const String& staticDescribe, const GenerateDirectory& directory) const
{
    const auto nextDirectory = CreateBinaryConfigurationFileDirectory(staticDescribe, directory);

    const ReplaceContainer replace{ { Replace{ configurationDescribe, staticDescribe } } };
    Generate(nextDirectory, logJson, logJsonOriginal, replace);

    const ReplaceContainer project{ { Replace{ environmentVariable, environmentVariableOriginal.data() },
                                      Replace{ projectTestingJson, projectTestingJsonOriginal.data() },
                                      Replace{ testingJson, testingJsonOriginal.data() } } };

    Generate(nextDirectory, project);
}

void AssistTools::GenerateTestingEngineImpl::GenerateRun() const
{
    const auto directory = GetGenerateDirectory(runDescribe, runTestingDescribe.data());
    directory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ readMeMd, readMeMdOriginal.data() },
                                      Replace{ gitIgnore, gitIgnoreOriginal.data() },
                                      Replace{ runAllTestingBat, SYSTEM_TEXT("RunAll") + projectName + batExtension.data() },
                                      Replace{ runProjectTestingBat, SYSTEM_TEXT("Run") + projectName + batExtension.data() } } };

    Generate(directory, project);
    GenerateRunBat(directory);
}

void AssistTools::GenerateTestingEngineImpl::GenerateRunBat(const GenerateDirectory& directory) const
{
    ParentType::GenerateRunBat(directory);
}

void AssistTools::GenerateTestingEngineImpl::GenerateRunBat(const String& moduleName, const GenerateDirectory& directory) const
{
    const GenerateFile::ReplaceContainer replace{ Replace{ moduleNameDescribe, moduleName } };
    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("RunAllModuleTestingBat"), SYSTEM_TEXT("RunAll") + moduleName + SYSTEM_TEXT("Testing.bat") },
                                      Replace{ SYSTEM_TEXT("RunModuleCoreTestingBat"), SYSTEM_TEXT("Run") + moduleName + SYSTEM_TEXT("CoreTesting.bat") },
                                      Replace{ SYSTEM_TEXT("RunModuleMiddleLayerTestingBat"), SYSTEM_TEXT("Run") + moduleName + SYSTEM_TEXT("MiddleLayerTesting.bat") },
                                      Replace{ SYSTEM_TEXT("RunModuleTestingBat"), SYSTEM_TEXT("Run") + moduleName + SYSTEM_TEXT("Testing.bat") } } };

    Generate(directory, project, replace);
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeProject(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(projectDescribe, projectName);
    nextDirectory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("TestingH"), SYSTEM_TEXT("Testing.h") },
                                      Replace{ SYSTEM_TEXT("TestingHelperCpp"), SYSTEM_TEXT("TestingHelper.cpp") },
                                      Replace{ SYSTEM_TEXT("TestingHelperH"), SYSTEM_TEXT("TestingHelper.h") },
                                      Replace{ SYSTEM_TEXT("TestingLibCpp"), SYSTEM_TEXT("TestingLib.cpp") },
                                      Replace{ SYSTEM_TEXT("TestingMainCpp"), SYSTEM_TEXT("TestingMain.cpp") },
                                      Replace{ SYSTEM_TEXT("VersionH"), SYSTEM_TEXT("Version.h") } } };

    Generate(nextDirectory, project);

    GenerateCodeVersion(nextDirectory);
    GenerateCodeEngine(nextDirectory);
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeVersion(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(versionSuiteDescribe);
    nextDirectory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("VersionSuiteH"), SYSTEM_TEXT("VersionSuite.h") },
                                      Replace{ SYSTEM_TEXT("VersionTestingCpp"), SYSTEM_TEXT("VersionTesting.cpp") },
                                      Replace{ SYSTEM_TEXT("VersionTestingH"), SYSTEM_TEXT("VersionTesting.h") } } };

    Generate(nextDirectory, project);
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeEngine(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(engineSuiteDescribe);
    nextDirectory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("EngineSuiteH"), SYSTEM_TEXT("EngineSuite.h") },
                                      Replace{ SYSTEM_TEXT("EngineTestingCpp"), SYSTEM_TEXT("EngineTesting.cpp") },
                                      Replace{ SYSTEM_TEXT("EngineTestingH"), SYSTEM_TEXT("EngineTesting.h") } } };

    Generate(nextDirectory, project);
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeModule(const GenerateDirectory& directory) const
{
    ExecuteModuleGenerate<CodeModuleTestingGenerate>(directory);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindows() const
{
    const auto directory = GetGenerateDirectory(projectNameWindowsDescribe, testingName + windowsDescribe.data());
    directory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("SetEnvironmentBat"), SYSTEM_TEXT("SetEnvironment.bat") },
                                      Replace{ SYSTEM_TEXT("ReadMeMd"), SYSTEM_TEXT("ReadMe.md") },
                                      Replace{ SYSTEM_TEXT("ProjectX64ReleaseLibsProps"), projectName + SYSTEM_TEXT("X64ReleaseLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectX64DebugLibsProps"), projectName + SYSTEM_TEXT("X64DebugLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectWin32ReleaseLibsProps"), projectName + SYSTEM_TEXT("Win32ReleaseLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectWin32DebugLibsProps"), projectName + SYSTEM_TEXT("Win32DebugLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectStaticX64ReleaseLibsProps"), projectName + SYSTEM_TEXT("StaticX64ReleaseLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectStaticX64DebugLibsProps"), projectName + SYSTEM_TEXT("StaticX64DebugLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectStaticWin32ReleaseLibsProps"), projectName + SYSTEM_TEXT("StaticWin32ReleaseLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectStaticWin32DebugLibsProps"), projectName + SYSTEM_TEXT("StaticWin32DebugLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectProps"), projectName + SYSTEM_TEXT(".props") },
                                      Replace{ SYSTEM_TEXT("ProjectEngineStaticGameDynamicX64ReleaseLibsProps"), projectName + SYSTEM_TEXT("EngineStaticGameDynamicX64ReleaseLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectEngineStaticGameDynamicX64DebugLibsProps"), projectName + SYSTEM_TEXT("EngineStaticGameDynamicX64DebugLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectEngineStaticGameDynamicWin32ReleaseLibsProps"), projectName + SYSTEM_TEXT("EngineStaticGameDynamicWin32ReleaseLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectEngineStaticGameDynamicWin32DebugLibsProps"), projectName + SYSTEM_TEXT("EngineStaticGameDynamicWin32DebugLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectEngineDynamicGameStaticX64ReleaseLibsProps"), projectName + SYSTEM_TEXT("EngineDynamicGameStaticX64ReleaseLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectEngineDynamicGameStaticX64DebugLibsProps"), projectName + SYSTEM_TEXT("EngineDynamicGameStaticX64DebugLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectEngineDynamicGameStaticWin32ReleaseLibsProps"), projectName + SYSTEM_TEXT("EngineDynamicGameStaticWin32ReleaseLibs.props") },
                                      Replace{ SYSTEM_TEXT("ProjectEngineDynamicGameStaticWin32DebugLibsProps"), projectName + SYSTEM_TEXT("EngineDynamicGameStaticWin32DebugLibs.props") },
                                      Replace{ SYSTEM_TEXT("Gitignore"), SYSTEM_TEXT(".gitignore") } } };

    Generate(directory, project);

    GenerateWindowsProject(directory);
    GenerateWindowsProjectModule(directory);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModule(const GenerateDirectory& directory) const
{
    ExecuteModuleGenerate<WindowsProjectModuleTestingGenerate>(directory);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProject(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(projectDescribe, projectName);
    nextDirectory.CreateFileDirectory();

    GenerateSln(nextDirectory, SYSTEM_TEXT("ProjectSln"), projectName + SYSTEM_TEXT(".sln"));

    GenerateWindowsProjectVcxproj(nextDirectory);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectVcxproj(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(projectDescribe, projectName);
    nextDirectory.CreateFileDirectory();

    Generate(nextDirectory, SYSTEM_TEXT("ProjectVcxproj"), projectName + SYSTEM_TEXT(".vcxproj"));
    GenerateUtf8(nextDirectory, SYSTEM_TEXT("ProjectVcxprojFilters"), projectName + SYSTEM_TEXT(".vcxproj.filters"));

    GenerateWindowsProjectResource(nextDirectory);
    GenerateWindowsProjectConfiguration(nextDirectory);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectConfiguration(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(configurationDescribe);
    nextDirectory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("EnvironmentVariableJson"), SYSTEM_TEXT("EnvironmentVariable.json") },
                                      Replace{ SYSTEM_TEXT("LogJson"), SYSTEM_TEXT("Log.json") },
                                      Replace{ SYSTEM_TEXT("ProjectTestingJson"), SYSTEM_TEXT("ProjectTesting.json") },
                                      Replace{ SYSTEM_TEXT("ProjectTestingNameJson"), projectName + SYSTEM_TEXT(".json") },
                                      Replace{ SYSTEM_TEXT("Testing"), SYSTEM_TEXT("Testing.json") } } };

    Generate(nextDirectory, project);
}
