///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 10:28)

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
        using Transform = Rendering::TransformF;
        using SpatialSharedPtr = Rendering::SpatialSharedPtr;
        using ConstCameraSharedPtr = Rendering::ConstCameraSharedPtr;

    public:
        explicit ObjectMotion(const SpatialSharedPtr& motionObject);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool MoveObject(float rotationSpeed);
        void RotateTrackBall(const ConstCameraSharedPtr& camera);

        void SetDoRoll(int value) noexcept;
        void SetDoYaw(int value) noexcept;
        void SetDoPitch(int value) noexcept;
        void SetTrackBallDow(bool value) noexcept;
        NODISCARD bool GetTrackBallDow() const noexcept;

        void SetBeginTrack(float xTrack, float yTrack) noexcept;
        void SetEndTrack(float xTrack, float yTrack) noexcept;
        void SetSaveRotate() noexcept(gAssert < 2 || gRenderingAssert < 2);

        NODISCARD Transform GetMotionObjectLocalTransform() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_OBJECT_MOTION_H
