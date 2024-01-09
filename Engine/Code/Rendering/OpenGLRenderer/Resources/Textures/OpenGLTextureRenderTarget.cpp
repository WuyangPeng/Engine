/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/08 19:48)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureRenderTarget.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

Rendering::OpenGLTextureRenderTarget::OpenGLTextureRenderTarget(const TextureRenderTargetSharedPtr& textureRenderTarget, const std::string& name)
    : ParentType{ textureRenderTarget, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureRenderTarget)

Rendering::ConstTextureRenderTargetSharedPtr Rendering::OpenGLTextureRenderTarget::GetTextureRenderTarget() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const TextureRenderTarget>(GetGraphicsObject());
}

bool Rendering::OpenGLTextureRenderTarget::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto texture = GetTexture();

    return texture && texture->HasMipMaps() && texture->WantAutoGenerateMipMaps();
}
