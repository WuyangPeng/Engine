///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 10:13)

#ifndef FRAMEWORK_APPLICATION_ANALYSIS_RENDERER_MANAGE_H
#define FRAMEWORK_APPLICATION_ANALYSIS_RENDERER_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/Renderers/RenderersFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE AnalysisRendererManager
    {
    public:
        using ClassType = AnalysisRendererManager;
        using RendererSharedPtr = std::shared_ptr<Rendering::Renderer>;

    public:
        explicit AnalysisRendererManager(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererSharedPtr GetRenderer() const noexcept;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisRendererType();
        void AnalysisRendererTexture(); 

    private:
        RendererSharedPtr renderer;
        std::string fileName;
        boost::property_tree::ptree mainTree;
        boost::property_tree::ptree textureTree;
        boost::property_tree::ptree clearColorTree;
        boost::property_tree::ptree windowParameterTree;

        RendererBasis rendererBasis;
        RendererTypes rendererType;
    };
}

#endif  // FRAMEWORK_APPLICATION_ANALYSIS_RENDERER_MANAGE_H
