/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 17:44)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture1.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

Rendering::OpenGLTexture1::OpenGLTexture1(const Texture1DSharedPtr& texture1D, const std::string& name)
    : ParentType{ texture1D, name, TextureTarget::Texture1D, TextureTargetBinding::Binding1D }
{
    SetGLHandle(System::GetGLGenTextures());
    SetGLBindTexture(TextureTarget::Texture1D, ClassType::GetGLHandle());

    const auto length = texture1D->GetDimension(0);
    SetGLTexturesStorage1D(TextureTarget::Texture1D, GetNumLevels(), GetInternalFormat(), length);

    Initialize();

    SetGLBindTexture(TextureTarget::Texture1D, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture1::~OpenGLTexture1() noexcept
{
    System::SetGLDeleteTextures(ClassType::GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture1)

Rendering::ConstTexture1DSharedPtr Rendering::OpenGLTexture1::GetTexture1D() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture1D>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture1::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto texture = GetTexture();

    return texture && texture->HasMipMaps() && texture->WantAutoGenerateMipMaps();
}

void Rendering::OpenGLTexture1::LoadTextureLevel(int level, const ConstSpanIterator& data)
{
    if (const auto texture = GetTexture();
        texture != nullptr && level < texture->GetNumLevels())
    {
        const auto length = texture->GetDimension(level, 0);

        SetGLTexturesSubImage1D(TextureTarget::Texture1D, level, 0, length, GetExternalFormat(), GetExternalType(), data.GetData());
    }
}
