///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:25)

#include "Rendering/RenderingExport.h"

#include "IndexBuffer.h"
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
#include "Rendering/Renderers/Flags/RendererTypes.h"

using System::operator&;

CORE_TOOLS_RTTI_DEFINE(Rendering, IndexBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IndexBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IndexBuffer);

Rendering::IndexBuffer::IndexBuffer(MAYBE_UNUSED IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives)
    : ParentType{ GetIndexCounter(type, numPrimitives), 0, GraphicsObjectType::IndexBuffer },
      primitiveType{ type },
      numPrimitives{ numPrimitives },
      numActivePrimitives{ numPrimitives },
      firstPrimitive{ 0 }
{
    if (numPrimitives <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效数量的primitives。"s));
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IndexBuffer::IndexBuffer(MAYBE_UNUSED IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives, int indexSize)
    : ParentType{ GetIndexCounter(type, numPrimitives), indexSize, GraphicsObjectType::IndexBuffer },
      primitiveType{ type },
      numPrimitives{ numPrimitives },
      numActivePrimitives{ numPrimitives },
      firstPrimitive{ 0 }
{
    if (numPrimitives <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效数量的primitives。"s));
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

Rendering::IndexBuffer::IndexBuffer(LoadConstructor value)
    : ParentType{ value },
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
        THROW_EXCEPTION(SYSTEM_TEXT("无效数量的primitives。"s));
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
        return;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的first primitives。"s));
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

void Rendering::IndexBuffer::SetPoint(int i, int32_t v)
{
    RENDERING_CLASS_IS_VALID_1;

    ValidPrimitiveType(IndexFormatType::HasPoints);

    if (i < numPrimitives)
    {
        if (GetElementSize() == sizeof(int32_t))
        {
            auto data = GetData(i * sizeof(int32_t));

            data.Increase<int32_t>(v);
        }
        else
        {
            auto data = GetData(i * sizeof(uint16_t));

            data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v));
        }
    }
}

int32_t Rendering::IndexBuffer::GetPoint(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ValidPrimitiveType(IndexFormatType::HasPoints);

    if (i < numPrimitives)
    {
        if (GetElementSize() == sizeof(int32_t))
        {
            auto data = GetData(i * sizeof(int32_t));

            return data.Increase<int32_t>();
        }
        else
        {
            auto data = GetData(i * sizeof(uint16_t));

            return data.Increase<uint16_t>();
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s));
}

void Rendering::IndexBuffer::SetSegment(int i, int32_t v0, int32_t v1)
{
    RENDERING_CLASS_IS_VALID_1;

    ValidPrimitiveType(IndexFormatType::HasSegments);

    if (i < numPrimitives)
    {
        if (GetElementSize() == sizeof(uint32_t))
        {
            if (primitiveType == IndexFormatType::PolysegmentDisjoint)
            {
                auto data = GetData(2 * i * sizeof(int32_t));

                data.Increase<int32_t>(v0);
                data.Increase<int32_t>(v1);
            }
            else
            {
                auto data = GetData(i * sizeof(int32_t));

                data.Increase<int32_t>(v0);
                data.Increase<int32_t>(v1);
            }
        }
        else
        {
            if (primitiveType == IndexFormatType::PolysegmentDisjoint)
            {
                auto data = GetData(2 * i * sizeof(uint16_t));

                data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v0));
                data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v1));
            }
            else
            {
                auto data = GetData(i * sizeof(uint16_t));

                data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v0));
                data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v1));
            }
        }
    }
}

Rendering::IndexBuffer::SegmentType Rendering::IndexBuffer::GetSegment(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ValidPrimitiveType(IndexFormatType::HasSegments);

    if (i < numPrimitives)
    {
        if (GetElementSize() == sizeof(uint32_t))
        {
            if (primitiveType == IndexFormatType::PolysegmentDisjoint)
            {
                auto data = GetData(2 * i * sizeof(int32_t));

                const auto v0 = data.Increase<int32_t>();
                const auto v1 = data.Increase<int32_t>();

                return { v0, v1 };
            }
            else
            {
                auto data = GetData(i * sizeof(int32_t));

                const auto v0 = data.Increase<int32_t>();
                const auto v1 = data.Increase<int32_t>();

                return { v0, v1 };
            }
        }
        else
        {
            if (primitiveType == IndexFormatType::PolysegmentDisjoint)
            {
                auto data = GetData(2 * i * sizeof(uint16_t));

                const auto v0 = data.Increase<uint16_t>();
                const auto v1 = data.Increase<uint16_t>();

                return { v0, v1 };
            }
            else
            {
                auto data = GetData(i * sizeof(uint16_t));

                const auto v0 = data.Increase<uint16_t>();
                const auto v1 = data.Increase<uint16_t>();

                return { v0, v1 };
            }
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s));
}

void Rendering::IndexBuffer::SetTriangle(int i, int32_t v0, int32_t v1, int32_t v2)
{
    RENDERING_CLASS_IS_VALID_1;

    ValidPrimitiveType(IndexFormatType::HasTriangles);

    if (i < numPrimitives)
    {
        if (GetElementSize() == sizeof(uint32_t))
        {
            if (primitiveType == IndexFormatType::Trimesh)
            {
                auto data = GetData(3 * i * sizeof(int32_t));

                data.Increase<int32_t>(v0);
                data.Increase<int32_t>(v1);
                data.Increase<int32_t>(v2);
            }
            else if (primitiveType == IndexFormatType::Tristrip)
            {
                auto data = GetData(i * sizeof(int32_t));

                data.Increase<int32_t>(v0);
                if ((i & 1) != 0)
                {
                    data.Increase<int32_t>(v2);
                    data.Increase<int32_t>(v1);
                }
                else
                {
                    data.Increase<int32_t>(v1);
                    data.Increase<int32_t>(v2);
                }
            }
            else if (primitiveType == IndexFormatType::TrimeshAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TrimeshAdj不支持。"s));
            }
            else if (primitiveType == IndexFormatType::TristripAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TristripAdj不支持。"s));
            }
        }
        else
        {
            if (primitiveType == IndexFormatType::Trimesh)
            {
                auto data = GetData(3 * i * sizeof(uint16_t));

                data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v0));
                data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v1));
                data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v2));
            }
            else if (primitiveType == IndexFormatType::Tristrip)
            {
                auto data = GetData(i * sizeof(uint16_t));

                data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v0));
                if ((i & 1) != 0)
                {
                    data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v2));
                    data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v1));
                }
                else
                {
                    data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v1));
                    data.Increase<uint16_t>(boost::numeric_cast<uint16_t>(v2));
                }
            }
            else if (primitiveType == IndexFormatType::TrimeshAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TrimeshAdj不支持。"s));
            }
            else if (primitiveType == IndexFormatType::TristripAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TristripAdj不支持。"s));
            }
        }
    }
}

Rendering::IndexBuffer::TriangleType Rendering::IndexBuffer::GetTriangle(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ValidPrimitiveType(IndexFormatType::HasTriangles);

    if (i < numPrimitives)
    {
        if (GetElementSize() == sizeof(uint32_t))
        {
            if (primitiveType == IndexFormatType::Trimesh)
            {
                auto data = GetData(3 * i * sizeof(int32_t));

                const auto v0 = data.Increase<int32_t>();
                const auto v1 = data.Increase<int32_t>();
                const auto v2 = data.Increase<int32_t>();

                return { v0, v1, v2 };
            }
            else if (primitiveType == IndexFormatType::Tristrip)
            {
                auto data = GetData(i * sizeof(int32_t));

                const auto v0 = data.Increase<int32_t>();
                if ((i & 1) != 0)
                {
                    const auto v1 = data.Increase<int32_t>();
                    const auto v2 = data.Increase<int32_t>();

                    return { v0, v2, v1 };
                }
                else
                {
                    const auto v1 = data.Increase<int32_t>();
                    const auto v2 = data.Increase<int32_t>();

                    return { v0, v1, v2 };
                }
            }
            else if (primitiveType == IndexFormatType::TrimeshAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TrimeshAdj不支持。"s));
            }
            else if (primitiveType == IndexFormatType::TristripAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TristripAdj不支持。"s));
            }
        }
        else
        {
            if (primitiveType == IndexFormatType::Trimesh)
            {
                auto data = GetData(3 * i * sizeof(uint16_t));

                const auto v0 = data.Increase<uint16_t>();
                const auto v1 = data.Increase<uint16_t>();
                const auto v2 = data.Increase<uint16_t>();

                return { v0, v1, v2 };
            }
            else if (primitiveType == IndexFormatType::Tristrip)
            {
                auto data = GetData(i * sizeof(uint16_t));

                const auto v0 = data.Increase<uint16_t>();
                if ((i & 1) != 0)
                {
                    const auto v1 = data.Increase<uint16_t>();
                    const auto v2 = data.Increase<uint16_t>();

                    return { v0, v2, v1 };
                }
                else
                {
                    const auto v1 = data.Increase<uint16_t>();
                    const auto v2 = data.Increase<uint16_t>();

                    return { v0, v1, v2 };
                }
            }
            else if (primitiveType == IndexFormatType::TrimeshAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TrimeshAdj不支持。"s));
            }
            else if (primitiveType == IndexFormatType::TristripAdj)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("TristripAdj不支持。"s));
            }
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界。"s));
}

void Rendering::IndexBuffer::ValidPrimitiveType(IndexFormatType type) const
{
    if ((primitiveType & type) == IndexFormatType::Zero)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的primitive类型。"s));
    }
}

int Rendering::IndexBuffer::GetIndexCounter(IndexFormatType type, int numPrimitives)
{
    using IndexCounterFunction = int (*)(int) noexcept;
    constexpr auto numTypes = System::EnumCastUnderlying(IndexFormatType::NumTypes);

    static const std::array<IndexCounterFunction, numTypes> indexCounter{ &IndexBuffer::GetPolypointIndexCount,
                                                                          &IndexBuffer::GetPolysegmentDisjointIndexCount,
                                                                          &IndexBuffer::GetPolysegmentContiguousIndexCount,
                                                                          &IndexBuffer::GetTrimeshIndexCount,
                                                                          &IndexBuffer::GetTristripIndexCount,
                                                                          &IndexBuffer::GetPolysegmentDisjointAdjIndexCount,
                                                                          &IndexBuffer::GetPolysegmentContiguousAdjIndexCount,
                                                                          &IndexBuffer::GetTrimeshAdjIndexCount,
                                                                          &IndexBuffer::GetTristripAdjIndexCount };

    const auto index = Mathematics::BitHacks::Log2OfPowerOfTwo(System::EnumCastUnderlying(type));

    return indexCounter.at(index)(numPrimitives);
}

Rendering::IndexBuffer::RendererObjectSharedPtr Rendering::IndexBuffer::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLIndexBuffer>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}