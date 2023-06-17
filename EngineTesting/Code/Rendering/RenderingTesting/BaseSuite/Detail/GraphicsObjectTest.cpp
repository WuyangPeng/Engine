///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:06)

#include "GraphicsObjectTest.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, GraphicsObjectTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, GraphicsObjectTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, GraphicsObjectTest);

Rendering::GraphicsObjectTest::GraphicsObjectTestSharedPtr Rendering::GraphicsObjectTest::Create(const std::string& name, GraphicsObjectType type)
{
    return std::make_shared<GraphicsObjectTest>(GraphicsObjectTestCreate::Init, name, type);
}

Rendering::GraphicsObjectTest::GraphicsObjectTest(GraphicsObjectTestCreate graphicsObjectTestCreate, const std::string& name, GraphicsObjectType type)
    : ParentType{ name, type }
{
    System::UnusedFunction(graphicsObjectTestCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GraphicsObjectTest);

Rendering::GraphicsObjectTest::GraphicsObjectTest(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::GraphicsObjectTest::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

int64_t Rendering::GraphicsObjectTest::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::GraphicsObjectTest::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::GraphicsObjectTest::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::GraphicsObjectTest::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::GraphicsObjectTest::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::GraphicsObjectTest::ObjectInterfaceSharedPtr Rendering::GraphicsObjectTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::GraphicsObjectTest::RendererObjectSharedPtr Rendering::GraphicsObjectTest::CreateRendererObject(MAYBE_UNUSED RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("RendererObject对象不存在。"));
}