///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:09)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_FLAGS_H
#define RENDERING_SCENE_GRAPH_VISUAL_FLAGS_H

namespace Rendering
{
    enum class VisualPrimitiveType
    {
        None,  // 默认构造
        Polypoint,
        PolysegmentsDisjoint,
        PolysegmentsContiguous,
        Triangles,  // 抽象
        TriangleMesh,
        TriangleStrip,
        TriangleFan,
        MaxQuantity
    };

    // 几何更新。如果顶点缓冲区的位置已经修改,
    // 您可能需要对原始的索引三角形更新表面帧(法线，切线，双切线)。
    // 假设位置更新和顶点缓冲区是锁住的。UpdateModelSpace的参数指定更新算法:

    //   VisualUpdateType::ModelBoundOnly:
    //      只更新的模型空间绑定的新位置。

    // 其他的选择,模型空间绑定总是重新计算,无论原始的类型。
    // 对于表面帧更新,Visual必须代表一个原始的索引三角形,
    // 必须有相关通道(法线，切线，双切线)。
    // 如果没有索引的原始三角形,调用更新在框架中不做任何事。
    // 这些通道更新只发生在顶点缓冲。
    // 例如,如果顶点缓冲区没有法线,VisualUpdateType::Normals对顶点缓冲区没有影响。
    // 另外一个例子,如果你指定VisualUpdateType::UseGeometry和
    // 顶点缓冲区有法线和切线但没有双切线,只有法线和切线更新
    // (即顶点缓冲区不再重新生成双切线)。

    //   VisualUpdateType::Normals:
    //      更新法线。
    //
    //   VisualUpdateType::UseGeometry:
    //      使用网状拓扑以确定表面帧。
    //      该算法使用最小二乘法，这是昂贵的。

    //   VisualUpdateTypeUseTcoordChannel + 非负整数:
    //      标准的方法来生成表面帧，是使用从顶点缓冲区中的纹理坐标单元。

    // 要通过顶点缓冲区减少视频内存的使用，如果你的顶点着色器使用法线，切线和双切钱，
    // 考虑通过法线和切线，然后让着色器计算双切线为bitangent = Cross(normal, tangent)

    enum class VisualUpdateType
    {
        ModelBoundOnly = -3,
        Normals = -2,
        UseGeometry = -1,
        UseTextureCoordChannel = 0
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_FLAGS_H
