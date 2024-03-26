/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:43)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureCubeArray.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

Rendering::OpenGLTextureCubeArray::OpenGLTextureCubeArray(const TextureCubeArraySharedPtr& textureCubeArray, const std::string& name)
    : ParentType{ textureCubeArray, name, TextureTarget::TextureCubeMapArray, TextureTargetBinding::BindingCubeArray }
{
    SetGLHandle(System::GetGLGenTextures());
    SetGLBindTexture(TextureTarget::TextureCubeMapArray, ClassType::GetGLHandle());

    const auto width = textureCubeArray->GetDimension(0);
    const auto height = textureCubeArray->GetDimension(1);
    const auto numItems = textureCubeArray->GetNumItems();
    const auto numCubes = textureCubeArray->GetNumCubes();

    SetGLTexturesStorage3D(TextureTarget::TextureCubeMapArray, GetNumLevels(), GetInternalFormat(), width, height, numItems);

    SetGLPixelStore(System::PixelStore::UnpackAlignment, 1);
    SetGLPixelStore(System::PixelStore::PackAlignment, 1);

    SetGLTexturesParameter(TextureTarget::TextureCubeMapArray, System::TextureParameter::TextureBaseLevel, 0);
    SetGLTexturesParameter(TextureTarget::TextureCubeMapArray, System::TextureParameter::TextureMaxLevel, GetNumLevels() - 1);

    constexpr auto cubeFaceCount = System::EnumCastUnderlying(CubeFaceType::Count);

    const auto texture = boost::polymorphic_pointer_cast<const TextureCubeArray>(GetGraphicsObject());

    if (ClassType::CanAutoGenerateMipmaps())
    {
        for (auto cube = 0; cube < numCubes; ++cube)
        {
            for (auto face = 0; face < cubeFaceCount; ++face)
            {
                const auto data = texture->GetDataForCubeArray(cube, face, 0);

                const auto item = textureCubeArray->GetItemIndexFor(cube, face);
                ClassType::LoadTextureLevel(item, 0, data);
            }
        }
        ClassType::GenerateMipmaps();
    }
    else
    {
        for (auto cube = 0; cube < numCubes; ++cube)
        {
            for (auto face = 0; face < cubeFaceCount; ++face)
            {
                for (auto level = 0; level < GetNumLevels(); ++level)
                {
                    const auto data = texture->GetDataForCubeArray(cube, face, level);

                    const auto item = textureCubeArray->GetItemIndexFor(cube, face);
                    ClassType::LoadTextureLevel(item, level, data);
                }
            }
        }
    }

    SetGLBindTexture(TextureTarget::TextureCubeMapArray, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTextureCubeArray::~OpenGLTextureCubeArray() noexcept
{
    System::SetGLDeleteTextures(ClassType::GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureCubeArray)

Rendering::ConstTextureCubeArraySharedPtr Rendering::OpenGLTextureCubeArray::GetTextureCubeArray() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const TextureCubeArray>(GetGraphicsObject());
}

bool Rendering::OpenGLTextureCubeArray::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto texture = GetTexture();

    return texture && texture->HasMipMaps() && texture->WantAutoGenerateMipMaps();
}

void Rendering::OpenGLTextureCubeArray::LoadTextureLevel(int item, int level, const ConstSpanIterator& data)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto texture = GetTextureCubeArray();
        texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);

        auto const cube = texture->GetCubeIndexFor(item);

        SetGLTexturesSubImage3D(TextureTarget::TextureCubeMapArray, level, 0, 0, cube, width, height, 1, GetExternalFormat(), GetExternalType(), data.GetData());
    }
}
