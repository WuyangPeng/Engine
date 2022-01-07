// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 14:42)

#include "Rendering/RenderingExport.h"

#include "IKController.h"
#include "Detail/IKControllerImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
 #include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26434)
CORE_TOOLS_RTTI_DEFINE(Rendering, IKController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IKController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IKController);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, IKController);

Rendering::IKController
	::IKController(const IKJointSharedPtrVector& joints)
	:ParentType{}, impl{ make_shared<ImplType>(joints) }
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
COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, IKController)

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, IKController)

Rendering::ControllerInterfaceSharedPtr Rendering::IKController
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}
										  
Rendering::IKController
	::IKController(LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IKController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::IKController ::Register(CoreTools::ObjectRegister& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;    

	const auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
		//impl->Register(target);
	}

	return uniqueID;
}

void Rendering::IKController
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IKController ::Link(CoreTools::ObjectLink& source)
{
	;

	ParentType::Link(source); 	

	//impl->Link(source);
}

void Rendering::IKController
    ::PostLink ()
{
	;
    
	ParentType::PostLink();	 
}

void Rendering::IKController ::Load(CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	//impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKController,GetIterations, int)									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKController, IsOrderEndToRoot, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, IKController, SetIterations, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, IKController, SetOrderEndToRoot, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKController,GetJointsSharedPtr, int,const Rendering::IKJointSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKController,GetJointsNum, int)

bool Rendering::IKController
	::Update(double applicationTime)
{
	if (ParentType::Update(applicationTime))
    {
		// 确保效果都在当前世界空间。
		// 假设joints形成一个链，使joints I的世界变换是joint I + 1的父变换。
		
		const auto mNumJoints = impl->GetJointsNum();

		for (auto index = 0; index < mNumJoints; ++index)
		{
			auto pointer = impl->GetJointsSharedPtr(index);
			pointer->UpdateWorldTransform();
		}

		// 更新joints一次一个，以满足目标。
		// 由于每个关节被更新，即联合之后出现在链中的节点joint必须在世界空间。

		for (auto iter = 0; iter < impl->GetIterations(); ++iter)
		{
			for (auto index = 0; index < mNumJoints; ++index)
			{
				auto realIndex = index;
				if (impl->IsOrderEndToRoot())
				{
					realIndex = mNumJoints - 1 - index;
				}
				
				auto joint = impl->GetJointsSharedPtr(realIndex);
				
				for (auto axis = Mathematics::MatrixRotationAxis::X;axis < Mathematics::MatrixRotationAxis::Count; ++axis)
				{		
					if (joint->IsAllowTranslation(axis))
					{
						if (joint->UpdateLocalTranslate(axis))
						{
							for (auto j = realIndex; j < mNumJoints; ++j)
							{
								auto joint2 = impl->GetJointsSharedPtr(j);
								joint2->UpdateWorldRotateAndTranslate();
							}
						}
					}
				}

				for (auto axis = Mathematics::MatrixRotationAxis::X; axis < Mathematics::MatrixRotationAxis::Count; ++axis)
				{
					if (joint->IsAllowRotation(axis))
					{
						if (joint->UpdateLocalRotate(axis))
						{
							for (auto j = realIndex; j < mNumJoints; ++j)
							{
								auto joint2 = impl->GetJointsSharedPtr(j);
								
								joint2->UpdateWorldRotateAndTranslate();
							}
						}
					}
				}
			}
		}		

		return true;
    }

	return false;    
}

CoreTools::ObjectInterfaceSharedPtr Rendering::IKController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

#include STSTEM_WARNING_POP