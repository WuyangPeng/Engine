// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:23)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HEADER_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HEADER_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateBaseImpl.h" 

namespace AssistTools
{ 
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateHeaderImpl : public GenerateTemplateBaseImpl
	{
	public:
		using ClassType = GenerateTemplateHeaderImpl ;
		using ParentType = GenerateTemplateBaseImpl ;

	public:
		GenerateTemplateHeaderImpl(const System::String& templateFileName,const Replace& replace);
		virtual ~GenerateTemplateHeaderImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, 
			            const CopyrightData& copyrightData, const System::String& projectCapital) const;

	private:
		static const System::String sm_Extension;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HEADER_IMPL_H
