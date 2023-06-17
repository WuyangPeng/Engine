///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:27)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureDepthStencil.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

Rendering::OpenGLTextureDepthStencil::OpenGLTextureDepthStencil(const TextureDepthStencilSharedPtr& textureDepthStencil, const std::string& name)
    : ParentType{ textureDepthStencil, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureDepthStencil)

Rendering::ConstTextureDepthStencilSharedPtr Rendering::OpenGLTextureDepthStencil::GetTextureDepthStencil() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const TextureDepthStencil>(GetGraphicsObject());
}

bool Rendering::OpenGLTextureDepthStencil::CanAutoGenerateMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return false;
}
