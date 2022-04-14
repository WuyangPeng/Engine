// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/24 17:19)

#include "Rendering/RenderingExport.h"

#include "StencilState.h"
#include "Detail/StencilStateImpl.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, StencilState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, StencilState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, StencilState);

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
COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, StencilState);

Rendering::StencilState::StencilState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, StencilState)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, StencilState)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, StencilState)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, StencilState)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, StencilState)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, StencilState)

Rendering::StencilState::StencilState()
    : ParentType{ "StencilState" }, impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::StencilState::~StencilState()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, StencilState)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, IsEnabled, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, GetCompare, Rendering::StencilState::CompareMode)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, GetReference, unsigned int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, GetMask, unsigned int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, GetWriteMask, unsigned int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, GetOnFail, Rendering::StencilState::OperationType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, GetOnZFail, Rendering::StencilState::OperationType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, StencilState, GetOnZPass, Rendering::StencilState::OperationType)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SetEnabled, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SetCompare, CompareMode, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SetReference, unsigned int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SetMask, unsigned int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SetWriteMask, unsigned int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SetOnFail, OperationType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SetOnZFail, OperationType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SetOnZPass, OperationType, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, StencilState, LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::StencilState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP