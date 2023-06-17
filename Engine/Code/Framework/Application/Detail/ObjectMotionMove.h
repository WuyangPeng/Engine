///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:42)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_MOVE_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_MOVE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ObjectMotionMove
    {
    public:
        using ClassType = ObjectMotionMove;
        using Matrix = Mathematics::MatrixF;
        using AVector = Mathematics::AVectorF;
        using Spatial = Rendering::Spatial;
        using Transform = Rendering::TransformF;
        using SpatialSharedPtr = Rendering::SpatialSharedPtr;

    public:
        explicit ObjectMotionMove(const SpatialSharedPtr& motionObject, int doRoll, int doYaw, int doPitch, float rotationSpeed);

        CLASS_INVARIANT_DECLARE;

        NODISCARD AVector GetAxis() const noexcept;
        float GetAngle() const noexcept;
        NODISCARD Matrix GetRotate() const noexcept;
        NODISCARD Transform GetIncrement() const;

    private:
        void Calculate();

    private:
        SpatialSharedPtr motionObject;
        int doRoll;
        int doYaw;
        int doPitch;
        float rotationSpeed;
        AVector axis;
        float angle;
        Matrix rotate;
    };
}

#endif  // FRAMEWORK_APPLICATION_OBJECT_MOTION_MOVE_H
