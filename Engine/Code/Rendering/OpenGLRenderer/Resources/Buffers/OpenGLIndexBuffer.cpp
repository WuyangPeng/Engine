/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 14:53)

#include "Rendering/RenderingExport.h"

#include "OpenGLIndexBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::OpenGLIndexBuffer::OpenGLIndexBuffer(const IndexBufferSharedPtr& buffer, const std::string& name)
    : ParentType{ buffer, name, BindBuffer::ElementArrayBuffer }
{
    ParentType::Initialize();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLIndexBuffer)

Rendering::ConstIndexBufferSharedPtr Rendering::OpenGLIndexBuffer::GetIndexBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const IndexBuffer>(GetGraphicsObject());
}

void Rendering::OpenGLIndexBuffer::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    SetGLBindBuffer(GetType(), GetGLHandle());
}

void Rendering::OpenGLIndexBuffer::Disable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    SetGLBindBuffer(GetType(), 0);
}
