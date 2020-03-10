// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:20)

#ifndef RENDERING_DETAIL_CLOD_MESH_TRIANGLE_MESH_H
#define RENDERING_DETAIL_CLOD_MESH_TRIANGLE_MESH_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBufferAccessor.h"

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ClodMeshTriangleMesh
	{
	public:
		using ClassType = ClodMeshTriangleMesh;
		
	public:
		explicit ClodMeshTriangleMesh(TrianglesMeshSmartPointer mesh);

		CLASS_INVARIANT_DECLARE;

		int GetNumVertices() const;
		int GetNumIndices() const;
		int GetNumTriangles() const;

		bool ValidBuffers() const;
		const int* GetIndexBufferReadOnlyData() const;

		const Mathematics::Vector3Df GetPosition(int index) const;

		const char* GetVertexBufferReadOnlyData() const;
		int GetStride() const;

		void SetNewVertexBufferData(const std::vector<char>& newData);
		void SetNewIndexBufferData(const std::vector<char>& newData);
	
	private:
		// 三角网络数据抽取。
		int m_NumVertices;
		int m_NumIndices;
		int m_NumTriangles;
		IndexBufferSmartPointer m_IndixBuffer;
		VertexBufferSmartPointer m_VertexBuffer;
		VertexBufferAccessor m_VertexBufferAccessor;
	};
}

#endif // RENDERING_DETAIL_CLOD_MESH_TRIANGLE_MESH_H
