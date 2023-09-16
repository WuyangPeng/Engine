///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:09)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_H
#define RENDERING_SCENE_GRAPH_CAMERA_H

#include "Rendering/RenderingDll.h"

#include "CameraFrustumData.h"
#include "Flags/CameraFlags.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Camera, CameraImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Camera : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Camera);
        using ParentType = Object;
        using CameraSharedPtr = std::shared_ptr<ClassType>;
        using ConstCameraSharedPtr = std::shared_ptr<ClassType>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
        using AxesAlignBoundingBox2D = Mathematics::AxesAlignBoundingBox2<float>;
        using Math = Mathematics::Math<float>;

    public:
        explicit Camera(bool isPerspective, bool isDepthRangeZeroOne, float epsilon = Math::GetZeroTolerance());

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Camera);

        NODISCARD float GetEpsilon() const noexcept;

        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        void SetPosition(const APoint& position);

        void SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetDirectionVector() const noexcept;
        NODISCARD AVector GetUpVector() const noexcept;
        NODISCARD AVector GetRightVector() const noexcept;

        NODISCARD Matrix GetViewMatrix() const noexcept;

        NODISCARD bool IsPerspective() const noexcept;

        void SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax);

        void SetFrustum(const float* frustum);

        void SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax);

        NODISCARD const float* GetFrustum() const noexcept;

        NODISCARD CameraFrustumData GetFrustumData() const noexcept;

        NODISCARD float GetDirectionMin() const noexcept;
        NODISCARD float GetDirectionMax() const noexcept;
        NODISCARD float GetUpMin() const noexcept;
        NODISCARD float GetUpMax() const noexcept;
        NODISCARD float GetRightMin() const noexcept;
        NODISCARD float GetRightMax() const noexcept;

        NODISCARD Matrix GetProjectionMatrix() const noexcept;

        void SetProjectionMatrix(const Matrix& projectionMatrix);
        void SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude);

        NODISCARD DepthType GetDepthType() const noexcept;

        NODISCARD Matrix GetProjectionViewMatrix() const noexcept;

        void SetPreViewMatrix(const Matrix& preViewMatrix);
        NODISCARD Matrix GetPreViewMatrix() const noexcept;
        NODISCARD bool PreViewIsIdentity() const noexcept;

        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        NODISCARD Matrix GetPostProjectionMatrix() const noexcept;
        NODISCARD bool PostProjectionIsIdentity() const noexcept;

        NODISCARD AxesAlignBoundingBox2D ComputeBoundingAABB(int numVertices, const char* vertices, int stride, const Matrix& worldMatrix) const;

    protected:
        void SetDepthType(DepthType depthType);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Camera);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Camera);
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_H
