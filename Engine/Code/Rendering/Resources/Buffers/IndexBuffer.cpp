///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 14:49)

#include "Rendering/RenderingExport.h"

#include "IndexBufferDetail.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/OpenGLRenderer/Resources/Buffers/OpenGLIndexBuffer.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

using System::operator&;

CORE_TOOLS_RTTI_DEFINE(Rendering, IndexBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IndexBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IndexBuffer);

Rendering::IndexBuffer::IndexBuffer(IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives)
    : ParentType{ GetIndexCounter(type, numPrimitives), 0, GraphicsObjectType::IndexBuffer },
      primitiveType{ type },
      numPrimitives{ numPrimitives },
      numActivePrimitives{ numPrimitives },
      firstPrimitive{ 0 }
{
    System::UnusedFunction(indexBufferCreate);

    if (numPrimitives <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效数量的primitives。"s))
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IndexBuffer::IndexBuffer(IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives, int indexSize)
    : ParentType{ GetIndexCounter(type, numPrimitives), indexSize, GraphicsObjectType::IndexBuffer },
      primitiveType{ type },
      numPrimitives{ numPrimitives },
      numActivePrimitives{ numPrimitives },
      firstPrimitive{ 0 }
{
    System::UnusedFunction(indexBufferCreate);

    if (numPrimitives <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效数量的primitives。"s))
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IndexBuffer::IndexBufferSharedPtr Rendering::IndexBuffer::Create(IndexFormatType type, int numPrimitives)
{
    return std::make_shared<ClassType>(IndexBufferCreate::Init, type, numPrimitives);
}

Rendering::IndexBuffer::IndexBufferSharedPtr Rendering::IndexBuffer::Create(IndexFormatType type, int numPrimitives, int indexSize)
{
    return std::make_shared<ClassType>(IndexBufferCreate::Init, type, numPrimitives, indexSize);
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::IndexBuffer::IsValid() const noexcept
{
    if (ParentType::IsValid() &&
        0 <= numPrimitives &&
        0 <= numActivePrimitives &&
        0 <= firstPrimitive)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::IndexBuffer::IndexBuffer(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor },
      primitiveType{ IndexFormatType::None },
      numPrimitives{ 0 },
      numActivePrimitives{ 0 },
      firstPrimitive{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::IndexBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += CoreTools::GetStreamSize(primitiveType);
    size += CoreTools::GetStreamSize(numPrimitives);
    size += CoreTools::GetStreamSize(numActivePrimitives);
    size += CoreTools::GetStreamSize(firstPrimitive);

    return size;
}

int64_t Rendering::IndexBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::IndexBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteEnum(primitiveType);
    target.Write(numPrimitives);
    target.Write(numActivePrimitives);
    target.Write(firstPrimitive);

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

    source.ReadEnum(primitiveType);
    source.Read(numPrimitives);
    source.Read(numActivePrimitives);
    source.Read(firstPrimitive);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::IndexBufferSharedPtr Rendering::IndexBuffer::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::IndexBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Rendering::IndexFormatType Rendering::IndexBuffer::GetPrimitiveType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return primitiveType;
}

int Rendering::IndexBuffer::GetNumPrimitives() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numPrimitives;
}

void Rendering::IndexBuffer::SetNumActivePrimitives(int numActive)
{
    RENDERING_CLASS_IS_VALID_1;

    if (numPrimitives < numActive)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效数量的primitives。"s))
    }

    numActivePrimitives = numActive;
}

int Rendering::IndexBuffer::GetNumActivePrimitives() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numActivePrimitives;
}

int Rendering::IndexBuffer::GetNumActiveIndices() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return GetIndexCounter(primitiveType, numActivePrimitives);
}

void Rendering::IndexBuffer::SetFirstPrimitive(int first)
{
    RENDERING_CLASS_IS_VALID_1;

    if (first < numPrimitives && first + numActivePrimitives <= numPrimitives)
    {
        firstPrimitive = first;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的first primitives。"s))
    }
}

int Rendering::IndexBuffer::GetFirstPrimitive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return firstPrimitive;
}

int Rendering::IndexBuffer::GetFirstIndex() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (firstPrimitive == 0)
    {
        return 0;
    }

    return GetIndexCounter(primitiveType, firstPrimitive);
}

void Rendering::IndexBuffer::SetPoint(int index, int32_t vertex)
{
    RENDERING_CLASS_IS_VALID_1;

    ValidPrimitiveType(IndexFormatType::HasPoints);

    if (index < numPrimitives)
    {
        if (GetElementSize() == CoreTools::GetStreamSize<int32_t>())
        {
            IncreaseData(index, vertex);
        }
        else
        {
            IncreaseData(index, boost::numeric_cast<uint16_t>(vertex));
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s))
}

int32_t Rendering::IndexBuffer::GetPoint(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ValidPrimitiveType(IndexFormatType::HasPoints);

    if (index < numPrimitives)
    {
        if (GetElementSize() == CoreTools::GetStreamSize<int32_t>())
        {
            return GetIncreaseData<int32_t>(index);
        }
        else
        {
            return GetIncreaseData<int16_t>(index);
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s))
}

void Rendering::IndexBuffer::SetSegment(int index, int32_t vertex0, int32_t vertex1)
{
    RENDERING_CLASS_IS_VALID_1;

    ValidPrimitiveType(IndexFormatType::HasSegments);

    if (index < numPrimitives)
    {
        if (GetElementSize() == CoreTools::GetStreamSize<int32_t>())
        {
            if (primitiveType == IndexFormatType::PolySegmentDisjoint)
            {
                IncreaseData(index, vertex0, vertex1, 2);
            }
            else
            {
                IncreaseData(index, vertex0, vertex1, 1);
            }
        }
        else
        {
            if (primitiveType == IndexFormatType::PolySegmentDisjoint)
            {
                IncreaseData(index, boost::numeric_cast<uint16_t>(vertex0), boost::numeric_cast<uint16_t>(vertex1), 2);
            }
            else
            {
                IncreaseData(index, boost::numeric_cast<uint16_t>(vertex0), boost::numeric_cast<uint16_t>(vertex1), 1);
            }
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s))
}

Rendering::IndexBuffer::SegmentType Rendering::IndexBuffer::GetSegment(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ValidPrimitiveType(IndexFormatType::HasSegments);

    if (index < numPrimitives)
    {
        if (GetElementSize() == CoreTools::GetStreamSize<int32_t>())
        {
            if (primitiveType == IndexFormatType::PolySegmentDisjoint)
            {
                return GetIncreaseData<int32_t>(index, 2);
            }
            else
            {
                return GetIncreaseData<int32_t>(index, 1);
            }
        }
        else
        {
            if (primitiveType == IndexFormatType::PolySegmentDisjoint)
            {
                return GetIncreaseData<int16_t>(index, 2);
            }
            else
            {
                return GetIncreaseData<int16_t>(index, 1);
            }
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s))
}

void Rendering::IndexBuffer::SetTriangle(int index, int32_t vertex0, int32_t vertex1, int32_t vertex2)
{
    RENDERING_CLASS_IS_VALID_1;

    ValidPrimitiveType(IndexFormatType::HasTriangles);

    if (index < numPrimitives)
    {
        if (GetElementSize() == CoreTools::GetStreamSize<int32_t>())
        {
            if (primitiveType == IndexFormatType::TriMesh)
            {
                IncreaseData(index, vertex0, vertex1, vertex2, 3);
            }
            else if (primitiveType == IndexFormatType::TriStrip)
            {
                if ((index & 1) != 0)
                {
                    IncreaseData(index, vertex0, vertex2, vertex1, 1);
                }
                else
                {
                    IncreaseData(index, vertex0, vertex1, vertex2, 1);
                }
            }
            else if (primitiveType == IndexFormatType::TriMeshAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TrimeshAdj不支持。"s))
            }
            else if (primitiveType == IndexFormatType::TriStripAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TristripAdj不支持。"s))
            }
        }
        else
        {
            if (primitiveType == IndexFormatType::TriMesh)
            {
                IncreaseData(index, boost::numeric_cast<uint16_t>(vertex0), boost::numeric_cast<uint16_t>(vertex1), boost::numeric_cast<uint16_t>(vertex2), 3);
            }
            else if (primitiveType == IndexFormatType::TriStrip)
            {
                if ((index & 1) != 0)
                {
                    IncreaseData(index, boost::numeric_cast<uint16_t>(vertex0), boost::numeric_cast<uint16_t>(vertex2), boost::numeric_cast<uint16_t>(vertex1), 1);
                }
                else
                {
                    IncreaseData(index, boost::numeric_cast<uint16_t>(vertex0), boost::numeric_cast<uint16_t>(vertex1), boost::numeric_cast<uint16_t>(vertex2), 1);
                }
            }
            else if (primitiveType == IndexFormatType::TriMeshAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TrimeshAdj不支持。"s))
            }
            else if (primitiveType == IndexFormatType::TriStripAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TristripAdj不支持。"s))
            }
        }
    }
}

Rendering::IndexBuffer::TriangleType Rendering::IndexBuffer::GetTriangle(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ValidPrimitiveType(IndexFormatType::HasTriangles);

    if (index < numPrimitives)
    {
        if (GetElementSize() == CoreTools::GetStreamSize<int32_t>())
        {
            if (primitiveType == IndexFormatType::TriMesh)
            {
                return GetIncreaseData<int32_t>(index, 3, false);
            }
            else if (primitiveType == IndexFormatType::TriStrip)
            {
                if ((index & 1) != 0)
                {
                    return GetIncreaseData<int32_t>(index, 1, true);
                }
                else
                {
                    return GetIncreaseData<int32_t>(index, 1, false);
                }
            }
            else if (primitiveType == IndexFormatType::TriMeshAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TrimeshAdj不支持。"s))
            }
            else if (primitiveType == IndexFormatType::TriStripAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TristripAdj不支持。"s))
            }
        }
        else
        {
            if (primitiveType == IndexFormatType::TriMesh)
            {
                return GetIncreaseData<int16_t>(index, 3, false);
            }
            else if (primitiveType == IndexFormatType::TriStrip)
            {
                if ((index & 1) != 0)
                {
                    return GetIncreaseData<int16_t>(index, 1, true);
                }
                else
                {
                    return GetIncreaseData<int16_t>(index, 1, false);
                }
            }
            else if (primitiveType == IndexFormatType::TriMeshAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TrimeshAdj不支持。"s))
            }
            else if (primitiveType == IndexFormatType::TriStripAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TristripAdj不支持。"s))
            }
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s))
}

void Rendering::IndexBuffer::ValidPrimitiveType(IndexFormatType type) const
{
    if ((primitiveType & type) == IndexFormatType::Zero)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的primitive类型。"s))
    }
}

int Rendering::IndexBuffer::GetIndexCounter(IndexFormatType type, int numPrimitives)
{
    using IndexCounterFunction = int (*)(int) noexcept;
    constexpr auto numTypes = System::EnumCastUnderlying(IndexFormatType::NumTypes);

    static const std::array<IndexCounterFunction, numTypes> indexCounter{ &IndexBuffer::GetPolyPointIndexCount,
                                                                          &IndexBuffer::GetPolySegmentDisjointIndexCount,
                                                                          &IndexBuffer::GetPolySegmentContiguousIndexCount,
                                                                          &IndexBuffer::GetTriMeshIndexCount,
                                                                          &IndexBuffer::GetTriStripIndexCount,
                                                                          &IndexBuffer::GetPolySegmentDisjointAdjIndexCount,
                                                                          &IndexBuffer::GetPolySegmentContiguousAdjIndexCount,
                                                                          &IndexBuffer::GetTriMeshAdjIndexCount,
                                                                          &IndexBuffer::GetTriStripAdjIndexCount };

    const auto index = Mathematics::BitHacks::Log2OfPowerOfTwo(System::EnumCastUnderlying(type));

    return indexCounter.at(index)(numPrimitives);
}

Rendering::IndexBuffer::RendererObjectSharedPtr Rendering::IndexBuffer::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLIndexBuffer>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}