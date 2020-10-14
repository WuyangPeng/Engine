// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 19:23)

#ifndef RENDERING_SCENE_GRAPH_STANDARD_MESH_IMPL_H
#define RENDERING_SCENE_GRAPH_STANDARD_MESH_IMPL_H

#include "Rendering/RenderingDll.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE StandardMeshImpl
    {
    public:
        using ClassType = StandardMeshImpl;
        using APoint = Mathematics::FloatAPoint;
        using AVector = Mathematics::FloatAVector;
        using Vector2D = Mathematics::Vector2Df;
        using Math = Mathematics::FloatMath;

    public:
        StandardMeshImpl(const VertexFormatSharedPtr& vertexFormat, bool isStatic = true, bool inside = false, const FloatTransform* transform = nullptr);

        StandardMeshImpl(const StandardMeshImpl& rhs);
        StandardMeshImpl& operator=(const StandardMeshImpl& rhs);

        StandardMeshImpl(StandardMeshImpl&& rhs) = default;
        StandardMeshImpl& operator=(StandardMeshImpl&& rhs) = default;
        ~StandardMeshImpl() = default;

        CLASS_INVARIANT_DECLARE;

        void SetTransform(const FloatTransform& transform) noexcept;
        const FloatTransform& GetTransform() const noexcept;

        const TrianglesMeshSharedPtr Rectangle(int xSamples, int ySamples, float xExtent, float yExtent) const;
        const TrianglesMeshSharedPtr Disk(int shellSamples, int radialSamples, float radius) const;
        const TrianglesMeshSharedPtr Box(float xExtent, float yExtent, float zExtent) const;
        const TrianglesMeshSharedPtr CylinderOmittedEndDisks(int axisSamples, int radialSamples, float radius, float height) const;
        const TrianglesMeshSharedPtr CylinderIncludedEndDisks(int axisSamples, int radialSamples, float radius, float height) const;
        const TrianglesMeshSharedPtr Sphere(int zSamples, int radialSamples, float radius) const;
        const TrianglesMeshSharedPtr Torus(int circleSamples, int radialSamples, float outerRadius, float innerRadius) const;

        const TrianglesMeshSharedPtr Tetrahedron() const;
        const TrianglesMeshSharedPtr Hexahedron() const;
        const TrianglesMeshSharedPtr Octahedron() const;
        const TrianglesMeshSharedPtr Dodecahedron() const;
        const TrianglesMeshSharedPtr Icosahedron() const;

    private:
        void Init();
        void TransformData(const VertexBufferAccessor& vertexBufferAccessor, const VertexBufferSharedPtr& vertexBuffer) const;
        void ReverseTriangleOrder(int numTriangles, int* indices) const noexcept;
        void CreatePlatonicNormals(const VertexBufferAccessor& vertexBufferAccessor, const VertexBufferSharedPtr& vertexBuffer) const;
        void CreatePlatonicTextures(const VertexBufferAccessor& vertexBufferAccessor, const VertexBufferSharedPtr& vertexBuffer) const;

    private:
        static constexpr auto sm_MaxUnits = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);

        VertexFormatSharedPtr m_VertexFormat;
        FloatTransform m_Transform;
        bool m_IsStatic;
        bool m_Inside;
        bool m_HasNormals;
        bool m_HasTextureCoords[sm_MaxUnits]{};
        BufferUsage m_Usage;
    };
}

#endif  // RENDERING_SCENE_GRAPH_STANDARD_MESH_IMPL_H
