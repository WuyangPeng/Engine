///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 16:20)

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

    class ModelViewControllerMessage : public MessageType
    {
    public:
        using ClassType = ModelViewControllerMessage;
        using ParentType = MessageType;

    public:
        explicit ModelViewControllerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using ModelViewControllerTesting = Framework::WindowProcessHandle<ModelViewControllerMessage>;
}

#endif  // MODEL_VIEW_CONTROLLER_TESTING_MODEL_VIEW_CONTROLLER_MESSAGE_H
