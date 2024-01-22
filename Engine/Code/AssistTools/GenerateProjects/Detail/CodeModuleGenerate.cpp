/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:00)

#include "AssistTools/AssistToolsExport.h"

#include "CodeModuleGenerate.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"
#include "AssistTools/GenerateProjects/Replace.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

AssistTools::CodeModuleGenerate::CodeModuleGenerate(const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, GenerateDirectory generateDirectory) noexcept
    : ParentType{ gameParameterAnalysis, codeMappingAnalysis },
      generateDirectory{ std::move(generateDirectory) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, CodeModuleGenerate)

void AssistTools::CodeModuleGenerate::GenerateModule(const GameModule& gameModule)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto directory = generateDirectory.GetGenerateDirectory(moduleDescribe, moduleName);
    directory.CreateFileDirectory();

    const ReplaceContainer replace{ Replace{ moduleNameDescribe, moduleName },
                                    Replace{ moduleUppercaseDescribe, gameModule.GetUppercaseName() } };

    GenerateCodeModuleCore(gameModule, replace, directory);
    GenerateCodeModuleMiddleLayer(gameModule, replace, directory);
    GenerateCodeModuleExe(gameModule, replace, directory);
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleCore(const GameModule& gameModule, const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    const auto moduleName = gameModule.GetModuleName();

    const auto nextDirectory = directory.GetGenerateDirectory(coreDescribe, moduleName + coreDescribe.data());
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("DllLibCpp")), SYSTEM_TEXT("DllLib.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("DllLibH")), SYSTEM_TEXT("DllLib.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("DllMainCpp")), SYSTEM_TEXT("DllMain.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreDllH")), moduleName + SYSTEM_TEXT("CoreDll.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreExportH")), moduleName + SYSTEM_TEXT("CoreExport.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreFwdH")), moduleName + SYSTEM_TEXT("CoreFwd.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreH")), moduleName + SYSTEM_TEXT("Core.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreImportH")), moduleName + SYSTEM_TEXT("CoreImport.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreLibH")), moduleName + SYSTEM_TEXT("CoreLib.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreNoImportH")), moduleName + SYSTEM_TEXT("CoreNoImport.h"), replace);
    GenerateCodeModuleCoreEngine(replace, nextDirectory);
    GenerateCodeModuleCoreHelper(gameModule, replace, nextDirectory);
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleCoreEngine(const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    const auto nextDirectory = directory.GetGenerateDirectory(engineDescribe);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("EngineFwdH")), SYSTEM_TEXT("EngineFwd.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("EngineH")), SYSTEM_TEXT("Engine.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("PlaceholderH")), SYSTEM_TEXT("Placeholder.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("PlaceholderCpp")), SYSTEM_TEXT("Placeholder.cpp"), replace);
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleCoreHelper(const GameModule& gameModule, const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    const auto moduleName = gameModule.GetModuleName();

    const auto nextDirectory = directory.GetGenerateDirectory(helperDescribe);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ExportMacroH")), SYSTEM_TEXT("ExportMacro.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("HelperFwdH")), SYSTEM_TEXT("HelperFwd.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("HelperH")), SYSTEM_TEXT("Helper.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreClassInvariantMacroH")), moduleName + SYSTEM_TEXT("CoreClassInvariantMacro.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleCoreCustomAssertMacroH")), moduleName + SYSTEM_TEXT("CoreCustomAssertMacro.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("UserMacroH")), SYSTEM_TEXT("UserMacro.h"), replace);
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleMiddleLayer(const GameModule& gameModule, const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(middleLayerDescribe, moduleName + middleLayerDescribe.data());
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("DllLibCpp")), SYSTEM_TEXT("DllLib.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("DllLibH")), SYSTEM_TEXT("DllLib.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("DllMainCpp")), SYSTEM_TEXT("DllMain.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerDllH")), moduleName + SYSTEM_TEXT("MiddleLayerDll.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerExportH")), moduleName + SYSTEM_TEXT("MiddleLayerExport.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerFwdH")), moduleName + SYSTEM_TEXT("MiddleLayerFwd.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerH")), moduleName + SYSTEM_TEXT("MiddleLayer.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerImportH")), moduleName + SYSTEM_TEXT("MiddleLayerImport.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerLibH")), moduleName + SYSTEM_TEXT("MiddleLayerLib.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerNoImportH")), moduleName + SYSTEM_TEXT("MiddleLayerNoImport.h"), replace);

    GenerateCodeModuleMiddleLayerHelper(gameModule, replace, nextDirectory);
    GenerateCodeModuleMiddleLayerManager(gameModule, replace, nextDirectory);
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleMiddleLayerManager(const GameModule& gameModule, const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    for (auto iter = GetMiddleLayerBegin(); iter != GetMiddleLayerEnd(); ++iter)
    {
        if (iter->GetMiddleLayerName() != inputDescribe)
        {
            GenerateCodeModuleMiddleLayerManager(gameModule, *iter, directory);
        }
        else
        {
            GenerateCodeModuleMiddleLayerInput(replace, directory);
        }
    }
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleMiddleLayerHelper(const GameModule& gameModule, const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(helperDescribe);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ExportMacroH")), SYSTEM_TEXT("ExportMacro.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("HelperFwdH")), SYSTEM_TEXT("HelperFwd.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("HelperH")), SYSTEM_TEXT("Helper.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("UserMacroH")), SYSTEM_TEXT("UserMacro.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerClassInvariantMacroH")), moduleName + SYSTEM_TEXT("MiddleLayerClassInvariantMacro.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMiddleLayerCustomAssertMacroH")), moduleName + SYSTEM_TEXT("MiddleLayerCustomAssertMacro.h"), replace);
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleMiddleLayerInput(const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    const auto nextDirectory = directory.GetGenerateDirectory(inputDescribe);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("InputFwdH")), SYSTEM_TEXT("InputFwd.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("InputH")), SYSTEM_TEXT("Input.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("InputManagerDetailH")), SYSTEM_TEXT("InputManagerDetail.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("InputManagerH")), SYSTEM_TEXT("InputManager.h"), replace);
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleMiddleLayerManager(const GameModule& gameModule, const MiddleLayerModule& middleLayerModule, const GenerateDirectory& directory)
{
    const auto middleLayerName = middleLayerModule.GetMiddleLayerName();
    const auto nextDirectory = directory.GetGenerateDirectory(middleLayerDescribe, middleLayerName);
    nextDirectory.CreateFileDirectory();

    const ReplaceContainer replace{ { moduleNameDescribe.data(), gameModule.GetModuleName() },
                                    { middleLayerNameDescribe.data(), middleLayerName },
                                    { moduleUppercaseDescribe.data(), gameModule.GetUppercaseName() },
                                    { middleLayerUppercaseDescribe.data(), middleLayerModule.GetUppercaseName() },
                                    { isManagerDescribe.data(), middleLayerModule.IsManager() ? managerDescribe.data() : SYSTEM_TEXT("") } };

    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("MiddleLayerFwdH")), middleLayerName + SYSTEM_TEXT("Fwd.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("MiddleLayerH")), middleLayerName + SYSTEM_TEXT(".h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("MiddleLayerManagerCpp")), middleLayerName + SYSTEM_TEXT("Manager.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("MiddleLayerManagerH")), middleLayerName + SYSTEM_TEXT("Manager.h"), replace);
}

void AssistTools::CodeModuleGenerate::GenerateCodeModuleExe(const GameModule& gameModule, const ReplaceContainer& replace, const GenerateDirectory& directory)
{
    const auto moduleName = gameModule.GetModuleName();
    const auto nextDirectory = directory.GetGenerateDirectory(moduleDescribe, moduleName);
    nextDirectory.CreateFileDirectory();

    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleH")), moduleName + SYSTEM_TEXT(".h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleHelperCpp")), moduleName + SYSTEM_TEXT("Helper.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleHelperH")), moduleName + SYSTEM_TEXT("Helper.h"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleLibCpp")), moduleName + SYSTEM_TEXT("Lib.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMainCpp")), moduleName + SYSTEM_TEXT("Main.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMessageCpp")), moduleName + SYSTEM_TEXT("Message.cpp"), replace);
    GenerateFile::GenerateByContent(nextDirectory, GetOnlyContent(nextDirectory.GetInputDirectory(), SYSTEM_TEXT("ModuleMessageH")), moduleName + SYSTEM_TEXT("Message.h"), replace);
}
