///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 19:21)

#ifndef RENDERING_RESOURCES_TEXTURE_BUFFER_H
#define RENDERING_RESOURCES_TEXTURE_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureBuffer
    {
    public:
        using ClassType = TextureBuffer;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;
        using FileBuffer = CoreTools::FileBuffer;
        using FileBufferSharedPtr = std::shared_ptr<FileBuffer>;

    public:
        explicit TextureBuffer(int itemSize) noexcept;
        ~TextureBuffer() noexcept = default;
        TextureBuffer(const TextureBuffer& rhs);
        TextureBuffer& operator=(const TextureBuffer& rhs);
        TextureBuffer(TextureBuffer&& rhs) noexcept;
        TextureBuffer& operator=(TextureBuffer&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Reset(int bufferSize);
        NODISCARD int GetSize() const;

        NODISCARD const char* GetReadOnlyData() const;
        NODISCARD char* GetWriteData();

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        void ExpandFileBufferSize(int newNumTotalBytes, int numLevel0Bytes);
        void ExpandFileBufferSizeOnCube(int newNumTotalBytes, int numLevel0Bytes);

    private:
        // 纹理的系统内存复制，使用在加载和更新视频内存
        FileBufferSharedPtr data;

        int itemSize;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_BUFFER_H
