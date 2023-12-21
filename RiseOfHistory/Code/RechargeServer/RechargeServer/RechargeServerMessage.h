/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef RECHARGE_SERVER_RECHARGE_SERVER_MESSAGE_H
#define RECHARGE_SERVER_RECHARGE_SERVER_MESSAGE_H

#include "RechargeServer/RechargeServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/Audio/AudioManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/Event/EventManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/GUI/GUIManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/Input/InputManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/Message/MessageManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/Network/NetworkManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/Rendering/RenderingManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/Resource/ResourceManager.h"
#include "RechargeServer/RechargeServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace RechargeServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<RechargeServerMiddleLayer::ObjectLogicManager, RechargeServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  RechargeServerMiddleLayer::InputManager,
                                                                  RechargeServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  RechargeServerMiddleLayer::PhysicalModellingManager,
                                                                  RechargeServerMiddleLayer::MessageManager,
                                                                  RechargeServerMiddleLayer::EventManager,
                                                                  RechargeServerMiddleLayer::SystemManager,
                                                                  RechargeServerMiddleLayer::ResourceManager,
                                                                  RechargeServerMiddleLayer::AudioManager,
                                                                  RechargeServerMiddleLayer::CameraSystemsManager,
                                                                  RechargeServerMiddleLayer::RenderingManager,
                                                                  RechargeServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class RechargeServerMessage final : public MessageType
    {
    public:
        using ClassType = RechargeServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        RechargeServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using RechargeServerMessageWindowProcessHandle = Framework::WindowProcessHandle<RechargeServerMessage>;
}

#endif  // RECHARGE_SERVER_RECHARGE_SERVER_MESSAGE_H
