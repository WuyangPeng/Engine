///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/17 15:51)

#include "AssistTools/AssistToolsExport.h"

#include "CodeModuleGenerate.h"
#include "GenerateEngineBaseDetail.h"
#include "GenerateEngineImpl.h"
#include "WindowsProjectModuleGenerate.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/ProjectServiceType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/Replace.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

AssistTools::GenerateEngineImpl::GenerateEngineImpl(const String& input, const String& output)
    : ParentType{ input, output, "Configuration/GameParameter.json" },
      projectName{ GetProjectName() }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateEngineImpl)

void AssistTools::GenerateEngineImpl::GenerateBinaryConfiguration(const String& staticDescribe, const GenerateDirectory& directory) const
{
    const auto nextDirectory = CreateBinaryConfigurationFileDirectory(staticDescribe, directory);

    const ReplaceContainer replace{ { Replace{ configurationDescribe, staticDescribe } } };
    Generate(nextDirectory, logJson, logJsonOriginal, replace);

    const ReplaceContainer project{ { Replace{ environmentVariable, environmentVariableOriginal.data() },
                                      Replace{ projectJson, projectJsonOriginal.data() },
                                      Replace{ projectNameJson, projectName + jsonExtension.data() },
                                      Replace{ rendererJson, rendererJsonOriginal.data() } } };

    Generate(nextDirectory, project);
}

void AssistTools::GenerateEngineImpl::GenerateRun() const
{
    const auto directory = GetGenerateDirectory(runDescribe);
    directory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ readMeMd, readMeMdOriginal.data() },
                                      Replace{ gitIgnore, gitIgnoreOriginal.data() },
                                      Replace{ runAllBat, SYSTEM_TEXT("RunAll") + projectName + batExtension.data() } } };

    Generate(directory, project);
    Generate(directory, runAllClientBat, runAllClientBatOriginal, ProjectServiceType::Client);
    Generate(directory, runAllServerBat, runAllServerBatOriginal, ProjectServiceType::Server);
    GenerateRunBat(directory);
}

void AssistTools::GenerateEngineImpl::GenerateRunBat(const GenerateDirectory& directory) const
{
    ParentType::GenerateRunBat(directory);

    GenerateRunBat(GetProjectName(), directory);
}

void AssistTools::GenerateEngineImpl::GenerateRunBat(const String& moduleName, const GenerateDirectory& directory) const
{
    const ReplaceContainer replace{ Replace{ moduleNameDescribe, moduleName } };

    Generate(directory,
             runBat,
             runDescribe.data() + moduleName + batExtension.data(),
             replace);
}

void AssistTools::GenerateEngineImpl::GenerateCodeProject(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(projectDescribe, projectName);
    nextDirectory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("ProjectFwdH"), projectName + SYSTEM_TEXT("Fwd.h") },
                                      Replace{ SYSTEM_TEXT("ProjectH"), projectName + SYSTEM_TEXT(".h") },
                                      Replace{ SYSTEM_TEXT("ProjectHelperCpp"), projectName + SYSTEM_TEXT("Helper.cpp") },
                                      Replace{ SYSTEM_TEXT("ProjectHelperH"), projectName + SYSTEM_TEXT("Helper.h") },
                                      Replace{ SYSTEM_TEXT("ProjectLibCpp"), projectName + SYSTEM_TEXT("Lib.cpp") },
                                      Replace{ SYSTEM_TEXT("ProjectMainCpp"), projectName + SYSTEM_TEXT("Main.cpp") },
                                      Replace{ SYSTEM_TEXT("ProjectMiddleLayerMessageCpp"), projectName + SYSTEM_TEXT("MiddleLayerMessage.cpp") },
                                      Replace{ SYSTEM_TEXT("ProjectMiddleLayerMessageH"), projectName + SYSTEM_TEXT("MiddleLayerMessage.h") },
                                      Replace{ SYSTEM_TEXT("VersionH"), SYSTEM_TEXT("Version.h") } } };

    Generate(nextDirectory, project);
    GenerateCodeHelper(nextDirectory);
}

void AssistTools::GenerateEngineImpl::GenerateCodeHelper(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(helperDescribe);
    nextDirectory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("HelperFwdH"), SYSTEM_TEXT("HelperFwd.h") },
                                      Replace{ SYSTEM_TEXT("HelperH"), SYSTEM_TEXT("Helper.h") },
                                      Replace{ SYSTEM_TEXT("ProjectClassInvariantMacroH"), projectName + SYSTEM_TEXT("ClassInvariantMacro.h") },
                                      Replace{ SYSTEM_TEXT("ProjectCustomAssertMacroH"), projectName + SYSTEM_TEXT("CustomAssertMacro.h") },
                                      Replace{ SYSTEM_TEXT("UserMacroH"), SYSTEM_TEXT("UserMacro.h") } } };

    Generate(nextDirectory, project);
}

void AssistTools::GenerateEngineImpl::GenerateCodeModule(const GenerateDirectory& directory) const
{
    ExecuteModuleGenerate<CodeModuleGenerate>(directory);
}

void AssistTools::GenerateEngineImpl::GenerateWindows() const
{
    const auto directory = GetGenerateDirectory(projectNameWindowsDescribe, projectName + windowsDescribe.data());
    directory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("SetEnvironmentBat"), SYSTEM_TEXT("SetEnvironment.bat") },
                                      Replace{ SYSTEM_TEXT("SetAllEnvironmentBat"), SYSTEM_TEXT("SetAllEnvironment.bat") },
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

void AssistTools::GenerateEngineImpl::GenerateWindowsProject(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(projectDescribe, projectName);
    nextDirectory.CreateFileDirectory();

    GenerateSln(nextDirectory, SYSTEM_TEXT("ProjectSln"), projectName + SYSTEM_TEXT(".sln"));

    GenerateWindowsProjectVcxproj(nextDirectory);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectVcxproj(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(projectDescribe, projectName);
    nextDirectory.CreateFileDirectory();

    Generate(nextDirectory, SYSTEM_TEXT("ProjectVcxproj"), projectName + SYSTEM_TEXT(".vcxproj"));
    GenerateUtf8(nextDirectory, SYSTEM_TEXT("ProjectVcxprojFilters"), projectName + SYSTEM_TEXT(".vcxproj.filters"));

    GenerateWindowsProjectResource(nextDirectory);
    GenerateWindowsProjectConfiguration(nextDirectory);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectConfiguration(const GenerateDirectory& directory) const
{
    const auto nextDirectory = directory.GetGenerateDirectory(configurationDescribe);
    nextDirectory.CreateFileDirectory();

    const ReplaceContainer project{ { Replace{ SYSTEM_TEXT("EnvironmentVariableJson"), SYSTEM_TEXT("EnvironmentVariable.json") },
                                      Replace{ SYSTEM_TEXT("LogJson"), SYSTEM_TEXT("Log.json") },
                                      Replace{ SYSTEM_TEXT("ProjectJson"), SYSTEM_TEXT("Project.json") },
                                      Replace{ SYSTEM_TEXT("ProjectNameJson"), projectName + SYSTEM_TEXT(".json") },
                                      Replace{ SYSTEM_TEXT("RendererJson"), SYSTEM_TEXT("Renderer.json") } } };

    Generate(nextDirectory, project);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModule(const GenerateDirectory& directory) const
{
    ExecuteModuleGenerate<WindowsProjectModuleGenerate>(directory);
}