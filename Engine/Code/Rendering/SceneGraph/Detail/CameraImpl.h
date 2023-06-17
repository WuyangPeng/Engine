///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:06)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_IMPL_H
#define RENDERING_SCENE_GRAPH_CAMERA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CameraMatrix.h"
#include "WorldCoordinateFrame.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraImpl
    {
    public:
        using ClassType = CameraImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
        using AxesAlignBoundingBox2D = Mathematics::AxesAlignBoundingBox2<float>;
        using HomogeneousPoint = Mathematics::HomogeneousPoint<float>;
        using Math = Mathematics::Math<float>;

    public:
        explicit CameraImpl(bool isPerspective, float epsilon = Math::GetZeroTolerance());
        explicit CameraImpl(float epsilon);

        CLASS_INVARIANT_DECLARE;

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

        // 对一组顶点计算轴对齐矩形包围盒在正则化显示空间,[-1,1]x[-1,1]。
        // 输入“顶点”是“float”的值三元组的指针,每个三元组代表一个顶点。
        // stride是从一个顶点第一位置的数通道到下一个顶点的第一个位置的通道的字节数。
        // 如果顶点是连续封装,stride为3 * sizeof(float)。
        // 顶点是在模型视图空间。输入“worldMatrix”转换模型视图空间到世界空间。

        NODISCARD AxesAlignBoundingBox2D ComputeBoundingAABB(int numVertices, const char* vertices, int stride, const Matrix& worldMatrix) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SetDepthType(DepthType depthType);

    private:
        CameraMatrix cameraMatrix;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_IMPL_H
