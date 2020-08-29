// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:21)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_BASE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_BASE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"
#include "AssistTools/GenerateProjects/Flags/GenerateTemplateReplaceFlags.h"

#include <map>

namespace AssistTools
{
	class CopyrightData;

	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateBaseImpl : public GenerateTemplateImpl
	{
	public:
		using ClassType = GenerateTemplateBaseImpl ;
		using ParentType = GenerateTemplateImpl ;
		using Replace = std::map<GenerateTemplateReplace, System::String> ;

	public:
		GenerateTemplateBaseImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace);
		

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	protected:
		const System::String GetOriginal(GenerateTemplateReplace flag) const;

		const VariableType GetCopyrightVariable(const CopyrightData& copyrightData) const;

	private:	
		typedef Replace::const_iterator ReplaceConstIter;

	private:
		static const System::String sm_DefaultEndYear;
		static const System::String sm_DefaultProjectChineseName;
		static const System::String sm_DefaultManagerChineseName;
		static const System::String sm_DefaultVersions;
		static const System::String sm_DefaultDate;
		static const System::String sm_DefaultHour;
		static const System::String sm_DefaultMinute;
		static const System::String sm_DefaultProjectCapital;
		static const System::String sm_DefaultManagerCapital;
		static const System::String sm_DefaultSolutionName;
		static const System::String sm_DefaultProjectName;		
		static const System::String sm_DefaultManagerName;		
		static const System::String sm_DefaultInterfaceName;

		Replace m_Replace;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_BASE_IMPL_H
