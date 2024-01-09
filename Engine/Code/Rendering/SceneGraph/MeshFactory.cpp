/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:56)

#include "Rendering/RenderingExport.h"

#include "MeshFactory.h"
#include "Detail/MeshFactoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, MeshFactory)

Rendering::MeshFactory::MeshFactory(const std::string& name)
    : impl{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::MeshFactory::MeshFactory(const VertexFormatSharedPtr& vertexFormat)
    : impl{ vertexFormat }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::MeshFactory::MeshFactory(const VertexFormatSharedPtr& vertexFormat, UsageType vertexBufferUsage)
    : impl{ vertexFormat, vertexBufferUsage }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MeshFactory)

void Rendering::MeshFactory::SetVertexFormat(const VertexFormatSharedPtr& format) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetVertexFormat(format);
}

void Rendering::MeshFactory::SetVertexBufferUsage(UsageType usage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetVertexBufferUsage(usage);
}

void Rendering::MeshFactory::SetIndexFormat(bool use32Bit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIndexFormat(use32Bit);
}

void Rendering::MeshFactory::SetIndexBufferUsage(UsageType usage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIndexBufferUsage(usage);
}

void Rendering::MeshFactory::SetOutside(bool outside) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOutside(outside);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateRectangle(int numXSamples, int numYSamples, float xExtent, float yExtent)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateRectangle(numXSamples, numYSamples, xExtent, yExtent);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateTriangle(int numSamples, float xExtent, float yExtent)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateTriangle(numSamples, xExtent, yExtent);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateDisk(int numShellSamples, int numRadialSamples, float radius)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateDisk(numShellSamples, numRadialSamples, radius);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateBox(float xExtent, float yExtent, float zExtent)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateBox(xExtent, yExtent, zExtent);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateCylinderOpen(int numAxisSamples, int numRadialSamples, float radius, float height)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateCylinderOpen(numAxisSamples, numRadialSamples, radius, height);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateCylinderClosed(int numAxisSamples, int numRadialSamples, float radius, float height)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateCylinderClosed(numAxisSamples, numRadialSamples, radius, height);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateSphere(int numZSamples, int numRadialSamples, float radius)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateSphere(numZSamples, numRadialSamples, radius);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateTorus(int numCircleSamples, int numRadialSamples, float outerRadius, float innerRadius)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateTorus(numCircleSamples, numRadialSamples, outerRadius, innerRadius);
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateTetrahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateTetrahedron();
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateHexahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateHexahedron();
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateOctahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateOctahedron();
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateDodecahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateDodecahedron();
}

Rendering::VisualSharedPtr Rendering::MeshFactory::CreateIcosahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateIcosahedron();
}
