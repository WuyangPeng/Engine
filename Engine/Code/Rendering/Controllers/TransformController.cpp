// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 16:20)

#include "Rendering/RenderingExport.h"

#include "TransformController.h"
#include "Detail/TransformControllerImpl.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, TransformController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TransformController); 
CORE_TOOLS_FACTORY_DEFINE(Rendering, TransformController);

Rendering::TransformController
	::TransformController(const FloatTransform& localTransform)
	:ParentType{}, m_Impl{ make_shared<ImplType>(localTransform) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering,TransformController)

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, TransformController) 

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, TransformController,SetTransform,FloatTransform,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TransformController,GetTransform,const Rendering::FloatTransform)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, TransformController,SetTranslate, APoint,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, TransformController,SetRotate, Matrix,void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, TransformController,SetUniformScale, float,void)			

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, TransformController,SetScale, APoint,void)	

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, TransformController,SetMatrix, Matrix,void)

void Rendering::TransformController
	::SetObject(ControllerInterface* object) 
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Spatial::sm_Type), "无效类\n");

	ParentType::SetObject(object);
}

void Rendering::TransformController
	::SetObjectInCopy(ControllerInterface* object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::SetObject(object);
}

bool Rendering::TransformController
	::Update (double applicationTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (ParentType::Update(applicationTime))
    {		 
		auto spatial = dynamic_cast<Spatial*>(GetControllerObject());
		if (spatial != nullptr)
		{
			spatial->SetLocalTransform(m_Impl->GetTransform());
			return true;
		}			
    }
	
	return false;
}

Rendering::ControllerInterfaceSharedPtr Rendering::TransformController
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}
 
Rendering::TransformController
	::TransformController(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>(FloatTransform()) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::TransformController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::TransformController ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);	
}

void Rendering::TransformController
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TransformController
    ::Link (const CoreTools::ObjectLinkSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 	
}

void Rendering::TransformController
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

void Rendering::TransformController
    ::Load (const CoreTools::BufferSourceSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TransformController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}
 



#include STSTEM_WARNING_POP