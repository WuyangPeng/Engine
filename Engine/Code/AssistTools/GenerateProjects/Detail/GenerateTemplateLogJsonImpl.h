// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:24)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_RESOURCE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_RESOURCE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateLogJsonImpl : public GenerateTemplateImpl
	{
	public:
		using ClassType = GenerateTemplateLogJsonImpl ;
		using ParentType = GenerateTemplateImpl ;

	public:
		GenerateTemplateLogJsonImpl(const System::String& templateFileName, const System::String& projectName);

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newFileName) const;

	private:
		static const System::String sm_Extension;

		System::String m_ProjectName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_RESOURCE_IMPL_H
