/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:54)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_WINDOWS_PROJECT_MODULE_GENERATE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_WINDOWS_PROJECT_MODULE_GENERATE_H

#include "AssistTools/AssistToolsDll.h"

#include "ModuleGenerate.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE WindowsProjectModuleGenerate final : public ModuleGenerate
    {
    public:
        using ClassType = WindowsProjectModuleGenerate;
        using ParentType = ModuleGenerate;

    public:
        WindowsProjectModuleGenerate(const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, GenerateDirectory generateDirectory) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void GenerateModule(const GameModule& gameModule) override;

        void GenerateWindowsProjectTodo(const GenerateDirectory& directory);

        void GenerateWindowsProjectModuleCore(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);
        void GenerateWindowsProjectModuleMiddleLayer(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);
        void GenerateWindowsProjectModuleExe(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);

        void GenerateWindowsProjectModuleResource(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);
        void GenerateWindowsProjectModuleExeConfiguration(const GameModule& gameModule, const GenerateDirectory& directory, const ReplaceContainer& replace);

    private:
        GenerateDirectory generateDirectory;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_WINDOWS_PROJECT_MODULE_GENERATE_H
