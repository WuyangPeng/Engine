///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/25 18:49)

#include "Rendering/RenderingExport.h"

#include "OpenGLTexture1Array.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

Rendering::OpenGLTexture1Array::OpenGLTexture1Array(const Texture1DArraySharedPtr& texture1Array, const std::string& name)
    : ParentType{ texture1Array, name, TextureTarget::Texture1DArray, TextureTargetBinding::Binding1DArray }
{
    SetGLHandle(System::GetGLGenTextures());
    System::SetGLBindTexture(TextureTarget::Texture1DArray, GetGLHandle());

    const auto length = texture1Array->GetDimension(0);
    const auto numItems = texture1Array->GetNumItems();
    System::SetGLTexStorage2D(TextureTarget::Texture1DArray, GetNumLevels(), GetInternalFormat(), length, numItems);

    Initialize();

    System::SetGLBindTexture(TextureTarget::Texture1DArray, 0);

    CreateStaging();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLTexture1Array::~OpenGLTexture1Array() noexcept
{
    System::SetGLDeleteTextures(GetGLHandle());

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

    auto texture = GetTexture();

    return texture && texture->HasMipmaps() && texture->WantAutogenerateMipmaps();
}

void Rendering::OpenGLTexture1Array::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTexture1Array::LoadTextureLevel(int item, int level, const ConstSpanIterator& data)
{
    RENDERING_CLASS_IS_VALID_9;

    auto texture = GetTexture();
    if (texture && level < texture->GetNumLevels())
    {
        auto const length = texture->GetDimension(level, 0);

        System::SetGLTexSubImage2D(TextureTarget::Texture1DArray, level, 0, item, length, 1, GetExternalFormat(), GetExternalType(), &*data.GetCurrent());
    }
}
