///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 11:08)

#ifndef RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H
#define RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WorldCoordinateFrame
    {
    public:
        using ClassType = WorldCoordinateFrame;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;
        using Math = Mathematics::Math<float>;

    public:
        explicit WorldCoordinateFrame(float epsilon);

        CLASS_INVARIANT_DECLARE;

        // 摄像机坐标系总是在世界坐标。
        // 默认 position  P = (0, 0,  0; 1)
        // 默认 direction D = (0, 0, -1; 0)
        // 默认 up        U = (0, 1,  0; 0)
        // 默认 right     R = (1, 0,  0; 0)
        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        void SetPosition(const APoint& position);

        void SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetDirectionVector() const noexcept;
        NODISCARD AVector GetUpVector() const noexcept;
        NODISCARD AVector GetRightVector() const noexcept;

        // 访问摄像机的视图矩阵。
        // 如果D = (d0,d1,d2),U = (u0,u1,u2),和R = (r0,r1,r2),
        // 视图矩阵为
        //   +-                     -+
        //   | r0  r1  r2  -Dot(R,P) |
        //   | u0  u1  u2  -Dot(U,P) |
        //   | d0  d1  d2  -Dot(D,P) |
        //   |  0   0   0          1 |
        //   +-                     -+
        // 对视图矩阵右乘向量,viewMat * vector4。
        NODISCARD Matrix GetViewMatrix() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        // 在帧变化后计算的视图矩阵。
        void OnFrameChange();

    private:
        // 世界坐标系。
        APoint worldPosition;
        AVector worldDirectionVector;
        AVector worldUpVector;
        AVector worldRightVector;

        // 摄像机的视图矩阵。
        // 矩阵存储,这样你将它应用到矢量在它的右边
        // viewMatrix * someVector4
        Matrix viewMatrix;

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_WORLD_COORDINATE_FRAME_H
