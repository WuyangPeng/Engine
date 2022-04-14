// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:54)

#include "Rendering/RenderingExport.h"

#include "DepthState.h"
#include "Detail/DepthStateImpl.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, DepthState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DepthState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DepthState);

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
        ;                                                                                   \
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
COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, DepthState);

Rendering::DepthState::DepthState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, DepthState)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, DepthState)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, DepthState)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, DepthState)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, DepthState)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, DepthState)

Rendering::DepthState::DepthState()
    : ParentType{ "DepthState" }, impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DepthState::~DepthState()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DepthState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DepthState, IsEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DepthState, IsWritable, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, DepthState, GetCompare, Rendering::DepthState::CompareMode)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState, SetEnabled, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState, SetWritable, bool, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState, SetCompare, CompareMode, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState, SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, DepthState, LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::DepthState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP