///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/02 16:08)

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
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "Rendering/SceneGraph/Culler.h"

using std::make_shared;
using std::vector;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Particles)

CORE_TOOLS_RTTI_DEFINE(Rendering, Particles);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Particles);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Particles);

Rendering::Particles::Particles(const VertexFormatSharedPtr& vertexformat,
                                const VertexBufferSharedPtr& vertexbuffer,
                                int indexSize,
                                const vector<APoint>& positions,
                                const vector<float>& sizes,
                                float sizeAdjust)
    : ParentType{ vertexformat, vertexbuffer, IndexBufferSharedPtr{} },
      impl{ positions, sizes, sizeAdjust }
{
    InitIndexBuffer(indexSize);
    InitTextureCoord();

    // ����߽緶Χ���������ӵ�λ�á�
    ComputeBounding(positions);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::Particles::InitIndexBuffer(int indexSize)
{
    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "��Ч������С��\n");

    auto numVertices = GetVertexBuffer()->GetNumElements();
    const auto numParticles = numVertices / 4;

    RENDERING_ASSERTION_1(numVertices % 4 == 0, "������������4�ı�����\n");
    RENDERING_ASSERTION_1(numParticles == impl->GetNumParticles(), "�����������λ�������С��ȡ�\n");

    auto indexBuffer = IndexBuffer::Create(6 * numParticles, indexSize);
    indexBuffer->InitIndexBufferInParticles();
    SetIndexBuffer(indexBuffer);
}

void Rendering::Particles::InitTextureCoord()
{
    // �õ����������ꡣ
    VertexBufferAccessor vertexBufferAccessor{ GetConstVertexFormat(), GetConstVertexBuffer() };

    RENDERING_ASSERTION_1(vertexBufferAccessor.HasTextureCoord(0), "����������������ʹ��ͨ��0\n");

    // ������������Ϊ��׼�ġ�
    GetVertexBuffer()->SetTextureCoordStandard(vertexBufferAccessor);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Particles)

Rendering::ControllerInterfaceSharedPtr Rendering::Particles::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Particles, GetNumParticles, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles, GetParticlesPosition, int, Rendering::Particles::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles, GetSize, int, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles, SetSizeAdjust, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Particles, GetSizeAdjust, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Particles, GetNumActive, int)

void Rendering::Particles::SetPosition(int index, const APoint& position)
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
    GetIndexBuffer()->SetNumElements(6 * numActive);
    GetVertexBuffer()->SetNumElements(4 * numActive);
}

void Rendering::Particles::GenerateParticles(const Camera& camera)
{
    RENDERING_CLASS_IS_VALID_1;

    // ��ȡλ�á�
    VertexBufferAccessor vertexBufferAccessor{ GetConstVertexFormat(), GetConstVertexBuffer() };
    RENDERING_ASSERTION_1(vertexBufferAccessor.HasPosition(), "Positions must exist\n");

    // ��ȡ������ģ�Ϳռ���������᷽��
    const auto transform = GetWorldTransform().GetInverseTransform();
    const auto upPlusRight = transform * (camera.GetUpVector() + camera.GetRightVector());
    const auto upMinusRight = transform * (camera.GetUpVector() - camera.GetRightVector());

    // �����ı�����һ�������Ρ�
    const auto numActive = impl->GetNumActive();
    for (auto index = 0; index < numActive; index += 4)
    {
        const auto position = impl->GetParticlesPosition(index);
        const auto trueSize = impl->GetTrueSize(index);
        auto scaledUpPlusRight = trueSize * upPlusRight;
        auto scaledUpMinusRight = trueSize * upMinusRight;

        GetVertexBuffer()->SetPosition(vertexBufferAccessor, index, position - scaledUpPlusRight);
        GetVertexBuffer()->SetPosition(vertexBufferAccessor, index + 1, position - scaledUpMinusRight);
        GetVertexBuffer()->SetPosition(vertexBufferAccessor, index + 2, position + scaledUpPlusRight);
        GetVertexBuffer()->SetPosition(vertexBufferAccessor, index + 3, position + scaledUpMinusRight);
    }

    UpdateModelSpace(VisualUpdateType::Normals);

    RENDERER_MANAGE_SINGLETON.UpdateAll(GetConstVertexBuffer());
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

uint64_t Rendering::Particles::Register(CoreTools::ObjectRegister& target) const
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
