/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:26)

#ifndef DATABASE_SERVER_DATABASE_SERVER_MESSAGE_H
#define DATABASE_SERVER_DATABASE_SERVER_MESSAGE_H

#include "DatabaseServer/DatabaseServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
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
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace DatabaseServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<DatabaseServerMiddleLayer::ObjectLogicManager, DatabaseServerMiddleLayer::ArtificialIntelligenceManager>;
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

    class DatabaseServerMessage final : public MessageType
    {
    public:
        using ClassType = DatabaseServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        DatabaseServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using DatabaseServerMessageWindowProcessHandle = Framework::WindowProcessHandle<DatabaseServerMessage>;
}

#endif  // DATABASE_SERVER_DATABASE_SERVER_MESSAGE_H
