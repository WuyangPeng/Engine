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
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
	class Camera;

    class RENDERING_DEFAULT_DECLARE CameraNode : public Node
    {
    public:
         COPY_UNSHARE_CLASSES_TYPE_DECLARE(CameraNode, DESTRUCTOR_STATEMENT);
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
		explicit CameraNode(const CameraSharedPtr& camera);
         

		CLASS_INVARIANT_OVERRIDE_DECLARE;        
           ObjectInterfaceSharedPtr CloneObject() const override;
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CameraNode);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
        
    public:
        // ����������������ڵ�ı���ת��������Ϊ��ǰ����ĵ�ǰ����ϵͳ��
        // �ڵ������任��������,
        // �����������ϵʹ�ýڵ������ת����
		void SetCamera(const CameraSharedPtr& camera);
		const ConstCameraSharedPtr GetCamera() const noexcept;
        
		  ControllerInterfaceSharedPtr Clone() const override;
        
    protected:
          bool UpdateWorldData (double applicationTime) override;
        
	private:
		IMPL_TYPE_DECLARE(CameraNode);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(CameraNode);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( CameraNode); 
}
#include STSTEM_WARNING_POP

#endif // RENDERING_SCENE_GRAPH_CAMERA_NODE_H
