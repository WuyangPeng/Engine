///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:33)

#ifndef RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_H
#define RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Contract/DelayCopyUnsharedImpl.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/Renderers/RenderersInternalFwd.h"

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

#endif  // RENDERING_RENDERERS_ANALYSIS_RENDERER_PARAMETER_H
