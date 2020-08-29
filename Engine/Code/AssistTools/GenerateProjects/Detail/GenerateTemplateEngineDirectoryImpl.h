// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:22)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_DIRECTORY_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_DIRECTORY_IMPL_H

#include "AssistTools/AssistToolsDll.h" 

#include "GenerateTemplateDirectoryImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateEngineDirectoryImpl : public GenerateTemplateDirectoryImpl
	{
	public:
		using ClassType = GenerateTemplateEngineDirectoryImpl ;
		using ParentType = GenerateTemplateDirectoryImpl ;

	public:
		GenerateTemplateEngineDirectoryImpl(const System::String& directory, const std::string& configurationFileName);
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, 
			            const System::String& newCoreName, const System::String& newIncludeName) const;

	private:
		void GenerateToSolution(const System::String& resourceDirectory, const System::String& newSolutionName, 
			                    const System::String& newCoreName) const;
		void GenerateToVcxproj(const System::String& resourceDirectory, const System::String& newSolutionName, 
			                   const System::String& newIncludeName) const;
		void GenerateToVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName) const;
		void GenerateToModuleVcxproj(const System::String& resourceDirectory, const System::String& newSolutionName, 
			                         const System::String& newCoreName, const System::String& newIncludeName) const;
		void GenerateToModuleVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName,
			                                const System::String& newCoreName) const;
		void GenerateToLogJson(const System::String& resourceDirectory, const System::String& newSolutionName) const;
		void GenerateToMiddleLayer(const System::String& resourceDirectory, const System::String& newSolutionName, 
			                       const System::String& newIncludeName, const System::String& newManager) const;
		void GenerateToMiddleLayerVcxproj(const System::String& resourceDirectory, const System::String& newSolutionName,
			                              const System::String& newManager, const System::String& newIncludeName) const;
		void GenerateToMiddleLayerVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName,
			                                     const System::String& newManager) const;
		void GenerateToUpdate(const System::String& resourceDirectory, const System::String& newManager,
			                  const System::String& newSolutionName) const;
		void GenerateToEnvironmentVariable(const System::String& resourceDirectory, const System::String& newSolutionName) const;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_DIRECTORY_IMPL_H
