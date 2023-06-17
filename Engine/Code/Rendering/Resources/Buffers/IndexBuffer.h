///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:22)

#ifndef RENDERING_RESOURCES_INDEX_BUFFER_H
#define RENDERING_RESOURCES_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/IndexFormat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IndexBuffer : public Buffer
    {
    public:
        using ClassType = IndexBuffer;
        using ParentType = Buffer;
        using IndexBufferSharedPtr = std::shared_ptr<ClassType>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const ClassType>;
        using SegmentType = std::pair<int32_t, int32_t>;
        using TriangleType = std::tuple<int32_t, int32_t, int32_t>;

    public:
        NODISCARD static IndexBufferSharedPtr Create(IndexFormatType type, int numPrimitives);
        NODISCARD static IndexBufferSharedPtr Create(IndexFormatType type, int numPrimitives, int indexSize);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndexBuffer);

        NODISCARD virtual IndexBufferSharedPtr Clone() const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD IndexFormatType GetPrimitiveType() const noexcept;

        NODISCARD int GetNumPrimitives() const noexcept;
        void SetNumActivePrimitives(int numActive);
        NODISCARD int GetNumActivePrimitives() const noexcept;
        NODISCARD int GetNumActiveIndices() const;
        void SetFirstPrimitive(int first);
        NODISCARD int GetFirstPrimitive() const noexcept;
        NODISCARD int GetFirstIndex() const;

        void SetPoint(int i, int32_t v);
        NODISCARD int32_t GetPoint(int i) const;
        void SetSegment(int i, int32_t v0, int32_t v1);
        NODISCARD SegmentType GetSegment(int i) const;
        void SetTriangle(int i, int32_t v0, int32_t v1, int32_t v2);
        NODISCARD TriangleType GetTriangle(int i) const;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    protected:
        void ValidPrimitiveType(IndexFormatType type) const;

    protected:
        enum class IndexBufferCreate
        {
            Init,
        };

    public:
        IndexBuffer(MAYBE_UNUSED IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives, int indexSize);
        IndexBuffer(MAYBE_UNUSED IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives);

    private:
        NODISCARD static int GetIndexCounter(IndexFormatType type, int numPrimitives);

        NODISCARD static constexpr int GetPolypointIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? numPrimitives : 1;
        }

        NODISCARD static constexpr int GetPolysegmentDisjointIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 2 * numPrimitives : 2;
        }

        NODISCARD static constexpr int GetPolysegmentContiguousIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? numPrimitives + 1 : 2;
        }

        NODISCARD static constexpr int GetTrimeshIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 3 * numPrimitives : 3;
        }

        NODISCARD static constexpr int GetTristripIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? numPrimitives + 2 : 3;
        }

        NODISCARD static constexpr int GetPolysegmentDisjointAdjIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 4 * numPrimitives : 4;
        }

        NODISCARD static constexpr int GetPolysegmentContiguousAdjIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? numPrimitives + 3 : 4;
        }

        NODISCARD static constexpr int GetTrimeshAdjIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 6 * numPrimitives : 6;
        }

        NODISCARD static constexpr int GetTristripAdjIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 2 * (numPrimitives + 2) : 6;
        }

    private:
        IndexFormatType primitiveType;
        int numPrimitives;
        int numActivePrimitives;
        int firstPrimitive;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(IndexBuffer);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(IndexBuffer);
}

#endif  // RENDERING_RESOURCES_INDEX_BUFFER_H
