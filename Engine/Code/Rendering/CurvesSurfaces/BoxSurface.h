///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:58)

#ifndef RENDERING_CURVES_SURFACES_BOX_SURFACE_H
#define RENDERING_CURVES_SURFACES_BOX_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/CurvesSurfacesVolumes/BSplineVolume.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/SceneGraph/Node.h"

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

        void UpdateSurface() noexcept;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        void UpdateFace(int numRows, int numCols, const VertexFormatSharedPtr& vformat, const VertexBufferSharedPtr& vbuffer, bool ccw, float faceValue, const std::array<int, 3>& permute);

    private:
        std::shared_ptr<Mathematics::BSplineVolume<float>> volume;
        int numUSamples;
        int numVSamples;
        int numWSamples;
        bool doSort;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(BoxSurface);
}

#endif  // RENDERING_CURVES_SURFACES_BOX_SURFACE_H
