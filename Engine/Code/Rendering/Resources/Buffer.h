///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 10:15)

#ifndef RENDERING_RESOURCES_BUFFER_H
#define RENDERING_RESOURCES_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "VertexFormat.h"
#include "Flags/BufferFlags.h"
#include "CoreTools/Base/SpanIterator.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Buffer, BufferImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Buffer : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Buffer);
        using ParentType = Object;
        using BufferSharedPtr = std::shared_ptr<ClassType>;
        using ConstBufferSharedPtr = std::shared_ptr<ClassType>;
        using ReadFileManager = CoreTools::ReadFileManager;
        using WriteFileManager = CoreTools::WriteFileManager;
        using SpanIterator = CoreTools::SpanIterator<std::vector<char>::const_iterator>;
        using WriteSpanIterator = CoreTools::SpanIterator<std::vector<char>::iterator>;

    public:
        explicit Buffer(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        Buffer(int numElements, int elementSize, BufferUsage usage);
        ~Buffer() noexcept = 0;
        Buffer(const Buffer& rhs) = default;
        Buffer& operator=(const Buffer& rhs) = default;
        Buffer(Buffer&& rhs) noexcept = default;
        Buffer& operator=(Buffer&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Buffer);

        NODISCARD int GetNumElements() const noexcept;
        NODISCARD int GetElementSize() const noexcept;
        NODISCARD BufferUsage GetUsage() const noexcept;

        // 应用程序可能需要不同数量的活跃索引。使用这个函数设置。
        // 它不改变数据存储,只改变缓冲区的m_NumElements成员。
        // 调用者负责保存的原始数量索引和当完成索引缓冲区时重置。
        // 调用者还不应该传入比原来的索引数量大的索引数量。
        void SetNumElements(int numElements) noexcept(g_Assert < 1 || g_RenderingAssert < 1);

        // 管理在系统内存缓冲区的副本。
        // 查询系统内存出现在IndexBuffer和VertexBuffer。
        // GetData()访问器应该返回只读数据。
        // 不应该转换到“char*”和写数据，否则渲染器不会知道数据已被修改。
        NODISCARD int GetNumBytes() const;
        NODISCARD const char* GetReadOnlyData() const noexcept;
        NODISCARD const char* GetReadOnlyData(int index) const;
        NODISCARD SpanIterator GetSpanIterator() const noexcept;
        NODISCARD WriteSpanIterator GetWriteSpanIterator() noexcept;

        void SetNewData(const std::vector<char>& newData);

    protected:
        void SaveBufferDataToFile(WriteFileManager& outFile) const;
        void ReadBufferDataFromFile(ReadFileManager& inFile);
        void SaveHeadToFile(WriteFileManager& outFile) const;
        void ReadHeadFromFile(ReadFileManager& inFile);
        void ReadBufferDataFromFile(ReadFileManager& inFile, const VertexFormat& vertexformat);
        void SaveBufferDataToFile(WriteFileManager& outFile, const VertexFormat& vertexformat) const;

        NODISCARD char* GetAccessWriteData(int index);

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Buffer);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Buffer);
}

#endif  // RENDERING_RESOURCES_BUFFER_H
