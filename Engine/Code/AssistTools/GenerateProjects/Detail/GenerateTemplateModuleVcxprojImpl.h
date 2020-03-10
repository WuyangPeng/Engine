// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:27)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateModuleVcxprojImpl : public GenerateTemplateImpl
	{
	public:
		typedef GenerateTemplateModuleVcxprojImpl ClassType;
		typedef GenerateTemplateImpl ParentType;

	public:
		GenerateTemplateModuleVcxprojImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& moduleName, const System::String& includeName);

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newModuleName, const System::String& newIncludeName) const;

	private:
		static const System::String sm_Extension;

		System::String m_SolutionName;
		System::String m_ModuleName;
		System::String m_IncludeName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_IMPL_H
