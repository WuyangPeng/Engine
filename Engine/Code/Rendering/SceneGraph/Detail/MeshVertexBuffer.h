/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:41)

#ifndef RENDERING_SCENE_GRAPH_MESH_VERTEX_BUFFER_H
#define RENDERING_SCENE_GRAPH_MESH_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

#include <map>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE MeshVertexBuffer
    {
    public:
        using ClassType = MeshVertexBuffer;

        using StorageType = std::vector<char>;
        using SpanIterator = CoreTools::SpanIterator<StorageType::iterator>;
        using Vector2 = Mathematics::Vector2F;
        using Vector3 = Mathematics::Vector3F;
        using Semantic = VertexFormatFlags::Semantic;

    public:
        explicit MeshVertexBuffer(VertexBufferSharedPtr vertexBuffer) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;

        NODISCARD bool HasChannel(Semantic aSemantic) const;

        void SetPosition(int index, const Vector3& position, int vertexSize);
        void SetNormal(int index, const Vector3& normal, int vertexSize);
        void SetTangent(int index, const Vector3& tangent, int vertexSize);
        void SetBitangent(int index, const Vector3& bitangent, int vertexSize);
        void SetTextureCoordinate(int unit, int index, const Vector2& textureCoordinate, int vertexSize);

        NODISCARD Vector3 GetPosition(int index, int vertexSize) const;
        NODISCARD Vector3 GetNormal(int index, int vertexSize) const;
        NODISCARD Vector3 GetTangent(int index, int vertexSize) const;
        NODISCARD Vector3 GetBitangent(int index, int vertexSize) const;
        NODISCARD Vector2 GetTextureCoordinate(int unit, int index, int vertexSize) const;

        void AddTextureCoords(int unit, const SpanIterator& channel);
        void SetGeometricChannel(Semantic aSemantic, float w, const VertexFormat& vertexFormat);

    private:
        using SpanIteratorContainer = std::map<Semantic, SpanIterator>;
        using TextureCoordsContainer = std::map<int, SpanIterator>;

    private:
        void AddChannel(Semantic aSemantic, const SpanIterator& channel);

    private:
        VertexBufferSharedPtr vertexBuffer;
        SpanIteratorContainer semantic;
        TextureCoordsContainer textureCoords;
    };
}

#endif  // RENDERING_SCENE_GRAPH_MESH_VERTEX_BUFFER_H
