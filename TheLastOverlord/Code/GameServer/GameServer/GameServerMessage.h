///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/24 22:11)

#ifndef GAME_SERVER_GAME_SERVER_MESSAGE_H
#define GAME_SERVER_GAME_SERVER_MESSAGE_H

#include "GameServer/GameServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "GameServer/GameServerMiddleLayer/Audio/AudioManager.h"
#include "GameServer/GameServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "GameServer/GameServerMiddleLayer/Event/EventManager.h"
#include "GameServer/GameServerMiddleLayer/GUI/GUIManager.h"
#include "GameServer/GameServerMiddleLayer/Input/InputManager.h"
#include "GameServer/GameServerMiddleLayer/Message/MessageManager.h"
#include "GameServer/GameServerMiddleLayer/Network/NetworkManager.h"
#include "GameServer/GameServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "GameServer/GameServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "GameServer/GameServerMiddleLayer/Rendering/RenderingManager.h"
#include "GameServer/GameServerMiddleLayer/Resource/ResourceManager.h"
#include "GameServer/GameServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace GameServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<GameServerMiddleLayer::ObjectLogicManager, GameServerMiddleLayer::ArtificialIntellegenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  GameServerMiddleLayer::InputManager,
                                                                  GameServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  GameServerMiddleLayer::PhysicalModellingManager,
                                                                  GameServerMiddleLayer::MessageManager,
                                                                  GameServerMiddleLayer::EventManager,
                                                                  GameServerMiddleLayer::SystemManager,
                                                                  GameServerMiddleLayer::ResourceManager,
                                                                  GameServerMiddleLayer::AudioManager,
                                                                  GameServerMiddleLayer::CameraSystemsManager,
                                                                  GameServerMiddleLayer::RenderingManager,
                                                                  GameServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class GameServerMessage : public MessageType
    {
    public:
        using ClassType = GameServerMessage;
        using ParentType = MessageType;

    public:
        explicit GameServerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using GameServerMessageWindowProcessHandle = Framework::WindowProcessHandle<GameServerMessage>;
}

#endif  // GAME_SERVER_GAME_SERVER_MESSAGE_H
