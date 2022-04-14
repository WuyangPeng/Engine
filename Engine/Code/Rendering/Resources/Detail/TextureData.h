///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/30 20:08)

#ifndef RENDERING_RESOURCES_TEXTURE_DATA_H
#define RENDERING_RESOURCES_TEXTURE_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureData
    {
    public:
        using ClassType = TextureData;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        TextureData(TextureFormat format, TextureFlags type, BufferUsage usage, int numLevels) noexcept;
        TextureData() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD TextureFormat GetFormat() const noexcept;
        NODISCARD TextureFlags GetTextureType() const noexcept;
        NODISCARD BufferUsage GetUsage() const noexcept;
        NODISCARD int32_t GetNumLevels() const noexcept;
        NODISCARD bool IsCompressed() const noexcept;

        void SetNumLevels(int32_t aNumLevels) noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        TextureFormat format;
        TextureFlags textureFlags;
        BufferUsage usage;
        int32_t numLevels;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_DATA_H
