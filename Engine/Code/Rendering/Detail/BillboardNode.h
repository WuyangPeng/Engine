// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:27)

#ifndef RENDERING_DETAIL_BILLBOARD_NODE_H
#define RENDERING_DETAIL_BILLBOARD_NODE_H

#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/Camera.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

RENDERING_EXPORT_SHARED_PTR(BillboardNodeImpl);

namespace Rendering
{
	// ����Ƶ�ģ�Ϳռ���е�(0,1,0)����ʸ��
	// ��ѡ��Ϊ��ת�Ĺ���Ƶ��ᡣ
	class RENDERING_DEFAULT_DECLARE BillboardNode : public Node
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(BillboardNode);
		using ParentType = Node;

	public:
		explicit BillboardNode(const CameraSmartPointer& camera);
		virtual ~BillboardNode();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BillboardNode);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
	
		// ����ƶ��������ͷ��
		void AlignTo(const CameraSmartPointer& camera);

		virtual ControllerInterfaceSmartPointer Clone() const override;

		const ConstCameraSmartPointer GetCamera() const;
		
	private:
		// �Լ��θ��µ�֧�֡�
		virtual bool UpdateWorldData(double applicationTime);

	private:
		IMPL_TYPE_DECLARE(BillboardNode);
	};

	CORE_TOOLS_STREAM_REGISTER(BillboardNode);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Seventh, BillboardNode);
}

#endif // RENDERING_DETAIL_BILLBOARD_NODE_H
