/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/15 09:11)

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
        // ͼ�������е�DrawIndexed���á�
        NODISCARD static IndexBufferSharedPtr Create(const std::string& name, IndexFormatType type, int numPrimitives, int indexSize, bool createStorage = true);

        /// ���ϣ�������ɶ��㻺�����ж����˳����������ʹ�ô˺������졣
        /// ͼ�������е�Draw���á�����ȷ��numPrimitives��numVertices����VertexBuffer�У�һ�¡�
        /// UsageType��־�����ã���Ϊû��ϵͳ�ڴ���Դ���ݡ�
        NODISCARD static IndexBufferSharedPtr Create(const std::string& name, IndexFormatType type, int numPrimitives);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndexBuffer);

        NODISCARD virtual IndexBufferSharedPtr Clone() const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD bool IsIndexed() const noexcept;
        NODISCARD IndexFormatType GetPrimitiveType() const noexcept;
        NODISCARD int GetNumPrimitives() const noexcept;

        /// ָ����ϣ���������л�����ʱҪ���ƵĻ�����������
        /// Ĭ��ֵΪnumPrimitives��
        /// ����SetNumActivePrimitives��ȷ����������numActive <= numPrimitives��
        void SetNumActivePrimitives(int numActive);
        NODISCARD int GetNumActivePrimitives() const noexcept;
        NODISCARD int GetNumActiveIndices() const;

        /// ָ��Ҫ���Ƶĵ�һ���������������Ĭ��ֵΪ�㡣
        /// ����ƻ�ͬʱ�޸Ļ�������������Ҫ���Ƶĵ�һ�������壬�������û������������
        /// SetFirstPrimitiveȷ��first < numPrimitives �� first + numActive <= numPrimitives��
        void SetFirstPrimitive(int first);
        NODISCARD int GetFirstPrimitive() const noexcept;
        NODISCARD int GetFirstIndex() const;

        /// ֧�ֻ�Ԫ����������/��ȡ��
        /// ������index���ڻ�Ԫ�ķ�Χ��ʱ���������׳��쳣��
        /// �����߸���Ϊ��Ԫ����ʹ����ȷ�ĺ�����
        /// ��Щ������ÿ����Ԫ�Ŀ����������ַ�Χ��������ת������˿�����Щ��һ�ַ��㡣
        /// Ϊ�˻������ٶȣ�������ʹ��
        /// auto indexBuffer = std::make_shared<IndexBuffer>(...);
        /// auto indices = indexBuffer->GetStorage();
        /// ͨ��Increase<type>����  <���� �� ��ȡ indices>;
        /// ���С�type���ǡ�int32_t����int16_t��������ȡ���ڹ��������������ķ�ʽ��
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
            // ��numPrimitives��Чʱ����һ���㡣
            return 0 < numPrimitives ? numPrimitives : 1;
        }

        NODISCARD static constexpr int GetPolygonSegmentDisjointIndexCount(int numPrimitives) noexcept
        {
            // ��numPrimitives��Чʱ������һ���߶Ρ�
            return 0 < numPrimitives ? 2 * numPrimitives : 2;
        }

        NODISCARD static constexpr int GetPolygonSegmentContiguousIndexCount(int numPrimitives) noexcept
        {
            // ��numPrimitives��Чʱ������һ���߶Ρ�
            return 0 < numPrimitives ? numPrimitives + 1 : 2;
        }

        NODISCARD static constexpr int GetTriangleMeshIndexCount(int numPrimitives) noexcept
        {
            // ��numPrimitives��Чʱ������һ�������Ρ�
            return 0 < numPrimitives ? 3 * numPrimitives : 3;
        }

        NODISCARD static constexpr int GetTriangleStripIndexCount(int numPrimitives) noexcept
        {
            // ��numPrimitives��Чʱ������һ�������Ρ�
            return 0 < numPrimitives ? numPrimitives + 2 : 3;
        }

        NODISCARD static constexpr int GetPolygonSegmentDisjointAdjacencyIndexCount(int numPrimitives) noexcept
        {
            // ��numPrimitives��Чʱ������һ���߶����ӡ�
            return 0 < numPrimitives ? 4 * numPrimitives : 4;
        }

        NODISCARD static constexpr int GetPolygonSegmentContiguousAdjacencyIndexCount(int numPrimitives) noexcept
        {
            // ��numPrimitives��Чʱ������һ���߶����ӡ�
            return 0 < numPrimitives ? numPrimitives + 3 : 4;
        }

        NODISCARD static constexpr int GetTriangleMeshAdjacencyIndexCount(int numPrimitives) noexcept
        {
            // ��numPrimitives��Чʱ������һ�����������ӡ�
            return 0 < numPrimitives ? 6 * numPrimitives : 6;
        }

        NODISCARD static constexpr int GetTriangleStripAdjacencyIndexCount(int numPrimitives) noexcept
        {
            // ��numPrimitives��Чʱ������һ�����������ӡ�
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
