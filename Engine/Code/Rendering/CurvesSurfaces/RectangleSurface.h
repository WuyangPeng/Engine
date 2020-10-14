// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:56)

#ifndef RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H
#define RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/Float2.h"
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
        // Construction and destruction.  The input surface must be rectangular,
        // not triangular.  RectangleSurface accepts responsibility for deleting
        // the input surface.  Any texture coordinates in the vertex format must
        // be 2D.  The minimum and maximum texture coordinates are specified in
        // the constructor.  If you have none, set tcoordMin and tcoordMax to
        // null.
        RectangleSurface(Mathematics::ParametricSurfacef* surface, int numUSamples, int numVSamples,
                         VertexFormatSharedPtr vformat, const Mathematics::Float2* tcoordMin, const Mathematics::Float2* tcoordMax);

        ~RectangleSurface();
        RectangleSurface(const RectangleSurface&) = default;
        RectangleSurface& operator=(const RectangleSurface&) = default;
        RectangleSurface(RectangleSurface&&) = default;
        RectangleSurface& operator=(RectangleSurface&&) = default;

        // Member access.
        void SetSurface(Mathematics::ParametricSurfacef* surface) noexcept;
        const Mathematics::ParametricSurfacef* GetSurface() const noexcept;
        int GetNumUSamples() const noexcept;
        int GetNumVSamples() const noexcept;

        // If the surface is modified, for example if it is control point
        // based and the control points are modified, then you should call this
        // update function to recompute the rectangle surface geometry.
        void UpdateSurface();

    protected:
        Mathematics::ParametricSurfacef* mSurface;
        int mNumUSamples, mNumVSamples;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(RectangleSurface);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( RectangleSurface);
}

#endif  // RENDERING_CURVES_SURFACES_RECTANGLE_SURFACE_H
