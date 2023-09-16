///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 11:03)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

ASSIST_TOOLS_COPY_UNSHARED_EXPORT_IMPL(GameParameterAnalysis, GameParameterAnalysisImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GameParameterAnalysis
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GameParameterAnalysis);

        using String = System::String;
        using MiddleLayerContainer = std::vector<MiddleLayerModule>;
        using MiddleLayerContainerConstIter = MiddleLayerContainer::const_iterator;
        using GameModuleContainer = std::vector<GameModule>;
        using GameModuleContainerConstIter = GameModuleContainer::const_iterator;

    public:
        explicit GameParameterAnalysis(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetModuleCount() const;
        NODISCARD GameModuleContainerConstIter GetModuleBegin() const noexcept;
        NODISCARD GameModuleContainerConstIter GetModuleEnd() const noexcept;
        NODISCARD MiddleLayerContainerConstIter GetMiddleLayerBegin() const noexcept;
        NODISCARD MiddleLayerContainerConstIter GetMiddleLayerEnd() const noexcept;

        NODISCARD String GetCoreName() const;
        NODISCARD String GetCoreCapital() const;
        NODISCARD String GetProjectChineseName() const;
        NODISCARD String GetProjectDescribeName() const;
        NODISCARD String GetProjectName() const;
        NODISCARD String GetProjectCapital() const;
        NODISCARD String GetProjectAbbreviation() const;
        NODISCARD String GetEndYear() const;
        NODISCARD String GetVersion() const;
        NODISCARD String GetVersionNum() const;
        NODISCARD String GetTestingName() const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_H