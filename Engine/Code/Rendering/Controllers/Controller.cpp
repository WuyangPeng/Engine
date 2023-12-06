/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 17:05)

#include "Rendering/RenderingExport.h"

#include "ControlledObject.h"
#include "Controller.h"
#include "Detail/ControllerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
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

Rendering::Controller::Controller(const std::string& name)
    : ParentType{ name }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Controller)

Rendering::Controller::ConstControllerSharedPtr Rendering::Controller::GetController() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetControllerObject();
}

Rendering::Controller::ControllerSharedPtr Rendering::Controller::GetController()
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetControllerObject();
}

void Rendering::Controller::SetController(const ControllerSharedPtr& controller)
{
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    impl->SetController(controller);
}

void Rendering::Controller::SetApplicationTime(double applicationTime) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetApplicationTime(applicationTime);
}

double Rendering::Controller::GetApplicationTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetApplicationTime();
}

double Rendering::Controller::GetControlTime(double applicationTime) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetControlTime(applicationTime);
}

Rendering::ControllerRepeatType Rendering::Controller::GetRepeat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetRepeat();
}

double Rendering::Controller::GetMinTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetMinTime();
}

double Rendering::Controller::GetMaxTime() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetMaxTime();
}

double Rendering::Controller::GetPhase() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPhase();
}

double Rendering::Controller::GetFrequency() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetFrequency();
}

bool Rendering::Controller::IsActive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->IsActive();
}

void Rendering::Controller::SetRepeat(ControllerRepeatType repeat) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetRepeat(repeat);
}

void Rendering::Controller::SetTime(double minTime, double maxTime)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTime(minTime, maxTime);
}

void Rendering::Controller::SetPhase(double phase) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetPhase(phase);
}

void Rendering::Controller::SetFrequency(double frequency) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetFrequency(frequency);
}

void Rendering::Controller::SetActive(bool active) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetActive(active);
}

bool Rendering::Controller::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return impl->Update(applicationTime);
}

// object不搜索impl里存的Controller，以避免循环。
CoreTools::ObjectSharedPtr Rendering::Controller::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    return ParentType::GetObjectByName(name);
}

Rendering::Controller::ObjectSharedPtrContainer Rendering::Controller::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    return ParentType::GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::Controller::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::GetConstObjectByName(name);
}

Rendering::Controller::ConstObjectSharedPtrContainer Rendering::Controller::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::GetAllConstObjectsByName(name);
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
    RENDERING_CLASS_IS_VALID_1;

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
