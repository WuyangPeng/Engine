///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 18:08)

#ifndef RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H
#define RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/TextureFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

namespace Rendering
{
    template <int WindowSize>
    class TextureLevelData
    {
    public:
        static_assert(WindowSize == 1 || WindowSize == 2 || WindowSize == 3, "WindowSize must be 1 or 2 or 3.");

        using ClassType = TextureLevelData<WindowSize>;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit TextureLevelData(int numDimensions) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumDimensions() const noexcept;
        NODISCARD int GetDimension(int index, int level) const;
        NODISCARD int GetNumLevelBytes(int level) const;
        NODISCARD int GetNumTotalBytes() const noexcept;
        NODISCARD int GetLevelOffset(int level) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        void SetNumLevelBytes(int level, int aNumLevelBytes);
        void SetDimension(int index, int level, int aDimension);
        void RecountNumTotalBytes(int numLevels, TextureFlags type) noexcept;
        void RecountLevelOffsets(int numLevels) noexcept;

    private:
        int numDimensions;
        std::array<std::array<int, TextureMaximumMipmapLevels>, WindowSize> dimension;
        std::array<int, TextureMaximumMipmapLevels> numLevelBytes;
        int numTotalBytes;
        std::array<int, TextureMaximumMipmapLevels> levelOffsets;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H
