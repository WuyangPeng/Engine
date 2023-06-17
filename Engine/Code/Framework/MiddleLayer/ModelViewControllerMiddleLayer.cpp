///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:26)

#include "Framework/FrameworkExport.h"

#include "ModelViewControllerMiddleLayer.h"
#include "Detail/ModelViewControllerMiddleLayerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::ModelViewControllerMiddleLayer::ModelViewControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelViewControllerMiddleLayer::ModelViewControllerMiddleLayer(ModelViewControllerMiddleLayer&& rhs) noexcept
    : ParentType{ move(rhs) }, impl{ std::move(rhs.impl) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::ModelViewControllerMiddleLayer& Framework::ModelViewControllerMiddleLayer::operator=(ModelViewControllerMiddleLayer&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    impl = std::move(rhs.impl);

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelViewControllerMiddleLayer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, SetModelMiddleLayer, MiddleLayerSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, SetViewMiddleLayer, MiddleLayerSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, SetControllerMiddleLayer, MiddleLayerSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetModelMiddleLayer, Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetViewMiddleLayer, Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetControllerMiddleLayer, Framework::ModelViewControllerMiddleLayer::MiddleLayerSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetConstModelMiddleLayer, Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetConstViewMiddleLayer, Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, ModelViewControllerMiddleLayer, GetConstControllerMiddleLayer, Framework::ModelViewControllerMiddleLayer::ConstMiddleLayerSharedPtr)
