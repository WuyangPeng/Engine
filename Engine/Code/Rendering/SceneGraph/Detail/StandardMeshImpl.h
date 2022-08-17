///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 16:56)

#ifndef RENDERING_SCENE_GRAPH_STANDARD_MESH_IMPL_H
#define RENDERING_SCENE_GRAPH_STANDARD_MESH_IMPL_H

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE StandardMeshImpl
    {
    public:
        using ClassType = StandardMeshImpl;
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using Vector2D = Mathematics::Vector2F;
        using Math = Mathematics::MathF;

    public:
        StandardMeshImpl(const VertexFormatSharedPtr& vertexFormat, bool isStatic = true, bool inside = false, const TransformF* transform = nullptr);

        ~StandardMeshImpl() noexcept = default;
        StandardMeshImpl(const StandardMeshImpl& rhs);
        StandardMeshImpl& operator=(const StandardMeshImpl& rhs);
        StandardMeshImpl(StandardMeshImpl&& rhs) noexcept;
        StandardMeshImpl& operator=(StandardMeshImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetTransform(const TransformF& aTransform) noexcept;
        NODISCARD const TransformF& GetTransform() const noexcept;

        NODISCARD TrianglesMeshSharedPtr Rectangle(int xSamples, int ySamples, float xExtent, float yExtent) const;
        NODISCARD TrianglesMeshSharedPtr Disk(int shellSamples, int radialSamples, float radius) const;
        NODISCARD TrianglesMeshSharedPtr Box(float xExtent, float yExtent, float zExtent) const;
        NODISCARD TrianglesMeshSharedPtr CylinderOmittedEndDisks(int axisSamples, int radialSamples, float radius, float height) const;
        NODISCARD TrianglesMeshSharedPtr CylinderIncludedEndDisks(int axisSamples, int radialSamples, float radius, float height) const;
        NODISCARD TrianglesMeshSharedPtr Sphere(int zSamples, int radialSamples, float radius) const;
        NODISCARD TrianglesMeshSharedPtr Torus(int circleSamples, int radialSamples, float outerRadius, float innerRadius) const;

        NODISCARD TrianglesMeshSharedPtr Tetrahedron() const;
        NODISCARD TrianglesMeshSharedPtr Hexahedron() const;
        NODISCARD TrianglesMeshSharedPtr Octahedron() const;
        NODISCARD TrianglesMeshSharedPtr Dodecahedron() const;
        NODISCARD TrianglesMeshSharedPtr Icosahedron() const;

    private:
        void Init();
        void TransformData(const VertexBuffer& vertexBufferAccessor, VertexBuffer& vertexBuffer) const noexcept;
        void ReverseTriangleOrder(int numTriangles, int* indices) const noexcept;
        void CreatePlatonicNormals(const VertexBuffer& vertexBufferAccessor, VertexBuffer& vertexBuffer) const noexcept;
        void CreatePlatonicTextures(const VertexBuffer& vertexBufferAccessor, VertexBuffer& vertexBuffer) const noexcept;

        static void InitIndexBuffer(IndexBuffer& indexBuffer, const std::vector<int>& indices);
        static void InitIndexBufferInRectangle(IndexBuffer& indexBuffer, int index, int rectangleIndex0, int rectangleIndex1, int rectangleIndex2, int rectangleIndex3);
        static void InitIndexBufferInDisk(IndexBuffer& indexBuffer, int radialSamplesMinus1, int shellSamplesMinus1);

    private:
        static constexpr auto maxUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);

        VertexFormatSharedPtr vertexFormat;
        TransformF transform;
        bool isStatic;
        bool inside;
        bool hasNormals;
        std::array<bool, maxUnits> hasTextureCoords{};
        BufferUsage usage;
    };
}

#endif  // RENDERING_SCENE_GRAPH_STANDARD_MESH_IMPL_H
