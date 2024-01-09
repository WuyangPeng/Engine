///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:50)

#ifndef RENDERING_DETAIL_CLOD_MESH_TRIANGLE_MESH_H
#define RENDERING_DETAIL_CLOD_MESH_TRIANGLE_MESH_H

#include "Mathematics/Algebra/Vector3.h"
#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ClodMeshTriangleMesh
    {
    public:
        using ClassType = ClodMeshTriangleMesh;

    public:
        ClodMeshTriangleMesh() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetNumIndices() const noexcept;
        NODISCARD int GetNumTriangles() const noexcept;

        NODISCARD bool ValidBuffers() const;
        NODISCARD const int* GetIndexBufferReadOnlyData() const;

        NODISCARD Mathematics::Vector3F GetPosition(int index) const noexcept;

        NODISCARD const char* GetVertexBufferReadOnlyData() const noexcept;
        NODISCARD int GetStride() const noexcept;

        void SetNewVertexBufferData(const std::vector<char>& newData);
        void SetNewIndexBufferData(const std::vector<char>& newData);

    private:
        // 三角网络数据抽取。
        int numVertices;
        int numIndices;
        int numTriangles;
        IndexBufferSharedPtr indixBuffer;
        VertexBufferSharedPtr vertexBuffer;
        VertexBufferSharedPtr vertexBufferAccessor;
    };
}

#endif  // RENDERING_DETAIL_CLOD_MESH_TRIANGLE_MESH_H
