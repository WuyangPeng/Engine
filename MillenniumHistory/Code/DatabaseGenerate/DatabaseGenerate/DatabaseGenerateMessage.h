/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef DATABASE_GENERATE_DATABASE_GENERATE_MESSAGE_H
#define DATABASE_GENERATE_DATABASE_GENERATE_MESSAGE_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Audio/AudioManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Event/EventManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/GUI/GUIManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Input/InputManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Message/MessageManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Network/NetworkManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Rendering/RenderingManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Resource/ResourceManager.h"
#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace DatabaseGenerate
{
    using ObjectLogicManager = Framework::ObjectLogicManager<DatabaseGenerateMiddleLayer::ObjectLogicManager, DatabaseGenerateMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  DatabaseGenerateMiddleLayer::InputManager,
                                                                  DatabaseGenerateMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  DatabaseGenerateMiddleLayer::PhysicalModellingManager,
                                                                  DatabaseGenerateMiddleLayer::MessageManager,
                                                                  DatabaseGenerateMiddleLayer::EventManager,
                                                                  DatabaseGenerateMiddleLayer::SystemManager,
                                                                  DatabaseGenerateMiddleLayer::ResourceManager,
                                                                  DatabaseGenerateMiddleLayer::AudioManager,
                                                                  DatabaseGenerateMiddleLayer::CameraSystemsManager,
                                                                  DatabaseGenerateMiddleLayer::RenderingManager,
                                                                  DatabaseGenerateMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class DatabaseGenerateMessage final : public MessageType
    {
    public:
        using ClassType = DatabaseGenerateMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        DatabaseGenerateMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using DatabaseGenerateMessageWindowProcessHandle = Framework::WindowProcessHandle<DatabaseGenerateMessage>;
}

#endif  // DATABASE_GENERATE_DATABASE_GENERATE_MESSAGE_H
