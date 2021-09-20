// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 17:53)

#include "Rendering/RenderingExport.h"

#include "LightConstant.h"
#include "Detail/LightConstantImpl.h"

#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26434)
CORE_TOOLS_RTTI_DEFINE(Rendering, LightConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightConstant);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, LightConstant); 
Rendering::LightConstant::LightConstant(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, LightConstant)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, LightConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, LightConstant)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, LightConstant)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, LightConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, LightConstant)
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, LightConstant);
#define COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE_WITH_PARENT(namespaceName, className)      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, impl{ std::make_shared<ImplType>(*rhs.impl) }                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(rhs);                                                         \
        impl = std::make_shared<ImplType>(*rhs.impl);                                       \
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
COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE_WITH_PARENT(Rendering, LightConstant);

Rendering::LightConstant
	::LightConstant(const LightSharedPtr& light)
	:ParentType{ sm_NumRegisters }, impl{ make_shared<ImplType>(light) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightConstant)

void Rendering::LightConstant
	::SetNumRegisters(int numRegisters)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(numRegisters == sm_NumRegisters, "LightConstant¼Ä´æÆ÷µÄÊýÁ¿±ØÐëÎª1");

	ParentType::SetNumRegisters(numRegisters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, LightConstant,GetLight, const Rendering::ConstLightSharedPtr )




#include STSTEM_WARNING_POP