///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/19 16:54)

#ifndef THE_LAST_OVERLORD_THE_LAST_OVERLORD_MIDDLE_LAYER_MESSAGE_H
#define THE_LAST_OVERLORD_THE_LAST_OVERLORD_MIDDLE_LAYER_MESSAGE_H

#include "TheLastOverlord.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace TheLastOverlord
{
    using ObjectLogicManager = Framework::ObjectLogicManager<Framework::ObjectLogicInterface, Framework::ArtificialIntellegenceInterface>;
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

    class TheLastOverlordMiddleLayerMessage final : public MessageType
    {
    public:
        using ClassType = TheLastOverlordMiddleLayerMessage;
        using ParentType = MessageType;
        using ConsoleAlloc = CoreTools::ConsoleAlloc;

    public:
        explicit TheLastOverlordMiddleLayerMessage(int64_t delta);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using TheLastOverlordProcess = Framework::WindowProcessHandle<TheLastOverlordMiddleLayerMessage>;
}

#endif  // THE_LAST_OVERLORD_THE_LAST_OVERLORD_MIDDLE_LAYER_MESSAGE_H
