// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:33)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateCodeDirectoryImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateHeader.h"
#include "AssistTools/GenerateProjects/GenerateTemplateHelper.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMessage.h"
#include "AssistTools/GenerateProjects/GenerateTemplateLib.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMain.h"
#include "AssistTools/GenerateProjects/GenerateTemplateManager.h"
#include "AssistTools/GenerateProjects/GenerateTemplateManagerLib.h"
#include "AssistTools/GenerateProjects/GenerateTemplateDllMain.h"
#include "AssistTools/GenerateProjects/GenerateTemplateDllLib.h"
#include "AssistTools/GenerateProjects/GenerateTemplateMacro.h"
#include "AssistTools/GenerateProjects/GenerateTemplateEngine.h" 

using  std::string;
 
AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateTemplateCodeDirectoryImpl(const System::String& directory, const string& configurationFileName)
	:ParentType(directory, configurationFileName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateCodeDirectoryImpl)

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital,const System::String& projectName, const System::String& newCoreName, const System::String& CoreNameCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

	GenerateToHeader(exportDirectory, newSolutionName, copyrightData, projectCapital);
	GenerateToHelper(exportDirectory, newSolutionName, copyrightData, projectCapital);
	GenerateToMessage(exportDirectory, newSolutionName, copyrightData, projectCapital);
	GenerateToLib(exportDirectory, newSolutionName, copyrightData);
	GenerateToMain(exportDirectory, newSolutionName, copyrightData, projectName); 

	GenerateToManager(exportDirectory, newSolutionName, copyrightData, newCoreName, projectCapital, CoreNameCapital);
	GenerateToCoreEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Core"), projectCapital, SYSTEM_TEXT("CORE"));

	GenerateToManagerMiddleLayer(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("MiddleLayer"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER"));
 
	GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, projectCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToHeader(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateH.txt"));	 
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName);

	GenerateTemplateHeader generateTemplateHeader(fileName, replace);
	generateTemplateHeader.GenerateTo(fullDirectory, newSolutionName, copyrightData, projectCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToHelper(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	GenerateToHelperHeader(exportDirectory, newSolutionName, copyrightData, projectCapital);
	GenerateToHelperSource(exportDirectory, newSolutionName, copyrightData, projectCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToHelperHeader(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateHelperH.txt"));
	const System::String newProjectName(newSolutionName + SYSTEM_TEXT("Helper"));
	const System::String extension(SYSTEM_TEXT(".h"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName);

	GenerateTemplateHelper generateTemplateHelper(fileName, extension, replace);
	generateTemplateHelper.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToHelperSource(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateHelperCpp.txt"));
	const System::String extension(SYSTEM_TEXT(".cpp"));
	const System::String newProjectName(newSolutionName + SYSTEM_TEXT("Helper"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName);

	GenerateTemplateHelper generateTemplateHelper(fileName, extension, replace);
	generateTemplateHelper.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToMessage(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	GenerateToMessageHeader(exportDirectory, newSolutionName, copyrightData, projectCapital);
	GenerateToMessageSource(exportDirectory, newSolutionName, copyrightData, projectCapital);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToMessageHeader(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMessageH.txt"));
	const System::String newProjectName(newSolutionName + SYSTEM_TEXT("Message"));
	const System::String extension(SYSTEM_TEXT(".h"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName);

	GenerateTemplateMessage generateTemplateHelper(fileName, extension, replace);
	generateTemplateHelper.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToMessageSource(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMessageCpp.txt"));
	const System::String newProjectName(newSolutionName + SYSTEM_TEXT("Message"));
	const System::String extension(SYSTEM_TEXT(".cpp"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName);

	GenerateTemplateMessage generateTemplateHelper(fileName, extension, replace);
	generateTemplateHelper.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToLib(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateLibCpp.txt"));
	const System::String newProjectName(newSolutionName + SYSTEM_TEXT("Lib"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName);

	GenerateTemplateLib generateTemplateLib(fileName,  replace);
	generateTemplateLib.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToMain(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData,const System::String& projectName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateMainCpp.txt"));
	const System::String newProjectName(newSolutionName + SYSTEM_TEXT("Main"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName);

	GenerateTemplateMain generateTemplateLib(fileName, replace);
	generateTemplateLib.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, projectName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerDllH.txt"), SYSTEM_TEXT("Dll"), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerExportH.txt"), SYSTEM_TEXT("Export"), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerFwdH.txt"), SYSTEM_TEXT("Fwd"), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerH.txt"), SYSTEM_TEXT(""), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerImportH.txt"), SYSTEM_TEXT("Import"), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerNoImportH.txt"), SYSTEM_TEXT("NoImport"), projectCapital, managerCapitalName);
	GenerateToManagerLib(exportDirectory, newSolutionName, copyrightData, managerName, projectCapital, managerCapitalName);
	GenerateToManagerDllMain(exportDirectory, newSolutionName, copyrightData, managerName);
	GenerateToManagerDllLib(exportDirectory, newSolutionName, copyrightData, managerName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateExportMacroH.txt"), SYSTEM_TEXT("ExportMacro"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerClassInvariantMacroH.txt"), newSolutionName + managerName + SYSTEM_TEXT("ClassInvariantMacro"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerCustomAssertMacroH.txt"), newSolutionName + managerName + SYSTEM_TEXT("CustomAssertMacro"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateMacroH.txt"), SYSTEM_TEXT("Macro"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateMacroFwdH.txt"), SYSTEM_TEXT("MacroFwd"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateUserMacroH.txt"), SYSTEM_TEXT("UserMacro"), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerMiddleLayer(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerDllH.txt"), SYSTEM_TEXT("Dll"), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerExportH.txt"), SYSTEM_TEXT("Export"), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerMiddleLayerFwdH.txt"), SYSTEM_TEXT("Fwd"), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerMiddleLayerH.txt"), SYSTEM_TEXT(""), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerImportH.txt"), SYSTEM_TEXT("Import"), projectCapital, managerCapitalName);
	GenerateToManager(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerNoImportH.txt"), SYSTEM_TEXT("NoImport"), projectCapital, managerCapitalName);
	GenerateToManagerLib(exportDirectory, newSolutionName, copyrightData, managerName, projectCapital, managerCapitalName);
	GenerateToManagerDllMain(exportDirectory, newSolutionName, copyrightData, managerName);
	GenerateToManagerDllLibMiddleLayer(exportDirectory, newSolutionName, copyrightData, managerName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateExportMacroH.txt"), SYSTEM_TEXT("ExportMacro"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerClassInvariantMacroH.txt"), newSolutionName + managerName + SYSTEM_TEXT("ClassInvariantMacro"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateManagerCustomAssertMacroH.txt"), newSolutionName + managerName + SYSTEM_TEXT("CustomAssertMacro"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateMacroH.txt"), SYSTEM_TEXT("Macro"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateMacroFwdH.txt"), SYSTEM_TEXT("MacroFwd"), projectCapital, managerCapitalName);
	GenerateToManagerMacro(exportDirectory, newSolutionName, copyrightData, managerName, SYSTEM_TEXT("GameTemplateUserMacroH.txt"), SYSTEM_TEXT("UserMacro"), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& testFileName, const System::String& resultSuffix, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + testFileName);
	const System::String newProjectName(newSolutionName + managerName + resultSuffix);
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + managerName);

	GenerateTemplateManager generateTemplateManager(fileName, replace);
	generateTemplateManager.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, managerCapitalName);	 
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerLib(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateManagerLibH.txt"));
	const System::String newProjectName(newSolutionName + managerName + SYSTEM_TEXT("Lib"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + managerName);

	GenerateTemplateManagerLib generateTemplateManagerLib(fileName, replace);
	generateTemplateManagerLib.GenerateTo(fullDirectory, newProjectName, copyrightData, projectCapital, managerCapitalName, newSolutionName, managerName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerDllMain(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateDllMainCpp.txt"));
	const System::String newProjectName(SYSTEM_TEXT("DllMain"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + managerName);

	GenerateTemplateDllMain generateTemplateDllMain(fileName, replace);
	generateTemplateDllMain.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, managerName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerDllLib(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateDllLibCpp.txt"));
	const System::String newProjectName(SYSTEM_TEXT("DllLib"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + managerName);

	System::String managerChineseName = GetReplacing(managerName + SYSTEM_TEXT("ChineseName"));

	GenerateTemplateDllLib generateTemplateDllLib(fileName, replace);
	generateTemplateDllLib.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, managerName, managerChineseName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerDllLibMiddleLayer(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + SYSTEM_TEXT("GameTemplateDllLibMiddleLayerCpp.txt"));
	const System::String newProjectName(SYSTEM_TEXT("DllLib"));
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + managerName);

	System::String managerChineseName = GetReplacing(managerName + SYSTEM_TEXT("ChineseName"));

	GenerateTemplateDllLib generateTemplateDllLib(fileName, replace);
	generateTemplateDllLib.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, managerName, managerChineseName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerMacro(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& testFileName, const System::String& resultSuffix, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + testFileName);
	const System::String newProjectName(resultSuffix);
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + managerName + GetForwardSlash() + SYSTEM_TEXT("Macro"));

	GenerateTemplateMacro generateTemplateMacro(fileName, replace);
	generateTemplateMacro.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, managerName, projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	GenerateToInputManagerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Input"), SYSTEM_TEXT("InputInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_INPUT"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Network"), SYSTEM_TEXT("NetworkManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_NETWORK"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("ObjectLogic"), SYSTEM_TEXT("ObjectLogicInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_OBJECT_LOGIC"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("ArtificialIntellegence"), SYSTEM_TEXT("ArtificialIntellegenceInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("PhysicalModelling"), SYSTEM_TEXT("PhysicalModellingManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_PHYSICAL_MODELLING"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Message"), SYSTEM_TEXT("MessageManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_MESSAGE"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Event"), SYSTEM_TEXT("EventManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_EVENT"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("System"), SYSTEM_TEXT("SystemManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_SYSTEM"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Resource"), SYSTEM_TEXT("ResourceManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_RESOURCE"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Audio"), SYSTEM_TEXT("AudioManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_AUDIO"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("CameraSystems"), SYSTEM_TEXT("CameraSystemsManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_CAMERA_SYSTEMS"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("Rendering"), SYSTEM_TEXT("RenderingManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_RENDERING"));
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("GUI"), SYSTEM_TEXT("GUIManagerInterface"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_GUI"));
}


void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToMiddleLayerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& managerInterfaceName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateEngineH.txt"), managerName, SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateEngineFwdH.txt"), managerName  + SYSTEM_TEXT("Fwd"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateOtherManagerH.txt"), managerName + SYSTEM_TEXT("Manager"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateOtherManagerCpp.txt"), managerName + SYSTEM_TEXT("Manager"), SYSTEM_TEXT(".cpp"), projectCapital, managerCapitalName);
}


void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& managerInterfaceName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateEngineH.txt"), SYSTEM_TEXT("Engine"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateEngineFwdH.txt"), SYSTEM_TEXT("EngineFwd"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateOtherManagerH.txt"), managerName, SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateOtherManagerCpp.txt"), managerName, SYSTEM_TEXT(".cpp"), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToInputManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& managerInterfaceName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateInputManagerEngineH.txt"), SYSTEM_TEXT("Input"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateInputManagerEngineFwdH.txt"), SYSTEM_TEXT("InputFwd"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateInputManagerH.txt"), managerName + SYSTEM_TEXT("Manager"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToMiddleLayerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerInterfaceName, SYSTEM_TEXT("GameTemplateInputManagerDetailH.txt"), managerName + SYSTEM_TEXT("Manager") + SYSTEM_TEXT("Detail"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName); 
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToCoreEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateToCoreEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerName, SYSTEM_TEXT("GameTemplateEngineH.txt"), SYSTEM_TEXT("Engine"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToCoreEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerName, SYSTEM_TEXT("GameTemplateEngineFwdH.txt"), SYSTEM_TEXT("EngineFwd"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerName, SYSTEM_TEXT("GameTemplatePlaceholderH.txt"), SYSTEM_TEXT("Placeholder"), SYSTEM_TEXT(".h"), projectCapital, managerCapitalName);
	GenerateToManagerEngine(exportDirectory, newSolutionName, copyrightData, managerName, managerName, SYSTEM_TEXT("GameTemplatePlaceholderCpp.txt"), SYSTEM_TEXT("Placeholder"), SYSTEM_TEXT(".cpp"), projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToCoreEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& managerInterfaceName, const System::String& testFileName, const System::String& resultSuffix, const System::String& extension, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + testFileName);
	const System::String newProjectName(resultSuffix);
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + managerName + GetForwardSlash() + SYSTEM_TEXT("Engine"));

	GenerateTemplateEngine generateTemplateEngine(fileName, extension, replace);
	generateTemplateEngine.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, SYSTEM_TEXT("Placeholder"), managerInterfaceName, projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& managerInterfaceName, const System::String& testFileName, const System::String& resultSuffix, const System::String& extension,  const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + testFileName);
	const System::String newProjectName(resultSuffix);
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + managerName + GetForwardSlash() + SYSTEM_TEXT("Engine"));

	GenerateTemplateEngine generateTemplateEngine(fileName, extension, replace);
	generateTemplateEngine.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, managerName, managerInterfaceName, projectCapital, managerCapitalName);
}

void AssistTools::GenerateTemplateCodeDirectoryImpl
	::GenerateToMiddleLayerEngine(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& managerName, const System::String& managerInterfaceName, const System::String& testFileName, const System::String& resultSuffix, const System::String& extension, const System::String& projectCapital, const System::String& managerCapitalName) const
{
	GenerateTemplateHeader::Replace replace;
	const System::String fileName(GetDirectory() + GetForwardSlash() + testFileName);
	const System::String newProjectName(resultSuffix);
	const System::String fullDirectory(exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetForwardSlash() + newSolutionName + SYSTEM_TEXT("MiddleLayer") + GetForwardSlash() + managerName);

	GenerateTemplateEngine generateTemplateEngine(fileName, extension, replace);
	generateTemplateEngine.GenerateTo(fullDirectory, newProjectName, copyrightData, newSolutionName, managerName + SYSTEM_TEXT("Manager"), managerInterfaceName, projectCapital, managerCapitalName);
}

