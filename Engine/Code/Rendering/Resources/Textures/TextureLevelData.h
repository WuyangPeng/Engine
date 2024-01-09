/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:56)

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
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        TextureLevelData() noexcept;
        explicit TextureLevelData(int numItems, int dimension0, bool hasMipMaps, int elementSize, int numLevels);
        explicit TextureLevelData(int numItems, int dimension0, int dimension1, bool hasMipMaps, int elementSize, int numLevels);
        explicit TextureLevelData(int numItems, int dimension0, int dimension1, int dimension2, bool hasMipMaps, int elementSize, int numLevels);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumItems() const noexcept;
        NODISCARD int GetNumDimensions() const noexcept;
        NODISCARD int GetDimension(int index) const;
        NODISCARD bool HasMipMaps() const noexcept;
        NODISCARD int GetDimension(int level, int index) const;
        NODISCARD int GetNumLevelBytes(int level) const;
        NODISCARD int GetLevelOffset(int item, int level) const;

        void SetDimension(int level, int index, int dimension);
        void SetNumLevelBytes(int level, int aNumLevelBytes);

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void AutoGenerateMipMaps() noexcept;
        NODISCARD bool WantAutoGenerateMipMaps() const noexcept;

    private:
        using LevelDimensionType = std::array<std::array<int, NumDimensions>, textureMaximumMipmapLevels>;
        using LevelNumBytesType = std::array<int, textureMaximumMipmapLevels>;
        using LevelOffsetsType = std::array<int, textureMaximumMipmapLevels>;
        using LevelOffsetsContainer = std::vector<LevelOffsetsType>;

    private:
        void Init(int dimension0, int dimension1, int dimension2, int elementSize, int numLevels);
        void InitLevelOffsetsNoMipMaps(int numLevels);
        void InitLevelOffsetsHasMipMaps(int numLevels);

    private:
        int numItems;
        LevelDimensionType levelDimension;
        LevelNumBytesType levelNumBytes;
        LevelOffsetsContainer levelOffsets;
        bool hasMipMaps;
        bool autoGenerateMipMaps;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H
