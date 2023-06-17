///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/25 18:52)

#ifndef WORLD_SERVER_WORLD_SERVER_MESSAGE_H
#define WORLD_SERVER_WORLD_SERVER_MESSAGE_H

#include "WorldServer/WorldServerMiddleLayer/ArtificialIntellegence/ArtificialIntellegenceManager.h"
#include "WorldServer/WorldServerMiddleLayer/Audio/AudioManager.h"
#include "WorldServer/WorldServerMiddleLayer/CameraSystems/CameraSystemsManager.h"
#include "WorldServer/WorldServerMiddleLayer/Event/EventManager.h"
#include "WorldServer/WorldServerMiddleLayer/GUI/GUIManager.h"
#include "WorldServer/WorldServerMiddleLayer/Input/InputManager.h"
#include "WorldServer/WorldServerMiddleLayer/Message/MessageManager.h"
#include "WorldServer/WorldServerMiddleLayer/Network/NetworkManager.h"
#include "WorldServer/WorldServerMiddleLayer/ObjectLogic/ObjectLogicManager.h"
#include "WorldServer/WorldServerMiddleLayer/PhysicalModelling/PhysicalModellingManager.h"
#include "WorldServer/WorldServerMiddleLayer/Rendering/RenderingManager.h"
#include "WorldServer/WorldServerMiddleLayer/Resource/ResourceManager.h"
#include "WorldServer/WorldServerMiddleLayer/System/SystemManager.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace WorldServer
{
    using ObjectLogicManager = Framework::ObjectLogicManager<WorldServerMiddleLayer::ObjectLogicManager, WorldServerMiddleLayer::ArtificialIntellegenceManager>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  WorldServerMiddleLayer::InputManager,
                                                                  WorldServerMiddleLayer::NetworkManager,
                                                                  ObjectLogicManager,
                                                                  WorldServerMiddleLayer::PhysicalModellingManager,
                                                                  WorldServerMiddleLayer::MessageManager,
                                                                  WorldServerMiddleLayer::EventManager,
                                                                  WorldServerMiddleLayer::SystemManager,
                                                                  WorldServerMiddleLayer::ResourceManager,
                                                                  WorldServerMiddleLayer::AudioManager,
                                                                  WorldServerMiddleLayer::CameraSystemsManager,
                                                                  WorldServerMiddleLayer::RenderingManager,
                                                                  WorldServerMiddleLayer::GUIManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class WorldServerMessage : public MessageType
    {
    public:
        using ClassType = WorldServerMessage;
        using ParentType = MessageType;

    public:
        explicit WorldServerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using WorldServerMessageWindowProcessHandle = Framework::WindowProcessHandle<WorldServerMessage>;
}

#endif  // WORLD_SERVER_WORLD_SERVER_MESSAGE_H
