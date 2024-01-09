/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:53)

#ifndef RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H
#define RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WorldCoordinateFrame
    {
    public:
        using ClassType = WorldCoordinateFrame;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using Math = Mathematics::Math<float>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;

    public:
        WorldCoordinateFrame() noexcept;
        explicit WorldCoordinateFrame(float epsilon);

        CLASS_INVARIANT_DECLARE;

        /// 摄像机坐标系总是在世界坐标。默认坐标系{P;D,U,R}在右手世界坐标中，其中
        /// 默认 position  P = (0, 0,  0; 1)
        /// 默认 direction D = (0, 0, -1; 0)
        /// 默认 up        U = (0, 1,  0; 0)
        /// 默认 right     R = (1, 0,  0; 0)
        /// 基{D,U,R}需要是一个右手正交集。
        void SetPosition(const APoint& aPosition);

        void SetAxes(const AVector& aDirectionVector, const AVector& aUpVector, const AVector& aRightVector);

        void SetFrame(const APoint& aPosition, const AVector& aDirectionVector, const AVector& aUpVector, const AVector& aRightVector);

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetDirectionVector() const noexcept;
        NODISCARD AVector GetUpVector() const noexcept;
        NODISCARD AVector GetRightVector() const noexcept;

        /// 访问坐标系的视图矩阵。
        /// 如果D = (d0,d1,d2),U = (u0,u1,u2),和R = (r0,r1,r2),
        /// 视图矩阵为
        ///   +-                     -+
        ///   | r0  r1  r2  -Dot(R,P) |
        ///   | u0  u1  u2  -Dot(U,P) |
        ///   | d0  d1  d2  -Dot(D,P) |
        ///   |  0   0   0          1 |
        ///   +-                     -+
        /// 当定义了MATHEMATICS_USE_MATRIX_VECTOR，对视图矩阵右乘向量，即viewMat*vector4。
        /// 当未定义MATHEMATICS_USE_MATRIX_VECTOR，对视图矩阵左乘向量，即vector4*viewMat，将使用显示矩阵的转置。
        /// MATHEMATICS_USE_MATRIX_VECTOR约定的逆视图矩阵为
        ///            +-            -+
        ///            | r0 u0 d0 p0 |
        ///   V^{-1} = | r1 u1 d1 p1 |
        ///            | r2 u2 d2 p1 |
        ///            |  0  0  0  1 |
        ///            +-           -+
        /// 点X = (x0,x1,x2,1)可以由
        ///   X = P + y0*R + y1*U + y2*D,
        /// 其中y0 = Dot(R,X-P), y1 = Dot(U,X-P), 和 y2 = Dot(D,X-P)
        /// 使用MATHEMATICS_USE_MATRIX_VECTOR约定，如果Y = (y0,y1,y2,1)，则Y = V*X，
        /// 其中V是视图矩阵。
        NODISCARD Matrix GetViewMatrix() const noexcept;
        NODISCARD Matrix GetInverseViewMatrix() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        // 计算帧更改后的视图矩阵，然后更新投影视图矩阵。
        void OnFrameChange();

    private:
        // 世界坐标系。
        APoint position;
        AVector directionVector;
        AVector upVector;
        AVector rightVector;

        /// 世界坐标系的视图矩阵（V）。
        /// 存储顺序取决于是否定义了MATHEMATICS_USE_MATRIX_VECTOR。
        /// 另一个矩阵是逆视图矩阵(V^{-1})。
        Matrix viewMatrix;
        Matrix inverseViewMatrix;

#ifdef RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

        /// 它的使用由条件编译控制（通过RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE）。
        /// 它允许您捕获不正确构建的框架或由于数值舍入错误而倾斜的框架。
        bool validateCoordinateFrame;

#endif  // RENDERING_USE_VALIDATE_COORDINATE_FRAME_ONCE

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H
