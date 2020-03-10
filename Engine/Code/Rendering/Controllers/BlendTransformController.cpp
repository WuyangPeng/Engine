// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 14:18)

#include "Rendering/RenderingExport.h"

#include "BlendTransformController.h"
#include "Detail/BlendTransformControllerImpl.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, BlendTransformController);

Rendering::BlendTransformController
	::BlendTransformController(const TransformControllerSmartPointer& firstController,const TransformControllerSmartPointer& secondController, 
							   bool rotationScaleMatrices,bool geometricRotation,bool geometricScale) 
	:ParentType{ Transform::sm_Identity }, m_Impl{ make_shared<ImplType>(firstController, secondController, rotationScaleMatrices, geometricRotation, geometricScale) }
{
     RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::BlendTransformController
	::~BlendTransformController()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, BlendTransformController)

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, BlendTransformController)

Rendering::ControllerInterfaceSmartPointer Rendering::BlendTransformController
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ NEW0 ClassType(*this) };
}
									  
Rendering::BlendTransformController
	::BlendTransformController(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>()}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::BlendTransformController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::BlendTransformController
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;    

	auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
		m_Impl->Register(target);
	}

	return uniqueID;
}

void Rendering::BlendTransformController
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::BlendTransformController
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 	

	m_Impl->Link(source);
}

void Rendering::BlendTransformController
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();	 
}

void Rendering::BlendTransformController
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BlendTransformController,GetFirstController,const Rendering::ConstTransformControllerSmartPointer)	

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BlendTransformController,GetSecondController,const Rendering::ConstTransformControllerSmartPointer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BlendTransformController,IsRotationScaleMatrices,bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, BlendTransformController,SetWeight, float,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BlendTransformController,GetWeight,float)
									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BlendTransformController,IsGeometricRotation,bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BlendTransformController,IsGeometricScale, bool)


void Rendering::BlendTransformController
	::SetObject(ControllerInterface* object) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Spatial::sm_Type), "无效类\n");
	
	ParentType::SetObject(object);
	m_Impl->SetObject(object); 
}

void Rendering::BlendTransformController
	::SetObjectInCopy(ControllerInterface* object) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	
	ParentType::SetObject(object);
	m_Impl->SetObject(object); 
}

bool Rendering::BlendTransformController
	::Update(double applicationTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Update(applicationTime))
	{
		m_Impl->Update(applicationTime); 

		auto blendTranslate = m_Impl->GetBlendTranslate();

		SetTranslate(blendTranslate);

		if (m_Impl->IsRotationScaleMatrices())
		{
			auto blendQuaternion = m_Impl->GetBlendQuaternion();

			SetRotate(blendQuaternion);

			auto blendScale = m_Impl->GetBlendScale();

			SetScale(blendScale);
		}
		else
		{
			// 算术混合矩阵。		
			auto blendMatrix = m_Impl->GetMatrix();

			SetMatrix(blendMatrix);
		}

		auto spatial = CoreTools::StaticCast<Spatial>(GetControllerObject());

		spatial->SetLocalTransform(GetTransform());	 

		return true;

	}

	return false;	 
} 