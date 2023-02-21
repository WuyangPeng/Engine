///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 11:43)

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
        // 节点的世界坐标使用相机的位置。
        // 节点的世界旋转矩阵使用相机的坐标轴。
        // 世界旋转矩阵的列0是相机的direction向量,
        // 世界旋转矩阵的列1是相机的up向量,
        // 世界旋转矩阵的列2是相机的right向量。

        // 节点的局部变换将设置为相机的当前坐标系统。
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
        // 当你设置摄像机，节点的本地转换将设置为当前相机的当前坐标系统。
        // 节点的世界变换将被计算,
        // 和相机的坐标系使用节点的世界转换。
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
