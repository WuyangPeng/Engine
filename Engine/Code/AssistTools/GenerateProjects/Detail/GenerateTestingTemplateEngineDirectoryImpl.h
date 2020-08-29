// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_IMPL_H

#include "AssistTools/AssistToolsDll.h" 

#include "GenerateTemplateDirectoryImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTestingTemplateEngineDirectoryImpl : public GenerateTemplateDirectoryImpl
	{
	public:
		typedef GenerateTestingTemplateEngineDirectoryImpl ClassType;
		typedef GenerateTemplateDirectoryImpl ParentType;

	public:
		GenerateTestingTemplateEngineDirectoryImpl(const System::String& directory, const std::string& configurationFileName);
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, 
			            const System::String& newIncludeName, const System::String& newTestingIncludeName,
						const System::String& newDebugLibName, const System::String& newReleaseLibName) const;
 
	private:
		void GenerateToSolution(const System::String& resourceDirectory, const System::String& newSolutionName,	const System::String& newCoreName) const;
		void GenerateToModule(const System::String& resourceDirectory, const System::String& newSolutionName, 
			                  const System::String& newIncludeName, const System::String& newTestingIncludeName,
							  const System::String& newDebugLibName, const System::String& newReleaseLibName,const System::String& moduleName) const;
		void GenerateToModuleVcxproj(const System::String& resourceDirectory, const System::String& newSolutionName, 
			                         const System::String& newIncludeName, const System::String& newTestingIncludeName,
									 const System::String& newDebugLibName, const System::String& newReleaseLibName,const System::String& moduleName) const;
		void GenerateToModuleVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const;
		void GenerateToUpdate(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const;
		void GenerateToLogJson(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const;		
		void GenerateToTestingJson(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const;
		void GenerateToEnvironmentVariable(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& moduleName) const;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_IMPL_H
