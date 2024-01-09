/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:56)

#include "Rendering/RenderingExport.h"

#include "Particles.h"
#include "Detail/ParticlesImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "Rendering/Visibility/Culler.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Particles)

CORE_TOOLS_RTTI_DEFINE(Rendering, Particles)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Particles);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Particles);

Rendering::Particles::Particles(const Container& positionSize, float sizeAdjust, const VertexFormat& vertexFormat)
    : ParentType{ "", nullptr, nullptr },
      impl{ positionSize, sizeAdjust }
{
    Check(vertexFormat);

    const auto numParticles = impl->GetNumActive();
    const auto numVertices = 4 * numParticles;
    const auto vertexBuffer = VertexBuffer::Create("", vertexFormat, numVertices);
    vertexBuffer->SetUsage(UsageType::DynamicUpdate);
    const auto vertexSize = vertexFormat.GetVertexSize();
    const auto index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::TextureCoord, 0);
    const auto offset = vertexFormat.GetOffset(index);
    auto textureCoord = vertexBuffer->GetStorage(offset);
    std::array commonTextureCoord{ Vector2{ 0.0f, 0.0f },
                                   Vector2{ 1.0f, 0.0f },
                                   Vector2{ 1.0f, 1.0f },
                                   Vector2{ 0.0f, 1.0f } };
    const auto step = vertexSize - Mathematics::GetStreamSize<Vector2>();
    if (step < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("步进值错误。"))
    }

    for (auto i = 0; i < numParticles; ++i)
    {
        for (auto j = 0; j < 4; ++j)
        {
            textureCoord.Increase(commonTextureCoord.at(j)[0]);
            textureCoord.Increase(commonTextureCoord.at(j)[1]);

            if (0 < step)
            {
                textureCoord += step;
            }
        }
    }
    SetVertexBuffer(vertexBuffer);

    const auto indexBuffer = IndexBuffer::Create("", IndexFormatType::TriangleMesh, 2 * numParticles, Mathematics::GetStreamSize<int32_t>());
    auto indices = indexBuffer->GetStorage();
    for (auto i = 0; i < numParticles; ++i)
    {
        const auto iFI = 4 * i;
        const auto iFIp1 = iFI + 1;
        const auto iFIp2 = iFI + 2;
        const auto iFIp3 = iFI + 3;
        indices.Increase(iFI);
        indices.Increase(iFIp1);
        indices.Increase(iFIp2);
        indices.Increase(iFI);
        indices.Increase(iFIp2);
        indices.Increase(iFIp3);
    }
    SetIndexBuffer(indexBuffer);

    UpdateModelBound();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Particles)

Rendering::ControllerInterfaceSharedPtr Rendering::Particles::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

int Rendering::Particles::GetNumParticles() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumParticles();
}

Mathematics::Vector4F Rendering::Particles::GetParticlesPosition(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetParticlesPosition(index);
}

void Rendering::Particles::SetSizeAdjust(float sizeAdjust)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetSizeAdjust(sizeAdjust);
}

float Rendering::Particles::GetSizeAdjust() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetSizeAdjust();
}

int Rendering::Particles::GetNumActive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumActive();
}

void Rendering::Particles::Check(const VertexFormat& vertexFormat) const
{
    auto index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::Position, 0);
    if (index < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点格式没有Semantic::Position"))
    }

    const auto posType = vertexFormat.GetAttributeType(index);
    if (posType != DataFormatType::R32G32B32A32Float && posType != DataFormatType::R32G32B32Float)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("位置类型无效"))
    }

    auto offset = vertexFormat.GetOffset(index);
    if (offset != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("位置偏移必须为0"))
    }

    index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::TextureCoord, 0);
    if (index < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点格式没有Semantic::TextureCoord"))
    }

    if (const auto texType = vertexFormat.GetAttributeType(index);
        texType != DataFormatType::R32G32Float)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理坐标类型无效"))
    }

    const auto texOffset = (posType == DataFormatType::R32G32B32Float ? 3 * CoreTools::GetStreamSize<float>() : 4 * CoreTools::GetStreamSize<float>());
    offset = vertexFormat.GetOffset(index);
    if (offset != texOffset)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理坐标必须紧跟位置"))
    }
}

void Rendering::Particles::SetPosition(int index, const Mathematics::Vector4F& position)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPosition(index, position);
}

void Rendering::Particles::SetNumActive(int numActive)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetNumActive(numActive);
    numActive = impl->GetNumActive();
    GetIndexBuffer()->SetNumActiveElements(6 * numActive);
    GetVertexBuffer()->SetNumActiveElements(4 * numActive);
}

void Rendering::Particles::GenerateParticles(const Camera& camera)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto vertexBuffer = GetVertexBuffer();

    const VertexFormat vertexFormat = vertexBuffer->GetFormat();
    const auto vertexSize = vertexFormat.GetVertexSize();
    auto vertices = vertexBuffer->GetStorage();

    const auto inverse = GetWorldTransform().GetInverseMatrix();
    const auto upR = inverse * (camera.GetUpVector() + camera.GetRightVector());
    const auto umR = inverse * (camera.GetUpVector() - camera.GetRightVector());

    const auto step = vertexSize - Mathematics::GetStreamSize<Vector2>();
    if (step < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("步进值错误。"))
    }

    for (auto i = 0; i < impl->GetNumActive(); ++i)
    {
        const auto posSize = impl->GetParticlesPosition(i);

        const Vector3 position{ posSize[0], posSize[1], posSize[2] };
        const auto trueSize = impl->GetSizeAdjust() * posSize[3];
        const auto scaledUpR = (trueSize * upR).GetVector3();
        const auto scaledUmR = (trueSize * umR).GetVector3();

        const auto pos0 = position - scaledUpR;
        vertices.Increase(pos0.GetX());
        vertices.Increase(pos0.GetY());
        vertices.Increase(pos0.GetZ());

        if (0 < step)
        {
            vertices += step;
        }

        const auto pos1 = position - scaledUmR;
        vertices.Increase(pos0.GetX());
        vertices.Increase(pos0.GetY());
        vertices.Increase(pos0.GetZ());

        if (0 < step)
        {
            vertices += step;
        }

        const auto pos2 = position + scaledUpR;
        vertices.Increase(pos0.GetX());
        vertices.Increase(pos0.GetY());
        vertices.Increase(pos0.GetZ());

        if (0 < step)
        {
            vertices += step;
        }

        const auto pos3 = position + scaledUmR;
        vertices.Increase(pos0.GetX());
        vertices.Increase(pos0.GetY());
        vertices.Increase(pos0.GetZ());

        if (0 < step)
        {
            vertices += step;
        }
    }

    UpdateModelBound();
}

Rendering::Particles::Particles(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Particles::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Particles::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Particles::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Particles::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Particles::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Particles::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
