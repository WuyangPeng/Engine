///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 14:51)

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
