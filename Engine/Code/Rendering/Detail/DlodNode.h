// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:29)

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

		// ��������(LOD)ϸ�ڵȼ���
	 	const APoint GetModelCenter() const  noexcept;		
		const APoint GetWorldCenter () const noexcept;

		void SetModelCenter(const APoint& modelCenter) noexcept;

		// ����ӽڵ�ľ�������
		int GetNumLevelsOfDetail () const noexcept;
		float GetModelMinDistance (int index) const;
		float GetModelMaxDistance(int index) const;
		float GetWorldMinDistance(int index) const;
		float GetWorldMaxDistance(int index) const;
		void SetModelDistance(int index, float minDistance, float maxDistance);
		
	protected:
		// ֧�ַּ��ü���
		  void GetVisibleSet(Culler& culler, bool noCull) override;

	private:
		// ���ػ�����������LOD���ģ�������ͷ����ѡ���ӽڵ㡣
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
