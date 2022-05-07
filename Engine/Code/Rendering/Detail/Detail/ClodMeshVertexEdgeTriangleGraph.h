///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/09 19:19)

#ifndef RENDERING_DETAIL_CLOD_MESH_VERTEX_EDGE_TRIANGLE_GRAPH_H
#define RENDERING_DETAIL_CLOD_MESH_VERTEX_EDGE_TRIANGLE_GRAPH_H

#include "Rendering/RenderingDll.h"

#include "ClodMeshCollapseInfo.h"
#include "ClodMeshEdge.h"
#include "ClodMeshVertex.h"
#include "CoreTools/DataTypes/MinHeap.h"
#include "Mathematics/Meshes/EdgeKey.h"
#include "Mathematics/Meshes/TriangleKey.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

#include <map>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ClodMeshVertexEdgeTriangleGraph
    {
    public:
        using ClassType = ClodMeshVertexEdgeTriangleGraph;
        using Triangle = int;
        using TriangleKey = Mathematics::TriangleKey;
        using EdgeKey = Mathematics::EdgeKey;
        using Remaining = std::vector<int>;
        using RemainingConstIter = Remaining::const_iterator;
        using MinHeapRecord = CoreTools::MinHeapRecord<EdgeKey, float>;
        using EdgeMap = std::map<EdgeKey, ClodMeshEdge>;
        using EdgeMapConstIter = EdgeMap::const_iterator;

    public:
        ClodMeshVertexEdgeTriangleGraph(int numVertices, int numIndices);

        CLASS_INVARIANT_DECLARE;

        void InsertTriangle(const TriangleKey& triangleKey, Triangle triangle);
        void RemoveTriangle(const TriangleKey& triangleKey);

        void ClassifyCollapsibleVertices();
        NODISCARD bool ValidResults(int numTriangles, int numVertices, int collapsesSize);

        void UpdateEdgeHeapToMaxReal(const EdgeKey& edgeKey);
        void UpdateEdgeHeap(int recordIndex, float metric);

        NODISCARD const ClodMeshEdge& GetClodMeshEdge(const EdgeKey& edgeKey) const;
        NODISCARD const ClodMeshVertex& GetClodMeshVertex(int index) const;
        NODISCARD Triangle GetTriangle(const TriangleKey& triangleKey) const;
        NODISCARD EdgeMapConstIter GetEdgeMapBegin() const noexcept;
        NODISCARD EdgeMapConstIter GetEdgeMapEnd() const noexcept;
        NODISCARD int GetMinHeapElementsNumber() const noexcept;

        NODISCARD MinHeapRecord GetMinHeapMinimum() const;

        NODISCARD RemainingConstIter GetVerticesRemainingBegin() const noexcept;
        NODISCARD RemainingConstIter GetTrianglesRemainingBegin() const noexcept;
        NODISCARD RemainingConstIter GetVerticesRemainingEnd() const noexcept;
        NODISCARD RemainingConstIter GetTrianglesRemainingEnd() const noexcept;

        NODISCARD bool IsUniqueIndexValid(int minHeapRecordIndex) const;

    private:
        using VertexArray = std::vector<ClodMeshVertex>;
        using TriangleMap = std::map<TriangleKey, Triangle>;
        using MinHeap = CoreTools::MinHeap<EdgeKey, float>;

    private:
        void InsertEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey);
        void RemoveEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey);

    private:
        // 顶点——边——三角形图形。
        VertexArray vertices;
        EdgeMap edges;
        TriangleMap triangles;

        // 边缘堆支持折叠操作。
        MinHeap heap;

        // 边缘折叠后的处理
        Remaining verticesRemaining;
        Remaining trianglesRemaining;
    };
}

#endif  // RENDERING_DETAIL_CLOD_MESH_VERTEX_EDGE_TRIANGLE_GRAPH_H
