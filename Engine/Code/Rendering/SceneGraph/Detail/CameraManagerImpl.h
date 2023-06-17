///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:06)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_MANAGE_IMPL_H
#define RENDERING_SCENE_GRAPH_CAMERA_MANAGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraManagerImpl
    {
    public:
        using ClassType = CameraManagerImpl;

    public:
        CameraManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        // ��Ӧ����ƽ̨���Ӧ�ó�������á�
        // �����֤�������ȷ��ͶӰ������GetProjection()��
        void SetDefaultDepthType(RendererTypes type) noexcept;
        NODISCARD DepthType GetDepthType() const noexcept;

    private:
        // ָ�����͵�ͶӰ����(DirectX��OpenGL��ͬ����
        DepthType depthType;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_MANAGE_IMPL_H
