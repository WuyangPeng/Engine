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
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
 #include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, IKController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IKController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IKController);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, IKController);

Rendering::IKController
	::IKController(const IKJointSmartPointerVector& joints)
	:ParentType{}, m_Impl{ make_shared<ImplType>(joints) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IKController
	::~IKController()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, IKController)

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, IKController)

Rendering::ControllerInterfaceSmartPointer Rendering::IKController
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ std::make_shared<ClassType>(*this) };
}
										  
Rendering::IKController
	::IKController(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IKController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::IKController ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;    

	const auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
		//m_Impl->Register(target);
	}

	return uniqueID;
}

void Rendering::IKController
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IKController
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 	

	m_Impl->Link(source);
}

void Rendering::IKController
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();	 
}

void Rendering::IKController
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKController,GetIterations, int)									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, IKController, IsOrderEndToRoot, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, IKController, SetIterations, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, IKController, SetOrderEndToRoot, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, IKController,GetJointsSmartPointer, int,const Rendering::IKJointSmartPointer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, IKController,GetJointsNum, int)

bool Rendering::IKController
	::Update(double applicationTime)
{
	if (ParentType::Update(applicationTime))
    {
		// 确保效果都在当前世界空间。
		// 假设joints形成一个链，使joints I的世界变换是joint I + 1的父变换。
		
		const auto mNumJoints = m_Impl->GetJointsNum();

		for (auto index = 0; index < mNumJoints; ++index)
		{
			auto pointer = m_Impl->GetJointsSmartPointer(index);
			pointer->UpdateWorldTransform();
		}

		// 更新joints一次一个，以满足目标。
		// 由于每个关节被更新，即联合之后出现在链中的节点joint必须在世界空间。

		for (auto iter = 0; iter < m_Impl->GetIterations(); ++iter)
		{
			for (auto index = 0; index < mNumJoints; ++index)
			{
				auto realIndex = index;
				if (m_Impl->IsOrderEndToRoot())
				{
					realIndex = mNumJoints - 1 - index;
				}
				
				auto joint = m_Impl->GetJointsSmartPointer(realIndex);
				
				for (auto axis = Mathematics::MatrixRotationAxis::X;axis < Mathematics::MatrixRotationAxis::Count; ++axis)
				{		
					if (joint->IsAllowTranslation(axis))
					{
						if (joint->UpdateLocalTranslate(axis))
						{
							for (auto j = realIndex; j < mNumJoints; ++j)
							{
								auto joint2 = m_Impl->GetJointsSmartPointer(j);
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
								auto joint2 = m_Impl->GetJointsSmartPointer(j);
								
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