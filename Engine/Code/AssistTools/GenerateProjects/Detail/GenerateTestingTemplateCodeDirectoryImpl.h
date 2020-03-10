// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateDirectoryImpl.h" 

namespace AssistTools
{ 
	class CopyrightData;

	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTestingTemplateCodeDirectoryImpl : public GenerateTemplateDirectoryImpl
	{
	public:
		typedef GenerateTestingTemplateCodeDirectoryImpl ClassType;
		typedef GenerateTemplateDirectoryImpl ParentType;

	public:
		GenerateTestingTemplateCodeDirectoryImpl(const System::String& directory, const std::string& configurationFileName);
		virtual ~GenerateTestingTemplateCodeDirectoryImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& newCoreName, const System::String& CoreNameCapital) const;

	private:
		void GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName,
							   const CopyrightData& copyrightData,const System::String& managerName,
							   const System::String& projectCapital,const System::String& managerCapital) const;
		void GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName,
							   const CopyrightData& copyrightData,const System::String& managerName,
							   const System::String& projectCapital,const System::String& managerCapital,
							   const System::String& extension, const System::String& fileName, const System::String& resultName) const; 
	};
} 
#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_IMPL_H
