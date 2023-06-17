///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:24)

#include "Framework/FrameworkExport.h"

#include "ModelViewControllerMiddleLayerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ModelViewControllerMiddleLayerImpl::ModelViewControllerMiddleLayerImpl() noexcept
    : model{}, view{}, controller{}
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ModelViewControllerMiddleLayerImpl)

void Framework::ModelViewControllerMiddleLayerImpl::SetModelMiddleLayer(const MiddleLayerSharedPtr& modelMiddleLayer) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    model = modelMiddleLayer;
}

void Framework::ModelViewControllerMiddleLayerImpl::SetViewMiddleLayer(const MiddleLayerSharedPtr& viewMiddleLayer) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    view = viewMiddleLayer;
}

void Framework::ModelViewControllerMiddleLayerImpl::SetControllerMiddleLayer(const MiddleLayerSharedPtr& controllerMiddleLayer) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    controller = controllerMiddleLayer;
}

Framework::ModelViewControllerMiddleLayerImpl::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl::GetModelMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return model.lock();
}

Framework::ModelViewControllerMiddleLayerImpl::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl::GetViewMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return view.lock();
}

Framework::ModelViewControllerMiddleLayerImpl::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl::GetControllerMiddleLayer() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return controller.lock();
}

Framework::ModelViewControllerMiddleLayerImpl::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl::GetConstModelMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return model.lock();
}

Framework::ModelViewControllerMiddleLayerImpl::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl::GetConstViewMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return view.lock();
}

Framework::ModelViewControllerMiddleLayerImpl::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl::GetConstControllerMiddleLayer() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return controller.lock();
}
