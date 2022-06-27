///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/23 19:30)

#ifndef ENGINE_MIDDLE_LAYER_TESTING_ENGINE_MIDDLE_LAYER_MESSAGE_H
#define ENGINE_MIDDLE_LAYER_TESTING_ENGINE_MIDDLE_LAYER_MESSAGE_H

#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace EngineMiddleLayer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<Framework::ObjectLogicInterface, Framework::ArtificialIntellegenceInterface>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  Framework::InputManager,
                                                                  Framework::NetworkManagerInterface,
                                                                  ObjectLogicManager,
                                                                  Framework::PhysicalModellingManagerInterface,
                                                                  Framework::MessageManagerInterface,
                                                                  Framework::EventManagerInterface,
                                                                  Framework::SystemManagerInterface,
                                                                  Framework::ResourceManagerInterface,
                                                                  Framework::AudioManagerInterface,
                                                                  Framework::CameraSystemsManagerInterface,
                                                                  Framework::RenderingManagerInterface,
                                                                  Framework::GUIManagerInterface>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class EngineMiddleLayerMessage : public MessageType
    {
    public:
        using ClassType = EngineMiddleLayerMessage;
        using ParentType = MessageType;

    public:
        explicit EngineMiddleLayerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using EngineMiddleLayerTesting = Framework::WindowProcessHandle<EngineMiddleLayerMessage>;
}

#endif  // ENGINE_MIDDLE_LAYER_TESTING_ENGINE_MIDDLE_LAYER_MESSAGE_H
