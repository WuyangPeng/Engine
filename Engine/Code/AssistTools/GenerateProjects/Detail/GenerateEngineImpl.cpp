///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 20:41)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateEngineImpl.h"
#include "System/FileManager/FileTools.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/FileManager/OFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"

AssistTools::GenerateEngineImpl::GenerateEngineImpl(const String& input, String output)
    : input{ input },
      output{ std::move(output) },
      gameParameterAnalysis{ "Configuration/GameParameter.json" },
      codeMappingAnalysis{ input + SYSTEM_TEXT("GenerateProjects.json") }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateEngineImpl)

void AssistTools::GenerateEngineImpl::Generate() const
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

void AssistTools::GenerateEngineImpl::GenerateTop() const
{
    Generate(input + SYSTEM_TEXT("ReadMeMd.txt"), output + SYSTEM_TEXT("ReadMe.md"));
    Generate(input + SYSTEM_TEXT("GitIgnore.txt"), output + SYSTEM_TEXT(".gitignore"));
    Generate(input + SYSTEM_TEXT("ClangFormat.txt"), output + SYSTEM_TEXT(".clang-format"));
}

void AssistTools::GenerateEngineImpl::GenerateBinary(const String& configuration) const
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

void AssistTools::GenerateEngineImpl::GenerateBinaryConfiguration(const String& configuration, const String& staticDescribe) const
{
    const auto directory = output + configuration + SYSTEM_TEXT("/") + staticDescribe + SYSTEM_TEXT("Windows");
    const auto resultWindows = System::CreateFileDirectory(directory, nullptr);
    const auto resultConfiguration = System::CreateFileDirectory(directory + SYSTEM_TEXT("/Configuration"), nullptr);

    System::UnusedFunction(resultWindows, resultConfiguration);

    Generate(input + SYSTEM_TEXT("Generate/Configuration/EnvironmentVariableJson.txt"), directory + SYSTEM_TEXT("/Configuration/EnvironmentVariable.json"));
    Generate(input + SYSTEM_TEXT("Generate/Configuration/LogJson.txt"), directory + SYSTEM_TEXT("/Configuration/Log.json"), { { SYSTEM_TEXT("Configuration"), staticDescribe } });
    Generate(input + SYSTEM_TEXT("Generate/Configuration/ProjectJson.txt"), directory + SYSTEM_TEXT("/Configuration/Project.json"));
    Generate(input + SYSTEM_TEXT("Generate/Configuration/ProjectNameJson.txt"), directory + SYSTEM_TEXT("/Configuration/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".json"));
    Generate(input + SYSTEM_TEXT("Generate/Configuration/RendererJson.txt"), directory + SYSTEM_TEXT("/Configuration/Renderer.json"));
}

void AssistTools::GenerateEngineImpl::GenerateRun() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Run"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Run/ReadMeMd.txt"), output + SYSTEM_TEXT("Run/ReadMe.md"));
    Generate(input + SYSTEM_TEXT("Run/GitIgnore.txt"), output + SYSTEM_TEXT("Run/.gitignore"));
    Generate(input + SYSTEM_TEXT("Run/RunAllBat.txt"), output + SYSTEM_TEXT("Run/RunAll") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".bat"));
    Generate(input + SYSTEM_TEXT("Run/RunAllClientBat.txt"), output + SYSTEM_TEXT("Run/RunAllClient.bat"), true);
    Generate(input + SYSTEM_TEXT("Run/RunAllServerBat.txt"), output + SYSTEM_TEXT("Run/RunAllServer.bat"), false);
    GenerateRunBat();
}

void AssistTools::GenerateEngineImpl::GenerateRunBat() const
{
    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        GenerateRunBat(iter->GetModuleName());
    }

    GenerateRunBat(gameParameterAnalysis.GetProjectName());
}

void AssistTools::GenerateEngineImpl::GenerateRunBat(const String& moduleName) const
{
    Generate(input + SYSTEM_TEXT("Run/RunBat.txt"), output + SYSTEM_TEXT("Run/Run") + moduleName + SYSTEM_TEXT(".bat"), { { SYSTEM_TEXT("ModuleName"), moduleName } });
}

void AssistTools::GenerateEngineImpl::GenerateDoxygen() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Doxygen"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Doxygen/Doxyfile.txt"), output + SYSTEM_TEXT("Doxygen/Doxyfile"));
}

void AssistTools::GenerateEngineImpl::GenerateDoc() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Doc"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Doc/OverviewMd.txt"), output + SYSTEM_TEXT("Doc/Overview.md"));
}

void AssistTools::GenerateEngineImpl::GenerateBat() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Bat"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Bat/DelDoxygenFileBat.txt"), output + SYSTEM_TEXT("Bat/DelDoxygenFile.bat"));
}

void AssistTools::GenerateEngineImpl::GenerateCode() const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Code"), nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Code/ReadMeMd.txt"), output + SYSTEM_TEXT("Code/ReadMe.md"));
    Generate(input + SYSTEM_TEXT("Code/GitIgnore.txt"), output + SYSTEM_TEXT("Code/.gitignore"));
    GenerateCodeProject();
    GenerateCodeModule();
}

void AssistTools::GenerateEngineImpl::GenerateCodeProject() const
{
    const auto directory = output + SYSTEM_TEXT("/Code/") + gameParameterAnalysis.GetProjectName();
    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Code/Project/ProjectFwdH.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Fwd.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/ProjectH.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".h"));
    Generate(input + SYSTEM_TEXT("Code/Project/ProjectHelperCpp.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Helper.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/ProjectHelperH.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Helper.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/ProjectLibCpp.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Lib.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/ProjectMainCpp.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Main.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/ProjectMiddleLayerMessageCpp.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("MiddleLayerMessage.cpp"));
    Generate(input + SYSTEM_TEXT("Code/Project/ProjectMiddleLayerMessageH.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("MiddleLayerMessage.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/VersionH.txt"), directory + SYSTEM_TEXT("/Version.h"));
    GenerateCodeHelper();
}

void AssistTools::GenerateEngineImpl::GenerateCodeHelper() const
{
    const auto directory = output + SYSTEM_TEXT("/Code/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/Helper/");
    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("Code/Project/Helper/HelperFwdH.txt"), directory + SYSTEM_TEXT("HelperFwd.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/Helper/HelperH.txt"), directory + SYSTEM_TEXT("Helper.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/Helper/ProjectClassInvariantMacroH.txt"), directory + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("ClassInvariantMacro.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/Helper/ProjectCustomAssertMacroH.txt"), directory + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("CustomAssertMacro.h"));
    Generate(input + SYSTEM_TEXT("Code/Project/Helper/UserMacroH.txt"), directory + SYSTEM_TEXT("UserMacro.h"));
}

void AssistTools::GenerateEngineImpl::GenerateCodeModule() const
{
    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        GenerateCodeModule(*iter);
    }
}

void AssistTools::GenerateEngineImpl::GenerateCodeModule(const GameModule& gameModule) const
{
    const auto result = System::CreateFileDirectory(output + SYSTEM_TEXT("/Code/") + gameModule.GetModuleName(), nullptr);

    System::UnusedFunction(result);

    GenerateCodeModuleCore(gameModule);
    GenerateCodeModuleMiddleLayer(gameModule);
    GenerateCodeModuleExe(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateCodeModuleCore(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Core/");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName }, { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/Core/DllLibCpp.txt"), directory + SYSTEM_TEXT("DllLib.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/DllLibH.txt"), directory + SYSTEM_TEXT("DllLib.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/DllMainCpp.txt"), directory + SYSTEM_TEXT("DllMain.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/ModuleCoreDllH.txt"), directory + moduleName + SYSTEM_TEXT("CoreDll.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/ModuleCoreExportH.txt"), directory + moduleName + SYSTEM_TEXT("CoreExport.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/ModuleCoreFwdH.txt"), directory + moduleName + SYSTEM_TEXT("CoreFwd.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/ModuleCoreH.txt"), directory + moduleName + SYSTEM_TEXT("Core.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/ModuleCoreImportH.txt"), directory + moduleName + SYSTEM_TEXT("CoreImport.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/ModuleCoreLibH.txt"), directory + moduleName + SYSTEM_TEXT("CoreLib.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/ModuleCoreNoImportH.txt"), directory + moduleName + SYSTEM_TEXT("CoreNoImport.h"), replace);
    GenerateCodeModuleCoreEngine(gameModule);
    GenerateCodeModuleCoreHelper(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateCodeModuleCoreEngine(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Core/Engine");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName }, { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/Core/Engine/EngineFwdH.txt"), directory + SYSTEM_TEXT("/EngineFwd.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/Engine/EngineH.txt"), directory + SYSTEM_TEXT("/Engine.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/Engine/PlaceholderH.txt"), directory + SYSTEM_TEXT("/Placeholder.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/Engine/PlaceholderCpp.txt"), directory + SYSTEM_TEXT("/Placeholder.cpp"), replace);
}

void AssistTools::GenerateEngineImpl::GenerateCodeModuleCoreHelper(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Core/Helper");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName }, { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/Core/Helper/ExportMacroH.txt"), directory + SYSTEM_TEXT("/ExportMacro.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/Helper/HelperFwdH.txt"), directory + SYSTEM_TEXT("/HelperFwd.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/Helper/HelperH.txt"), directory + SYSTEM_TEXT("/Helper.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/Helper/ModuleCoreClassInvariantMacroH.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("CoreClassInvariantMacro.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/Helper/ModuleCoreCustomAssertMacroH.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("CoreCustomAssertMacro.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Core/Helper/UserMacroH.txt"), directory + SYSTEM_TEXT("/UserMacro.h"), replace);
}

void AssistTools::GenerateEngineImpl::GenerateCodeModuleMiddleLayer(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer/");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName }, { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/DllLibCpp.txt"), directory + SYSTEM_TEXT("/DllLib.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/DllLibH.txt"), directory + SYSTEM_TEXT("/DllLib.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/DllMainCpp.txt"), directory + SYSTEM_TEXT("/DllMain.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/ModuleMiddleLayerDllH.txt"), directory + moduleName + SYSTEM_TEXT("MiddleLayerDll.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/ModuleMiddleLayerExportH.txt"), directory + moduleName + SYSTEM_TEXT("MiddleLayerExport.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/ModuleMiddleLayerFwdH.txt"), directory + moduleName + SYSTEM_TEXT("MiddleLayerFwd.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/ModuleMiddleLayerH.txt"), directory + moduleName + SYSTEM_TEXT("MiddleLayer.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/ModuleMiddleLayerImportH.txt"), directory + moduleName + SYSTEM_TEXT("MiddleLayerImport.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/ModuleMiddleLayerLibH.txt"), directory + moduleName + SYSTEM_TEXT("MiddleLayerLib.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/ModuleMiddleLayerNoImportH.txt"), directory + moduleName + SYSTEM_TEXT("MiddleLayerNoImport.h"), replace);

    GenerateCodeModuleMiddleLayerHelper(gameModule);

    for (auto iter = gameParameterAnalysis.GetMiddleLayerBegin(); iter != gameParameterAnalysis.GetMiddleLayerEnd(); ++iter)
    {
        if (iter->GetMiddleLayerName() != SYSTEM_TEXT("Input"))
        {
            GenerateCodeModuleMiddleLayer(gameModule, *iter);
        }
        else
        {
            GenerateCodeModuleMiddleLayerInput(gameModule);
        }
    }
}

void AssistTools::GenerateEngineImpl::GenerateCodeModuleMiddleLayerHelper(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer/Helper");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName }, { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Helper/ExportMacroH.txt"), directory + SYSTEM_TEXT("/ExportMacro.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Helper/HelperFwdH.txt"), directory + SYSTEM_TEXT("/HelperFwd.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Helper/HelperH.txt"), directory + SYSTEM_TEXT("/Helper.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Helper/UserMacroH.txt"), directory + SYSTEM_TEXT("/UserMacro.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Helper/ModuleMiddleLayerClassInvariantMacroH.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayerClassInvariantMacro.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Helper/ModuleMiddleLayerCustomAssertMacroH.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayerCustomAssertMacro.h"), replace);
}

void AssistTools::GenerateEngineImpl::GenerateCodeModuleMiddleLayerInput(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer/Input");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName }, { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Input/InputFwdH.txt"), directory + SYSTEM_TEXT("/InputFwd.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Input/InputH.txt"), directory + SYSTEM_TEXT("/Input.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Input/InputManagerDetailH.txt"), directory + SYSTEM_TEXT("/InputManagerDetail.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/Input/InputManagerH.txt"), directory + SYSTEM_TEXT("/InputManager.h"), replace);
}

void AssistTools::GenerateEngineImpl::GenerateCodeModuleMiddleLayer(const GameModule& gameModule, const MiddleLayerModule& middleLayerModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto middleLayerName = middleLayerModule.GetMiddleLayerName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer/") + middleLayerName;

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("MiddleLayerName"), middleLayerName },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() },
                                                    { SYSTEM_TEXT("MiddleLayerUppercase"), middleLayerModule.GetUppercaseName() },
                                                    { SYSTEM_TEXT("IsManager"), middleLayerModule.IsManager() ? SYSTEM_TEXT("Manager") : SYSTEM_TEXT("") } } };

    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/MiddleLayer/MiddleLayerFwdH.txt"), directory + SYSTEM_TEXT("/") + middleLayerName + SYSTEM_TEXT("Fwd.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/MiddleLayer/MiddleLayerH.txt"), directory + SYSTEM_TEXT("/") + middleLayerName + SYSTEM_TEXT(".h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/MiddleLayer/MiddleLayerManagerCpp.txt"), directory + SYSTEM_TEXT("/") + middleLayerName + SYSTEM_TEXT("Manager.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/MiddleLayer/MiddleLayer/MiddleLayerManagerH.txt"), directory + SYSTEM_TEXT("/") + middleLayerName + SYSTEM_TEXT("Manager.h"), replace);
}

void AssistTools::GenerateEngineImpl::GenerateCodeModuleExe(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/Code/") + moduleName + SYSTEM_TEXT("/") + moduleName;

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName }, { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("Code/Module/Module/ModuleH.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT(".h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/ModuleHelperCpp.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Helper.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/ModuleHelperH.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Helper.h"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/ModuleLibCpp.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Lib.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/ModuleMainCpp.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Main.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/ModuleMessageCpp.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Message.cpp"), replace);
    Generate(input + SYSTEM_TEXT("Code/Module/Module/ModuleMessageH.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Message.h"), replace);
}

void AssistTools::GenerateEngineImpl::GenerateWindows() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/SetEnvironmentBat.txt"), directory + SYSTEM_TEXT("/SetEnvironment.bat"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/SetAllEnvironmentBat.txt"), directory + SYSTEM_TEXT("/SetAllEnvironment.bat"));
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

void AssistTools::GenerateEngineImpl::GenerateWindowsProject() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName();

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/ProjectSln.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".sln"));

    GenerateWindowsProjectVcxproj();
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectVcxproj() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName();

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/ProjectVcxproj.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".vcxproj"));
    GenerateUtf8(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/ProjectVcxprojFilters.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".vcxproj.filters"));

    GenerateWindowsProjectResource();
    GenerateWindowsProjectConfiguration();
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectResource() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/Resource");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Resource/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Resource/ScheduleMd.txt"), directory + SYSTEM_TEXT("/Schedule.md"));

    GenerateWindowsProjectResourceTodo();
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectResourceTodo() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/Resource/Todo");

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

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectConfiguration() const
{
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("/Configuration");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/EnvironmentVariableJson.txt"), directory + SYSTEM_TEXT("/EnvironmentVariable.json"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/LogJson.txt"), directory + SYSTEM_TEXT("/Log.json"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/ProjectJson.txt"), directory + SYSTEM_TEXT("/Project.json"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/ProjectNameJson.txt"), directory + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT(".json"));
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Project/Project/Configuration/RendererJson.txt"), directory + SYSTEM_TEXT("/Renderer.json"));
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModule(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName;

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleSln.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT(".sln"), replace);

    GenerateWindowsProjectModuleCore(gameModule);
    GenerateWindowsProjectModuleMiddleLayer(gameModule);
    GenerateWindowsProjectModuleExe(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleCore(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Core");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/ModuleCoreVcxproj.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Core.vcxproj"), replace);
    GenerateUtf8(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/ModuleCoreVcxprojFilters.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Core.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleCoreResource(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleMiddleLayer(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/ModuleMiddleLayerVcxproj.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer.vcxproj"), replace);
    GenerateUtf8(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/ModuleMiddleLayerVcxprojFilters.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer.vcxproj.filters"), replace);

    GenerateWindowsProjectModuleMiddleLayerResource(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleExe(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName;

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/ModuleVcxproj.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT(".vcxproj"), replace);
    GenerateUtf8(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/ModuleVcxprojFilters.txt"), directory + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT(".vcxproj.filters"), replace);

    GenerateWindowsProjectModuleExeResource(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleCoreResource(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Core/Resource");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Resource/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleCore/Resource/ScheduleMd.txt"), directory + SYSTEM_TEXT("/Schedule.md"), replace);

    GenerateWindowsProjectModuleCoreResourceTodo(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleMiddleLayerResource(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer/Resource");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Resource/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/ModuleMiddleLayer/Resource/ScheduleMd.txt"), directory + SYSTEM_TEXT("/Schedule.md"), replace);

    GenerateWindowsProjectModuleMiddleLayerResourceTodo(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleExeResource(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("/Resource");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Resource/ReadMeMd.txt"), directory + SYSTEM_TEXT("/ReadMe.md"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Resource/ScheduleMd.txt"), directory + SYSTEM_TEXT("/Schedule.md"), replace);

    GenerateWindowsProjectModuleExeResourceTodo(gameModule);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleExeConfiguration(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("/Configuration");

    const auto result = System::CreateFileDirectory(directory, nullptr);

    System::UnusedFunction(result);

    const ProjectGeneration::ReplaceType replace{ { { SYSTEM_TEXT("ModuleName"), moduleName },
                                                    { SYSTEM_TEXT("ModuleChineseName"), gameModule.GetChineseName() },
                                                    { SYSTEM_TEXT("ModuleUppercase"), gameModule.GetUppercaseName() } } };

    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Configuration/EnvironmentVariableJson.txt"), directory + SYSTEM_TEXT("/EnvironmentVariable.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Configuration/LogJson.txt"), directory + SYSTEM_TEXT("/Log.json"), replace);
    Generate(input + SYSTEM_TEXT("ProjectNameWindows/Module/Module/Configuration/RendererJson.txt"), directory + SYSTEM_TEXT("/Renderer.json"), replace);
}

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleCoreResourceTodo(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("Core/Resource/Todo");

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

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleMiddleLayerResourceTodo(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("MiddleLayer/Resource/Todo");

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

void AssistTools::GenerateEngineImpl::GenerateWindowsProjectModuleExeResourceTodo(const GameModule& gameModule) const
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = output + SYSTEM_TEXT("/") + gameParameterAnalysis.GetProjectName() + SYSTEM_TEXT("Windows/") + moduleName + SYSTEM_TEXT("/") + moduleName + SYSTEM_TEXT("/Resource/Todo");

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

void AssistTools::GenerateEngineImpl::Generate(const String& inputFileName, const String& outputFileName) const
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

void AssistTools::GenerateEngineImpl::Generate(const String& inputFileName, const String& outputFileName, const ReplaceType& replace) const
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

void AssistTools::GenerateEngineImpl::Generate(const String& inputFileName, const String& outputFileName, bool isClient) const
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

void AssistTools::GenerateEngineImpl::GenerateUtf8(const String& inputFileName, const String& outputFileName) const
{
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Utf8,
                                               inputFileName,
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    CoreTools::OFStreamManager streamManager{ outputFileName, false };

    streamManager << content;
}

void AssistTools::GenerateEngineImpl::GenerateUtf8(const String& inputFileName, const String& outputFileName, const ReplaceType& replace) const
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
