// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:40)

#include "Rendering/RenderingExport.h"

#include "ClodMeshVertexEdgeTriangleGraph.h"

#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"  

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
Rendering::ClodMeshVertexEdgeTriangleGraph
	::ClodMeshVertexEdgeTriangleGraph(int numVertices, int numIndices)
	: m_Vertices{ numVertices }, m_Edges{}, m_Triangles{},
      m_Heap{ numIndices, 0, Mathematics::MathF::maxReal }, m_VerticesRemaining{}, m_TrianglesRemaining{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshVertexEdgeTriangleGraph)

void Rendering::ClodMeshVertexEdgeTriangleGraph
	::InsertTriangle(const TriangleKey& triangleKey, Triangle triangle)
{
	RENDERING_CLASS_IS_VALID_9;

	const auto triangleKey0 = triangleKey.GetKey(0);
	const auto triangleKey1 = triangleKey.GetKey(1);
	const auto triangleKey2 = triangleKey.GetKey(2);
	const EdgeKey firstEdgeKey{ triangleKey0, triangleKey1 };
	const EdgeKey secondEdgeKey{ triangleKey1, triangleKey2 };
	const EdgeKey thirdEdgeKey{ triangleKey2, triangleKey0 };

	// 将每一个边缘到插入它的终点连接链表
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

	// 插入三角形到图形。
	m_Triangles[triangleKey] = triangle;
}

// private
void Rendering::ClodMeshVertexEdgeTriangleGraph
	::InsertEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey)
{
    const auto iter = m_Edges.find(edgeKey);
	if (iter == m_Edges.end())
	{
		// 边是第一次遇到。将其插入图形并加入堆。将三角形插入到其链接表。
		auto& edge = m_Edges[edgeKey];
		edge.InsertTriangleKey(triangleKey);
		edge.SetMinHeapRecordIndex(m_Heap.Insert(edgeKey, Mathematics::MathF::maxReal));
	}
	else
	{		
		// 边已存在于图形。将三角形插入到其链接表。
		iter->second.InsertTriangleKey(triangleKey);
	}
}


void Rendering::ClodMeshVertexEdgeTriangleGraph
	::RemoveTriangle(const TriangleKey& triangleKey)
{
	RENDERING_CLASS_IS_VALID_9;

	const auto triangleKey0 = triangleKey.GetKey(0);
	const auto triangleKey1 = triangleKey.GetKey(1);
	const auto triangleKey2 = triangleKey.GetKey(2);
	const EdgeKey firstEdgeKey{ triangleKey0, triangleKey1 };
	const EdgeKey secondEdgeKey{ triangleKey1, triangleKey2 };
	const EdgeKey thirdEdgeKey{ triangleKey2, triangleKey0 };

  	// 删除顶点连接表的三角形。
	m_Vertices[triangleKey0].EraseTriangleKey(triangleKey);
	m_Vertices[triangleKey1].EraseTriangleKey(triangleKey);
	m_Vertices[triangleKey2].EraseTriangleKey(triangleKey);

	RemoveEdgeAndTriangle(firstEdgeKey, triangleKey);
	RemoveEdgeAndTriangle(secondEdgeKey, triangleKey);
	RemoveEdgeAndTriangle(thirdEdgeKey, triangleKey);	 

	// 从图形中将三角形移除
    m_Triangles.erase(triangleKey);
}

// private
void Rendering::ClodMeshVertexEdgeTriangleGraph
	::RemoveEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey)
{
    const auto iter = m_Edges.find(edgeKey);
	if (iter != m_Edges.end())
	{
		auto& edge = iter->second;
		edge.EraseTriangleKey(triangleKey);
		if (edge.GetTriangleKeySize() == 0)
		{		
			// 边缘不被任何三角形共用，因此从堆中删除。
			RENDERING_ASSERTION_2(m_Heap.IsUniqueIndexValid(iter->second.GetMinHeapRecordIndex()),  "意外情况\n");

			m_Heap.Update(iter->second.GetMinHeapRecordIndex(), -1.0f);

			const auto record = m_Heap.Remove();
			auto ekey = record.GetGenerator();
                        [[maybe_unused]] auto metric = record.GetValue();

			 

			RENDERING_ASSERTION_2(Mathematics::MathF::Approximate(metric, -1.0f, 1e-8f), "该试题应该为-1。\n");

			// 删除边的端点的连接表。
			m_Vertices[edgeKey.GetKey(0)].EraseEdgeKey(edgeKey);
			m_Vertices[edgeKey.GetKey(1)].EraseEdgeKey(edgeKey);

			// 从图形中删除边
			m_Edges.erase(edgeKey);
		}
	}
	else
	{
		RENDERING_ASSERTION_2(false, "意外情况\n");
	}
}

 
void Rendering::ClodMeshVertexEdgeTriangleGraph
	::ClassifyCollapsibleVertices()
{
	RENDERING_CLASS_IS_VALID_9;

	// TODO: 测试非流形顶点。
	// 这些不能被收缩，因为他们是两名局部不相交子网之间的桥梁（按边三角形连接项）。
	// 测试是计算vertex.m_AdjTriangles本地连接的部件的数目。
	// 如果元件的数目大于一，顶点是非流形。

 	// 测试顶点，以确定它们是否在网格的边的边界的端点。
	for(auto& vertex:m_Vertices)
    {     		 
		const auto end = vertex.GetEdgeKeyEnd();
		for (auto outerIter = vertex.GetEdgeKeyBegin() ; outerIter != end;++outerIter)
        {
			const auto innerIter = m_Edges.find(*outerIter);
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

	const auto edge = m_Edges.find(edgeKey);
	RENDERING_ASSERTION_2(m_Heap.IsUniqueIndexValid(edge->second.GetMinHeapRecordIndex()), "意外情况\n");

	m_Heap.Update(edge->second.GetMinHeapRecordIndex(), Mathematics::MathF::maxReal);
}

bool Rendering::ClodMeshVertexEdgeTriangleGraph
	::ValidResults(int numTriangles, int numVertices,int collapsesSize)
{
	RENDERING_CLASS_IS_VALID_9;

	// 保存剩余的三角形的索引。这些都需要在索引缓冲器中重新排序。
	if (numTriangles != boost::numeric_cast<int>(2 * collapsesSize + m_Triangles.size()))
    {
		RENDERING_ASSERTION_2(false, "不正确的三角形数量。\n");
        return false;
    }

	for(const auto& triangle: m_Triangles)
	{
		m_TrianglesRemaining.push_back(triangle.second);
	}

	// 保存剩余的顶点的索引。这些都是需要的顶点缓冲中重新排序。
	int i = 0;
	for (const auto& clodMeshVertex : m_Vertices)
	{
		const auto hasEdges = (0 < clodMeshVertex.GetEdgeKeySize());
		const auto hasTriangles = (0 < clodMeshVertex.GetTriangleKeySize());
		if (hasEdges != hasTriangles)
		{
			RENDERING_ASSERTION_2(false, "不一致的边三角形连接。\n");
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
		RENDERING_ASSERTION_2(false, "不正确的顶点数目\n");
        return false;
    }

    return true;
}

const Rendering::ClodMeshEdge& Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetClodMeshEdge(const EdgeKey& edgeKey) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	const auto iter = m_Edges.find(edgeKey);

	if (iter != m_Edges.end())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("找不到边的数据"s));
	}	 
}

const Rendering::ClodMeshVertex& Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetClodMeshVertex(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Vertices.size()), "索引越界！\n");

	return m_Vertices[index];
}

Rendering::ClodMeshVertexEdgeTriangleGraph::Triangle Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetTriangle(const TriangleKey& triangleKey) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	const auto iter = m_Triangles.find(triangleKey);

	if (iter != m_Triangles.end())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("找不到三角形的数据"s));
	}
}

Rendering::ClodMeshVertexEdgeTriangleGraph::EdgeMapConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetEdgeMapBegin() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Edges.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::EdgeMapConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetEdgeMapEnd() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Edges.end();
}

int Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetMinHeapElementsNumber() const noexcept
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
	::GetVerticesRemainingBegin() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VerticesRemaining.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetVerticesRemainingEnd() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VerticesRemaining.end();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetTrianglesRemainingBegin() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_TrianglesRemaining.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph
	::GetTrianglesRemainingEnd() const noexcept
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
#include STSTEM_WARNING_POP