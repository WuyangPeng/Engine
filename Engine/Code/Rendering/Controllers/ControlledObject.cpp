///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 11:45)

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
#include "Mathematics/Base/MathDetail.h"

using std::make_shared;
using std::string;
using std::vector;

CORE_TOOLS_RTTI_DEFINE(Rendering, ControlledObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ControlledObject);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ControlledObject);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ControlledObject);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ControlledObject)

Rendering::ControlledObject::ControlledObject(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }, impl{ this }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ControlledObject::ControlledObject(const ControlledObject& rhs)
    : ParentType(rhs), impl{ this }
{
    AttachControllerInCopy(rhs);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ControlledObject& Rendering::ControlledObject::operator=(const ControlledObject& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::operator=(rhs);

    impl = PackageType{ this };

    AttachControllerInCopy(rhs);

    return *this;
}

Rendering::ControlledObject::ControlledObject(ControlledObject&& rhs) noexcept
    : ParentType{ std::move(rhs) }, impl{ std::move(rhs.impl) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ControlledObject& Rendering::ControlledObject::operator=(ControlledObject&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    impl = std::move(rhs.impl);

    return *this;
}

// private
void Rendering::ControlledObject::AttachControllerInCopy(const ControlledObject& rhs)
{
    const auto count = rhs.GetNumControllers();

    for (auto index = 0; index < count; ++index)
    {
        auto controller = rhs.GetConstController(index)->Clone();

        impl->AttachControllerInCopy(controller);
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControlledObject)

const Rendering::ControllerInterface* Rendering::ControlledObject::GetControllerObject() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetControllerObject();
}

Rendering::ControllerInterface* Rendering::ControlledObject::GetControllerObject() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetControllerObject();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ControlledObject, Update, double, bool)

void Rendering::ControlledObject::SetObject(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetObject(object);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ControlledObject, GetNumControllers, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ControlledObject, GetConstController, int, Rendering::ConstControllerInterfaceSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ControlledObject, GetController, int, Rendering::ControllerInterfaceSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ControlledObject, AttachController, ControllerInterfaceSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ControlledObject, DetachController, ControllerInterfaceSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ControlledObject, DetachAllControllers, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ControlledObject, UpdateControllers, double, bool)

Rendering::ControlledObject::ControlledObject(LoadConstructor value)
    : ParentType{ value }, impl{ this }
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

    const auto registerID = ParentType::Register(target);
    if (registerID != 0)
    {
        impl->Register(target);
    }

    return registerID;
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
