// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/19 09:29)

#ifndef RENDERING_RESOURCES_BUFFER_IMPL_H
#define RENDERING_RESOURCES_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/VertexFormat.h"

#include <vector>

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
    class WriteFileManager;
    class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BufferImpl
    {
    public:
        using ClassType = BufferImpl;
        using ReadFileManager = CoreTools::ReadFileManager;
        using WriteFileManager = CoreTools::WriteFileManager;

    public:
        BufferImpl() noexcept;
        BufferImpl(int numElements, int elementSize, BufferUsage usage);

        CLASS_INVARIANT_DECLARE;

        int GetNumElements() const noexcept;
        int GetElementSize() const noexcept;
        BufferUsage GetUsage() const noexcept;

        // Ӧ�ó��������Ҫ��ͬ�����Ļ�Ծ������ʹ������������á�
        // �����ı����ݴ洢,ֻ�ı仺������m_NumElements��Ա��
        // �����߸��𱣴��ԭʼ���������͵��������������ʱ���á�
        // �����߻���Ӧ�ô����ԭ�������������������������
        void SetNumElements(int numElements);

        // ������ϵͳ�ڴ滺�����ĸ�����
        // ��ѯϵͳ�ڴ������IndexBuffer��VertexBuffer��
        // GetData()������Ӧ�÷���ֻ�����ݡ�
        // ��Ӧ��ת������char*����д���ݣ�������Ⱦ������֪�������ѱ��޸ġ�
        int GetNumBytes() const;
        const char* GetReadOnlyData() const noexcept;
        const char* GetReadOnlyData(int index) const;

        void SaveBufferDataToFile(WriteFileManager& outFile) const;
        void ReadBufferDataFromFile(ReadFileManager& inFile);
        void ReadHeadFromFile(ReadFileManager& inFile);
        void SaveHeadToFile(WriteFileManager& outFile) const;
        void ReadBufferDataFromFile(ReadFileManager& inFile, const ConstVertexFormatSmartPointer& vertexformat);
        void SaveBufferDataToFile(WriteFileManager& outFile, const ConstVertexFormatSmartPointer& vertexformat) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        int GetStreamingSize() const;

        char* GetAccessWriteData(int index);

        void SetNewData(const std::vector<char>& newData);

    private:
        int m_NumElements;
        int m_ElementSize;
        BufferUsage m_Usage;
        std::vector<char> m_Data;
    };
}

#endif  // RENDERING_RESOURCES_BUFFER_IMPL_H
