///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/27 14:57)

#ifndef MAIL_SERVER_MAIL_SERVER_MESSAGE_H
#define MAIL_SERVER_MAIL_SERVER_MESSAGE_H

#include "MailServer/MailServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
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
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace MailServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<MailServerMiddleLayer::ObjectLogicManager, MailServerMiddleLayer::ArtificialIntellegenceManager>;
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

    class MailServerMessage : public MessageType
    {
    public:
        using ClassType = MailServerMessage;
        using ParentType = MessageType;

    public:
        explicit MailServerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using MailServerMessageWindowProcessHandle = Framework::WindowProcessHandle<MailServerMessage>;
}

#endif  // MAIL_SERVER_MAIL_SERVER_MESSAGE_H
