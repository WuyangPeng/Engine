///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 13:45)

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

    class DefaultEngineMiddleLayerMessage final : public MessageType
    {
    public:
        using ClassType = DefaultEngineMiddleLayerMessage;
        using ParentType = MessageType;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        DefaultEngineMiddleLayerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ConsoleAlloc = CoreTools::ConsoleAlloc;

    private:
        ConsoleAlloc alloc;
    };

    using DefaultEngineMiddleLayerTesting = Framework::WindowProcessHandle<DefaultEngineMiddleLayerMessage>;
}

#endif  // DEFAULT_ENGINE_MIDDLE_LAYER_TESTING_DEFAULT_ENGINE_MIDDLE_LAYER_MESSAGE_H
