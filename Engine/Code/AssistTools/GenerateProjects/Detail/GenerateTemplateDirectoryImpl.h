// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:21)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DIRECTORY_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DIRECTORY_IMPL_H

#include "AssistTools/AssistToolsDll.h" 

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/EngineConfiguration/StringReplacing.h"

#include <string>

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateDirectoryImpl
	{
	public:
		using ClassType = GenerateTemplateDirectoryImpl ;

	public:
		GenerateTemplateDirectoryImpl(const System::String& directory, const std::string& configurationFileName);
		virtual ~GenerateTemplateDirectoryImpl() = default;
		GenerateTemplateDirectoryImpl(const GenerateTemplateDirectoryImpl& rhs) = default;
		GenerateTemplateDirectoryImpl& operator=(const GenerateTemplateDirectoryImpl& rhs) = default;
		GenerateTemplateDirectoryImpl(GenerateTemplateDirectoryImpl&& rhs) noexcept = default;
		GenerateTemplateDirectoryImpl& operator=(GenerateTemplateDirectoryImpl && rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;	

	protected:
		const System::String GetDirectory() const;
		static const System::String GetForwardSlash();
		static const System::String GetEngineDirectory();
		static const System::String GetProjectName();
		static const System::String GetCoreName();
		static const System::String GetModuleName();
		static const System::String GetExeProjectName();
		static const System::String GetDllProjectName();
		static const System::String GetIncludeName();
		static const System::String GetLogFileName();
		static const System::String GetConfigurationDirectory();
		static const System::String GetManagerName();
		static const System::String GetResource();
		static const System::String GetUpdate();
		static const System::String GetCodeDirectory();
		static const System::String GetTesting();
		static const System::String GetDebugLibName();
		static const System::String GetReleaseLibName();
		static const System::String GetTestingIncludeName();
		static const System::String GetNewProjectName();
		static const System::String GetGameIncludeName();

		const System::String GetReplacing(const System::String& original) const;

	private: 
		System::String m_Directory;
		CoreTools::StringReplacing m_StringReplacing;

		static const System::String sm_ForwardSlash;
		static const System::String sm_EngineDirectory;
		static const System::String sm_CodeDirectory;
		static const System::String sm_ProjectName;
		static const System::String sm_CoreName;
		static const System::String sm_ModuleName;
		static const System::String sm_ExeProjectName;
		static const System::String sm_DllProjectName;
		static const System::String sm_IncludeName;
		static const System::String sm_LogFileName;
		static const System::String sm_ConfigurationDirectory;
		static const System::String sm_ManagerName;
		static const System::String sm_Resource;
		static const System::String sm_Update;
		static const System::String sm_Testing;
		static const System::String sm_DebugLibName;
		static const System::String sm_ReleaseLibName;
		static const System::String sm_NewProjectName;
		static const System::String sm_GameIncludeName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DIRECTORY_IMPL_H
