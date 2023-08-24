/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#ifndef CHAT_SERVER_CHAT_SERVER_MESSAGE_H
#define CHAT_SERVER_CHAT_SERVER_MESSAGE_H

#include "ChatServer/ChatServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "ChatServer/ChatServerMiddleLayer/Audio/AudioManager.h"
#include "ChatServer/ChatServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "ChatServer/ChatServerMiddleLayer/Event/EventManager.h"
#include "ChatServer/ChatServerMiddleLayer/GUI/GUIManager.h"
#include "ChatServer/ChatServerMiddleLayer/Input/InputManager.h"
#include "ChatServer/ChatServerMiddleLayer/Message/MessageManager.h"
#include "ChatServer/ChatServerMiddleLayer/Network/NetworkManager.h"
#include "ChatServer/ChatServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "ChatServer/ChatServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "ChatServer/ChatServerMiddleLayer/Rendering/RenderingManager.h"
#include "ChatServer/ChatServerMiddleLayer/Resource/ResourceManager.h"
#include "ChatServer/ChatServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace ChatServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<ChatServerMiddleLayer::ObjectLogicManager, ChatServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  ChatServerMiddleLayer::InputManager,
                                                                  ChatServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  ChatServerMiddleLayer::PhysicalModellingManager,
                                                                  ChatServerMiddleLayer::MessageManager,
                                                                  ChatServerMiddleLayer::EventManager,
                                                                  ChatServerMiddleLayer::SystemManager,
                                                                  ChatServerMiddleLayer::ResourceManager,
                                                                  ChatServerMiddleLayer::AudioManager,
                                                                  ChatServerMiddleLayer::CameraSystemsManager,
                                                                  ChatServerMiddleLayer::RenderingManager,
                                                                  ChatServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class ChatServerMessage : public MessageType
    {
    public:
        using ClassType = ChatServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ChatServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using ChatServerMessageWindowProcessHandle = Framework::WindowProcessHandle<ChatServerMessage>;
}

#endif  // CHAT_SERVER_CHAT_SERVER_MESSAGE_H
