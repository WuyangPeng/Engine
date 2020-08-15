// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 09:29)

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
