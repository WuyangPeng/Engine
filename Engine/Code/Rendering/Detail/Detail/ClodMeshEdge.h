// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:18)

#ifndef RENDERING_DETAIL_CLOD_MESH_EDGE_H
#define RENDERING_DETAIL_CLOD_MESH_EDGE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Meshes/TriangleKey.h"

#include <set>

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ClodMeshEdge
	{
	public:
		using ClassType = ClodMeshEdge;
		using TriangleKey = Mathematics::TriangleKey;
		using TriangleKeySet = std::set<TriangleKey>;
		using TriangleKeySetConstIter = TriangleKeySet::const_iterator;

	public:
		ClodMeshEdge() noexcept;

		CLASS_INVARIANT_DECLARE;

		void InsertTriangleKey(const TriangleKey& triangleKey);
		void EraseTriangleKey(const TriangleKey& triangleKey);
			 
		int GetTriangleKeySize() const noexcept;
	
		TriangleKeySetConstIter GetTriangleKeyBegin() const noexcept; 
		TriangleKeySetConstIter GetTriangleKeyEnd() const noexcept;

		int GetMinHeapRecordIndex() const noexcept;
		void SetMinHeapRecordIndex(int index) noexcept;

		const TriangleKey GetBeginTriangleKey() const;
		const TriangleKey GetEndTriangleKey() const;

	private:	
		TriangleKeySet m_AdjTriangles;
		int m_MinHeapRecordIndex;
	};
}

#endif // RENDERING_DETAIL_CLOD_MESH_EDGE_H
