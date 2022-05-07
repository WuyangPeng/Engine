///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/30 10:25)

#ifndef RENDERING_RESOURCES_BUFFER_IMPL_H
#define RENDERING_RESOURCES_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SpanIterator.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/VertexFormat.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BufferImpl
    {
    public:
        using ClassType = BufferImpl;
        using ReadFileManager = CoreTools::ReadFileManager;
        using WriteFileManager = CoreTools::WriteFileManager;
        using SpanIterator = CoreTools::SpanIterator<std::vector<char>::const_iterator>;
        using WriteSpanIterator = CoreTools::SpanIterator<std::vector<char>::iterator>;

    public:
        BufferImpl() noexcept;
        BufferImpl(int numElements, int elementSize, BufferUsage usage);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int32_t GetNumElements() const noexcept;
        NODISCARD int32_t GetElementSize() const noexcept;
        NODISCARD BufferUsage GetUsage() const noexcept;

        // Ӧ�ó��������Ҫ��ͬ�����Ļ�Ծ������ʹ������������á�
        // �����ı����ݴ洢,ֻ�ı仺������m_NumElements��Ա��
        // �����߸��𱣴��ԭʼ���������͵��������������ʱ���á�
        // �����߻���Ӧ�ô����ԭ�������������������������
        void SetNumElements(int32_t newNumElements) noexcept(g_Assert < 1 || g_RenderingAssert < 1);

        // ������ϵͳ�ڴ滺�����ĸ�����
        // ��ѯϵͳ�ڴ������IndexBuffer��VertexBuffer��
        // GetData()������Ӧ�÷���ֻ�����ݡ�
        // ��Ӧ��ת������char*����д���ݣ�������Ⱦ������֪�������ѱ��޸ġ�
        NODISCARD int GetNumBytes() const;
        NODISCARD const char* GetReadOnlyData() const noexcept;
        NODISCARD const char* GetReadOnlyData(int index) const;
        NODISCARD SpanIterator GetSpanIterator() const noexcept;
        NODISCARD WriteSpanIterator GetWriteSpanIterator() noexcept;

        void SaveBufferDataToFile(WriteFileManager& outFile) const;
        void ReadBufferDataFromFile(ReadFileManager& inFile);
        void ReadHeadFromFile(ReadFileManager& inFile);
        void SaveHeadToFile(WriteFileManager& outFile) const;
        void ReadBufferDataFromFile(ReadFileManager& inFile, const VertexFormat& vertexformat);
        void SaveBufferDataToFile(WriteFileManager& outFile, const VertexFormat& vertexformat) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD char* GetAccessWriteData(int index);

        void SetNewData(const std::vector<char>& newData);

    private:
        int32_t numElements;
        int32_t elementSize;
        BufferUsage usage;
        std::vector<char> data;
    };
}

#endif  // RENDERING_RESOURCES_BUFFER_IMPL_H
