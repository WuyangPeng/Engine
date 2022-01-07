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
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, Material);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Material);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Material);

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, Material);

Rendering::Material
	::Material()
	:ParentType{ "Material" }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Material
	::Material(const Colour& emissive, const Colour& ambient,const Colour& diffuse, const Colour& specular)
	:ParentType{ "Material" },
	impl{ make_shared<ImplType>(emissive, ambient, diffuse, specular) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Material
	::~Material()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Material) 

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
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}  


void Rendering::Material
    ::Load (CoreTools::BufferSource& source)
{
	;
  
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	ParentType::Load(source);

	impl->Load(source);

	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Material
    ::Link (CoreTools::ObjectLink& source)
{
	;
    
	ParentType::Link(source);
}

void Rendering::Material
    ::PostLink ()
{
	;
    
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
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Material
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += impl->GetStreamingSize();
    
	return size;
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Material::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP