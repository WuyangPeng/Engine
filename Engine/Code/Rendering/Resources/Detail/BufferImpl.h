///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 10:25)

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

        // 应用程序可能需要不同数量的活跃索引。使用这个函数设置。
        // 它不改变数据存储,只改变缓冲区的m_NumElements成员。
        // 调用者负责保存的原始数量索引和当完成索引缓冲区时重置。
        // 调用者还不应该传入比原来的索引数量大的索引数量。
        void SetNumElements(int32_t newNumElements) noexcept(g_Assert < 1 || g_RenderingAssert < 1);

        // 管理在系统内存缓冲区的副本。
        // 查询系统内存出现在IndexBuffer和VertexBuffer。
        // GetData()访问器应该返回只读数据。
        // 不应该转换到“char*”和写数据，否则渲染器不会知道数据已被修改。
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
