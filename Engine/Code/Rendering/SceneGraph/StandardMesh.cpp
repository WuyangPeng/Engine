///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 16:26)

#include "Rendering/RenderingExport.h"

#include "StandardMesh.h"
#include "Detail/StandardMeshImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Detail/VertexBufferAccessorImpl.h"
#include "Rendering/SceneGraph/Detail/PickRecordContainerImpl.h"
#include "Rendering/SceneGraph/Detail/PickRecordImpl.h"

using std::make_shared;

Rendering::StandardMesh::StandardMesh(const VertexFormatSharedPtr& vertexFormat, bool isStatic, bool inside, const TransformF* transform)
    : impl{ vertexFormat, isStatic, inside, transform }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, StandardMesh)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, StandardMesh, SetTransform, TransformF, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, StandardMesh, GetTransform, const Rendering::TransformF&)
COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, StandardMesh)

const Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Rectangle(int xSamples, int ySamples, float xExtent, float yExtent) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Rectangle(xSamples, ySamples, xExtent, yExtent);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Disk(int shellSamples, int radialSamples, float radius) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Disk(shellSamples, radialSamples, radius);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Box(float xExtent, float yExtent, float zExtent) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Box(xExtent, yExtent, zExtent);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::CylinderOmittedEndDisks(int axisSamples, int radialSamples, float radius, float height) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->CylinderOmittedEndDisks(axisSamples, radialSamples, radius, height);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::CylinderIncludedEndDisks(int axisSamples, int radialSamples, float radius, float height) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->CylinderIncludedEndDisks(axisSamples, radialSamples, radius, height);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Sphere(int zSamples, int radialSamples, float radius) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Sphere(zSamples, radialSamples, radius);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Torus(int circleSamples, int radialSamples, float outerRadius, float innerRadius) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Torus(circleSamples, radialSamples, outerRadius, innerRadius);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Tetrahedron, Rendering::TrianglesMeshSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Hexahedron, Rendering::TrianglesMeshSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Octahedron, Rendering::TrianglesMeshSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Dodecahedron, Rendering::TrianglesMeshSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Icosahedron, Rendering::TrianglesMeshSharedPtr)
