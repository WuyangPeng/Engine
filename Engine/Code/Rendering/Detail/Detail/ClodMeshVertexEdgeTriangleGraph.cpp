///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/09 19:21)

#include "Rendering/RenderingExport.h"

#include "ClodMeshVertexEdgeTriangleGraph.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::ClodMeshVertexEdgeTriangleGraph::ClodMeshVertexEdgeTriangleGraph(int numVertices, int numIndices)
    : vertices{ numVertices },
      edges{},
      triangles{},
      heap{ numIndices, 0, Mathematics::MathF::maxReal },
      verticesRemaining{},
      trianglesRemaining{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshVertexEdgeTriangleGraph)

void Rendering::ClodMeshVertexEdgeTriangleGraph::InsertTriangle(const TriangleKey& triangleKey, Triangle triangle)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto triangleKey0 = triangleKey.GetKey(0);
    const auto triangleKey1 = triangleKey.GetKey(1);
    const auto triangleKey2 = triangleKey.GetKey(2);
    const EdgeKey firstEdgeKey{ triangleKey0, triangleKey1 };
    const EdgeKey secondEdgeKey{ triangleKey1, triangleKey2 };
    const EdgeKey thirdEdgeKey{ triangleKey2, triangleKey0 };

    // 将每一个边缘到插入它的终点连接链表
    vertices.at(triangleKey0).InsertEdgeKey(firstEdgeKey);
    vertices.at(triangleKey0).InsertEdgeKey(thirdEdgeKey);
    vertices.at(triangleKey0).InsertTriangleKey(triangleKey);

    vertices.at(triangleKey1).InsertEdgeKey(firstEdgeKey);
    vertices.at(triangleKey1).InsertEdgeKey(secondEdgeKey);
    vertices.at(triangleKey1).InsertTriangleKey(triangleKey);

    vertices.at(triangleKey2).InsertEdgeKey(secondEdgeKey);
    vertices.at(triangleKey2).InsertEdgeKey(thirdEdgeKey);
    vertices.at(triangleKey2).InsertTriangleKey(triangleKey);

    InsertEdgeAndTriangle(firstEdgeKey, triangleKey);
    InsertEdgeAndTriangle(secondEdgeKey, triangleKey);
    InsertEdgeAndTriangle(thirdEdgeKey, triangleKey);

    // 插入三角形到图形。
    triangles[triangleKey] = triangle;
}

// private
void Rendering::ClodMeshVertexEdgeTriangleGraph::InsertEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey)
{
    const auto iter = edges.find(edgeKey);
    if (iter == edges.end())
    {
        // 边是第一次遇到。将其插入图形并加入堆。将三角形插入到其链接表。
        auto& edge = edges[edgeKey];
        edge.InsertTriangleKey(triangleKey);
        edge.SetMinHeapRecordIndex(heap.Insert(edgeKey, Mathematics::MathF::maxReal));
    }
    else
    {
        // 边已存在于图形。将三角形插入到其链接表。
        iter->second.InsertTriangleKey(triangleKey);
    }
}

void Rendering::ClodMeshVertexEdgeTriangleGraph::RemoveTriangle(const TriangleKey& triangleKey)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto triangleKey0 = triangleKey.GetKey(0);
    const auto triangleKey1 = triangleKey.GetKey(1);
    const auto triangleKey2 = triangleKey.GetKey(2);
    const EdgeKey firstEdgeKey{ triangleKey0, triangleKey1 };
    const EdgeKey secondEdgeKey{ triangleKey1, triangleKey2 };
    const EdgeKey thirdEdgeKey{ triangleKey2, triangleKey0 };

    // 删除顶点连接表的三角形。
    vertices.at(triangleKey0).EraseTriangleKey(triangleKey);
    vertices.at(triangleKey1).EraseTriangleKey(triangleKey);
    vertices.at(triangleKey2).EraseTriangleKey(triangleKey);

    RemoveEdgeAndTriangle(firstEdgeKey, triangleKey);
    RemoveEdgeAndTriangle(secondEdgeKey, triangleKey);
    RemoveEdgeAndTriangle(thirdEdgeKey, triangleKey);

    // 从图形中将三角形移除
    triangles.erase(triangleKey);
}

// private
void Rendering::ClodMeshVertexEdgeTriangleGraph::RemoveEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey)
{
    const auto iter = edges.find(edgeKey);
    if (iter != edges.end())
    {
        auto& edge = iter->second;
        edge.EraseTriangleKey(triangleKey);
        if (edge.GetTriangleKeySize() == 0)
        {
            // 边缘不被任何三角形共用，因此从堆中删除。
            RENDERING_ASSERTION_2(heap.IsUniqueIndexValid(iter->second.GetMinHeapRecordIndex()), "意外情况\n");

            heap.Update(iter->second.GetMinHeapRecordIndex(), -1.0f);

            const auto record = heap.Remove();
            auto ekey = record.GetGenerator();
            MAYBE_UNUSED auto metric = record.GetValue();

            RENDERING_ASSERTION_2(Mathematics::MathF::Approximate(metric, -1.0f, 1e-8f), "该试题应该为-1。\n");

            // 删除边的端点的连接表。
            vertices.at(edgeKey.GetKey(0)).EraseEdgeKey(edgeKey);
            vertices.at(edgeKey.GetKey(1)).EraseEdgeKey(edgeKey);

            // 从图形中删除边
            edges.erase(edgeKey);
        }
    }
    else
    {
        RENDERING_ASSERTION_2(false, "意外情况\n");
    }
}

void Rendering::ClodMeshVertexEdgeTriangleGraph::ClassifyCollapsibleVertices()
{
    RENDERING_CLASS_IS_VALID_9;

    // TODO: 测试非流形顶点。
    // 这些不能被收缩，因为他们是两名局部不相交子网之间的桥梁（按边三角形连接项）。
    // 测试是计算vertex.m_AdjTriangles本地连接的部件的数目。
    // 如果元件的数目大于一，顶点是非流形。

    // 测试顶点，以确定它们是否在网格的边的边界的端点。
    for (auto& vertex : vertices)
    {
        const auto end = vertex.GetEdgeKeyEnd();
        for (auto outerIter = vertex.GetEdgeKeyBegin(); outerIter != end; ++outerIter)
        {
            const auto innerIter = edges.find(*outerIter);
            if (innerIter->second.GetTriangleKeySize() != 2)
            {
                vertex.SetCollapsible(false);
                break;
            }
        }
    }
}

void Rendering::ClodMeshVertexEdgeTriangleGraph::UpdateEdgeHeapToMaxReal(const EdgeKey& edgeKey)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto edge = edges.find(edgeKey);
    RENDERING_ASSERTION_2(heap.IsUniqueIndexValid(edge->second.GetMinHeapRecordIndex()), "意外情况\n");

    heap.Update(edge->second.GetMinHeapRecordIndex(), Mathematics::MathF::maxReal);
}

bool Rendering::ClodMeshVertexEdgeTriangleGraph::ValidResults(int numTriangles, int numVertices, int collapsesSize)
{
    RENDERING_CLASS_IS_VALID_9;

    // 保存剩余的三角形的索引。这些都需要在索引缓冲器中重新排序。
    if (numTriangles != 2 * collapsesSize + boost::numeric_cast<int>(triangles.size()))
    {
        RENDERING_ASSERTION_2(false, "不正确的三角形数量。\n");
        return false;
    }

    for (const auto& triangle : triangles)
    {
        trianglesRemaining.push_back(triangle.second);
    }

    // 保存剩余的顶点的索引。这些都是需要的顶点缓冲中重新排序。
    auto i = 0;
    for (const auto& clodMeshVertex : vertices)
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
            verticesRemaining.emplace_back(i);
        }

        ++i;
    }

    if (numVertices != boost::numeric_cast<int>(collapsesSize + verticesRemaining.size()))
    {
        RENDERING_ASSERTION_2(false, "不正确的顶点数目\n");
        return false;
    }

    return true;
}

const Rendering::ClodMeshEdge& Rendering::ClodMeshVertexEdgeTriangleGraph::GetClodMeshEdge(const EdgeKey& edgeKey) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto iter = edges.find(edgeKey);

    if (iter != edges.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到边的数据"s));
    }
}

const Rendering::ClodMeshVertex& Rendering::ClodMeshVertexEdgeTriangleGraph::GetClodMeshVertex(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(vertices.size()), "索引越界！\n");

    return vertices.at(index);
}

Rendering::ClodMeshVertexEdgeTriangleGraph::Triangle Rendering::ClodMeshVertexEdgeTriangleGraph::GetTriangle(const TriangleKey& triangleKey) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto iter = triangles.find(triangleKey);

    if (iter != triangles.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到三角形的数据"s));
    }
}

Rendering::ClodMeshVertexEdgeTriangleGraph::EdgeMapConstIter Rendering::ClodMeshVertexEdgeTriangleGraph::GetEdgeMapBegin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return edges.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::EdgeMapConstIter Rendering::ClodMeshVertexEdgeTriangleGraph::GetEdgeMapEnd() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return edges.end();
}

int Rendering::ClodMeshVertexEdgeTriangleGraph::GetMinHeapElementsNumber() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return heap.GetElementsNumber();
}

void Rendering::ClodMeshVertexEdgeTriangleGraph::UpdateEdgeHeap(int recordIndex, float metric)
{
    RENDERING_CLASS_IS_VALID_9;

    heap.Update(recordIndex, metric);
}

Rendering::ClodMeshVertexEdgeTriangleGraph::MinHeapRecord Rendering::ClodMeshVertexEdgeTriangleGraph::GetMinHeapMinimum() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return heap.GetMinimum();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph::GetVerticesRemainingBegin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return verticesRemaining.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph::GetVerticesRemainingEnd() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return verticesRemaining.end();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph::GetTrianglesRemainingBegin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return trianglesRemaining.begin();
}

Rendering::ClodMeshVertexEdgeTriangleGraph::RemainingConstIter Rendering::ClodMeshVertexEdgeTriangleGraph::GetTrianglesRemainingEnd() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return trianglesRemaining.end();
}

bool Rendering::ClodMeshVertexEdgeTriangleGraph::IsUniqueIndexValid(int minHeapRecordIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return heap.IsUniqueIndexValid(minHeapRecordIndex);
}