/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/12 15:09)

#include "ResourcesTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, ResourcesTest)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ResourcesTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ResourcesTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ResourcesTest);

Rendering::ResourcesTest::ResourcesTest(const std::string& name, GraphicsObjectType type)
    : ParentType{ name, type }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ResourcesTest::ResourcesTest(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage)
    : ParentType{ name, numElements, elementSize, type, createStorage }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ResourcesTest::ResourcesTest(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type)
    : ParentType{ name, numElements, elementSize, storage, type }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ResourcesTest)

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::ResourcesTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::GraphicsObject::RendererObjectSharedPtr Rendering::ResourcesTest::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(rendererTypes);

    THROW_EXCEPTION(SYSTEM_TEXT("ResourcesTest无法创建RendererObject。"))
}
