///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:24)

#ifndef RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H
#define RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

#include <array>
#include <vector>

namespace Rendering
{
    template <int NumDimensions>
    class TextureLevelData
    {
    public:
        static_assert(NumDimensions == 1 || NumDimensions == 2 || NumDimensions == 3, "NumDimensions must be 1 or 2 or 3.");

        using ClassType = TextureLevelData<NumDimensions>;
        using ReadFileManager = CoreTools::ReadFileManager;
        using WriteFileManager = CoreTools::WriteFileManager;

    public:
        TextureLevelData() noexcept;
        explicit TextureLevelData(int numItems, int dimension0, bool hasMipmaps, int elementSize, int numLevels);
        explicit TextureLevelData(int numItems, int dimension0, int dimension1, bool hasMipmaps, int elementSize, int numLevels);
        explicit TextureLevelData(int numItems, int dimension0, int dimension1, int dimension2, bool hasMipmaps, int elementSize, int numLevels);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumItems() const noexcept;
        NODISCARD int GetNumDimensions() const noexcept;
        NODISCARD int GetDimension(int index) const;
        NODISCARD bool HasMipmaps() const noexcept;
        NODISCARD int GetDimension(int level, int index) const;
        NODISCARD int GetNumLevelBytes(int level) const;
        NODISCARD int GetLevelOffset(int item, int level) const;

        void SetDimension(int level, int index, int dimension);
        void SetNumLevelBytes(int level, int aNumLevelBytes);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        void AutogenerateMipmaps() noexcept;
        NODISCARD bool WantAutogenerateMipmaps() const noexcept;

    private:
        using LevelDimensionType = std::array<std::array<int, NumDimensions>, textureMaximumMipmapLevels>;
        using LevelNumBytesType = std::array<int, textureMaximumMipmapLevels>;
        using LevelOffsetsType = std::array<int, textureMaximumMipmapLevels>;
        using LevelOffsetsContainer = std::vector<LevelOffsetsType>;

    private:
        void Init(int dimension0, int dimension1, int dimension2, int elementSize, int numLevels);
        void InitLevelOffsetsNoMipmaps(int numLevels);
        void InitLevelOffsetsHasMipmaps(int numLevels);

    private:
        int numItems;
        LevelDimensionType levelDimension;
        LevelNumBytesType levelNumBytes;
        LevelOffsetsContainer levelOffsets;
        bool hasMipmaps;
        bool autogenerateMipmaps;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H
