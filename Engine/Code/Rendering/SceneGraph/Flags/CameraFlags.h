/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:33)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FLAGS_H
#define RENDERING_SCENE_GRAPH_CAMERA_FLAGS_H

namespace Rendering
{
    // 访问相机的投影矩阵。投影矩阵映射到深度[0,1]是Direct3D使用。
    // 视图矩阵映射到深度[-1,1] 是OpenGL使用。
    enum class DepthType
    {
        ZeroToOne,  // [0,1]
        MinusOneToOne,  // [-1,1]
        Quantity
    };

    /// 视图平截头体支持。
    /// 视图平截头体参数[rMin,rMax], [uMin,uMax],和[dMin,dMax]。
    /// 区间[rMin,rMax]测量正确的方向R,这些都是“左”和“右”平截头体的值。
    /// 区间[uMin,uMax]测量正确的方向U,这些都是“底”和“顶”平截头体的值。
    /// 区间[dMin,dMax]测量正确的方向D,这些都是“近”和“远”平截头体的值。
    /// 平截头体的值存储在一个数组与以下映射:
    enum class ViewFrustum
    {
        DirectionMin = 0,  // near
        DirectionMax = 1,  // far
        UpMin = 2,  // bottom
        UpMax = 3,  // top
        RightMin = 4,  // left
        RightMax = 5,  // right
        Quantity = 6
    };

    // 访问世界裁减平面的堆栈。你可能会使用push和pop平面，除了视图平截头体的平面。
    // PushPlane需要在世界输入平面坐标。数据成员planeState在位系统的启用和禁用平面裁剪。
    enum
    {
        MaxPlaneQuantity = 32
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_FLAGS_H
