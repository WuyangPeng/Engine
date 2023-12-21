/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/19 23:52)

#ifndef MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_MIDDLE_LAYER_MESSAGE_H
#define MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_MIDDLE_LAYER_MESSAGE_H

#include "MillenniumHistory.h"
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

namespace MillenniumHistory
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

    class MillenniumHistoryMiddleLayerMessage final : public MessageType
    {
    public:
        using ClassType = MillenniumHistoryMiddleLayerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        MillenniumHistoryMiddleLayerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using MillenniumHistoryProcess = Framework::WindowProcessHandle<MillenniumHistoryMiddleLayerMessage>;
}

#endif  // MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_MIDDLE_LAYER_MESSAGE_H
