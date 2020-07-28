// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:36)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateManagerLibImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateManagerLibImpl
	::sm_Extension(SYSTEM_TEXT(".h"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateManagerLibImpl
	::GenerateTemplateManagerLibImpl(const System::String& templateFileName,  const Replace& replace)
	:ParentType(templateFileName, sm_Extension,replace) 
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateManagerLibImpl)

void AssistTools::GenerateTemplateManagerLibImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital,const System::String& managerCapital,const System::String& solutionName,  const System::String& managerName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerName), managerName));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerCapital), managerCapital)); 
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName));

	return ParentType::Generate (resourceDirectory, newProjectName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_LIB_H
#define %ProjectCapital%_%ManagerCapital%_LIB_H

#if defined(_MSC_VER) 

  #ifdef _DEBUG 
    #pragma comment(lib,"%SolutionName%%ManagerName%D.lib")
  #else
    #pragma comment(lib,"%SolutionName%%ManagerName%.lib")
  #endif // _DEBUG

#endif // _MSC_VER

#endif // %ProjectCapital%_%ManagerCapital%_LIB_H
*/