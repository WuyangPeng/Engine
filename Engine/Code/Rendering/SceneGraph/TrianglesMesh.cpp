// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 18:38)

#include "Rendering/RenderingExport.h"

#include "TrianglesMesh.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TrianglesMesh);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TrianglesMesh);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TrianglesMesh);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TrianglesMesh);

Rendering::TrianglesMesh
	::TrianglesMesh(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer, const IndexBufferSmartPointer& indexbuffer) 
	:ParentType{ VisualPrimitiveType::TriangleMesh,vertexformat,vertexbuffer,indexbuffer }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TrianglesMesh
	::~TrianglesMesh()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TrianglesMesh)

int Rendering::TrianglesMesh
	::GetNumTriangles() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return GetConstIndexBuffer()->GetNumElements() / 3;
}

const Rendering::TriangleIndex 
	Rendering::TrianglesMesh
	::GetTriangle(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < GetNumTriangles())
	{
		auto indices = 3 * index + reinterpret_cast<const int*>(GetConstIndexBuffer()->GetReadOnlyData());
		auto firstIndex = *indices++;
		auto secondIndex = *indices++;
		auto thirdIndex = *indices;

		return TriangleIndex{ firstIndex,secondIndex,thirdIndex };
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ������ζ�������"));
	}	 
}

Rendering::ControllerInterfaceSmartPointer Rendering::TrianglesMesh
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ NEW0 ClassType(*this) };
} 

 
