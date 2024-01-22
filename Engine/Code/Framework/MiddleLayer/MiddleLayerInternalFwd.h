/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:00)

#ifndef FRAMEWORK_MIDDLE_LAYER_INTERNAL_FWD_H
#define FRAMEWORK_MIDDLE_LAYER_INTERNAL_FWD_H

#include "MiddleLayerFwd.h"

#include <memory>

namespace Framework
{
    using MiddleLayerInterfaceSharedPtr = std::shared_ptr<MiddleLayerInterface>;
    using ConstMiddleLayerInterfaceSharedPtr = std::shared_ptr<const MiddleLayerInterface>;

    using MiddleLayerInterfaceUniquePtr = std::unique_ptr<MiddleLayerInterface>;
    using ConstMiddleLayerInterfaceUniquePtr = std::unique_ptr<const MiddleLayerInterface>;

    using ModelViewControllerMiddleLayerSharedPtr = std::shared_ptr<ModelViewControllerMiddleLayer>;
    using ConstModelViewControllerMiddleLayerSharedPtr = std::shared_ptr<const ModelViewControllerMiddleLayer>;

    using ModelMiddleLayerSharedPtr = std::shared_ptr<ModelMiddleLayer>;
    using ConstModelMiddleLayerSharedPtr = std::shared_ptr<const ModelMiddleLayer>;

    using ViewMiddleLayerSharedPtr = std::shared_ptr<ViewMiddleLayer>;
    using ConstViewMiddleLayerSharedPtr = std::shared_ptr<const ViewMiddleLayer>;

    using PixelViewMiddleLayerSharedPtr = std::shared_ptr<PixelViewMiddleLayer>;
    using ConstPixelViewMiddleLayerSharedPtr = std::shared_ptr<const PixelViewMiddleLayer>;

    using CameraModelMiddleLayerSharedPtr = std::shared_ptr<CameraModelMiddleLayer>;
    using ConstCameraModelMiddleLayerSharedPtr = std::shared_ptr<const CameraModelMiddleLayer>;

    using CameraViewMiddleLayerSharedPtr = std::shared_ptr<CameraViewMiddleLayer>;
    using ConstCameraViewMiddleLayerSharedPtr = std::shared_ptr<const CameraViewMiddleLayer>;

    using EngineMiddleLayerInterfaceSharedPtr = std::shared_ptr<EngineMiddleLayerInterface>;
    using ConstEngineMiddleLayerInterfaceSharedPtr = std::shared_ptr<const EngineMiddleLayerInterface>;

    using NetworkManagerInterfaceSharedPtr = std::shared_ptr<NetworkManagerInterface>;
    using ConstNetworkManagerInterfaceSharedPtr = std::shared_ptr<const NetworkManagerInterface>;

    using ObjectLogicManagerInterfaceSharedPtr = std::shared_ptr<ObjectLogicManagerInterface>;
    using ConstObjectLogicManagerInterfaceSharedPtr = std::shared_ptr<const ObjectLogicManagerInterface>;

    using ObjectLogicInterfaceSharedPtr = std::shared_ptr<ObjectLogicInterface>;
    using ConstObjectLogicInterfaceSharedPtr = std::shared_ptr<const ObjectLogicInterface>;

    using ArtificialIntelligenceInterfaceSharedPtr = std::shared_ptr<ArtificialIntelligenceInterface>;
    using ConstArtificialIntelligenceInterfaceSharedPtr = std::shared_ptr<const ArtificialIntelligenceInterface>;

    using InputManagerInterfaceSharedPtr = std::shared_ptr<InputManagerInterface>;
    using ConstInputManagerInterfaceSharedPtr = std::shared_ptr<const InputManagerInterface>;

    using PhysicalModellingManagerInterfaceSharedPtr = std::shared_ptr<PhysicalModellingManagerInterface>;
    using ConstPhysicalModellingManagerInterfaceSharedPtr = std::shared_ptr<const PhysicalModellingManagerInterface>;

    using MessageManagerInterfaceSharedPtr = std::shared_ptr<MessageManagerInterface>;
    using ConstMessageManagerInterfaceSharedPtr = std::shared_ptr<const MessageManagerInterface>;

    using EventManagerInterfaceSharedPtr = std::shared_ptr<EventManagerInterface>;
    using ConstEventManagerInterfaceSharedPtr = std::shared_ptr<const EventManagerInterface>;

    using SystemManagerInterfaceSharedPtr = std::shared_ptr<SystemManagerInterface>;
    using ConstSystemManagerInterfaceSharedPtr = std::shared_ptr<const SystemManagerInterface>;

    using ResourceManagerInterfaceSharedPtr = std::shared_ptr<ResourceManagerInterface>;
    using ConstResourceManagerInterfaceSharedPtr = std::shared_ptr<const ResourceManagerInterface>;

    using AudioManagerInterfaceSharedPtr = std::shared_ptr<AudioManagerInterface>;
    using ConstAudioManagerInterfaceSharedPtr = std::shared_ptr<const AudioManagerInterface>;

    using CameraSystemsManagerInterfaceSharedPtr = std::shared_ptr<CameraSystemsManagerInterface>;
    using ConstCameraSystemsManagerInterfaceSharedPtr = std::shared_ptr<const CameraSystemsManagerInterface>;

    using RenderingManagerInterfaceSharedPtr = std::shared_ptr<RenderingManagerInterface>;
    using ConstRenderingManagerInterfaceSharedPtr = std::shared_ptr<const RenderingManagerInterface>;

    using GUIManagerInterfaceSharedPtr = std::shared_ptr<GUIManagerInterface>;
    using ConstGUIManagerInterfaceSharedPtr = std::shared_ptr<const GUIManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_FWD_H