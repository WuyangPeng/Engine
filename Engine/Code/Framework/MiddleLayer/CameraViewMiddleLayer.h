///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 16:21)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ViewMiddleLayer.h"
#include "Rendering/SceneGraph/Camera.h"

namespace Framework
{
    // 视图层类的声明
    class FRAMEWORK_DEFAULT_DECLARE CameraViewMiddleLayer : public ViewMiddleLayer
    {
    public:
        using ClassType = CameraViewMiddleLayer;
        using ParentType = ViewMiddleLayer;
        using CameraSmartPointer = Rendering::CameraSharedPtr;

    public:
        explicit CameraViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

        void SetCamera(const CameraSmartPointer& camera) noexcept;
        NODISCARD WindowSize GetWindowSize() const;

        NODISCARD float GetXTrack(int x) const noexcept;
        NODISCARD float GetYTrack(int y) const noexcept;

    private:
        float multiplier;
    };

    using CameraViewMiddleLayerSharedPtr = std::shared_ptr<CameraViewMiddleLayer>;
    using ConstCameraViewMiddleLayerSharedPtr = std::shared_ptr<const CameraViewMiddleLayer>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H
