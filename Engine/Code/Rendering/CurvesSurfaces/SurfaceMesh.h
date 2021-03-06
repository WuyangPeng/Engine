// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/25 15:57)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_MESH_H
#define RENDERING_CURVES_SURFACES_SURFACE_MESH_H

#include "Rendering/RenderingDll.h"

#include "Float2Array.h"
#include "SurfacePatch.h"
#include "Mathematics/Meshes/EdgeKey.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

#include <map>

namespace Rendering
{
    class /*RENDERING_DEFAULT_DECLARE*/ SurfaceMesh : public TrianglesMesh
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SurfaceMesh);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        using ClassType = SurfaceMesh;
        using ParentType = TrianglesMesh;

    public:
        // Construction and destruction.  If there are T triangles, ibuffer
        // has 3*T elements, patches has T elements, and spkParams has 3*T
        // elements.  Each triangle has a patch for constructing vertices in the
        // subdivision.  The subdivision requires knowing the parameter values
        // at the vertices of the original triangles.  SurfaceMesh assumes
        // responsibility for deleting the patches array (so it must be
        // dynamically allocated).  The parameter allowDynamicChange should be
        // set to 'true' when you plan on dynamically changing the surface
        // patches.  For example, you might modify the control points in a Bezier
        // surface patch.
        SurfaceMesh(VertexFormatSharedPtr vformat, VertexBufferSharedPtr vbuffer, IndexBufferSharedPtr ibuffer,
                    Float2ArraySharedPtr params, SurfacePatchSharedPtr* patches, bool allowDynamicChange);

        ~SurfaceMesh();
        SurfaceMesh(const SurfaceMesh&) = default;
        SurfaceMesh& operator=(const SurfaceMesh&) = default;
        SurfaceMesh(SurfaceMesh&&) = default;
        SurfaceMesh& operator=(SurfaceMesh&&) = default;

        // Level of subdivision.  The 'level' value must be nonnegative.
        void SetLevel(int level);
        int GetLevel() const noexcept;

        // Call this function when one or more of your surface patches has
        // dynamically changed.
        void OnDynamicChange();

        // Free up all memory used by the object, other than the TriMesh data.
        // The intent is that the surface mesh is in its final form.  Once this
        // function is called, SetLevel is ignored.
        void Lock();
        bool IsLocked() const noexcept;

    protected:
        VertexBufferSharedPtr mOrigVBuffer;
        IndexBufferSharedPtr mOrigIBuffer;
        Float2ArraySharedPtr mOrigParams;
        SurfacePatchSharedPtr* mPatches;
        int mNumFullVertices, mNumPatches, mLevel;

    private:
        // Support for subdivision of the mesh.
        class Edge
        {
        public:
            Edge(int v0 = -1, int v1 = -1);

            // Support for std::set.
            bool operator<(const Edge& edge) const;

            // Surface for subdivision evaluations.
            SurfacePatchSharedPtr Patch;

            // Indices for the vertices.
            int V[2]{};

            // Surface parameter values for the endpoints.
            Mathematics::Float2 Param[2];

            // Index for the midpoint.
            int VMid;

            // Surface parameter value for the midpoint.
            Mathematics::Float2 ParamMid;

            // Number of triangles sharing the edge.
            int References;
        };

        using EdgeMap = std::map<Mathematics::EdgeKey, Edge>;

        class Triangle
        {
        public:
            Triangle() noexcept;

            // The surface for subdivision evaluations.
            SurfacePatchSharedPtr Patch;

            // Indices for the vertices.
            int V[3]{};
        };

        void Allocate(int& numTotalVertices, int& numTotalEdges, EdgeMap& edgeMap, int& numTotalTriangles, Triangle*& triangles);

        void Subdivide(int& numVertices, int& numEdges, EdgeMap& edgeMap, int& numTriangles, Triangle* triangles);

        void InsertInto(EdgeMap& edgeMap, SurfacePatchSharedPtr patch, int v0, int v1, const Mathematics::Float2& param0, const Mathematics::Float2& param1, int newReferences);

        // Support for dynamic changes in the surface patches.
        class SurfaceInfo
        {
        public:
            SurfaceInfo()  ;

            SurfacePatchSharedPtr Patch;
            Mathematics::Float2 Param;
        };

        void InitializeSurfaceInfo() noexcept;

        bool mAllowDynamicChange;
        SurfaceInfo* mSInfo;
    };
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(SurfaceMesh);
    CORE_TOOLS_SHARED_PTR_DECLARE( SurfaceMesh);
#include STSTEM_WARNING_POP
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_MESH_H
