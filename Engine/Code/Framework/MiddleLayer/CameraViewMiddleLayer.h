/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:59)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ViewMiddleLayer.h"
#include "Rendering/SceneGraph/Camera.h"

// ��ͼ���������
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
