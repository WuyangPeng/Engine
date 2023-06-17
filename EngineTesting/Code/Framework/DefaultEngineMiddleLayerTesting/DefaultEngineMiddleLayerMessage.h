///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 18:10)

#ifndef DEFAULT_ENGINE_MIDDLE_LAYER_TESTING_DEFAULT_ENGINE_MIDDLE_LAYER_MESSAGE_H
#define DEFAULT_ENGINE_MIDDLE_LAYER_TESTING_DEFAULT_ENGINE_MIDDLE_LAYER_MESSAGE_H

#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"

namespace DefaultEngineMiddleLayer
{
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class DefaultEngineMiddleLayerMessage : public MessageType
    {
    public:
        using ClassType = DefaultEngineMiddleLayerMessage;
        using ParentType = MessageType;

    public:
        DefaultEngineMiddleLayerMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc alloc;
    };

    using DefaultEngineMiddleLayerTesting = Framework::WindowProcessHandle<DefaultEngineMiddleLayerMessage>;
}

#endif  // DEFAULT_ENGINE_MIDDLE_LAYER_TESTING_DEFAULT_ENGINE_MIDDLE_LAYER_MESSAGE_H
