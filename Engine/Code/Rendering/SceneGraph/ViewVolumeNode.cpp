/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:56)

#include "Rendering/RenderingExport.h"

#include "ViewVolumeNode.h"
#include "Detail/ViewVolumeNodeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ViewVolumeNode)

CORE_TOOLS_RTTI_DEFINE(Rendering, ViewVolumeNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ViewVolumeNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ViewVolumeNode);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ViewVolumeNode)

Rendering::ViewVolumeNode::ViewVolumeNode(const ViewVolumeSharedPtr& viewVolume)
    : ParentType{ "CameraNode", NodeCreate::Init }, impl{ viewVolume }
{
    SetViewVolume(viewVolume);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ViewVolumeNode)

void Rendering::ViewVolumeNode::SetViewVolume(const ViewVolumeSharedPtr& viewVolume)
{
    RENDERING_CLASS_IS_VALID_1;

    impl->SetViewVolume(viewVolume);

    if (viewVolume)
    {
        Matrix rotate{};

        rotate.SetColumn(0, viewVolume->GetDirectionVector().GetHomogeneousPoint());
        rotate.SetColumn(1, viewVolume->GetUpVector().GetHomogeneousPoint());
        rotate.SetColumn(2, viewVolume->GetRightVector().GetHomogeneousPoint());
        rotate.SetColumn(3, { 0.0f, 0.0f, 0.0f, 1.0f });

        SetLocalTransformTranslate(viewVolume->GetPosition());
        SetLocalTransformRotate(rotate);
        MAYBE_UNUSED const auto result = Update();
    }
}

Rendering::ViewVolumeSharedPtr Rendering::ViewVolumeNode::GetViewVolume() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetViewVolume();
}

bool Rendering::ViewVolumeNode::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto result = ParentType::UpdateWorldData(applicationTime);

    const auto viewVolume = impl->GetViewVolume();

    const auto worldTransform = GetWorldTransform();
    const auto cameraPosition = worldTransform.GetTranslate();
    const auto rotate = worldTransform.GetRotate();

    const auto cameraDirectionVector = rotate.GetColumn(0);
    const auto cameraUpVector = rotate.GetColumn(1);
    const auto cameraRightVector = rotate.GetColumn(2);

    viewVolume->SetFrame(cameraPosition, Mathematics::AVector{ cameraDirectionVector }, Mathematics::AVector{ cameraUpVector }, Mathematics::AVector{ cameraRightVector });

    return result;
}

Rendering::ViewVolumeNode::ViewVolumeNode(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CameraSharedPtr{} }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::ViewVolumeNode::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::ViewVolumeNode::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerId = ParentType::Register(target);
    if (registerId != 0)
    {
        impl->Register(target);
    }

    return registerId;
}

void Rendering::ViewVolumeNode::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::ViewVolumeNode::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::ViewVolumeNode::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::ViewVolumeNode::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::ViewVolumeNode::ControllerSharedPtr Rendering::ViewVolumeNode::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::ViewVolumeNode::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}
