///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/18 10:43)

#ifndef RENDERING_CURVES_SURFACES_REVOLUTION_SURFACE_H
#define RENDERING_CURVES_SURFACES_REVOLUTION_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/Float.h"
#include "Mathematics/CurvesSurfacesVolumes/Curve2.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class RevolutionSurface : public TrianglesMesh
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(RevolutionSurface);

    public:
        using ClassType = RevolutionSurface;
        using ParentType = TrianglesMesh;

    public:
        enum class TopologyType
        {
            RevDiskTopology,
            RevCylinderTopology,
            RevSphereTopology,
            RevTorusTopology,
            MaxTopologyTypes
        };

        RevolutionSurface(const std::shared_ptr<Mathematics::Curve2<float>>& curve,
                          float xCenter,
                          TopologyType topology,
                          int numCurveSamples,
                          int numRadialSamples,
                          bool sampleByArcLength,
                          bool outsideView,
                          const VertexFormatSharedPtr& vformat);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD int GetCurveSamples() const noexcept;
        NODISCARD int GetRadialSamples() const noexcept;
        void SetCurve(const std::shared_ptr<Mathematics::Curve2<float>>& aCurve) noexcept;
        NODISCARD std::shared_ptr<Mathematics::Curve2<float>> GetCurve() const noexcept;
        NODISCARD TopologyType GetTopology() const noexcept;
        void SetSampleByArcLength(bool aSampleByArcLength) noexcept;
        NODISCARD bool GetSampleByArcLength() const noexcept;

        void UpdateSurface();

    protected:
        void ComputeSampleData();
        void UpdateDisk();
        void UpdateCylinder();
        void UpdateSphere();
        void UpdateTorus();

    private:
        std::shared_ptr<Mathematics::Curve2<float>> curve;
        float xCenter;
        TopologyType topology;
        int numCurveSamples;
        int numRadialSamples;
        std::vector<float> sin;
        std::vector<float> cos;
        std::vector<Mathematics::Vector3F> samples;
        bool sampleByArcLength;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(RevolutionSurface);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(RevolutionSurface);
}

#endif  // RENDERING_CURVES_SURFACES_REVOLUTION_SURFACE_H
