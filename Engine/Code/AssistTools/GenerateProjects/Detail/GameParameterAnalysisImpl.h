///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 11:02)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GameParameterAnalysisImpl
    {
    public:
        using ClassType = GameParameterAnalysisImpl;

        using String = System::String;
        using MiddleLayerContainer = std::vector<MiddleLayerModule>;
        using MiddleLayerContainerConstIter = MiddleLayerContainer::const_iterator;
        using GameModuleContainer = std::vector<GameModule>;
        using GameModuleContainerConstIter = GameModuleContainer::const_iterator;

    public:
        explicit GameParameterAnalysisImpl(const std::string& fileName);

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

    private:
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();

        void InsertModule(const String& moduleName, const BasicTree& basicTree);
        void InsertMiddleLayer(const String& middleLayerName, const BasicTree& basicTree);

    private:
        std::string fileName;
        BasicTree mainTree;

        String coreName;
        String coreCapital;
        String projectChineseName;
        String projectDescribeName;
        String projectName;
        String projectCapital;
        String projectAbbreviation;
        String endYear;
        String version;
        String versionNum;
        GameModuleContainer gameModule;
        MiddleLayerContainer middleLayer;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_IMPL_H