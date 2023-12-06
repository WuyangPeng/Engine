/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef MAIL_SERVER_MAIL_SERVER_MESSAGE_H
#define MAIL_SERVER_MAIL_SERVER_MESSAGE_H

#include "MailServer/MailServerMiddleLayer/ArtificialIntelligence/ArtificialIntelligenceManager.h"
#include "MailServer/MailServerMiddleLayer/Audio/AudioManager.h"
#include "MailServer/MailServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "MailServer/MailServerMiddleLayer/Event/EventManager.h"
#include "MailServer/MailServerMiddleLayer/GUI/GUIManager.h"
#include "MailServer/MailServerMiddleLayer/Input/InputManager.h"
#include "MailServer/MailServerMiddleLayer/Message/MessageManager.h"
#include "MailServer/MailServerMiddleLayer/Network/NetworkManager.h"
#include "MailServer/MailServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "MailServer/MailServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "MailServer/MailServerMiddleLayer/Rendering/RenderingManager.h"
#include "MailServer/MailServerMiddleLayer/Resource/ResourceManager.h"
#include "MailServer/MailServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace MailServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<MailServerMiddleLayer::ObjectLogicManager, MailServerMiddleLayer::ArtificialIntelligenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  MailServerMiddleLayer::InputManager,
                                                                  MailServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  MailServerMiddleLayer::PhysicalModellingManager,
                                                                  MailServerMiddleLayer::MessageManager,
                                                                  MailServerMiddleLayer::EventManager,
                                                                  MailServerMiddleLayer::SystemManager,
                                                                  MailServerMiddleLayer::ResourceManager,
                                                                  MailServerMiddleLayer::AudioManager,
                                                                  MailServerMiddleLayer::CameraSystemsManager,
                                                                  MailServerMiddleLayer::RenderingManager,
                                                                  MailServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class MailServerMessage final : public MessageType
    {
    public:
        using ClassType = MailServerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        MailServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using MailServerMessageWindowProcessHandle = Framework::WindowProcessHandle<MailServerMessage>;
}

#endif  // MAIL_SERVER_MAIL_SERVER_MESSAGE_H
