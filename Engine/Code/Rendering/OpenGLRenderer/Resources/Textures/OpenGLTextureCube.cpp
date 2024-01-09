/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:39)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureCube.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

Rendering::OpenGLTextureCube::OpenGLTextureCube(const TextureCubeSharedPtr& textureCube, const std::string& name)
    : ParentType{ textureCube, name, TextureTarget::TextureCubeMap, TextureTargetBinding::BindingCube }
{
    SetGLHandle(System::GetGLGenTextures());
    SetGLBindTexture(TextureTarget::TextureCubeMap, ClassType::GetGLHandle());

    const auto width = textureCube->GetDimension(0);
    const auto height = textureCube->GetDimension(1);

    SetGLTexturesStorage2D(TextureTarget::TextureCubeMap, GetNumLevels(), GetInternalFormat(), width, height);

    Initialize();

    SetGLBindTexture(TextureTarget::TextureCubeMap, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTextureCube::~OpenGLTextureCube() noexcept
{
    System::SetGLDeleteTextures(ClassType::GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureCube)

Rendering::ConstTextureCubeSharedPtr Rendering::OpenGLTextureCube::GetTextureCube() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const TextureCube>(GetGraphicsObject());
}

bool Rendering::OpenGLTextureCube::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto texture = GetTexture();

    return texture && texture->HasMipMaps() && texture->WantAutoGenerateMipMaps();
}

void Rendering::OpenGLTextureCube::LoadTextureLevel(int item, int level, const ConstSpanIterator& data)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto texture = GetTexture();
        texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);

        const auto targetFace = GetCubeFaceTarget(item);

        SetGLTexturesSubImage2D(targetFace, level, 0, 0, width, height, GetExternalFormat(), GetExternalType(), data.GetData());
    }
}
