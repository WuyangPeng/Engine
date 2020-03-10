// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:40)

#include "Rendering/RenderingExport.h"

#include "ClodMeshVertexEdgeTriangleGraph.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"  

#include <boost/numeric/conversion/cast.hpp>

Rendering::ClodMeshVertexEdgeTriangleGraph
	::ClodMeshVertexEdgeTriangleGraph(int numVertices, int numIndices)
	: m_Vertices{ numVertices }, m_Edges{}, m_Triangles{},
	  m_Heap{ numIndices, 0, Mathematics::Mathf::sm_MaxReal }, m_VerticesRemaining{}, m_TrianglesRemaining{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshVertexEdgeTriangleGraph)

void Rendering::ClodMeshVertexEdgeTriangleGraph
	::InsertTriangle(const TriangleKey& triangleKey, Triangle triangle)
{
	RENDERING_CLASS_IS_VALID_9;

	auto triangleKey0 = triangleKey.GetKey(0);
	auto triangleKey1 = triangleKey.GetKey(1);
	auto triangleKey2 = triangleKey.GetKey(2);
	EdgeKey firstEdgeKey{ triangleKey0, triangleKey1 };
	EdgeKey secondEdgeKey{ triangleKey1, triangleKey2 };
	EdgeKey thirdEdgeKey{ triangleKey2, triangleKey0 };

	// ��ÿһ����Ե�����������յ���������
    m_Vertices[triangleKey0].InsertEdgeKey(firstEdgeKey);
	m_Vertices[triangleKey0].InsertEdgeKey(thirdEdgeKey);
	m_Vertices[triangleKey0].InsertTriangleKey(triangleKey);

	m_Vertices[triangleKey1].InsertEdgeKey(firstEdgeKey);
	m_Vertices[triangleKey1].InsertEdgeKey(secondEdgeKey);
	m_Vertices[triangleKey1].InsertTriangleKey(triangleKey);

	m_Vertices[triangleKey2].InsertEdgeKey(secondEdgeKey);
	m_Vertices[triangleKey2].InsertEdgeKey(thirdEdgeKey);
	m_Vertices[triangleKey2].InsertTriangleKey(triangleKey);

	InsertEdgeAndTriangle(firstEdgeKey, triangleKey);
	InsertEdgeAndTriangle(secondEdgeKey, triangleKey);
	InsertEdgeAndTriangle(thirdEdgeKey, triangleKey);	 

	// ���������ε�ͼ�Ρ�
	m_Triangles[triangleKey] = triangle;
}

// private
void Rendering::ClodMeshVertexEdgeTriangleGraph
	::InsertEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey)
{
	auto iter = m_Edges.find(edgeKey);
	if (iter == m_Edges.end())
	{
		// ���ǵ�һ���������������ͼ�β�����ѡ��������β��뵽�����ӱ�
		auto& edge = m_Edges[edgeKey];
		edge.InsertTriangleKey(triangleKey);
		edge.SetMinHeapRecordIndex(m_Heap.Insert(edgeKey, Mathematics::Mathf::sm_MaxReal));
	}
	else
	{		
		// ���Ѵ�����ͼ�Ρ��������β��뵽�����ӱ�
		iter->second.InsertTriangleKey(triangleKey);
	}
}


void Rendering::ClodMeshVertexEdgeTriangleGraph
	::RemoveTriangle(const TriangleKey& triangleKey)
{
	RENDERING_CLASS_IS_VALID_9;

	auto triangleKey0 = triangleKey.GetKey(0);
	auto triangleKey1 = triangleKey.GetKey(1);
	auto triangleKey2 = triangleKey.GetKey(2);
	EdgeKey firstEdgeKey{ triangleKey0, triangleKey1 };
	EdgeKey secondEdgeKey{ triangleKey1, triangleKey2 };
	EdgeKey thirdEdgeKey{ triangleKey2, triangleKey0 };

  	// ɾ���������ӱ�������Ρ�
	m_Vertices[triangleKey0].EraseTriangleKey(triangleKey);
	m_Vertices[triangleKey1].EraseTriangleKey(triangleKey);
	m_Vertices[triangleKey2].EraseTriangleKey(triangleKey);

	RemoveEdgeAndTriangle(firstEdgeKey, triangleKey);
	RemoveEdgeAndTriangle(secondEdgeKey, triangleKey);
	RemoveEdgeAndTriangle(thirdEdgeKey, triangleKey);	 

	// ��ͼ���н��������Ƴ�
    m_Triangles.erase(triangleKey);
}

// private
void Rendering::ClodMeshVertexEdgeTriangleGraph
	::RemoveEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey)
{
	auto iter = m_Edges.find(edgeKey);
	if (iter != m_Edges.end())
	{
		auto& edge = iter->second;
		edge.EraseTriangleKey(triangleKey);
		if (edge.GetTriangleKeySize() == 0)
		{		
			// ��Ե�����κ������ι��ã���˴Ӷ���ɾ����
			RENDERING_ASSERTION_2(m_Heap.IsUniqueIndexValid(iter->second.GetMinHeapRecordIndex()),  "�������\n");

			m_Heap.Update(iter->second.GetMinHeapRecordIndex(), -1.0f);

			auto record = m_Heap.Remove();
			auto ekey = record.GetGenerator();
			auto metric = record.GetValue();

			SYSTEM_UNUSED_ARG(metric);

			RENDERING_ASSERTION_2(Mathematics::Mathf::Approximate(metric, -1.0f, 1e-8f), "������Ӧ��Ϊ-1��\n");

			// ɾ���ߵĶ˵�����ӱ�
			m_Vertices[edgeKey.GetKey(0)].EraseEdgeKey(edgeKey);
			m_Vertices[edgeKey.GetKey(1)].EraseEdgeKey(edgeKey);

			// ��ͼ����ɾ����
			m_Edges.erase(edgeKey);
		}
	}
	else
	{
		RENDERING_ASSERTION_2(false, "�������\n");
	}
}

 
void Rendering::ClodMeshVertexEdgeTriangleGraph
	::ClassifyCollapsibleVertices()
{
	RENDERING_CLASS_IS_VALID_9;

	// TODO: ���Է����ζ��㡣
	// ��Щ���ܱ���������Ϊ�����������ֲ����ཻ����֮��������������������������
	// �����Ǽ���vertex.m_AdjTriangles�������ӵĲ�������Ŀ��
	// ���Ԫ������Ŀ����һ�������Ƿ����Ρ�

 	// ���Զ��㣬��ȷ�������Ƿ�������ıߵı߽�Ķ˵㡣
	for(auto& vertex:m_Vertices)
    {     		 
		for (auto outerIter = vertex.GetEdgeKeyBegin(), end = vertex.GetEdgeKeyEnd(); outerIter != end;++outerIter)
        {
			auto innerIter = m_Edges.find(*outerIter);
            if (innerIter->second.GetTriangleKeySize() != 2)
            {
                vertex.SetCollapsible(false);
                break;
            }
        }
    } 
}

void Rendering::ClodMeshVertexEdgeTriangleGraph
	::UpdateEdgeHeapToMaxReal(const EdgeKey& edgeKey)
{
	RENDERING_CLASS_IS_VALID_9;

	auto edge = m_Edges.find(edgeKey);
	RENDERING_ASSERTION_2(m_Heap.IsUniqueIndexValid(edge->second.GetMinHeapRecordIndex()), "�������\n");

	m_Heap.Update(edge->second.GetMinHeapRecordIndex(), Mathematics::Mathf::sm_MaxReal);
}

bool Rendering::ClodMeshVertexEdgeTriangleGraph
	::ValidResults(int numTriangles, int numVertices,int collapsesSize)
{
	RENDERING_CLASS_IS_VALID_9;

	// ����ʣ��������ε���������Щ����Ҫ����������������������
	if (numTriangles != boost::numeric_cast<int>(2 * collapsesSize + m_Triangles.size()))
    {
		RENDERING_ASSERTION_2(false, "����ȷ��������������\n");
        return false;
    }

	for(const auto& triangle: m_Triangles)
	{
		m_TrianglesRemaining.push_back(triangle.second);
	}

	// ����ʣ��Ķ������������Щ������Ҫ�Ķ��㻺������������
	int i = 0;
	for (const auto& clodMeshVertex : m_Vertices)
	{
		auto hasEdges = (0 < clodMeshVertex.GetEdgeKeySize());
		auto hasTriangles = (0 < clodMeshVertex.GetTriangleKeySize());
		if (hasEdges != hasTriangles)
		{
			RENDERING_ASSERTION_2(false, "��һ�µı����������ӡ�\n");
			return false;
		}

		if (0 < clodMeshVertex.GetEdgeKeySize())
		{
			m_VerticesRemaining.push_back(i);
		}

		++i;
	}
   
	if (numVertices != boost::numeric_cast<int>(collapsesSize + m_VerticesRemaining.size()))
    {
		RENDERING_ASSERTION_2(false, "����ȷ�Ķ�����Ŀ\n");
        return false;
    }

    return true;
}

const Rendering::ClodMeshEdge& Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetClodMeshEdge(const EdgeKey& edgeKey) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto iter = m_Edges.find(edgeKey);

	if (iter != m_Edges.end())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ����ߵ�����"));
	}	 
}

const Rendering::ClodMeshVertex& Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetClodMeshVertex(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "����Խ�磡\n");

	return m_Vertices[index];
}

Rendering::ClodMeshVertexEdgeTriangleGraph::Triangle Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetTriangle(const TriangleKey& triangleKey) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto iter = m_Triangles.find(triangleKey);

	if (iter != m_Triangles.end())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ��������ε�����"));
	}
}

Rendering::ClodMeshVertexEdgeTriangleGraph::EdgeMapConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetEdgeMapBegin() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Edges.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::EdgeMapConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetEdgeMapEnd() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Edges.end();
}

int Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetMinHeapElementsNumber() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Heap.GetElementsNumber();
}

void Rendering::ClodMeshVertexEdgeTriangleGraph
	::UpdateEdgeHeap(int recordIndex, float metric)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Heap.Update(recordIndex,metric);
}

const Rendering::ClodMeshVertexEdgeTriangleGraph::MinHeapRecord Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetMinHeapMinimum() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	
	return m_Heap.GetMinimum();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetVerticesRemainingBegin() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VerticesRemaining.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetVerticesRemainingEnd() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VerticesRemaining.end();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetTrianglesRemainingBegin() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_TrianglesRemaining.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetTrianglesRemainingEnd() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_TrianglesRemaining.end();
}

bool Rendering::ClodMeshVertexEdgeTriangleGraph
	::IsUniqueIndexValid(int minHeapRecordIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Heap.IsUniqueIndexValid(minHeapRecordIndex);
}
