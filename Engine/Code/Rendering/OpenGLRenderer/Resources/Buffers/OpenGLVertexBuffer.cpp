///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/20 23:09)

#include "Rendering/RenderingExport.h"

#include "OpenGLVertexBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::OpenGLVertexBuffer::OpenGLVertexBuffer(const VertexBufferSharedPtr& buffer, const std::string& name)
    : ParentType{ buffer, name, BindBuffer::ArrayBuffer }
{
    Initialize();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLVertexBuffer)

Rendering::ConstVertexBufferSharedPtr Rendering::OpenGLVertexBuffer::GetVertexBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const VertexBuffer>(GetGraphicsObject());
}

void Rendering::OpenGLVertexBuffer::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}
