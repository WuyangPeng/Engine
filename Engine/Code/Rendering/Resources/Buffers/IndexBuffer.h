/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/15 09:11)

#ifndef RENDERING_RESOURCES_INDEX_BUFFER_H
#define RENDERING_RESOURCES_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
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
        // 图形引擎中的DrawIndexed调用。
        NODISCARD static IndexBufferSharedPtr Create(const std::string& name, IndexFormatType type, int numPrimitives, int indexSize, bool createStorage = true);

        /// 如果希望索引由顶点缓冲区中顶点的顺序隐含，请使用此函数构造。
        /// 图形引擎中的Draw调用。必须确保numPrimitives和numVertices（在VertexBuffer中）一致。
        /// UsageType标志不适用，因为没有系统内存资源数据。
        NODISCARD static IndexBufferSharedPtr Create(const std::string& name, IndexFormatType type, int numPrimitives);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndexBuffer);

        NODISCARD virtual IndexBufferSharedPtr Clone() const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD bool IsIndexed() const noexcept;
        NODISCARD IndexFormatType GetPrimitiveType() const noexcept;
        NODISCARD int GetNumPrimitives() const noexcept;

        /// 指定不希望绘制所有基本体时要绘制的基本体数量。
        /// 默认值为numPrimitives。
        /// 函数SetNumActivePrimitives可确保输入满足numActive <= numPrimitives。
        void SetNumActivePrimitives(int numActive);
        NODISCARD int GetNumActivePrimitives() const noexcept;
        NODISCARD int GetNumActiveIndices() const;

        /// 指定要绘制的第一个基本体的索引。默认值为零。
        /// 如果计划同时修改活动基本体的数量和要绘制的第一个基本体，请先设置活动基本体数量。
        /// SetFirstPrimitive确保first < numPrimitives 和 first + numActive <= numPrimitives。
        void SetFirstPrimitive(int first);
        NODISCARD int GetFirstPrimitive() const noexcept;
        NODISCARD int GetFirstIndex() const;

        /// 支持基元索引的设置/获取。
        /// 当索引index不在基元的范围内时，函数将抛出异常。
        /// 调用者负责为基元类型使用正确的函数。
        /// 这些函数有每个基元的开销，即各种范围检查和类型转换，因此考虑这些是一种方便。
        /// 为了获得最佳速度，您可以使用
        /// auto indexBuffer = std::make_shared<IndexBuffer>(...);
        /// auto indices = indexBuffer->GetStorage();
        /// 通过Increase<type>函数  <设置 或 获取 indices>;
        /// 其中“type”是“int32_t”或“int16_t”，具体取决于构建索引缓冲区的方式。
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
        IndexBuffer(const std::string& name, IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives, int indexSize, bool createStorage);
        IndexBuffer(const std::string& name, IndexBufferCreate indexBufferCreate, IndexFormatType type, int numPrimitives);

    private:
        NODISCARD static int GetIndexCounter(IndexFormatType type, int numPrimitives);

        NODISCARD static constexpr int GetPolygonPointIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时创建一个点。
            return 0 < numPrimitives ? numPrimitives : 1;
        }

        NODISCARD static constexpr int GetPolygonSegmentDisjointIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时，创建一个线段。
            return 0 < numPrimitives ? 2 * numPrimitives : 2;
        }

        NODISCARD static constexpr int GetPolygonSegmentContiguousIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时，创建一个线段。
            return 0 < numPrimitives ? numPrimitives + 1 : 2;
        }

        NODISCARD static constexpr int GetTriangleMeshIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时，创建一个三角形。
            return 0 < numPrimitives ? 3 * numPrimitives : 3;
        }

        NODISCARD static constexpr int GetTriangleStripIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时，创建一个三角形。
            return 0 < numPrimitives ? numPrimitives + 2 : 3;
        }

        NODISCARD static constexpr int GetPolygonSegmentDisjointAdjacencyIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时，创建一个线段连接。
            return 0 < numPrimitives ? 4 * numPrimitives : 4;
        }

        NODISCARD static constexpr int GetPolygonSegmentContiguousAdjacencyIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时，创建一个线段连接。
            return 0 < numPrimitives ? numPrimitives + 3 : 4;
        }

        NODISCARD static constexpr int GetTriangleMeshAdjacencyIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时，创建一个三角形连接。
            return 0 < numPrimitives ? 6 * numPrimitives : 6;
        }

        NODISCARD static constexpr int GetTriangleStripAdjacencyIndexCount(int numPrimitives) noexcept
        {
            // 当numPrimitives无效时，创建一个三角形连接。
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

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(IndexBuffer);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(IndexBuffer);
}

#endif  // RENDERING_RESOURCES_INDEX_BUFFER_H
