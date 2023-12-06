///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.1 (2023/11/21 15:09)

#ifndef RENDERING_SCENE_GRAPH_PROJECTION_MATRIX_H
#define RENDERING_SCENE_GRAPH_PROJECTION_MATRIX_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ProjectionMatrix
    {
    public:
        using ClassType = ProjectionMatrix;

        using Matrix = Mathematics::Matrix<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit ProjectionMatrix(DepthType depthType) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 访问相机的投影矩阵。这些矩阵映射到区间[0,1]中的深度。

        /// 平截头体的值是N (near), F (far), B (bottom), T (top),
        /// L (left), 和 R (right)。 定义MATHEMATICS_USE_MATRIX_VECTOR时，各种矩阵如下：
        /// 未定义MATHEMATICS_USE_MATRIX_VECTOR时，使用这些矩阵的转置。
        ///
        /// 透视, 深度 [0,1]
        ///   +-                                               -+
        ///   | 2*N/(R-L)  0           -(R+L)/(R-L)  0          |
        ///   | 0          2*N/(T-B)   -(T+B)/(T-B)  0          |
        ///   | 0          0           F/(F-N)       -N*F/(F-N) |
        ///   | 0          0           1             0          |
        ///   +-                                               -+
        ///
        /// 透视, 深度 [-1,1]
        ///   +-                                                 -+
        ///   | 2*N/(R-L)  0           -(R+L)/(R-L)  0            |
        ///   | 0          2*N/(T-B)   -(T+B)/(T-B)  0            |
        ///   | 0          0           (F+N)/(F-N)   -2*F*N/(F-N) |
        ///   | 0          0           1             0
        ///   +-                                                 -+
        ///
        /// 正交, 深度 [0,1]
        ///   +-                                       -+
        ///   | 2/(R-L)  0  0              -(R+L)/(R-L) |
        ///   | 0        2/(T-B)  0        -(T+B)/(T-B) |
        ///   | 0        0        1/(F-N)  -N/(F-N)  0  |
        ///   | 0        0        0        1            |
        ///   +-                                       -+
        ///
        /// 正交, 深度 [-1,1]
        ///   +-                                       -+
        ///   | 2/(R-L)  0        0        -(R+L)/(R-L) |
        ///   | 0        2/(T-B)  0        -(T+B)/(T-B) |
        ///   | 0        0        2/(F-N)  -(F+N)/(F-N) |
        ///   | 0        0        0        1            |
        ///   +-                                       -+
        ///
        /// 投影矩阵右乘向量,projMat * vector4。

        // 返回的矩阵是透视矩阵还是正交矩阵，取决于IsPerspective。
        NODISCARD Matrix GetProjectionMatrix() const noexcept;

        /// 对于高级效果，您可能希望将投影矩阵设置为标准矩阵以外的其他矩阵。
        void SetProjectionMatrix(const Matrix& aProjectionMatrix, const Matrix& viewMatrix) noexcept;
        void SetProjectionViewMatrix(const Matrix& aProjectionViewMatrix) noexcept;

        /// 投影视图世界矩阵通常在着色器程序中用于将模型空间数据转换为剪辑空间数据。
        /// 为了避免重复计算每个几何对象的投影视图矩阵，乘积被存储和维护在这个类中。
        NODISCARD Matrix GetProjectionViewMatrix() const noexcept;

        NODISCARD DepthType GetDepthType() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void UpdateProjectionViewMatrix(const Matrix& viewMatrix) noexcept;

    private:
        // 视图坐标系的投影矩阵，
        // 投影矩阵被存储为右乘向量,projMatrix * someVector4。
        Matrix projectionMatrix;

        // 投影矩阵与视图矩阵的乘积。
        // 这包括post-projection和/或pre-view当这些矩阵不是单位矩阵时。
        Matrix projectionViewMatrix;

        DepthType depthType;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PROJECTION_MATRIX_H
