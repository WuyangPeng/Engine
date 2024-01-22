﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:56)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_CODE_MODULE_TESTING_GENERATE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_CODE_MODULE_TESTING_GENERATE_H

#include "AssistTools/AssistToolsDll.h"

#include "ModuleGenerate.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE CodeModuleTestingGenerate final : public ModuleGenerate
    {
    public:
        using ClassType = CodeModuleTestingGenerate;
        using ParentType = ModuleGenerate;

    public:
        CodeModuleTestingGenerate(const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, GenerateDirectory generateDirectory) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void GenerateModule(const GameModule& gameModule) override;

        void GenerateCodeModule(const GameModule& gameModule, const ReplaceContainer& replace, const GenerateDirectory& directory, const StringView& describe, const StringView& suffix);

        void GenerateByContent(const ReplaceContainer& replace, const GenerateDirectory& directory);

    private:
        GenerateDirectory generateDirectory;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_CODE_MODULE_TESTING_GENERATE_H
