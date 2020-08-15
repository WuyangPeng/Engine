// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:24)

#ifndef RENDERING_DETAIL_CLOD_MESH_VERTEX_EDGE_TRIANGLE_GRAPH_H
#define RENDERING_DETAIL_CLOD_MESH_VERTEX_EDGE_TRIANGLE_GRAPH_H

#include "Rendering/RenderingDll.h"

#include "ClodMeshEdge.h"
#include "ClodMeshVertex.h"
#include "ClodMeshCollapseInfo.h"
#include "CoreTools/DataTypes/MinHeap.h"
#include "Mathematics/Meshes/EdgeKey.h"
#include "Mathematics/Meshes/TriangleKey.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

#include <vector>
#include <map>

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
		bool ValidResults(int numTriangles, int numVertices, int collapsesSize);

		void UpdateEdgeHeapToMaxReal(const EdgeKey& edgeKey);
		void UpdateEdgeHeap(int recordIndex, float metric);

		const ClodMeshEdge& GetClodMeshEdge(const EdgeKey& edgeKey) const;
		const ClodMeshVertex& GetClodMeshVertex(int index) const;
		Triangle GetTriangle(const TriangleKey& triangleKey) const;
		EdgeMapConstIter GetEdgeMapBegin() const noexcept;
		EdgeMapConstIter GetEdgeMapEnd() const noexcept;
		int GetMinHeapElementsNumber() const noexcept;

		const MinHeapRecord GetMinHeapMinimum() const;

		RemainingConstIter GetVerticesRemainingBegin() const noexcept;
		RemainingConstIter GetTrianglesRemainingBegin() const noexcept;
		RemainingConstIter GetVerticesRemainingEnd() const noexcept;
		RemainingConstIter GetTrianglesRemainingEnd() const noexcept;

		bool IsUniqueIndexValid(int minHeapRecordIndex) const;

	private:		
		using VertexArray = std::vector<ClodMeshVertex>;
		using TriangleMap = std::map<TriangleKey, Triangle>;
		using MinHeap = CoreTools::MinHeap<EdgeKey, float>;
	
	private:
		void InsertEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey);
		void RemoveEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey);

	private:
		// 顶点——边——三角形图形。
		VertexArray m_Vertices;
		EdgeMap m_Edges;
		TriangleMap m_Triangles;

		// 边缘堆支持折叠操作。
		MinHeap m_Heap;	

		// 边缘折叠后的处理
		Remaining m_VerticesRemaining;
		Remaining m_TrianglesRemaining;
	};
}

#endif // RENDERING_DETAIL_CLOD_MESH_VERTEX_EDGE_TRIANGLE_GRAPH_H
