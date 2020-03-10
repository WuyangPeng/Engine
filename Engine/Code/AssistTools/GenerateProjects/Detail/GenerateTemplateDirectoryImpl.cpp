// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:33)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "System/Helper/UnicodeUsing.h" 

using std::string;

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_ForwardSlash(SYSTEM_TEXT("/"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_EngineDirectory(SYSTEM_TEXT("Engine"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_ProjectName(SYSTEM_TEXT("ProjectName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_CoreName(SYSTEM_TEXT("ToolsName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_ModuleName(SYSTEM_TEXT("ModuleName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_ExeProjectName(SYSTEM_TEXT("ExeProjectName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_IncludeName(SYSTEM_TEXT("IncludeName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_DllProjectName(SYSTEM_TEXT("DllProjectName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_LogFileName(SYSTEM_TEXT("Log"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_ConfigurationDirectory(SYSTEM_TEXT("Configuration"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_ManagerName(SYSTEM_TEXT("ManagerName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_Resource(SYSTEM_TEXT("Resource"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_Update(SYSTEM_TEXT("Update.txt"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_CodeDirectory(SYSTEM_TEXT("Code"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_Testing(SYSTEM_TEXT("Testing"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_DebugLibName(SYSTEM_TEXT("DebugLibName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_ReleaseLibName(SYSTEM_TEXT("ReleaseLibName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_NewProjectName(SYSTEM_TEXT("NewProjectName"));

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::sm_GameIncludeName(SYSTEM_TEXT("GameIncludeName"));
 
AssistTools::GenerateTemplateDirectoryImpl
	::GenerateTemplateDirectoryImpl(const System::String& directory, const string& configurationFileName)	 
	:m_Directory(directory), m_StringReplacing(configurationFileName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
} 

AssistTools::GenerateTemplateDirectoryImpl
	::~GenerateTemplateDirectoryImpl()
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}
 
CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateDirectoryImpl)

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetDirectory() const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Directory;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetForwardSlash()
{
	return sm_ForwardSlash;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetEngineDirectory()
{
	return sm_EngineDirectory;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetProjectName()
{
	return sm_ProjectName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetCoreName()
{
	return sm_CoreName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetModuleName()
{
	return sm_ModuleName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetExeProjectName()
{
	return sm_ExeProjectName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetDllProjectName()
{
	return sm_DllProjectName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetIncludeName()
{
	return sm_IncludeName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetLogFileName()
{
	return sm_LogFileName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetConfigurationDirectory()
{
	return sm_ConfigurationDirectory;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetManagerName()
{
	return sm_ManagerName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetResource()
{
	return sm_Resource;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl	
	::GetUpdate()
{
	return sm_Update;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetCodeDirectory()
{
	return sm_CodeDirectory;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetReplacing(const System::String& original) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_StringReplacing.GetReplacing(original);
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetTesting()
{
	return sm_Testing;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetDebugLibName()
{
	return sm_DebugLibName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetReleaseLibName()
{
	return sm_ReleaseLibName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetTestingIncludeName()
{
	return sm_Testing + sm_IncludeName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetNewProjectName()
{
	return sm_NewProjectName;
}

const System::String AssistTools::GenerateTemplateDirectoryImpl
	::GetGameIncludeName()
{
	return sm_GameIncludeName;
}


