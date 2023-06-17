///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/29 11:08)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateLibImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

const System::String AssistTools::GenerateTemplateLibImpl::extension(SYSTEM_TEXT(".cpp"));

AssistTools::GenerateTemplateLibImpl::GenerateTemplateLibImpl(const System::String& templateFileName, const Replace& replace)
    : ParentType{ templateFileName, extension, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateLibImpl)

void AssistTools::GenerateTemplateLibImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& solutionName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newVariable = GetCopyrightVariable(copyrightData);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName);

    return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
ʾ��ģ�壺
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%�汾��%Versions% (%Date% %Hour%:%Minute%)

#include "ThreadingCoreRenderEngine/ThreadingCoreRenderEngineLib.h"

#include "%SolutionName%/%SolutionName%MiddleLayer/%SolutionName%MiddleLayerLib.h" 
*/