///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:59)

#ifndef RENDERING_CURVES_SURFACES_TUBE_SURFACE_H
#define RENDERING_CURVES_SURFACES_TUBE_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/Float.h"
#include "Mathematics/CurvesSurfacesVolumes/Curve3.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class TubeSurface : public TrianglesMesh
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TubeSurface);

    public:
        using ClassType = TubeSurface;
        using ParentType = TrianglesMesh;

    public:
        using RadialFunction = float (*)(float);

        TubeSurface(const std::shared_ptr<Mathematics::Curve3<float>>& medial,
                    RadialFunction radial,
                    bool closed,
                    const Mathematics::Vector3F& upVector,
                    int numMedialSamples,
                    int mNumSliceSamples,
                    bool sampleByArcLength,
                    bool insideView,
                    const Mathematics::Float2& tcoordMin,
                    const Mathematics::Float2& tcoordMax,
                    VertexFormatSharedPtr vformat);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetMedial(const std::shared_ptr<Mathematics::Curve3<float>>& aMedial) noexcept;
        NODISCARD std::shared_ptr<Mathematics::Curve3<float>> GetMedial() const noexcept;
        void SetRadial(RadialFunction aRadial) noexcept;
        NODISCARD RadialFunction GetRadial() const noexcept;
        void SetUpVector(const Mathematics::Vector3F& aUpVector) noexcept;
        NODISCARD const Mathematics::Vector3F& GetUpVector() const noexcept;
        NODISCARD int GetNumMedialSamples() const noexcept;
        NODISCARD int GetNumSliceSamples() const noexcept;

        NODISCARD std::vector<Mathematics::Vector3F> GetTMinSlice() noexcept;
        NODISCARD std::vector<Mathematics::Vector3F> GetTMaxSlice() noexcept;

        void UpdateSurface();

    protected:
        NODISCARD int Index(int s, int m) noexcept;
        void ComputeSinCos();
        void ComputeVertices();
        void ComputeNormals() noexcept;
        void ComputeUVs(const Mathematics::Float2& tcoordMin, const Mathematics::Float2& tcoordMax);
        void ComputeIndices(bool insideView);

    private:
        std::shared_ptr<Mathematics::Curve3<float>> medial;
        RadialFunction radial;
        int numMedialSamples;
        int numSliceSamples;
        Mathematics::Vector3F upVector;
        std::vector<float> sin;
        std::vector<float> cos;
        bool closed;
        bool sampleByArcLength;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(TubeSurface);
}

#endif  // RENDERING_CURVES_SURFACES_TUBE_SURFACE_H
