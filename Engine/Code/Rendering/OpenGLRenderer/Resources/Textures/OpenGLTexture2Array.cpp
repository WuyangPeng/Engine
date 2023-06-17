///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture2Array.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

Rendering::OpenGLTexture2Array::OpenGLTexture2Array(const Texture2DArraySharedPtr& texture2Array, const std::string& name)
    : ParentType{ texture2Array, name, TextureTarget::Texture2DArray, TextureTargetBinding::Binding2DArray }
{
    SetGLHandle(System::GetGLGenTextures());
    System::SetGLBindTexture(TextureTarget::Texture2DArray, GetGLHandle());

    const auto width = texture2Array->GetDimension(0);
    const auto height = texture2Array->GetDimension(1);
    const auto numItems = texture2Array->GetNumItems();

    System::SetGLTexturesStorage3D(TextureTarget::Texture2DArray, GetNumLevels(), GetInternalFormat(), width, height, numItems);

    Initialize();

    System::SetGLBindTexture(TextureTarget::Texture2DArray, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture2Array::~OpenGLTexture2Array() noexcept
{
    System::SetGLDeleteTextures(GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTexture2Array)

Rendering::ConstTexture2DArraySharedPtr Rendering::OpenGLTexture2Array::GetTexture2DArray() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Texture2DArray>(GetGraphicsObject());
}

bool Rendering::OpenGLTexture2Array::CanAutoGenerateMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto texture = GetTexture();

    return texture && texture->HasMipmaps() && texture->WantAutogenerateMipmaps();
}

void Rendering::OpenGLTexture2Array::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTexture2Array::LoadTextureLevel(int item, int level, const ConstSpanIterator& data)
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();
    if (texture && level < texture->GetNumLevels())
    {
        const auto width = texture->GetDimension(level, 0);
        const auto height = texture->GetDimension(level, 1);

        System::SetGLTexturesSubImage3D(TextureTarget::Texture2DArray, level, 0, 0, item, width, height, 1, GetExternalFormat(), GetExternalType(), &*data.GetCurrent());
    }
}
