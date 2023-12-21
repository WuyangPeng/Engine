/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/12 15:09)

#include "BufferTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Resources/Buffers/BufferDetail.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, BufferTest)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BufferTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BufferTest);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, BufferTest);

Rendering::BufferTest::BufferTest(const std::string& name, GraphicsObjectType type)
    : ParentType{ name, type }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::BufferTest::BufferTest(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage)
    : ParentType{ name, numElements, elementSize, type, createStorage }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::BufferTest::BufferTest(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type)
    : ParentType{ name, numElements, elementSize, storage, type }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BufferTest)

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::BufferTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::GraphicsObject::RendererObjectSharedPtr Rendering::BufferTest::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_1;

    System::UnusedFunction(rendererTypes);

    THROW_EXCEPTION(SYSTEM_TEXT("BufferTest无法创建RendererObject。"))
}

void Rendering::BufferTest::CheckMember(const MemberLayout& memberLayout)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::CheckMember(memberLayout);
}

void Rendering::BufferTest::CheckMember(int index, const MemberLayout& memberLayout)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::CheckMember(index, memberLayout);
}
