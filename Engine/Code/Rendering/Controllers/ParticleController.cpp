// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 15:28)

#include "Rendering/RenderingExport.h"

#include "ParticleController.h"
#include "Detail/ParticleControllerImpl.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/SceneGraph/Particles.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/TypeCasting.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, ParticleController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ParticleController); 
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ParticleController);

Rendering::ParticleController
	::ParticleController() 
	:ParentType{}, m_Impl{ make_shared<ImplType>() }, m_Particles{ nullptr }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ParticleController
	::~ParticleController() 
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ParticleController
	::ParticleController(const ParticleController& rhs) 
	: ParentType(rhs), m_Impl{ make_shared<ImplType>(*rhs.m_Impl) }, m_Particles{ CoreTools::StaticCast<Particles>(GetControllerObject()) }
{ 
	RENDERING_SELF_CLASS_IS_VALID_1; 
}                                    
		
Rendering::ParticleController& Rendering::ParticleController
	::operator= (const ParticleController& rhs) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::operator=(rhs);     
	m_Impl = make_shared<ImplType>(*rhs.m_Impl);
	m_Particles = CoreTools::StaticCast<Particles>(GetControllerObject());

	return *this;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, ParticleController) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ParticleController,GetNumParticles,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ParticleController,GetSystemLinearSpeed,float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,SetSystemLinearSpeed,float,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ParticleController,GetSystemAngularSpeed,float)								 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,SetSystemAngularSpeed,float,void) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ParticleController,GetSystemLinearAxis,const Rendering::ParticleController::AVector) 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ParticleController,SetSystemLinearAxis,AVector,void) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ParticleController,GetSystemAngularAxis,const Rendering::ParticleController::AVector)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ParticleController,SetSystemAngularAxis,AVector,void) 							 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ParticleController,GetSystemSizeChange,float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,SetSystemSizeChange,float,void)
										 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,GetParticleLinearSpeed,int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,GetParticleLinearAxis,int,const Rendering::ParticleController::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,GetParticleSizeChange,int,float)


void Rendering::ParticleController
	::SetParticleLinearSpeed(int index, float particleLinearSpeed)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetParticleLinearSpeed(index, particleLinearSpeed);
}


void Rendering::ParticleController
	::SetParticleLinearAxis(int index, const AVector& particleLinearAxis)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetParticleLinearAxis(index, particleLinearAxis);
}


void Rendering::ParticleController
	::SetParticleSizeChange(int index, float particleSizeChange)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetParticleSizeChange(index, particleSizeChange);
}

bool Rendering::ParticleController
	::Update(double applicationTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (Controller::Update(applicationTime))
	{
		auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));

		UpdateSystemMotion(ctrlTime);
		UpdatePointMotion(ctrlTime);

		return true;
	}

	return false;
}

void Rendering::ParticleController
	::SetObject(ControllerInterface* object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Particles::sm_Type), "无效类\n");

	ParentType::SetObject(object);

	if (object != nullptr)
	{		 
		m_Particles = CoreTools::StaticCast<Particles>(object);
		Reallocate(m_Particles->GetNumParticles());
	}
	else
	{
		m_Particles = nullptr;
		Reallocate(0);
	}	 
}

void Rendering::ParticleController
	::SetObjectInCopy(ControllerInterface* object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::SetObject(object);
}

void Rendering::ParticleController
	::Reallocate(int numParticles)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (0 < numParticles)
		m_Impl = std::make_shared<ImplType>(numParticles);
	else
		m_Impl = std::make_shared<ImplType>(); 
}

void Rendering::ParticleController
	::UpdateSystemMotion(float ctrlTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (m_Particles != nullptr)
	{
		auto dSize = ctrlTime * GetSystemSizeChange();
		m_Particles->SetSizeAdjust(m_Particles->GetSizeAdjust() + dSize);
		if (m_Particles->GetSizeAdjust() < 0.0f)
		{
			m_Particles->SetSizeAdjust(0.0f);
		}

		auto distance = ctrlTime * GetSystemLinearSpeed();
		auto deltaTrn = distance * GetSystemLinearAxis();
		auto localTransform = m_Particles->GetLocalTransform();
		auto translate = localTransform.GetTranslate() + deltaTrn;
		localTransform.SetTranslate(translate);

		auto angle = ctrlTime * GetSystemAngularSpeed();
		Mathematics::Matrixf deltaRot{ GetSystemAngularAxis(), angle };
		auto rotate = deltaRot * localTransform.GetRotate();
		localTransform.SetRotate(rotate);

		m_Particles->SetLocalTransform(localTransform);
	}
}

void Rendering::ParticleController
	::UpdatePointMotion(float ctrlTime)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (m_Particles != nullptr)
	{
		auto numActive = m_Particles->GetNumActive();
		for (auto i = 0; i < numActive; ++i)
		{
			auto position = m_Particles->GetPosition(i);
			auto size = m_Particles->GetSize(i);

			auto dSize = ctrlTime * GetParticleSizeChange(i);
			size += dSize;
			auto distance = ctrlTime * GetParticleLinearSpeed(i);
			auto deltaTrn = distance * GetParticleLinearAxis(i);
			position += deltaTrn;
		
			m_Particles->SetPosition(i,position);
			m_Particles->SetSize(i,size);
			
		}
	}  
}


Rendering::ParticleController
	::ParticleController(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }, m_Particles{ nullptr }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::ParticleController
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::ParticleController
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);	
}

void Rendering::ParticleController
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::ParticleController
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Link(source); 	 
}

void Rendering::ParticleController
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();

	auto object = GetControllerObject();

	RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Particles::sm_Type), "无效类\n");

	m_Particles = CoreTools::StaticCast<Particles>(object);
}

void Rendering::ParticleController
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}


 