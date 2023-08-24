///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 16:21)

#include "Framework/FrameworkExport.h"

#include "ModelViewControllerMiddleLayer.h"
#include "Detail/ModelViewControllerMiddleLayerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

Framework::ModelViewControllerMiddleLayer::ModelViewControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ModelViewControllerMiddleLayer)

void Framework::ModelViewControllerMiddleLayer::SetModelMiddleLayer(const MiddleLayerSharedPtr& modelMiddleLayer) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetModelMiddleLayer(modelMiddleLayer);
}

void Framework::ModelViewControllerMiddleLayer::SetViewMiddleLayer(const MiddleLayerSharedPtr& viewMiddleLayer) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetViewMiddleLayer(viewMiddleLayer);
}

void Framework::ModelViewControllerMiddleLayer::SetControllerMiddleLayer(const MiddleLayerSharedPtr& controllerMiddleLayer) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->SetControllerMiddleLayer(controllerMiddleLayer);
}

Framework::MiddleLayerInterface::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayer::GetModelMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->GetModelMiddleLayer();
}

Framework::MiddleLayerInterface::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayer::GetViewMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->GetViewMiddleLayer();
}

Framework::MiddleLayerInterface::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayer::GetControllerMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->GetControllerMiddleLayer();
}

Framework::MiddleLayerInterface::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayer::GetConstModelMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetConstModelMiddleLayer();
}

Framework::MiddleLayerInterface::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayer::GetConstViewMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetConstViewMiddleLayer();
}

Framework::MiddleLayerInterface::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayer::GetConstControllerMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetConstControllerMiddleLayer();
}
