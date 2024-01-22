/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:53)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GameParameterAnalysisImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GameParameterAnalysis
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GameParameterAnalysis);

        using String = System::String;
        using GameModuleContainer = std::vector<GameModule>;
        using GameModuleContainerConstIter = GameModuleContainer::const_iterator;
        using MiddleLayerContainer = std::vector<MiddleLayerModule>;
        using MiddleLayerContainerConstIter = MiddleLayerContainer::const_iterator;

    public:
        explicit GameParameterAnalysis(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetModuleCount() const;
        NODISCARD GameModuleContainerConstIter GetModuleBegin() const noexcept;
        NODISCARD GameModuleContainerConstIter GetModuleEnd() const noexcept;
        NODISCARD MiddleLayerContainerConstIter GetMiddleLayerBegin() const noexcept;
        NODISCARD MiddleLayerContainerConstIter GetMiddleLayerEnd() const noexcept;
        NODISCARD bool HasTools() const noexcept;

        NODISCARD String GetGameParameter(GameParameterType gameParameterType) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_H