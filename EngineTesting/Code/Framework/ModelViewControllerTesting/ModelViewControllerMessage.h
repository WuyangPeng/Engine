///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 13:42)

#ifndef MODEL_VIEW_CONTROLLER_TESTING_MODEL_VIEW_CONTROLLER_MESSAGE_H
#define MODEL_VIEW_CONTROLLER_TESTING_MODEL_VIEW_CONTROLLER_MESSAGE_H

#include "FrameViewMiddleLayer.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ControllerMiddleLayer.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainer.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace ModelViewController
{
    using MiddleLayerType = Framework::ModelViewControllerMiddleLayerContainer<Framework::WindowApplicationTrait, Framework::ModelMiddleLayer, FrameViewMiddleLayer, Framework::ControllerMiddleLayer>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class ModelViewControllerMessage final : public MessageType
    {
    public:
        using ClassType = ModelViewControllerMessage;
        using ParentType = MessageType;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ModelViewControllerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ConsoleAlloc = CoreTools::ConsoleAlloc;

    private:
        ConsoleAlloc alloc;
    };

    using ModelViewControllerTesting = Framework::WindowProcessHandle<ModelViewControllerMessage>;
}

#endif  // MODEL_VIEW_CONTROLLER_TESTING_MODEL_VIEW_CONTROLLER_MESSAGE_H
