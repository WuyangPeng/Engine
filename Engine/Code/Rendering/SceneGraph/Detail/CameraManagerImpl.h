// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:13)

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
                CameraManagerImpl(MAYBE_UNUSED int count) noexcept;
	
		CLASS_INVARIANT_DECLARE;
 
        // ��Ӧ����ƽ̨���Ӧ�ó�������á�
        // �����֤�������ȷ��ͶӰ������GetProjection()��
                void SetDefaultDepthType(RendererTypes type) noexcept;
                DepthType GetDepthType() const noexcept;

	private: 
		// ָ�����͵�ͶӰ����(DirectX��OpenGL��ͬ���� 
		DepthType m_DepthType;		
	};
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_MANAGE_IMPL_H



	