/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:23)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture2.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

Rendering::OpenGLTexture2::OpenGLTexture2(const Texture2DSharedPtr& texture2D, const std::string& name)
    : ParentType{ texture2D, name, TextureTarget::Texture2D, TextureTargetBinding::Binding2D }
{
    SetGLHandle(System::GetGLGenTextures());
    SetGLBindTexture(TextureTarget::Texture2D, ClassType::GetGLHandle());

    const auto width = texture2D->GetDimension(0);
    const auto height = texture2D->GetDimension(1);
    SetGLTexturesStorage2D(TextureTarget::Texture2D, GetNumLevels(), GetInternalFormat(), width, height);

    Initialize();

    SetGLBindTexture(TextureTarget::Texture2D, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture2::~OpenGLTexture2() noexcept
{
    System::SetGLDeleteTextures(ClassType::GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture2)

Rendering::ConstTexture2DSharedPtr Rendering::OpenGLTexture2::GetTexture2D() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture2D>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture2::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto texture = GetTexture2D();

    return texture &&
           texture->HasMipMaps() &&
           texture->WantAutoGenerateMipMaps() &&
           !texture->IsShared();
}

void Rendering::OpenGLTexture2::LoadTextureLevel(int level, const ConstSpanIterator& data)
{
    if (const auto texture = GetTexture();
        texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);

        SetGLTexturesSubImage2D(TextureTarget::Texture2D, level, 0, 0, width, height, GetExternalFormat(), GetExternalType(), data.GetData());
    }
}
