///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/18 13:51)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_MESH_H
#define RENDERING_CURVES_SURFACES_SURFACE_MESH_H

#include "Rendering/RenderingDll.h"

#include "Float2Array.h"
#include "SurfacePatch.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Mathematics/Meshes/EdgeKey.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

#include <map>

namespace Rendering
{
    class SurfaceMesh : public TrianglesMesh
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SurfaceMesh);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        using ClassType = SurfaceMesh;
        using ParentType = TrianglesMesh;

    public:
        SurfaceMesh(const VertexFormatSharedPtr& vformat,
                    const VertexBufferSharedPtr& vbuffer,
                    const IndexBufferSharedPtr& ibuffer,
                    const Float2ArraySharedPtr& params,
                    const std::vector<CoreTools::ObjectAssociated<SurfacePatch>>& patches,
                    bool allowDynamicChange);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetLevel(int aLevel);
        NODISCARD int GetLevel() const noexcept;

        void OnDynamicChange();

        void Lock() noexcept;
        NODISCARD bool IsLocked() const noexcept;

    private:
        class Edge
        {
        public:
            Edge(int v0 = -1, int v1 = -1) noexcept;

            NODISCARD bool operator<(const Edge& edge) const;

            SurfacePatchSharedPtr patch;

            std::array<int, 2> v;

            std::array<Mathematics::Float2, 2> param;

            int vMid;

            Mathematics::Float2 paramMid;

            int references;
        };

        using EdgeMap = std::map<Mathematics::EdgeKey, Edge>;

        class Triangle
        {
        public:
            Triangle() noexcept;

            CoreTools::ObjectAssociated<SurfacePatch> patch;

            std::array<int, 3> v;
        };

        NODISCARD std::vector<Triangle> Allocate(int& numTotalVertices, int& numTotalEdges, EdgeMap& edgeMap, int& numTotalTriangles);

        void Subdivide(int& numVertices, int& numEdges, EdgeMap& edgeMap, int& numTriangles, std::vector<Triangle>& triangles);

        void InsertInto(EdgeMap& edgeMap, const SurfacePatchSharedPtr& patch, int v0, int v1, const Mathematics::Float2& param0, const Mathematics::Float2& param1, int newReferences);

        class SurfaceInfo
        {
        public:
            SurfaceInfo() noexcept;

            CoreTools::ObjectAssociated<SurfacePatch> patch;
            Mathematics::Float2 param;
        };

        void InitializeSurfaceInfo();

    private:
        CoreTools::ObjectAssociated<VertexBuffer> origVBuffer;
        CoreTools::ObjectAssociated<IndexBuffer> origIBuffer;
        CoreTools::ObjectAssociated<Float2Array> origParams;
        std::vector<CoreTools::ObjectAssociated<SurfacePatch>> patches;
        int numFullVertices;
        int numPatches;
        int level;

        bool allowDynamicChange;
        std::vector<SurfaceInfo> sInfo;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(SurfaceMesh);
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_MESH_H
