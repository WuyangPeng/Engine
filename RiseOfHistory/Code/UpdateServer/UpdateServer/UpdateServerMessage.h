/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H
#define UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H

#include "UpdateServer/UpdateServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Audio/AudioManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Event/EventManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/GUI/GUIManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Input/InputManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Message/MessageManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Network/NetworkManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Rendering/RenderingManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/Resource/ResourceManager.h"
#include "UpdateServer/UpdateServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace UpdateServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<UpdateServerMiddleLayer::ObjectLogicManager, UpdateServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  UpdateServerMiddleLayer::InputManager,
                                                                  UpdateServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  UpdateServerMiddleLayer::PhysicalModellingManager,
                                                                  UpdateServerMiddleLayer::MessageManager,
                                                                  UpdateServerMiddleLayer::EventManager,
                                                                  UpdateServerMiddleLayer::SystemManager,
                                                                  UpdateServerMiddleLayer::ResourceManager,
                                                                  UpdateServerMiddleLayer::AudioManager,
                                                                  UpdateServerMiddleLayer::CameraSystemsManager,
                                                                  UpdateServerMiddleLayer::RenderingManager,
                                                                  UpdateServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class UpdateServerMessage final : public MessageType
    {
    public:
        using ClassType = UpdateServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        UpdateServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using UpdateServerMessageWindowProcessHandle = Framework::WindowProcessHandle<UpdateServerMessage>;
}

#endif  // UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H
