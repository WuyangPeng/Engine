// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 14:31)

#include "Rendering/RenderingExport.h"

#include "ControlledObject.h"
#include "Detail/ControlledObjectImpl.h"
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,ControlledObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,ControlledObject);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,ControlledObject);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ControlledObject);

Rendering::ControlledObject
    ::ControlledObject()
	:ParentType{}, m_Impl{}, m_Object{ nullptr }
{
    m_Impl = make_shared<ImplType>(this);
    
    RENDERING_SELF_CLASS_IS_VALID_1;
}

 
Rendering::ControlledObject
    ::ControlledObject(const ControlledObject& rhs)
	:ParentType(rhs), m_Impl{}, m_Object{ rhs.m_Object }
{
	m_Impl = make_shared<ImplType>(this);
	
	AttachControllerInCopy(rhs);
    
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ControlledObject& Rendering::ControlledObject
	::operator=(const ControlledObject& rhs) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::operator=(rhs);   
	
	m_Impl = make_shared<ImplType>(this);
	
	AttachControllerInCopy(rhs);

	m_Object = rhs.m_Object;

	return *this;
} 

Rendering::ControlledObject ::ControlledObject(ControlledObject&& rhs) noexcept
    : ParentType(std::move(rhs)), m_Impl{ std::move(rhs.m_Impl) }, m_Object{ std::move(rhs.m_Object) }
{
   

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ControlledObject& Rendering::ControlledObject ::operator=(ControlledObject&& rhs) noexcept
{


    ParentType::operator=(std::move(rhs));

    m_Impl = std::move(rhs.m_Impl);

  

    m_Object = std::move(rhs.m_Object);

    return *this;
} 

// private
void Rendering::ControlledObject
	::AttachControllerInCopy(const ControlledObject& rhs)
{
	const auto count = rhs.GetNumControllers ();
	
	for(int index = 0; index < count;++ index)
	{
		ControllerInterfaceSharedPtr controller{ rhs.GetConstController(index)->Clone() };
		
		m_Impl->AttachControllerInCopy(controller);
	}
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering,ControlledObject)

const Rendering::ControllerInterface* Rendering::ControlledObject ::GetControllerObject() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Object;
}

Rendering::ControllerInterface* Rendering::ControlledObject ::GetControllerObject() noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Object;
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ControlledObject,  Update, double,bool)

void Rendering::ControlledObject ::SetObject(ControllerInterface* object) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Object = object;
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ControlledObject,GetNumControllers,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ControlledObject,GetConstController,int,Rendering::ConstControllerInterfaceSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ControlledObject,GetController,int,Rendering::ControllerInterfaceSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ControlledObject,AttachController,ControllerInterfaceSharedPtr ,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ControlledObject,DetachController,ControllerInterfaceSharedPtr ,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,ControlledObject,DetachAllControllers,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,ControlledObject,UpdateControllers,double,bool)

 
Rendering::ControlledObject
   ::ControlledObject (LoadConstructor value)
	:ParentType{ value }, m_Impl{}
{
	m_Impl = make_shared<ImplType>(this);
    
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::ControlledObject
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += m_Impl->GetStreamingSize();

	size += CORE_TOOLS_STREAM_SIZE(m_Object);  
    
	return size;
}

uint64_t Rendering::ControlledObject ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	const auto uniqueID = ParentType::Register(target);
	if(uniqueID != 0)
	{
		//m_Impl->Register(target);

		//target.Register(m_Object);   
	}   
    
    return uniqueID;
}

void Rendering::ControlledObject ::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);

   // target.WritePointer(m_Object); 
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::ControlledObject
    ::Link (const CoreTools::ObjectLinkSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 

    m_Impl->Link(source);

	/*ControllerInterfaceSharedPtr object { m_ObjectID, nullptr };
	  
    source.ResolveObjectSharedPtrLink(object);

	m_Object = object.GetData();*/
}

void Rendering::ControlledObject
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

void Rendering::ControlledObject ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);

	ControllerInterfaceSharedPtr object;

//    source.ReadSharedPtr(object);

	//m_ObjectID = object.GetAddress();
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

#include STSTEM_WARNING_POP


