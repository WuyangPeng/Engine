///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 18:01)

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

    class CameraModelViewControllerMessage final : public MessageType
    {
    public:
        using ClassType = CameraModelViewControllerMessage;
        using ParentType = MessageType;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        CameraModelViewControllerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ConsoleAlloc = CoreTools::ConsoleAlloc;

    private:
        ConsoleAlloc alloc;
    };

    using CameraModelViewControllerTesting = Framework::WindowProcessHandle<CameraModelViewControllerMessage>;
}

#endif  // CAMERA_MODEL_VIEW_CONTROLLER_TESTING_PIXEL_MODEL_VIEW_CONTROLLER_MESSAGE_H
