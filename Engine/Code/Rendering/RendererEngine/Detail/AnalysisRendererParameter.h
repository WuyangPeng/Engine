/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:09)

#ifndef RENDERING_RENDERER_ENGINE_ANALYSIS_RENDERER_PARAMETER_H
#define RENDERING_RENDERER_ENGINE_ANALYSIS_RENDERER_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Contract/DelayCopyUnsharedImpl.h"
#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"
#include "Rendering/RendererEngine/RendererParameter.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE AnalysisRendererParameter
    {
    public:
        using ClassType = AnalysisRendererParameter;
        using PackageType = CoreTools::DelayCopyUnsharedImpl<RendererParameter, RendererParameterImpl>;

    public:
        explicit AnalysisRendererParameter(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD PackageType GetRendererParameter() const noexcept;

    private:
        using TreeType = boost::property_tree::ptree;

    private:
        void Analysis();
        void AnalysisJson();
        void AnalysisRendererType();
        void AnalysisRendererTexture();
        void AnalysisRendererClearColor();
        void AnalysisWindowParameter();
        void AnalysisWindowName();
        void AnalysisWindowPictorialParameter();

    private:
        PackageType rendererParameter;
        std::string fileName;
        TreeType mainTree;
        TreeType textureTree;
        TreeType clearColorTree;
        TreeType windowParameterTree;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_ANALYSIS_RENDERER_PARAMETER_H
