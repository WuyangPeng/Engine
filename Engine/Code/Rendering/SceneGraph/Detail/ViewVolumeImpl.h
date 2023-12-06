/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/21 19:09)

#ifndef RENDERING_SCENE_GRAPH_VIEW_VOLUME_IMPL_H
#define RENDERING_SCENE_GRAPH_VIEW_VOLUME_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CameraFrustum.h"
#include "ProjectionMatrix.h"
#include "WorldCoordinateFrame.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ViewVolumeImpl
    {
    public:
        using ClassType = ViewVolumeImpl;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using Math = Mathematics::Math<float>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;

        using Container = std::array<float, System::EnumCastUnderlying(ViewFrustum::Quantity)>;

    public:
        ViewVolumeImpl() noexcept;
        ViewVolumeImpl(bool isPerspective, DepthType depthType, float epsilon);

        CLASS_INVARIANT_DECLARE;

        void SetPosition(const APoint& position);
        void SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector);
        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetDirectionVector() const noexcept;
        NODISCARD AVector GetUpVector() const noexcept;
        NODISCARD AVector GetRightVector() const noexcept;

        NODISCARD Matrix GetViewMatrix() const noexcept;
        NODISCARD Matrix GetInverseViewMatrix() const noexcept;

        NODISCARD Matrix GetProjectionMatrix() const noexcept;
        void SetProjectionMatrix(const Matrix& aProjectionMatrix) noexcept;
        NODISCARD Matrix GetProjectionViewMatrix() const noexcept;
        void SetProjectionViewMatrix(const Matrix& aProjectionMatrix) noexcept;

        NODISCARD DepthType GetDepthType() const noexcept;

        NODISCARD bool IsPerspective() const noexcept;

        void SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax);
        void SetFrustum(const Container& frustum);
        void SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax);
        NODISCARD Container GetFrustum() const noexcept;
        NODISCARD CameraFrustumData GetSymmetricFrustum() const;

        NODISCARD float GetDirectionMin() const;
        NODISCARD float GetDirectionMax() const;
        NODISCARD float GetUpMin() const;
        NODISCARD float GetUpMax() const;
        NODISCARD float GetRightMin() const;
        NODISCARD float GetRightMax() const;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void UpdateProjectionViewMatrix() noexcept;

    private:
        // 在截头体改变之后计算投影矩阵，然后更新投影视图矩阵。
        void OnFrustumChange();

    private:
        WorldCoordinateFrame worldCoordinateFrame;
        ProjectionMatrix projectionMatrix;
        CameraFrustum cameraFrustum;
    };
}

#endif  // RENDERING_SCENE_GRAPH_VIEW_VOLUME_IMPL_H
