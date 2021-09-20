// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:47)

#include "VisualTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "System/Helper/Helper.h"

CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, VisualTest);
CORE_TOOLS_RTTI_DEFINE(Rendering,VisualTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,VisualTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering,VisualTest); 

Rendering::VisualTest
	::VisualTest(VisualPrimitiveType type)
	:ParentType{ type }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualTest
	::VisualTest(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, 
	             const VertexBufferSharedPtr& vertexbuffer, 
				 const IndexBufferSharedPtr& indexbuffer) 
	:ParentType{ type, vertexformat, vertexbuffer, indexbuffer }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualTest
    ::~VisualTest()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,VisualTest) 

Rendering::VisualTest::ControllerInterfaceSharedPtr   Rendering::VisualTest
      ::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

    return ControllerInterfaceSharedPtr(new ClassType(*this));
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::VisualTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ControllerInterfaceSharedPtr(new ClassType(*this));
}
