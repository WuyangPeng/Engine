// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 15:09)

#include "Rendering/RenderingExport.h"

#include "KeyframeController.h"
#include "Detail/KeyframeControllerImpl.h"
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
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26496)
CORE_TOOLS_RTTI_DEFINE(Rendering, KeyframeController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, KeyframeController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, KeyframeController);

Rendering::KeyframeController
	::KeyframeController( int numCommonTimes, int numTranslations, int numRotations,int numScales, const FloatTransform& localTransform )
	:ParentType{ localTransform },
	m_Impl{ make_shared<ImplType>(numCommonTimes,numTranslations,numRotations,numScales) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}
 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, KeyframeController)

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, KeyframeController)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, KeyframeController,GetNumCommonTimes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetCommonTimes, int,float)

void Rendering::KeyframeController
	::SetCommonTimes(int index, float commonTimes)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetCommonTimes(index, commonTimes);
}
								
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, KeyframeController,GetNumTranslations, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetTranslationTimes, int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetTranslations, int,const Rendering::KeyframeController::APoint)
 
void Rendering::KeyframeController
	::SetTranslationTimes(int index, float translationTimes)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetTranslationTimes(index, translationTimes);
}

void Rendering::KeyframeController
	::SetTranslations(int index,  const APoint& translations)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetTranslations(index, translations);
}
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, KeyframeController,GetNumRotations, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetRotationTimes, int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetRotations, int,const Rendering::KeyframeController::AQuaternion)
 
void Rendering::KeyframeController
	::SetRotationTimes(int index,  float rotationTimes)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetRotationTimes(index, rotationTimes);
}

void Rendering::KeyframeController
	::SetRotations(int index, const AQuaternion& rotations)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetRotations(index, rotations);
}
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, KeyframeController,GetNumScales, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetScaleTimes, int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetScales, int,float)
 
void Rendering::KeyframeController
	::SetScaleTimes(int index, float scaleTimes)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetScaleTimes(index, scaleTimes);
}

void Rendering::KeyframeController
	::SetScales(int index, float scales)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetScales(index, scales);
}
 
void Rendering::KeyframeController
	::SetObject(ControllerInterface* object) 
{
	RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Spatial::GetCurrentRttiType()), "无效类\n");
	
	ParentType::SetObject(object);
}

void Rendering::KeyframeController
	::SetObjectInCopy(ControllerInterface* object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::SetObject(object);
}

Rendering::ControllerInterfaceSharedPtr Rendering::KeyframeController
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, KeyframeController,GetTranslate, ControllerKeyInfo,const Rendering::KeyframeController::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, KeyframeController,GetRotate, ControllerKeyInfo,const Rendering::KeyframeController::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, KeyframeController,GetScale, ControllerKeyInfo,float)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetTranslateKeyInfo,float,const Rendering::ControllerKeyInfo)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetRotateKeyInfo,float,const Rendering::ControllerKeyInfo)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetScaleKeyInfo,float,const Rendering::ControllerKeyInfo)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController,GetCommonKeyInfo,float,const Rendering::ControllerKeyInfo) 

bool Rendering::KeyframeController
	::Update( double applicationTime )
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Update(applicationTime))
	{
		auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));		 

		// 这里的逻辑检查同样时间的数组，以减少调用GetKeyInfo的次数。
		if (0 < GetNumCommonTimes())
		{
			const auto controllerKeyInfo = GetCommonKeyInfo(ctrlTime);		 

			if (0 < GetNumTranslations())  
			{
				auto translate = GetTranslate(controllerKeyInfo);
				 
				SetTranslate(translate);
			}

			if (0 < GetNumRotations()) 
			{
				const auto rotate = GetRotate(controllerKeyInfo);
				SetRotate(rotate);
			}

			if (0 < GetNumScales()) 
			{
				const auto scale = GetScale(controllerKeyInfo);
				SetUniformScale(scale);
			}
		}
		else
		{
			if (0 < GetNumTranslations())
			{
				const auto controllerKeyInfo = GetTranslateKeyInfo(ctrlTime);
				auto translate = GetTranslate(controllerKeyInfo);

				SetTranslate(translate);
			}

			if (0 < GetNumRotations())
			{
				const auto controllerKeyInfo = GetRotateKeyInfo(ctrlTime);
				const auto rotate = GetRotate(controllerKeyInfo);
				SetRotate(rotate);
			}

			if (0 < GetNumScales())
			{
				const auto controllerKeyInfo = GetScaleKeyInfo(ctrlTime);
				const auto scale = GetScale(controllerKeyInfo);
				SetUniformScale(scale);
			} 
		}
                auto spatial = dynamic_cast<Spatial*>(GetControllerObject());
		 
		spatial->SetLocalTransform(GetTransform());
		return true;
	}

	return false;	
}

										  
Rendering::KeyframeController
	::KeyframeController(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::KeyframeController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::KeyframeController ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);	
}

void Rendering::KeyframeController
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::KeyframeController ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 	 
}

void Rendering::KeyframeController
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();	 
}

void Rendering::KeyframeController ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::KeyframeController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP