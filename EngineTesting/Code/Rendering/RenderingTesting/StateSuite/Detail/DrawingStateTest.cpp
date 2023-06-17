///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:02)

#include "DrawingStateTest.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, DrawingStateTest);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DrawingStateTest);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DrawingStateTest);

Rendering::DrawingStateTest::DrawingStateTestSharedPtr Rendering::DrawingStateTest::Create(const std::string& name, GraphicsObjectType type)
{
    return std::make_shared<DrawingStateTest>(DrawingStateTestCreate::Init, name, type);
}

Rendering::DrawingStateTest::DrawingStateTest(DrawingStateTestCreate drawingStateTestCreate, const std::string& name, GraphicsObjectType type)
    : ParentType{ name, type }
{
    System::UnusedFunction(drawingStateTestCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DrawingStateTest);

Rendering::DrawingStateTest::DrawingStateTest(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::DrawingStateTest::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

int64_t Rendering::DrawingStateTest::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::DrawingStateTest::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::DrawingStateTest::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::DrawingStateTest::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::DrawingStateTest::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::DrawingStateTest::ObjectInterfaceSharedPtr Rendering::DrawingStateTest::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}
