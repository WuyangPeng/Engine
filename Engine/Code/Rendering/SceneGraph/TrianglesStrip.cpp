// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 18:39)

#include "Rendering/RenderingExport.h"

#include "TrianglesStrip.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TrianglesStrip);

Rendering::TrianglesStrip
	::TrianglesStrip(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer) 
	:ParentType{ VisualPrimitiveType::TriangleStrip,vertexformat,vertexbuffer,indexbuffer }
{
	RENDERING_ASSERTION_1(indexbuffer->GetNumElements() >= vertexbuffer->GetNumElements(),"����������û���㹻��Ԫ��\n");

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TrianglesStrip
	::TrianglesStrip(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,int indexSize)
	:ParentType{ VisualPrimitiveType::TriangleStrip, vertexformat, vertexbuffer, IndexBufferSmartPointer() }
{
	auto numVertices = vertexbuffer->GetNumElements();

	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numVertices, indexSize) };
	indexBuffer->InitIndexBuffer();		
	SetIndexBuffer(indexBuffer);
		
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TrianglesStrip
	::~TrianglesStrip()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TrianglesStrip)

int Rendering::TrianglesStrip
	::GetNumTriangles() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return GetConstIndexBuffer()->GetNumElements() - 2;  
}

const Rendering::TriangleIndex 
	Rendering::TrianglesStrip
	::GetTriangle(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < GetNumTriangles())
	{
		auto indices = reinterpret_cast<const int*>(GetConstIndexBuffer()->GetReadOnlyData());
		auto firstIndex = indices[index];
		auto secondIndex = -1;
		auto thirdIndex = -1;
		if (index & 1)
		{
			secondIndex = indices[index + 2];
			thirdIndex = indices[index + 1];
		}
		else
		{
			secondIndex = indices[index + 1];
			thirdIndex = indices[index + 2];
		}

		// �˻������α��ٶ�Ϊ��������������ǵش���
		// ���Ǳ���Ϊ����Ч�ġ�
		if (firstIndex != secondIndex && firstIndex != thirdIndex && secondIndex != thirdIndex)
		{
			return TriangleIndex{ firstIndex, secondIndex, thirdIndex };
		}
		else
		{
			THROW_EXCEPTION(SYSTEM_TEXT("�����ζ�����������Ч��"));
		}
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ������ζ�������"));
	}	 
}

 Rendering::ControllerInterfaceSmartPointer 
	 Rendering::TrianglesStrip
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ NEW0 ClassType(*this) };
} 