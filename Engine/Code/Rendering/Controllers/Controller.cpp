// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 14:37)

#include "Rendering/RenderingExport.h"

#include "Controller.h"
#include "ControlledObject.h"
#include "Detail/ControllerImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/ClassInvariant/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,Controller);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,Controller);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,Controller);

Rendering::Controller
    ::Controller()
	:ParentType{}, m_Impl{ make_shared <ImplType>() }, m_Object{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Controller
    ::~Controller()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Controller
	::Controller(const Controller& rhs) 
	:ParentType(rhs), m_Impl{ make_shared <ImplType>(*rhs.m_Impl) }, m_Object{ rhs.m_Object }
{ 
	RENDERING_SELF_CLASS_IS_VALID_1;
}         

Rendering::Controller& Rendering::Controller
	::operator=(const Controller& rhs) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::operator=(rhs);   
	
	m_Impl = make_shared <ImplType>(*rhs.m_Impl);

	m_Object = rhs.m_Object;

	return *this;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, Controller)

const Rendering::ControllerInterface* Rendering::Controller
    ::GetControllerObject () const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Object;
}
		
Rendering::ControllerInterface* Rendering::Controller ::GetControllerObject() noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	return m_Object;
}

 

void Rendering::Controller ::SetObject(ControllerInterface* object)  
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	CoreTools::DoNothing();

	m_Object = object;
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, Controller, SetApplicationTime, double, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Controller, GetApplicationTime, double)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Controller,GetControlTime,double,double)

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

const CoreTools::ObjectSmartPointer Rendering::Controller
    ::GetObjectByName(const string& name)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    // m_Object不搜索对象图以避免循环。
    return ParentType::GetObjectByName(name);
}

const vector<CoreTools::ObjectSmartPointer> Rendering::Controller
    ::GetAllObjectsByName(const string& name)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    // m_Object不搜索对象图以避免循环。
    return ParentType::GetAllObjectsByName(name);;
}

const CoreTools::ConstObjectSmartPointer Rendering::Controller
    ::GetConstObjectByName(const string& name) const
{     
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    // m_Object不搜索对象图以避免循环。
    return ParentType::GetConstObjectByName(name);
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::Controller
    ::GetAllConstObjectsByName(const string& name) const
{    
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    // m_Object不搜索对象图以避免循环。
    return ParentType::GetAllConstObjectsByName(name);;
}

Rendering::Controller
    ::Controller(LoadConstructor value)
    : ParentType{ value }, m_Impl{ make_shared<ImplType>() }, m_Object{nullptr}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Controller
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += m_Impl->GetStreamingSize();

    size += CORE_TOOLS_STREAM_SIZE(m_Object);
    
	return size;
}

uint64_t Rendering::Controller
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	const auto uniqueID = ParentType::Register(target);

	if(uniqueID != 0)
	{
		target.Register(m_Object);
	}
    
    return uniqueID;
}

void Rendering::Controller
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);

    target.WritePointer(m_Object);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Controller
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::Link(source); 

/*	ControllerInterfaceSmartPointer object{ m_ObjectID,nullptr };
	
    source.ResolveObjectSmartPointerLink(object);

	m_Object = object.GetData();*/
}

void Rendering::Controller
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

void Rendering::Controller
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);

	ControllerInterfaceSmartPointer object;

	//source.ReadSmartPointer(object);

	//m_ObjectID = object.GetAddress();
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Controller
	::SetTime( double minTime,double maxTime ) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetTime(minTime,maxTime);
}

bool Rendering::Controller::Update(double applicationTime)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    CoreTools::DoNothing();

    return m_Impl->Update(applicationTime);
}

#include STSTEM_WARNING_POP