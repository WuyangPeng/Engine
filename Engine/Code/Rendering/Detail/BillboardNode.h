// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:27)

#ifndef RENDERING_DETAIL_BILLBOARD_NODE_H
#define RENDERING_DETAIL_BILLBOARD_NODE_H

#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/Camera.h"


RENDERING_EXPORT_SHARED_PTR(BillboardNodeImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

namespace Rendering
{
	// 广告牌的模型空间具有的(0,1,0)向上矢量
	// 被选择为旋转的广告牌的轴。
	class RENDERING_DEFAULT_DECLARE BillboardNode : public Node
	{
	public:
            COPY_UNSHARE_CLASSES_TYPE_DECLARE(BillboardNode, = default);
		using ParentType = Node;

	public:
		explicit BillboardNode(const CameraSharedPtr& camera);
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BillboardNode);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
	
		// 广告牌对齐的摄像头。
		void AlignTo(const CameraSharedPtr& camera);

		 ControllerInterfaceSharedPtr Clone() const override;

		const ConstCameraSharedPtr GetCamera() const;
		
	private:
		// 对几何更新的支持。
		  bool UpdateWorldData(double applicationTime) override;

	private:
		IMPL_TYPE_DECLARE(BillboardNode);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(BillboardNode);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( BillboardNode);
}
#include STSTEM_WARNING_POP
#endif // RENDERING_DETAIL_BILLBOARD_NODE_H
