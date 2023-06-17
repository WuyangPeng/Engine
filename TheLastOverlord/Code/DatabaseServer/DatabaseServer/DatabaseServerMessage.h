///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/29 21:25)

#ifndef DATABASE_SERVER_DATABASE_SERVER_MESSAGE_H
#define DATABASE_SERVER_DATABASE_SERVER_MESSAGE_H

#include "DatabaseServer/DatabaseServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/Audio/AudioManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/Event/EventManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/GUI/GUIManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/Input/InputManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/Message/MessageManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/Network/NetworkManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/Rendering/RenderingManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/Resource/ResourceManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h" 
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace DatabaseServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<DatabaseServerMiddleLayer::ObjectLogicManager, DatabaseServerMiddleLayer::ArtificialIntellegenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  DatabaseServerMiddleLayer::InputManager,
                                                                  DatabaseServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  DatabaseServerMiddleLayer::PhysicalModellingManager,
                                                                  DatabaseServerMiddleLayer::MessageManager,
                                                                  DatabaseServerMiddleLayer::EventManager,
                                                                  DatabaseServerMiddleLayer::SystemManager,
                                                                  DatabaseServerMiddleLayer::ResourceManager,
                                                                  DatabaseServerMiddleLayer::AudioManager,
                                                                  DatabaseServerMiddleLayer::CameraSystemsManager,
                                                                  DatabaseServerMiddleLayer::RenderingManager,
                                                                  DatabaseServerMiddleLayer::GUIManager>;

    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class DatabaseServerMessage : public MessageType
    {
    public:
        using ClassType = DatabaseServerMessage;
        using ParentType = MessageType;

    public:
        explicit DatabaseServerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using DatabaseServerMessageWindowProcessHandle = Framework::WindowProcessHandle<DatabaseServerMessage>;
}

#endif  // DATABASE_SERVER_DATABASE_SERVER_MESSAGE_H
