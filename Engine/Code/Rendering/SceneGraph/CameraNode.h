// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:17)

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
           ObjectInterfaceSharedPtr CloneObject() const override;
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CameraNode);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
        
    public:
        // 当你设置摄像机，节点的本地转换将设置为当前相机的当前坐标系统。
        // 节点的世界变换将被计算,
        // 和相机的坐标系使用节点的世界转换。
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
