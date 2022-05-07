///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 11:06)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateHelperImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AssistTools::GenerateTemplateHelperImpl::GenerateTemplateHelperImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace)
    : ParentType{ templateFileName, extension, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateHelperImpl)

void AssistTools::GenerateTemplateHelperImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& solutionName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newVariable = GetCopyrightVariable(copyrightData);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName);

    return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
示例模板：
.h

// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%版本：%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ProjectCapital%_HELPER_H
#define %ProjectCapital%_%ProjectCapital%_HELPER_H

#include "%SolutionName%Message.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"

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
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%版本：%Versions% (%Date% %Hour%:%Minute%)

#include "%SolutionName%.h"
#include "%SolutionName%Helper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSharedPtrDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

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