///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/28 18:54)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateCodeDirectoryImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateDllLib.h"
#include "AssistTools/GenerateProjects/GenerateTemplateDllMain.h"
#include "AssistTools/GenerateProjects/GenerateTemplateEngine.h"
#include "AssistTools/GenerateProjects/GenerateTemplateHeader.h"
#include "AssistTools/GenerateProjects/GenerateTemplateHelper.h"
#include "AssistTools/GenerateProjects/GenerateTemplateLib.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMain.h"
#include "AssistTools/GenerateProjects/GenerateTemplateManager.h"
#include "AssistTools/GenerateProjects/GenerateTemplateManagerLib.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMessage.h"

using std::string;
using namespace std::literals;

AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateTemplateCodeDirectoryImpl(const System::String& directory, const string& configurationFileName)
    : ParentType{ directory, configurationFileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateCodeDirectoryImpl)

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& aProjectName, const System::String& newCoreName, const System::String& CoreNameCapital) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    GenerateToHeader(exportDirectory, newSolutionName, copyrightData, projectCapital);
    GenerateToHelper(exportDirectory, newSolutionName, copyrightData, projectCapital);
    GenerateToMessage(exportDirectory, newSolutionName, copyrightData, projectCapital);
    GenerateToLib(exportDirectory, newSolutionName, copyrightData);
    GenerateToMain(exportDirectory, newSolutionName, copyrightData, aProjectName);

    GenerateToManager(exportDirectory, newSolutionName, copyrightData, newCoreName, projectCapital, CoreNameCapital);
    GenerateToCoreEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Core"s), projectCapital, SYSTEM_TEXT("CORE"s));

    GenerateToManagerMiddleLayer(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("MiddleLayer"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER"s));

    GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, projectCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToHeader(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateH.txt"s) };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName };

    GenerateTemplateHeader generateTemplateHeader{ fileName, replace };
    generateTemplateHeader.GenerateTo(fullDirectory, newSolutionName, copyrightData, projectCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToHelper(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
    GenerateToHelperHeader(exportDirectory, newSolutionName, copyrightData, projectCapital);
    GenerateToHelperSource(exportDirectory, newSolutionName, copyrightData, projectCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToHelperHeader(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateHelperH.txt"s) };
    const System::String newProjectName{ newSolutionName + SYSTEM_TEXT("Helper"s) };
    const System::String extension{ SYSTEM_TEXT(".h") };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName };

    GenerateTemplateHelper generateTemplateHelper{ fileName, extension, replace };
    generateTemplateHelper.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToHelperSource(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateHelperCpp.txt"s) };
    const System::String extension{ SYSTEM_TEXT(".cpp"s) };
    const System::String newProjectName{ newSolutionName + SYSTEM_TEXT("Helper"s) };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName };

    GenerateTemplateHelper generateTemplateHelper{ fileName, extension, replace };
    generateTemplateHelper.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToMessage(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
    GenerateToMessageHeader(exportDirectory, newSolutionName, copyrightData, projectCapital);
    GenerateToMessageSource(exportDirectory, newSolutionName, copyrightData, projectCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToMessageHeader(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
    GenerateTemplateHeader::Replace replace{};
    const auto fileName = GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMessageH.txt"s);
    const auto newProjectName = newSolutionName + SYSTEM_TEXT("Message"s);
    const auto extension = SYSTEM_TEXT(".h"s);
    const auto fullDirectory = exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName;

    GenerateTemplateMessage generateTemplateHelper{ fileName, extension, replace };
    generateTemplateHelper.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToMessageSource(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMessageCpp.txt"s) };
    const System::String newProjectName{ newSolutionName + SYSTEM_TEXT("Message"s) };
    const System::String extension{ SYSTEM_TEXT(".cpp"s) };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName };

    GenerateTemplateMessage generateTemplateHelper{ fileName, extension, replace };
    generateTemplateHelper.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToLib(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateLibCpp.txt"s) };
    const System::String newProjectName{ newSolutionName + SYSTEM_TEXT("Lib"s) };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName };

    GenerateTemplateLib generateTemplateLib{ fileName, replace };
    generateTemplateLib.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToMain(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aProjectName) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMainCpp.txt"s) };
    const System::String newProjectName{ newSolutionName + SYSTEM_TEXT("Main"s) };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName };

    GenerateTemplateMain generateTemplateLib{ fileName, replace };
    generateTemplateLib.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, aProjectName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerDllH.txt"s), SYSTEM_TEXT("Dll"s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerExportH.txt"s), SYSTEM_TEXT("Export"s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerFwdH.txt"s), SYSTEM_TEXT("Fwd"s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerH.txt"s), SYSTEM_TEXT(""s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerImportH.txt"s), SYSTEM_TEXT("Import"s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerNoImportH.txt"s), SYSTEM_TEXT("NoImport"s), projectCapital, managerCapitalName);
    GenerateToManagerLib(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapitalName);
    GenerateToManagerDllMain(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapitalName);
    GenerateToManagerDllLib(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateExportMacroH.txt"s), SYSTEM_TEXT("ExportMacro"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerClassInvariantMacroH.txt"s), newSolutionName + aManagerName + SYSTEM_TEXT("ClassInvariantMacro"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerCustomAssertMacroH.txt"s), newSolutionName + aManagerName + SYSTEM_TEXT("CustomAssertMacro"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateMacroH.txt"s), SYSTEM_TEXT("Macro"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateMacroFwdH.txt"s), SYSTEM_TEXT("MacroFwd"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateUserMacroH.txt"s), SYSTEM_TEXT("UserMacro"s), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerMiddleLayer(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerDllH.txt"s), SYSTEM_TEXT("Dll"s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerExportH.txt"s), SYSTEM_TEXT("Export"s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerMiddleLayerFwdH.txt"s), SYSTEM_TEXT("Fwd"s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerMiddleLayerH.txt"s), SYSTEM_TEXT(""s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerImportH.txt"s), SYSTEM_TEXT("Import"s), projectCapital, managerCapitalName);
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerNoImportH.txt"s), SYSTEM_TEXT("NoImport"s), projectCapital, managerCapitalName);
    GenerateToManagerLib(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapitalName);
    GenerateToManagerDllMain(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapitalName);
    GenerateToManagerDllLibMiddleLayer(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateExportMacroH.txt"s), SYSTEM_TEXT("ExportMacro"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerClassInvariantMacroH.txt"s), newSolutionName + aManagerName + SYSTEM_TEXT("ClassInvariantMacro"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateManagerCustomAssertMacroH.txt"s), newSolutionName + aManagerName + SYSTEM_TEXT("CustomAssertMacro"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateMacroH.txt"s), SYSTEM_TEXT("Macro"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateMacroFwdH.txt"s), SYSTEM_TEXT("MacroFwd"s), projectCapital, managerCapitalName);
    GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, aManagerName, SYSTEM_TEXT("GameTemplateUserMacroH.txt"s), SYSTEM_TEXT("UserMacro"s), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& testFileName, const System::String& resultSuffix, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + testFileName };
    const System::String newProjectName{ newSolutionName + aManagerName + resultSuffix };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + aManagerName };

    GenerateTemplateManager generateTemplateManager{ fileName, replace };
    generateTemplateManager.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerLib(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateManagerLibH.txt"s) };
    const System::String newProjectName{ newSolutionName + aManagerName + SYSTEM_TEXT("Lib"s) };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + aManagerName };

    GenerateTemplateManagerLib generateTemplateManagerLib{ fileName, replace };
    generateTemplateManagerLib.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, managerCapitalName, newSolutionName, aManagerName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerDllMain(const System::String& exportDirectory,
                                                                              const System::String& newSolutionName,
                                                                              const CopyrightData& copyrightData,
                                                                              const System::String& aManagerName,
                                                                              const System::String& projectCapital,
                                                                              const System::String& managerCapital) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateDllMainCpp.txt"s) };
    const System::String newProjectName{ SYSTEM_TEXT("DllMain"s) };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + aManagerName };

    GenerateTemplateDllMain generateTemplateDllMain{ fileName, replace };
    generateTemplateDllMain.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, aManagerName, projectCapital, managerCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerDllLib(const System::String& exportDirectory,
                                                                             const System::String& newSolutionName,
                                                                             const CopyrightData& copyrightData,
                                                                             const System::String& aManagerName,
                                                                             const System::String& projectCapital,
                                                                             const System::String& managerCapital) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateDllLibCpp.txt"s) };
    const System::String newProjectName{ SYSTEM_TEXT("DllLib") };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + aManagerName };

    auto managerChineseName = GetReplacing(aManagerName + SYSTEM_TEXT("ChineseName"s));

    GenerateTemplateDllLib generateTemplateDllLib{ fileName, replace };
    generateTemplateDllLib.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, aManagerName, managerChineseName, projectCapital, managerCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerDllLibMiddleLayer(const System::String& exportDirectory,
                                                                                        const System::String& newSolutionName,
                                                                                        const CopyrightData& copyrightData,
                                                                                        const System::String& aManagerName,
                                                                                        const System::String& projectCapital,
                                                                                        const System::String& managerCapitalName) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateDllLibMiddleLayerCpp.txt"s) };
    const System::String newProjectName{ SYSTEM_TEXT("DllLib") };
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + aManagerName };

    auto managerChineseName = GetReplacing(aManagerName + SYSTEM_TEXT("ChineseName"s));

    GenerateTemplateDllLib generateTemplateDllLib{ fileName, replace };
    generateTemplateDllLib.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, aManagerName, managerChineseName, projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerMacro(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& testFileName, const System::String& resultSuffix, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + testFileName };
    const auto& newProjectName = resultSuffix;
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + aManagerName + GetForwardSlash() + SYSTEM_TEXT("Macro"s) };

    GenerateTemplateMacro generateTemplateMacro{ fileName, replace };
    generateTemplateMacro.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, aManagerName, projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
    GenerateToInputManagerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Input"s), SYSTEM_TEXT("InputInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_INPUT"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Network"s), SYSTEM_TEXT("NetworkManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_NETWORK"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("ObjectLogic"s), SYSTEM_TEXT("ObjectLogicInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_OBJECT_LOGIC"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("ArtificialIntellegence"s), SYSTEM_TEXT("ArtificialIntellegenceInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_ARTIFICIAL_INTELLIGENCE"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("PhysicalModelling"s), SYSTEM_TEXT("PhysicalModellingManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_PHYSICAL_MODELLING"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Message"s), SYSTEM_TEXT("MessageManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_MESSAGE"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Event"s), SYSTEM_TEXT("EventManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_EVENT"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("System"s), SYSTEM_TEXT("SystemManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_SYSTEM"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Resource"s), SYSTEM_TEXT("ResourceManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_RESOURCE"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Audio"s), SYSTEM_TEXT("AudioManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_AUDIO"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("CameraSystems"s), SYSTEM_TEXT("CameraSystemsManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_CAMERA_SYSTEMS"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Rendering"s), SYSTEM_TEXT("RenderingManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_RENDERING"s));
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("GUI"s), SYSTEM_TEXT("GUIManagerInterface"s), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_GUI"s));
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToMiddleLayerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& managerInterfaceName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateEngineH.txt"s), aManagerName, SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateEngineFwdH.txt"s), aManagerName + SYSTEM_TEXT("Fwd"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateOtherManagerH.txt"s), aManagerName + SYSTEM_TEXT("Manager"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateOtherManagerCpp.txt"s), aManagerName + SYSTEM_TEXT("Manager"s), SYSTEM_TEXT(".cpp"s), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& managerInterfaceName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateEngineH.txt"s), SYSTEM_TEXT("Engine"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateEngineFwdH.txt"s), SYSTEM_TEXT("EngineFwd"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateOtherManagerH.txt"s), aManagerName, SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateOtherManagerCpp.txt"s), aManagerName, SYSTEM_TEXT(".cpp"s), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToInputManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& managerInterfaceName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateInputManagerEngineH.txt"s), SYSTEM_TEXT("Input"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateInputManagerEngineFwdH.txt"s), SYSTEM_TEXT("InputFwd"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateInputManagerH.txt"s), aManagerName + SYSTEM_TEXT("Manager"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateInputManagerDetailH.txt"s), aManagerName + SYSTEM_TEXT("Manager"s) + SYSTEM_TEXT("Detail"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToCoreEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateToCoreEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, aManagerName, SYSTEM_TEXT("GameTemplateEngineH.txt"s), SYSTEM_TEXT("Engine"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToCoreEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, aManagerName, SYSTEM_TEXT("GameTemplateEngineFwdH.txt"s), SYSTEM_TEXT("EngineFwd"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, aManagerName, SYSTEM_TEXT("GameTemplatePlaceholderH.txt"s), SYSTEM_TEXT("Placeholder"s), SYSTEM_TEXT(".h"s), projectCapital, managerCapitalName);
    GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, aManagerName, aManagerName, SYSTEM_TEXT("GameTemplatePlaceholderCpp.txt"s), SYSTEM_TEXT("Placeholder"s), SYSTEM_TEXT(".cpp"s), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToCoreEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& managerInterfaceName, const System::String& testFileName, const System::String& resultSuffix, const System::String& extension, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + testFileName };
    const auto& newProjectName = resultSuffix;
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + aManagerName + GetForwardSlash() + SYSTEM_TEXT("Engine"s) };

    GenerateTemplateEngine generateTemplateEngine{ fileName, extension, replace };
    generateTemplateEngine.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, SYSTEM_TEXT("Placeholder"), managerInterfaceName, projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& managerInterfaceName, const System::String& testFileName, const System::String& resultSuffix, const System::String& extension, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + testFileName };
    const auto& newProjectName = resultSuffix;
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + aManagerName + GetForwardSlash() + SYSTEM_TEXT("Engine"s) };

    GenerateTemplateEngine generateTemplateEngine{ fileName, extension, replace };
    generateTemplateEngine.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, aManagerName, managerInterfaceName, projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl::GenerateToMiddleLayerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& managerInterfaceName, const System::String& testFileName, const System::String& resultSuffix, const System::String& extension, const System::String& projectCapital, const System::String& managerCapitalName) const
{
    GenerateTemplateHeader::Replace replace{};
    const System::String fileName{ GetDirectory() + GetForwardSlash() + testFileName };
    const auto& newProjectName = resultSuffix;
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + SYSTEM_TEXT("MiddleLayer"s) + GetForwardSlash() + aManagerName };

    GenerateTemplateEngine generateTemplateEngine{ fileName, extension, replace };
    generateTemplateEngine.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, aManagerName + SYSTEM_TEXT("Manager"), managerInterfaceName, projectCapital, managerCapitalName);
}
