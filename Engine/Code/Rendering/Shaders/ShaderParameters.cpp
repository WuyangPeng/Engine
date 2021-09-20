// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:06)

#include "Rendering/RenderingExport.h"

#include "ShaderParameters.h"
#include "Detail/ShaderParametersImpl.h"
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
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, ShaderParameters);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ShaderParameters);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ShaderParameters); 

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ShaderParameters);

Rendering::ShaderParameters::ShaderParameters(LoadConstructor loadConstructor)
        : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
    {
        SELF_CLASS_IS_VALID_0;
    }
    CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ShaderParameters)
    CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ShaderParameters)
    CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ShaderParameters)
    CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ShaderParameters)
    CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ShaderParameters)
    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ShaderParameters)

Rendering::ShaderParameters
	::ShaderParameters(const ConstShaderBaseSharedPtr& shader)
	:ParentType{ "ShaderParameters" }, impl{ make_shared<ImplType>(shader) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderParameters
	::~ShaderParameters()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderParameters)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters,GetNumConstants,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters, GetNumTextures, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters, GetConstants,const Rendering::ShaderParameters::ConstShaderFloatSharedPtrGather)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ShaderParameters,GetTextures,const Rendering::ShaderParameters::ConstTextureSharedPtrGather)

int Rendering::ShaderParameters
	::SetConstant(const string& name, const ShaderFloatSharedPtr& shaderFloat)
{
	;
       
	return impl->SetConstant(name, shaderFloat);
}

void Rendering::ShaderParameters
	::SetConstant(int handle, const ShaderFloatSharedPtr& shaderFloat)
{
	;
       
	return impl->SetConstant(handle, shaderFloat);
}

int Rendering::ShaderParameters
	::SetTexture(const string& name, const TextureSharedPtr& texture)
{
	;
       
	return impl->SetTexture(name, texture);
}

void Rendering::ShaderParameters
	::SetTexture(int handle, const TextureSharedPtr& texture)
{
	;
       
	return impl->SetTexture(handle, texture);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderParameters,GetConstant,string,const Rendering::ConstShaderFloatSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ShaderParameters,GetTexture,string, const Rendering::ConstTextureSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderParameters,GetConstant,int,const Rendering::ConstShaderFloatSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, ShaderParameters, GetTexture,int, const Rendering::ConstTextureSharedPtr)



void Rendering::ShaderParameters
	::UpdateConstants(const VisualSharedPtr& visual, const CameraSharedPtr& camera)
{
	;
       
	return impl->UpdateConstants(visual, camera);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::ShaderParameters::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP