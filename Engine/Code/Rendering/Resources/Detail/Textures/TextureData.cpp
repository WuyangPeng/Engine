///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:28)

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
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���������ݲ���ȷ��\n"s));
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

void Rendering::TextureData::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    outFile.Write(sizeof(DataFormatType), &format);
    outFile.Write(sizeof(int32_t), &numLevels);
}

void Rendering::TextureData::ReadFromFile(ReadFileManager& inFile)
{
    inFile.Read(sizeof(DataFormatType), &format);
    inFile.Read(sizeof(int32_t), &numLevels);

    if (format <= DataFormatType::Unknown || DataFormatType::NumFormats <= format || numLevels < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ���������ݲ���ȷ��\n"s));
    }
}
