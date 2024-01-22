/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:56)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H

#include "ModelViewControllerMiddleLayerContainer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::ModelViewControllerMiddleLayerContainer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      modelMiddleLayer{ std::make_shared<ModelMiddleLayer>(middleLayerPlatform, environmentDirectory) },
      viewMiddleLayer{ std::make_shared<ViewMiddleLayer>(middleLayerPlatform, environmentDirectory) },
      controllerMiddleLayer{ std::make_shared<ControllerMiddleLayerType>(middleLayerPlatform, environmentDirectory) }
{
    modelMiddleLayer->SetViewMiddleLayer(viewMiddleLayer);
    modelMiddleLayer->SetControllerMiddleLayer(controllerMiddleLayer);

    viewMiddleLayer->SetModelMiddleLayer(modelMiddleLayer);
    viewMiddleLayer->SetControllerMiddleLayer(controllerMiddleLayer);

    controllerMiddleLayer->SetModelMiddleLayer(modelMiddleLayer);
    controllerMiddleLayer->SetViewMiddleLayer(viewMiddleLayer);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::ModelViewControllerMiddleLayerContainer(ModelViewControllerMiddleLayerContainer&& rhs) noexcept
    : ParentType{ std::move(rhs) },
      modelMiddleLayer{ std::move(rhs.modelMiddleLayer) },
      viewMiddleLayer{ std::move(rhs.viewMiddleLayer) },
      controllerMiddleLayer{ std::move(rhs.controllerMiddleLayer) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>& Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::operator=(ModelViewControllerMiddleLayerContainer&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    modelMiddleLayer = std::move(rhs.modelMiddleLayer);
    viewMiddleLayer = std::move(rhs.viewMiddleLayer);
    controllerMiddleLayer = std::move(rhs.controllerMiddleLayer);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::IsValid() const noexcept
{
    if (ParentType::IsValid() && modelMiddleLayer != nullptr && viewMiddleLayer != nullptr && controllerMiddleLayer != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::PreCreate() && modelMiddleLayer->PreCreate() && viewMiddleLayer->PreCreate() && controllerMiddleLayer->PreCreate())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Create(const EnvironmentParameter& environmentParameter)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Create(environmentParameter) && modelMiddleLayer->Create(environmentParameter) && viewMiddleLayer->Create(environmentParameter) && controllerMiddleLayer->Create(environmentParameter))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Initialize() && viewMiddleLayer->Initialize() && modelMiddleLayer->Initialize() && controllerMiddleLayer->Initialize())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Destroy() && modelMiddleLayer->Destroy() && viewMiddleLayer->Destroy() && controllerMiddleLayer->Destroy())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
void Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::Terminate();

    modelMiddleLayer->Terminate();
    viewMiddleLayer->Terminate();
    controllerMiddleLayer->Terminate();
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
void Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::PreIdle();

    modelMiddleLayer->PreIdle();
    viewMiddleLayer->PreIdle();
    controllerMiddleLayer->PreIdle();
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Idle(int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Idle(timeDelta) && modelMiddleLayer->Idle(timeDelta) && viewMiddleLayer->Idle(timeDelta) && controllerMiddleLayer->Idle(timeDelta))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Paint()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Paint() && viewMiddleLayer->Paint())
        return true;
    else
        return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Move(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Move(point) && viewMiddleLayer->Move(point))
        return true;
    else
        return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Resize(windowDisplay, size) && viewMiddleLayer->Resize(windowDisplay, size))
        return true;
    else
        return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::KeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::KeyUp(key, point) && controllerMiddleLayer->KeyUp(key, point))
        return true;
    else
        return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::KeyDown(key, point) && controllerMiddleLayer->KeyDown(key, point))
        return true;
    else
        return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::SpecialKeyUp(key, point) && controllerMiddleLayer->SpecialKeyUp(key, point))
        return true;
    else
        return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::SpecialKeyDown(key, point) && controllerMiddleLayer->SpecialKeyDown(key, point))
        return true;
    else
        return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::PassiveMotion(const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::PassiveMotion(point) && controllerMiddleLayer->PassiveMotion(point))
        return true;
    else
        return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::Motion(point, virtualKeys) && controllerMiddleLayer->Motion(point, virtualKeys))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::MouseWheel(delta, point, virtualKeys) && controllerMiddleLayer->MouseWheel(delta, point, virtualKeys))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template <typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (ParentType::MouseClick(button, state, point, virtualKeys) && controllerMiddleLayer->MouseClick(button, state, point, virtualKeys))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H
