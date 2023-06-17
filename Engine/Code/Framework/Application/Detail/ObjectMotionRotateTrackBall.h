///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:43)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_ROTATE_TRACK_BALL_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_ROTATE_TRACK_BALL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ObjectMotionRotateTrackBall
    {
    public:
        using ClassType = ObjectMotionRotateTrackBall;
        using Matrix = Mathematics::MatrixF;
        using AVector = Mathematics::AVectorF;
        using Transform = Rendering::TransformF;
        using SpatialSharedPtr = Rendering::SpatialSharedPtr;
        using ConstCameraSharedPtr = Rendering::ConstCameraSharedPtr;

    public:
        explicit ObjectMotionRotateTrackBall(const SpatialSharedPtr& motionObject,
                                             const ConstCameraSharedPtr& camera,
                                             float beginXTrack,
                                             float beginYTrack,
                                             float endXTrack,
                                             float endYTrack,
                                             const Matrix& saveRotate);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Transform GetTransform() const noexcept;

    private:
        void Calculate();

    private:
        SpatialSharedPtr motionObject;
        ConstCameraSharedPtr camera;
        float beginXTrack;
        float beginYTrack;
        float endXTrack;
        float endYTrack;
        Matrix saveRotate;
        Matrix localRotate;
    };
}

#endif  // FRAMEWORK_APPLICATION_OBJECT_MOTION_ROTATE_TRACK_BALL_H
