///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.1 (2023/11/23 22:08)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SLN_PROJECT_GENERATION_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SLN_PROJECT_GENERATION_H

#include "AssistTools/AssistToolsDll.h"

#include "Utf8ReplaceProjectGeneration.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE SlnProjectGeneration final : public Utf8ReplaceProjectGeneration
    {
    public:
        using ClassType = SlnProjectGeneration;
        using ParentType = Utf8ReplaceProjectGeneration;

    public:
        SlnProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GetContent() const override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SLN_PROJECT_GENERATION_H
