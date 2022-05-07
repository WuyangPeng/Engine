///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 10:26)

#include "Rendering/RenderingExport.h"

#include "BufferImpl.h"
#include "BufferParameter.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <gsl/util>

Rendering::BufferImpl::BufferImpl() noexcept
    : numElements{ 0 }, elementSize{ 0 }, usage{ BufferUsage::Quantity }, data{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::BufferImpl::BufferImpl(int numElements, int elementSize, BufferUsage usage)
    : numElements{ numElements },
      elementSize{ elementSize },
      usage{ usage },
      data(gsl::narrow_cast<size_t>(numElements) * elementSize)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::BufferImpl::IsValid() const noexcept
{
    if (0 <= numElements && 0 <= elementSize && numElements * elementSize <= gsl::narrow_cast<int>(data.size()))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int32_t Rendering::BufferImpl::GetNumElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numElements;
}

int32_t Rendering::BufferImpl::GetElementSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return elementSize;
}

Rendering::BufferUsage Rendering::BufferImpl::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return usage;
}

void Rendering::BufferImpl::SetNumElements(int32_t newNumElements) noexcept(g_Assert < 1 || g_RenderingAssert < 1)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(newNumElements <= boost::numeric_cast<int>(data.size()) / elementSize, "设置的长度溢出！");

    numElements = newNumElements;
}

int Rendering::BufferImpl::GetNumBytes() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(data.size());
}

const char* Rendering::BufferImpl::GetReadOnlyData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return data.data();
}

Rendering::BufferImpl::SpanIterator Rendering::BufferImpl::GetSpanIterator() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return SpanIterator{ data.begin(), data.end() };
}

Rendering::BufferImpl::WriteSpanIterator Rendering::BufferImpl::GetWriteSpanIterator() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return WriteSpanIterator{ data.begin(), data.end() };
}

const char* Rendering::BufferImpl::GetReadOnlyData(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return &data.at(index);
}

void Rendering::BufferImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numElements);
    source.Read(elementSize);
    source.ReadEnum(usage);

    int32_t size{};
    source.Read(size);
    data.resize(size);

    source.ReadContainer(data);
}

void Rendering::BufferImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numElements);
    target.Write(elementSize);
    target.WriteEnum(usage);
    target.WriteContainerWithNumber(data);
}

int Rendering::BufferImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(numElements);

    size += CORE_TOOLS_STREAM_SIZE(elementSize);
    size += CORE_TOOLS_STREAM_SIZE(usage);
    auto numBytes = boost::numeric_cast<int32_t>(data.size());
    size += CORE_TOOLS_STREAM_SIZE(numBytes);
    size += numBytes * CORE_TOOLS_STREAM_SIZE(decltype(data[0]){});

    return size;
}

void Rendering::BufferImpl::SaveBufferDataToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    SaveHeadToFile(outFile);

    const auto numBytes = gsl::narrow_cast<int32_t>(GetNumBytes());
    outFile.Write(sizeof(int32_t), &numBytes);

    outFile.Write(elementSize, numBytes / elementSize, data.data());
}

void Rendering::BufferImpl::SaveBufferDataToFile(WriteFileManager& outFile, const VertexFormat& vertexformat) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto stride = vertexformat.GetStride();

    RENDERING_ASSERTION_1(stride == GetElementSize(), "格式步进值和顶点大小必须匹配。\n");

    // 建立一个顶点缓冲属性的表。
    // 每个属性都有一个偏移量,属性组件的大小,和组件大小的数量
    // 例如,属性使用偏移量0和类型AT_FLOAT3为(offset,size,numComponents) = (0,4,3)。
    std::array<BufferParameter, System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes)> table{};
    const auto numAttributes = vertexformat.GetNumAttributes();
    for (auto attributesIndex = 0; attributesIndex < numAttributes; ++attributesIndex)
    {
        const auto type = vertexformat.GetAttributeType(attributesIndex);
        const auto offset = vertexformat.GetOffset(attributesIndex);
        const auto componentSize = VertexFormat::GetComponentSize(type);
        const auto numComponents = VertexFormat::GetNumComponents(type);

        table.at(attributesIndex).Set(offset, componentSize, numComponents);
    }

    // 一次写入顶点，允许字节交换(字节顺序)。

    auto vertexIndex = 0;
    for (auto i = 0; i < numElements; ++i)
    {
        for (auto attributesIndex = 0; attributesIndex < numAttributes; ++attributesIndex)
        {
            const auto beginIndex = vertexIndex + table.at(attributesIndex).GetOffset();
            outFile.Write(table.at(attributesIndex).GetComponentSize(), table.at(attributesIndex).GetNumComponents(), &data.at(beginIndex));
        }

        vertexIndex += stride;
    }
}

void Rendering::BufferImpl::SaveHeadToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    outFile.Write(sizeof(int32_t), &numElements);
    outFile.Write(sizeof(int32_t), &elementSize);
    outFile.Write(sizeof(BufferUsage), &usage);
}

void Rendering::BufferImpl::ReadBufferDataFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    inFile.Read(sizeof(int32_t), &numElements);

    if (numElements != 0)
    {
        inFile.Read(sizeof(int32_t), &elementSize);
        inFile.Read(sizeof(BufferUsage), &usage);

        int32_t numBytes{};
        inFile.Read(sizeof(int32_t), &numBytes);
        data.resize(numBytes);

        inFile.Read(elementSize, numBytes / elementSize, data.data());
    }
}

void Rendering::BufferImpl::ReadBufferDataFromFile(ReadFileManager& inFile, const VertexFormat& vertexformat)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto stride = vertexformat.GetStride();

    RENDERING_ASSERTION_1(stride == GetElementSize(), "格式步进值和顶点大小必须匹配。\n");

    // 建立一个顶点缓冲属性的表。
    // 每个属性都有一个偏移量,属性组件的大小,和组件大小的数量
    // 例如,属性使用偏移量0和类型AT_FLOAT3为(offset,size,numComponents) = (0,4,3)。
    std::array<BufferParameter, System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes)> table{};
    const auto numAttributes = vertexformat.GetNumAttributes();
    for (auto attributesIndex = 0; attributesIndex < numAttributes; ++attributesIndex)
    {
        const auto type = vertexformat.GetAttributeType(attributesIndex);
        const auto offset = vertexformat.GetOffset(attributesIndex);
        const auto componentSize = VertexFormat::GetComponentSize(type);
        const auto numComponents = VertexFormat::GetNumComponents(type);

        table.at(attributesIndex).Set(offset, componentSize, numComponents);
    }

    // 一次读取顶点，允许字节交换(字节顺序)。

    auto vertexIndex = 0;
    for (auto i = 0; i < numElements; ++i, vertexIndex += stride)
    {
        for (auto attributesIndex = 0; attributesIndex < numAttributes; ++attributesIndex)
        {
            const auto beginIndex = vertexIndex + table.at(attributesIndex).GetOffset();
            inFile.Read(table.at(attributesIndex).GetComponentSize(), table.at(attributesIndex).GetNumComponents(), &data.at(beginIndex));
        }
    }
}

void Rendering::BufferImpl::ReadHeadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    inFile.Read(sizeof(int32_t), &numElements);
    inFile.Read(sizeof(int32_t), &elementSize);
    inFile.Read(sizeof(BufferUsage), &usage);

    const auto dataSize = numElements * elementSize;

    data.resize(dataSize);
}

char* Rendering::BufferImpl::GetAccessWriteData(int index)
{
    RENDERING_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<char*>(GetReadOnlyData(index));

#include STSTEM_WARNING_POP
}

void Rendering::BufferImpl::SetNewData(const std::vector<char>& newData)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(data.size() == newData.size(), "数据大小不相等\n");

    data = newData;
}
