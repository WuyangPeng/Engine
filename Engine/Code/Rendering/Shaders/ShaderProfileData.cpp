// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:07)

#include "Rendering/RenderingExport.h"

#include "ShaderProfileData.h"
#include "Detail/ShaderProfileDataImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,ShaderProfileData);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,ShaderProfileData);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,ShaderProfileData); 

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ShaderProfileData);


Rendering::ShaderProfileData::ShaderProfileData(LoadConstructor loadConstructor)
        : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
    {
        SELF_CLASS_IS_VALID_0;
    }
    CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ShaderProfileData)
    CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ShaderProfileData)
    CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ShaderProfileData)
    CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ShaderProfileData)
    CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ShaderProfileData)
    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ShaderProfileData)

Rendering::ShaderProfileData
	::ShaderProfileData(int numConstants, int numSamplers)
	:ParentType{ "ShaderProfileData" }, impl{ make_shared<ImplType>(numConstants, numSamplers) }
{  
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderProfileData
	::~ShaderProfileData()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderProfileData)

void Rendering::ShaderProfileData
::SetBaseRegister( int profile, int index, int baseRegister )
{
	;

	return impl->SetBaseRegister(profile,index,baseRegister);
}

void Rendering::ShaderProfileData
	::SetTextureUnit( int profile, int index, int textureUnit )
{
	;

	return impl->SetTextureUnit(profile, index, textureUnit);
}

void Rendering::ShaderProfileData
	::SetProgram( int profile, const std::string& program )
{
	;

	return impl->SetProgram(profile, program);
}

int Rendering::ShaderProfileData
	::GetBaseRegister( int profile, int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetBaseRegister(profile, index);
}

int Rendering::ShaderProfileData
	::GetTextureUnit( int profile, int index ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetTextureUnit(profile, index);
}

const std::string Rendering::ShaderProfileData
	::GetProgram( int profile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetProgram(profile);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderProfileData, GetBaseRegisterSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ShaderProfileData, GetTextureUnitSize, int)

CoreTools::ObjectInterfaceSharedPtr Rendering::ShaderProfileData::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP