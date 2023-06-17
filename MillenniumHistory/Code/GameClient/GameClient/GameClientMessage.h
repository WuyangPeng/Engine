///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/13 21:38)

#ifndef GAME_CLIENT_GAME_CLIENT_MESSAGE_H
#define GAME_CLIENT_GAME_CLIENT_MESSAGE_H

#include "GameClient/GameClientMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "GameClient/GameClientMiddleLayer/Audio/AudioManager.h"
#include "GameClient/GameClientMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "GameClient/GameClientMiddleLayer/Event/EventManager.h"
#include "GameClient/GameClientMiddleLayer/GUI/GUIManager.h"
#include "GameClient/GameClientMiddleLayer/Input/InputManager.h"
#include "GameClient/GameClientMiddleLayer/Message/MessageManager.h"
#include "GameClient/GameClientMiddleLayer/Network/NetworkManager.h"
#include "GameClient/GameClientMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "GameClient/GameClientMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "GameClient/GameClientMiddleLayer/Rendering/RenderingManager.h"
#include "GameClient/GameClientMiddleLayer/Resource/ResourceManager.h"
#include "GameClient/GameClientMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace GameClient
{
    using ObjectLogicManager = Framework::ObjectLogicManager<GameClientMiddleLayer::ObjectLogicManager, GameClientMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  GameClientMiddleLayer::InputManager,
                                                                  GameClientMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  GameClientMiddleLayer::PhysicalModellingManager,
                                                                  GameClientMiddleLayer::MessageManager,
                                                                  GameClientMiddleLayer::EventManager,
                                                                  GameClientMiddleLayer::SystemManager,
                                                                  GameClientMiddleLayer::ResourceManager,
                                                                  GameClientMiddleLayer::AudioManager,
                                                                  GameClientMiddleLayer::CameraSystemsManager,
                                                                  GameClientMiddleLayer::RenderingManager,
                                                                  GameClientMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class GameClientMessage : public MessageType
    {
    public:
        using ClassType = GameClientMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        GameClientMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using GameClientMessageWindowProcessHandle = Framework::WindowProcessHandle<GameClientMessage>;
}

#endif  // GAME_CLIENT_GAME_CLIENT_MESSAGE_H
