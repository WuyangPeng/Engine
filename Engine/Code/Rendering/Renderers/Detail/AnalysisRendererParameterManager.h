///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 10:43)

#ifndef RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_MANAGE_H
#define RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "Rendering/Renderers/RenderersInternalFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE AnalysisRendererParameterManager
    {
    public:
        using ClassType = AnalysisRendererParameterManager;
        using RendererParameterSharedPtr = std::shared_ptr<RendererParameterImpl>;

    public:
        explicit AnalysisRendererParameterManager(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererParameterSharedPtr GetRendererParameterPtr() const noexcept;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisRendererType();
        void AnalysisRendererTexture();
        void AnalysisRendererClearColor();
        void AnalysisWindowParameter();

    private:
        RendererParameterSharedPtr rendererParameter;
        std::string fileName;
        boost::property_tree::ptree mainTree;
        boost::property_tree::ptree textureTree;
        boost::property_tree::ptree clearColorTree;
        boost::property_tree::ptree windowParameterTree;
    };
}

#endif  // RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_MANAGE_H
