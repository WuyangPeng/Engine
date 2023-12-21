/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/17 20:09)

#ifndef PLAYER_SERVER_PLAYER_SERVER_MESSAGE_H
#define PLAYER_SERVER_PLAYER_SERVER_MESSAGE_H

#include "PlayerServer/PlayerServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/Audio/AudioManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/Event/EventManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/GUI/GUIManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/Input/InputManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/Message/MessageManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/Network/NetworkManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/Rendering/RenderingManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/Resource/ResourceManager.h"
#include "PlayerServer/PlayerServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace PlayerServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<PlayerServerMiddleLayer::ObjectLogicManager, PlayerServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  PlayerServerMiddleLayer::InputManager,
                                                                  PlayerServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  PlayerServerMiddleLayer::PhysicalModellingManager,
                                                                  PlayerServerMiddleLayer::MessageManager,
                                                                  PlayerServerMiddleLayer::EventManager,
                                                                  PlayerServerMiddleLayer::SystemManager,
                                                                  PlayerServerMiddleLayer::ResourceManager,
                                                                  PlayerServerMiddleLayer::AudioManager,
                                                                  PlayerServerMiddleLayer::CameraSystemsManager,
                                                                  PlayerServerMiddleLayer::RenderingManager,
                                                                  PlayerServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class PlayerServerMessage final : public MessageType
    {
    public:
        using ClassType = PlayerServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        PlayerServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using PlayerServerMessageWindowProcessHandle = Framework::WindowProcessHandle<PlayerServerMessage>;
}

#endif  // PLAYER_SERVER_PLAYER_SERVER_MESSAGE_H
