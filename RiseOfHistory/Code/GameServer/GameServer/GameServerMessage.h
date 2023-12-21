/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef GAME_SERVER_GAME_SERVER_MESSAGE_H
#define GAME_SERVER_GAME_SERVER_MESSAGE_H

#include "GameServer/GameServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
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
    using ObjectLogicManager = Framework::ObjectLogicManager<GameServerMiddleLayer::ObjectLogicManager, GameServerMiddleLayer::ArtificialIntelligenceManager>;
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

    class GameServerMessage final : public MessageType
    {
    public:
        using ClassType = GameServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        GameServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using GameServerMessageWindowProcessHandle = Framework::WindowProcessHandle<GameServerMessage>;
}

#endif  // GAME_SERVER_GAME_SERVER_MESSAGE_H
