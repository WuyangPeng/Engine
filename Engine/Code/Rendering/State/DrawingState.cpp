/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:20)

#include "Rendering/RenderingExport.h"

#include "DrawingState.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/NullRendererObject.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, DrawingState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DrawingState);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, DrawingState);

Rendering::DrawingState::DrawingState(const std::string& name, GraphicsObjectType type)
    : ParentType{ name, type }
{
    CheckDrawingState();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::DrawingState::CheckDrawingState()
{
    if (!IsDrawingState())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GraphicsObject类型错误。"s));
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DrawingState)

Rendering::DrawingState::DrawingState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::DrawingState::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

int64_t Rendering::DrawingState::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::DrawingState::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::DrawingState::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::DrawingState::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::DrawingState::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CheckDrawingState();
}

Rendering::DrawingState::RendererObjectSharedPtr Rendering::DrawingState::CreateRendererObject(MAYBE_UNUSED RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_9;

    return std::make_shared<NullRendererObject>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
}