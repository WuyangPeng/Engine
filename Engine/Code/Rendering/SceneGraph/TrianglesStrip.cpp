// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 18:39)

#include "Rendering/RenderingExport.h"

#include "TrianglesStrip.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TrianglesStrip);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, TrianglesStrip);

Rendering::TrianglesStrip
	::TrianglesStrip(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer) 
	:ParentType{ VisualPrimitiveType::TriangleStrip,vertexformat,vertexbuffer,indexbuffer }
{
	RENDERING_ASSERTION_1(indexbuffer->GetNumElements() >= vertexbuffer->GetNumElements(),"索引缓冲区没有足够的元素\n");

	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TrianglesStrip
	::TrianglesStrip(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,int indexSize)
	:ParentType{ VisualPrimitiveType::TriangleStrip, vertexformat, vertexbuffer, IndexBufferSmartPointer() }
{
	const auto numVertices = vertexbuffer->GetNumElements();

	IndexBufferSmartPointer indexBuffer{ std::make_shared < IndexBuffer>(numVertices, indexSize) };
	indexBuffer->InitIndexBuffer();		
	SetIndexBuffer(indexBuffer);
		
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
            const auto firstIndex = indices[index];
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

		// 退化三角形被假定为互换和添加在三角地带。
		// 他们被认为是无效的。
		if (firstIndex != secondIndex && firstIndex != thirdIndex && secondIndex != thirdIndex)
		{
			return TriangleIndex{ firstIndex, secondIndex, thirdIndex };
		}
		else
		{
			THROW_EXCEPTION(SYSTEM_TEXT("三角形顶点索引是无效的"s));
		}
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("未找到三角形顶点索引"s));
	}	 
}

 Rendering::ControllerInterfaceSmartPointer 
	 Rendering::TrianglesStrip
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ std::make_shared<ClassType>(*this) };
}
 #include STSTEM_WARNING_POP