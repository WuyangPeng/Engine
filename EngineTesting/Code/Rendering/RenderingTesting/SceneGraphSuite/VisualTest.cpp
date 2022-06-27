///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 15:42)

#include "VisualTest.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, VisualTest);
CORE_TOOLS_RTTI_DEFINE(Rendering, VisualTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VisualTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VisualTest);

Rendering::VisualTest::VisualTest(VisualPrimitiveType type)
    : ParentType{ type }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualTest::VisualTest(VisualPrimitiveType type,
                                  const VertexFormatSharedPtr& vertexformat,
                                  const VertexBufferSharedPtr& vertexbuffer,
                                  const IndexBufferSharedPtr& indexbuffer)
    : ParentType{ type, vertexformat, vertexbuffer, indexbuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualTest)

Rendering::VisualTest::ControllerInterfaceSharedPtr Rendering::VisualTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::VisualTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
