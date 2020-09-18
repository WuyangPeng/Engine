// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 10:19)

#ifndef RENDERING_RESOURCES_TEXTURE_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureData.h"
#include "TextureBuffer.h" 
#include "TextureUserField.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "System/Helper/EnumCast.h"

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
    class RENDERING_HIDDEN_DECLARE TextureImpl
    {
    public:
		using ClassType = TextureImpl;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;
		using TextureImplPtr = std::shared_ptr<ClassType>;

    public:
        TextureImpl (TextureFormat format,TextureFlags type,BufferUsage usage,int numLevels);
        virtual ~TextureImpl();
		TextureImpl(const TextureImpl&) = default;
		TextureImpl& operator=(const TextureImpl&) = default;
		TextureImpl( TextureImpl&&) = default;
		TextureImpl& operator=( TextureImpl&&) = default;
        
		CLASS_INVARIANT_VIRTUAL_DECLARE;

        TextureFormat GetFormat () const noexcept;
        TextureFlags GetTextureType () const noexcept;
        BufferUsage GetUsage () const noexcept;
        int GetNumLevels () const noexcept;
        
        virtual int GetNumDimensions () const = 0;
        virtual int GetDimension (int index, int level) const  = 0;
        virtual int GetNumLevelBytes (int level) const  = 0;
        virtual int GetNumTotalBytes () const = 0;
        virtual int GetLevelOffset (int level) const = 0;
        
        void GenerateMipmaps ();
        bool HasMipmaps () const;
        
        int GetPixelSize () const;
        static int GetPixelSize (TextureFormat format);
        bool IsCompressed () const noexcept;
        bool IsMipmapable () const;

		// 管理系统内存纹理的一个副本。字节数通过GetNumTotalBytes()查询。
		// 查询系统的内存发生在Texture1D，Texture2D，Texture3D和TextureCube。
		// GetReadOnlyData()访问器应该返回只读数据。
		// 不要转换类型为“char*”去写,渲染器不会知道数据已被修改。
        const char* GetReadOnlyData () const;

		// 用户字段。这些可能是用于存储特定于应用程序的未知纹理类。
        void SetUserField (int index, int userField);
        int GetUserField (int index) const;
        
		void Load (CoreTools::BufferSource& source);
		void Save (const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize () const;              
      
		void SaveToFile (WriteFileManager& outFile) const;
		void ReadFromFile (ReadFileManager& inFile);		

		static int CalculateNumDimensions (TextureFlags type);
		static int CalculateItemSize(TextureFormat format);

    protected:        
		char* GetWriteData();	
		void SetNumLevels(int numLevels) noexcept;
		void ExpandFileBufferSizeOnCube();	
		void ResetTextureBufferNum();

		virtual int GetMaxLevels() const = 0;
        
    private:
        virtual void LoadLevelData (CoreTools::BufferSource& source) = 0;
		virtual void SaveLevelData (const CoreTools::BufferTargetSharedPtr& target) const = 0;
		virtual int GetLevelDataStreamingSize () const = 0;

		virtual void SaveLevelDataToFile (WriteFileManager& outFile) const = 0;
		virtual void LoadLevelDataFromFile (ReadFileManager& inFile) = 0;

		void RecomputationLevelBytes();		

		virtual void ExpandFileBufferSize();

		virtual void DoGenerateMipmaps() = 0;
		virtual void ComputeNumLevelBytes() = 0;
		virtual void VerifyNumLevels() = 0;
		
	private:
   		// 成员的值通过构造函数传递。
        TextureData m_TextureData;

		// 用户字段来存储特定于应用程序的数据。
        TextureUserField m_TextureUserField;

		// 纹理的系统内存复制，使用在加载和更新视频内存
		TextureBuffer m_Data;

        static int sm_NumDimensions[System::EnumCastUnderlying(TextureFlags::Quantity)];
        static int sm_PixelSize[System::EnumCastUnderlying(TextureFormat::Quantity)];
        static bool sm_Mipmapable[System::EnumCastUnderlying(TextureFormat::Quantity)];
		static int sm_ItemSize[System::EnumCastUnderlying(TextureFormat::Quantity)];
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_IMPL_H
