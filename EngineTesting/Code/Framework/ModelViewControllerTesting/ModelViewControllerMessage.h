// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 09:25)

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
        CoreTools::ConsoleAlloc m_Alloc;
    };

    using ModelViewControllerTesting = Framework::WindowProcessHandle<ModelViewControllerMessage>;
}

#endif  // MODEL_VIEW_CONTROLLER_TESTING_MODEL_VIEW_CONTROLLER_MESSAGE_H
