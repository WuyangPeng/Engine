///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 20:10)

#include "Rendering/RenderingExport.h"

#include "TextureData.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::TextureData::TextureData(TextureFormat format, TextureFlags type, BufferUsage usage, int numLevels) noexcept
    : format{ format }, textureFlags{ type }, usage{ usage }, numLevels{ numLevels }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureData::TextureData() noexcept
    : format{ TextureFormat::Quantity }, textureFlags{ TextureFlags::Quantity }, usage{ BufferUsage::Quantity }, numLevels{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::TextureData::IsValid() const noexcept
{
    if (0 <= numLevels)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::TextureFormat Rendering::TextureData::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return format;
}

Rendering::TextureFlags Rendering::TextureData::GetTextureType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return textureFlags;
}

Rendering::BufferUsage Rendering::TextureData::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return usage;
}

int32_t Rendering::TextureData::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numLevels;
}

bool Rendering::TextureData::IsCompressed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return format == TextureFormat::DXT1 || format == TextureFormat::DXT3 || format == TextureFormat::DXT5;
}

void Rendering::TextureData::SetNumLevels(int32_t aNumLevels) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    numLevels = aNumLevels;
}

void Rendering::TextureData::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadEnum(format);
    source.ReadEnum(textureFlags);
    source.ReadEnum(usage);
    source.Read(numLevels);

    if (format < TextureFormat::First ||
        TextureFormat::Max <= format ||
        textureFlags < TextureFlags::Texture1D ||
        TextureFlags::Quantity <= textureFlags ||
        usage < BufferUsage::Static ||
        BufferUsage::Quantity <= usage ||
        numLevels < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("读取的纹理数据不正确。\n"s));
    }
}

void Rendering::TextureData::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteEnum(format);
    target.WriteEnum(textureFlags);
    target.WriteEnum(usage);
    target.Write(numLevels);
}

int Rendering::TextureData::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(format);

    size += CORE_TOOLS_STREAM_SIZE(textureFlags);
    size += CORE_TOOLS_STREAM_SIZE(usage);
    size += CORE_TOOLS_STREAM_SIZE(numLevels);

    return size;
}

void Rendering::TextureData::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    outFile.Write(sizeof(TextureFormat), &format);
    outFile.Write(sizeof(TextureFlags), &textureFlags);
    outFile.Write(sizeof(BufferUsage), &usage);
    outFile.Write(sizeof(int32_t), &numLevels);
}

void Rendering::TextureData::ReadFromFile(ReadFileManager& inFile)
{
    inFile.Read(sizeof(TextureFormat), &format);
    inFile.Read(sizeof(TextureFlags), &textureFlags);
    inFile.Read(sizeof(BufferUsage), &usage);
    inFile.Read(sizeof(int32_t), &numLevels);

    if (!(TextureFormat::First <= format &&
          format < TextureFormat::Max &&
          TextureFlags::Texture1D <= textureFlags &&
          textureFlags < TextureFlags::Quantity &&
          BufferUsage::Static <= usage &&
          usage < BufferUsage::Quantity &&
          0 <= numLevels))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("读取的纹理数据不正确。\n"s));
    }
}
