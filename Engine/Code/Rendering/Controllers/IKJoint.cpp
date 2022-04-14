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

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::vector;
using std::make_shared;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, IKJoint);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IKJoint);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IKJoint);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, IKJoint);

Rendering::IKJoint
	::IKJoint(const SpatialSharedPtr& object, const IKGoalSharedPtrVector& goals) 
	:ParentType{ "IKJoint" }, impl{ make_shared<ImplType>(object, goals) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

#define COPY_CONSTRUCTION_DEFINE_WITH_PARENT(namespaceName, className)                      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, impl{ std::make_shared<ImplType>(*rhs.impl) }                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        className temp{ rhs };                                                              \
        Swap(temp);                                                                         \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        ;                                       \
        std::swap(impl, rhs.impl);                                                          \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, impl{ std::move(rhs.impl) }                         \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        impl = std::move(rhs.impl);                                                         \
        return *this;                                                                       \
    }                                                                                        
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, IKJoint)

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, IKJoint)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,GetAxis,MatrixRotationAxis,const Rendering::IKJoint::AVector)
									   
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKJoint,GetObjectSharedPtr,const Rendering::ConstSpatialSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKJoint,GetGoalsNum,int) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,GetGoalsSharedPtr,int,const Rendering::ConstIKGoalSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKJoint,UpdateWorldTransform,void)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,UpdateLocalTranslate,MatrixRotationAxis,bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,UpdateLocalRotate,MatrixRotationAxis,bool)

										  
Rendering::IKJoint
	::IKJoint(LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IKJoint
::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::IKJoint
::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	const auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
		impl->Register(target);
	}

	return uniqueID;
}

void Rendering::IKJoint
::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IKJoint
::Link (CoreTools::ObjectLink& source)
{
	;

	ParentType::Link(source); 	

	impl->Link(source);
}

void Rendering::IKJoint
::PostLink ()
{
	;
    
	ParentType::PostLink();	 
}

void Rendering::IKJoint
::Load (CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::IKJoint
	::SetAllowTranslation(MatrixRotationAxis axisIndex, bool allowTranslation) 
{
	;

	impl->SetAllowTranslation(axisIndex, allowTranslation);
}

void Rendering::IKJoint
	::SetAllowRotation(MatrixRotationAxis axisIndex, bool allowRotation)
{
	;

	impl->SetAllowRotation(axisIndex, allowRotation);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,IsAllowTranslation,MatrixRotationAxis,bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKJoint,IsAllowRotation,MatrixRotationAxis,bool)

void Rendering::IKJoint::UpdateWorldRotateAndTranslate() noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->UpdateWorldRotateAndTranslate();
}

CoreTools::ObjectInterfaceSharedPtr Rendering::IKJoint::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP