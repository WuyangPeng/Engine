// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:21)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_CODE_DIRECTORY_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_CODE_DIRECTORY_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateDirectoryImpl.h" 

namespace AssistTools
{ 
	class CopyrightData;

	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateCodeDirectoryImpl : public GenerateTemplateDirectoryImpl
	{
	public:
		using ClassType = GenerateTemplateCodeDirectoryImpl ;
		using ParentType = GenerateTemplateDirectoryImpl ;

	public:
		GenerateTemplateCodeDirectoryImpl(const System::String& directory, const std::string& configurationFileName);
		virtual ~GenerateTemplateCodeDirectoryImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, 
			            const CopyrightData& copyrightData, const System::String& projectCapital,
						const System::String& projectName, const System::String& newCoreName, const System::String& CoreNameCapital) const;
 
	private:
		void GenerateToHeader(const System::String& exportDirectory, const System::String& newSolutionName, 
			                  const CopyrightData& copyrightData, const System::String& projectCapital) const;
		void GenerateToHelper(const System::String& exportDirectory, const System::String& newSolutionName, 
			                  const CopyrightData& copyrightData, const System::String& projectCapital) const;
		void GenerateToHelperHeader(const System::String& exportDirectory, const System::String& newSolutionName,
			                        const CopyrightData& copyrightData, const System::String& projectCapital) const;
		void GenerateToHelperSource(const System::String& exportDirectory, const System::String& newSolutionName,
			                        const CopyrightData& copyrightData, const System::String& projectCapital) const;
		void GenerateToMessage(const System::String& exportDirectory, const System::String& newSolutionName, 
			                   const CopyrightData& copyrightData, const System::String& projectCapital) const;
		void GenerateToMessageHeader(const System::String& exportDirectory, const System::String& newSolutionName,
			                         const CopyrightData& copyrightData, const System::String& projectCapital) const;
		void GenerateToMessageSource(const System::String& exportDirectory, const System::String& newSolutionName, 
			                         const CopyrightData& copyrightData, const System::String& projectCapital) const;
		void GenerateToLib(const System::String& exportDirectory, const System::String& newSolutionName, 
			               const CopyrightData& copyrightData) const;
		void GenerateToMain(const System::String& exportDirectory, const System::String& newSolutionName,
			                const CopyrightData& copyrightData, const System::String& projectName) const;
		void GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, 
			                   const CopyrightData& copyrightData, const System::String& managerName,
							   const System::String& projectCapital, const System::String& managerCapitalName) const;
		void GenerateToManagerMiddleLayer(const System::String& exportDirectory, const System::String& newSolutionName, 
			                              const CopyrightData& copyrightData, const System::String& managerName,
										  const System::String& projectCapital, const System::String& managerCapitalName) const;	 
		void GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, 
			                   const CopyrightData& copyrightData, const System::String& managerName, 
							   const System::String& testFileName, const System::String& resultSuffix,
							   const System::String& projectCapital, const System::String& managerCapitalName) const;
		void GenerateToManagerLib(const System::String& exportDirectory, const System::String& newSolutionName, 
			                      const CopyrightData& copyrightData, const System::String& managerName,
								  const System::String& projectCapital, const System::String& managerCapitalName) const;
		void GenerateToManagerDllMain(const System::String& exportDirectory, const System::String& newSolutionName,
			                          const CopyrightData& copyrightData, const System::String& managerName) const;
		void GenerateToManagerDllLib(const System::String& exportDirectory, const System::String& newSolutionName, 
			                         const CopyrightData& copyrightData, const System::String& managerName) const;
		void GenerateToManagerDllLibMiddleLayer(const System::String& exportDirectory, const System::String& newSolutionName,
			                                    const CopyrightData& copyrightData, const System::String& managerName) const;
		void GenerateToManagerMacro(const System::String& exportDirectory, const System::String& newSolutionName, 
			                        const CopyrightData& copyrightData, const System::String& managerName, 
									const System::String& testFileName, const System::String& resultSuffix, 
									const System::String& projectCapital, const System::String& managerCapitalName) const;
		void GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, 
			                         const CopyrightData& copyrightData, const System::String& projectCapital) const;
		void GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName, 
			                         const CopyrightData& copyrightData, const System::String& managerName, 
			                         const System::String& managerInterfaceName, const System::String& projectCapital, 
									 const System::String& managerCapitalName) const;
		void GenerateToMiddleLayerEngine(const System::String& exportDirectory, const System::String& newSolutionName, 
			                             const CopyrightData& copyrightData, const System::String& managerName, 
			                             const System::String& managerInterfaceName, const System::String& projectCapital, 
									     const System::String& managerCapitalName) const;
		void GenerateToInputManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName,
			                              const CopyrightData& copyrightData, const System::String& managerName,
			                              const System::String& managerInterfaceName, const System::String& projectCapital,
										  const System::String& managerCapitalName) const;
		void GenerateToCoreEngine(const System::String& exportDirectory, const System::String& newSolutionName, 
			                      const CopyrightData& copyrightData, const System::String& managerName,
								  const System::String& projectCapital, const System::String& managerCapitalName) const;
		void GenerateToManagerEngine(const System::String& exportDirectory, const System::String& newSolutionName,
			                         const CopyrightData& copyrightData, const System::String& managerName,
									 const System::String& managerInterfaceName,const System::String& testFileName, 
									 const System::String& resultSuffix, const System::String& extension,  
									 const System::String& projectCapital, const System::String& managerCapitalName) const;	
		void GenerateToCoreEngine(const System::String& exportDirectory, const System::String& newSolutionName,
			                      const CopyrightData& copyrightData, const System::String& managerName, 
								  const System::String& managerInterfaceName,const System::String& testFileName, 
								  const System::String& resultSuffix, const System::String& extension, 
								  const System::String& projectCapital, const System::String& managerCapitalName) const;	
		void GenerateToMiddleLayerEngine(const System::String& exportDirectory, const System::String& newSolutionName,
			                             const CopyrightData& copyrightData, const System::String& managerName,
										 const System::String& managerInterfaceName,const System::String& testFileName, 
										 const System::String& resultSuffix, const System::String& extension,  
										 const System::String& projectCapital, const System::String& managerCapitalName) const;	
	};
} 
#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_CODE_DIRECTORY_IMPL_H
