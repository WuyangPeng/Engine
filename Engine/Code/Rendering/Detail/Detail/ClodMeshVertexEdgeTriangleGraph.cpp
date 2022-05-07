///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/09 19:21)

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

    // ��ÿһ����Ե�����������յ���������
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

    // ���������ε�ͼ�Ρ�
    triangles[triangleKey] = triangle;
}

// private
void Rendering::ClodMeshVertexEdgeTriangleGraph::InsertEdgeAndTriangle(const EdgeKey& edgeKey, const TriangleKey& triangleKey)
{
    const auto iter = edges.find(edgeKey);
    if (iter == edges.end())
    {
        // ���ǵ�һ���������������ͼ�β�����ѡ��������β��뵽�����ӱ�
        auto& edge = edges[edgeKey];
        edge.InsertTriangleKey(triangleKey);
        edge.SetMinHeapRecordIndex(heap.Insert(edgeKey, Mathematics::MathF::maxReal));
    }
    else
    {
        // ���Ѵ�����ͼ�Ρ��������β��뵽�����ӱ�
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

    // ɾ���������ӱ�������Ρ�
    vertices.at(triangleKey0).EraseTriangleKey(triangleKey);
    vertices.at(triangleKey1).EraseTriangleKey(triangleKey);
    vertices.at(triangleKey2).EraseTriangleKey(triangleKey);

    RemoveEdgeAndTriangle(firstEdgeKey, triangleKey);
    RemoveEdgeAndTriangle(secondEdgeKey, triangleKey);
    RemoveEdgeAndTriangle(thirdEdgeKey, triangleKey);

    // ��ͼ���н��������Ƴ�
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
            // ��Ե�����κ������ι��ã���˴Ӷ���ɾ����
            RENDERING_ASSERTION_2(heap.IsUniqueIndexValid(iter->second.GetMinHeapRecordIndex()), "�������\n");

            heap.Update(iter->second.GetMinHeapRecordIndex(), -1.0f);

            const auto record = heap.Remove();
            auto ekey = record.GetGenerator();
            MAYBE_UNUSED auto metric = record.GetValue();

            RENDERING_ASSERTION_2(Mathematics::MathF::Approximate(metric, -1.0f, 1e-8f), "������Ӧ��Ϊ-1��\n");

            // ɾ���ߵĶ˵�����ӱ�
            vertices.at(edgeKey.GetKey(0)).EraseEdgeKey(edgeKey);
            vertices.at(edgeKey.GetKey(1)).EraseEdgeKey(edgeKey);

            // ��ͼ����ɾ����
            edges.erase(edgeKey);
        }
    }
    else
    {
        RENDERING_ASSERTION_2(false, "�������\n");
    }
}

void Rendering::ClodMeshVertexEdgeTriangleGraph::ClassifyCollapsibleVertices()
{
    RENDERING_CLASS_IS_VALID_9;

    // TODO: ���Է����ζ��㡣
    // ��Щ���ܱ���������Ϊ�����������ֲ����ཻ����֮��������������������������
    // �����Ǽ���vertex.m_AdjTriangles�������ӵĲ�������Ŀ��
    // ���Ԫ������Ŀ����һ�������Ƿ����Ρ�

    // ���Զ��㣬��ȷ�������Ƿ�������ıߵı߽�Ķ˵㡣
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
    RENDERING_ASSERTION_2(heap.IsUniqueIndexValid(edge->second.GetMinHeapRecordIndex()), "�������\n");

    heap.Update(edge->second.GetMinHeapRecordIndex(), Mathematics::MathF::maxReal);
}

bool Rendering::ClodMeshVertexEdgeTriangleGraph::ValidResults(int numTriangles, int numVertices, int collapsesSize)
{
    RENDERING_CLASS_IS_VALID_9;

    // ����ʣ��������ε���������Щ����Ҫ����������������������
    if (numTriangles != 2 * collapsesSize + boost::numeric_cast<int>(triangles.size()))
    {
        RENDERING_ASSERTION_2(false, "����ȷ��������������\n");
        return false;
    }

    for (const auto& triangle : triangles)
    {
        trianglesRemaining.push_back(triangle.second);
    }

    // ����ʣ��Ķ������������Щ������Ҫ�Ķ��㻺������������
    auto i = 0;
    for (const auto& clodMeshVertex : vertices)
    {
        const auto hasEdges = (0 < clodMeshVertex.GetEdgeKeySize());
        const auto hasTriangles = (0 < clodMeshVertex.GetTriangleKeySize());
        if (hasEdges != hasTriangles)
        {
            RENDERING_ASSERTION_2(false, "��һ�µı����������ӡ�\n");
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
        RENDERING_ASSERTION_2(false, "����ȷ�Ķ�����Ŀ\n");
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
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ����ߵ�����"s));
    }
}

const Rendering::ClodMeshVertex& Rendering::ClodMeshVertexEdgeTriangleGraph::GetClodMeshVertex(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(vertices.size()), "����Խ�磡\n");

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
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ��������ε�����"s));
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