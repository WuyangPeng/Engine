///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 17:07)

#ifndef PIXEL_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H
#define PIXEL_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H

#include "FrameViewMiddleLayer.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ControllerMiddleLayer.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainer.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace PixelModelViewController
{
    using MiddleLayerType = Framework::ModelViewControllerMiddleLayerContainer<Framework::WindowApplicationTrait, Framework::ModelMiddleLayer, FrameViewMiddleLayer, Framework::ControllerMiddleLayer>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class PixelModelViewControllerMessage : public MessageType
    {
    public:
        using ClassType = PixelModelViewControllerMessage;
        using ParentType = MessageType;

    public:
        explicit PixelModelViewControllerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using PixelModelViewControllerTesting = Framework::WindowProcessHandle<PixelModelViewControllerMessage>;
}

#endif  // PIXEL_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H
