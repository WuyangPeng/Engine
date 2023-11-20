/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef FIGHTING_SERVER_FIGHTING_SERVER_MESSAGE_H
#define FIGHTING_SERVER_FIGHTING_SERVER_MESSAGE_H

#include "FightingServer/FightingServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "FightingServer/FightingServerMiddleLayer/Audio/AudioManager.h"
#include "FightingServer/FightingServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "FightingServer/FightingServerMiddleLayer/Event/EventManager.h"
#include "FightingServer/FightingServerMiddleLayer/GUI/GUIManager.h"
#include "FightingServer/FightingServerMiddleLayer/Input/InputManager.h"
#include "FightingServer/FightingServerMiddleLayer/Message/MessageManager.h"
#include "FightingServer/FightingServerMiddleLayer/Network/NetworkManager.h"
#include "FightingServer/FightingServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "FightingServer/FightingServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "FightingServer/FightingServerMiddleLayer/Rendering/RenderingManager.h"
#include "FightingServer/FightingServerMiddleLayer/Resource/ResourceManager.h"
#include "FightingServer/FightingServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace FightingServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<FightingServerMiddleLayer::ObjectLogicManager, FightingServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  FightingServerMiddleLayer::InputManager,
                                                                  FightingServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  FightingServerMiddleLayer::PhysicalModellingManager,
                                                                  FightingServerMiddleLayer::MessageManager,
                                                                  FightingServerMiddleLayer::EventManager,
                                                                  FightingServerMiddleLayer::SystemManager,
                                                                  FightingServerMiddleLayer::ResourceManager,
                                                                  FightingServerMiddleLayer::AudioManager,
                                                                  FightingServerMiddleLayer::CameraSystemsManager,
                                                                  FightingServerMiddleLayer::RenderingManager,
                                                                  FightingServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class FightingServerMessage : public MessageType
    {
    public:
        using ClassType = FightingServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        FightingServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using FightingServerMessageWindowProcessHandle = Framework::WindowProcessHandle<FightingServerMessage>;
}

#endif  // FIGHTING_SERVER_FIGHTING_SERVER_MESSAGE_H
