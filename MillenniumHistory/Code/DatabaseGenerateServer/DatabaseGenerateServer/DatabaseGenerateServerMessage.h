///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/12 22:28)

#ifndef DATABASE_GENERATE_SERVER_DATABASE_GENERATE_SERVER_MESSAGE_H
#define DATABASE_GENERATE_SERVER_DATABASE_GENERATE_SERVER_MESSAGE_H

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Audio/AudioManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Event/EventManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/GUI/GUIManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Input/InputManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Message/MessageManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Network/NetworkManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Rendering/RenderingManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Resource/ResourceManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace DatabaseGenerateServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<DatabaseGenerateServerMiddleLayer::ObjectLogicManager, DatabaseGenerateServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  DatabaseGenerateServerMiddleLayer::InputManager,
                                                                  DatabaseGenerateServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  DatabaseGenerateServerMiddleLayer::PhysicalModellingManager,
                                                                  DatabaseGenerateServerMiddleLayer::MessageManager,
                                                                  DatabaseGenerateServerMiddleLayer::EventManager,
                                                                  DatabaseGenerateServerMiddleLayer::SystemManager,
                                                                  DatabaseGenerateServerMiddleLayer::ResourceManager,
                                                                  DatabaseGenerateServerMiddleLayer::AudioManager,
                                                                  DatabaseGenerateServerMiddleLayer::CameraSystemsManager,
                                                                  DatabaseGenerateServerMiddleLayer::RenderingManager,
                                                                  DatabaseGenerateServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class DatabaseGenerateServerMessage : public MessageType
    {
    public:
        using ClassType = DatabaseGenerateServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        DatabaseGenerateServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using DatabaseGenerateServerMessageWindowProcessHandle = Framework::WindowProcessHandle<DatabaseGenerateServerMessage>;
}

#endif  // DATABASE_GENERATE_SERVER_DATABASE_GENERATE_SERVER_MESSAGE_H
