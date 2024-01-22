/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:21)

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
