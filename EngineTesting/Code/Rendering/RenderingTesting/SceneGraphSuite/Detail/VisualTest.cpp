/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/20 16:24)

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

Rendering::VisualTest::VisualTest(const std::string& name)
    : ParentType{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VisualTest::VisualTest(const std::string& name,
                                  const VertexFormatSharedPtr& vertexFormat,
                                  const VertexBufferSharedPtr& vertexBuffer,
                                  const IndexBufferSharedPtr& indexBuffer)
    : ParentType{ name, vertexFormat, vertexBuffer, indexBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualTest)

Rendering::VisualTest::ControllerSharedPtr Rendering::VisualTest::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::VisualTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}
