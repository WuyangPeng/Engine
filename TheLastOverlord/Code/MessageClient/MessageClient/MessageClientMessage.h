/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef MESSAGE_CLIENT_MESSAGE_CLIENT_MESSAGE_H
#define MESSAGE_CLIENT_MESSAGE_CLIENT_MESSAGE_H

#include "MessageClient/MessageClientMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "MessageClient/MessageClientMiddleLayer/Audio/AudioManager.h"
#include "MessageClient/MessageClientMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "MessageClient/MessageClientMiddleLayer/Event/EventManager.h"
#include "MessageClient/MessageClientMiddleLayer/GUI/GUIManager.h"
#include "MessageClient/MessageClientMiddleLayer/Input/InputManager.h"
#include "MessageClient/MessageClientMiddleLayer/Message/MessageManager.h"
#include "MessageClient/MessageClientMiddleLayer/Network/NetworkManager.h"
#include "MessageClient/MessageClientMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "MessageClient/MessageClientMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "MessageClient/MessageClientMiddleLayer/Rendering/RenderingManager.h"
#include "MessageClient/MessageClientMiddleLayer/Resource/ResourceManager.h"
#include "MessageClient/MessageClientMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace MessageClient
{
    using ObjectLogicManager = Framework::ObjectLogicManager<MessageClientMiddleLayer::ObjectLogicManager, MessageClientMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  MessageClientMiddleLayer::InputManager,
                                                                  MessageClientMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  MessageClientMiddleLayer::PhysicalModellingManager,
                                                                  MessageClientMiddleLayer::MessageManager,
                                                                  MessageClientMiddleLayer::EventManager,
                                                                  MessageClientMiddleLayer::SystemManager,
                                                                  MessageClientMiddleLayer::ResourceManager,
                                                                  MessageClientMiddleLayer::AudioManager,
                                                                  MessageClientMiddleLayer::CameraSystemsManager,
                                                                  MessageClientMiddleLayer::RenderingManager,
                                                                  MessageClientMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class MessageClientMessage : public MessageType
    {
    public:
        using ClassType = MessageClientMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        MessageClientMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using MessageClientMessageWindowProcessHandle = Framework::WindowProcessHandle<MessageClientMessage>;
}

#endif  // MESSAGE_CLIENT_MESSAGE_CLIENT_MESSAGE_H
