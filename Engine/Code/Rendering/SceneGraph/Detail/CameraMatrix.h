// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 19:14)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
#define RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H

#include "Rendering/RenderingDll.h"

#include "CameraFrustum.h"
#include "WorldCoordinateFrame.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraMatrix
    {
    public:
        using ClassType = CameraMatrix;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
        using Math = Mathematics::Math<float>;

    public:
        explicit CameraMatrix(const WorldCoordinateFrame& worldCoordinateFrame, const CameraFrustum& cameraFrustum, float epsilon = Math::sm_ZeroTolerance);
        explicit CameraMatrix(float epsilon = Math::sm_ZeroTolerance);

        CLASS_INVARIANT_DECLARE;

        // 平截头体的值是N (near), F (far), B (bottom), T (top),
        // L (left), 和 R (right).  各种矩阵如下：
        //
        // 透视, 深度 [0,1]
        //   +-                                               -+
        //   | 2*N/(R-L)  0           -(R+L)/(R-L)  0          |
        //   | 0          2*N/(T-B)   -(T+B)/(T-B)  0          |
        //   | 0          0           F/(F-N)       -N*F/(F-N) |
        //   | 0          0           1             0          |
        //   +-                                               -+
        //
        // 透视, 深度 [-1,1]
        //   +-                                                 -+
        //   | 2*N/(R-L)  0           -(R+L)/(R-L)  0            |
        //   | 0          2*N/(T-B)   -(T+B)/(T-B)  0            |
        //   | 0          0           (F+N)/(F-N)   -2*F*N/(F-N) |
        //   | 0          0           1             0
        //   +-                                                 -+
        //
        // 正交, 深度 [0,1]
        //   +-                                       -+
        //   | 2/(R-L)  0  0              -(R+L)/(R-L) |
        //   | 0        2/(T-B)  0        -(T+B)/(T-B) |
        //   | 0        0        1/(F-N)  -N/(F-N)  0  |
        //   | 0        0        0        1            |
        //   +-                                       -+
        //
        // 正交, 深度 [-1,1]
        //   +-                                       -+
        //   | 2/(R-L)  0        0        -(R+L)/(R-L) |
        //   | 0        2/(T-B)  0        -(T+B)/(T-B) |
        //   | 0        0        2/(F-N)  -(F+N)/(F-N) |
        //   | 0        0        0        1            |
        //   +-                                       -+
        //
        // 投影矩阵右乘向量,projMat * vector4。

        // 返回矩阵的值取决于DepthType和IsPerspective。
        const Matrix GetProjectionMatrix() const noexcept;

        // 支持高级效果。
        // 第一个函数允许您设置任何投影矩阵。
        // 第二个函数指定一个凸四边形视口。
        // 点必须在相机坐标系且对于视点观察是逆时针顺序。
        // 平面是四边形在观察平面,有一个“拉伸”值为1。
        // nearExtrude值是(0,infinity)。
        // 它指定分数从视点到观察平面在立方形的视图的体积的近平面。
        // farExtrude值是(nearExtrude,infinity)。
        // 它指定分数从视点到观察平面在立方形的视图的体积的远平面。
        void SetProjectionMatrix(const Matrix& projectionMatrix);
        void SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude);

        DepthType GetDepthType() const noexcept;

        void SetDepthType(DepthType depthType);

        // 世界投影视图矩阵是常用的片段着色器程序去转换模型空间数据到裁剪空间数据。
        // 为了避免重复计算每个几何对象的投影矩阵,在该类中存储和维护。
        const Matrix GetProjectionViewMatrix() const noexcept;

        // 预览矩阵应用于在模型对世界之后，视图矩阵之前。
        // 用于转换等世界对象的反射。默认值为单位矩阵。
        void SetPreViewMatrix(const Matrix& preViewMatrix)  ;
        const Matrix GetPreViewMatrix() const noexcept;
        bool PreViewIsIdentity() const noexcept;

        // 后投影矩阵用于空间转换如渲染后的图像的反射。默认值为单位矩阵。
        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        const Matrix GetPostProjectionMatrix() const noexcept;
        bool PostProjectionIsIdentity() const noexcept;

        // 计算投影矩阵在平截头体的变化后。
        void OnFrustumChange(const CameraFrustum& cameraFrustum);

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        int GetStreamingSize() const;

        const CameraFrustum& GetCameraFrustum() const noexcept;
        const WorldCoordinateFrame& GetWorldCoordinateFrame() const noexcept;

        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        void SetPosition(const APoint& position)  ;

        void SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        float GetEpsilon() const noexcept;

    private:
        void OnFrustumChange();

        // 计算后投影矩阵、投影矩阵、视图矩阵、预览矩阵的结果
        void UpdateProjectionViewMatrix();

    private:
        WorldCoordinateFrame m_WorldCoordinateFrame;
        CameraFrustum m_CameraFrustum;

        // 摄像机的投影矩阵，
        // 投影矩阵被存储为右乘向量,projMatrix * someVector4。
        Matrix m_ProjectionMatrix[System::EnumCastUnderlying(DepthType::Quantity)];

        // 投影与视图矩阵的乘积。这包括post-projection和/或pre-view当这些矩阵不是单位矩阵时。
        Matrix m_ProjectionViewMatrix[System::EnumCastUnderlying(DepthType::Quantity)];

        // 摄像机的preview矩阵
        Matrix m_PreViewMatrix;
        bool m_PreViewIsIdentity;

        // 摄像机的postprojection矩阵
        Matrix m_PostProjectionMatrix;
        bool m_PostProjectionIsIdentity;

        // 这个对象的深度类型。值在构造函数时被初始化为CAMERA_MANAGE_SINGLETON.GetDepthType()。
        // 相机不在流中存储此值。
        // 派生类Projector覆盖深度类型和存储它,因为你可能想要一个投影仪的类型但不匹配图形API类型。
        DepthType m_DepthType;

        float m_Epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
