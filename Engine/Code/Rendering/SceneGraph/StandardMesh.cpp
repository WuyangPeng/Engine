// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/22 18:26)

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

const Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Disk(int shellSamples, int radialSamples, float radius) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Disk(shellSamples, radialSamples, radius);
}

const Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Box(float xExtent, float yExtent, float zExtent) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Box(xExtent, yExtent, zExtent);
}

const Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::CylinderOmittedEndDisks(int axisSamples, int radialSamples, float radius, float height) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->CylinderOmittedEndDisks(axisSamples, radialSamples, radius, height);
}

const Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::CylinderIncludedEndDisks(int axisSamples, int radialSamples, float radius, float height) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->CylinderIncludedEndDisks(axisSamples, radialSamples, radius, height);
}

const Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Sphere(int zSamples, int radialSamples, float radius) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Sphere(zSamples, radialSamples, radius);
}

const Rendering::TrianglesMeshSharedPtr Rendering::StandardMesh::Torus(int circleSamples, int radialSamples, float outerRadius, float innerRadius) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->Torus(circleSamples, radialSamples, outerRadius, innerRadius);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Tetrahedron, const Rendering::TrianglesMeshSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Hexahedron, const Rendering::TrianglesMeshSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Octahedron, const Rendering::TrianglesMeshSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Dodecahedron, const Rendering::TrianglesMeshSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StandardMesh, Icosahedron, const Rendering::TrianglesMeshSharedPtr)
