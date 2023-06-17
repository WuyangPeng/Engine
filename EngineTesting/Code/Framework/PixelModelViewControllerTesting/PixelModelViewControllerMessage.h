///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:33)

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
        PixelModelViewControllerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using PixelModelViewControllerTesting = Framework::WindowProcessHandle<PixelModelViewControllerMessage>;
}

#endif  // PIXEL_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H
