///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 23:19)

#ifndef SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H
#define SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H

#include "ServerManager/ServerManagerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
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
    using ObjectLogicManager = Framework::ObjectLogicManager<ServerManagerMiddleLayer::ObjectLogicManager, ServerManagerMiddleLayer::ArtificialIntellegenceManager>;
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

    public:
        explicit ServerManagerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using ServerManagerMessageWindowProcessHandle = Framework::WindowProcessHandle<ServerManagerMessage>;
}

#endif  // SERVER_MANAGER_SERVER_MANAGER_MESSAGE_H
