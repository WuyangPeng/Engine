///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 19:16)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_IMPL_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
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
        using Transform = Rendering::TransformF;
        using SpatialSharedPtr = Rendering::SpatialSharedPtr;
        using ConstCameraSharedPtr = Rendering::ConstCameraSharedPtr;

    public:
        explicit ObjectMotionImpl(const SpatialSharedPtr& motionObject) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool MoveObject(float rotationSpeed);
        void RotateTrackBall(const ConstCameraSharedPtr& camera);

        void SetDoRoll(int value) noexcept;
        void SetDoYaw(int value) noexcept;
        void SetDoPitch(int value) noexcept;
        void SetTrackBallDow(bool value) noexcept;
        void SetBeginTrack(float xTrack, float yTrack) noexcept;
        void SetEndTrack(float xTrack, float yTrack) noexcept;
        void SetSaveRotate() noexcept(g_Assert < 2 || g_RenderingAssert < 2);
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
