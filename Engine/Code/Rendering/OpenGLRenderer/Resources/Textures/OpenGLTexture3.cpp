/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:29)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture3.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

Rendering::OpenGLTexture3::OpenGLTexture3(const Texture3DSharedPtr& texture3D, const std::string& name)
    : ParentType{ texture3D, name, TextureTarget::Texture3D, TextureTargetBinding::Binding3D }
{
    SetGLHandle(System::GetGLGenTextures());
    SetGLBindTexture(TextureTarget::Texture3D, ClassType::GetGLHandle());

    const auto width = texture3D->GetDimension(0);
    const auto height = texture3D->GetDimension(1);
    const auto depth = texture3D->GetDimension(2);
    SetGLTexturesStorage3D(TextureTarget::Texture3D, GetNumLevels(), GetInternalFormat(), width, height, depth);

    Initialize();

    SetGLBindTexture(TextureTarget::Texture3D, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture3::~OpenGLTexture3() noexcept
{
    System::SetGLDeleteTextures(ClassType::GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture3)

Rendering::ConstTexture3DSharedPtr Rendering::OpenGLTexture3::GetTexture3D() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture3D>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture3::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto texture = GetTexture();

    return texture &&
           texture->HasMipMaps() &&
           texture->WantAutoGenerateMipMaps();
}

void Rendering::OpenGLTexture3::LoadTextureLevel(int level, const ConstSpanIterator& data)
{
    if (const auto texture = GetTexture();
        texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);
        const auto depth = texture->GetDimension(level, 2);

        SetGLTexturesSubImage3D(TextureTarget::Texture2D, level, 0, 0, 0, width, height, depth, GetExternalFormat(), GetExternalType(), data.GetData());
    }
}
