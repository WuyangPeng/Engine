///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/23 17:22)

#ifndef CAMERA_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H
#define CAMERA_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H

#include "FrameViewMiddleLayer.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayer.h"
#include "Framework/MiddleLayer/CameraModelMiddleLayer.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainer.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace CameraModelViewController
{
    using MiddleLayerType = Framework::ModelViewControllerMiddleLayerContainer<Framework::WindowApplicationTrait, Framework::CameraModelMiddleLayer, FrameViewMiddleLayer, Framework::CameraControllerMiddleLayer>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class CameraModelViewControllerMessage : public MessageType
    {
    public:
        using ClassType = CameraModelViewControllerMessage;
        using ParentType = MessageType;

    public:
        CameraModelViewControllerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using CameraModelViewControllerTesting = Framework::WindowProcessHandle<CameraModelViewControllerMessage>;
}

#endif  // CAMERA_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H
