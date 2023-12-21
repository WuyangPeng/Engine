/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/20 09:55)

#include "Rendering/RenderingExport.h"

#include "Culler.h"
#include "Visual.h"
#include "Flags/VisualFlags.h"
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

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Visual)

CORE_TOOLS_RTTI_DEFINE(Rendering, Visual);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Visual);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Visual);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, Visual)

Rendering::Visual::Visual(const std::string& name)
    : ParentType{ name }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual::Visual(const std::string& name, const VertexFormatSharedPtr& vertexFormat, const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer)
    : ParentType{ name }, impl{ vertexFormat, vertexBuffer, indexBuffer }
{
    ClassType::UpdateModelSpace(VisualUpdateType::ModelBoundOnly);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Visual)

Rendering::IndexFormatType Rendering::Visual::GetPrimitiveType() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPrimitiveType();
}

void Rendering::Visual::SetVertexFormat(const VertexFormatSharedPtr& vertexFormat) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertexFormat(vertexFormat);
}

Rendering::ConstVertexFormatSharedPtr Rendering::Visual::GetConstVertexFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstVertexFormat();
}

Rendering::VertexFormatSharedPtr Rendering::Visual::GetVertexFormat() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVertexFormat();
}

void Rendering::Visual::SetVertexBuffer(const VertexBufferSharedPtr& vertexBuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertexBuffer(vertexBuffer);
}

Rendering::ConstVertexBufferSharedPtr Rendering::Visual::GetConstVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstVertexBuffer();
}

Rendering::VertexBufferSharedPtr Rendering::Visual::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVertexBuffer();
}

void Rendering::Visual::SetIndexBuffer(const IndexBufferSharedPtr& indexBuffer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetIndexBuffer(indexBuffer);
}

Rendering::ConstIndexBufferSharedPtr Rendering::Visual::GetConstIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstIndexBuffer();
}

Rendering::IndexBufferSharedPtr Rendering::Visual::GetIndexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetIndexBuffer();
}

const Mathematics::BoundingSphereF& Rendering::Visual::GetModelBound() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetModelBound();
}

Rendering::Visual::BoundingSphere& Rendering::Visual::GetModelBound() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetModelBound();
}

void Rendering::Visual::UpdateModelSpace(VisualUpdateType type)
{
    System::UnusedFunction(type);

    UpdateModelBound();
}

void Rendering::Visual::SetVisualEffect(const VisualEffectSharedPtr& visualEffect) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVisualEffect(visualEffect);
}

Rendering::ConstVisualEffectSharedPtr Rendering::Visual::GetConstVisualEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstVisualEffect();
}

Rendering::Visual::VisualEffectSharedPtr Rendering::Visual::GetVisualEffect() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVisualEffect();
}

void Rendering::Visual::UpdateWorldBound()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto worldTransform = GetWorldTransform();
    const auto worldBound = impl->UpdateWorldBound(worldTransform);

    SetWorldBound(worldBound);
}

void Rendering::Visual::UpdateModelBound()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateModelBound();
}

void Rendering::Visual::UpdateModelNormals()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateModelNormals();
}

void Rendering::Visual::GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(camera, noCull);

    culler.Insert(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()));
}

Rendering::Visual::Visual(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
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

    const auto registerId = ParentType::Register(target);

    if (registerId != 0)
    {
        impl->Register(target);
    }

    return registerId;
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
