///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 16:14)

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
        explicit CameraControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool KeyDown(int key, const WindowPoint& point) override;
        NODISCARD bool SpecialKeyDown(int key, const WindowPoint& point) override;
        NODISCARD bool SpecialKeyUp(int key, const WindowPoint& point) override;
        bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;
        bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) override;

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
