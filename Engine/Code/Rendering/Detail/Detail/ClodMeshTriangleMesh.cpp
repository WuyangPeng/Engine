// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:38)

#include "Rendering/RenderingExport.h"

#include "ClodMeshTriangleMesh.h"
#include "Mathematics/Meshes/TriangleKey.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

#include <boost/numeric/conversion/cast.hpp>
#include <set>

using std::set;

Rendering::ClodMeshTriangleMesh
	::ClodMeshTriangleMesh(TrianglesMeshSmartPointer mesh)
	: m_NumVertices{ mesh->GetVertexBuffer()->GetNumElements() },m_NumIndices{ mesh->GetIndexBuffer()->GetNumElements() },m_NumTriangles{ m_NumIndices / 3 },
	  m_IndixBuffer{ mesh->GetIndexBuffer() },m_VertexBuffer{ mesh->GetVertexBuffer() },m_VertexBufferAccessor{ mesh.GetData() }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshTriangleMesh)

int Rendering::ClodMeshTriangleMesh
	::GetNumVertices() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_NumVertices;
}

int Rendering::ClodMeshTriangleMesh
	::GetNumIndices() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_NumIndices;
}

bool Rendering::ClodMeshTriangleMesh
	::ValidBuffers() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	using TriangleKeySet = set<Mathematics::TriangleKey>;
	TriangleKeySet triangles;
	std::set<int> vertexIndices;
	auto currentIndex = GetIndexBufferReadOnlyData();

	for (auto trianglesIndex = 0; trianglesIndex < m_NumTriangles; ++trianglesIndex)
	{
		auto firstIndex = *currentIndex++;
		auto secondIndex = *currentIndex++;
		auto thirdIndex = *currentIndex++;
		if (firstIndex == secondIndex || firstIndex == thirdIndex || secondIndex == thirdIndex)
		{
			// 现在，输入应该来自三角网格或三角扇。
			// 边折叠算法必须进行修改，以应对为其退化添加三角形（以产生长条）的三角形带。
			RENDERING_ASSERTION_2(false, "退化三角形是不允许的。\n");
			return false;
		}

		vertexIndices.insert(firstIndex);
		vertexIndices.insert(secondIndex);
		vertexIndices.insert(thirdIndex);

		auto result = triangles.insert(Mathematics::TriangleKey(firstIndex, secondIndex, thirdIndex));

		if (result.second == false)
		{
			// 索引缓冲区包含重复三角形。边折叠算法不被设计来处理重复。
			RENDERING_ASSERTION_2(false, "索引缓冲区包含重复三角形。\n");
			return false;
		}
	}

	// 测试一个有效的顶点缓冲区
	if (boost::numeric_cast<int>(vertexIndices.size()) < m_NumVertices || m_NumVertices != (*vertexIndices.rbegin() + 1))
	{
		// 如果下面的断言被触发时，顶点缓冲器具有不被索引缓冲器引用的顶点。
		// 这是一个问题，因为在顶点缓冲器是基于边折叠的顺序重新排序。
		// 引用输入顶点缓冲在任何其他索引缓冲区现在是无效的。
		RENDERING_ASSERTION_2(false, "索引缓冲区没有引用的所有顶点。\n");
		return false;
	}

	return true;
}

const int* Rendering::ClodMeshTriangleMesh
	::GetIndexBufferReadOnlyData() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return  reinterpret_cast<const int*>(m_IndixBuffer->GetReadOnlyData());
}

int Rendering::ClodMeshTriangleMesh
	::GetNumTriangles() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_NumTriangles;
}

const Mathematics::Vector3Df Rendering::ClodMeshTriangleMesh
	::GetPosition(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexBufferAccessor.GetPosition<Mathematics::Vector3Df>(index);
}

const char* Rendering::ClodMeshTriangleMesh
	::GetVertexBufferReadOnlyData() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return  m_VertexBufferAccessor.GetData();
}

int Rendering::ClodMeshTriangleMesh
	::GetStride() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return  m_VertexBufferAccessor.GetStride();
}

void Rendering::ClodMeshTriangleMesh
	::SetNewVertexBufferData(const std::vector<char>& newData)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexBuffer->SetNewData(newData);
}

void Rendering::ClodMeshTriangleMesh
	::SetNewIndexBufferData(const std::vector<char>& newData)
{
	RENDERING_CLASS_IS_VALID_9;

	m_IndixBuffer->SetNewData(newData);
}

