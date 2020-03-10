// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:23)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateBaseImpl.h" 

namespace AssistTools
{ 
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateEngineImpl : public GenerateTemplateBaseImpl
	{
	public:
		using ClassType = GenerateTemplateEngineImpl ;
		using ParentType = GenerateTemplateBaseImpl ;

	public:
		GenerateTemplateEngineImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace);
		virtual ~GenerateTemplateEngineImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, 
			            const System::String& solutionName, const System::String& managerName,const System::String& interfaceName,
						const System::String& projectCapital,const System::String& managerCapital) const;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_IMPL_H
