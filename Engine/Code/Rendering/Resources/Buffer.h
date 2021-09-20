// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/19 10:50)

#ifndef RENDERING_RESOURCES_BUFFER_H
#define RENDERING_RESOURCES_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "VertexFormat.h"
#include "Flags/BufferFlags.h"


#include "CoreTools/ObjectSystems/Object.h"

 
EXPORT_SHARED_PTR(Rendering, BufferImpl, RENDERING_DEFAULT_DECLARE);
namespace CoreTools
{
    class WriteFileManager;
    class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Buffer : public CoreTools::Object
    {
    public:
    public:
        void Swap(Buffer& rhs) noexcept;

    public:
        TYPE_DECLARE(Buffer);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~Buffer() noexcept =0;
        Buffer(const Buffer& rhs);
        Buffer& operator=(const Buffer& rhs);
        Buffer(Buffer&& rhs) noexcept;
        Buffer& operator=(Buffer&& rhs) noexcept;
        using ParentType = Object;
        using BufferSharedPtr = std::shared_ptr<ClassType>;
        using ConstBufferSharedPtr = std::shared_ptr<ClassType>;
        using ReadFileManager = CoreTools::ReadFileManager;
        using WriteFileManager = CoreTools::WriteFileManager;

    public:
        Buffer();
        Buffer(int numElements, int elementSize, BufferUsage usage);
          

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Buffer);

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

        void SetNewData(const std::vector<char>& newData);

    protected:
        void SaveBufferDataToFile(WriteFileManager& outFile) const;
        void ReadBufferDataFromFile(ReadFileManager& inFile);
        void SaveHeadToFile(WriteFileManager& outFile) const;
        void ReadHeadFromFile(ReadFileManager& inFile);
        void ReadBufferDataFromFile(ReadFileManager& inFile, const ConstVertexFormatSharedPtr& vertexformat);
        void SaveBufferDataToFile(WriteFileManager& outFile, const ConstVertexFormatSharedPtr& vertexformat) const;

        char* GetAccessWriteData(int index);

    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Buffer);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( Buffer);
}

#endif  // RENDERING_RESOURCES_BUFFER_H
