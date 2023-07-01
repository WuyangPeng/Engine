///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 14:45)

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

        void SetPoint(int index, int32_t vertex);
        NODISCARD int32_t GetPoint(int index) const;
        void SetSegment(int index, int32_t vertex0, int32_t vertex1);
        NODISCARD SegmentType GetSegment(int index) const;
        void SetTriangle(int index, int32_t vertex0, int32_t vertex1, int32_t vertex2);
        NODISCARD TriangleType GetTriangle(int index) const;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    protected:
        void ValidPrimitiveType(IndexFormatType type) const;

    protected:
        enum class IndexBufferCreate
        {
            Init,
        };

    public:
        IndexBuffer(IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives, int indexSize);
        IndexBuffer(IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives);

    private:
        NODISCARD static int GetIndexCounter(IndexFormatType type, int numPrimitives);

        NODISCARD static constexpr int GetPolyPointIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? numPrimitives : 1;
        }

        NODISCARD static constexpr int GetPolySegmentDisjointIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 2 * numPrimitives : 2;
        }

        NODISCARD static constexpr int GetPolySegmentContiguousIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? numPrimitives + 1 : 2;
        }

        NODISCARD static constexpr int GetTriMeshIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 3 * numPrimitives : 3;
        }

        NODISCARD static constexpr int GetTriStripIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? numPrimitives + 2 : 3;
        }

        NODISCARD static constexpr int GetPolySegmentDisjointAdjIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 4 * numPrimitives : 4;
        }

        NODISCARD static constexpr int GetPolySegmentContiguousAdjIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? numPrimitives + 3 : 4;
        }

        NODISCARD static constexpr int GetTriMeshAdjIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 6 * numPrimitives : 6;
        }

        NODISCARD static constexpr int GetTriStripAdjIndexCount(int numPrimitives) noexcept
        {
            return 0 < numPrimitives ? 2 * (numPrimitives + 2) : 6;
        }

        template <typename T>
        void IncreaseData(int index, T vertex);

        template <typename T>
        NODISCARD T GetIncreaseData(int index) const;

        template <typename T>
        void IncreaseData(int index, T vertex0, T vertex1, int multiple);

        template <typename T>
        NODISCARD SegmentType GetIncreaseData(int index, int multiple) const;

        template <typename T>
        void IncreaseData(int index, T vertex0, T vertex1, T vertex2, int multiple);

        template <typename T>
        NODISCARD TriangleType GetIncreaseData(int index, int multiple, bool changePosition) const;

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
