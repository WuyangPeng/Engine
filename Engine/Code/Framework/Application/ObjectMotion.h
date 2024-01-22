/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:24)

#ifndef FRAMEWORK_APPLICATION_OBJECT_MOTION_H
#define FRAMEWORK_APPLICATION_OBJECT_MOTION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Spatial.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(ObjectMotionImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE ObjectMotion
    {
    public:
        NON_COPY_TYPE_DECLARE(ObjectMotion);

        using Matrix = Mathematics::MatrixF;
        using AVector = Mathematics::AVectorF;
        using Transform = Mathematics::TransformF;
        using SpatialSharedPtr = Rendering::SpatialSharedPtr;
        using ConstCameraSharedPtr = Rendering::ConstCameraSharedPtr;

    public:
        explicit ObjectMotion(const SpatialSharedPtr& motionObject);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool MoveObject(float rotationSpeed);
        void RotateTrackBall(const ConstCameraSharedPtr& camera);

        void SetDoRoll(int doRoll) noexcept;
        void SetDoYaw(int doYaw) noexcept;
        void SetDoPitch(int doPitch) noexcept;
        void SetTrackBallDow(bool trackBallDow) noexcept;
        NODISCARD bool GetTrackBallDow() const noexcept;

        void SetBeginTrack(float xTrack, float yTrack) noexcept;
        void SetEndTrack(float xTrack, float yTrack) noexcept;
        void SetSaveRotate();

        NODISCARD Transform GetMotionObjectLocalTransform() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_OBJECT_MOTION_H
