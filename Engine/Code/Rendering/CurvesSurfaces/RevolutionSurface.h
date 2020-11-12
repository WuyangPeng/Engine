// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/25 15:56)

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
        // The axis of revolution is the z-axis.  You can obtain arbitrary axes
        // after the fact by applying translations and rotations to the object.
        // The curve of revolution is (x(t),z(t)) with t in [tmin,tmax] and
        // z(t) > 0.  It is also assumed to be non-self-intersecting.  When the
        // curve is open, three cases to consider:  If z(tmin) and z(tmax) are
        // both positive, the surface topology is that of a cylinder (use
        // REV_CYLINDER_TOPOLOGY).  If exactly one of z(tmin) or z(tmax) is zero,
        // the surface topology is that of a disk (use REV_DISK_TOPOLOGY).  If
        // z(tmin) and z(tmax) are both zero, the surface topology is that of a
        // sphere (use REV_SPHERE_TOPOLOGY).  When the curve of revolution is
        // closed so that (x(tmin),z(tmin)) and (x(tmax),z(tmax)) are the same
        // point, the surface topology is that of a torus.  For now, rather than
        // having the surface object determine the type of curve, use the
        // Topology enumerated values to provide this information.

        enum /*RENDERING_DEFAULT_DECLARE*/ class TopologyType
        {
            REV_DISK_TOPOLOGY,
            REV_CYLINDER_TOPOLOGY,
            REV_SPHERE_TOPOLOGY,
            REV_TORUS_TOPOLOGY,
            MAX_TOPOLOGY_TYPES
        };

        // Construction and destruction.  The caller is responsible for deleting
        // the input curve.
        RevolutionSurface(Mathematics::Curve2f* curve, float xCenter, TopologyType topology,
                          int numCurveSamples, int numRadialSamples, bool sampleByArcLength,
                          bool outsideView, VertexFormatSharedPtr vformat);

        ~RevolutionSurface();
         
        RevolutionSurface(const RevolutionSurface&) = default;
        RevolutionSurface& operator=(const RevolutionSurface&) = default;
        RevolutionSurface(RevolutionSurface&&) = default;
        RevolutionSurface& operator=(RevolutionSurface&&) = default;
        ObjectInterfaceSharedPtr CloneObject() const override;
        // Mmber access.
        int GetCurveSamples() const noexcept;
        int GetRadialSamples() const noexcept;
        void SetCurve(Mathematics::Curve2f* curve) noexcept;
        const Mathematics::Curve2f* GetCurve() const noexcept;
        TopologyType GetTopology() const noexcept;
        void SetSampleByArcLength(bool sampleByArcLength) noexcept;
        bool GetSampleByArcLength() const noexcept;

        // Modify vertices and normals when the curve itself changes over time.
        // You are responsible for maintaining the topology of the curve.  For
        // example, if your constructor input was REV_SPHERE_TOPOLOGY, you should
        // not change the curve to produce a non-spherical topology.
        void UpdateSurface();

    protected:
        void ComputeSampleData();
        void UpdateDisk();
        void UpdateCylinder();
        void UpdateSphere();
        void UpdateTorus();

        Mathematics::Curve2f* mCurve;
        float mXCenter;
        TopologyType mTopology;
        int mNumCurveSamples, mNumRadialSamples;
        float* mSin;
        float* mCos;
        Mathematics::FloatVector3D* mSamples;
        bool mSampleByArcLength;
    };
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(RevolutionSurface);
    CORE_TOOLS_SHARED_PTR_DECLARE(RevolutionSurface);
#include STSTEM_WARNING_POP
}

#endif  // RENDERING_CURVES_SURFACES_REVOLUTION_SURFACE_H
