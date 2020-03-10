// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:20)

#ifndef RENDERING_DETAIL_CLOD_MESH_VERTEX_H
#define RENDERING_DETAIL_CLOD_MESH_VERTEX_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Meshes/TriangleKey.h"
#include "Mathematics/Meshes/EdgeKey.h"

#include <set>

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ClodMeshVertex
	{
	public:
		using ClassType = ClodMeshVertex;
		using TriangleKey = Mathematics::TriangleKey;
		using EdgeKey = Mathematics::EdgeKey;
		// 顶点——边——三角形的图形。
		using TriangleKeySet = std::set<TriangleKey>;
		using EdgeKeySet = std::set<EdgeKey>;
		using TriangleKeySetConstIter = TriangleKeySet::const_iterator;
		using EdgeKeySetConstIter = EdgeKeySet::const_iterator;

	public:
		ClodMeshVertex(); 

		CLASS_INVARIANT_DECLARE;

		void InsertTriangleKey(const TriangleKey& triangleKey);
		void InsertEdgeKey(const EdgeKey& edgeKey);
		void SetCollapsible(bool collapsible);

		void EraseTriangleKey(const TriangleKey& triangleKey);
		void EraseEdgeKey(const EdgeKey& edgeKey);
		 
		int GetTriangleKeySize() const;
		int GetEdgeKeySize() const;
		bool IsCollapsible() const;

		TriangleKeySetConstIter GetTriangleKeyBegin() const;
		TriangleKeySetConstIter GetTriangleKeyEnd() const;
		EdgeKeySetConstIter GetEdgeKeyBegin() const;
		EdgeKeySetConstIter GetEdgeKeyEnd() const;

	private:
		EdgeKeySet m_AdjEdges;
		TriangleKeySet m_AdjTriangles;
		bool m_Collapsible;
	};
}

#endif // RENDERING_DETAIL_CLOD_MESH_VERTEX_H
