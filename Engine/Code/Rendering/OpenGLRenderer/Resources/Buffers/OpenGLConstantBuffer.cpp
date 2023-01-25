///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/20 21:55)

#include "Rendering/RenderingExport.h"

#include "OpenGLConstantBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "System/OpenGL/OpenGLBuffers.h"

Rendering::OpenGLConstantBuffer::OpenGLConstantBuffer(const ConstantBufferSharedPtr& buffer, const std::string& name)
    : ParentType{ buffer, name, BindBuffer::UniformBuffer }
{
    Initialize();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLConstantBuffer)

Rendering::ConstConstantBufferSharedPtr Rendering::OpenGLConstantBuffer::GetConstantBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const ConstantBuffer>(GetGraphicsObject());
}

void Rendering::OpenGLConstantBuffer::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLConstantBuffer::AttachToUnit(OpenGLInt uniformBufferUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLBindBufferBase(BindBuffer::UniformBuffer, uniformBufferUnit, GetGLHandle());
}
