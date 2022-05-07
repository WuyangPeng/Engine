///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 15:39)

#ifndef RENDERING_CURVES_SURFACES_BOX_SURFACE_H
#define RENDERING_CURVES_SURFACES_BOX_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/CurvesSurfacesVolumes/BSplineVolume.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class BoxSurface : public Node
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BoxSurface);

    public:
        using ClassType = BoxSurface;
        using ParentType = Node;

    public:
        BoxSurface(const Mathematics::BSplineVolume<float>& volume, int numUSamples, int numVSamples, int numWSamples, const std::array<VertexFormatSharedPtr, 6>& vformat);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const Mathematics::BSplineVolume<float>& GetVolume() const noexcept;
        NODISCARD int GetNumUSamples() const noexcept;
        NODISCARD int GetNumVSamples() const noexcept;
        NODISCARD int GetNumWSamples() const noexcept;

        void UpdateSurface();

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        NODISCARD TrianglesMeshSharedPtr CreateFace(int numRows, int numCols, const VertexFormatSharedPtr& vformat, bool ccw, float faceValue, const std::array<int, 3>& permute);

        void UpdateFace(int numRows, int numCols, const VertexFormatSharedPtr& vformat, const VertexBufferSharedPtr& vbuffer, bool ccw, float faceValue, const std::array<int, 3>& permute);

    private:
        std::shared_ptr<Mathematics::BSplineVolume<float>> volume;
        int numUSamples;
        int numVSamples;
        int numWSamples;
        bool doSort;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(BoxSurface);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(BoxSurface)
}

#endif  // RENDERING_CURVES_SURFACES_BOX_SURFACE_H
