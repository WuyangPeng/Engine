// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:30)

#include "Rendering/RenderingExport.h"

#include "Detail/LightImpl.h"
#include "Light.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, Light);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Light);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Light); 

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, Light);

Rendering::Light
	::Light(LightType type,float epsilon)
	:ParentType{ "Light" }, m_Impl{ make_shared<ImplType>(type, epsilon) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Light
	::~Light()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, Light)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Light,SetType,LightType,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetType, Rendering::LightType)
										 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Light,SetAngle,float,void)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Light,SetExponent,float,void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetAngle, float) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetCosAngle, float) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetSinAngle, float)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetExponent, float) 
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Light,SetAmbient,Colour,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Light,SetDiffuse,Colour,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Light,SetSpecular,Colour,void)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetAmbient,const Rendering::Light::Colour) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetDiffuse,const Rendering::Light::Colour) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetSpecular, const Rendering::Light::Colour)
 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetPosition, const Rendering::Light::APoint)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetDirectionVector, const Rendering::Light::AVector)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetUpVector, const Rendering::Light::AVector)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetRightVector, const Rendering::Light::AVector)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Light,SetPosition, APoint,void)
										  
void Rendering::Light
	::SetVector(const AVector& up, const AVector& right, const AVector& direction)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
   
	return m_Impl->SetVector(up, right, direction);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Light,SetDirection, AVector,void)
 
void Rendering::Light
	::SetAttenuation(float constant, float linear, float quadratic, float intensity)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
   
	return m_Impl->SetAttenuation(constant,linear,quadratic,intensity);
}
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetConstant, float)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetLinear, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetQuadratic, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Light,GetIntensity, float)
 
Rendering::Light
	::Light(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
} 

int Rendering::Light
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += m_Impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::Light
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);
}

void Rendering::Light
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Light
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::Link(source);
}

void Rendering::Light
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

void Rendering::Light
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
  
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	m_Impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}


 #include STSTEM_WARNING_POP