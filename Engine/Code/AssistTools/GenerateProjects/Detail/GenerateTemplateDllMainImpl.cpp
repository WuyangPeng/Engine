// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:33)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDllMainImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateDllMainImpl
	::sm_Extension(SYSTEM_TEXT(".cpp"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateDllMainImpl
	::GenerateTemplateDllMainImpl(const System::String& templateFileName,  const Replace& replace)
	:ParentType(templateFileName, sm_Extension,replace) 
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateDllMainImpl)

void AssistTools::GenerateTemplateDllMainImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData,  const System::String& solutionName, const System::String& managerName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerName), managerName));

	return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫ 
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#include "%SolutionName%%ManagerName%Export.h"

#include "%SolutionName%%ManagerName%Fwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

DLL_MAIN_FUNCTION(%SolutionName%%ManagerName%)
*/