///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/09 18:54)

#include "Rendering/RenderingExport.h"

#include "ClodMeshTriangleMesh.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Meshes/TriangleKey.h"

#include <set>

using std::set;

Rendering::ClodMeshTriangleMesh::ClodMeshTriangleMesh(TrianglesMesh& mesh)
    : numVertices{ mesh.GetVertexBuffer()->GetNumElements() },
      numIndices{ mesh.GetIndexBuffer()->GetNumElements() },
      numTriangles{ numIndices / 3 },
      indixBuffer{ mesh.GetIndexBuffer() },
      vertexBuffer{ mesh.GetVertexBuffer() },
      vertexBufferAccessor{ mesh }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshTriangleMesh)

int Rendering::ClodMeshTriangleMesh::GetNumVertices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numVertices;
}

int Rendering::ClodMeshTriangleMesh::GetNumIndices() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numIndices;
}

bool Rendering::ClodMeshTriangleMesh::ValidBuffers() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    using TriangleKeySet = set<Mathematics::TriangleKey>;
    TriangleKeySet triangles{};
    std::set<int> vertexIndices{};
    auto currentIndex = GetIndexBufferReadOnlyData();
    if (currentIndex == nullptr)
    {
        return false;
    }

    for (auto trianglesIndex = 0; trianglesIndex < numTriangles; ++trianglesIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        const auto firstIndex = *currentIndex++;
        const auto secondIndex = *currentIndex++;
        const auto thirdIndex = *currentIndex++;

#include STSTEM_WARNING_POP

        if (firstIndex == secondIndex || firstIndex == thirdIndex || secondIndex == thirdIndex)
        {
            // ���ڣ�����Ӧ��������������������ȡ�
            // ���۵��㷨��������޸ģ���Ӧ��Ϊ���˻���������Σ��Բ����������������δ���
            RENDERING_ASSERTION_2(false, "�˻��������ǲ�����ġ�\n");
            return false;
        }

        vertexIndices.emplace(firstIndex);
        vertexIndices.emplace(secondIndex);
        vertexIndices.emplace(thirdIndex);

        const auto result = triangles.insert(Mathematics::TriangleKey{ firstIndex, secondIndex, thirdIndex });

        if (result.second == false)
        {
            // ���������������ظ������Ρ����۵��㷨��������������ظ���
            RENDERING_ASSERTION_2(false, "���������������ظ������Ρ�\n");
            return false;
        }
    }

    // ����һ����Ч�Ķ��㻺����
    if (boost::numeric_cast<int>(vertexIndices.size()) < numVertices || numVertices != (*vertexIndices.rbegin() + 1))
    {
        // �������Ķ��Ա�����ʱ�����㻺�������в����������������õĶ��㡣
        // ����һ�����⣬��Ϊ�ڶ��㻺�����ǻ��ڱ��۵���˳����������
        // �������붥�㻺�����κ�����������������������Ч�ġ�
        RENDERING_ASSERTION_2(false, "����������û�����õ����ж��㡣\n");
        return false;
    }

    return true;
}

const int* Rendering::ClodMeshTriangleMesh::GetIndexBufferReadOnlyData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const int*>(indixBuffer->GetReadOnlyData());

#include STSTEM_WARNING_POP
}

int Rendering::ClodMeshTriangleMesh::GetNumTriangles() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numTriangles;
}

Mathematics::Vector3F Rendering::ClodMeshTriangleMesh::GetPosition(int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexBufferAccessor.GetPosition<Mathematics::Vector3F>(index);
}

const char* Rendering::ClodMeshTriangleMesh::GetVertexBufferReadOnlyData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexBufferAccessor.GetData();
}

int Rendering::ClodMeshTriangleMesh::GetStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexBufferAccessor.GetStride();
}

void Rendering::ClodMeshTriangleMesh::SetNewVertexBufferData(const std::vector<char>& newData)
{
    RENDERING_CLASS_IS_VALID_9;

    vertexBuffer->SetNewData(newData);
}

void Rendering::ClodMeshTriangleMesh::SetNewIndexBufferData(const std::vector<char>& newData)
{
    RENDERING_CLASS_IS_VALID_9;

    indixBuffer->SetNewData(newData);
}
