///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/02 16:51)

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
        // ����һ���ռ��������ȾĿ����ʹ�á�
        NODISCARD static CameraSharedPtr CreateCamera();

        // ʹ��ָ���ĳߴ紴��һ�����οռ��ڵ���ȾĿ�ꡣ
        // �����ʽ���������Ԫ�����λ�ú��ڵ�λ0�Ķ�Ԫ�����������ꡣ
        // ��Щ���Ա�������䡣�κ��������Բ�������
        // ����[xmin,xmax] x [ymin,ymax]���������[0,1] x [0,1]��
        NODISCARD static TrianglesMeshSharedPtr CreateRectangle(const VertexFormatSharedPtr& vertexFormat,
                                                                int renderTargetWidth,
                                                                int renderTargetHeight,
                                                                float xMin,
                                                                float xMax,
                                                                float yMin,
                                                                float yMax,
                                                                float zValue);

        // ���ؾ��οռ���λ�á�
        NODISCARD static std::vector<APoint> CreatePositions(int renderTargetWidth, int renderTargetHeight, float xMin, float xMax, float yMin, float yMax, float zValue);

        // ���ؾ��οռ��������ꡣ
        NODISCARD static std::vector<Vector2D> CreateTextureCoords();

    private:
        NODISCARD static bool ValidSizes(int renderTargetWidth, int renderTargetHeight);
        NODISCARD static bool ValidFormat(const VertexFormat& vertexFormat);

        static void InitIndexBufferInParticles(IndexBuffer& indexBuffer);
    };
}

#endif  // RENDERING_SCENE_GRAPH_SCREEN_TARGET_H
