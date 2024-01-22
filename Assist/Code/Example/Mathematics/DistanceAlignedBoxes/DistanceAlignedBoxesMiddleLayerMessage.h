/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 16:31)

#ifndef DISTANCE_ALIGNED_BOXES_DISTANCE_ALIGNED_BOXES_MIDDLE_LAYER_MESSAGE_H
#define DISTANCE_ALIGNED_BOXES_DISTANCE_ALIGNED_BOXES_MIDDLE_LAYER_MESSAGE_H

#include "DistanceAlignedBoxes.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ArtificialIntelligenceInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainer.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManager.h"
#include "Framework/WindowProcess/WindowMessage.h"
#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Example/Mathematics/DistanceAlignedBoxesCore/Input/InputManagerDetail.h"
#include "Example/Mathematics/DistanceAlignedBoxesCore/Rendering/RenderingManager.h"
#include "Example/Mathematics/DistanceAlignedBoxesCore/Resource/ResourceManager.h"

namespace DistanceAlignedBoxes
{
    using ObjectLogicManager = Framework::ObjectLogicManager<Framework::ObjectLogicInterface, Framework::ArtificialIntelligenceInterface>;
    using MiddleLayerType = Framework::EngineMiddleLayerContainer<Framework::WindowApplicationTrait,
                                                                  InputManager,
                                                                  Framework::NetworkManagerInterface,
                                                                  ObjectLogicManager,
                                                                  Framework::PhysicalModellingManagerInterface,
                                                                  Framework::MessageManagerInterface,
                                                                  Framework::EventManagerInterface,
                                                                  Framework::SystemManagerInterface,
                                                                  ResourceManager,
                                                                  Framework::AudioManagerInterface,
                                                                  Framework::CameraSystemsManagerInterface,
                                                                  RenderingManager,
                                                                  Framework::GUIManagerInterface>;
    using MessageType = Framework::WindowMessage<MiddleLayerType>;

    class DistanceAlignedBoxesMiddleLayerMessage final : public MessageType
    {
    public:
        using ClassType = DistanceAlignedBoxesMiddleLayerMessage;
        using ParentType = MessageType;

        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        DistanceAlignedBoxesMiddleLayerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        ConsoleAlloc alloc;
    };

    using DistanceAlignedBoxesProcess = Framework::WindowProcessHandle<DistanceAlignedBoxesMiddleLayerMessage>;
}

#endif  // DISTANCE_ALIGNED_BOXES_DISTANCE_ALIGNED_BOXES_MIDDLE_LAYER_MESSAGE_H
