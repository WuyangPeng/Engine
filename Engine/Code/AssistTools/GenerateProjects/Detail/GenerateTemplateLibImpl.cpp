// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:35)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateLibImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

const System::String AssistTools::GenerateTemplateLibImpl
	::sm_Extension(SYSTEM_TEXT(".cpp"));

AssistTools::GenerateTemplateLibImpl
	::GenerateTemplateLibImpl(const System::String& templateFileName, const Replace& replace)
	:ParentType(templateFileName, sm_Extension, replace)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

AssistTools::GenerateTemplateLibImpl
	::~GenerateTemplateLibImpl()
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateLibImpl)

void AssistTools::GenerateTemplateLibImpl
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& solutionName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName));

	return ParentType::GenerateTo(resourceDirectory, newProjectName, newVariable);
}


/*
 æ¿˝ƒ£∞Â£∫
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%∞Ê±æ£∫%Versions% (%Date% %Hour%:%Minute%)

#include "ThreadingCoreRenderEngine/ThreadingCoreRenderEngineLib.h"

#include "%SolutionName%/%SolutionName%MiddleLayer/%SolutionName%MiddleLayerLib.h" 
*/