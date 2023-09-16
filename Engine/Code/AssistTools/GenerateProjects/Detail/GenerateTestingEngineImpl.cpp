///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/25 09:49)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingEngineImpl.h"
#include "System/FileManager/FileTools.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"

AssistTools::GenerateTestingEngineImpl::GenerateTestingEngineImpl(const String& input, String output)
    : input{ input },
      output{ std::move(output) },
      gameParameterAnalysis{ "Configuration/GameTestingParameter.json" },
      codeMappingAnalysis{ input + SYSTEM_TEXT("GenerateProjects.json") }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTestingEngineImpl)

void AssistTools::GenerateTestingEngineImpl::Generate() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    const auto result = System::CreateFileDirectory(output, nullptr);

    System::UnusedFunction(result);

    GenerateTop();
    GenerateBinary(SYSTEM_TEXT("x64"));
    GenerateBinary(SYSTEM_TEXT("Win32"));
    GenerateRun();
    GenerateDoxygen();
    GenerateDoc();
    GenerateBat();
    GenerateCode();
    GenerateWindows();
}

void AssistTools::GenerateTestingEngineImpl::GenerateTop() const
{
    Generate(input + SYSTEM_TEXT("ReadMeMd.txt"), output + SYSTEM_TEXT("ReadMe.md"));
    Generate(input + SYSTEM_TEXT("GitIgnore.txt"), output + SYSTEM_TEXT(".gitignore"));
    Generate(input + SYSTEM_TEXT("ClangFormat.txt"), output + SYSTEM_TEXT(".clang-format"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateBinary(const String& configuration) const
{
    const auto result = System::CreateFileDirectory(output + configuration, nullptr);

    System::UnusedFunction(result);

    const auto directory = output + configuration;

    Generate(input + SYSTEM_TEXT("Generate/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"), { { SYSTEM_TEXT("Configuration"), configuration } });
    Generate(input + SYSTEM_TEXT("Generate/GitIgnore.txt"), directory + SYSTEM_TEXT("/.gitignore"));

    GenerateBinaryConfiguration(configuration, SYSTEM_TEXT("Debug"));
    GenerateBinaryConfiguration(configuration, SYSTEM_TEXT("EngineStaticDebug"));
    GenerateBinaryConfiguration(configuration, SYSTEM_TEXT("GameStaticDebug"));
    GenerateBinaryConfiguration(configuration, SYSTEM_TEXT("StaticDebug"));
    GenerateBinaryConfiguration(configuration, SYSTEM_TEXT("Release"));
    GenerateBinaryConfiguration(configuration, SYSTEM_TEXT("EngineStaticRelease"));
    GenerateBinaryConfiguration(configuration, SYSTEM_TEXT("GameStaticRelease"));
    GenerateBinaryConfiguration(configuration, SYSTEM_TEXT("StaticRelease"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateBinaryConfiguration(const String& configuration, const String& staticDescribe) const
{
    const auto directory = output + configuration + SYSTEM_TEXT("/") + staticDescribe + SYSTEM_TEXT("Windows");
    const auto resultWindows = System::CreateFileDirectory(directory, nullptr);
    const auto resultConfiguration = System::CreateFileDirectory(directory + SYSTEM_TEXT("/Configuration"), nullptr);

    System::UnusedFunction(resultWindows, resultConfiguration);

    Generate(input + SYSTEM_TEXT("Generate/Configuration/EnvironmentVariableJson.txt"), directory + SYSTEM_TEXT("/Configuration/EnvironmentVariable.json"));
    Generate(input + SYSTEM_TEXT("Generate/Configuration/LogJson.txt"), directory + SYSTEM_TEXT("/Configuration/Log.json"), { { SYSTEM_TEXT("Configuration"), staticDescribe } });
    Generate(input + SYSTEM_TEXT("Generate/Configuration/ProjectTestingJson.txt"), directory + SYSTEM_TEXT("/Configuration/ProjectTesting.json"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateRun() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/RunTesting"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Run/ReadMeMd.txt"), output + SYSTEM_TEXT("RunTesting/ReadMe.md"));
    Generate(input + SYSTEM_TEXT("Run/GitIgnore.txt"), output + SYSTEM_TEXT("RunTesting/.gitignore"));
    Generate(input + SYSTEM_TEXT("Run/RunAllTestingBat.txt"), output + SYSTEM_TEXT("RunTesting/RunAll") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".bat"));
    Generate(input + SYSTEM_TEXT("Run/RunProjectTestingBat.txt"), output + SYSTEM_TEXT("RunTesting/Run") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".bat"));
    GenerateRunBat();
}

void AssistTools::GenerateTestingEngineImpl::GenerateRunBat() const
{
    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        GenerateRunBat(iter->GetModuleName());
    }
}

void AssistTools::GenerateTestingEngineImpl::GenerateRunBat(const String& moduleName) const
{
    Generate(input + SYSTEM_TEXT("Run/RunAllModuleTestingBat.txt"), output + SYSTEM_TEXT("RunTesting/RunAll") + moduleName + SYSTEM_TEXT("Testing.bat"), { { SYSTEM_TEXT("ModuleName"), moduleName } });
    Generate(input + SYSTEM_TEXT("Run/RunModuleCoreTestingBat.txt"), output + SYSTEM_TEXT("RunTesting/Run") + moduleName + SYSTEM_TEXT("CoreTesting.bat"), { { SYSTEM_TEXT("ModuleName"), moduleName } });
    Generate(input + SYSTEM_TEXT("Run/RunModuleMiddleLayerTestingBat.txt"), output + SYSTEM_TEXT("RunTesting/Run") + moduleName + SYSTEM_TEXT("MiddleLayerTesting.bat"), { { SYSTEM_TEXT("ModuleName"), moduleName } });
    Generate(input + SYSTEM_TEXT("Run/RunModuleTestingBat.txt"), output + SYSTEM_TEXT("RunTesting/Run") + moduleName + SYSTEM_TEXT("Testing.bat"), { { SYSTEM_TEXT("ModuleName"), moduleName } });
}

void AssistTools::GenerateTestingEngineImpl::GenerateDoxygen() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Doxygen"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Doxygen/Doxyfile.txt"), output + SYSTEM_TEXT("Doxygen/Doxyfile"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateDoc() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Doc"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Doc/OverviewMd.txt"), output + SYSTEM_TEXT("Doc/Overview.md"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateBat() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Bat"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Bat/DelDoxygenFileBat.txt"), output + SYSTEM_TEXT("Bat/DelDoxygenFile.bat"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateCode() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Code"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Code/ReadMeMd.txt"), output + SYSTEM_TEXT("Code/ReadMe.md"));
    Generate(input + SYSTEM_TEXT("Code/GitIgnore.txt"), output + SYSTEM_TEXT("Code/.gitignore"));
    GenerateCodeProject();
    GenerateCodeModule();
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeProject() const
{
    const auto directory = output + SYSTEM_TEXT("/Code/") + gameParameterAnalysis.GetProjectName();
    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Code/Project/TestingH.txt"), directory + SYSTEM_TEXT("/Testing.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/TestingHelperCpp.txt"), directory + SYSTEM_TEXT("/TestingHelper.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/TestingHelperH.txt"), directory + SYSTEM_TEXT("/TestingHelper.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/TestingLibCpp.txt"), directory + SYSTEM_TEXT("/TestingLib.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/TestingMainCpp.txt"), directory + SYSTEM_TEXT("/TestingMain.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/VersionH.txt"), directory + SYSTEM_TEXT("/Version.h"));
    GenerateCodeVersion();
    GenerateCodeEngine();
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeVersion() const
{
    const auto directory = output + SYSTEM_TEXT("/Code/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/VersionSuite/");
    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Code/Project/VersionSuite/VersionSuiteH.txt"), directory + SYSTEM_TEXT("VersionSuite.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/VersionSuite/VersionTestingCpp.txt"), directory + SYSTEM_TEXT("VersionTesting.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/VersionSuite/VersionTestingH.txt"), directory + SYSTEM_TEXT("VersionTesting.h"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeEngine() const
{
    const auto directory = output + SYSTEM_TEXT("/Code/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/EngineSuite/");
    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Code/Project/EngineSuite/EngineSuiteH.txt"), directory + SYSTEM_TEXT("EngineSuite.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/EngineSuite/EngineTestingCpp.txt"), directory + SYSTEM_TEXT("EngineTesting.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/EngineSuite/EngineTestingH.txt"), directory + SYSTEM_TEXT("EngineTesting.h"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeModule() const
{
    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        GenerateCodeModule(*iter);
    }
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeModule(const GameModule& gameModule) const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Code/") + gameModule.GetModuleName() + SYSTEM_TEXT("Testing"), nullptr);

    System::UnusedFunction(result);

    GenerateCodeModuleCore(gameModule);
    GenerateCodeModuleMiddleLayer(gameModule);
    GenerateCodeModuleExe(gameModule);
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeModuleCore(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("CoreTesting/");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/ModuleCore/TestingH.txt"), directory + SYSTEM_TEXT("Testing.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/ModuleCore/TestingHelperCpp.txt"), directory + SYSTEM_TEXT("TestingHelper.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/ModuleCore/TestingHelperH.txt"), directory + SYSTEM_TEXT("TestingHelper.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/ModuleCore/TestingLibCpp.txt"), directory + SYSTEM_TEXT("TestingLib.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/ModuleCore/TestingMainCpp.txt"), directory + SYSTEM_TEXT("TestingMain.cpp"), replace);
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeModuleMiddleLayer(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("MiddleLayerTesting/");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/ModuleMiddleLayer/TestingH.txt"), directory + SYSTEM_TEXT("Testing.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/ModuleMiddleLayer/TestingHelperCpp.txt"), directory + SYSTEM_TEXT("TestingHelper.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/ModuleMiddleLayer/TestingHelperH.txt"), directory + SYSTEM_TEXT("TestingHelper.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/ModuleMiddleLayer/TestingLibCpp.txt"), directory + SYSTEM_TEXT("TestingLib.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/ModuleMiddleLayer/TestingMainCpp.txt"), directory + SYSTEM_TEXT("TestingMain.cpp"), replace);
}

void AssistTools::GenerateTestingEngineImpl::GenerateCodeModuleExe(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("Testing/");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/Module/TestingH.txt"), directory + SYSTEM_TEXT("Testing.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/TestingHelperCpp.txt"), directory + SYSTEM_TEXT("TestingHelper.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/TestingHelperH.txt"), directory + SYSTEM_TEXT("TestingHelper.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/TestingLibCpp.txt"), directory + SYSTEM_TEXT("TestingLib.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/TestingMainCpp.txt"), directory + SYSTEM_TEXT("TestingMain.cpp"), replace);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindows() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/SetEnvironmentBat.txt"), directory + SYSTEM_TEXT("/SetEnvironment.bat"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectX64ReleaseLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("X64ReleaseLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectX64DebugLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("X64DebugLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectWin32ReleaseLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Win32ReleaseLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectWin32DebugLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Win32DebugLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectStaticX64ReleaseLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("StaticX64ReleaseLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectStaticX64DebugLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("StaticX64DebugLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectStaticWin32ReleaseLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("StaticWin32ReleaseLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectStaticWin32DebugLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("StaticWin32DebugLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectEngineStaticGameDynamicX64ReleaseLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("EngineStaticGameDynamicX64ReleaseLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectEngineStaticGameDynamicX64DebugLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("EngineStaticGameDynamicX64DebugLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectEngineStaticGameDynamicWin32ReleaseLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("EngineStaticGameDynamicWin32ReleaseLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectEngineStaticGameDynamicWin32DebugLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("EngineStaticGameDynamicWin32DebugLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectEngineDynamicGameStaticX64ReleaseLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("EngineDynamicGameStaticX64ReleaseLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectEngineDynamicGameStaticX64DebugLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("EngineDynamicGameStaticX64DebugLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectEngineDynamicGameStaticWin32ReleaseLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("EngineDynamicGameStaticWin32ReleaseLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/ProjectEngineDynamicGameStaticWin32DebugLibsProps.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("EngineDynamicGameStaticWin32DebugLibs.props"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Gitignore.txt"), directory + SYSTEM_TEXT("/.gitignore"));

    GenerateWindowsProject();

    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        GenerateWindowsProjectModule(*iter);
    }
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProject() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName();

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/ProjectSln.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".sln"));

    GenerateWindowsProjectVcxproj();
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectVcxproj() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName();

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/ProjectVcxproj.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".vcxproj"));
    GenerateUtf8(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/ProjectVcxprojFilters.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".vcxproj.filters"));

    GenerateWindowsProjectResource();
    GenerateWindowsProjectConfiguration();
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectResource() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/Resource");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Resource/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Resource/ScheduleMd.txt"), directory + SYSTEM_TEXT("/Schedule.md"));

    GenerateWindowsProjectResourceTodo();
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectResourceTodo() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/Resource/Todo");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    for (auto i = 0; i < 10; ++i)
    {
        const ProjectGeneration::ReplaceType replace{ { SYSTEM_TEXT("LevelIndex"), System::ToString(i) } };

        Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Resource/Todo/Level.txt"),
                 directory + SYSTEM_TEXT("/Level ") + System::ToString(i) + SYSTEM_TEXT(".txt"),
                 replace);
    }
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectConfiguration() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/Configuration");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/EnvironmentVariableJson.txt"), directory + SYSTEM_TEXT("/EnvironmentVariable.json"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/LogJson.txt"), directory + SYSTEM_TEXT("/Log.json"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/ProjectTestingJson.txt"), directory + SYSTEM_TEXT("/ProjectTesting.json"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/ProjectTestingNameJson.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".json"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/Testing.txt"), directory + SYSTEM_TEXT("/Testing.json"));
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModule(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    GenerateWindowsProjectModuleCore(gameModule);
    GenerateWindowsProjectModuleMiddleLayer(gameModule);
    GenerateWindowsProjectModuleExe(gameModule);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleCore(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("CoreTesting");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/ModuleCoreVcxproj.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("CoreTesting.vcxproj"), replace);
    GenerateUtf8(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/ModuleCoreVcxprojFilters.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("CoreTesting.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleCoreResource(gameModule);
    GenerateWindowsProjectModuleCoreConfiguration(gameModule);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleMiddleLayer(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("MiddleLayerTesting");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/ModuleMiddleLayerVcxproj.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayerTesting.vcxproj"), replace);
    GenerateUtf8(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/ModuleMiddleLayerVcxprojFilters.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayerTesting.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleMiddleLayerResource(gameModule);
    GenerateWindowsProjectModuleMiddleLayerConfiguration(gameModule);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleExe(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("Testing");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/ModuleVcxproj.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Testing.vcxproj"), replace);
    GenerateUtf8(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/ModuleVcxprojFilters.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Testing.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleExeResource(gameModule);
    GenerateWindowsProjectModuleExeConfiguration(gameModule);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleCoreResource(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("CoreTesting/Resource");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Resource/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Resource/ScheduleMd.txt"), directory + SYSTEM_TEXT("/Schedule.md"), replace);

    GenerateWindowsProjectModuleCoreResourceTodo(gameModule);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleMiddleLayerResource(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("MiddleLayerTesting/Resource");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Resource/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Resource/ScheduleMd.txt"), directory + SYSTEM_TEXT("/Schedule.md"), replace);

    GenerateWindowsProjectModuleMiddleLayerResourceTodo(gameModule);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleExeResource(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("Testing/Resource");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Resource/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Resource/ScheduleMd.txt"), directory + SYSTEM_TEXT("/Schedule.md"), replace);

    GenerateWindowsProjectModuleExeResourceTodo(gameModule);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleCoreConfiguration(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("CoreTesting/Configuration");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Configuration/EnvironmentVariableJson.txt"), directory + SYSTEM_TEXT("/EnvironmentVariable.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Configuration/LogJson.txt"), directory + SYSTEM_TEXT("/Log.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Configuration/Testing.txt"), directory + SYSTEM_TEXT("/Testing.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Configuration/ModuleTestingJson.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("CoreTesting.json"), replace);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleMiddleLayerConfiguration(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("MiddleLayerTesting/Configuration");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Configuration/EnvironmentVariableJson.txt"), directory + SYSTEM_TEXT("/EnvironmentVariable.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Configuration/LogJson.txt"), directory + SYSTEM_TEXT("/Log.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Configuration/Testing.txt"), directory + SYSTEM_TEXT("/Testing.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Configuration/ModuleTestingJson.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayerTesting.json"), replace);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleExeConfiguration(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("Testing/Configuration");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Configuration/EnvironmentVariableJson.txt"), directory + SYSTEM_TEXT("/EnvironmentVariable.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Configuration/LogJson.txt"), directory + SYSTEM_TEXT("/Log.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Configuration/Testing.txt"), directory + SYSTEM_TEXT("/Testing.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Configuration/ModuleTestingJson.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Testing.json"), replace);
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleCoreResourceTodo(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("CoreTesting/Resource/Todo");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    for (auto i = 0; i < 10; ++i)
    {
        const ProjectGeneration::ReplaceType replace{ { SYSTEM_TEXT("LevelIndex"), System::ToString(i) } };

        Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Resource/Todo/Level.txt"),
                 directory + SYSTEM_TEXT("/Level ") + System::ToString(i) + SYSTEM_TEXT(".txt"),
                 replace);
    }
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleMiddleLayerResourceTodo(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("MiddleLayerTesting/Resource/Todo");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    for (auto i = 0; i < 10; ++i)
    {
        const ProjectGeneration::ReplaceType replace{ { SYSTEM_TEXT("LevelIndex"), System::ToString(i) } };

        Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Resource/Todo/Level.txt"),
                 directory + SYSTEM_TEXT("/Level ") + System::ToString(i) + SYSTEM_TEXT(".txt"),
                 replace);
    }
}

void AssistTools::GenerateTestingEngineImpl::GenerateWindowsProjectModuleExeResourceTodo(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetTestingName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("Testing/") + moduleName + SYSTEM_TEXT("Testing/Resource/Todo");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    for (auto i = 0; i < 10; ++i)
    {
        const ProjectGeneration::ReplaceType replace{ { SYSTEM_TEXT("LevelIndex"), System::ToString(i) } };

        Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Resource/Todo/Level.txt"),
                 directory + SYSTEM_TEXT("/Level ") + System::ToString(i) + SYSTEM_TEXT(".txt"),
                 replace);
    }
}

void AssistTools::GenerateTestingEngineImpl::Generate(const String& inputFileName, const String& outputFileName) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Default,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    CoreTools::OFStreamManager streamManager{ outputFileName, false };
    streamManager.SetSimplifiedChinese();

    streamManager << content;
}

void AssistTools::GenerateTestingEngineImpl::Generate(const String& inputFileName, const String& outputFileName, const ReplaceType& replace) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Default,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis,
                                               replace };

    const auto content = projectGeneration.GetContent();

    CoreTools::OFStreamManager streamManager{ outputFileName, false };
    streamManager.SetSimplifiedChinese();

    streamManager << content;
}

void AssistTools::GenerateTestingEngineImpl::Generate(const String& inputFileName, const String& outputFileName, bool isClient) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Default,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis,
                                               isClient };

    const auto content = projectGeneration.GetContent();

    CoreTools::OFStreamManager streamManager{ outputFileName, false };
    streamManager.SetSimplifiedChinese();

    streamManager << content;
}

void AssistTools::GenerateTestingEngineImpl::GenerateUtf8(const String& inputFileName, const String& outputFileName) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Utf8,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    CoreTools::OFStreamManager streamManager{ outputFileName, false };

    streamManager << content;
}

void AssistTools::GenerateTestingEngineImpl::GenerateUtf8(const String& inputFileName, const String& outputFileName, const ReplaceType& replace) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Utf8,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis,
                                               replace };

    const auto content = projectGeneration.GetContent();

    CoreTools::OFStreamManager streamManager{ outputFileName, false };

    streamManager << content;
}
