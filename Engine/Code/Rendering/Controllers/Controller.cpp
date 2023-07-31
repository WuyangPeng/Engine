///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 10:57)

#include "Rendering/RenderingExport.h"

#include "ControlledObject.h"
#include "Controller.h"
#include "Detail/ControllerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/MathDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Controller);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Controller);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Controller);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Controller)

Rendering::Controller::Controller(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Controller)

Rendering::Controller::ConstControllerInterfaceSharedPtr Rendering::Controller::GetControllerObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetControllerObject();
}

Rendering::Controller::ControllerInterfaceSharedPtr Rendering::Controller::GetControllerObject()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetControllerObject();
}

void Rendering::Controller::SetControllerObject(const ControllerInterfaceSharedPtr& aObject)
{
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    impl->SetObject(aObject);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Controller, SetApplicationTime, double, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Controller, GetApplicationTime, double)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Controller, GetControlTime, double, double)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Controller, GetRepeat, Rendering::ControllerRepeatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Controller, GetMinTime, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Controller, GetMaxTime, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Controller, GetPhase, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Controller, GetFrequency, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Controller, IsActive, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Controller, SetRepeat, ControllerRepeatType, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Controller, SetPhase, double, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Controller, SetFrequency, double, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Controller, SetActive, bool, void)

CoreTools::ObjectSharedPtr Rendering::Controller::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    // object不搜索对象图以避免循环。
    return ParentType::GetObjectByName(name);
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::Controller::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    // object不搜索对象图以避免循环。
    return ParentType::GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::Controller::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    // object不搜索对象图以避免循环。
    return ParentType::GetConstObjectByName(name);
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::Controller::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    // object不搜索对象图以避免循环。
    return ParentType::GetAllConstObjectsByName(name);
    ;
}

Rendering::Controller::Controller(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Controller::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Controller::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Controller::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Controller::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Controller::PostLink()
{
    ParentType::PostLink();
}

void Rendering::Controller::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Controller::SetTime(double minTime, double maxTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTime(minTime, maxTime);
}

bool Rendering::Controller::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return impl->Update(applicationTime);
}
