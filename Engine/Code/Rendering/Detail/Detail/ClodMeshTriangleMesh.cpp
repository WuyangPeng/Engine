///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:52)

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
            // 现在，输入应该来自三角网格或三角扇。
            // 边折叠算法必须进行修改，以应对为其退化添加三角形（以产生长条）的三角形带。
            RENDERING_ASSERTION_2(false, "退化三角形是不允许的。\n");
            return false;
        }

        vertexIndices.emplace(firstIndex);
        vertexIndices.emplace(secondIndex);
        vertexIndices.emplace(thirdIndex);

        const auto result = triangles.insert(Mathematics::TriangleKey{ firstIndex, secondIndex, thirdIndex });

        if (result.second == false)
        {
            // 索引缓冲区包含重复三角形。边折叠算法不被设计来处理重复。
            RENDERING_ASSERTION_2(false, "索引缓冲区包含重复三角形。\n");
            return false;
        }
    }

    // 测试一个有效的顶点缓冲区
    if (boost::numeric_cast<int>(vertexIndices.size()) < numVertices || numVertices != (*vertexIndices.rbegin() + 1))
    {
        // 如果下面的断言被触发时，顶点缓冲器具有不被索引缓冲器引用的顶点。
        // 这是一个问题，因为在顶点缓冲器是基于边折叠的顺序重新排序。
        // 引用输入顶点缓冲在任何其他索引缓冲区现在是无效的。
        RENDERING_ASSERTION_2(false, "索引缓冲区没有引用的所有顶点。\n");
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
