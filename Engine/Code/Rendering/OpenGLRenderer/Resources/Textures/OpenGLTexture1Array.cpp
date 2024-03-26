/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:15)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture1Array.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

Rendering::OpenGLTexture1Array::OpenGLTexture1Array(const Texture1DArraySharedPtr& texture1Array, const std::string& name)
    : ParentType{ texture1Array, name, TextureTarget::Texture1DArray, TextureTargetBinding::Binding1DArray }
{
    SetGLHandle(System::GetGLGenTextures());
    SetGLBindTexture(TextureTarget::Texture1DArray, ClassType::GetGLHandle());

    const auto length = texture1Array->GetDimension(0);
    const auto numItems = texture1Array->GetNumItems();
    SetGLTexturesStorage2D(TextureTarget::Texture1DArray, GetNumLevels(), GetInternalFormat(), length, numItems);

    Initialize();

    SetGLBindTexture(TextureTarget::Texture1DArray, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture1Array::~OpenGLTexture1Array() noexcept
{
    System::SetGLDeleteTextures(ClassType::GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture1Array)

Rendering::ConstTexture1DArraySharedPtr Rendering::OpenGLTexture1Array::GetTexture1DArray() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture1DArray>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture1Array::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto texture = GetTexture();

    return texture && texture->HasMipMaps() && texture->WantAutoGenerateMipMaps();
}

void Rendering::OpenGLTexture1Array::LoadTextureLevel(int item, int level, const ConstSpanIterator& data)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto texture = GetTexture();
        texture && level < texture->GetNumLevels())
    {
        auto const length = texture->GetDimension(level, 0);

        SetGLTexturesSubImage2D(TextureTarget::Texture1DArray, level, 0, item, length, 1, GetExternalFormat(), GetExternalType(), data.GetData());
    }
}