// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 10:17)

#ifndef RENDERING_RESOURCES_TEXTURE_DATA_H
#define RENDERING_RESOURCES_TEXTURE_DATA_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureData
    {
    public:
		using ClassType = TextureData;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

    public:
        TextureData (TextureFormat format, TextureFlags type,BufferUsage usage,int numLevels) noexcept;
		TextureData() noexcept;
        
		CLASS_INVARIANT_DECLARE;

        TextureFormat GetFormat () const noexcept;
        TextureFlags GetTextureType () const noexcept;
        BufferUsage GetUsage () const noexcept;
        int GetNumLevels () const noexcept;       
        bool IsCompressed () const noexcept;

		void SetNumLevels(int numLevels) noexcept;

		void Load (CoreTools::BufferSource& source);
		void Save (CoreTools::BufferTarget& target) const;
		int GetStreamingSize () const;		

		void SaveToFile (WriteFileManager& outFile) const;
		void ReadFromFile (ReadFileManager& inFile);
        
    private:
        TextureFormat m_Format;
        TextureFlags m_Type;
        BufferUsage m_Usage;
        int m_NumLevels;      
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_DATA_H
