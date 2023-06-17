///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/29 17:24)

#ifndef UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H
#define UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H

#include "UpdateServer/UpdateServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
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
    using ObjectLogicManager = Framework::ObjectLogicManager<UpdateServerMiddleLayer::ObjectLogicManager, UpdateServerMiddleLayer::ArtificialIntellegenceManager>;
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

    class UpdateServerMessage : public MessageType
    {
    public:
        using ClassType = UpdateServerMessage;
        using ParentType = MessageType;

    public:
        explicit UpdateServerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using UpdateServerMessageWindowProcessHandle = Framework::WindowProcessHandle<UpdateServerMessage>;
}

#endif  // UPDATE_SERVER_UPDATE_SERVER_MESSAGE_H
