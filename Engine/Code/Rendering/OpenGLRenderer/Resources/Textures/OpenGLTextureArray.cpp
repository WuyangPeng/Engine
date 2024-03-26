/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:31)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureArray.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/OpenGLRenderer/Detail/Resources/Textures/OpenGLTextureSingleImpl.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OpenGLTextureArray)

Rendering::OpenGLTextureArray::OpenGLTextureArray(const TextureArraySharedPtr& textureArray, const std::string& name, TextureTarget target, TextureTargetBinding targetBinding)
    : ParentType{ textureArray, name, target, targetBinding }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLTextureArray)

Rendering::OpenGLTextureArray::~OpenGLTextureArray() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::DeleteBuffers);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::OpenGLTextureArray::DeleteBuffers() const
{
    for (auto level = 0; level < GetNumLevels(); ++level)
    {
        System::SetGLDeleteBuffers(impl->GetLevelPixelUnpackBuffer(level));
        System::SetGLDeleteBuffers(impl->GetLevelPixelPackBuffer(level));
    }
}

Rendering::ConstTextureArraySharedPtr Rendering::OpenGLTextureArray::GetTextureArray() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const TextureArray>(GetGraphicsObject());
}

Rendering::TextureArraySharedPtr Rendering::OpenGLTextureArray::GetTextureArray()
{
    RENDERING_CLASS_IS_VALID_9;

    return boost::polymorphic_pointer_cast<TextureArray>(GetGraphicsObject());
}

void Rendering::OpenGLTextureArray::Initialize()
{
    const auto prevBinding = GetGLInteger(GetTargetBinding());
    SetGLBindTexture(GetTarget(), GetGLHandle());

    SetGLPixelStore(System::PixelStore::UnpackAlignment, 1);
    SetGLPixelStore(System::PixelStore::PackAlignment, 1);

    SetGLTexturesParameter(GetTarget(), System::TextureParameter::TextureBaseLevel, 0);
    SetGLTexturesParameter(GetTarget(), System::TextureParameter::TextureMaxLevel, GetNumLevels() - 1);

    const auto texture = GetTexture();
    const auto numItems = texture->GetNumItems();

    if (CanAutoGenerateMipmaps())
    {
        for (auto item = 0; item < numItems; ++item)
        {
            const auto data = texture->GetDataFor(item, 0);

            LoadTextureLevel(item, 0, data);
        }
        GenerateMipmaps();
    }
    else
    {
        for (auto item = 0; item < numItems; ++item)
        {
            for (auto level = 0; level < GetNumLevels(); ++level)
            {
                const auto data = texture->GetDataFor(item, level);

                LoadTextureLevel(item, level, data);
            }
        }
    }

    SetGLBindTexture(GetTarget(), prevBinding);
}

bool Rendering::OpenGLTextureArray::Update()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTexture();
    const auto numItems = texture->GetNumItems();

    if (CanAutoGenerateMipmaps())
    {
        for (auto item = 0; item < numItems; ++item)
        {
            if (!Update(item, 0))
            {
                return false;
            }
        }
        GenerateMipmaps();
    }
    else
    {
        for (auto item = 0; item < numItems; ++item)
        {
            for (auto level = 0; level < texture->GetNumLevels(); ++level)
            {
                if (!Update(item, level))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Rendering::OpenGLTextureArray::CopyCpuToGpu()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTexture();
    const auto numItems = texture->GetNumItems();

    if (CanAutoGenerateMipmaps())
    {
        for (auto item = 0; item < numItems; ++item)
        {
            if (!CopyCpuToGpu(item, 0))
            {
                return false;
            }
        }
        GenerateMipmaps();
    }
    else
    {
        for (auto item = 0; item < numItems; ++item)
        {
            for (auto level = 0; level < texture->GetNumLevels(); ++level)
            {
                if (!CopyCpuToGpu(item, level))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Rendering::OpenGLTextureArray::CopyGpuToCpu()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTexture();
    const auto numItems = texture->GetNumItems();

    for (auto item = 0; item < numItems; ++item)
    {
        for (auto level = 0; level < texture->GetNumLevels(); ++level)
        {
            if (!CopyGpuToCpu(item, level))
            {
                return false;
            }
        }
    }

    return true;
}

bool Rendering::OpenGLTextureArray::Update(int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTexture();
    if (texture->GetUsage() != UsageType::DynamicUpdate)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理使用必须为DynamicUpdate。"));
    }

    return DoCopyCpuToGpu(item, level);
}

bool Rendering::OpenGLTextureArray::CopyCpuToGpu(int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!PreparedForCopy(BufferLocking::WriteOnly))
    {
        return false;
    }

    return DoCopyCpuToGpu(item, level);
}

bool Rendering::OpenGLTextureArray::CopyGpuToCpu(int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!PreparedForCopy(BufferLocking::ReadOnly))
    {
        return false;
    }

    const auto texture = GetTextureArray();

    if (const auto numItems = texture->GetNumItems();
        item >= numItems)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理级别超出范围。"));
    }

    if (level >= texture->GetNumLevels())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理级别超出范围。"));
    }

    const auto pixBuffer = impl->GetLevelPixelPackBuffer(level);
    if (0 == pixBuffer)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未为级别") + System::ToString(level) + SYSTEM_TEXT("定义暂存缓冲区。"));
    }

    const auto data = texture->GetDataFor(item, level);
    const auto numBytes = texture->GetNumLevelBytes(level);
    if (0 == numBytes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("没有纹理级别") + System::ToString(level) + SYSTEM_TEXT("的目标数据。"));
    }

    auto const textureTarget = GetTarget();
    SetGLBindTexture(textureTarget, GetGLHandle());

    SetGLBindBuffer(BindBuffer::PixelPackBuffer, pixBuffer);
    GetGLTexturesImage(textureTarget, level, GetExternalFormat(), GetExternalType(), nullptr);
    GetGLBufferSubData(BindBuffer::PixelPackBuffer, 0, numBytes, &*data.GetCurrent());
    SetGLBindBuffer(BindBuffer::PixelPackBuffer, 0);

    SetGLBindTexture(textureTarget, 0);

    return true;
}

bool Rendering::OpenGLTextureArray::GenerateMipmaps()
{
    RENDERING_CLASS_IS_VALID_9;

    if (CanAutoGenerateMipmaps())
    {
        const auto prevBinding = GetGLInteger(GetTargetBinding());
        SetGLBindTexture(GetTarget(), GetGLHandle());

        SetGLGenerateMipmap(GetTarget());

        SetGLBindTexture(GetTarget(), prevBinding);

        return true;
    }
    return false;
}

bool Rendering::OpenGLTextureArray::DoCopyCpuToGpu(int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTextureArray();

    if (CanAutoGenerateMipmaps() && (0 < level))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无法更新GPU中自动生成的mipmap。"));
    }

    if (const auto numItems = texture->GetNumItems();
        numItems <= item)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理级别超出范围。"));
    }

    if (texture->GetNumLevels() <= level)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("纹理级别超出范围。"));
    }

    const auto data = texture->GetDataFor(item, level);
    const auto numBytes = texture->GetNumLevelBytes(level);
    if (numBytes == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("没有纹理级别") + System::ToString(level) + SYSTEM_TEXT("的源数据"));
    }

    const auto textureTarget = GetTarget();
    SetGLBindTexture(textureTarget, GetGLHandle());

    if (const auto pixBuffer = impl->GetLevelPixelUnpackBuffer(level);
        pixBuffer != 0)
    {
        SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, pixBuffer);
        SetGLBufferSubData(System::BindBuffer::PixelUnpackBuffer, 0, numBytes, data.GetData());
        LoadTextureLevel(level, level, ConstSpanIterator{ data.GetBegin(), data.GetBegin() });
        SetGLBindBuffer(System::BindBuffer::PixelUnpackBuffer, 0);
    }
    else
    {
        LoadTextureLevel(level, level, ConstSpanIterator{ data.GetBegin(), data.GetEnd(), data.GetCurrent() });
    }

    SetGLBindTexture(textureTarget, 0);

    return true;
}

void Rendering::OpenGLTextureArray::CreateStaging()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto texture = GetTexture();
    const auto copyType = texture->GetCopy();

    const auto createPixelUnpackBuffers = (copyType == CopyType::CpuToStaging) || (copyType == CopyType::Bidirectional);

    const auto createPixelPackBuffers = (copyType == CopyType::StagingToCpu) || (copyType == CopyType::Bidirectional);

    constexpr auto usage = System::BufferUsage::Dynamic;

    if (createPixelUnpackBuffers)
    {
        for (auto level = 0; level < GetNumLevels(); ++level)
        {
            if (auto pixBuffer = impl->GetLevelPixelUnpackBuffer(level);
                pixBuffer == 0)
            {
                const auto numBytes = texture->GetNumLevelBytes(level);

                pixBuffer = System::GetGLGenBuffers();
                impl->SetLevelPixelUnpackBuffer(level, pixBuffer);
                SetGLBindBuffer(BindBuffer::PixelUnpackBuffer, pixBuffer);
                SetGLBufferData(BindBuffer::PixelUnpackBuffer, numBytes, nullptr, usage);
                SetGLBindBuffer(BindBuffer::PixelUnpackBuffer, 0);
            }
        }
    }

    if (createPixelPackBuffers)
    {
        for (auto level = 0; level < GetNumLevels(); ++level)
        {
            if (auto pixBuffer = impl->GetLevelPixelPackBuffer(level);
                pixBuffer == 0)
            {
                const auto numBytes = texture->GetNumLevelBytes(level);

                pixBuffer = System::GetGLGenBuffers();
                impl->SetLevelPixelPackBuffer(level, pixBuffer);

                SetGLBindBuffer(BindBuffer::PixelPackBuffer, pixBuffer);
                SetGLBufferData(BindBuffer::PixelPackBuffer, numBytes, nullptr, usage);
                SetGLBindBuffer(BindBuffer::PixelPackBuffer, 0);
            }
        }
    }
}

System::TextureCubeMap Rendering::OpenGLTextureArray::GetCubeFaceTarget(int index)
{
    using Container = std::array<System::TextureCubeMap, 6>;
    static Container cubeFaceTarget{ TextureCubeMap::PositiveX,
                                     TextureCubeMap::NegativeX,
                                     TextureCubeMap::PositiveY,
                                     TextureCubeMap::NegativeY,
                                     TextureCubeMap::PositiveZ,
                                     TextureCubeMap::NegativeZ };

    return cubeFaceTarget.at(index);
}
