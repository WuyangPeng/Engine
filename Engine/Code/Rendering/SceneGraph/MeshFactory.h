/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:54)

#ifndef RENDERING_SCENE_GRAPH_MESH_FACTORY_H
#define RENDERING_SCENE_GRAPH_MESH_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(MeshFactory, MeshFactoryImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE MeshFactory
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(MeshFactory);

    public:
        explicit MeshFactory(const std::string& name);
        explicit MeshFactory(const VertexFormatSharedPtr& vertexFormat);
        MeshFactory(const VertexFormatSharedPtr& vertexFormat, UsageType vertexBufferUsage);

        CLASS_INVARIANT_DECLARE;

        void SetVertexFormat(const VertexFormatSharedPtr& format) noexcept;
        void SetVertexBufferUsage(UsageType usage) noexcept;
        void SetIndexFormat(bool use32Bit) noexcept;
        void SetIndexBufferUsage(UsageType usage) noexcept;
        void SetOutside(bool outside) noexcept;

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
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_MESH_FACTORY_H
