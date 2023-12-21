/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/17 20:09)

#ifndef CROSS_SERVER_CROSS_SERVER_MESSAGE_H
#define CROSS_SERVER_CROSS_SERVER_MESSAGE_H

#include "CrossServer/CrossServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "CrossServer/CrossServerMiddleLayer/Audio/AudioManager.h"
#include "CrossServer/CrossServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "CrossServer/CrossServerMiddleLayer/Event/EventManager.h"
#include "CrossServer/CrossServerMiddleLayer/GUI/GUIManager.h"
#include "CrossServer/CrossServerMiddleLayer/Input/InputManager.h"
#include "CrossServer/CrossServerMiddleLayer/Message/MessageManager.h"
#include "CrossServer/CrossServerMiddleLayer/Network/NetworkManager.h"
#include "CrossServer/CrossServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "CrossServer/CrossServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "CrossServer/CrossServerMiddleLayer/Rendering/RenderingManager.h"
#include "CrossServer/CrossServerMiddleLayer/Resource/ResourceManager.h"
#include "CrossServer/CrossServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace CrossServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<CrossServerMiddleLayer::ObjectLogicManager, CrossServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  CrossServerMiddleLayer::InputManager,
                                                                  CrossServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  CrossServerMiddleLayer::PhysicalModellingManager,
                                                                  CrossServerMiddleLayer::MessageManager,
                                                                  CrossServerMiddleLayer::EventManager,
                                                                  CrossServerMiddleLayer::SystemManager,
                                                                  CrossServerMiddleLayer::ResourceManager,
                                                                  CrossServerMiddleLayer::AudioManager,
                                                                  CrossServerMiddleLayer::CameraSystemsManager,
                                                                  CrossServerMiddleLayer::RenderingManager,
                                                                  CrossServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class CrossServerMessage final : public MessageType
    {
    public:
        using ClassType = CrossServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        CrossServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using CrossServerMessageWindowProcessHandle = Framework::WindowProcessHandle<CrossServerMessage>;
}

#endif  // CROSS_SERVER_CROSS_SERVER_MESSAGE_H
