///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/16 18:45)

#ifndef RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H
#define RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/Float.h"
#include "Mathematics/CurvesSurfacesVolumes/ParametricSurface.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class RectangleSurface : public TrianglesMesh
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(RectangleSurface);

    public:
        using ClassType = RectangleSurface;
        using ParentType = TrianglesMesh;

    public:
        RectangleSurface(const std::shared_ptr<Mathematics::ParametricSurface<float>>& surface,
                         int numUSamples,
                         int numVSamples,
                         const VertexFormatSharedPtr& vformat,
                         const Mathematics::Float2& tcoordMin,
                         const Mathematics::Float2& tcoordMax);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetSurface(const std::shared_ptr<Mathematics::ParametricSurface<float>>& aSurface) noexcept;
        NODISCARD std::shared_ptr<Mathematics::ParametricSurface<float>> GetSurface() noexcept;
        NODISCARD int GetNumUSamples() const noexcept;
        NODISCARD int GetNumVSamples() const noexcept;

        void UpdateSurface();

    private:
        std::shared_ptr<Mathematics::ParametricSurface<float>> surface;
        int numUSamples;
        int numVSamples;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(RectangleSurface);
}

#endif  // RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H
