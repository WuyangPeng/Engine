// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:17)

#ifndef RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H
#define RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/TextureFlags.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
    class WriteFileManager;
    class ReadFileManager;
}

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

        int GetNumDimensions() const noexcept;
        int GetDimension(int index, int level) const;
        int GetNumLevelBytes(int level) const;
        int GetNumTotalBytes() const noexcept;
        int GetLevelOffset(int level) const;

        void Load(const CoreTools::BufferSourceSharedPtr& source);
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        int GetStreamingSize() const noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        void SetNumLevelBytes(int level, int numLevelBytes);
        void SetDimension(int index, int level, int dimension);
        void RecountNumTotalBytes(int numLevels, TextureFlags type) noexcept;
        void RecountLevelOffsets(int numLevels) noexcept;

    private:
        int m_NumDimensions;
        int m_Dimension[WindowSize][TextureMaximumMipmapLevels]{};
        int m_NumLevelBytes[TextureMaximumMipmapLevels]{};
        int m_NumTotalBytes;
        int m_LevelOffsets[TextureMaximumMipmapLevels]{};
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_H
