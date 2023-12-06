///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:56)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GameParameter.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"

#include <map>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GameParameterAnalysisImpl
    {
    public:
        using ClassType = GameParameterAnalysisImpl;

        using String = System::String;
        using GameModuleContainer = std::vector<GameModule>;
        using GameModuleContainerConstIter = GameModuleContainer::const_iterator;
        using MiddleLayerContainer = std::vector<MiddleLayerModule>;
        using MiddleLayerContainerConstIter = MiddleLayerContainer::const_iterator;

    public:
        explicit GameParameterAnalysisImpl(std::string fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetModuleCount() const;
        NODISCARD GameModuleContainerConstIter GetModuleBegin() const noexcept;
        NODISCARD GameModuleContainerConstIter GetModuleEnd() const noexcept;
        NODISCARD MiddleLayerContainerConstIter GetMiddleLayerBegin() const noexcept;
        NODISCARD MiddleLayerContainerConstIter GetMiddleLayerEnd() const noexcept;
        NODISCARD bool HasTools() const noexcept;

        NODISCARD String GetGameParameter(GameParameterType gameParameterType) const;

    private:
        using BasicTree = boost::property_tree::basic_ptree<std::string, std::string>;
        using MappingContainer = std::map<GameParameterType, String>;
        using GameParameterContainer = std::vector<GameParameter>;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisMain();

        void AnalysisGameParameter();
        void AnalysisModule();
        void AnalysisMiddleLayer();

        void AnalysisModule(const std::string& moduleName, const BasicTree& basicTree);
        void AnalysisMiddleLayer(const std::string& middleLayerName, const BasicTree& basicTree);

        void InsertModule(const std::string& moduleName, const BasicTree& basicTree);
        void InsertMiddleLayer(const std::string& middleLayerName, const BasicTree& basicTree);

        NODISCARD static const GameParameterContainer& GetGameParameterContainer();

    private:
        std::string fileName;
        BasicTree mainTree;
        MappingContainer gameParameter;
        GameModuleContainer gameModule;
        MiddleLayerContainer middleLayer;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_ANALYSIS_IMPL_H