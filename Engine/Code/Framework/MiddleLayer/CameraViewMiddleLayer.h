/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:59)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ViewMiddleLayer.h"
#include "Rendering/SceneGraph/Camera.h"

// 视图层类的声明
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE CameraViewMiddleLayer : public ViewMiddleLayer
    {
    public:
        using ClassType = CameraViewMiddleLayer;
        using ParentType = ViewMiddleLayer;

    public:
        CameraViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

        NODISCARD WindowSize GetWindowSize() const;

        NODISCARD float GetXTrack(int x) const;
        NODISCARD float GetYTrack(int y) const;

    private:
        float multiplier;
    };

    using CameraViewMiddleLayerSharedPtr = std::shared_ptr<CameraViewMiddleLayer>;
    using ConstCameraViewMiddleLayerSharedPtr = std::shared_ptr<const CameraViewMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H
