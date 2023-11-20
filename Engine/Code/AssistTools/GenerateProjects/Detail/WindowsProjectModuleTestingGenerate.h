﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/16 17:10)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_WINDOWS_PROJECT_MODULE_TESTING_GENERATE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_WINDOWS_PROJECT_MODULE_TESTING_GENERATE_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateDirectory.h"
#include "ModuleGenerate.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE WindowsProjectModuleTestingGenerate final : public ModuleGenerate
    {
    public:
        using ClassType = WindowsProjectModuleTestingGenerate;
        using ParentType = ModuleGenerate;

    public:
        WindowsProjectModuleTestingGenerate(const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, GenerateDirectory generateDirectory) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void GenerateModule(const GameModule& gameModule) override;

        void GenerateWindowsProjectModuleCore(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);
        void GenerateWindowsProjectModuleMiddleLayer(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);
        void GenerateWindowsProjectModuleExe(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);

        void GenerateWindowsProjectModuleResource(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);
        void GenerateWindowsProjectModuleConfiguration(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace, const String& mark);
        void GenerateWindowsProjectModuleResourceTodo(const GenerateDirectory& directory);

    private:
        GenerateDirectory generateDirectory;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_WINDOWS_PROJECT_MODULE_TESTING_GENERATE_H
