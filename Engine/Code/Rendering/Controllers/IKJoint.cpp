// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 15:05)

#include "Rendering/RenderingExport.h"

#include "IKJoint.h"
#include "Detail/IKJointImpl.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/TypeCasting.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;
using std::make_shared;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, IKJoint);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IKJoint);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IKJoint);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, IKJoint);

Rendering::IKJoint
	::IKJoint(const SpatialSmartPointer& object, const IKGoalSmartPointerVector& goals) 
	:ParentType{ "IKJoint" }, m_Impl{ make_shared<ImplType>(object, goals) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IKJoint
	::~IKJoint()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, IKJoint)

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, IKJoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,GetAxis,MatrixRotationAxis,const Rendering::IKJoint::AVector)
									   
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKJoint,GetObjectSmartPointer,const Rendering::ConstSpatialSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKJoint,GetGoalsNum,int) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,GetGoalsSmartPointer,int,const Rendering::ConstIKGoalSmartPointer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKJoint,UpdateWorldTransform,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKJoint,UpdateWorldRotateAndTranslate,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,UpdateLocalTranslate,MatrixRotationAxis,bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,UpdateLocalRotate,MatrixRotationAxis,bool)

										  
Rendering::IKJoint
	::IKJoint(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IKJoint
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::IKJoint
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	const auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
		m_Impl->Register(target);
	}

	return uniqueID;
}

void Rendering::IKJoint
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IKJoint
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 	

	m_Impl->Link(source);
}

void Rendering::IKJoint
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();	 
}

void Rendering::IKJoint
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::IKJoint
	::SetAllowTranslation(MatrixRotationAxis axisIndex, bool allowTranslation) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->SetAllowTranslation(axisIndex, allowTranslation);
}

void Rendering::IKJoint
	::SetAllowRotation(MatrixRotationAxis axisIndex, bool allowRotation)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Impl->SetAllowRotation(axisIndex, allowRotation);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,IsAllowTranslation,MatrixRotationAxis,bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,IsAllowRotation,MatrixRotationAxis,bool)
#include STSTEM_WARNING_POP