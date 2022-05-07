// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 19:21)

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
        explicit DefaultEngineMiddleLayerMessage(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CoreTools::ConsoleAlloc m_Alloc;
    };

    using DefaultEngineMiddleLayerTesting = Framework::WindowProcessHandle<DefaultEngineMiddleLayerMessage>;
}

#endif  // DEFAULT_ENGINE_MIDDLE_LAYER_TESTING_DEFAULT_ENGINE_MIDDLE_LAYER_MESSAGE_H
