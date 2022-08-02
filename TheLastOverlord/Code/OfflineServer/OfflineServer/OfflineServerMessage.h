///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/26 19:28)

#ifndef OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H
#define OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H

#include "OfflineServer/OfflineServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
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
    using ObjectLogicManager = Framework::ObjectLogicManager<OfflineServerMiddleLayer::ObjectLogicManager, OfflineServerMiddleLayer::ArtificialIntellegenceManager>;
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

    class OfflineServerMessage : public MessageType
    {
    public:
        using ClassType = OfflineServerMessage;
        using ParentType = MessageType;

    public:
        explicit OfflineServerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using OfflineServerMessageWindowProcessHandle = Framework::WindowProcessHandle<OfflineServerMessage>;
}

#endif  // OFFLINE_SERVER_OFFLINE_SERVER_MESSAGE_H
