// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:19)

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

		// 几何更新。Draw函数将调用此更新，并根据目标记录的当前值调整TrianglesMesh数量。
		// 可以在不需要显示网格的应用程序手动调用。
		void SelectLevelOfDetail(VertexBufferSharedPtr vertexbuffer,IndexBufferSharedPtr indexbuffer,int targetRecord);

		 CORE_TOOLS_NAMES_IMPL_DECLARE;


	private:
		// 成员LOD选择。
		int m_CurrentRecord;
		int m_TargetRecord;
		CollapseRecordArraySharedPtr m_RecordArray;
	};
}

#endif // RENDERING_DETAIL_CLOD_MESH_IMPL_H
