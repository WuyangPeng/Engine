// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:27)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_SOLUTION_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_SOLUTION_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateSolutionImpl : public GenerateTemplateImpl
	{
	public:
		typedef GenerateTemplateSolutionImpl ClassType;
		typedef GenerateTemplateImpl ParentType;

	public:
		GenerateTemplateSolutionImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& coreName);
		virtual ~GenerateTemplateSolutionImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const;

	private: 
		static const System::String sm_Extension;

		System::String m_SolutionName;
		System::String m_CoreName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_SOLUTION_IMPL_H
