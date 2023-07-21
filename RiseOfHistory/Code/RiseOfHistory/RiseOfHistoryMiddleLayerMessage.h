///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/18 17:41)

#ifndef RISE_OF_HISTORY_RISE_OF_HISTORY_MIDDLE_LAYER_MESSAGE_H
#define RISE_OF_HISTORY_RISE_OF_HISTORY_MIDDLE_LAYER_MESSAGE_H

#include "RiseOfHistory.h"
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

namespace RiseOfHistory
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

    class RiseOfHistoryMiddleLayerMessage final : public MessageType
    {
    public:
        using ClassType = RiseOfHistoryMiddleLayerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        RiseOfHistoryMiddleLayerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using RiseOfHistoryProcess = Framework::WindowProcessHandle<RiseOfHistoryMiddleLayerMessage>;
}

#endif  // RISE_OF_HISTORY_RISE_OF_HISTORY_MIDDLE_LAYER_MESSAGE_H
