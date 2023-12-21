/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:10)

#ifndef CORSS_SERVER_CORSS_SERVER_MESSAGE_H
#define CORSS_SERVER_CORSS_SERVER_MESSAGE_H

#include "CorssServer/CorssServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "CorssServer/CorssServerMiddleLayer/Audio/AudioManager.h"
#include "CorssServer/CorssServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "CorssServer/CorssServerMiddleLayer/Event/EventManager.h"
#include "CorssServer/CorssServerMiddleLayer/GUI/GUIManager.h"
#include "CorssServer/CorssServerMiddleLayer/Input/InputManager.h"
#include "CorssServer/CorssServerMiddleLayer/Message/MessageManager.h"
#include "CorssServer/CorssServerMiddleLayer/Network/NetworkManager.h"
#include "CorssServer/CorssServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "CorssServer/CorssServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "CorssServer/CorssServerMiddleLayer/Rendering/RenderingManager.h"
#include "CorssServer/CorssServerMiddleLayer/Resource/ResourceManager.h"
#include "CorssServer/CorssServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace CorssServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<CorssServerMiddleLayer::ObjectLogicManager, CorssServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  CorssServerMiddleLayer::InputManager,
                                                                  CorssServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  CorssServerMiddleLayer::PhysicalModellingManager,
                                                                  CorssServerMiddleLayer::MessageManager,
                                                                  CorssServerMiddleLayer::EventManager,
                                                                  CorssServerMiddleLayer::SystemManager,
                                                                  CorssServerMiddleLayer::ResourceManager,
                                                                  CorssServerMiddleLayer::AudioManager,
                                                                  CorssServerMiddleLayer::CameraSystemsManager,
                                                                  CorssServerMiddleLayer::RenderingManager,
                                                                  CorssServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class CorssServerMessage final : public MessageType
    {
    public:
        using ClassType = CorssServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        CorssServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using CorssServerMessageWindowProcessHandle = Framework::WindowProcessHandle<CorssServerMessage>;
}

#endif  // CORSS_SERVER_CORSS_SERVER_MESSAGE_H
