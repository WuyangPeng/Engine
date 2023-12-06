///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 14:59)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_IMPL_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ObjectMotionImpl
    {
    public:
        using ClassType = ObjectMotionImpl;

        using Matrix = Mathematics::MatrixF;
        using AVector = Mathematics::AVectorF;
        using Transform = Mathematics::TransformF;
        using SpatialSharedPtr = Rendering::SpatialSharedPtr;
        using ConstCameraSharedPtr = Rendering::ConstCameraSharedPtr;

    public:
        explicit ObjectMotionImpl(SpatialSharedPtr motionObject) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool MoveObject(float rotationSpeed);
        void RotateTrackBall(const ConstCameraSharedPtr& camera);

        void SetDoRoll(int aDoRoll) noexcept;
        void SetDoYaw(int aDoYaw) noexcept;
        void SetDoPitch(int aDoPitch) noexcept;
        void SetTrackBallDow(bool aTrackBallDow) noexcept;
        void SetBeginTrack(float xTrack, float yTrack) noexcept;
        void SetEndTrack(float xTrack, float yTrack) noexcept;
        void SetSaveRotate();
        NODISCARD bool GetTrackBallDow() const noexcept;

        NODISCARD Transform GetMotionObjectLocalTransform() const noexcept;

    private:
        SpatialSharedPtr motionObject;
        int doRoll;
        int doYaw;
        int doPitch;
        float beginXTrack;
        float beginYTrack;
        float endXTrack;
        float endYTrack;
        Matrix saveRotate;
        bool useTrackBall;
        bool trackBallDown;
    };
}

#endif  // FRAMEWORK_APPLICATION_CAMERA_MOTION_IMPL_H
