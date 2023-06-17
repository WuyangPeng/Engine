///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:53)

#include "Rendering/RenderingExport.h"

#include "CreateClodMeshImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

Rendering::CreateClodMeshImpl::CreateClodMeshImpl(TrianglesMesh& mesh)
    : clodMeshTriangleMesh{ mesh }, graph{ clodMeshTriangleMesh.GetNumVertices(), clodMeshTriangleMesh.GetNumIndices() }, collapses{}, collapseRecord{}
{
    Compute();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CreateClodMeshImpl)

Rendering::CollapseRecordArraySharedPtr Rendering::CreateClodMeshImpl::GetCollapseRecordArray() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CollapseRecordArraySharedPtr{ std::make_shared<CollapseRecordArray>(collapseRecord) };
}

// private
void Rendering::CreateClodMeshImpl::Compute()
{
    // ȷ���������������������Ч�ڱ�Ե�۵���
    if (!clodMeshTriangleMesh.ValidBuffers())
    {
        return;
    }

    // �������㡪���ߡ���������ͼ��
    CreateVertexEdgeTriangleGraph();

    // �����Ǳ߽߱�Ķ˵㣬���Ƿ����Σ�
    // �����������������������ӵ���������������������
    graph.ClassifyCollapsibleVertices();

    // ���±ߵĶѡ�
    for (auto iter = graph.GetEdgeMapBegin(); iter != graph.GetEdgeMapEnd(); ++iter)
    {
        RENDERING_ASSERTION_2(graph.IsUniqueIndexValid(iter->second.GetMinHeapRecordIndex()), "���������\n");
        graph.UpdateEdgeHeap(iter->second.GetMinHeapRecordIndex(), ComputeMetric(iter->first));
    }

    while (0 < graph.GetMinHeapElementsNumber())
    {
        const auto record = graph.GetMinHeapMinimum();
        auto ekey = record.GetGenerator();
        auto metric = record.GetValue();

        if (Mathematics::MathF::Approximate(metric, Mathematics::MathF::maxReal, 1e-8f))
        {
            // ����ʣ��Ķ�Ԫ�ض������޵�ֵ��
            if (!ValidResults())
            {
                return;
            }
            break;
        }

        const auto indexThrow = CanCollapse(ekey);
        if (0 <= indexThrow)
        {
            Collapse(ekey, indexThrow);
        }
        else
        {
            graph.UpdateEdgeHeapToMaxReal(ekey);
        }
    }

    // �������򶥵㻺�������������ɱ߱���ȥ����ʱ��������С�
    // ���磬��һ�����߱����Ƴ��Ķ������ڻ������е����һ�����㡣
    // �����������������������������ɱ߱���ȥ����ʱ��������С�
    // ���磬��һ�����߱����Ƴ������������ڻ������е����һ�������Ρ�
    ReorderBuffers();

    // ������¼�洢�����仯���ڶ�̬LOD�仯��
    ComputeRecords();
}

// private
void Rendering::CreateClodMeshImpl::CreateVertexEdgeTriangleGraph()
{
    auto currentIndex = clodMeshTriangleMesh.GetIndexBufferReadOnlyData();

    if (currentIndex == nullptr)
    {
        return;
    }

    for (auto trianglesIndex = 0; trianglesIndex < clodMeshTriangleMesh.GetNumTriangles(); ++trianglesIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        const auto first = *currentIndex++;
        const auto second = *currentIndex++;
        const auto third = *currentIndex++;

#include STSTEM_WARNING_POP

        const TriangleKey triangleKey{ first, second, third };

        graph.InsertTriangle(triangleKey, trianglesIndex);
    }
}

float Rendering::CreateClodMeshImpl::ComputeMetric(const EdgeKey& edgeKey)
{
    // ��ЩȨ�ؿ��Ե��������κ���ϲ����ֵ��
    constexpr auto lengthWeight = 10.0f;
    constexpr auto angleWeight = 1.0f;

    // ����ı�Եָ�ꡣֻ�ж��ֵı�Ե���������������ι���ߣ������������
    const auto& edge = graph.GetClodMeshEdge(edgeKey);
    if (edge.GetTriangleKeySize() == 2)
    {
        // ���ȵĹ��ס�
        const auto end0 = clodMeshTriangleMesh.GetPosition(edgeKey.GetKey(0));
        const auto end1 = clodMeshTriangleMesh.GetPosition(edgeKey.GetKey(1));
        auto difference = end1 - end0;
        auto metric = lengthWeight * Mathematics::Vector3ToolsF::GetLength(difference);

        // �Ƕ�/����Ĺ��ס�
        auto triangleKey = edge.GetBeginTriangleKey();
        const auto beginNormal = GetNormal(triangleKey);

        triangleKey = edge.GetEndTriangleKey();
        const auto endNormal = GetNormal(triangleKey);

        const auto cross = Mathematics::Vector3ToolsF::CrossProduct(beginNormal, endNormal);
        metric += angleWeight * Mathematics::Vector3ToolsF::GetLength(cross);

        return metric;
    }

    // �ߵı߽磨���бߵ�һ�������Σ��ͽ��ӱ�Ե��3�������������ι��ñߣ������������
    return Mathematics::MathF::maxReal;
}

Mathematics::Vector3F Rendering::CreateClodMeshImpl::GetNormal(const TriangleKey& triangleKey)
{
    const auto position0 = clodMeshTriangleMesh.GetPosition(triangleKey.GetKey(0));
    const auto position1 = clodMeshTriangleMesh.GetPosition(triangleKey.GetKey(1));
    const auto position2 = clodMeshTriangleMesh.GetPosition(triangleKey.GetKey(2));
    auto edgeDirection0 = position1 - position0;
    auto edgeDirection1 = position2 - position0;

    return Mathematics::Vector3ToolsF::CrossProduct(edgeDirection0, edgeDirection1);
}

int Rendering::CreateClodMeshImpl::CanCollapse(const EdgeKey& edgeKey)
{
    const auto& vertex0 = graph.GetClodMeshVertex(edgeKey.GetKey(0));
    const auto& vertex1 = graph.GetClodMeshVertex(edgeKey.GetKey(1));

    // �����Ƿ�ɱ���
    auto indexKeep = 0;
    auto indexThrow = 0;
    if (vertex0.IsCollapsible())
    {
        indexKeep = 1;
        indexThrow = 0;
    }
    else if (vertex1.IsCollapsible())
    {
        indexKeep = 0;
        indexThrow = 1;
    }
    else
    {
        return -1;
    }

    // �����������״���۵����������ܱ�����ġ�
    const auto vKeep = edgeKey.GetKey(indexKeep);
    const auto vThrow = edgeKey.GetKey(indexThrow);
    const auto& vertexThrow = graph.GetClodMeshVertex(vThrow);
    const auto positionKeep = clodMeshTriangleMesh.GetPosition(vKeep);
    const auto positionThrow = clodMeshTriangleMesh.GetPosition(vThrow);

    for (auto iter = vertexThrow.GetTriangleKeyBegin(); iter != vertexThrow.GetTriangleKeyEnd(); ++iter)
    {
        const auto& trianglKey = *iter;

        // ����Ϊ��ʹ��CCW��ʱ��˳���������εĶ���ȷ����ƽ��ķ���������
        const auto middleIndex = trianglKey.GetKeyIndex(vThrow);
        const auto minusIndex = (middleIndex + 2) % 3;
        const auto plusIndex = (middleIndex + 1) % 3;
        const auto positionMinus = clodMeshTriangleMesh.GetPosition(trianglKey.GetKey(minusIndex));
        const auto positionPlus = clodMeshTriangleMesh.GetPosition(trianglKey.GetKey(plusIndex));
        auto dirPlus = positionPlus - positionThrow;
        auto dirMinus = positionMinus - positionThrow;
        const auto normalThrow = Mathematics::Vector3ToolsF::CrossProduct(dirPlus, dirMinus);

        // ������keepλ�ô���throwλ��
        // �������������εĶ���ȷ����ƽ��ķ���������ʹ��CCW˳�򣩡�
        dirPlus = positionPlus - positionKeep;
        dirMinus = positionMinus - positionKeep;
        const auto normalKeep = Mathematics::Vector3ToolsF::CrossProduct(dirPlus, dirMinus);

        // ����������֮��ĽǶ��Ǵ���90��ʱ�����ǲ�����ġ�
        if (Mathematics::Vector3ToolsF::DotProduct(normalThrow, normalKeep) < 0.0f)
        {
            return -1;
        }
    }

    return indexThrow;
}

void Rendering::CreateClodMeshImpl::Collapse(const EdgeKey& edgeKey, int indexThrow)
{
    // �õ��ıߵĶ˵㱻������
    const auto vKeep = edgeKey.GetKey(1 - indexThrow);
    const auto vThrow = edgeKey.GetKey(indexThrow);
    auto vertexThrow = graph.GetClodMeshVertex(vThrow);
    ClodMeshCollapseInfo collapse{ vKeep, vThrow };

    // ɾ�����������ι���throw���㡣
    // ����keep����������β������ŵıߡ�
    // ��Եı߱����棬����Ķ���˳��
    // �����Ϣ���Ը����׵�ȷ�������µ������α�����ͼ�ζѣ��߱��뱻���¡�
    using Tuple = CoreTools::Tuple<3, int>;
    std::set<Tuple> keepInfo{};

    for (auto iter = vertexThrow.GetTriangleKeyBegin(); iter != vertexThrow.GetTriangleKeyEnd(); ++iter)
    {
        const auto& triangleKey = *iter;

        const auto keyIndex = triangleKey.GetKeyIndex(vThrow);

        RENDERING_ASSERTION_2(keyIndex < 3, "���������\n");

        CoreTools::Tuple<3, int> tuple{};
        tuple[0] = triangleKey.GetKey((keyIndex + 1) % 3);
        tuple[1] = triangleKey.GetKey((keyIndex + 2) % 3);
        tuple[2] = graph.GetTriangle(triangleKey);

        if (tuple[0] != vKeep && tuple[1] != vKeep)
        {
            keepInfo.insert(tuple);
        }
        else
        {
            if (collapse.GetTThrow0() == -1)
            {
                collapse.SetTThrow0(tuple[2]);
            }
            else
            {
                RENDERING_ASSERTION_2(collapse.GetTThrow1() == -1, "���������\n");
                collapse.SetTThrow1(tuple[2]);
                collapses.emplace_back(collapse);
            }
        }

        graph.RemoveTriangle(triangleKey);
    }

    // ������keep��������µ������Ρ�������Ҫ�ڶ�Ҫ���µıߡ�
    using EdgeKeySet = std::set<EdgeKey>;
    EdgeKeySet needUpdate;

    for (const auto& tuple : keepInfo)
    {
        auto v0 = vKeep;
        auto v1 = tuple[0];
        auto v2 = tuple[1];
        auto triangle = tuple[2];
        graph.InsertTriangle(TriangleKey{ v0, v1, v2 }, triangle);
        needUpdate.emplace(v0, v1);
        needUpdate.emplace(v1, v2);
        needUpdate.emplace(v2, v0);
    }

    // ���±����ߵ���Щ�ѡ�
    for (const auto& updateKey : needUpdate)
    {
        const auto& clodMeshEdge = graph.GetClodMeshEdge(updateKey);

        RENDERING_ASSERTION_2(graph.IsUniqueIndexValid(clodMeshEdge.GetMinHeapRecordIndex()), "���������\n");

        graph.UpdateEdgeHeap(clodMeshEdge.GetMinHeapRecordIndex(), ComputeMetric(updateKey));
    }
}

bool Rendering::CreateClodMeshImpl::ValidResults()
{
    return graph.ValidResults(clodMeshTriangleMesh.GetNumTriangles(), clodMeshTriangleMesh.GetNumVertices(), boost::numeric_cast<int>(collapses.size()));
}

void Rendering::CreateClodMeshImpl::ReorderBuffers()
{
    // �����϶���˳����µĶ���˳��֮���ӳ�䡣
    std::vector<int> vertexNewToOld(clodMeshTriangleMesh.GetNumVertices());
    std::vector<int> vertexOldToNew(clodMeshTriangleMesh.GetNumVertices());
    auto vertexNew = clodMeshTriangleMesh.GetNumVertices() - 1;

    for (const auto& collapse : collapses)
    {
        int vertexOld = collapse.GetVThrow();
        vertexNewToOld.at(vertexNew) = vertexOld;
        vertexOldToNew.at(vertexOld) = vertexNew--;
    }

    for (auto iter = graph.GetVerticesRemainingBegin(); iter != graph.GetVerticesRemainingEnd(); ++iter)
    {
        auto vertexOld = *iter;
        vertexNewToOld.at(vertexNew) = vertexOld;
        vertexOldToNew.at(vertexOld) = vertexNew--;
    }

    // �������򶥵㻺������
    auto oldData = clodMeshTriangleMesh.GetVertexBufferReadOnlyData();
    const auto stride = clodMeshTriangleMesh.GetStride();
    const auto newDataSize = clodMeshTriangleMesh.GetNumVertices() * stride;
    std::vector<char> newData(newDataSize);

    for (auto vertexIndex = 0; vertexIndex < clodMeshTriangleMesh.GetNumVertices(); ++vertexIndex)
    {
        const auto index = stride * vertexNewToOld.at(vertexIndex);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        auto srcVertex = oldData + index;

#include STSTEM_WARNING_POP

        const auto newDataIndex = stride * vertexIndex;
        System::MemoryCopy(&newData.at(newDataIndex), srcVertex, stride);
    }
    clodMeshTriangleMesh.SetNewVertexBufferData(newData);

    // ���������ξ�˳����µ�������˳��Ķ�Ӧ��ϵ��
    std::vector<int> triangleNewToOld(clodMeshTriangleMesh.GetNumTriangles());
    auto trianglesNew = clodMeshTriangleMesh.GetNumTriangles() - 1;

    for (const auto& collapse : collapses)
    {
        auto triangleOld = collapse.GetTThrow0();
        triangleNewToOld.at(trianglesNew--) = triangleOld;
        triangleOld = collapse.GetTThrow1();
        triangleNewToOld.at(trianglesNew--) = triangleOld;
    }

    for (auto iter = graph.GetTrianglesRemainingBegin(); iter != graph.GetTrianglesRemainingEnd(); ++iter)
    {
        auto triangleOld = *iter;
        triangleNewToOld.at(trianglesNew--) = triangleOld;
    }

    // ��������������������
    std::vector<char> newIndices(clodMeshTriangleMesh.GetNumIndices() * sizeof(int));

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto trgIndices = reinterpret_cast<int*>(newIndices.data());

#include STSTEM_WARNING_POP

    for (auto trianglesIndex = 0; trianglesIndex < clodMeshTriangleMesh.GetNumTriangles(); ++trianglesIndex)
    {
        auto triangleOld = triangleNewToOld.at(trianglesIndex);
        const auto next = 3 * triangleOld;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        auto srcIndices = clodMeshTriangleMesh.GetIndexBufferReadOnlyData() + next;
        for (auto j = 0; j < 3; ++j)
        {
            *trgIndices++ = *srcIndices++;
        }

#include STSTEM_WARNING_POP
    }

    // ӳ�����������������

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto newIndicesPtr = reinterpret_cast<int*>(newIndices.data());

#include STSTEM_WARNING_POP

    for (auto i = 0; i < clodMeshTriangleMesh.GetNumIndices(); ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        newIndicesPtr[i] = vertexOldToNew.at(newIndicesPtr[i]);

#include STSTEM_WARNING_POP
    }

    clodMeshTriangleMesh.SetNewIndexBufferData(newIndices);

    // ӳ��keep��throw����
    for (auto& collapse : collapses)
    {
        collapse.SetVKeep(vertexOldToNew.at(collapse.GetVKeep()));
        collapse.SetVThrow(vertexOldToNew.at(collapse.GetVThrow()));
    }
}

void Rendering::CreateClodMeshImpl::ComputeRecords()
{
    if (collapses.size() == 0)
        return;

    auto numRecords = boost::numeric_cast<int>(collapses.size() + 1);
    collapseRecord.resize(numRecords, CollapseRecord{ -1 });

    // ����ļ�¼�洢ֻ�ж���������εĳ���ֵ��
    collapseRecord.at(0).SetNumVertices(clodMeshTriangleMesh.GetNumVertices());
    collapseRecord.at(0).SetNumTriangles(clodMeshTriangleMesh.GetNumTriangles());

    // ����������������Ϊ���Ǵ���ÿһ��������¼�滻throw���㡣
    std::vector<int> indices(clodMeshTriangleMesh.GetNumIndices());
    System::MemoryCopy(indices.data(), clodMeshTriangleMesh.GetIndexBufferReadOnlyData(), clodMeshTriangleMesh.GetNumIndices() * sizeof(int));
    std::vector<int> verticesThrowIndices(clodMeshTriangleMesh.GetNumIndices());

    // �����еı�����¼��
    auto record = &collapseRecord.at(1);
    auto numVertices = clodMeshTriangleMesh.GetNumVertices();
    auto numTriangles = clodMeshTriangleMesh.GetNumTriangles();

    for (const auto& collapse : collapses)
    {
        record->SetVKeep(collapse.GetVKeep());
        record->SetVThrow(collapse.GetVThrow());

        // ��Ե����ʧȥ��һ�����㡣
        --numVertices;
        record->SetNumVertices(numVertices);

        // ��Ե����ʧȥ������������
        numTriangles -= 2;
        record->SetNumTriangles(numTriangles);

        // �����ıߺ͸��±���������������������
        const auto numIndices = 3 * numTriangles;
        auto recordNumIndices = 0;
        for (auto i = 0; i < numIndices; ++i)
        {
            if (indices.at(i) == record->GetVThrow())
            {
                verticesThrowIndices.at(recordNumIndices++) = i;
                indices.at(i) = record->GetVKeep();
            }
        }

        if (0 < recordNumIndices)
        {
            std::vector<int> indices2(recordNumIndices);

            const auto numBytes = recordNumIndices * sizeof(int);
            System::MemoryCopy(indices2.data(), verticesThrowIndices.data(), boost::numeric_cast<uint32_t>(numBytes));

            record->SetIndices(indices2);
        }
        else
        {
            record->ClearIndices();
        }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ++record;

#include STSTEM_WARNING_POP
    }
}
