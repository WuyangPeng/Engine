///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/16 10:45)

#include "Rendering/RenderingExport.h"

#include "TextureRenderTarget.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureRenderTarget);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureRenderTarget);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextureRenderTarget);

Rendering::TextureRenderTarget::TextureRenderTarget(DataFormatType format, int width, int height, bool hasMipmaps)
    : ParentType{ format, width, height, hasMipmaps, GraphicsObjectType::TextureRenderTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureRenderTarget)

Rendering::TextureRenderTarget::TextureRenderTarget(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int64_t Rendering::TextureRenderTarget::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::TextureRenderTarget::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TextureRenderTarget::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::TextureRenderTarget::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::TextureRenderTarget::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

int Rendering::TextureRenderTarget::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::GetStreamingSize();
}

Rendering::TextureSharedPtr Rendering::TextureRenderTarget::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TextureRenderTarget::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}