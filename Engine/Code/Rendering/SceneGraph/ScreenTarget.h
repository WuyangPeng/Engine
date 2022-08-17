///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:51)

#ifndef RENDERING_SCENE_GRAPH_SCREEN_TARGET_H
#define RENDERING_SCENE_GRAPH_SCREEN_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "TrianglesMesh.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ScreenTarget
    {
    public:
        using ClassType = ScreenTarget;
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using Vector2D = Mathematics::Vector2F;

    public:
        // 创建一个空间相机在渲染目标中使用。
        NODISCARD static CameraSharedPtr CreateCamera();

        // 使用指定的尺寸创建一个矩形空间内的渲染目标。
        // 顶点格式必须包含三元数组的位置和在单位0的二元数组纹理坐标。
        // 这些属性被函数填充。任何其他属性不被处理。
        // 矩形[xmin,xmax] x [ymin,ymax]必须包含在[0,1] x [0,1]。
        NODISCARD static TrianglesMeshSharedPtr CreateRectangle(const VertexFormatSharedPtr& vertexFormat,
                                                                int renderTargetWidth,
                                                                int renderTargetHeight,
                                                                float xMin,
                                                                float xMax,
                                                                float yMin,
                                                                float yMax,
                                                                float zValue);

        // 返回矩形空间内位置。
        NODISCARD static std::vector<APoint> CreatePositions(int renderTargetWidth, int renderTargetHeight, float xMin, float xMax, float yMin, float yMax, float zValue);

        // 返回矩形空间纹理坐标。
        NODISCARD static std::vector<Vector2D> CreateTextureCoords();

    private:
        NODISCARD static bool ValidSizes(int renderTargetWidth, int renderTargetHeight);
        NODISCARD static bool ValidFormat(const VertexFormat& vertexFormat);

        static void InitIndexBufferInParticles(IndexBuffer& indexBuffer);
    };
}

#endif  // RENDERING_SCENE_GRAPH_SCREEN_TARGET_H
