/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:58)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H

#include "CameraModelMiddleLayer.h"
#include "CameraViewMiddleLayer.h"
#include "ControllerMiddleLayer.h"

#include <map>

namespace Framework
{
    template <typename ApplicationTrait>
    class CameraControllerMiddleLayer : public ControllerMiddleLayer<ApplicationTrait>
    {
    public:
        using ClassType = CameraControllerMiddleLayer<ApplicationTrait>;
        using ParentType = ControllerMiddleLayer<ApplicationTrait>;

    public:
        CameraControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) override;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) override;
        NODISCARD bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
        NODISCARD bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;

    private:
        NODISCARD CameraModelMiddleLayerSharedPtr GetCameraModelMiddleLayer();
        NODISCARD CameraViewMiddleLayerSharedPtr GetCameraViewMiddleLayer();

        void SpecialKey(int key, bool pressed);
        void CameraSpecialKey(int key, bool pressed);
        void ObjectSpecialKey(int key, bool pressed);

    private:
        using KeyIdentifiers = typename ApplicationTrait::KeyIdentifiers;
        using ChangeCameraSpeedFunction = void (CameraModelMiddleLayer::*)();
        using ChangeCameraSpeedProcess = std::map<int, ChangeCameraSpeedFunction>;
        using ChangeCameraMotionFunction = void (CameraModelMiddleLayer::*)(Mathematics::NumericalValueSymbol);
        using ChangeCameraMotionProcess = std::map<int, std::pair<ChangeCameraMotionFunction, Mathematics::NumericalValueSymbol>>;
        using ChangeObjectMotionFunction = void (CameraModelMiddleLayer::*)(bool);
        using ChangeObjectMotionProcess = std::map<int, ChangeObjectMotionFunction>;

    private:
        ChangeCameraSpeedProcess changeCameraSpeed;
        ChangeCameraMotionProcess changeCameraMotion;
        ChangeObjectMotionProcess changeObjectMotion;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_H
