/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:26)

#ifndef OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H
#define OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H

#include "OfflineServer/OfflineServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Audio/AudioManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Event/EventManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/GUI/GUIManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Input/InputManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Message/MessageManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Network/NetworkManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Rendering/RenderingManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/Resource/ResourceManager.h"
#include "OfflineServer/OfflineServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace OfflineServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<OfflineServerMiddleLayer::ObjectLogicManager, OfflineServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  OfflineServerMiddleLayer::InputManager,
                                                                  OfflineServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  OfflineServerMiddleLayer::PhysicalModellingManager,
                                                                  OfflineServerMiddleLayer::MessageManager,
                                                                  OfflineServerMiddleLayer::EventManager,
                                                                  OfflineServerMiddleLayer::SystemManager,
                                                                  OfflineServerMiddleLayer::ResourceManager,
                                                                  OfflineServerMiddleLayer::AudioManager,
                                                                  OfflineServerMiddleLayer::CameraSystemsManager,
                                                                  OfflineServerMiddleLayer::RenderingManager,
                                                                  OfflineServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class OfflineServerMessage final : public MessageType
    {
    public:
        using ClassType = OfflineServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        OfflineServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using OfflineServerMessageWindowProcessHandle = Framework::WindowProcessHandle<OfflineServerMessage>;
}

#endif  // OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H
