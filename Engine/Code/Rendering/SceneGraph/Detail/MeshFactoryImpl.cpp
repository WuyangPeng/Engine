/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:39)

#include "Rendering/RenderingExport.h"

#include "MeshFactoryImpl.h"
#include "System/FileManager/CFile.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <gsl/util>

Rendering::MeshFactoryImpl::MeshFactoryImpl(const std::string& name)
    : vertexFormat{ VertexFormat::Create(name, VertexFormat::AttributeContainer{ VertexFormatAttribute{ DataFormatType::R32G32B32Float, VertexFormatFlags::Semantic::Position, 0 } }) },
      indexSize{ CoreTools::GetStreamSize<int32_t>() },
      vertexBufferUsage{ UsageType::Immutable },
      indexBufferUsage{ UsageType::Immutable },
      outside{ true },
      assignTextureCoords{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::MeshFactoryImpl::MeshFactoryImpl(VertexFormatSharedPtr vertexFormat) noexcept
    : vertexFormat{ std::move(vertexFormat) },
      indexSize{ CoreTools::GetStreamSize<int32_t>() },
      vertexBufferUsage{ UsageType::Immutable },
      indexBufferUsage{ UsageType::Immutable },
      outside{ true },
      assignTextureCoords{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::MeshFactoryImpl::MeshFactoryImpl(VertexFormatSharedPtr vertexFormat, UsageType vertexBufferUsage) noexcept
    : vertexFormat{ std::move(vertexFormat) },
      indexSize{ CoreTools::GetStreamSize<int32_t>() },
      vertexBufferUsage{ vertexBufferUsage },
      indexBufferUsage{ UsageType::Immutable },
      outside{ true },
      assignTextureCoords{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MeshFactoryImpl)

void Rendering::MeshFactoryImpl::SetVertexFormat(const VertexFormatSharedPtr& format) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormat = format;
}

void Rendering::MeshFactoryImpl::SetVertexBufferUsage(UsageType usage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexBufferUsage = usage;
}

void Rendering::MeshFactoryImpl::SetIndexFormat(bool use32Bit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    indexSize = use32Bit ? CoreTools::GetStreamSize<int32_t>() : CoreTools::GetStreamSize<int16_t>();
}

void Rendering::MeshFactoryImpl::SetIndexBufferUsage(UsageType usage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    indexBufferUsage = usage;
}

void Rendering::MeshFactoryImpl::SetOutside(bool aOutside) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    outside = aOutside;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateRectangle(int numXSamples, int numYSamples, float xExtent, float yExtent)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto inv0 = 1.0f / (static_cast<float>(numXSamples) - 1.0f);
    const auto inv1 = 1.0f / (static_cast<float>(numYSamples) - 1.0f);
    const auto numVertices = numXSamples * numYSamples;
    const auto numTriangles = 2 * (numXSamples - 1) * (numYSamples - 1);

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    constexpr Vector3 normal{ 0.0f, 0.0f, 1.0f };
    constexpr Vector3 tangent{ 1.0f, 0.0f, 0.0f };
    constexpr Vector3 bitangent{ 0.0f, 1.0f, 0.0f };
    Vector2 textureCoordinate{};

    for (auto i1 = 0, i = 0; i1 < numYSamples; ++i1)
    {
        textureCoordinate[1] = static_cast<float>(i1) * inv1;
        position[1] = (2.0f * textureCoordinate[1] - 1.0f) * yExtent;
        for (auto i0 = 0; i0 < numXSamples; ++i0, ++i)
        {
            textureCoordinate[0] = static_cast<float>(i0) * inv0;
            position[0] = (2.0f * textureCoordinate[0] - 1.0f) * xExtent;

            SetPosition(i, position, meshVertexBuffer);
            SetNormal(i, normal, meshVertexBuffer);
            SetTangent(i, tangent, meshVertexBuffer);
            SetBitangent(i, bitangent, meshVertexBuffer);
            SetTextureCoordinate(i, textureCoordinate, meshVertexBuffer);
        }
    }

    auto indexBuffer = CreateIndexBuffer(numTriangles);

    for (auto i1 = 0, t = 0; i1 < numYSamples - 1; ++i1)
    {
        for (auto i0 = 0; i0 < numXSamples - 1; ++i0)
        {
            const auto v0 = i0 + numXSamples * i1;
            const auto v1 = v0 + 1;
            const auto v2 = v1 + numXSamples;
            const auto v3 = v0 + numXSamples;

            indexBuffer->SetTriangle(t++, v0, v1, v2);
            indexBuffer->SetTriangle(t++, v0, v2, v3);
        }
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->UpdateModelBound();

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateTriangle(int numSamples, float xExtent, float yExtent)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto inv = 1.0f / (static_cast<float>(numSamples) - 1.0f);
    const auto numVertices = numSamples * (numSamples + 1) / 2;
    const auto numTriangles = (numSamples - 1) * (numSamples - 1);

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    constexpr Vector3 normal{ 0.0f, 0.0f, 1.0f };
    constexpr Vector3 tangent{ 1.0f, 0.0f, 0.0f };
    constexpr Vector3 bitangent{ 0.0f, 1.0f, 0.0f };
    Vector2 textureCoordinate{};

    for (auto i1 = 0, i = 0; i1 < numSamples; ++i1)
    {
        textureCoordinate[1] = static_cast<float>(i1) * inv;
        position[1] = textureCoordinate[1] * yExtent;
        for (auto i0 = 0; i0 + i1 < numSamples; ++i0, ++i)
        {
            textureCoordinate[0] = static_cast<float>(i0) * inv;
            position[0] = textureCoordinate[0] * xExtent;

            SetPosition(i, position, meshVertexBuffer);
            SetNormal(i, normal, meshVertexBuffer);
            SetTangent(i, tangent, meshVertexBuffer);
            SetBitangent(i, bitangent, meshVertexBuffer);
            SetTextureCoordinate(i, textureCoordinate, meshVertexBuffer);
        }
    }
    const auto indexBuffer = CreateIndexBuffer(numTriangles);

    auto y0 = 0;
    auto y1 = numSamples;
    auto t = 0;
    for (auto i1 = 0; i1 < numSamples - 2; ++i1)
    {
        auto bot0 = y0;
        auto bot1 = bot0 + 1;
        auto top0 = y1;
        auto top1 = y1 + 1;
        for (auto i0 = 0; i0 + i1 < numSamples - 2; ++i0)
        {
            indexBuffer->SetTriangle(t++, bot0, bot1, top0);
            indexBuffer->SetTriangle(t++, bot1, top1, top0);
            bot0 = bot1++;
            top0 = top1++;
        }
        indexBuffer->SetTriangle(t++, bot0, bot1, top0);
        y0 = y1;
        y1 = top0 + 1;
    }
    indexBuffer->SetTriangle(t++, y0, y0 + 1, y1);

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->UpdateModelBound();

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateDisk(int numShellSamples, int numRadialSamples, float radius)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto shellSamplesMinus1 = numShellSamples - 1;
    const auto radialSamplesMinus1 = numRadialSamples - 1;
    const auto invShellSamplesMinus1 = 1.0f / static_cast<float>(shellSamplesMinus1);
    const auto invRadialSamplesMinus1 = 1.0f / static_cast<float>(numRadialSamples);
    const auto numVertices = 1 + numRadialSamples * shellSamplesMinus1;
    const auto numTriangles = numRadialSamples * (2 * shellSamplesMinus1 - 1);

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{ 0.0f, 0.0f, 0.0f };
    constexpr Vector3 normal{ 0.0f, 0.0f, 1.0f };
    constexpr Vector3 tangent{ 1.0f, 0.0f, 0.0f };
    constexpr Vector3 bitangent{ 0.0f, 1.0f, 0.0f };
    Vector2 textureCoordinate{ 0.5f, 0.5f };

    SetPosition(0, position, meshVertexBuffer);
    SetNormal(0, normal, meshVertexBuffer);
    SetTangent(0, tangent, meshVertexBuffer);
    SetBitangent(0, bitangent, meshVertexBuffer);
    SetTextureCoordinate(0, textureCoordinate, meshVertexBuffer);

    for (auto r = 0; r < numRadialSamples; ++r)
    {
        const auto angle = invRadialSamplesMinus1 * static_cast<float>(r) * Mathematics::MathF::GetTwoPI();
        const auto cs = std::cos(angle);
        const auto sn = std::sin(angle);
        const Vector3 radial{ cs, sn, 0.0f };

        for (auto s = 1; s < numShellSamples; ++s)
        {
            const auto fraction = invShellSamplesMinus1 * static_cast<float>(s);
            const auto fractionRadial = fraction * radial;
            const auto i = s + shellSamplesMinus1 * r;
            position = radius * fractionRadial;
            textureCoordinate[0] = 0.5f + 0.5f * fractionRadial[0];
            textureCoordinate[1] = 0.5f + 0.5f * fractionRadial[1];

            SetPosition(i, position, meshVertexBuffer);
            SetNormal(i, normal, meshVertexBuffer);
            SetTangent(i, tangent, meshVertexBuffer);
            SetBitangent(i, bitangent, meshVertexBuffer);
            SetTextureCoordinate(i, textureCoordinate, meshVertexBuffer);
        }
    }

    const auto indexBuffer = CreateIndexBuffer(numTriangles);

    for (auto r0 = radialSamplesMinus1, r1 = 0, t = 0; r1 < numRadialSamples; r0 = r1++)
    {
        indexBuffer->SetTriangle(t++, 0, 1 + shellSamplesMinus1 * r0, 1 + shellSamplesMinus1 * r1);

        for (auto s = 1; s < shellSamplesMinus1; ++s)
        {
            const auto i00 = s + shellSamplesMinus1 * r0;
            const auto i01 = s + shellSamplesMinus1 * r1;
            const auto i10 = i00 + 1;
            const auto i11 = i01 + 1;

            indexBuffer->SetTriangle(t++, i00, i10, i11);
            indexBuffer->SetTriangle(t++, i00, i11, i01);
        }
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->UpdateModelBound();

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateBox(float xExtent, float yExtent, float zExtent)
{
    RENDERING_CLASS_IS_VALID_9;

    constexpr auto numVertices = 8;
    constexpr auto numTriangles = 12;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};
    Vector2 textureCoordinate{};

    Vector3 diagonal{ xExtent, yExtent, zExtent };
    diagonal.Normalize();
    if (!outside)
    {
        diagonal = -diagonal;
    }

    for (auto z = 0, v = 0; z < 2; ++z)
    {
        const auto fz = static_cast<float>(z);
        const auto oneMinusFz = 1.0f - fz;
        const auto zSign = 2.0f * fz - 1.0f;
        position[2] = zSign * zExtent;
        normal[2] = zSign * diagonal[2];
        for (auto y = 0; y < 2; ++y)
        {
            const auto fy = static_cast<float>(y);
            const auto ySign = 2.0f * fy - 1.0f;
            position[1] = ySign * yExtent;
            normal[1] = ySign * diagonal[1];
            textureCoordinate[1] = (1.0f - fy) * oneMinusFz + (0.75f - 0.5f * fy) * fz;
            for (auto x = 0; x < 2; ++x, ++v)
            {
                const auto fx = static_cast<float>(x);
                const auto xSign = 2.0f * fx - 1.0f;
                position[0] = xSign * xExtent;
                normal[0] = xSign * diagonal[0];
                textureCoordinate[0] = fx * oneMinusFz + (0.25f + 0.5f * fx) * fz;

                basis.at(0) = normal;

                const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);

                SetPosition(v, position, meshVertexBuffer);
                SetNormal(v, normal, meshVertexBuffer);
                SetTangent(v, orthogonal.GetVVector(), meshVertexBuffer);
                SetBitangent(v, orthogonal.GetWVector(), meshVertexBuffer);
                SetTextureCoordinate(v, textureCoordinate, meshVertexBuffer);
            }
        }
    }

    const auto indexBuffer = CreateIndexBuffer(numTriangles);

    indexBuffer->SetTriangle(0, 0, 2, 3);
    indexBuffer->SetTriangle(1, 0, 3, 1);
    indexBuffer->SetTriangle(2, 0, 1, 5);
    indexBuffer->SetTriangle(3, 0, 5, 4);
    indexBuffer->SetTriangle(4, 0, 4, 6);
    indexBuffer->SetTriangle(5, 0, 6, 2);
    indexBuffer->SetTriangle(6, 7, 6, 4);
    indexBuffer->SetTriangle(7, 7, 4, 5);
    indexBuffer->SetTriangle(8, 7, 5, 1);
    indexBuffer->SetTriangle(9, 7, 1, 3);
    indexBuffer->SetTriangle(10, 7, 3, 2);
    indexBuffer->SetTriangle(11, 7, 2, 6);
    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->UpdateModelBound();

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateCylinderOpen(int numAxisSamples, int numRadialSamples, float radius, float height)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto numVertices = numAxisSamples * (numRadialSamples + 1);
    const auto numTriangles = 2 * (numAxisSamples - 1) * numRadialSamples;
    const auto invRadialSamples = 1.0f / static_cast<float>(numRadialSamples);
    const auto invASm1 = 1.0f / static_cast<float>(numAxisSamples - 1);
    const auto halfHeight = 0.5f * height;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};
    Vector2 textureCoordinate{};

    std::vector<float> cs(gsl::narrow_cast<size_t>(numRadialSamples) + 1);
    std::vector<float> sn(gsl::narrow_cast<size_t>(numRadialSamples) + 1);
    for (auto r = 0; r < numRadialSamples; ++r)
    {
        const auto angle = invRadialSamples * static_cast<float>(r) * Mathematics::MathF::GetTwoPI();
        cs.at(r) = std::cos(angle);
        sn.at(r) = std::sin(angle);
    }
    cs.at(numRadialSamples) = cs.at(0);
    sn.at(numRadialSamples) = sn.at(0);

    for (auto a = 0, i = 0; a < numAxisSamples; ++a)
    {
        const auto axisFraction = static_cast<float>(a) * invASm1;
        const auto z = -halfHeight + height * axisFraction;

        const Vector3 sliceCenter{ 0.0f, 0.0f, z };

        for (auto r = 0; r <= numRadialSamples; ++r, ++i)
        {
            const auto radialFraction = static_cast<float>(r) * invRadialSamples;
            normal = { cs.at(r), sn.at(r), 0.0f };
            position = sliceCenter + radius * normal;
            if (!outside)
            {
                normal = -normal;
            }

            basis.at(0) = normal;

            const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
            textureCoordinate = { radialFraction, axisFraction };

            SetPosition(i, position, meshVertexBuffer);
            SetNormal(i, normal, meshVertexBuffer);
            SetTangent(i, orthogonal.GetVVector(), meshVertexBuffer);
            SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
            SetTextureCoordinate(i, textureCoordinate, meshVertexBuffer);
        }
    }

    const auto indexBuffer = CreateIndexBuffer(numTriangles);
    for (auto a = 0, aStart = 0, t = 0; a < numAxisSamples - 1; ++a)
    {
        auto i0 = aStart;
        auto i1 = i0 + 1;
        aStart += numRadialSamples + 1;
        auto i2 = aStart;
        auto i3 = i2 + 1;
        for (auto i = 0; i < numRadialSamples; ++i, ++i0, ++i1, ++i2, ++i3)
        {
            indexBuffer->SetTriangle(t++, i0, i1, i2);
            indexBuffer->SetTriangle(t++, i1, i3, i2);
        }
    }
    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->UpdateModelBound();

    const auto maxDist = std::sqrt(radius * radius + height * height);
    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(maxDist);

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateCylinderClosed(int numAxisSamples, int numRadialSamples, float radius, float height)
{
    RENDERING_CLASS_IS_VALID_9;

    auto [meshVertexBuffer, visual] = DoCreateSphere(numAxisSamples, numRadialSamples, radius);

    const auto vertexBuffer = visual->GetVertexBuffer();
    const auto numVertices = vertexBuffer->GetNumElements();

    std::array<Vector3, 3> basis{};

    const auto hDiv2 = 0.5f * height;
    auto i = numVertices - 2;
    auto position = meshVertexBuffer.GetPosition(i, vertexFormat->GetVertexSize());
    position[2] = -hDiv2;
    SetPosition(i, position, meshVertexBuffer);
    i = numVertices - 1;
    position = meshVertexBuffer.GetPosition(i, vertexFormat->GetVertexSize());
    position[2] = +hDiv2;
    SetPosition(i, position, meshVertexBuffer);

    const auto zFactor = 2.0f / static_cast<float>(numAxisSamples - 1);
    const auto tmp0 = radius * (-1.0f + zFactor);
    const auto tmp1 = 1.0f / (radius * (+1.0f - zFactor));
    for (i = 0; i < numVertices - 2; ++i)
    {
        position = meshVertexBuffer.GetPosition(i, vertexFormat->GetVertexSize());
        position[2] = hDiv2 * (-1.0f + tmp1 * (position[2] - tmp0));
        const auto adjust = radius / std::sqrt(position[0] * position[0] + position[1] * position[1]);
        position[0] *= adjust;
        position[1] *= adjust;
        SetPosition(i, position, meshVertexBuffer);
    }

    visual->UpdateModelNormals();

    for (i = 0; i < numVertices; ++i)
    {
        basis.at(0) = meshVertexBuffer.GetNormal(i, vertexFormat->GetVertexSize());
        const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
        SetTangent(i, orthogonal.GetVVector(), meshVertexBuffer);
        SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
    }

    const auto maxDist = std::sqrt(radius * radius + height * height);
    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(maxDist);

    return visual;
}

Rendering::MeshFactoryImpl::SphereResult Rendering::MeshFactoryImpl::DoCreateSphere(int numZSamples, int numRadialSamples, float radius)
{
    const auto zsm1 = numZSamples - 1;
    const auto zsm2 = numZSamples - 2;
    const auto zsm3 = numZSamples - 3;
    const auto rsp1 = numRadialSamples + 1;
    const auto invRadialSamples = 1.0f / static_cast<float>(numRadialSamples);
    const auto zFactor = 2.0f / static_cast<float>(zsm1);
    const auto numVertices = zsm2 * rsp1 + 2;
    const auto numTriangles = 2 * zsm2 * numRadialSamples;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};
    Vector2 tcd{};

    std::vector<float> cs(rsp1);
    std::vector<float> sn(rsp1);
    for (auto r = 0; r < numRadialSamples; ++r)
    {
        const auto angle = invRadialSamples * static_cast<float>(r) * Mathematics::MathF::GetTwoPI();
        cs.at(r) = std::cos(angle);
        sn.at(r) = std::sin(angle);
    }
    cs.at(numRadialSamples) = cs.at(0);
    sn.at(numRadialSamples) = sn.at(0);

    auto i = 0;
    for (auto z = 1; z < zsm1; ++z)
    {
        const auto zFraction = -1.0f + zFactor * static_cast<float>(z);
        const auto zValue = radius * zFraction;

        const Vector3 sliceCenter{ 0.0f, 0.0f, zValue };

        const auto sliceRadius = std::sqrt(std::max(radius * radius - zValue * zValue, 0.0f));

        for (auto r = 0; r <= numRadialSamples; ++r, ++i)
        {
            const auto radialFraction = static_cast<float>(r) * invRadialSamples;
            const Vector3 radial{ cs.at(r), sn.at(r), 0.0f };
            position = sliceCenter + sliceRadius * radial;
            normal = position;
            normal.Normalize();
            if (!outside)
            {
                normal = -normal;
            }

            basis.at(0) = normal;
            const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
            tcd = { radialFraction, 0.5f * (zFraction + 1.0f) };

            SetPosition(i, position, meshVertexBuffer);
            SetNormal(i, normal, meshVertexBuffer);
            SetTangent(i, orthogonal.GetVVector(), meshVertexBuffer);
            SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
            SetTextureCoordinate(i, tcd, meshVertexBuffer);
        }
    }

    position = { 0.0f, 0.0f, -radius };
    if (outside)
    {
        normal = { 0.0f, 0.0f, -1.0f };
    }
    else
    {
        normal = { 0.0f, 0.0f, 1.0f };
    }
    basis.at(0) = normal;
    auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
    tcd = { 0.5f, 0.0f };
    SetPosition(i, position, meshVertexBuffer);
    SetNormal(i, normal, meshVertexBuffer);
    SetTangent(i, orthogonal.GetVVector(), meshVertexBuffer);
    SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
    SetTextureCoordinate(i, tcd, meshVertexBuffer);
    ++i;

    position = { 0.0f, 0.0f, radius };
    if (outside)
    {
        normal = { 0.0f, 0.0f, 1.0f };
    }
    else
    {
        normal = { 0.0f, 0.0f, -1.0f };
    }
    basis.at(0) = normal;
    orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
    tcd = { 0.5f, 1.0f };
    SetPosition(i, position, meshVertexBuffer);
    SetNormal(i, normal, meshVertexBuffer);
    SetTangent(i, orthogonal.GetVVector(), meshVertexBuffer);
    SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
    SetTextureCoordinate(i, tcd, meshVertexBuffer);

    auto indexBuffer = CreateIndexBuffer(numTriangles);

    auto t = 0;
    for (auto z = 0, zStart = 0; z < zsm3; ++z)
    {
        auto i0 = zStart;
        auto i1 = i0 + 1;
        zStart += rsp1;
        auto i2 = zStart;
        auto i3 = i2 + 1;
        for (i = 0; i < numRadialSamples; ++i, ++i0, ++i1, ++i2, ++i3)
        {
            indexBuffer->SetTriangle(t++, i0, i1, i2);
            indexBuffer->SetTriangle(t++, i1, i3, i2);
        }
    }

    const auto numVerticesM2 = numVertices - 2;
    for (i = 0; i < numRadialSamples; ++i, ++t)
    {
        indexBuffer->SetTriangle(t, i, numVerticesM2, i + 1);
    }

    const auto numVerticesM1 = numVertices - 1, offset = zsm3 * rsp1;
    for (i = 0; i < numRadialSamples; ++i, ++t)
    {
        indexBuffer->SetTriangle(t, i + offset, i + 1 + offset, numVerticesM1);
    }

    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);
    visual->UpdateModelBound();

    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(radius);

    return { meshVertexBuffer, visual };
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateSphere(int numZSamples, int numRadialSamples, float radius)
{
    RENDERING_CLASS_IS_VALID_9;

    return DoCreateSphere(numZSamples, numRadialSamples, radius).second;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateTorus(int numCircleSamples, int numRadialSamples, float outerRadius, float innerRadius)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto invCircleSamples = 1.0f / static_cast<float>(numCircleSamples);
    const auto invRadialSamples = 1.0f / static_cast<float>(numRadialSamples);
    const auto numVertices = (numCircleSamples + 1) * (numRadialSamples + 1);
    const auto numTriangles = 2 * numCircleSamples * numRadialSamples;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};
    Vector2 tcd{};

    auto i = 0;
    for (auto c = 0; c < numCircleSamples; ++c)
    {
        const auto circleFraction = static_cast<float>(c) * invCircleSamples;
        const auto theta = circleFraction * Mathematics::MathF::GetTwoPI();
        const auto cosTheta = std::cos(theta);
        const auto sinTheta = std::sin(theta);
        const Vector3 radial{ cosTheta, sinTheta, 0.0f };
        const auto torusMiddle = outerRadius * radial;

        for (auto r = 0; r <= numRadialSamples; ++r, ++i)
        {
            const auto radialFraction = static_cast<float>(r) * invRadialSamples;
            const auto phi = radialFraction * circleFraction * Mathematics::MathF::GetTwoPI();
            const auto cosPhi = std::cos(phi);
            const auto sinPhi = std::sin(phi);
            normal = cosPhi * radial + sinPhi * Vector3::GetUnitZ();

            position = torusMiddle + innerRadius * normal;
            if (!outside)
            {
                normal = -normal;
            }

            basis.at(0) = normal;
            const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
            tcd = { radialFraction, circleFraction };

            SetPosition(i, position, meshVertexBuffer);
            SetNormal(i, normal, meshVertexBuffer);
            SetTangent(i, orthogonal.GetWVector(), meshVertexBuffer);
            SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
            SetTextureCoordinate(i, tcd, meshVertexBuffer);
        }
    }

    for (auto r = 0; r <= numRadialSamples; ++r, ++i)
    {
        SetPosition(i, meshVertexBuffer.GetPosition(r, vertexFormat->GetVertexSize()), meshVertexBuffer);

        if (meshVertexBuffer.HasChannel(VertexFormatFlags::Semantic::Normal))
        {
            SetNormal(i, meshVertexBuffer.GetNormal(r, vertexFormat->GetVertexSize()), meshVertexBuffer);
        }
        if (meshVertexBuffer.HasChannel(VertexFormatFlags::Semantic::Tangent))
        {
            SetTangent(i, meshVertexBuffer.GetTangent(r, vertexFormat->GetVertexSize()), meshVertexBuffer);
        }
        if (meshVertexBuffer.HasChannel(VertexFormatFlags::Semantic::Binormal))
        {
            SetBitangent(i, meshVertexBuffer.GetBitangent(r, vertexFormat->GetVertexSize()), meshVertexBuffer);
        }
        for (auto unit = 0; unit < textureCoordinateUnits; ++unit)
        {
            if (assignTextureCoords.at(unit))
            {
                meshVertexBuffer.SetTextureCoordinate(unit, i, Vector2{ meshVertexBuffer.GetTextureCoordinate(unit, r, vertexFormat->GetVertexSize())[0], 1.0f }, vertexFormat->GetVertexSize());
            }
        }
    }

    auto indexBuffer = CreateIndexBuffer(numTriangles);
    auto t = 0;
    for (auto c = 0, cStart = 0; c < numCircleSamples; ++c)
    {
        auto i0 = cStart;
        auto i1 = i0 + 1;
        cStart += numRadialSamples + 1;
        auto i2 = cStart;
        auto i3 = i2 + 1;
        for (i = 0; i < numRadialSamples; ++i, ++i0, ++i1, ++i2, ++i3)
        {
            indexBuffer->SetTriangle(t++, i0, i2, i1);
            indexBuffer->SetTriangle(t++, i1, i2, i3);
        }
    }

    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->UpdateModelBound();

    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(outerRadius);

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateTetrahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto sqrt2Div3 = std::sqrt(2.0f) / 3.0f;
    const auto sqrt6Div3 = std::sqrt(6.0f) / 3.0f;
    constexpr auto oneThird = 1.0f / 3.0f;
    constexpr auto numVertices = 4;
    constexpr auto numTriangles = 4;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};

    SetPosition(0, { 0.0f, 0.0f, 1.0f }, meshVertexBuffer);
    SetPosition(1, { 2.0f * sqrt2Div3, 0.0f, -oneThird }, meshVertexBuffer);
    SetPosition(2, { -sqrt2Div3, sqrt6Div3, -oneThird }, meshVertexBuffer);
    SetPosition(3, { -sqrt2Div3, -sqrt6Div3, -oneThird }, meshVertexBuffer);
    for (auto i = 0; i < numVertices; ++i)
    {
        position = meshVertexBuffer.GetPosition(i, vertexFormat->GetVertexSize());
        normal = (outside ? position : -position);
        SetNormal(i, normal, meshVertexBuffer);
        basis.at(0) = normal;
        const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
        SetTangent(i, orthogonal.GetWVector(), meshVertexBuffer);
        SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
        SetPlatonicTextureCoordinate(i, position, meshVertexBuffer);
    }

    auto indexBuffer = CreateIndexBuffer(numTriangles);
    indexBuffer->SetTriangle(0, 0, 1, 2);
    indexBuffer->SetTriangle(1, 0, 2, 3);
    indexBuffer->SetTriangle(2, 0, 3, 1);
    indexBuffer->SetTriangle(3, 1, 3, 2);

    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(1.0f);

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateHexahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto sqrtThird = std::sqrt(1.0f / 3.0f);
    constexpr auto numVertices = 8;
    constexpr auto numTriangles = 12;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};

    SetPosition(0, { -sqrtThird, -sqrtThird, -sqrtThird }, meshVertexBuffer);
    SetPosition(1, { sqrtThird, -sqrtThird, -sqrtThird }, meshVertexBuffer);
    SetPosition(2, { sqrtThird, sqrtThird, -sqrtThird }, meshVertexBuffer);
    SetPosition(3, { -sqrtThird, sqrtThird, -sqrtThird }, meshVertexBuffer);
    SetPosition(4, { -sqrtThird, -sqrtThird, sqrtThird }, meshVertexBuffer);
    SetPosition(5, { sqrtThird, -sqrtThird, sqrtThird }, meshVertexBuffer);
    SetPosition(6, { sqrtThird, sqrtThird, sqrtThird }, meshVertexBuffer);
    SetPosition(7, { -sqrtThird, sqrtThird, sqrtThird }, meshVertexBuffer);
    for (auto i = 0; i < numVertices; ++i)
    {
        position = meshVertexBuffer.GetPosition(i, vertexFormat->GetVertexSize());
        normal = (outside ? position : -position);
        SetNormal(i, normal, meshVertexBuffer);
        basis.at(0) = normal;
        const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
        SetTangent(i, orthogonal.GetWVector(), meshVertexBuffer);
        SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
        SetPlatonicTextureCoordinate(i, position, meshVertexBuffer);
    }

    auto indexBuffer = CreateIndexBuffer(numTriangles);
    indexBuffer->SetTriangle(0, 0, 3, 2);
    indexBuffer->SetTriangle(1, 0, 2, 1);
    indexBuffer->SetTriangle(2, 0, 1, 5);
    indexBuffer->SetTriangle(3, 0, 5, 4);
    indexBuffer->SetTriangle(4, 0, 4, 7);
    indexBuffer->SetTriangle(5, 0, 7, 3);
    indexBuffer->SetTriangle(6, 6, 5, 1);
    indexBuffer->SetTriangle(7, 6, 1, 2);
    indexBuffer->SetTriangle(8, 6, 2, 3);
    indexBuffer->SetTriangle(9, 6, 3, 7);
    indexBuffer->SetTriangle(10, 6, 7, 4);
    indexBuffer->SetTriangle(11, 6, 4, 5);

    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(1.0f);

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateOctahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    constexpr auto numVertices = 6;
    constexpr auto numTriangles = 8;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};

    SetPosition(0, { 1.0f, 0.0f, 0.0f }, meshVertexBuffer);
    SetPosition(1, { -1.0f, 0.0f, 0.0f }, meshVertexBuffer);
    SetPosition(2, { 0.0f, 1.0f, 0.0f }, meshVertexBuffer);
    SetPosition(3, { 0.0f, -1.0f, 0.0f }, meshVertexBuffer);
    SetPosition(4, { 0.0f, 0.0f, 1.0f }, meshVertexBuffer);
    SetPosition(5, { 0.0f, 0.0f, -1.0f }, meshVertexBuffer);
    for (auto i = 0; i < numVertices; ++i)
    {
        position = meshVertexBuffer.GetPosition(i, vertexFormat->GetVertexSize());
        normal = (outside ? position : -position);
        SetNormal(i, normal, meshVertexBuffer);
        basis.at(0) = normal;
        const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
        SetTangent(i, orthogonal.GetWVector(), meshVertexBuffer);
        SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
        SetPlatonicTextureCoordinate(i, position, meshVertexBuffer);
    }

    auto indexBuffer = CreateIndexBuffer(numTriangles);
    indexBuffer->SetTriangle(0, 4, 0, 2);
    indexBuffer->SetTriangle(1, 4, 2, 1);
    indexBuffer->SetTriangle(2, 4, 1, 3);
    indexBuffer->SetTriangle(3, 4, 3, 0);
    indexBuffer->SetTriangle(4, 5, 2, 0);
    indexBuffer->SetTriangle(5, 5, 1, 2);
    indexBuffer->SetTriangle(6, 5, 3, 1);
    indexBuffer->SetTriangle(7, 5, 0, 3);

    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(1.0f);

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateDodecahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto a = 1.0f / std::sqrt(3.0f);
    const auto b = std::sqrt((3.0f - std::sqrt(5.0f)) / 6.0f);
    const auto c = std::sqrt((3.0f + std::sqrt(5.0f)) / 6.0f);
    constexpr auto numVertices = 20;
    constexpr auto numTriangles = 36;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};

    SetPosition(0, { a, a, a }, meshVertexBuffer);
    SetPosition(1, { a, a, -a }, meshVertexBuffer);
    SetPosition(2, { a, -a, a }, meshVertexBuffer);
    SetPosition(3, { a, -a, -a }, meshVertexBuffer);
    SetPosition(4, { -a, a, a }, meshVertexBuffer);
    SetPosition(5, { -a, a, -a }, meshVertexBuffer);
    SetPosition(6, { -a, -a, a }, meshVertexBuffer);
    SetPosition(7, { -a, -a, -a }, meshVertexBuffer);
    SetPosition(8, { b, c, 0.0f }, meshVertexBuffer);
    SetPosition(9, { -b, c, 0.0f }, meshVertexBuffer);
    SetPosition(10, { b, -c, 0.0f }, meshVertexBuffer);
    SetPosition(11, { -b, -c, 0.0f }, meshVertexBuffer);
    SetPosition(12, { c, 0.0f, b }, meshVertexBuffer);
    SetPosition(13, { c, 0.0f, -b }, meshVertexBuffer);
    SetPosition(14, { -c, 0.0f, b }, meshVertexBuffer);
    SetPosition(15, { -c, 0.0f, -b }, meshVertexBuffer);
    SetPosition(16, { 0.0f, b, c }, meshVertexBuffer);
    SetPosition(17, { 0.0f, -b, c }, meshVertexBuffer);
    SetPosition(18, { 0.0f, b, -c }, meshVertexBuffer);
    SetPosition(19, { 0.0f, -b, -c }, meshVertexBuffer);
    for (auto i = 0; i < numVertices; ++i)
    {
        position = meshVertexBuffer.GetPosition(i, vertexFormat->GetVertexSize());
        normal = (outside ? position : -position);
        SetNormal(i, normal, meshVertexBuffer);
        basis.at(0) = normal;
        const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);
        SetTangent(i, orthogonal.GetVVector(), meshVertexBuffer);
        SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
        SetPlatonicTextureCoordinate(i, position, meshVertexBuffer);
    }

    auto indexBuffer = CreateIndexBuffer(numTriangles);

    indexBuffer->SetTriangle(0, 0, 8, 9);
    indexBuffer->SetTriangle(1, 0, 9, 4);
    indexBuffer->SetTriangle(2, 0, 4, 16);
    indexBuffer->SetTriangle(3, 0, 12, 13);
    indexBuffer->SetTriangle(4, 0, 13, 1);
    indexBuffer->SetTriangle(5, 0, 1, 8);
    indexBuffer->SetTriangle(6, 0, 16, 17);
    indexBuffer->SetTriangle(7, 0, 17, 2);
    indexBuffer->SetTriangle(8, 0, 2, 12);
    indexBuffer->SetTriangle(9, 8, 1, 18);
    indexBuffer->SetTriangle(10, 8, 18, 5);
    indexBuffer->SetTriangle(11, 8, 5, 9);
    indexBuffer->SetTriangle(12, 12, 2, 10);
    indexBuffer->SetTriangle(13, 12, 10, 3);
    indexBuffer->SetTriangle(14, 12, 3, 13);
    indexBuffer->SetTriangle(15, 16, 4, 14);
    indexBuffer->SetTriangle(16, 16, 14, 6);
    indexBuffer->SetTriangle(17, 16, 6, 17);
    indexBuffer->SetTriangle(18, 9, 5, 15);
    indexBuffer->SetTriangle(19, 9, 15, 14);
    indexBuffer->SetTriangle(20, 9, 14, 4);
    indexBuffer->SetTriangle(21, 6, 11, 10);
    indexBuffer->SetTriangle(22, 6, 10, 2);
    indexBuffer->SetTriangle(23, 6, 2, 17);
    indexBuffer->SetTriangle(24, 3, 19, 18);
    indexBuffer->SetTriangle(25, 3, 18, 1);
    indexBuffer->SetTriangle(26, 3, 1, 13);
    indexBuffer->SetTriangle(27, 7, 15, 5);
    indexBuffer->SetTriangle(28, 7, 5, 18);
    indexBuffer->SetTriangle(29, 7, 18, 19);
    indexBuffer->SetTriangle(30, 7, 11, 6);
    indexBuffer->SetTriangle(31, 7, 6, 14);
    indexBuffer->SetTriangle(32, 7, 14, 15);
    indexBuffer->SetTriangle(33, 7, 19, 3);
    indexBuffer->SetTriangle(34, 7, 3, 10);
    indexBuffer->SetTriangle(35, 7, 10, 11);

    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(1.0f);

    return visual;
}

Rendering::VisualSharedPtr Rendering::MeshFactoryImpl::CreateIcosahedron()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto goldenRatio = 0.5f * (1.0f + std::sqrt(5.0f));
    const auto invRoot = 1.0f / std::sqrt(1.0f + goldenRatio * goldenRatio);
    const auto u = goldenRatio * invRoot;
    const auto v = invRoot;
    constexpr auto numVertices = 12;
    constexpr auto numTriangles = 20;

    auto meshVertexBuffer = CreateMeshVertexBuffer(numVertices);

    Vector3 position{};
    Vector3 normal{};
    std::array<Vector3, 3> basis{};

    SetPosition(0, { u, v, 0.0f }, meshVertexBuffer);
    SetPosition(1, { -u, v, 0.0f }, meshVertexBuffer);
    SetPosition(2, { u, -v, 0.0f }, meshVertexBuffer);
    SetPosition(3, { -u, -v, 0.0f }, meshVertexBuffer);
    SetPosition(4, { v, 0.0f, u }, meshVertexBuffer);
    SetPosition(5, { v, 0.0f, -u }, meshVertexBuffer);
    SetPosition(6, { -v, 0.0f, u }, meshVertexBuffer);
    SetPosition(7, { -v, 0.0f, -u }, meshVertexBuffer);
    SetPosition(8, { 0.0f, u, v }, meshVertexBuffer);
    SetPosition(9, { 0.0f, -u, v }, meshVertexBuffer);
    SetPosition(10, { 0.0f, u, -v }, meshVertexBuffer);
    SetPosition(11, { 0.0f, -u, -v }, meshVertexBuffer);
    for (auto i = 0; i < numVertices; ++i)
    {
        position = meshVertexBuffer.GetPosition(i, vertexFormat->GetVertexSize());
        normal = (outside ? position : -position);
        SetNormal(i, normal, meshVertexBuffer);
        basis.at(0) = normal;
        const auto orthogonal = Mathematics::Vector3ToolsF::ComputeOrthogonalComplement(1, basis);

        SetTangent(i, orthogonal.GetVVector(), meshVertexBuffer);
        SetBitangent(i, orthogonal.GetWVector(), meshVertexBuffer);
        SetPlatonicTextureCoordinate(i, position, meshVertexBuffer);
    }

    const auto indexBuffer = CreateIndexBuffer(numTriangles);

    indexBuffer->SetTriangle(0, 0, 8, 4);
    indexBuffer->SetTriangle(1, 0, 5, 10);
    indexBuffer->SetTriangle(2, 2, 4, 9);
    indexBuffer->SetTriangle(3, 2, 11, 5);
    indexBuffer->SetTriangle(4, 1, 6, 8);
    indexBuffer->SetTriangle(5, 1, 10, 7);
    indexBuffer->SetTriangle(6, 3, 9, 6);
    indexBuffer->SetTriangle(7, 3, 7, 11);
    indexBuffer->SetTriangle(8, 0, 10, 8);
    indexBuffer->SetTriangle(9, 1, 8, 10);
    indexBuffer->SetTriangle(10, 2, 9, 11);
    indexBuffer->SetTriangle(11, 3, 11, 9);
    indexBuffer->SetTriangle(12, 4, 2, 0);
    indexBuffer->SetTriangle(13, 5, 0, 2);
    indexBuffer->SetTriangle(14, 6, 1, 3);
    indexBuffer->SetTriangle(15, 7, 3, 1);
    indexBuffer->SetTriangle(16, 8, 6, 4);
    indexBuffer->SetTriangle(17, 9, 4, 6);
    indexBuffer->SetTriangle(18, 10, 5, 7);
    indexBuffer->SetTriangle(19, 11, 7, 5);

    if (!outside)
    {
        ReverseTriangleOrder(*indexBuffer);
    }

    const auto visual = std::make_shared<Visual>(vertexFormat->GetName(), meshVertexBuffer.GetVertexBuffer(), indexBuffer);

    visual->GetModelBound().SetCenter({ 0.0f, 0.0f, 0.0f });
    visual->GetModelBound().SetRadius(1.0f);

    return visual;
}

Rendering::MeshVertexBuffer Rendering::MeshFactoryImpl::CreateMeshVertexBuffer(int numVertices)
{
    const auto vertexBuffer = VertexBuffer::Create(vertexFormat->GetName(), *vertexFormat, numVertices);
    vertexBuffer->SetUsage(vertexBufferUsage);

    MeshVertexBuffer meshVertexBuffer{ vertexBuffer };

    meshVertexBuffer.SetGeometricChannel(VertexFormatFlags::Semantic::Position, 1.0f, *vertexFormat);
    meshVertexBuffer.SetGeometricChannel(VertexFormatFlags::Semantic::Normal, 0.0f, *vertexFormat);
    meshVertexBuffer.SetGeometricChannel(VertexFormatFlags::Semantic::Tangent, 0.0f, *vertexFormat);
    meshVertexBuffer.SetGeometricChannel(VertexFormatFlags::Semantic::Binormal, 0.0f, *vertexFormat);

    const VertexBuffer::DataFormatTypeContainer required{ DataFormatType::R32G32Float };

    for (auto unit = 0; unit < textureCoordinateUnits; ++unit)
    {
        try
        {
            const auto channel = vertexBuffer->GetChannel(VertexFormatFlags::Semantic::TextureCoord, unit, required);
            meshVertexBuffer.AddTextureCoords(unit, channel);
            assignTextureCoords.at(unit) = true;
        }
        catch (const CoreTools::Error&)
        {
            assignTextureCoords.at(unit) = false;
        }
    }

    return meshVertexBuffer;
}

Rendering::IndexBufferSharedPtr Rendering::MeshFactoryImpl::CreateIndexBuffer(int numTriangles) const
{
    auto indexBuffer = IndexBuffer::Create(vertexFormat->GetName(), IndexFormatType::TriangleMesh, numTriangles, indexSize);

    indexBuffer->SetUsage(indexBufferUsage);

    return indexBuffer;
}

void Rendering::MeshFactoryImpl::SetPosition(int index, const Vector3& position, MeshVertexBuffer& meshVertexBuffer)
{
    meshVertexBuffer.SetPosition(index, position, vertexFormat->GetVertexSize());
}

void Rendering::MeshFactoryImpl::SetNormal(int index, const Vector3& normal, MeshVertexBuffer& meshVertexBuffer)
{
    meshVertexBuffer.SetNormal(index, normal, vertexFormat->GetVertexSize());
}

void Rendering::MeshFactoryImpl::SetTangent(int index, const Vector3& tangent, MeshVertexBuffer& meshVertexBuffer)
{
    meshVertexBuffer.SetTangent(index, tangent, vertexFormat->GetVertexSize());
}

void Rendering::MeshFactoryImpl::SetBitangent(int index, const Vector3& bitangent, MeshVertexBuffer& meshVertexBuffer)
{
    meshVertexBuffer.SetBitangent(index, bitangent, vertexFormat->GetVertexSize());
}

void Rendering::MeshFactoryImpl::SetTextureCoordinate(int index, const Vector2& textureCoordinates, MeshVertexBuffer& meshVertexBuffer)
{
    for (auto unit = 0; unit < textureCoordinateUnits; ++unit)
    {
        meshVertexBuffer.SetTextureCoordinate(unit, index, textureCoordinates, vertexFormat->GetVertexSize());
    }
}

void Rendering::MeshFactoryImpl::SetPlatonicTextureCoordinate(int index, const Vector3& position, MeshVertexBuffer& meshVertexBuffer)
{
    Vector2 textureCoordinate{};
    if (Mathematics::MathF::FAbs(position[2]) < 1.0f)
    {
        textureCoordinate[0] = 0.5f * (1.0f + Mathematics::MathF::ATan2(position[1], position[0]) * Mathematics::MathF::GetInversePI());
    }
    else
    {
        textureCoordinate[0] = 0.5f;
    }

    textureCoordinate[1] = Mathematics::MathF::ACos(position[2]) * Mathematics::MathF::GetInversePI();

    for (auto unit = 0; unit < textureCoordinateUnits; ++unit)
    {
        meshVertexBuffer.SetTextureCoordinate(unit, index, textureCoordinate, vertexFormat->GetVertexSize());
    }
}

void Rendering::MeshFactoryImpl::ReverseTriangleOrder(IndexBuffer& indexBuffer)
{
    const auto numTriangles = indexBuffer.GetNumPrimitives();
    for (auto t = 0; t < numTriangles; ++t)
    {
        const auto triangle = indexBuffer.GetTriangle(t);
        indexBuffer.SetTriangle(t, get<0>(triangle), get<2>(triangle), get<1>(triangle));
    }
}
