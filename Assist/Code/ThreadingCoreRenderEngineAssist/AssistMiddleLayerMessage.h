///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 13:55)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_MIDDLE_LAYER_MESSAGE_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_MIDDLE_LAYER_MESSAGE_H

#include "Assist.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ArtificialIntelligenceInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace ThreadingCoreRenderEngineAssist
{
    using ObjectLogicManager = Framework::ObjectLogicManager<Framework::ObjectLogicInterface, Framework::ArtificialIntelligenceInterface>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  InputMiddleLayer,
                                                                  Framework::NetworkManagerInterface,
                                                                  ObjectLogicManager,
                                                                  Framework::PhysicalModellingManagerInterface,
                                                                  Framework::MessageManagerInterface,
                                                                  Framework::EventManagerInterface,
                                                                  SystemMiddleLayer,
                                                                  ResourceMiddleLayer,
                                                                  Framework::AudioManagerInterface,
                                                                  Framework::CameraSystemsManagerInterface,
                                                                  Framework::RenderingManagerInterface,
                                                                  GUIMiddleLayer>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class AssistMiddleLayerMessage final : public MessageType
    {
    public:
        using ClassType = AssistMiddleLayerMessage;
        using ParentType = MessageType;
        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        explicit AssistMiddleLayerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using AssistProcess = Framework::WindowProcessHandle<AssistMiddleLayerMessage>;
}

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_ASSIST_MIDDLE_LAYER_MESSAGE_H
