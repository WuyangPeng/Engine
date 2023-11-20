/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H
#define SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H

#include "ServerManager/ServerManagerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Audio/AudioManager.h"
#include "ServerManager/ServerManagerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Event/EventManager.h"
#include "ServerManager/ServerManagerMiddleLayer/GUI/GUIManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Input/InputManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Message/MessageManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Network/NetworkManager.h"
#include "ServerManager/ServerManagerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "ServerManager/ServerManagerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Rendering/RenderingManager.h"
#include "ServerManager/ServerManagerMiddleLayer/Resource/ResourceManager.h"
#include "ServerManager/ServerManagerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace ServerManager
{
    using ObjectLogicManager = Framework::ObjectLogicManager<ServerManagerMiddleLayer::ObjectLogicManager, ServerManagerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  ServerManagerMiddleLayer::InputManager,
                                                                  ServerManagerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  ServerManagerMiddleLayer::PhysicalModellingManager,
                                                                  ServerManagerMiddleLayer::MessageManager,
                                                                  ServerManagerMiddleLayer::EventManager,
                                                                  ServerManagerMiddleLayer::SystemManager,
                                                                  ServerManagerMiddleLayer::ResourceManager,
                                                                  ServerManagerMiddleLayer::AudioManager,
                                                                  ServerManagerMiddleLayer::CameraSystemsManager,
                                                                  ServerManagerMiddleLayer::RenderingManager,
                                                                  ServerManagerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class ServerManagerMessage : public MessageType
    {
    public:
        using ClassType = ServerManagerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        ServerManagerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using ServerManagerMessageWindowProcessHandle = Framework::WindowProcessHandle<ServerManagerMessage>;
}

#endif  // SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H
