/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:29)

#include "Rendering/RenderingExport.h"

#include "TextureData.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::TextureData::TextureData(DataFormatType format, int numLevels) noexcept
    : format{ format }, numLevels{ numLevels }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureData::TextureData() noexcept
    : format{ DataFormatType::Unknown }, numLevels{ 0 }
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

Rendering::DataFormatType Rendering::TextureData::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return format;
}

int Rendering::TextureData::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numLevels;
}

void Rendering::TextureData::SetNumLevels(int aNumLevels) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    numLevels = aNumLevels;
}

void Rendering::TextureData::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadEnum(format);
    source.Read(numLevels);

    if (format <= DataFormatType::Unknown || DataFormatType::NumFormats <= format || numLevels < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("读取的纹理数据不正确。\n"s))
    }
}

void Rendering::TextureData::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteEnum(format);
    target.Write(numLevels);
}

int Rendering::TextureData::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(format);

    size += CoreTools::GetStreamSize(numLevels);

    return size;
}
