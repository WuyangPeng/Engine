﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:56)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_DEFAULT_PROJECT_GENERATION_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_DEFAULT_PROJECT_GENERATION_H

#include "AssistTools/AssistToolsDll.h"

#include "ProjectGenerationImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE DefaultProjectGeneration : public ProjectGenerationImpl
    {
    public:
        using ClassType = DefaultProjectGeneration;
        using ParentType = ProjectGenerationImpl;

    public:
        DefaultProjectGeneration(const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GetContent() const override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_DEFAULT_PROJECT_GENERATION_H