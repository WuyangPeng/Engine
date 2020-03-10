// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-2017
//
// 引擎版本：1.0.0.0 (2017/12/29 23:07)

#include "Rendering/RenderingExport.h"

#include "TrianglesFan.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TrianglesFan);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TrianglesFan);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TrianglesFan);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TrianglesFan);

Rendering::TrianglesFan
	::TrianglesFan(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer, const IndexBufferSmartPointer& indexbuffer) 
	:ParentType{ VisualPrimitiveType::TriangleFan,vertexformat,vertexbuffer,indexbuffer }
{
	RENDERING_ASSERTION_1(indexbuffer->GetNumElements() >= vertexbuffer->GetNumElements(),"索引缓冲区没有足够的元素\n");

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TrianglesFan
	::TrianglesFan(const VertexFormatSmartPointer& vertexformat, const VertexBufferSmartPointer& vertexbuffer,int indexSize)
	:ParentType{ VisualPrimitiveType::TriangleFan, vertexformat, vertexbuffer, IndexBufferSmartPointer() }
{
	auto numVertices = vertexbuffer->GetNumElements();

	IndexBufferSmartPointer indexBuffer{ NEW0 IndexBuffer(numVertices, indexSize) };
	indexBuffer->InitIndexBuffer();		
	SetIndexBuffer(indexBuffer);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TrianglesFan
	::~TrianglesFan()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TrianglesFan)

int Rendering::TrianglesFan
	::GetNumTriangles() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return GetConstIndexBuffer()->GetNumElements() - 2;
}

const Rendering::TriangleIndex 
	Rendering::TrianglesFan
	::GetTriangle(int index) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < GetNumTriangles())
	{
		auto indices = reinterpret_cast<const int*>(GetConstIndexBuffer()->GetReadOnlyData());
		auto firstIndex = indices[0];
		auto secondIndex = indices[index + 1];
		auto thirdIndex = indices[index + 2];

		return TriangleIndex{ firstIndex,secondIndex,thirdIndex };
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("未找到三角形顶点索引"));
	}	 
}

Rendering::ControllerInterfaceSmartPointer 
	Rendering::TrianglesFan
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ NEW0 ClassType(*this) };
} 