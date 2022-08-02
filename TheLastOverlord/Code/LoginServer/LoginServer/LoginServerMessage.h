///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/24 0:59)

#ifndef LOGIN_SERVER_LOGIN_SERVER_MESSAGE_H
#define LOGIN_SERVER_LOGIN_SERVER_MESSAGE_H

#include "LoginServer/LoginServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "LoginServer/LoginServerMiddleLayer/Audio/AudioManager.h"
#include "LoginServer/LoginServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "LoginServer/LoginServerMiddleLayer/Event/EventManager.h"
#include "LoginServer/LoginServerMiddleLayer/GUI/GUIManager.h"
#include "LoginServer/LoginServerMiddleLayer/Input/InputManager.h"
#include "LoginServer/LoginServerMiddleLayer/Message/MessageManager.h"
#include "LoginServer/LoginServerMiddleLayer/Network/NetworkManager.h"
#include "LoginServer/LoginServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "LoginServer/LoginServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "LoginServer/LoginServerMiddleLayer/Rendering/RenderingManager.h"
#include "LoginServer/LoginServerMiddleLayer/Resource/ResourceManager.h"
#include "LoginServer/LoginServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace LoginServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<LoginServerMiddleLayer::ObjectLogicManager, LoginServerMiddleLayer::ArtificialIntellegenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  LoginServerMiddleLayer::InputManager,
                                                                  LoginServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  LoginServerMiddleLayer::PhysicalModellingManager,
                                                                  LoginServerMiddleLayer::MessageManager,
                                                                  LoginServerMiddleLayer::EventManager,
                                                                  LoginServerMiddleLayer::SystemManager,
                                                                  LoginServerMiddleLayer::ResourceManager,
                                                                  LoginServerMiddleLayer::AudioManager,
                                                                  LoginServerMiddleLayer::CameraSystemsManager,
                                                                  LoginServerMiddleLayer::RenderingManager,
                                                                  LoginServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class LoginServerMessage : public MessageType
    {
    public:
        using ClassType = LoginServerMessage;
        using ParentType = MessageType;

    public:
        explicit LoginServerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using LoginServerMessageWindowProcessHandle = Framework::WindowProcessHandle<LoginServerMessage>;
}

#endif  // LOGIN_SERVER_LOGIN_SERVER_MESSAGE_H
