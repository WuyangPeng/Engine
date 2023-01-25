///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/26 10:47)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureCube.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "System/OpenGL/OpenGLTextures.h"

Rendering::OpenGLTextureCube::OpenGLTextureCube(const TextureCubeSharedPtr& textureCube, const std::string& name)
    : ParentType{ textureCube, name, TextureTarget::TextureCubeMap, TextureTargetBinding::BindingCube }
{
    SetGLHandle(System::GetGLGenTextures());
    System::SetGLBindTexture(TextureTarget::TextureCubeMap, GetGLHandle());

    const auto width = textureCube->GetDimension(0);
    const auto height = textureCube->GetDimension(1);

    System::SetGLTexturesStorage2D(TextureTarget::TextureCubeMap, GetNumLevels(), GetInternalFormat(), width, height);

    Initialize();

    System::SetGLBindTexture(TextureTarget::TextureCubeMap, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTextureCube::~OpenGLTextureCube() noexcept
{
    System::SetGLDeleteTextures(GetGLHandle());

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

    auto texture = GetTexture();

    return texture && texture->HasMipmaps() && texture->WantAutogenerateMipmaps();
}

void Rendering::OpenGLTextureCube::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTextureCube::LoadTextureLevel(int item, int level, const ConstSpanIterator& data)
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();
    if (texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);

        const auto targetFace = GetCubeFaceTarget(item);

        System::SetGLTexturesSubImage2D(targetFace, level, 0, 0, width, height, GetExternalFormat(), GetExternalType(), &*data.GetCurrent());
    }
}
