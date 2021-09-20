// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:52)

#include "Rendering/RenderingExport.h"

#include "AlphaState.h"
#include "Detail/AlphaStateImpl.h"
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
CORE_TOOLS_RTTI_DEFINE(Rendering,AlphaState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,AlphaState);
CORE_TOOLS_FACTORY_DEFINE(Rendering,AlphaState);  

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, AlphaState);

Rendering::AlphaState::AlphaState(LoadConstructor loadConstructor)
        : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
    {
        SELF_CLASS_IS_VALID_0;
    }
    CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, AlphaState)
    CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, AlphaState)
    CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, AlphaState)
    CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, AlphaState)
    CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, AlphaState)
    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, AlphaState)

Rendering::AlphaState
	::AlphaState()
	:ParentType{ "AlphaState" }, impl{ make_shared< ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}
 
Rendering::AlphaState
	::~AlphaState ()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, AlphaState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,AlphaState,IsBlendEnabled,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,AlphaState,GetSourceBlend,Rendering::AlphaState::SourceBlendMode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,AlphaState,GetDestinationBlend,Rendering::AlphaState::DestinationBlendMode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,AlphaState,IsCompareEnabled,bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,AlphaState,GetCompare,Rendering::AlphaState::CompareMode)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,AlphaState,GetReference,float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,AlphaState,GetConstantColor,const Rendering::AlphaState::Colour)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,AlphaState,SetBlendEnabled,bool,void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,AlphaState,SetSourceBlend,SourceBlendMode,void)		
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,AlphaState,SetDestinationBlend,DestinationBlendMode,void) 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,AlphaState,SetCompareEnabled,bool,void) 		
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,AlphaState,SetCompare,CompareMode,void) 			
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,AlphaState,SetReference,float,void)  	
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,AlphaState,SetConstantColor,Colour,void)  

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, AlphaState,SaveState, WriteFileManager&, void)
 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, AlphaState,LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::AlphaState::CloneObject() const 
{
	 RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP