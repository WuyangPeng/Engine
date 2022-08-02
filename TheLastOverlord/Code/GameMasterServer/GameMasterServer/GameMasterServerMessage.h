///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 22:29)

#ifndef GAME_MASTER_SERVER_GAME_MASTER_SERVER_MESSAGE_H
#define GAME_MASTER_SERVER_GAME_MASTER_SERVER_MESSAGE_H

#include "GameMasterServer/GameMasterServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Audio/AudioManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Event/EventManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/GUI/GUIManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Input/InputManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Message/MessageManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Network/NetworkManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Rendering/RenderingManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/Resource/ResourceManager.h"
#include "GameMasterServer/GameMasterServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace GameMasterServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<GameMasterServerMiddleLayer::ObjectLogicManager, GameMasterServerMiddleLayer::ArtificialIntellegenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  GameMasterServerMiddleLayer::InputManager,
                                                                  GameMasterServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  GameMasterServerMiddleLayer::PhysicalModellingManager,
                                                                  GameMasterServerMiddleLayer::MessageManager,
                                                                  GameMasterServerMiddleLayer::EventManager,
                                                                  GameMasterServerMiddleLayer::SystemManager,
                                                                  GameMasterServerMiddleLayer::ResourceManager,
                                                                  GameMasterServerMiddleLayer::AudioManager,
                                                                  GameMasterServerMiddleLayer::CameraSystemsManager,
                                                                  GameMasterServerMiddleLayer::RenderingManager,
                                                                  GameMasterServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class GameMasterServerMessage : public MessageType
    {
    public:
        using ClassType = GameMasterServerMessage;
        using ParentType = MessageType;

    public:
        explicit GameMasterServerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using GameMasterServerMessageWindowProcessHandle = Framework::WindowProcessHandle<GameMasterServerMessage>;
}

#endif  // GAME_MASTER_SERVER_GAME_MASTER_SERVER_MESSAGE_H
