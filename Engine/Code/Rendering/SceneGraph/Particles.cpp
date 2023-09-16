///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:17)

#include "Rendering/RenderingExport.h"

#include "Particles.h"
#include "Detail/ParticlesImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/SceneGraph/Culler.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Particles)

CORE_TOOLS_RTTI_DEFINE(Rendering, Particles);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Particles);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Particles);

Rendering::Particles::Particles(const VertexFormatSharedPtr& vertexformat,
                                const VertexBufferSharedPtr& vertexbuffer,
                                int indexSize,
                                const std::vector<Mathematics::Vector4F>& positions,
                                const std::vector<float>& sizes,
                                float sizeAdjust)
    : ParentType{ vertexformat, vertexbuffer, IndexBufferSharedPtr{} },
      impl{ positions, sizes, sizeAdjust }
{
    InitIndexBuffer(indexSize);
    InitTextureCoord();

    // 计算边界范围仅基于粒子的位置。
    std::vector<APoint> point{};
    for (const auto& element : positions)
    {
        point.emplace_back(APoint{ element[0], element[1], element[2] });
    }
    ComputeBounding(point);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::Particles::InitIndexBuffer(int indexSize)
{
    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "无效索引大小。\n");

    auto numVertices = GetVertexBuffer()->GetNumElements();
    const auto numParticles = numVertices / 4;

    RENDERING_ASSERTION_1(numVertices % 4 == 0, "顶点数必须是4的倍数。\n");
    RENDERING_ASSERTION_1(numParticles == impl->GetNumParticles(), "粒子数必须和位置数组大小相等。\n");

    auto indexBuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, 6 * numParticles, indexSize);
    InitIndexBufferInParticles(*indexBuffer);
    SetIndexBuffer(indexBuffer);
}

void Rendering::Particles::InitTextureCoord() noexcept
{
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Particles)

void Rendering::Particles::InitIndexBufferInParticles(IndexBuffer& indexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto indexSize = indexBuffer.GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = indexBuffer.GetNumElements();
    const auto numParticles = numVertices / 6;

    if (indexSize == 2)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int16_t*>(&*indexBuffer.GetData(0).GetCurrent());

#include SYSTEM_WARNING_POP

        if (indices != nullptr)
        {
            for (int16_t i{}; i < numParticles; ++i)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i * 6] = 4 * i;
                indices[i * 6 + 1] = 4 * i + 1;
                indices[i * 6 + 2] = 4 * i + 2;
                indices[i * 6 + 3] = 4 * i;
                indices[i * 6 + 4] = 4 * i + 2;
                indices[i * 6 + 5] = 4 * i + 3;

#include SYSTEM_WARNING_POP
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
            for (auto i = 0; i < numParticles; ++i)
            {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i * 6] = 4 * i;
                indices[i * 6 + 1] = 4 * i + 1;
                indices[i * 6 + 2] = 4 * i + 2;
                indices[i * 6 + 3] = 4 * i;
                indices[i * 6 + 4] = 4 * i + 2;
                indices[i * 6 + 5] = 4 * i + 3;

#include SYSTEM_WARNING_POP
            }
        }
    }
}

Rendering::ControllerInterfaceSharedPtr Rendering::Particles::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Particles, GetNumParticles, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles, GetParticlesPosition, int, Mathematics::Vector4F)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles, GetSize, int, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles, SetSizeAdjust, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Particles, GetSizeAdjust, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Particles, GetNumActive, int)

void Rendering::Particles::SetPosition(int index, const Mathematics::Vector4F& position)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPosition(index, position);
}

void Rendering::Particles::SetSize(int index, float size)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetSize(index, size);
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

    // 获取位置。

    // 获取在粒子模型空间中相机的轴方向。
    const auto transform = GetWorldTransform().GetInverseTransform();
    const auto upPlusRight = transform * (camera.GetUpVector() + camera.GetRightVector());
    const auto upMinusRight = transform * (camera.GetUpVector() - camera.GetRightVector());

    // 生成四边形像一对三角形。
    const auto numActive = impl->GetNumActive();
    for (auto index = 0; index < numActive; index += 4)
    {
        const auto position = impl->GetParticlesPosition(index);
        const auto trueSize = impl->GetTrueSize(index);
        auto scaledUpPlusRight = trueSize * upPlusRight;
        auto scaledUpMinusRight = trueSize * upMinusRight;
    }

    UpdateModelSpace(VisualUpdateType::Normals);
}

void Rendering::Particles::GetVisibleSet(Culler& culler, bool noCull)
{
    GenerateParticles(*culler.GetCamera());
    ParentType::GetVisibleSet(culler, noCull);
}

Rendering::Particles::Particles(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
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
