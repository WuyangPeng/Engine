///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/08 14:46)

#ifndef FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H

#include "CameraControllerMiddleLayer.h"
#include "ControllerMiddleLayerDetail.h"
#include "MiddleLayerInterface.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename ApplicationTrait>
Framework::CameraControllerMiddleLayer<ApplicationTrait>::CameraControllerMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory },
      changeCameraSpeed{ { KeyIdentifiers::lowerT, &CameraModelMiddleLayer::SlowerCameraTranslation },  // 摄像机平移变慢。
                         { KeyIdentifiers::upperT, &CameraModelMiddleLayer::FasterCameraTranslation },  // 摄像机平移变快。
                         { KeyIdentifiers::lowerR, &CameraModelMiddleLayer::SlowerCameraRotation },  // 摄像机旋转变慢。
                         { KeyIdentifiers::upperR, &CameraModelMiddleLayer::FasterCameraRotation } },  // 摄像机旋转变快。
      changeCameraMotion{ { KeyIdentifiers::keyF1, { &CameraModelMiddleLayer::SetDoRoll, Mathematics::NumericalValueSymbol::Positive } },
                          { KeyIdentifiers::keyF2, { &CameraModelMiddleLayer::SetDoRoll, Mathematics::NumericalValueSymbol::Negative } },
                          { KeyIdentifiers::keyF3, { &CameraModelMiddleLayer::SetDoYaw, Mathematics::NumericalValueSymbol::Positive } },
                          { KeyIdentifiers::keyF4, { &CameraModelMiddleLayer::SetDoYaw, Mathematics::NumericalValueSymbol::Negative } },
                          { KeyIdentifiers::keyF5, { &CameraModelMiddleLayer::SetDoPitch, Mathematics::NumericalValueSymbol::Positive } },
                          { KeyIdentifiers::keyF6, { &CameraModelMiddleLayer::SetDoPitch, Mathematics::NumericalValueSymbol::Negative } } },
      changeObjectMotion{ { KeyIdentifiers::keyLeftArrow, &CameraModelMiddleLayer::SetMoveLeft },
                          { KeyIdentifiers::keyRightArrow, &CameraModelMiddleLayer::SetMoveRight },
                          { KeyIdentifiers::keyUpArrow, &CameraModelMiddleLayer::SetMoveForward },
                          { KeyIdentifiers::keyDownArrow, &CameraModelMiddleLayer::SetMoveBackward },
                          { KeyIdentifiers::keyPageUp, &CameraModelMiddleLayer::SetMoveUp },
                          { KeyIdentifiers::keyPageDown, &CameraModelMiddleLayer::SetMoveDown },
                          { KeyIdentifiers::keyHome, &CameraModelMiddleLayer::SetLookUp },
                          { KeyIdentifiers::keyEnd, &CameraModelMiddleLayer::SetLookDown },
                          { KeyIdentifiers::keyInsert, &CameraModelMiddleLayer::SetTurnLeft },
                          { KeyIdentifiers::keyDelete, &CameraModelMiddleLayer::SetTurnRight } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>::KeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::KeyDown(key, point))
    {
        if (const auto iter = changeCameraSpeed.find(key);
            iter != changeCameraSpeed.cend())
        {
            const auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

            // 标准键对应用程序。
            ((*cameraModelMiddleLayer).*(iter->second))();
        }

        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>::SpecialKeyDown(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::SpecialKeyDown(key, point))
    {
        SpecialKey(key, true);

        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>::SpecialKey(int key, bool pressed)
{
    if (KeyIdentifiers::keyF1 <= key && key <= KeyIdentifiers::keyF12)
    {
        CameraSpecialKey(key, pressed);
    }
    else
    {
        ObjectSpecialKey(key, pressed);
    }
}

template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>::CameraSpecialKey(int key, bool pressed)
{
    if (const auto iter = changeCameraMotion.find(key);
        iter != changeCameraMotion.cend())
    {
        const auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

        ((*cameraModelMiddleLayer).*(iter->second.first))(pressed ? iter->second.second : Mathematics::NumericalValueSymbol::Zero);
    }
}

template <typename ApplicationTrait>
void Framework::CameraControllerMiddleLayer<ApplicationTrait>::ObjectSpecialKey(int key, bool pressed)
{
    if (const auto iter = changeObjectMotion.find(key);
        iter != changeObjectMotion.cend())
    {
        const auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

        ((*cameraModelMiddleLayer).*(iter->second))(pressed);
    }
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>::SpecialKeyUp(int key, const WindowPoint& point)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::SpecialKeyUp(key, point))
    {
        SpecialKey(key, false);

        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::MouseClick(button, state, point, virtualKeys))
    {
        if (button == MouseButtonsTypes::LeftButton)
        {
            const auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();

            if (state == MouseStateTypes::MouseDown)
            {
                const auto cameraViewMiddleLayer = GetCameraViewMiddleLayer();

                cameraModelMiddleLayer->SetBeginTrack(point, *cameraViewMiddleLayer);
            }
            else
            {
                cameraModelMiddleLayer->SetTrackBallDow(false);
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait>
bool Framework::CameraControllerMiddleLayer<ApplicationTrait>::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (ParentType::Motion(point, virtualKeys))
    {
        if (const auto cameraModelMiddleLayer = GetCameraModelMiddleLayer();
            virtualKeys.IsLeftMouseDown() && cameraModelMiddleLayer->GetTrackBallDow())
        {
            const auto cameraViewMiddleLayer = GetCameraViewMiddleLayer();

            cameraModelMiddleLayer->RotateTrackBall(point, *cameraViewMiddleLayer);
        }

        return true;
    }
    else
    {
        return false;
    }
}

template <typename ApplicationTrait>
Framework::CameraModelMiddleLayerSharedPtr Framework::CameraControllerMiddleLayer<ApplicationTrait>::GetCameraModelMiddleLayer()
{
    return boost::polymorphic_pointer_cast<CameraModelMiddleLayer>(this->GetModelMiddleLayer());
}

template <typename ApplicationTrait>
Framework::CameraViewMiddleLayerSharedPtr Framework::CameraControllerMiddleLayer<ApplicationTrait>::GetCameraViewMiddleLayer()
{
    return boost::polymorphic_pointer_cast<CameraViewMiddleLayer>(this->GetViewMiddleLayer());
}

#endif  // FRAMEWORK_MIDDLE_LAYER_CAMERA_CONTROLLER_MIDDLE_LAYER_DETAIL_H