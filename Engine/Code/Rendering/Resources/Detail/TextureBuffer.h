// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 09:48)

#ifndef RENDERING_RESOURCES_TEXTURE_BUFFER_H
#define RENDERING_RESOURCES_TEXTURE_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h" 
#include "Rendering/DataTypes/Flags/TextureFormat.h"

#include <memory>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
    class FileBuffer;	
	class WriteFileManager;
	class ReadFileManager;	
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureBuffer
    {
    public:
		using ClassType = TextureBuffer;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;
		using FileBuffer = CoreTools::FileBuffer;
        using FileBufferPtr = std::shared_ptr<FileBuffer>;

    public:
		explicit TextureBuffer(int itemSize) noexcept;
		TextureBuffer(const TextureBuffer& rhs);
		TextureBuffer& operator=(const TextureBuffer& rhs);
		TextureBuffer( TextureBuffer&& rhs) = default;
		TextureBuffer& operator=( TextureBuffer&& rhs) = default;
        ~TextureBuffer()= default;
		
		CLASS_INVARIANT_DECLARE; 

		void Reset(int bufferSize);
		int GetSize() const;
		
        const char* GetReadOnlyData () const;
		char* GetWriteData();
        
		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;              
      
		void SaveToFile (WriteFileManager& outFile) const;
		void ReadFromFile (ReadFileManager& inFile);	

		void ExpandFileBufferSize(int newNumTotalBytes, int numLevel0Bytes);
		void ExpandFileBufferSizeOnCube(int newNumTotalBytes, int numLevel0Bytes);
  		
	private:
		// 纹理的系统内存复制，使用在加载和更新视频内存
        FileBufferPtr m_Data;

		int m_ItemSize;
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_BUFFER_H
