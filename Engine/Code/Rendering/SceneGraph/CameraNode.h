///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/02 11:43)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_NODE_H
#define RENDERING_SCENE_GRAPH_CAMERA_NODE_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Node.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(CameraNode, CameraNodeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CameraNode : public Node
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CameraNode);
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

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CameraNode);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        // ����������������ڵ�ı���ת��������Ϊ��ǰ����ĵ�ǰ����ϵͳ��
        // �ڵ������任��������,
        // �����������ϵʹ�ýڵ������ת����
        void SetCamera(const CameraSharedPtr& camera);
        NODISCARD ConstCameraSharedPtr GetCamera() const noexcept;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;

    protected:
        NODISCARD bool UpdateWorldData(double applicationTime) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(CameraNode);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(CameraNode);
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_NODE_H
