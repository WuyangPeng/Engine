/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:37)

#ifndef RENDERING_SCENE_GRAPH_MESH_FACTORY_IMPL_H
#define RENDERING_SCENE_GRAPH_MESH_FACTORY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "MeshVertexBuffer.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/SceneGraph/Visual.h"

#include <array>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE MeshFactoryImpl
    {
    public:
        using ClassType = MeshFactoryImpl;

    public:
        explicit MeshFactoryImpl(const std::string& name);
        explicit MeshFactoryImpl(VertexFormatSharedPtr vertexFormat) noexcept;
        MeshFactoryImpl(VertexFormatSharedPtr vertexFormat, UsageType vertexBufferUsage) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetVertexFormat(const VertexFormatSharedPtr& format) noexcept;
        void SetVertexBufferUsage(UsageType usage) noexcept;
        void SetIndexFormat(bool use32Bit) noexcept;
        void SetIndexBufferUsage(UsageType usage) noexcept;
        void SetOutside(bool aOutside) noexcept;

        NODISCARD VisualSharedPtr CreateRectangle(int numXSamples, int numYSamples, float xExtent, float yExtent);
        NODISCARD VisualSharedPtr CreateTriangle(int numSamples, float xExtent, float yExtent);
        NODISCARD VisualSharedPtr CreateDisk(int numShellSamples, int numRadialSamples, float radius);
        NODISCARD VisualSharedPtr CreateBox(float xExtent, float yExtent, float zExtent);
        NODISCARD VisualSharedPtr CreateCylinderOpen(int numAxisSamples, int numRadialSamples, float radius, float height);
        NODISCARD VisualSharedPtr CreateCylinderClosed(int numAxisSamples, int numRadialSamples, float radius, float height);
        NODISCARD VisualSharedPtr CreateSphere(int numZSamples, int numRadialSamples, float radius);
        NODISCARD VisualSharedPtr CreateTorus(int numCircleSamples, int numRadialSamples, float outerRadius, float innerRadius);

        NODISCARD VisualSharedPtr CreateTetrahedron();
        NODISCARD VisualSharedPtr CreateHexahedron();
        NODISCARD VisualSharedPtr CreateOctahedron();
        NODISCARD VisualSharedPtr CreateDodecahedron();
        NODISCARD VisualSharedPtr CreateIcosahedron();

    private:
        static constexpr auto textureCoordinateUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);

        using AssignTextureCoordsType = std::array<bool, textureCoordinateUnits>;
        using StorageType = std::vector<char>;
        using SpanIterator = CoreTools::SpanIterator<StorageType::iterator>;
        using ConstSpanIterator = CoreTools::SpanIterator<StorageType::const_iterator>;
        using Vector2 = Mathematics::Vector2F;
        using Vector3 = Mathematics::Vector3F;
        using SphereResult = std::pair<MeshVertexBuffer, VisualSharedPtr>;

    private:
        NODISCARD MeshVertexBuffer CreateMeshVertexBuffer(int numVertices);
        NODISCARD IndexBufferSharedPtr CreateIndexBuffer(int numTriangles) const;

        void SetPosition(int index, const Vector3& position, MeshVertexBuffer& meshVertexBuffer);
        void SetNormal(int index, const Vector3& normal, MeshVertexBuffer& meshVertexBuffer);
        void SetTangent(int index, const Vector3& tangent, MeshVertexBuffer& meshVertexBuffer);
        void SetBitangent(int index, const Vector3& bitangent, MeshVertexBuffer& meshVertexBuffer);

        void SetTextureCoordinate(int index, const Vector2& textureCoordinates, MeshVertexBuffer& meshVertexBuffer);
        void SetPlatonicTextureCoordinate(int index, const Vector3& position, MeshVertexBuffer& meshVertexBuffer);

        void ReverseTriangleOrder(IndexBuffer& indexBuffer);

        NODISCARD SphereResult DoCreateSphere(int numZSamples, int numRadialSamples, float radius);

    private:
        VertexFormatSharedPtr vertexFormat;
        int indexSize;
        UsageType vertexBufferUsage;
        UsageType indexBufferUsage;
        bool outside;
        AssignTextureCoordsType assignTextureCoords;
    };
}

#endif  // RENDERING_SCENE_GRAPH_MESH_FACTORY_IMPL_H
