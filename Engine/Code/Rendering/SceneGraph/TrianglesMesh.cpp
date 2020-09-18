// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/22 18:38)

#include "Rendering/RenderingExport.h"

#include "TrianglesMesh.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH 
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
 #include SYSTEM_WARNING_DISABLE(26426)
 #include SYSTEM_WARNING_DISABLE(26486)
 #include SYSTEM_WARNING_DISABLE(26481)
 #include SYSTEM_WARNING_DISABLE(26489)
 #include SYSTEM_WARNING_DISABLE(26490)
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
	const	auto firstIndex = *indices++;
                const auto secondIndex = *indices++;
        const auto thirdIndex = *indices;

		return TriangleIndex{ firstIndex,secondIndex,thirdIndex };
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Î´ÕÒµ½Èý½ÇÐÎ¶¥µãË÷Òý"s));
	}	 
}

Rendering::ControllerInterfaceSmartPointer Rendering::TrianglesMesh
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSmartPointer{ std::make_shared<ClassType>(*this) };
} 

CoreTools::ObjectInterfaceSharedPtr Rendering::TrianglesMesh::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP
