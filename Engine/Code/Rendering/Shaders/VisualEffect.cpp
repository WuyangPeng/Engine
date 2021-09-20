// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:27)


#include "Rendering/RenderingExport.h"

#include "VisualEffect.h"
#include "Detail/VisualEffectImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualEffect);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualEffect);

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, VisualEffect);

Rendering::VisualEffect::VisualEffect(LoadConstructor loadConstructor)
        : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
    {
        SELF_CLASS_IS_VALID_0;
    }
    CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, VisualEffect)
    CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, VisualEffect)
    CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, VisualEffect)
    CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, VisualEffect)
    CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, VisualEffect)
    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, VisualEffect)

Rendering::VisualEffect
	::VisualEffect()
	:ParentType{ "VisualEffect" }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualEffect
	::~VisualEffect()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualEffect)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualEffect,InsertTechnique,VisualTechniqueSharedPtr,void)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualEffect,GetNumTechniques,int)  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect,GetTechnique,int,const Rendering::ConstVisualTechniqueSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect,GetNumPasses,int,int)
 
const Rendering::ConstVertexShaderSharedPtr Rendering::VisualEffect
	::GetVertexShader(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetVertexShader(techniqueIndex, passIndex);
}

const Rendering::ConstPixelShaderSharedPtr Rendering::VisualEffect
	::GetPixelShader(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetPixelShader(techniqueIndex, passIndex);
}

const Rendering::ConstAlphaStateSharedPtr Rendering::VisualEffect
	::GetAlphaState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetAlphaState(techniqueIndex, passIndex);
}

const Rendering::ConstCullStateSharedPtr Rendering::VisualEffect
	::GetCullState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetCullState(techniqueIndex, passIndex);
}

const Rendering::ConstDepthStateSharedPtr Rendering::VisualEffect
	::GetDepthState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetDepthState(techniqueIndex, passIndex);
}

const Rendering::ConstOffsetStateSharedPtr Rendering::VisualEffect
	::GetOffsetState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetOffsetState(techniqueIndex, passIndex);
}

const Rendering::ConstStencilStateSharedPtr Rendering::VisualEffect
	::GetStencilState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetStencilState(techniqueIndex, passIndex);
}

const Rendering::ConstWireStateSharedPtr Rendering::VisualEffect
	::GetWireState(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetWireState(techniqueIndex, passIndex);
}

const Rendering::ConstVisualPassSharedPtr Rendering::VisualEffect
	::GetPass(int techniqueIndex, int passIndex) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return impl->GetPass(techniqueIndex, passIndex);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect,SaveVisualTechnique, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualEffect,LoadVisualTechnique, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::VisualEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP