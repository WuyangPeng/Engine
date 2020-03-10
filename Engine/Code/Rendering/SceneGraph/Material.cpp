// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:40)

#include "Rendering/RenderingExport.h"

#include "Detail/MaterialImpl.h"
#include "Material.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, Material);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Material);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Material);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, Material);

Rendering::Material
	::Material()
	:ParentType{ "Material" }, m_Impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Material
	::Material(const Colour& emissive, const Colour& ambient,const Colour& diffuse, const Colour& specular)
	:ParentType{ "Material" },
	m_Impl{ make_shared<ImplType>(emissive, ambient, diffuse, specular) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Material
	::~Material()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, Material) 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Material,GetEmissive, const Rendering::Material::Colour)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Material,GetAmbient, const Rendering::Material::Colour)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Material,GetDiffuse, const Rendering::Material::Colour)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Material,GetSpecular, const Rendering::Material::Colour)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Material, SetEmissive, Colour, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Material,SetAmbient, Colour, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Material,SetDiffuse, Colour, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Material,SetSpecular, Colour, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Material,GetAlpha, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Material,GetSpecularExponent, float)

Rendering::Material
	::Material(LoadConstructor value)
	:ParentType{ value }, m_Impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}  


void Rendering::Material
    ::Load (CoreTools::BufferSource& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
  
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	ParentType::Load(source);

	m_Impl->Load(source);

	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Material
    ::Link (CoreTools::ObjectLink& source)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::Link(source);
}

void Rendering::Material
    ::PostLink ()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    
	ParentType::PostLink();
}

uint64_t Rendering::Material
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);
}

void Rendering::Material
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	m_Impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Material
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += m_Impl->GetStreamingSize();
    
	return size;
}

