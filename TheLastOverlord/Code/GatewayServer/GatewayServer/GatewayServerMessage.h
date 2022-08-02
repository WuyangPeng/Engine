///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/23 14:01)

#ifndef GATEWAY_SERVER_GATEWAY_SERVER_MESSAGE_H
#define GATEWAY_SERVER_GATEWAY_SERVER_MESSAGE_H

#include "GatewayServer/GatewayServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
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
    using ObjectLogicManager = Framework::ObjectLogicManager<GatewayServerMiddleLayer::ObjectLogicManager, GatewayServerMiddleLayer::ArtificialIntellegenceManager>;
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

    class GatewayServerMessage : public MessageType
    {
    public:
        using ClassType = GatewayServerMessage;
        using ParentType = MessageType;

    public:
        explicit GatewayServerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using GatewayServerMessageWindowProcessHandle = Framework::WindowProcessHandle<GatewayServerMessage>;
}

#endif  // GATEWAY_SERVER_GATEWAY_SERVER_MESSAGE_H
