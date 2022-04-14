///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 11:49)

#include "Rendering/RenderingExport.h"

#include "IndexBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Renderers/RendererManager.h"

using std::vector;

CORE_TOOLS_RTTI_DEFINE(Rendering, IndexBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IndexBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IndexBuffer);

Rendering::IndexBuffer::IndexBuffer(MAYBE_UNUSED IndexBufferCreate indexBufferCreate)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, offset{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IndexBuffer::IndexBuffer(MAYBE_UNUSED IndexBufferCreate indexBufferCreate, int numIndices, int indexSize, BufferUsage usage)
    : ParentType{ numIndices, indexSize, usage }, offset{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IndexBuffer::IndexBufferSharedPtr Rendering::IndexBuffer::Create()
{
    return std::make_shared<ClassType>(IndexBufferCreate::Init);
}

Rendering::IndexBuffer::IndexBufferSharedPtr Rendering::IndexBuffer::Create(int numIndices, int indexSize, BufferUsage usage)
{
    return std::make_shared<ClassType>(IndexBufferCreate::Init, numIndices, indexSize, usage);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, IndexBuffer)

void Rendering::IndexBuffer::SetOffset(int aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    offset = aOffset;
}

int Rendering::IndexBuffer::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return offset;
}

Rendering::IndexBuffer::IndexBuffer(LoadConstructor value)
    : ParentType{ value }, offset{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IndexBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += CORE_TOOLS_STREAM_SIZE(offset);

    return size;
}

uint64_t Rendering::IndexBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::IndexBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(offset);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IndexBuffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::IndexBuffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::IndexBuffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(offset);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::IndexBuffer::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ParentType::SaveBufferDataToFile(outFile);

    outFile.Write(sizeof(int32_t), &offset);
}

void Rendering::IndexBuffer::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::ReadBufferDataFromFile(inFile);

    if (GetNumElements() != 0)
    {
        inFile.Read(sizeof(int32_t), &offset);
    }
}

Rendering::IndexBufferSharedPtr Rendering::IndexBuffer::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

void Rendering::IndexBuffer::InitIndexBuffer()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto indexSize = GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = GetNumElements();

    if (indexSize == 2)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto indices = reinterpret_cast<int16_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

        if (indices != nullptr)
        {
            for (int16_t i{}; i < numVertices; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i] = i;

#include STSTEM_WARNING_POP
            }
        }
    }
    else  // indexSize == 4
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int32_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP
        if (indices != nullptr)
        {
            for (auto i = 0; i < numVertices; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i] = i;

#include STSTEM_WARNING_POP
            }
        }
    }
}

void Rendering::IndexBuffer::InitIndexBuffer(const vector<int>& indices)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto indexSize = GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = boost::numeric_cast<size_t>(GetNumElements());

    RENDERING_ASSERTION_1(numVertices == indices.size(), "索引数不对应。");

    if (indexSize == 2)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto accessWriteData = reinterpret_cast<int16_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

        if (accessWriteData != nullptr)
        {
            for (auto i = 0u; i < numVertices; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                accessWriteData[i] = boost::numeric_cast<int16_t>(indices.at(i));

#include STSTEM_WARNING_POP
            }
        }
    }
    else  // indexSize == 4
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto accessWriteData = reinterpret_cast<int32_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

        if (accessWriteData != nullptr)
        {
            for (auto i = 0u; i < numVertices; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                accessWriteData[i] = indices.at(i);

#include STSTEM_WARNING_POP
            }
        }
    }
}

void Rendering::IndexBuffer::InitIndexBufferInParticles()
{
    RENDERING_CLASS_IS_VALID_1;

    const auto indexSize = GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = GetNumElements();
    const auto numParticles = numVertices / 6;

    if (indexSize == 2)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int16_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

        if (indices != nullptr)
        {
            for (int16_t i{}; i < numParticles; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i * 6] = 4 * i;
                indices[i * 6 + 1] = 4 * i + 1;
                indices[i * 6 + 2] = 4 * i + 2;
                indices[i * 6 + 3] = 4 * i;
                indices[i * 6 + 4] = 4 * i + 2;
                indices[i * 6 + 5] = 4 * i + 3;

#include STSTEM_WARNING_POP
            }
        }
    }
    else  // indexSize == 4
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int32_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

        if (indices != nullptr)
        {
            for (auto i = 0; i < numParticles; ++i)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[i * 6] = 4 * i;
                indices[i * 6 + 1] = 4 * i + 1;
                indices[i * 6 + 2] = 4 * i + 2;
                indices[i * 6 + 3] = 4 * i;
                indices[i * 6 + 4] = 4 * i + 2;
                indices[i * 6 + 5] = 4 * i + 3;

#include STSTEM_WARNING_POP
            }
        }
    }
}

void Rendering::IndexBuffer::InitIndexBufferInRectangle(int index, int rectangleIndex0, int rectangleIndex1, int rectangleIndex2, int rectangleIndex3)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto indexSize = GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    const auto numVertices = GetNumElements();
    const auto numRectangles = numVertices / 6;

    if (0 <= index && index < numRectangles)
    {
        if (indexSize == 2)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

            auto indices = reinterpret_cast<int16_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

            if (indices != nullptr)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[index * 6] = boost::numeric_cast<int16_t>(rectangleIndex0);
                indices[index * 6 + 1] = boost::numeric_cast<int16_t>(rectangleIndex1);
                indices[index * 6 + 2] = boost::numeric_cast<int16_t>(rectangleIndex2);
                indices[index * 6 + 3] = boost::numeric_cast<int16_t>(rectangleIndex0);
                indices[index * 6 + 4] = boost::numeric_cast<int16_t>(rectangleIndex2);
                indices[index * 6 + 5] = boost::numeric_cast<int16_t>(rectangleIndex3);

#include STSTEM_WARNING_POP
            }
        }
        else  // indexSize == 4
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

            auto indices = reinterpret_cast<int32_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

            if (indices != nullptr)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[index * 6] = rectangleIndex0;
                indices[index * 6 + 1] = rectangleIndex1;
                indices[index * 6 + 2] = rectangleIndex2;
                indices[index * 6 + 3] = rectangleIndex0;
                indices[index * 6 + 4] = rectangleIndex2;
                indices[index * 6 + 5] = rectangleIndex3;

#include STSTEM_WARNING_POP
            }
        }
    }
}

void Rendering::IndexBuffer::InitIndexBufferInDisk(int radialSamplesMinus1, int shellSamplesMinus1)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto indexSize = GetElementSize();

    RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "索引大小只能为2或4。");

    if (indexSize == 2)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int16_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

        if (indices != nullptr)
        {
            auto firstIndex = radialSamplesMinus1;

            for (auto secondIndex = 0; secondIndex <= radialSamplesMinus1; ++secondIndex)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[0] = 0;
                indices[1] = boost::numeric_cast<int16_t>(1 + shellSamplesMinus1 * firstIndex);
                indices[2] = boost::numeric_cast<int16_t>(1 + shellSamplesMinus1 * secondIndex);
                indices += 3;

                for (auto shellIndex = 1; shellIndex < shellSamplesMinus1; ++shellIndex)
                {
                    const auto index00 = boost::numeric_cast<int16_t>(shellIndex + shellSamplesMinus1 * firstIndex);
                    const auto index01 = boost::numeric_cast<int16_t>(shellIndex + shellSamplesMinus1 * secondIndex);
                    const auto index10 = boost::numeric_cast<int16_t>(index00 + 1);
                    const auto index11 = boost::numeric_cast<int16_t>(index01 + 1);

                    indices[0] = index00;
                    indices[1] = index10;
                    indices[2] = index11;
                    indices[3] = index00;
                    indices[4] = index11;
                    indices[5] = index01;

                    indices += 6;
                }

#include STSTEM_WARNING_POP

                firstIndex = secondIndex;
            }
        }
    }
    else  // indexSize == 4
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        auto indices = reinterpret_cast<int32_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

        if (indices != nullptr)
        {
            auto firstIndex = radialSamplesMinus1;

            for (auto secondIndex = 0; secondIndex <= radialSamplesMinus1; ++secondIndex)
            {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                indices[0] = 0;
                indices[1] = 1 + shellSamplesMinus1 * firstIndex;
                indices[2] = 1 + shellSamplesMinus1 * secondIndex;
                indices += 3;

                for (auto shellIndex = 1; shellIndex < shellSamplesMinus1; ++shellIndex)
                {
                    const auto index00 = shellIndex + shellSamplesMinus1 * firstIndex;
                    const auto index01 = shellIndex + shellSamplesMinus1 * secondIndex;
                    const auto index10 = index00 + 1;
                    const auto index11 = index01 + 1;

                    indices[0] = index00;
                    indices[1] = index10;
                    indices[2] = index11;
                    indices[3] = index00;
                    indices[4] = index11;
                    indices[5] = index01;

                    indices += 6;
                }

#include STSTEM_WARNING_POP

                firstIndex = secondIndex;
            }
        }
    }
}

void Rendering::IndexBuffer::SetIndexBuffer(int index, MAYBE_UNUSED int original, int current)
{
    RENDERING_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto accessWriteData = reinterpret_cast<int32_t*>(GetAccessWriteData(0));

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    if (accessWriteData != nullptr)
    {
        RENDERING_ASSERTION_2(accessWriteData[index] == original, "原来的索引错误\n");

        accessWriteData[index] = current;
    }

#include STSTEM_WARNING_POP
}

CoreTools::ObjectInterfaceSharedPtr Rendering::IndexBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
