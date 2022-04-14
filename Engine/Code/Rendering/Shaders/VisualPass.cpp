// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 17:31)

#include "Rendering/RenderingExport.h"

#include "VisualPass.h"
#include "Detail/VisualPassImpl.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, VisualPass);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualPass);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualPass);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, VisualPass);

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
COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, VisualPass);

Rendering::VisualPass::VisualPass(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, VisualPass)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, VisualPass)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, VisualPass)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, VisualPass)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, VisualPass)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, VisualPass)

Rendering::VisualPass::VisualPass()
    : ParentType{ "VisualPass" }, impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualPass::~VisualPass()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualPass)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass, SetVertexShader, VertexShaderSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass, SetPixelShader, PixelShaderSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass, SetAlphaState, AlphaStateSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass, SetCullState, CullStateSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass, SetDepthState, DepthStateSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass, SetOffsetState, OffsetStateSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass, SetStencilState, StencilStateSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualPass, SetWireState, WireStateSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass, GetVertexShader, const Rendering::ConstVertexShaderSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass, GetPixelShader, const Rendering::ConstPixelShaderSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass, GetAlphaState, const Rendering::ConstAlphaStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass, GetCullState, const Rendering::ConstCullStateSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass, GetDepthState, const Rendering::ConstDepthStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass, GetOffsetState, const Rendering::ConstOffsetStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass, GetStencilState, const Rendering::ConstStencilStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualPass, GetWireState, const Rendering::ConstWireStateSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualPass, SaveShader, WriteFileManager&, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualPass, SaveState, WriteFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualPass, LoadShader, ReadFileManager&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualPass, LoadState, ReadFileManager&, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::VisualPass::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP