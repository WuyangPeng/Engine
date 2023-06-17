///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/22 23:13)

#ifndef BACKGROUND_CLIENT_BACKGROUND_CLIENT_MESSAGE_H
#define BACKGROUND_CLIENT_BACKGROUND_CLIENT_MESSAGE_H

#include "BackgroundClient/BackgroundClientMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Audio/AudioManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Event/EventManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/GUI/GUIManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Input/InputManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Message/MessageManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Network/NetworkManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Rendering/RenderingManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/Resource/ResourceManager.h"
#include "BackgroundClient/BackgroundClientMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace BackgroundClient
{
    using ObjectLogicManager = Framework::ObjectLogicManager<BackgroundClientMiddleLayer::ObjectLogicManager, BackgroundClientMiddleLayer::ArtificialIntellegenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  BackgroundClientMiddleLayer::InputManager,
                                                                  BackgroundClientMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  BackgroundClientMiddleLayer::PhysicalModellingManager,
                                                                  BackgroundClientMiddleLayer::MessageManager,
                                                                  BackgroundClientMiddleLayer::EventManager,
                                                                  BackgroundClientMiddleLayer::SystemManager,
                                                                  BackgroundClientMiddleLayer::ResourceManager,
                                                                  BackgroundClientMiddleLayer::AudioManager,
                                                                  BackgroundClientMiddleLayer::CameraSystemsManager,
                                                                  BackgroundClientMiddleLayer::RenderingManager,
                                                                  BackgroundClientMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class BackgroundClientMessage : public MessageType
    {
    public:
        using ClassType = BackgroundClientMessage;
        using ParentType = MessageType;

    public:
        explicit BackgroundClientMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using BackgroundClientMessageWindowProcessHandle = Framework::WindowProcessHandle<BackgroundClientMessage>;
}

#endif  // BACKGROUND_CLIENT_BACKGROUND_CLIENT_MESSAGE_H
