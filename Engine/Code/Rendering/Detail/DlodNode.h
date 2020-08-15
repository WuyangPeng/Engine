// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:29)

#ifndef RENDERING_DETAIL_DLOD_NODE_H
#define RENDERING_DETAIL_DLOD_NODE_H

#include "Rendering/RenderingDll.h"

#include "SwitchNode.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

RENDERING_EXPORT_SHARED_PTR(DlodNodeImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE DlodNode : public SwitchNode
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(DlodNode);
		using ParentType = SwitchNode;

	public:
		explicit DlodNode (int numLevelsOfDetail);
		  ~DlodNode ();
		  DlodNode(DlodNode&&) noexcept = default;
		DlodNode& operator=(DlodNode&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DlodNode); 

		// 访问中心(LOD)细节等级。
	 	const APoint GetModelCenter() const  noexcept;		
		const APoint GetWorldCenter () const noexcept;

		void SetModelCenter(const APoint& modelCenter) noexcept;

		// 获得子节点的距离间隔。
		int GetNumLevelsOfDetail () const noexcept;
		float GetModelMinDistance (int index) const;
		float GetModelMaxDistance(int index) const;
		float GetWorldMinDistance(int index) const;
		float GetWorldMaxDistance(int index) const;
		void SetModelDistance(int index, float minDistance, float maxDistance);
		
	protected:
		// 支持分级裁剪。
		  void GetVisibleSet(Culler& culler, bool noCull) override;

	private:
		// 开关基于来自世界LOD中心，以摄像头距离选择子节点。
		void SelectLevelOfDetail (const ConstCameraSmartPointer& camera);
 
	private:
		IMPL_TYPE_DECLARE(DlodNode);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(DlodNode);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Eighth,DlodNode);
}

#endif // RENDERING_DETAIL_DLOD_NODE_H
