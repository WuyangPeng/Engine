/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef GATEWAY_SERVER_GATEWAY_SERVER_MESSAGE_H
#define GATEWAY_SERVER_GATEWAY_SERVER_MESSAGE_H

#include "GatewayServer/GatewayServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/Audio/AudioManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/Event/EventManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/GUI/GUIManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/Input/InputManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/Message/MessageManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/Network/NetworkManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/Rendering/RenderingManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/Resource/ResourceManager.h"
#include "GatewayServer/GatewayServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace GatewayServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<GatewayServerMiddleLayer::ObjectLogicManager, GatewayServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  GatewayServerMiddleLayer::InputManager,
                                                                  GatewayServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  GatewayServerMiddleLayer::PhysicalModellingManager,
                                                                  GatewayServerMiddleLayer::MessageManager,
                                                                  GatewayServerMiddleLayer::EventManager,
                                                                  GatewayServerMiddleLayer::SystemManager,
                                                                  GatewayServerMiddleLayer::ResourceManager,
                                                                  GatewayServerMiddleLayer::AudioManager,
                                                                  GatewayServerMiddleLayer::CameraSystemsManager,
                                                                  GatewayServerMiddleLayer::RenderingManager,
                                                                  GatewayServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class GatewayServerMessage final : public MessageType
    {
    public:
        using ClassType = GatewayServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        GatewayServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using GatewayServerMessageWindowProcessHandle = Framework::WindowProcessHandle<GatewayServerMessage>;
}

#endif  // GATEWAY_SERVER_GATEWAY_SERVER_MESSAGE_H
