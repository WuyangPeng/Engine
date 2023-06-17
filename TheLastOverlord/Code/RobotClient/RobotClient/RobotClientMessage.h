///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/22 17:18)

#ifndef ROBOT_CLIENT_ROBOT_CLIENT_MESSAGE_H
#define ROBOT_CLIENT_ROBOT_CLIENT_MESSAGE_H

#include "RobotClient/RobotClientMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "RobotClient/RobotClientMiddleLayer/Audio/AudioManager.h"
#include "RobotClient/RobotClientMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "RobotClient/RobotClientMiddleLayer/Event/EventManager.h"
#include "RobotClient/RobotClientMiddleLayer/GUI/GUIManager.h"
#include "RobotClient/RobotClientMiddleLayer/Input/InputManager.h"
#include "RobotClient/RobotClientMiddleLayer/Message/MessageManager.h"
#include "RobotClient/RobotClientMiddleLayer/Network/NetworkManager.h"
#include "RobotClient/RobotClientMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "RobotClient/RobotClientMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "RobotClient/RobotClientMiddleLayer/Rendering/RenderingManager.h"
#include "RobotClient/RobotClientMiddleLayer/Resource/ResourceManager.h"
#include "RobotClient/RobotClientMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace RobotClient
{
    using ObjectLogicManager = Framework::ObjectLogicManager<RobotClientMiddleLayer::ObjectLogicManager, RobotClientMiddleLayer::ArtificialIntellegenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  RobotClientMiddleLayer::InputManager,
                                                                  RobotClientMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  RobotClientMiddleLayer::PhysicalModellingManager,
                                                                  RobotClientMiddleLayer::MessageManager,
                                                                  RobotClientMiddleLayer::EventManager,
                                                                  RobotClientMiddleLayer::SystemManager,
                                                                  RobotClientMiddleLayer::ResourceManager,
                                                                  RobotClientMiddleLayer::AudioManager,
                                                                  RobotClientMiddleLayer::CameraSystemsManager,
                                                                  RobotClientMiddleLayer::RenderingManager,
                                                                  RobotClientMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class RobotClientMessage : public MessageType
    {
    public:
        using ClassType = RobotClientMessage;
        using ParentType = MessageType;

    public:
        explicit RobotClientMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using RobotClientMessageWindowProcessHandle = Framework::WindowProcessHandle<RobotClientMessage>;
}

#endif  // ROBOT_CLIENT_ROBOT_CLIENT_MESSAGE_H
