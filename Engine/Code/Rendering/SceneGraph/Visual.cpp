///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 20:01)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "Visual.h"
#include "Detail/VisualImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;
using std::vector;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Visual)

CORE_TOOLS_RTTI_DEFINE(Rendering, Visual);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Visual);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Visual);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, Visual);

Rendering::Visual::Visual(VisualPrimitiveType type)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ type }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual::Visual(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ type, vertexformat, vertexbuffer, indexbuffer }
{
    UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual::Visual(const Visual& rhs)
    : ParentType(rhs), impl{ rhs.GetPrimitiveType() }
{
    CloneData(rhs);

    UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual& Rendering::Visual::operator=(const Visual& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::operator=(rhs);

    impl = PackageType{ rhs.GetPrimitiveType() };

    CloneData(rhs);

    UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    return *this;
}

Rendering::Visual::Visual(Visual&& rhs) noexcept
    : ParentType{ std::move(rhs) },
      impl{ std::move(rhs.impl) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual& Rendering::Visual::operator=(Visual&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));
    impl = std::move(rhs.impl);

    return *this;
}

// private
void Rendering::Visual::CloneData(const Visual& rhs)
{
    CloneVertexFormat(rhs);
    CloneVertexBuffer(rhs);
    CloneIndexBuffer(rhs);
}

// private
void Rendering::Visual::CloneVertexFormat(const Visual& rhs)
{
    auto vertexFormat = rhs.GetConstVertexFormat();

    if (vertexFormat)
        SetVertexFormat(vertexFormat->Clone());
    else
        SetVertexFormat(VertexFormatSharedPtr{});
}

// private
void Rendering::Visual::CloneVertexBuffer(const Visual& rhs)
{
    auto vertexBuffer = rhs.GetConstVertexBuffer();

    if (vertexBuffer)
        SetVertexBuffer(vertexBuffer->Clone());
    else
        SetVertexBuffer(VertexBufferSharedPtr{});
}

// private
void Rendering::Visual::CloneIndexBuffer(const Visual& rhs)
{
    auto indexBuffer = rhs.GetConstIndexBuffer();

    if (indexBuffer)
        SetIndexBuffer(indexBuffer->Clone());
    else
        SetIndexBuffer(IndexBufferSharedPtr{});
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Visual)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetPrimitiveType, Rendering::VisualPrimitiveType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetConstVertexFormat, Rendering::ConstVertexFormatSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetVertexFormat, Rendering::VertexFormatSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Visual, SetVertexFormat, VertexFormatSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetConstVertexBuffer, Rendering::ConstVertexBufferSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetVertexBuffer, Rendering::VertexBufferSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Visual, SetVertexBuffer, VertexBufferSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetConstIndexBuffer, Rendering::ConstIndexBufferSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetIndexBuffer, Rendering::IndexBufferSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Visual, SetIndexBuffer, IndexBufferSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetConstEffectInstance, Rendering::ConstVisualEffectInstanceSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, Visual, SetEffectInstance, VisualEffectInstanceSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetEffectInstance, Rendering::VisualEffectInstanceSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetModelBound, const Rendering::BoundF&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Visual, GetModelBound, Rendering::BoundF&)

void Rendering::Visual::UpdateModelSpace(MAYBE_UNUSED VisualUpdateType type)
{
    UpdateModelBound();
}

void Rendering::Visual::UpdateWorldBound()
{
    const auto worldTransform = GetWorldTransform();
    const auto worldBound = impl->GetWorldBound(worldTransform);

    BoundGrowToContain(worldBound);
}

void Rendering::Visual::UpdateModelBound()
{
    impl->UpdateModelBound();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Visual, ComputeBounding, vector<APoint>, void)

void Rendering::Visual::GetVisibleSet(Culler& culler, MAYBE_UNUSED bool noCull)
{
    culler.Insert(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()));
}

Rendering::ConstVisualSharedPtr Rendering::Visual::GetSharedPtr() const
{
    return boost::polymorphic_pointer_cast<const ClassType>(shared_from_this());
}

Rendering::Visual::Visual(LoadConstructor value)
    : ParentType{ value }, impl{ VisualPrimitiveType::None }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Visual::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Visual::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerID = ParentType::Register(target);

    if (registerID != 0)
    {
        impl->Register(target);
    }

    return registerID;
}

void Rendering::Visual::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Visual::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::Visual::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Visual::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
