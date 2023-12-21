/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H
#define BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H

#include "BackgroundServer/BackgroundServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Audio/AudioManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Event/EventManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/GUI/GUIManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Input/InputManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Message/MessageManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Network/NetworkManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Rendering/RenderingManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Resource/ResourceManager.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace BackgroundServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<BackgroundServerMiddleLayer::ObjectLogicManager, BackgroundServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  BackgroundServerMiddleLayer::InputManager,
                                                                  BackgroundServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  BackgroundServerMiddleLayer::PhysicalModellingManager,
                                                                  BackgroundServerMiddleLayer::MessageManager,
                                                                  BackgroundServerMiddleLayer::EventManager,
                                                                  BackgroundServerMiddleLayer::SystemManager,
                                                                  BackgroundServerMiddleLayer::ResourceManager,
                                                                  BackgroundServerMiddleLayer::AudioManager,
                                                                  BackgroundServerMiddleLayer::CameraSystemsManager,
                                                                  BackgroundServerMiddleLayer::RenderingManager,
                                                                  BackgroundServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class BackgroundServerMessage final : public MessageType
    {
    public:
        using ClassType = BackgroundServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        BackgroundServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using BackgroundServerMessageWindowProcessHandle = Framework::WindowProcessHandle<BackgroundServerMessage>;
}

#endif  // BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H
