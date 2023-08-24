/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#ifndef LOG_SERVER_LOG_SERVER_MESSAGE_H
#define LOG_SERVER_LOG_SERVER_MESSAGE_H

#include "LogServer/LogServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "LogServer/LogServerMiddleLayer/Audio/AudioManager.h"
#include "LogServer/LogServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "LogServer/LogServerMiddleLayer/Event/EventManager.h"
#include "LogServer/LogServerMiddleLayer/GUI/GUIManager.h"
#include "LogServer/LogServerMiddleLayer/Input/InputManager.h"
#include "LogServer/LogServerMiddleLayer/Message/MessageManager.h"
#include "LogServer/LogServerMiddleLayer/Network/NetworkManager.h"
#include "LogServer/LogServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "LogServer/LogServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "LogServer/LogServerMiddleLayer/Rendering/RenderingManager.h"
#include "LogServer/LogServerMiddleLayer/Resource/ResourceManager.h"
#include "LogServer/LogServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace LogServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<LogServerMiddleLayer::ObjectLogicManager, LogServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  LogServerMiddleLayer::InputManager,
                                                                  LogServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  LogServerMiddleLayer::PhysicalModellingManager,
                                                                  LogServerMiddleLayer::MessageManager,
                                                                  LogServerMiddleLayer::EventManager,
                                                                  LogServerMiddleLayer::SystemManager,
                                                                  LogServerMiddleLayer::ResourceManager,
                                                                  LogServerMiddleLayer::AudioManager,
                                                                  LogServerMiddleLayer::CameraSystemsManager,
                                                                  LogServerMiddleLayer::RenderingManager,
                                                                  LogServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class LogServerMessage : public MessageType
    {
    public:
        using ClassType = LogServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        LogServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using LogServerMessageWindowProcessHandle = Framework::WindowProcessHandle<LogServerMessage>;
}

#endif  // LOG_SERVER_LOG_SERVER_MESSAGE_H
