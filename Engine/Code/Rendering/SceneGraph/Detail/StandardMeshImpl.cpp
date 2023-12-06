///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:14)

#include "Rendering/RenderingExport.h"

#include "StandardMeshImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

#include <vector>

Rendering::StandardMeshImpl::StandardMeshImpl(const VertexFormatSharedPtr& vertexFormat, bool isStatic, bool inside, const Mathematics::TransformF* transform)
    : vertexFormat{ vertexFormat },
      transform{ transform != nullptr ? *transform : Mathematics::TransformF{} },
      isStatic{ isStatic },
      inside{ inside },
      hasNormals{ false },
      hasTextureCoords{},
      usage{ isStatic ? BufferUsage::Static : BufferUsage::Dynamic }
{
    Init();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::StandardMeshImpl::StandardMeshImpl(const StandardMeshImpl& rhs)
    : vertexFormat{ rhs.vertexFormat->Clone() },
      transform{ rhs.transform },
      isStatic{ rhs.isStatic },
      inside{ rhs.inside },
      hasNormals{ rhs.hasNormals },
      hasTextureCoords{ rhs.hasTextureCoords },
      usage{ rhs.usage }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::StandardMeshImpl::Init()
{
    const auto positionIndex = vertexFormat->GetIndex(VertexFormatFlags::Semantic::Position);

    RENDERING_ASSERTION_1(0 <= positionIndex, "顶点格式必须包含位置。\n");

    MAYBE_UNUSED const auto positionType = vertexFormat->GetAttributeType(positionIndex);
    RENDERING_ASSERTION_1(positionType == DataFormatType::R32G32B32Float, "位置必须是3元组的浮点数。\n");

    const auto normalIndex = vertexFormat->GetIndex(VertexFormatFlags::Semantic::Normal);
    if (0 <= normalIndex)
    {
        const auto normalType = vertexFormat->GetAttributeType(normalIndex);

        if (normalType == DataFormatType::R32G32B32Float)
        {
            hasNormals = true;
        }
        else
        {
            hasNormals = false;
        }
    }

    for (auto unit = 0; unit < maxUnits; ++unit)
    {
        const auto textureCoordIndex = vertexFormat->GetIndex(VertexFormatFlags::Semantic::TextureCoord, unit);
        if (0 <= textureCoordIndex)
        {
            const auto textureCoordType = vertexFormat->GetAttributeType(textureCoordIndex);

            if (textureCoordType == DataFormatType::R32G32Float)
            {
                hasTextureCoords.at(unit) = true;
            }
            else
            {
                hasTextureCoords.at(unit) = false;
            }
        }
    }
}

Rendering::StandardMeshImpl& Rendering::StandardMeshImpl::operator=(const StandardMeshImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat = rhs.vertexFormat->Clone();
    transform = rhs.transform;
    isStatic = rhs.isStatic;
    inside = rhs.inside;
    hasNormals = rhs.hasNormals;
    usage = rhs.usage;

    for (auto i = 0; i < maxUnits; ++i)
    {
        hasTextureCoords.at(i) = rhs.hasTextureCoords.at(i);
    }

    return *this;
}

Rendering::StandardMeshImpl& Rendering::StandardMeshImpl::operator=(StandardMeshImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat = std::move(rhs.vertexFormat);
    transform = std::move(rhs.transform);
    isStatic = std::move(rhs.isStatic);
    inside = std::move(rhs.inside);
    hasNormals = std::move(rhs.hasNormals);
    usage = std::move(rhs.usage);

    hasTextureCoords = std::move(rhs.hasTextureCoords);

    return *this;
}

Rendering::StandardMeshImpl::StandardMeshImpl(StandardMeshImpl&& rhs) noexcept
    : vertexFormat{ std::move(rhs.vertexFormat) },
      transform{ std::move(rhs.transform) },
      isStatic{ std::move(rhs.isStatic) },
      inside{ std::move(rhs.inside) },
      hasNormals{ std::move(rhs.hasNormals) },
      hasTextureCoords{ std::move(rhs.hasTextureCoords) },
      usage{ std::move(rhs.usage) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, StandardMeshImpl)

void Rendering::StandardMeshImpl::SetTransform(const Mathematics::TransformF& aTransform) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    transform = aTransform;
}

const Mathematics::TransformF& Rendering::StandardMeshImpl::GetTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transform;
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Rectangle(int xSamples, int ySamples, MAYBE_UNUSED float xExtent, MAYBE_UNUSED float yExtent) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numTriangles = 2 * (xSamples - 1) * (ySamples - 1);
    const auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。
    const auto xSamplesInvertor = 1.0f / (xSamples - 1.0f);
    const auto ySamplesInvertor = 1.0f / (ySamples - 1.0f);

    auto totalIndex = 0;
    for (auto yIndex = 0; yIndex < ySamples; ++yIndex)
    {
        MAYBE_UNUSED const auto vTextureCoord = yIndex * ySamplesInvertor;

        for (auto xIndex = 0; xIndex < xSamples; ++xIndex)
        {
            MAYBE_UNUSED const auto uTextureCoord = xIndex * xSamplesInvertor;

            for (auto unit = 0; unit < maxUnits; ++unit)
            {
                if (hasTextureCoords.at(unit))
                {
                }
            }

            ++totalIndex;
        }
    }

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);

    totalIndex = 0;
    for (auto yIndex = 0; yIndex < ySamples - 1; ++yIndex)
    {
        for (auto xIndex = 0; xIndex < xSamples - 1; ++xIndex)
        {
            const auto firstIndex = xIndex + xSamples * yIndex;
            const auto secondIndex = firstIndex + 1;
            const auto thirdIndex = secondIndex + xSamples;
            const auto fourthIndex = firstIndex + xSamples;

            InitIndexBufferInRectangle(*indexBuffer, totalIndex, firstIndex, secondIndex, thirdIndex, fourthIndex);

            ++totalIndex;
        }
    }

    return std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);
}

// private
void Rendering::StandardMeshImpl::TransformData(MAYBE_UNUSED const VertexBuffer& vertexBufferAccessor, MAYBE_UNUSED VertexBuffer& vertexBuffer) const noexcept
{
    if (!transform.IsIdentity())
    {
    }
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Disk(int shellSamples, int radialSamples, MAYBE_UNUSED float radius) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto radialSamplesMinus1 = radialSamples - 1;
    const auto shellSamplesMinus1 = shellSamples - 1;
    MAYBE_UNUSED const auto numVertices = 1 + radialSamples * shellSamplesMinus1;
    const auto numTriangles = radialSamples * (2 * shellSamplesMinus1 - 1);
    const auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。

    for (auto unit = 0; unit < maxUnits; ++unit)
    {
        if (hasTextureCoords.at(unit))
        {
        }
    }

    const auto radialSamplesInvertor = 1.0f / static_cast<float>(radialSamples);
    for (auto radialIndex = 0; radialIndex < radialSamples; ++radialIndex)
    {
        auto angle = Math::GetTwoPI() * radialSamplesInvertor * radialIndex;
        auto angleCos = Math::Cos(angle);
        auto angleSin = Math::Sin(angle);
        const APoint radial{ angleCos, angleSin, 0.0f };
    }

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    InitIndexBufferInDisk(*indexBuffer, radialSamplesMinus1, shellSamplesMinus1);

    return std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Box(MAYBE_UNUSED float xExtent, MAYBE_UNUSED float yExtent, MAYBE_UNUSED float zExtent) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED constexpr auto numVertices = 8;
    constexpr auto numTriangles = 12;
    constexpr auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    for (auto unit = 0; unit < maxUnits; ++unit)
    {
        if (hasTextureCoords.at(unit))
        {
        }
    }

    // 生成索引（外视图）
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);

    std::vector<int> indices(36);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    indices.at(0) = 0;
    indices[1] = 2;
    indices[2] = 1;
    indices[3] = 0;
    indices[4] = 3;
    indices[5] = 2;
    indices[6] = 0;
    indices[7] = 1;
    indices[8] = 5;
    indices[9] = 0;
    indices[10] = 5;
    indices[11] = 4;
    indices[12] = 0;
    indices[13] = 4;
    indices[14] = 7;
    indices[15] = 0;
    indices[16] = 7;
    indices[17] = 3;
    indices[18] = 6;
    indices[19] = 4;
    indices[20] = 5;
    indices[21] = 6;
    indices[22] = 7;
    indices[23] = 4;
    indices[24] = 6;
    indices[25] = 5;
    indices[26] = 1;
    indices[27] = 6;
    indices[28] = 1;
    indices[29] = 2;
    indices[30] = 6;
    indices[31] = 2;
    indices[32] = 3;
    indices[33] = 6;
    indices[34] = 3;
    indices[35] = 7;

#include SYSTEM_WARNING_POP

    if (inside)
    {
        ReverseTriangleOrder(numTriangles, indices.data());
    }

    InitIndexBuffer(*indexBuffer, indices);

    auto mesh = std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);
    if (hasNormals)
    {
        mesh->UpdateModelSpace(VisualUpdateType::Normals);
    }

    return mesh;
}

// private
void Rendering::StandardMeshImpl::ReverseTriangleOrder(int numTriangles, int* indices) const noexcept
{
    if (indices != nullptr)
    {
        for (auto i = 0; i < numTriangles; ++i)
        {
            auto lhsIndex = 3 * i + 1;
            auto rhsIndex = lhsIndex + 1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            std::swap(indices[lhsIndex], indices[rhsIndex]);

#include SYSTEM_WARNING_POP
        }
    }
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::CylinderOmittedEndDisks(int axisSamples, int radialSamples, float radius, float height) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED const auto numVertices = axisSamples * (radialSamples + 1);
    const auto numTriangles = 2 * (axisSamples - 1) * radialSamples;
    const auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。
    const auto radialSamplesInvertor = 1.0f / boost::numeric_cast<float>(radialSamples);
    const auto radialSamplesMinus1Invertor = 1.0f / boost::numeric_cast<float>(axisSamples - 1);
    const auto halfHeight = 0.5f * height;

    // 产生单位圆上的点用于计算圆柱切片的网格点。
    const auto nextRadialSamples = radialSamples + 1;

    std::vector<float> angleCos(nextRadialSamples);
    std::vector<float> angleSin(nextRadialSamples);
    for (auto radialIndex = 0; radialIndex < radialSamples; ++radialIndex)
    {
        auto angle = Math::GetTwoPI() * radialSamplesInvertor * radialIndex;
        angleCos.at(radialIndex) = Math::Cos(angle);
        angleSin.at(radialIndex) = Math::Sin(angle);
    }

    angleCos.at(radialSamples) = angleCos.at(0);
    angleSin.at(radialSamples) = angleSin.at(0);

    // 生成圆柱本身。
    auto totalIndex = 0;
    for (auto axisIndex = 0; axisIndex < axisSamples; ++axisIndex)
    {
        const auto axisFraction = axisIndex * radialSamplesMinus1Invertor;  // 在 [0,1]
        const auto zCoordinate = -halfHeight + height * axisFraction;

        // 计算中心切片。
        const APoint sliceCenter{ 0.0f, 0.0f, zCoordinate };

        // 计算切片顶点在端点的复制。
        MAYBE_UNUSED const auto save = totalIndex;
        for (auto radialIndex = 0; radialIndex < radialSamples; ++radialIndex)
        {
            MAYBE_UNUSED const auto radialFraction = radialIndex * radialSamplesInvertor;  // in [0,1)
            const AVector normal{ angleCos.at(radialIndex), angleSin.at(radialIndex), 0.0f };

            for (auto unit = 0; unit < maxUnits; ++unit)
            {
                if (hasTextureCoords.at(unit))
                {
                }
            }

            ++totalIndex;
        }

        for (auto unit = 0; unit < maxUnits; ++unit)
        {
            if (hasTextureCoords.at(unit))
            {
            }
        }

        ++totalIndex;
    }

    // 产生索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    std::vector<int> indices(numIndices);
    size_t indicesIndex{};

    auto aStart = 0;
    for (auto axisIndex = 0; axisIndex < axisSamples - 1; ++axisIndex)
    {
        auto i0 = aStart;
        auto i1 = i0 + 1;
        aStart += radialSamples + 1;
        auto i2 = aStart;
        auto i3 = i2 + 1;
        for (totalIndex = 0; totalIndex < radialSamples; ++totalIndex, indicesIndex += 6)
        {
            if (inside)
            {
                indices.at(indicesIndex) = i0++;
                indices.at(indicesIndex + 1) = i2;
                indices.at(indicesIndex + 2) = i1;
                indices.at(indicesIndex + 3) = i1++;
                indices.at(indicesIndex + 4) = i2++;
                indices.at(indicesIndex + 5) = i3++;
            }
            else  // 外部视图
            {
                indices.at(indicesIndex) = i0++;
                indices.at(indicesIndex + 1) = i1;
                indices.at(indicesIndex + 2) = i2;
                indices.at(indicesIndex + 3) = i1++;
                indices.at(indicesIndex + 4) = i3++;
                indices.at(indicesIndex + 5) = i2++;
            }
        }
    }

    InitIndexBuffer(*indexBuffer, indices);

    auto mesh = std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);

    // 重复的顶点裂缝使自动生成的边界体积稍微偏离中心。
    // 重置边界使用真实的信息。
    auto maxDist = Math::Sqrt(radius * radius + height * height);
    mesh->GetModelBound().SetCenter(Mathematics::APointF::GetOrigin());
    mesh->GetModelBound().SetRadius(maxDist);

    return mesh;
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::CylinderIncludedEndDisks(int axisSamples, int radialSamples, float radius, float height) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto mesh = Sphere(axisSamples, radialSamples, radius);
    auto vertexBuffer = mesh->GetVertexBuffer();
    MAYBE_UNUSED const auto numVertices = vertexBuffer->GetNumElements();

    // 平铺球到两极
    MAYBE_UNUSED const auto heightDivide2 = 0.5f * height;

    // 重映射 z值到 [-h / 2,h / 2].
    const auto zFactor = 2.0f / (axisSamples - 1);
    MAYBE_UNUSED const auto tmp0 = radius * (-1.0f + zFactor);
    MAYBE_UNUSED const auto tmp1 = 1.0f / (radius * (+1.0f - zFactor));

    if (hasNormals)
    {
        mesh->UpdateModelSpace(VisualUpdateType::Normals);
    }

    // 重复的顶点裂缝使自动生成的边界体积稍微偏离中心。
    // 重置边界使用真实的信息。
    auto maxDist = Math::Sqrt(radius * radius + height * height);
    mesh->GetModelBound().SetCenter(Mathematics::APointF::GetOrigin());
    mesh->GetModelBound().SetRadius(maxDist);

    return mesh;
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Sphere(int zSamples, int radialSamples, float radius) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto zSamplesMinus1 = zSamples - 1;
    const auto zSamplesMinus2 = zSamples - 2;
    const auto zSamplesMinus3 = zSamples - 3;
    const auto radialSamplesPlus1 = radialSamples + 1;
    const auto numVertices = zSamplesMinus2 * radialSamplesPlus1 + 2;
    const auto numTriangles = 2 * zSamplesMinus2 * radialSamples;
    const auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。
    const auto radialSamplesInvertor = 1.0f / boost::numeric_cast<float>(radialSamples);
    const auto zFactor = 2.0f / boost::numeric_cast<float>(zSamplesMinus1);

    // 生成单位圆上的点，一个圆柱切片被计算网格点使用。
    std::vector<float> angleCos(radialSamplesPlus1);
    std::vector<float> angleSin(radialSamplesPlus1);

    for (auto radialSamplesIndex = 0; radialSamplesIndex < radialSamples; ++radialSamplesIndex)
    {
        auto angle = Math::GetTwoPI() * radialSamplesInvertor * radialSamplesIndex;
        angleCos.at(radialSamplesIndex) = Math::Cos(angle);
        angleSin.at(radialSamplesIndex) = Math::Sin(angle);
    }

    angleSin.at(radialSamples) = angleSin.at(0);
    angleCos.at(radialSamples) = angleCos.at(0);

    // 产生圆柱本身。
    auto totalIndex = 0;
    for (auto zSamplesIndex = 1; zSamplesIndex < zSamplesMinus1; ++zSamplesIndex)
    {
        const auto zFraction = -1.0f + zFactor * zSamplesIndex;  // in (-1,1)
        const auto zValue = radius * zFraction;

        // 计算切片的中心
        const APoint sliceCenter{ 0.0f, 0.0f, zValue };

        // 计算切片的半径
        MAYBE_UNUSED auto sliceRadius = Math::Sqrt(Math::FAbs(radius * radius - zValue * zValue));

        // 计算切片顶点和复制终点。
        MAYBE_UNUSED const auto save = totalIndex;
        for (auto radialSamplesIndex = 0; radialSamplesIndex < radialSamples; ++radialSamplesIndex)
        {
            MAYBE_UNUSED const auto radialFraction = radialSamplesIndex * radialSamplesInvertor;  // in [0,1)
            const AVector radial{ angleCos.at(radialSamplesIndex), angleSin.at(radialSamplesIndex), 0.0f };

            ++totalIndex;
        }

        ++totalIndex;
    }

    ++totalIndex;

    ++totalIndex;

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    std::vector<int> indices(numIndices);
    size_t indicesIndex{};

    auto zStart = 0;
    for (auto zSamplesIndex = 0; zSamplesIndex < zSamplesMinus3; ++zSamplesIndex)
    {
        auto i0 = zStart;
        auto i1 = i0 + 1;
        zStart += radialSamplesPlus1;
        auto i2 = zStart;
        auto i3 = i2 + 1;
        for (auto i = 0; i < radialSamples; ++i)
        {
            if (inside)
            {
                indices.at(indicesIndex) = i0++;
                indices.at(indicesIndex + 1) = i2;
                indices.at(indicesIndex + 2) = i1;
                indices.at(indicesIndex + 3) = i1++;
                indices.at(indicesIndex + 4) = i2++;
                indices.at(indicesIndex + 5) = i3++;
            }
            else  // 内部视图
            {
                indices.at(indicesIndex) = i0++;
                indices.at(indicesIndex + 1) = i1;
                indices.at(indicesIndex + 2) = i2;
                indices.at(indicesIndex + 3) = i1++;
                indices.at(indicesIndex + 4) = i3++;
                indices.at(indicesIndex + 5) = i2++;
            }

            indicesIndex += 6;
        }
    }

    // 南极三角形
    auto numVerticesMinus2 = numVertices - 2;
    for (auto i = 0; i < radialSamples; ++i)
    {
        if (inside)
        {
            indices.at(indicesIndex) = i;
            indices.at(indicesIndex + 1) = i + 1;
            indices.at(indicesIndex + 2) = numVerticesMinus2;
        }
        else
        {
            indices.at(indicesIndex) = i;
            indices.at(indicesIndex + 1) = numVerticesMinus2;
            indices.at(indicesIndex + 2) = i + 1;
        }

        indicesIndex += 3;
    }

    // 北极三角形
    auto numVerticesMinus1 = numVertices - 1;
    auto offset = zSamplesMinus3 * radialSamplesPlus1;
    for (auto i = 0; i < radialSamples; ++i)
    {
        if (inside)
        {
            indices.at(indicesIndex) = i + offset;
            indices.at(indicesIndex + 1) = numVerticesMinus1;
            indices.at(indicesIndex + 2) = i + 1 + offset;
        }
        else
        {
            indices.at(indicesIndex) = i + offset;
            indices.at(indicesIndex + 1) = i + 1 + offset;
            indices.at(indicesIndex + 2) = numVerticesMinus1;
        }

        indicesIndex += 3;
    }

    InitIndexBuffer(*indexBuffer, indices);

    // 重复的顶点裂缝使自动生成的边界体积稍微偏离中心。
    // 重置边界使用真实的信息。
    auto mesh = std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);

    mesh->GetModelBound().SetCenter(Mathematics::APointF::GetOrigin());
    mesh->GetModelBound().SetRadius(radius);

    return mesh;
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Torus(int circleSamples, int radialSamples, float outerRadius, MAYBE_UNUSED float innerRadius) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED const auto numVertices = (circleSamples + 1) * (radialSamples + 1);
    const auto numTriangles = 2 * circleSamples * radialSamples;
    const auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。
    const auto circleSamplesInvertor = 1.0f / static_cast<float>(circleSamples);
    const auto radialSamplesInvertor = 1.0f / static_cast<float>(radialSamples);

    // 产生圆柱体本身。
    auto totalIndex = 0;
    for (auto circleIndex = 0; circleIndex < circleSamples; ++circleIndex)
    {
        // 计算在规定的角度圆环的圆心。
        const auto circleFraction = circleIndex * circleSamplesInvertor;  // 在 [0,1)
        auto theta = Math::GetTwoPI() * circleFraction;
        auto cosTheta = Math::Cos(theta);
        auto sinTheta = Math::Sin(theta);
        const APoint radial{ cosTheta, sinTheta, 0.0f };
        const auto torusMiddle = outerRadius * radial;

        MAYBE_UNUSED const auto save = totalIndex;
        for (auto radialIndex = 0; radialIndex < radialSamples; ++radialIndex)
        {
            const auto radialFraction = radialIndex * radialSamplesInvertor;  // in [0,1)
            auto phi = Math::GetTwoPI() * radialFraction;
            auto cosPhi = Math::Cos(phi);
            auto sinPhi = Math::Sin(phi);
            const auto normal = cosPhi * radial - sinPhi * APoint(0.0f, 0.0f, -1.0f);

            ++totalIndex;
        }

        ++totalIndex;
    }

    // 重复圆柱体两端以形成一个环面。
    for (auto radialIndex = 0; radialIndex <= radialSamples; ++radialIndex)
    {
        ++totalIndex;
    }

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    std::vector<int> indices(numIndices);

    size_t indicesIndex{};
    auto cStart = 0;
    for (auto circleIndex = 0; circleIndex < circleSamples; ++circleIndex)
    {
        auto i0 = cStart;
        auto i1 = i0 + 1;
        cStart += radialSamples + 1;
        auto i2 = cStart;
        auto i3 = i2 + 1;
        for (auto i = 0; i < radialSamples; ++i)
        {
            if (inside)
            {
                indices.at(indicesIndex) = i0++;
                indices.at(indicesIndex + 1) = i1;
                indices.at(indicesIndex + 2) = i2;
                indices.at(indicesIndex + 3) = i1++;
                indices.at(indicesIndex + 4) = i3++;
                indices.at(indicesIndex + 5) = i2++;
            }
            else  // 内部视图
            {
                indices.at(indicesIndex) = i0++;
                indices.at(indicesIndex + 1) = i2;
                indices.at(indicesIndex + 2) = i1;
                indices.at(indicesIndex + 3) = i1++;
                indices.at(indicesIndex + 4) = i2++;
                indices.at(indicesIndex + 5) = i3++;
            }

            indicesIndex += 6;
        }
    }

    InitIndexBuffer(*indexBuffer, indices);

    // 重复的顶点裂缝使自动生成的边界体积稍微偏离中心。
    // 重置边界使用真实的信息。
    auto mesh = std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);

    mesh->GetModelBound().SetCenter(Mathematics::APointF::GetOrigin());
    mesh->GetModelBound().SetRadius(outerRadius);

    return mesh;
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Tetrahedron() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED auto fSqrt2Div3 = Math::Sqrt(2.0f) / 3.0f;
    MAYBE_UNUSED auto fSqrt6Div3 = Math::Sqrt(6.0f) / 3.0f;
    MAYBE_UNUSED constexpr auto fOneThird = 1.0f / 3.0f;

    MAYBE_UNUSED constexpr auto numVertices = 4;
    constexpr auto numTriangles = 4;
    constexpr auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    std::vector<int> indices(12);

    indices.at(0) = 0;
    indices.at(1) = 1;
    indices.at(2) = 2;
    indices.at(3) = 0;
    indices.at(4) = 2;
    indices.at(5) = 3;
    indices.at(6) = 0;
    indices.at(7) = 3;
    indices.at(8) = 1;
    indices.at(9) = 1;
    indices.at(10) = 3;
    indices.at(11) = 2;

    if (inside)
    {
        ReverseTriangleOrder(numTriangles, &indices.at(0));
    }

    InitIndexBuffer(*indexBuffer, indices);

    return std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Hexahedron() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED auto fSqrtThird = Math::Sqrt(1.0f / 3.0f);

    MAYBE_UNUSED constexpr auto numVertices = 8;
    constexpr auto numTriangles = 12;
    constexpr auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    std::vector<int> indices(numIndices);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    indices[0] = 0;
    indices[1] = 3;
    indices[2] = 2;
    indices[3] = 0;
    indices[4] = 2;
    indices[5] = 1;
    indices[6] = 0;
    indices[7] = 1;
    indices[8] = 5;
    indices[9] = 0;
    indices[10] = 5;
    indices[11] = 4;
    indices[12] = 0;
    indices[13] = 4;
    indices[14] = 7;
    indices[15] = 0;
    indices[16] = 7;
    indices[17] = 3;
    indices[18] = 6;
    indices[19] = 5;
    indices[20] = 1;
    indices[21] = 6;
    indices[22] = 1;
    indices[23] = 2;
    indices[24] = 6;
    indices[25] = 2;
    indices[26] = 3;
    indices[27] = 6;
    indices[28] = 3;
    indices[29] = 7;
    indices[30] = 6;
    indices[31] = 7;
    indices[32] = 4;
    indices[33] = 6;
    indices[34] = 4;
    indices[35] = 5;

#include SYSTEM_WARNING_POP

    if (inside)
    {
        ReverseTriangleOrder(numTriangles, &indices.at(0));
    }

    InitIndexBuffer(*indexBuffer, indices);

    return std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Octahedron() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED constexpr auto numVertices = 6;
    constexpr auto numTriangles = 8;
    constexpr auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    std::vector<int> indices(numIndices);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    indices[0] = 4;
    indices[1] = 0;
    indices[2] = 2;
    indices[3] = 4;
    indices[4] = 2;
    indices[5] = 1;
    indices[6] = 4;
    indices[7] = 1;
    indices[8] = 3;
    indices[9] = 4;
    indices[10] = 3;
    indices[11] = 0;
    indices[12] = 5;
    indices[13] = 2;
    indices[14] = 0;
    indices[15] = 5;
    indices[16] = 1;
    indices[17] = 2;
    indices[18] = 5;
    indices[19] = 3;
    indices[20] = 1;
    indices[21] = 5;
    indices[22] = 0;
    indices[23] = 3;

#include SYSTEM_WARNING_POP

    if (inside)
    {
        ReverseTriangleOrder(numTriangles, &indices.at(0));
    }

    InitIndexBuffer(*indexBuffer, indices);

    return std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Dodecahedron() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED const auto a = 1.0f / Math::Sqrt(3.0f);
    MAYBE_UNUSED auto b = Math::Sqrt((3.0f - Math::Sqrt(5.0f)) / 6.0f);
    MAYBE_UNUSED auto c = Math::Sqrt((3.0f + Math::Sqrt(5.0f)) / 6.0f);

    MAYBE_UNUSED constexpr auto numVertices = 20;
    constexpr auto numTriangles = 36;
    constexpr auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    std::vector<int> indices(numIndices);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    indices[0] = 0;
    indices[1] = 8;
    indices[2] = 9;
    indices[3] = 0;
    indices[4] = 9;
    indices[5] = 4;
    indices[6] = 0;
    indices[7] = 4;
    indices[8] = 16;
    indices[9] = 0;
    indices[10] = 12;
    indices[11] = 13;
    indices[12] = 0;
    indices[13] = 13;
    indices[14] = 1;
    indices[15] = 0;
    indices[16] = 1;
    indices[17] = 8;
    indices[18] = 0;
    indices[19] = 16;
    indices[20] = 17;
    indices[21] = 0;
    indices[22] = 17;
    indices[23] = 2;
    indices[24] = 0;
    indices[25] = 2;
    indices[26] = 12;
    indices[27] = 8;
    indices[28] = 1;
    indices[29] = 18;
    indices[30] = 8;
    indices[31] = 18;
    indices[32] = 5;
    indices[33] = 8;
    indices[34] = 5;
    indices[35] = 9;
    indices[36] = 12;
    indices[37] = 2;
    indices[38] = 10;
    indices[39] = 12;
    indices[40] = 10;
    indices[41] = 3;
    indices[42] = 12;
    indices[43] = 3;
    indices[44] = 13;
    indices[45] = 16;
    indices[46] = 4;
    indices[47] = 14;
    indices[48] = 16;
    indices[49] = 14;
    indices[50] = 6;
    indices[51] = 16;
    indices[52] = 6;
    indices[53] = 17;
    indices[54] = 9;
    indices[55] = 5;
    indices[56] = 15;
    indices[57] = 9;
    indices[58] = 15;
    indices[59] = 14;
    indices[60] = 9;
    indices[61] = 14;
    indices[62] = 4;
    indices[63] = 6;
    indices[64] = 11;
    indices[65] = 10;
    indices[66] = 6;
    indices[67] = 10;
    indices[68] = 2;
    indices[69] = 6;
    indices[70] = 2;
    indices[71] = 17;
    indices[72] = 3;
    indices[73] = 19;
    indices[74] = 18;
    indices[75] = 3;
    indices[76] = 18;
    indices[77] = 1;
    indices[78] = 3;
    indices[79] = 1;
    indices[80] = 13;
    indices[81] = 7;
    indices[82] = 15;
    indices[83] = 5;
    indices[84] = 7;
    indices[85] = 5;
    indices[86] = 18;
    indices[87] = 7;
    indices[88] = 18;
    indices[89] = 19;
    indices[90] = 7;
    indices[91] = 11;
    indices[92] = 6;
    indices[93] = 7;
    indices[94] = 6;
    indices[95] = 14;
    indices[96] = 7;
    indices[97] = 14;
    indices[98] = 15;
    indices[99] = 7;
    indices[100] = 19;
    indices[101] = 3;
    indices[102] = 7;
    indices[103] = 3;
    indices[104] = 10;
    indices[105] = 7;
    indices[106] = 10;
    indices[107] = 11;

#include SYSTEM_WARNING_POP

    if (inside)
    {
        ReverseTriangleOrder(numTriangles, indices.data());
    }

    InitIndexBuffer(*indexBuffer, indices);

    return std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);
}

Rendering::TrianglesMeshSharedPtr Rendering::StandardMeshImpl::Icosahedron() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto goldenRatio = 0.5f * (1.0f + Math::Sqrt(5.0f));
    const auto invRoot = 1.0f / Math::Sqrt(1.0f + goldenRatio * goldenRatio);
    MAYBE_UNUSED const auto u = goldenRatio * invRoot;
    MAYBE_UNUSED const auto v = invRoot;

    MAYBE_UNUSED constexpr auto numVertices = 12;
    constexpr auto numTriangles = 20;
    constexpr auto numIndices = 3 * numTriangles;
    const auto stride = vertexFormat->GetStride();

    // 创建一个顶点缓冲区
    auto vertexBuffer = VertexBuffer::Create(*vertexFormat, stride);

    // 生成几何数据。

    // 生成索引
    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, numIndices, 4);
    std::vector<int> indices(numIndices);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    indices[0] = 0;
    indices[1] = 8;
    indices[2] = 4;
    indices[3] = 0;
    indices[4] = 5;
    indices[5] = 10;
    indices[6] = 2;
    indices[7] = 4;
    indices[8] = 9;
    indices[9] = 2;
    indices[10] = 11;
    indices[11] = 5;
    indices[12] = 1;
    indices[13] = 6;
    indices[14] = 8;
    indices[15] = 1;
    indices[16] = 10;
    indices[17] = 7;
    indices[18] = 3;
    indices[19] = 9;
    indices[20] = 6;
    indices[21] = 3;
    indices[22] = 7;
    indices[23] = 11;
    indices[24] = 0;
    indices[25] = 10;
    indices[26] = 8;
    indices[27] = 1;
    indices[28] = 8;
    indices[29] = 10;
    indices[30] = 2;
    indices[31] = 9;
    indices[32] = 11;
    indices[33] = 3;
    indices[34] = 11;
    indices[35] = 9;
    indices[36] = 4;
    indices[37] = 2;
    indices[38] = 0;
    indices[39] = 5;
    indices[40] = 0;
    indices[41] = 2;
    indices[42] = 6;
    indices[43] = 1;
    indices[44] = 3;
    indices[45] = 7;
    indices[46] = 3;
    indices[47] = 1;
    indices[48] = 8;
    indices[49] = 6;
    indices[50] = 4;
    indices[51] = 9;
    indices[52] = 4;
    indices[53] = 6;
    indices[54] = 10;
    indices[55] = 5;
    indices[56] = 7;
    indices[57] = 11;
    indices[58] = 7;
    indices[59] = 5;

#include SYSTEM_WARNING_POP

    if (inside)
    {
        ReverseTriangleOrder(numTriangles, indices.data());
    }

    InitIndexBuffer(*indexBuffer, indices);

    return std::make_shared<TrianglesMesh>(vertexFormat->Clone(), vertexBuffer, indexBuffer);
}

void Rendering::StandardMeshImpl::InitIndexBufferInRectangle(IndexBuffer& indexBuffer, int index, int rectangleIndex0, int rectangleIndex1, int rectangleIndex2, int rectangleIndex3)
{
    const auto indexSize = indexBuffer.GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = indexBuffer.GetNumElements();
    const auto numRectangles = numVertices / 6;

    if (0 <= index && index < numRectangles)
    {
        if (indexSize == 2)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

            auto indices = reinterpret_cast<int16_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

            if (indices != nullptr)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[index * 6] = boost::numeric_cast<int16_t>(rectangleIndex0);
                indices[index * 6 + 1] = boost::numeric_cast<int16_t>(rectangleIndex1);
                indices[index * 6 + 2] = boost::numeric_cast<int16_t>(rectangleIndex2);
                indices[index * 6 + 3] = boost::numeric_cast<int16_t>(rectangleIndex0);
                indices[index * 6 + 4] = boost::numeric_cast<int16_t>(rectangleIndex2);
                indices[index * 6 + 5] = boost::numeric_cast<int16_t>(rectangleIndex3);

#include SYSTEM_WARNING_POP
            }
        }
        else  // indexSize == 4
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

            auto indices = reinterpret_cast<int32_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

            if (indices != nullptr)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[index * 6] = rectangleIndex0;
                indices[index * 6 + 1] = rectangleIndex1;
                indices[index * 6 + 2] = rectangleIndex2;
                indices[index * 6 + 3] = rectangleIndex0;
                indices[index * 6 + 4] = rectangleIndex2;
                indices[index * 6 + 5] = rectangleIndex3;

#include SYSTEM_WARNING_POP
            }
        }
    }
}

void Rendering::StandardMeshImpl::InitIndexBufferInDisk(IndexBuffer& indexBuffer, int radialSamplesMinus1, int shellSamplesMinus1)
{
    const auto indexSize = indexBuffer.GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    if (indexSize == 2)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int16_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

        if (indices != nullptr)
        {
            auto firstIndex = radialSamplesMinus1;

            for (auto secondIndex = 0; secondIndex <= radialSamplesMinus1; ++secondIndex)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[0] = 0;
                indices[1] = boost::numeric_cast<int16_t>(1 + shellSamplesMinus1 * firstIndex);
                indices[2] = boost::numeric_cast<int16_t>(1 + shellSamplesMinus1 * secondIndex);
                indices += 3;

                for (auto shellIndex = 1; shellIndex < shellSamplesMinus1; ++shellIndex)
                {
                    const auto index00 = boost::numeric_cast<int16_t>(shellIndex + shellSamplesMinus1 * firstIndex);
                    const auto index01 = boost::numeric_cast<int16_t>(shellIndex + shellSamplesMinus1 * secondIndex);
                    const auto index10 = boost::numeric_cast<int16_t>(index00 + 1);
                    const auto index11 = boost::numeric_cast<int16_t>(index01 + 1);

                    indices[0] = index00;
                    indices[1] = index10;
                    indices[2] = index11;
                    indices[3] = index00;
                    indices[4] = index11;
                    indices[5] = index01;

                    indices += 6;
                }

#include SYSTEM_WARNING_POP

                firstIndex = secondIndex;
            }
        }
    }
    else  // indexSize == 4
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int32_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

        if (indices != nullptr)
        {
            auto firstIndex = radialSamplesMinus1;

            for (auto secondIndex = 0; secondIndex <= radialSamplesMinus1; ++secondIndex)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[0] = 0;
                indices[1] = 1 + shellSamplesMinus1 * firstIndex;
                indices[2] = 1 + shellSamplesMinus1 * secondIndex;
                indices += 3;

                for (auto shellIndex = 1; shellIndex < shellSamplesMinus1; ++shellIndex)
                {
                    const auto index00 = shellIndex + shellSamplesMinus1 * firstIndex;
                    const auto index01 = shellIndex + shellSamplesMinus1 * secondIndex;
                    const auto index10 = index00 + 1;
                    const auto index11 = index01 + 1;

                    indices[0] = index00;
                    indices[1] = index10;
                    indices[2] = index11;
                    indices[3] = index00;
                    indices[4] = index11;
                    indices[5] = index01;

                    indices += 6;
                }

#include SYSTEM_WARNING_POP

                firstIndex = secondIndex;
            }
        }
    }
}

void Rendering::StandardMeshImpl::InitIndexBuffer(IndexBuffer& indexBuffer, const std::vector<int>& indices)
{
    const auto indexSize = indexBuffer.GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = boost::numeric_cast<size_t>(indexBuffer.GetNumElements());

    RENDERING_ASSERTION_1(numVertices == indices.size(), "索引数不对应。");

    if (indexSize == 2)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto accessWriteData = reinterpret_cast<int16_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

        if (accessWriteData != nullptr)
        {
            for (auto i = 0u; i < numVertices; ++i)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                accessWriteData[i] = boost::numeric_cast<int16_t>(indices.at(i));

#include SYSTEM_WARNING_POP
            }
        }
    }
    else  // indexSize == 4
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto accessWriteData = reinterpret_cast<int32_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

        if (accessWriteData != nullptr)
        {
            for (auto i = 0u; i < numVertices; ++i)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                accessWriteData[i] = indices.at(i);

#include SYSTEM_WARNING_POP
            }
        }
    }
}

// private
void Rendering::StandardMeshImpl::CreatePlatonicNormals(MAYBE_UNUSED const VertexBuffer& vertexBufferAccessor, MAYBE_UNUSED VertexBuffer& vertexBuffer) const noexcept
{
    if (hasNormals)
    {
    }
}

// private
void Rendering::StandardMeshImpl::CreatePlatonicTextures(MAYBE_UNUSED const VertexBuffer& vertexBufferAccessor, MAYBE_UNUSED VertexBuffer& vertexBuffer) const noexcept
{
}
