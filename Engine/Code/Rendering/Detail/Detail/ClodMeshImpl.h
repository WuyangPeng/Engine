// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:19)

#ifndef RENDERING_DETAIL_CLOD_MESH_IMPL_H
#define RENDERING_DETAIL_CLOD_MESH_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Detail/CollapseRecordArray.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class ObjectRegister;
	class ObjectLink;
	class Object;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ClodMeshImpl
	{
	public:
		using ClassType = ClodMeshImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectRegister = CoreTools::ObjectRegister;
		using ObjectLink = CoreTools::ObjectLink;
		using Object = CoreTools::Object;

	public:
		ClodMeshImpl() noexcept;		
		explicit ClodMeshImpl(const CollapseRecordArraySharedPtr& recordArray) noexcept;

		CLASS_INVARIANT_DECLARE;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;
		void Link(const CoreTools:: ObjectLinkSharedPtr& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;
 
		int GetNumRecords () const;
		int GetTargetRecord() const noexcept;
		void SetTargetRecord(int targetRecord) noexcept;	

		// ���θ��¡�Draw���������ô˸��£�������Ŀ���¼�ĵ�ǰֵ����TrianglesMesh������
		// �����ڲ���Ҫ��ʾ�����Ӧ�ó����ֶ����á�
		void SelectLevelOfDetail(VertexBufferSharedPtr vertexbuffer,IndexBufferSharedPtr indexbuffer,int targetRecord);

		 CORE_TOOLS_NAMES_IMPL_DECLARE;


	private:
		// ��ԱLODѡ��
		int m_CurrentRecord;
		int m_TargetRecord;
		CollapseRecordArraySharedPtr m_RecordArray;
	};
}

#endif // RENDERING_DETAIL_CLOD_MESH_IMPL_H
