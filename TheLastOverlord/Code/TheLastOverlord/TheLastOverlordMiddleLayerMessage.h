/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:42)

#ifndef THE_LAST_OVERLORD_THE_LAST_OVERLORD_MIDDLE_LAYER_MESSAGE_H
#define THE_LAST_OVERLORD_THE_LAST_OVERLORD_MIDDLE_LAYER_MESSAGE_H

#include "TheLastOverlord.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ArtificialIntelligenceInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/Project/GUIProjectManager.h"
#include "Framework/Project/InputProjectManagerDetail.h"
#include "Framework/Project/ResourceProjectManager.h"
#include "Framework/Project/SystemProjectManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace TheLastOverlord
{
    using ObjectLogicManager = Framework::ObjectLogicManager<Framework::ObjectLogicInterface, Framework::ArtificialIntelligenceInterface>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  Framework::InputProjectManager,
                                                                  Framework::NetworkManagerInterface,
                                                                  ObjectLogicManager,
                                                                  Framework::PhysicalModellingManagerInterface,
                                                                  Framework::MessageManagerInterface,
                                                                  Framework::EventManagerInterface,
                                                                  Framework::SystemProjectManager,
                                                                  Framework::ResourceProjectManager,
                                                                  Framework::AudioManagerInterface,
                                                                  Framework::CameraSystemsManagerInterface,
                                                                  Framework::RenderingManagerInterface,
                                                                  Framework::GUIProjectManager>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class TheLastOverlordMiddleLayerMessage final : public MessageType
    {
    public:
        using ClassType = TheLastOverlordMiddleLayerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        TheLastOverlordMiddleLayerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using TheLastOverlordProcess = Framework::WindowProcessHandle<TheLastOverlordMiddleLayerMessage>;
}

#endif  // THE_LAST_OVERLORD_THE_LAST_OVERLORD_MIDDLE_LAYER_MESSAGE_H
