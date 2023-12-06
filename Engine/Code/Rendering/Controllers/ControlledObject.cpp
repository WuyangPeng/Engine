/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/21 09:30)

#include "Rendering/RenderingExport.h"

#include "ControlledObject.h"
#include "Detail/ControlledObjectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ControlledObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ControlledObject);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ControlledObject);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ControlledObject)

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ControlledObject)

Rendering::ControlledObject::ControlledObject(const std::string& name)
    : ParentType{ name }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControlledObject)

bool Rendering::ControlledObject::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Update(applicationTime);
}

int Rendering::ControlledObject::GetNumControllers() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetNumControllers();
}

Rendering::ControlledObject::ConstControllerSharedPtr Rendering::ControlledObject::GetConstController(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetConstController(index);
}

Rendering::ControlledObject::ControllerSharedPtr Rendering::ControlledObject::GetController(int index)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetController(index);
}

void Rendering::ControlledObject::AttachController(const ControllerSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->AttachController(controller, boost::polymorphic_pointer_downcast<ControllerInterface>(shared_from_this()));
}

void Rendering::ControlledObject::DetachController(const ControllerSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->DetachController(controller);
}

void Rendering::ControlledObject::DetachAllControllers()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->DetachAllControllers();
}

Rendering::ControlledObject::ControlledObject(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::ControlledObject::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::ControlledObject::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerId = ParentType::Register(target);
    if (registerId != 0)
    {
        impl->Register(target);
    }

    return registerId;
}

void Rendering::ControlledObject::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::ControlledObject::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::ControlledObject::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::ControlledObject::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
