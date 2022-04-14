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
#include SYSTEM_WARNING_DISABLE(26455) 
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26496)
CORE_TOOLS_RTTI_DEFINE(Rendering, ParticleController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ParticleController); 
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, ParticleController);

Rendering::ParticleController 
	::ParticleController() 
	:ParentType{}, impl{ make_shared<ImplType>() }, m_Particles{ nullptr }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

Rendering::ParticleController
	::ParticleController(const ParticleController& rhs) 
	: ParentType(rhs), impl{ make_shared<ImplType>(*rhs.impl) }, m_Particles{ dynamic_cast<Particles*>(GetControllerObject()) }
{ 
	RENDERING_SELF_CLASS_IS_VALID_1; 
}                                    
		
Rendering::ParticleController& Rendering::ParticleController
	::operator= (const ParticleController& rhs) 
{
	;

	ParentType::operator=(rhs);     
	impl = make_shared<ImplType>(*rhs.impl);
        m_Particles = dynamic_cast<Particles*>(GetControllerObject());

	return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ParticleController) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController,GetNumParticles,int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController,GetSystemLinearSpeed,float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, ParticleController,SetSystemLinearSpeed,float,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController,GetSystemAngularSpeed,float)								 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, ParticleController,SetSystemAngularSpeed,float,void) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController,GetSystemLinearAxis,const Rendering::ParticleController::AVector) 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, ParticleController,SetSystemLinearAxis,AVector,void) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController,GetSystemAngularAxis,const Rendering::ParticleController::AVector)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, ParticleController,SetSystemAngularAxis,AVector,void) 							 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ParticleController,GetSystemSizeChange,float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, ParticleController,SetSystemSizeChange,float,void)
										 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,GetParticleLinearSpeed,int,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,GetParticleLinearAxis,int,const Rendering::ParticleController::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ParticleController,GetParticleSizeChange,int,float)


void Rendering::ParticleController
	::SetParticleLinearSpeed(int index, float particleLinearSpeed)
{
	;

	return impl->SetParticleLinearSpeed(index, particleLinearSpeed);
}


void Rendering::ParticleController
	::SetParticleLinearAxis(int index, const AVector& particleLinearAxis)
{
	;

	return impl->SetParticleLinearAxis(index, particleLinearAxis);
}


void Rendering::ParticleController
	::SetParticleSizeChange(int index, float particleSizeChange)
{
	;

	return impl->SetParticleSizeChange(index, particleSizeChange);
}

bool Rendering::ParticleController
	::Update(double applicationTime)
{
	;

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
	;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Particles::GetCurrentRttiType()), "无效类\n");

	ParentType::SetObject(object);

	if (object != nullptr)
	{		 
		m_Particles = dynamic_cast<Particles*>(object);
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
	;

	ParentType::SetObject(object);
}

void Rendering::ParticleController
	::Reallocate(int numParticles)
{
	;

	if (0 < numParticles)
		impl = std::make_shared<ImplType>(numParticles);
	else
		impl = std::make_shared<ImplType>(); 
}

void Rendering::ParticleController
	::UpdateSystemMotion(float ctrlTime)
{
	;

	if (m_Particles != nullptr)
	{
		const auto dSize = ctrlTime * GetSystemSizeChange();
		m_Particles->SetSizeAdjust(m_Particles->GetSizeAdjust() + dSize);
		if (m_Particles->GetSizeAdjust() < 0.0f)
		{
			m_Particles->SetSizeAdjust(0.0f);
		}

		const auto distance = ctrlTime * GetSystemLinearSpeed();
		auto deltaTrn = distance * GetSystemLinearAxis();
		auto localTransform = m_Particles->GetLocalTransform();
		auto translate = localTransform.GetTranslate() + deltaTrn;
		localTransform.SetTranslate(translate);

		const auto angle = ctrlTime * GetSystemAngularSpeed();
		const Mathematics::MatrixF deltaRot{ GetSystemAngularAxis(), angle };
		const auto rotate = deltaRot * localTransform.GetRotate();
		localTransform.SetRotate(rotate);

		m_Particles->SetLocalTransform(localTransform);
	}
}

void Rendering::ParticleController
	::UpdatePointMotion(float ctrlTime)
{
	;

	if (m_Particles != nullptr)
	{
		const auto numActive = m_Particles->GetNumActive();
		for (auto i = 0; i < numActive; ++i)
		{
			auto position = m_Particles->GetParticlesPosition(i);
			auto size = m_Particles->GetSize(i);

			const auto dSize = ctrlTime * GetParticleSizeChange(i);
			size += dSize;
			const auto distance = ctrlTime * GetParticleLinearSpeed(i);
			auto deltaTrn = distance * GetParticleLinearAxis(i);
			position += deltaTrn;
		
			m_Particles->SetPosition(i,position);
			m_Particles->SetSize(i,size);
			
		}
	}  
}


Rendering::ParticleController
	::ParticleController(LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }, m_Particles{ nullptr }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::ParticleController
::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::ParticleController::Register(CoreTools::ObjectRegister& target) const
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
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::ParticleController
::Link (CoreTools::ObjectLink& source)
{
	;

	ParentType::Link(source); 	 
}

void Rendering::ParticleController
::PostLink ()
{
	;
    
	ParentType::PostLink();

	auto object = GetControllerObject();

	RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Particles::GetCurrentRttiType()), "无效类\n");

	m_Particles = dynamic_cast<Particles*>(object);
}

void Rendering::ParticleController
::Load (CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}


 #include STSTEM_WARNING_POP