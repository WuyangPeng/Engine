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

EXPORT_SHARED_PTR(Rendering, DlodNodeImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE DlodNode : public SwitchNode
	{
	public:
            void Swap(DlodNode& rhs) noexcept;

        public:
            TYPE_DECLARE(DlodNode);
            using ClassShareType = CoreTools::CopyUnsharedClasses;
            ~DlodNode() noexcept = default;
            DlodNode(const DlodNode& rhs);
            DlodNode& operator=(const DlodNode& rhs);
            DlodNode(DlodNode&& rhs) noexcept;
            DlodNode& operator=(DlodNode&& rhs) noexcept;
		using ParentType = SwitchNode;

	public:
		explicit DlodNode (int numLevelsOfDetail);
		 
		 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
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
		void SelectLevelOfDetail (const ConstCameraSharedPtr& camera);
 
	private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(DlodNode);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE(DlodNode);
}
#include STSTEM_WARNING_POP
#endif // RENDERING_DETAIL_DLOD_NODE_H
