///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/26 10:47)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureCubeArray.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

Rendering::OpenGLTextureCubeArray::OpenGLTextureCubeArray(const TextureCubeArraySharedPtr& textureCubeArray, const std::string& name)
    : ParentType{ textureCubeArray, name, TextureTarget::TextureCubeMapArray, TextureTargetBinding::BindingCubeArray }
{
    SetGLHandle(System::GetGLGenTextures());
    System::SetGLBindTexture(TextureTarget::TextureCubeMapArray, GetGLHandle());

    const auto width = textureCubeArray->GetDimension(0);
    const auto height = textureCubeArray->GetDimension(1);
    const auto numItems = textureCubeArray->GetNumItems();
    const auto numCubes = textureCubeArray->GetNumCubes();

    System::SetGLTexStorage3D(TextureTarget::TextureCubeMapArray, GetNumLevels(), GetInternalFormat(), width, height, numItems);

    System::SetGLPixelStore(System::PixelStore::UnpackAlignment, 1);
    System::SetGLPixelStore(System::PixelStore::PackAlignment, 1);

    System::SetGLTexParameter(TextureTarget::TextureCubeMapArray, System::TextureParameter::TextureBaseLevel, 0);
    System::SetGLTexParameter(TextureTarget::TextureCubeMapArray, System::TextureParameter::TextureMaxLevel, GetNumLevels() - 1);

    constexpr auto cubeFaceCount = System::EnumCastUnderlying(CubeFaceType::Count);

    auto texture = boost::polymorphic_pointer_cast<const TextureCubeArray>(GetGraphicsObject());

    if (CanAutoGenerateMipmaps())
    {
        for (auto cube = 0; cube < numCubes; ++cube)
        {
            for (auto face = 0; face < cubeFaceCount; ++face)
            {
                const auto data = texture->GetDataForCubeArray(cube, face, 0);

                const auto item = textureCubeArray->GetItemIndexFor(cube, face);
                LoadTextureLevel(item, 0, data);
            }
        }
        GenerateMipmaps();
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
                    LoadTextureLevel(item, level, data);
                }
            }
        }
    }

    System::SetGLBindTexture(TextureTarget::TextureCubeMapArray, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTextureCubeArray::~OpenGLTextureCubeArray() noexcept
{
    System::SetGLDeleteTextures(GetGLHandle());

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

    auto texture = GetTexture();

    return texture && texture->HasMipmaps() && texture->WantAutogenerateMipmaps();
}

void Rendering::OpenGLTextureCubeArray::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTextureCubeArray::LoadTextureLevel(int item, int level, const ConstSpanIterator& data)
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = boost::polymorphic_pointer_cast<const TextureCubeArray>(GetGraphicsObject());
    if (texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);

        auto const cube = texture->GetCubeIndexFor(item);
        auto const face = texture->GetFaceIndexFor(item);

        const auto targetFace = GetCubeFaceTarget(face);

        System::SetGLTexSubImage3D(targetFace, level, 0, 0, cube, width, height, 1, GetExternalFormat(), GetExternalType(), &*data.GetCurrent());
    }
}
