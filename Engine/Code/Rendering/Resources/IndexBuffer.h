///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/30 11:45)

#ifndef RENDERING_RESOURCES_INDEX_BUFFER_H
#define RENDERING_RESOURCES_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE IndexBuffer : public Buffer
    {
    public:
        using ClassType = IndexBuffer;
        using ParentType = Buffer;
        using IndexBufferSharedPtr = std::shared_ptr<ClassType>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const ClassType>;

    public:
        NODISCARD static IndexBufferSharedPtr Create();
        NODISCARD static IndexBufferSharedPtr Create(int numIndices, int indexSize, BufferUsage usage = BufferUsage::Static);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndexBuffer);

        // ������ƫ������ʹ������Ⱦ�����ơ�
        // ����������������ڶ������ͼԪ��������������ʱ����,
        // ÿ����Ԫʹ��һ������������
        // �����������,Ӧ�ó������ÿһ������Ԫ�ض�̬����SetNumElements��SetOffset��
        void SetOffset(int aOffset) noexcept;
        NODISCARD int GetOffset() const noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        NODISCARD virtual IndexBufferSharedPtr Clone() const;

        void InitIndexBuffer();
        void InitIndexBufferInParticles();
        void InitIndexBufferInRectangle(int index, int rectangleIndex0, int rectangleIndex1, int rectangleIndex2, int rectangleIndex3);
        void InitIndexBufferInDisk(int radialSamplesMinus1, int shellSamplesMinus1);
        void InitIndexBuffer(const std::vector<int>& indices);

        void SetIndexBuffer(int index, MAYBE_UNUSED int original, int current);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        enum class IndexBufferCreate
        {
            Init,
        };

    public:
        explicit IndexBuffer(MAYBE_UNUSED IndexBufferCreate indexBufferCreate);
        IndexBuffer(MAYBE_UNUSED IndexBufferCreate indexBufferCreate, int numIndices, int indexSize, BufferUsage usage = BufferUsage::Static);

    private:
        int32_t offset;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(IndexBuffer);

#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(IndexBuffer);
}

#endif  // RENDERING_RESOURCES_INDEX_BUFFER_H
