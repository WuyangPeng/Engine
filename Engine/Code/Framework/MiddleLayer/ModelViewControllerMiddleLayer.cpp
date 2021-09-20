// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:55)

#include "Framework/FrameworkExport.h"

#include "ModelViewControllerMiddleLayer.h"
#include "Detail/ModelViewControllerMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::move;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
Framework::ModelViewControllerMiddleLayer ::ModelViewControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, impl{0}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelViewControllerMiddleLayer ::ModelViewControllerMiddleLayer(ModelViewControllerMiddleLayer&& rhs) noexcept
    : ParentType{ move(rhs) }, impl{ move(rhs.impl) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelViewControllerMiddleLayer& Framework::ModelViewControllerMiddleLayer ::operator=(ModelViewControllerMiddleLayer&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(move(rhs));

    impl = move(rhs.impl);

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelViewControllerMiddleLayer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, SetModelMiddleLayer, MiddleLayerSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, SetViewMiddleLayer, MiddleLayerSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, SetControllerMiddleLayer, MiddleLayerSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetModelMiddleLayer, const Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetViewMiddleLayer, const Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetControllerMiddleLayer, const Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetConstModelMiddleLayer, const Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetConstViewMiddleLayer, const Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetConstControllerMiddleLayer, const Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr)

#include STSTEM_WARNING_POP