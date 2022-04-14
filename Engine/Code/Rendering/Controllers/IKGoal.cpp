// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 15:03)

#include "Rendering/RenderingExport.h"

#include "IKGoal.h"
#include "Detail/IKGoalImpl.h"
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
 #include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, IKGoal);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IKGoal);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IKGoal);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, IKGoal);

Rendering::IKGoal
	::IKGoal(const SpatialSharedPtr& target,const SpatialSharedPtr& effector,float weight)
	:ParentType{ "IKGoal" }, impl{ make_shared<ImplType>(target, effector, weight) }
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

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, IKGoal)

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, IKGoal)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKGoal,GetTarget, const Rendering::ConstSpatialSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKGoal, GetEffector, const Rendering::ConstSpatialSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKGoal, GetTargetPosition, const Rendering::IKGoal::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKGoal, GetEffectorPosition, const Rendering::IKGoal::APoint)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, IKGoal, SetWeight, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKGoal, GetWeight, float)
										  
Rendering::IKGoal
	::IKGoal(LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IKGoal
::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::IKGoal
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

void Rendering::IKGoal
::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IKGoal::Link(CoreTools::ObjectLink& source)
{
	;

	ParentType::Link(source); 	

	//impl->Link(source);
}

void Rendering::IKGoal
::PostLink ()
{
	;
    
	ParentType::PostLink();	 
}

void Rendering::IKGoal::Load(CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	//impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::IKGoal::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP