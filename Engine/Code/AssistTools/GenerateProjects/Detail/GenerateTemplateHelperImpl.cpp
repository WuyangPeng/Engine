// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:34)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateHelperImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateHelperImpl
	::GenerateTemplateHelperImpl(const System::String& templateFileName, const System::String& extension,  const Replace& replace)
	:ParentType(templateFileName, extension, replace)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateHelperImpl)

void AssistTools::GenerateTemplateHelperImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital,const System::String& solutionName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName));

	return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}


/*
 æ¿˝ƒ£∞Â£∫
.h

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ProjectCapital%_HELPER_H
#define %ProjectCapital%_%ProjectCapital%_HELPER_H

#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "%SolutionName%Message.h"

namespace %SolutionName%
{
	typedef Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild,%SolutionName%MessageWindowProcessHandle>
			WindowMainFunctionHelperBase;

	class %SolutionName%Helper : public WindowMainFunctionHelperBase
	{
	public:
		typedef %SolutionName%Helper ClassType;		
		typedef WindowMainFunctionHelperBase ParentType;
		typedef Framework::WindowApplicationInformation WindowApplicationInformation;
		typedef Framework::EnvironmentDirectory EnvironmentDirectory;

	public:
		%SolutionName%Helper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory);
		virtual ~%SolutionName%Helper();
		
		CLASS_INVARIANT_VIRTUAL_DECLARE;	
	};
}

#endif // %ProjectCapital%_%ProjectCapital%_HELPER_H

.cpp

// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#include "%SolutionName%Helper.h"
#include "%SolutionName%.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"

%SolutionName%::%SolutionName%Helper
	::%SolutionName%Helper(HInstance instance,char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory)
	:ParentType(instance,commandLine,information,environmentDirectory)
{
	SELF_CLASS_IS_VALID_9;
}

%SolutionName%::%SolutionName%Helper
	::~%SolutionName%Helper()
{
	SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(%SolutionName%,%SolutionName%Helper) 
*/