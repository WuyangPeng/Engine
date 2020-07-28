// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:34)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateHeaderImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h" 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateHeaderImpl
	::sm_Extension(SYSTEM_TEXT(".h"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateHeaderImpl
	::GenerateTemplateHeaderImpl(const System::String& templateFileName,  const Replace& replace)
	:ParentType(templateFileName, sm_Extension,replace) 
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateHeaderImpl)

void AssistTools::GenerateTemplateHeaderImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital));

	return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
 æ¿˝ƒ£∞Â£∫
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_H
#define %ProjectCapital%_H

#endif // %ProjectCapital%_H
*/