// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/23 14:37)

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

using std::make_shared;
using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, Controller);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Controller);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Controller);

Rendering::Controller::Controller()
    : ParentType{}, impl{ make_shared<ImplType>() }, m_Object{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Controller::Controller(const Controller& rhs)
    : ParentType(rhs), impl{ make_shared<ImplType>(*rhs.impl) }, m_Object{ rhs.m_Object }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Controller& Rendering::Controller::operator=(const Controller& rhs)
{
    ;

    ParentType::operator=(rhs);

    impl = make_shared<ImplType>(*rhs.impl);

    m_Object = rhs.m_Object;

    return *this;
}

Rendering::Controller::Controller(Controller&& rhs) noexcept
    : ParentType(std::move(rhs)), impl{ std::move(rhs.impl) }, m_Object{ std::move(rhs.m_Object) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Controller& Rendering::Controller::operator=(Controller&& rhs) noexcept
{
    ;

    ParentType::operator=(std::move(rhs));

    impl = std::move(rhs.impl);

    m_Object = std::move(rhs.m_Object);

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Controller)

const Rendering::ControllerInterface* Rendering::Controller::GetControllerObject() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Object;
}

Rendering::ControllerInterface* Rendering::Controller::GetControllerObject() noexcept
{
    ;

    return m_Object;
}

void Rendering::Controller::SetObject(ControllerInterface* object)
{
    ;

    CoreTools::DisableNoexcept();

    m_Object = object;
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

CoreTools::ObjectSharedPtr Rendering::Controller::GetObjectByName(const string& name)
{
    ;

    // m_Object不搜索对象图以避免循环。
    return ParentType::GetObjectByName(name);
}

vector<CoreTools::ObjectSharedPtr> Rendering::Controller::GetAllObjectsByName(const string& name)
{
    ;

    // m_Object不搜索对象图以避免循环。
    return ParentType::GetAllObjectsByName(name);
    ;
}

CoreTools::ConstObjectSharedPtr Rendering::Controller::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    // m_Object不搜索对象图以避免循环。
    return ParentType::GetConstObjectByName(name);
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::Controller::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    // m_Object不搜索对象图以避免循环。
    return ParentType::GetAllConstObjectsByName(name);
    ;
}

Rendering::Controller::Controller(LoadConstructor value)
    : ParentType{ value }, impl{ make_shared<ImplType>() }, m_Object{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Controller::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    size += CORE_TOOLS_STREAM_SIZE(m_Object);

    return size;
}

uint64_t Rendering::Controller::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto uniqueID = ParentType::Register(target);

    if (uniqueID != 0)
    {
        //target.Register(m_Object);
    }

    return uniqueID;
}

void Rendering::Controller::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    // target.WritePointer(m_Object);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Controller::Link(CoreTools::ObjectLink& source)
{
    ;

    ParentType::Link(source);

    /*	ControllerInterfaceSharedPtr object{ m_ObjectID,nullptr };
	
    source.ResolveObjectSharedPtrLink(object);

	m_Object = object.GetData();*/
}

void Rendering::Controller::PostLink()
{
    ;

    ParentType::PostLink();
}

void Rendering::Controller::Load(CoreTools::BufferSource& source)
{
    ;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    //impl->Load(source);

    ControllerInterfaceSharedPtr object;

    //source.ReadSharedPtr(object);

    //m_ObjectID = object.GetAddress();

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Controller::SetTime(double minTime, double maxTime) noexcept
{
    ;

    return impl->SetTime(minTime, maxTime);
}

bool Rendering::Controller::Update(double applicationTime)
{
    ;

    CoreTools::DisableNoexcept();

    return impl->Update(applicationTime);
}

#include STSTEM_WARNING_POP