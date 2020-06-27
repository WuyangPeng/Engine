// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:28)

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
		// ClodMesh将复制“网格”的索引缓冲器，
		// 因为它需要能够独立地更新两个索引，
		// 或更多个ClodMesh对象共享相同的顶点缓冲器和折叠的记录。
		explicit ClodMesh(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,
			              const IndexBufferSmartPointer& indexbuffer,const CollapseRecordArraySmartPointer& recordArray);
		virtual ~ClodMesh();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ClodMesh);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
		
		int GetNumRecords () const;
		
		int GetTargetRecord() const;
		void SetTargetRecord(int targetRecord);
		
		// LOD选择是基于应用手动选择。
		// 要使用相机距离或屏幕空间的覆盖范围，
		// 从ClodMesh派生类和重写“GetAutomatedTargetRecord”。
	
		// 获取目标记录。虚拟函数可以由派生类重写，以获得目标所需的自动变更。
		virtual int GetAutomatedTargetRecord() const;
		
		// 几何更新。Draw函数将调用此更新，并根据目标记录的当前值调整TrianglesMesh数量。
		// 可以在不需要显示网格的应用程序手动调用。
		void SelectLevelOfDetail ();

		virtual ControllerInterfaceSmartPointer Clone() const override;
		
	protected:
		// 支持分级裁剪。
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
