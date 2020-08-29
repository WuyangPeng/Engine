// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 10:50)

#ifndef RENDERING_RESOURCES_BUFFER_H
#define RENDERING_RESOURCES_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "VertexFormat.h"
#include "Flags/BufferFlags.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointer.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointer.h"
#include "CoreTools/ObjectSystems/Object.h"

RENDERING_EXPORT_SHARED_PTR(BufferImpl);

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
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(Buffer);
        using ParentType = Object;
        using BufferSmartPointer = CoreTools::ThirdSubclassSmartPointer<ClassType>;
        using ConstBufferSmartPointer = CoreTools::ConstThirdSubclassSmartPointer<ClassType>;
        using ReadFileManager = CoreTools::ReadFileManager;
        using WriteFileManager = CoreTools::WriteFileManager;

    public:
        Buffer();
        Buffer(int numElements, int elementSize, BufferUsage usage);
          ~Buffer() = 0;
        Buffer(Buffer&&) = default;
        Buffer& operator=(Buffer&&) = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Buffer);

        int GetNumElements() const noexcept;
        int GetElementSize() const noexcept;
        BufferUsage GetUsage() const noexcept;

        // 应用程序可能需要不同数量的活跃索引。使用这个函数设置。
        // 它不改变数据存储,只改变缓冲区的m_NumElements成员。
        // 调用者负责保存的原始数量索引和当完成索引缓冲区时重置。
        // 调用者还不应该传入比原来的索引数量大的索引数量。
        void SetNumElements(int numElements);

        // 管理在系统内存缓冲区的副本。
        // 查询系统内存出现在IndexBuffer和VertexBuffer。
        // GetData()访问器应该返回只读数据。
        // 不应该转换到“char*”和写数据，否则渲染器不会知道数据已被修改。
        int GetNumBytes() const;
        const char* GetReadOnlyData() const noexcept;
        const char* GetReadOnlyData(int index) const;

        void SetNewData(const std::vector<char>& newData);

    protected:
        void SaveBufferDataToFile(WriteFileManager& outFile) const;
        void ReadBufferDataFromFile(ReadFileManager& inFile);
        void SaveHeadToFile(WriteFileManager& outFile) const;
        void ReadHeadFromFile(ReadFileManager& inFile);
        void ReadBufferDataFromFile(ReadFileManager& inFile, const ConstVertexFormatSmartPointer& vertexformat);
        void SaveBufferDataToFile(WriteFileManager& outFile, const ConstVertexFormatSmartPointer& vertexformat) const;

        char* GetAccessWriteData(int index);

    private:
        IMPL_TYPE_DECLARE(Buffer);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Buffer);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, Buffer);
}

#endif  // RENDERING_RESOURCES_BUFFER_H
