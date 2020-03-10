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
		virtual ~DlodNode ();

		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DlodNode); 

		// ��������(LOD)ϸ�ڵȼ���
	 	const APoint GetModelCenter() const;		
		const APoint GetWorldCenter () const;

		void SetModelCenter(const APoint& modelCenter);

		// ����ӽڵ�ľ�������
		int GetNumLevelsOfDetail () const;
		float GetModelMinDistance (int index) const;
		float GetModelMaxDistance(int index) const;
		float GetWorldMinDistance(int index) const;
		float GetWorldMaxDistance(int index) const;
		void SetModelDistance(int index, float minDistance, float maxDistance);
		
	protected:
		// ֧�ַּ��ü���
		virtual void GetVisibleSet(Culler& culler, bool noCull);

	private:
		// ���ػ�����������LOD���ģ�������ͷ����ѡ���ӽڵ㡣
		void SelectLevelOfDetail (const ConstCameraSmartPointer& camera);
 
	private:
		IMPL_TYPE_DECLARE(DlodNode);
	};

	CORE_TOOLS_STREAM_REGISTER(DlodNode);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Eighth,DlodNode);
}

#endif // RENDERING_DETAIL_DLOD_NODE_H
