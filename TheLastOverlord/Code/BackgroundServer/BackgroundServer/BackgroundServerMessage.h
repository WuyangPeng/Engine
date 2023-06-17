///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/29 18:46)
#ifndef BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H
#define BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H

#include "BackgroundServer/BackgroundServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
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
    using ObjectLogicManager = Framework::ObjectLogicManager<BackgroundServerMiddleLayer::ObjectLogicManager, BackgroundServerMiddleLayer::ArtificialIntellegenceManager>;
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

    class BackgroundServerMessage : public MessageType
    {
    public:
        using ClassType = BackgroundServerMessage;
        using ParentType = MessageType;

    public:
        explicit BackgroundServerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using BackgroundServerMessageWindowProcessHandle = Framework::WindowProcessHandle<BackgroundServerMessage>;
}

#endif  // BACKGROUND_SERVER_BACKGROUND_SERVER_MESSAGE_H
