// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:17)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_NODE_H
#define RENDERING_SCENE_GRAPH_CAMERA_NODE_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Node.h"

RENDERING_EXPORT_SHARED_PTR(CameraNodeImpl);

namespace Rendering
{
	class Camera;

    class RENDERING_DEFAULT_DECLARE CameraNode : public Node
    {
    public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(CameraNode);
		using ParentType = Node;
        
    public:
        // �ڵ����������ʹ�������λ�á�
        // �ڵ��������ת����ʹ������������ᡣ
        // ������ת�������0�������direction����,
        // ������ת�������1�������up����,
        // ������ת�������2�������right������

        // �ڵ�ľֲ��任������Ϊ����ĵ�ǰ����ϵͳ��
        //   local translation       = camera location
        //   local rotation column 0 = camera direction
        //   local rotation column 1 = camera up
        //   local rotation column 2 = camera right
		explicit CameraNode(const CameraSmartPointer& camera);
          ~CameraNode ();
                CameraNode(CameraNode&&) noexcept = default;
          CameraNode& operator=(CameraNode&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CameraNode);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
        
    public:
        // ����������������ڵ�ı���ת��������Ϊ��ǰ����ĵ�ǰ����ϵͳ��
        // �ڵ������任��������,
        // �����������ϵʹ�ýڵ������ת����
		void SetCamera(const CameraSmartPointer& camera);
		const ConstCameraSmartPointer GetCamera() const noexcept;
        
		  ControllerInterfaceSmartPointer Clone() const override;
        
    protected:
          bool UpdateWorldData (double applicationTime) override;
        
	private:
		IMPL_TYPE_DECLARE(CameraNode);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(CameraNode);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Seventh, CameraNode); 
}

#endif // RENDERING_SCENE_GRAPH_CAMERA_NODE_H
