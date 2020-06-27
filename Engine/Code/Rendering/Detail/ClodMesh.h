// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:28)

#ifndef RENDERING_DETAIL_CLOD_MESH_H
#define RENDERING_DETAIL_CLOD_MESH_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Rendering/Detail/CollapseRecordArray.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

RENDERING_EXPORT_SHARED_PTR(ClodMeshImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ClodMesh : public TrianglesMesh
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(ClodMesh);
		using ParentType = TrianglesMesh;

	public:
		// ClodMesh�����ơ����񡱵�������������
		// ��Ϊ����Ҫ�ܹ������ظ�������������
		// ������ClodMesh��������ͬ�Ķ��㻺�������۵��ļ�¼��
		explicit ClodMesh(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,
			              const IndexBufferSmartPointer& indexbuffer,const CollapseRecordArraySmartPointer& recordArray);
		virtual ~ClodMesh();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ClodMesh);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
		
		int GetNumRecords () const;
		
		int GetTargetRecord() const;
		void SetTargetRecord(int targetRecord);
		
		// LODѡ���ǻ���Ӧ���ֶ�ѡ��
		// Ҫʹ������������Ļ�ռ�ĸ��Ƿ�Χ��
		// ��ClodMesh���������д��GetAutomatedTargetRecord����
	
		// ��ȡĿ���¼�����⺯����������������д���Ի��Ŀ��������Զ������
		virtual int GetAutomatedTargetRecord() const;
		
		// ���θ��¡�Draw���������ô˸��£�������Ŀ���¼�ĵ�ǰֵ����TrianglesMesh������
		// �����ڲ���Ҫ��ʾ�����Ӧ�ó����ֶ����á�
		void SelectLevelOfDetail ();

		virtual ControllerInterfaceSmartPointer Clone() const override;
		
	protected:
		// ֧�ַּ��ü���
		virtual void GetVisibleSet(Culler& culler, bool noCull) override;

	private:
		IMPL_TYPE_DECLARE(ClodMesh);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(ClodMesh);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Ninth, ClodMesh);
}

#endif // RENDERING_DETAIL_CLOD_MESH_H
