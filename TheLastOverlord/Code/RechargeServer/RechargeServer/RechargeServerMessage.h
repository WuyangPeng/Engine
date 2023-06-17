///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/27 22:20)

#ifndef RECHARGE_SERVER_RECHARGE_SERVER_MESSAGE_H
#define RECHARGE_SERVER_RECHARGE_SERVER_MESSAGE_H

#include "RechargeServer/RechargeServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
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
    using ObjectLogicManager = Framework::ObjectLogicManager<RechargeServerMiddleLayer::ObjectLogicManager, RechargeServerMiddleLayer::ArtificialIntellegenceManager>;
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

    class RechargeServerMessage : public MessageType
    {
    public:
        using ClassType = RechargeServerMessage;
        using ParentType = MessageType;

    public:
        explicit RechargeServerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using RechargeServerMessageWindowProcessHandle = Framework::WindowProcessHandle<RechargeServerMessage>;
}

#endif  // RECHARGE_SERVER_RECHARGE_SERVER_MESSAGE_H
