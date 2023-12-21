///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:52)

#include "Rendering/RenderingExport.h"

#include "ClodMeshTriangleMesh.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Meshes/TriangleKey.h"

#include <set>

Rendering::ClodMeshTriangleMesh::ClodMeshTriangleMesh(TrianglesMesh& mesh)
    : numVertices{ mesh.GetVertexBuffer()->GetNumElements() },
      numIndices{ mesh.GetIndexBuffer()->GetNumElements() },
      numTriangles{ numIndices / 3 },
      indixBuffer{ mesh.GetIndexBuffer() },
      vertexBuffer{ mesh.GetVertexBuffer() },
      vertexBufferAccessor{ *mesh.GetVertexBuffer() }
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

    using TriangleKeySet = std::set<Mathematics::TriangleKey>;
    TriangleKeySet triangles{};
    std::set<int> vertexIndices{};
    auto currentIndex = GetIndexBufferReadOnlyData();
    if (currentIndex == nullptr)
    {
        return false;
    }

    for (auto trianglesIndex = 0; trianglesIndex < numTriangles; ++trianglesIndex)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        const auto firstIndex = *currentIndex++;
        const auto secondIndex = *currentIndex++;
        const auto thirdIndex = *currentIndex++;

#include SYSTEM_WARNING_POP

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

const int* Rendering::ClodMeshTriangleMesh::GetIndexBufferReadOnlyData() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const int*>(*indixBuffer->GetStorage());

#include SYSTEM_WARNING_POP
}

int Rendering::ClodMeshTriangleMesh::GetNumTriangles() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numTriangles;
}

Mathematics::Vector3F Rendering::ClodMeshTriangleMesh::GetPosition(MAYBE_UNUSED int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return Mathematics::Vector3F{};
}

const char* Rendering::ClodMeshTriangleMesh::GetVertexBufferReadOnlyData() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return &*vertexBufferAccessor.GetStorage();
}

int Rendering::ClodMeshTriangleMesh::GetStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return 0;
}

void Rendering::ClodMeshTriangleMesh::SetNewVertexBufferData(const std::vector<char>& newData)
{
    RENDERING_CLASS_IS_VALID_9;

    vertexBuffer->SetStorage(newData);
}

void Rendering::ClodMeshTriangleMesh::SetNewIndexBufferData(const std::vector<char>& newData)
{
    RENDERING_CLASS_IS_VALID_9;

    indixBuffer->SetStorage(newData);
}
