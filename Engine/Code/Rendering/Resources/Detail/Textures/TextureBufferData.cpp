///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 19:52)

#include "Rendering/RenderingExport.h"

#include "TextureBufferData.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;

Rendering::TextureBufferData::TextureBufferData(int itemSize) noexcept
    : data{}, itemSize{ itemSize }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureBufferData::TextureBufferData(const TextureBufferData& rhs)
    : data{ rhs.data != nullptr ? std::make_shared<FileBuffer>(*rhs.data) : nullptr }, itemSize{ rhs.itemSize }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureBufferData::TextureBufferData(TextureBufferData&& rhs) noexcept
    : data{ std::move(rhs.data) }, itemSize{ std::move(rhs.itemSize) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureBufferData& Rendering::TextureBufferData::operator=(TextureBufferData&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    data = std::move(rhs.data);
    itemSize = rhs.itemSize;

    return *this;
}

Rendering::TextureBufferData& Rendering::TextureBufferData::operator=(const TextureBufferData& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    if (rhs.data != nullptr)
    {
        data = make_shared<FileBuffer>(*rhs.data);
    }
    else
    {
        data = nullptr;
    }

    itemSize = rhs.itemSize;

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::TextureBufferData::IsValid() const noexcept
{
    if (0 < itemSize)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

const char* Rendering::TextureBufferData::GetReadOnlyData() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(data != nullptr, "数据还未读取！");

    return data->GetBufferBegin();
}

char* Rendering::TextureBufferData::GetWriteData()
{
    RENDERING_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<char*>(static_cast<const ClassType*>(this)->GetReadOnlyData());

#include STSTEM_WARNING_POP
}

void Rendering::TextureBufferData::Reset(int bufferSize)
{
    RENDERING_CLASS_IS_VALID_1;

    data = make_shared<FileBuffer>(bufferSize);
}

void Rendering::TextureBufferData::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    int32_t numTotalBytes{};
    source.Read(numTotalBytes);

    if (numTotalBytes != 0)
    {
        data = make_shared<FileBuffer>(numTotalBytes);

        auto container = source.ReadVectorWithNumber<char>(numTotalBytes);

        std::copy(container.cbegin(), container.cend(), data->begin());
    }
}

void Rendering::TextureBufferData::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (data != nullptr && data->GetSize() != 0)
    {
        std::vector<char> result{ data->begin(), data->end() };
        target.WriteContainerWithNumber(result);
    }
    else
    {
        target.Write(0);
    }
}

int Rendering::TextureBufferData::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto size = CORE_TOOLS_STREAM_SIZE(0);

    if (data != nullptr)
    {
        return boost::numeric_cast<int>(data->GetSize() + size);
    }
    else
    {
        return size;
    }
}

void Rendering::TextureBufferData::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(data != nullptr, "数据还未读取！");

    outFile.Write(boost::numeric_cast<size_t>(itemSize), boost::numeric_cast<size_t>(data->GetSize() / itemSize), data->GetBufferBegin());
}

void Rendering::TextureBufferData::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(data != nullptr, "数据还未读取！");

    inFile.Read(itemSize, boost::numeric_cast<size_t>(data->GetSize() / itemSize), data->GetBufferBegin());
}

void Rendering::TextureBufferData::ExpandFileBufferSize(int newNumTotalBytes, int numLevel0Bytes)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(data != nullptr, "数据还未读取！");
    RENDERING_ASSERTION_0(numLevel0Bytes <= boost::numeric_cast<int>(data->GetSize()), "传入的等级0字节数太大。");

    auto fileBuffer = make_shared<FileBuffer>(newNumTotalBytes);

    std::copy(data->begin(), data->end(), fileBuffer->begin());

    data = fileBuffer;
}

void Rendering::TextureBufferData::ExpandFileBufferSizeOnCube(int newNumTotalBytes, int numLevel0Bytes)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(data != nullptr, "数据还未读取！");
    RENDERING_ASSERTION_0(boost::numeric_cast<size_t>(numLevel0Bytes * 6) <= data->GetSize(), "传入的等级0字节数太大。");

    auto oldNumTotalBytes = boost::numeric_cast<int>(data->GetSize());

    FileBufferSharedPtr fileBuffer{ make_shared<FileBuffer>(newNumTotalBytes) };

    for (auto face = 0; face < 6; ++face)
    {
        const auto oldFaceOffset = face * oldNumTotalBytes / 6;
        auto faceOffset = face * newNumTotalBytes / 6;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        memcpy(fileBuffer->GetBufferBegin() + faceOffset, GetReadOnlyData() + oldFaceOffset, numLevel0Bytes);

#include STSTEM_WARNING_POP
    }

    data = fileBuffer;
}

int Rendering::TextureBufferData::GetSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (data != nullptr)
    {
        return boost::numeric_cast<int>(data->GetSize());
    }
    else
    {
        return 0;
    }
}
