// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:38)

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
			// ���ڣ�����Ӧ��������������������ȡ�
			// ���۵��㷨��������޸ģ���Ӧ��Ϊ���˻���������Σ��Բ����������������δ���
			RENDERING_ASSERTION_2(false, "�˻��������ǲ�����ġ�\n");
			return false;
		}

		vertexIndices.insert(firstIndex);
		vertexIndices.insert(secondIndex);
		vertexIndices.insert(thirdIndex);

		auto result = triangles.insert(Mathematics::TriangleKey(firstIndex, secondIndex, thirdIndex));

		if (result.second == false)
		{
			// ���������������ظ������Ρ����۵��㷨��������������ظ���
			RENDERING_ASSERTION_2(false, "���������������ظ������Ρ�\n");
			return false;
		}
	}

	// ����һ����Ч�Ķ��㻺����
	if (boost::numeric_cast<int>(vertexIndices.size()) < m_NumVertices || m_NumVertices != (*vertexIndices.rbegin() + 1))
	{
		// �������Ķ��Ա�����ʱ�����㻺�������в����������������õĶ��㡣
		// ����һ�����⣬��Ϊ�ڶ��㻺�����ǻ��ڱ��۵���˳����������
		// �������붥�㻺�����κ�����������������������Ч�ġ�
		RENDERING_ASSERTION_2(false, "����������û�����õ����ж��㡣\n");
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

