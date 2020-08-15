// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 11:10)

#ifndef RENDERING_RESOURCES_TEXTURE_H
#define RENDERING_RESOURCES_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "Flags/BufferFlags.h"
#include "Flags/TextureFlags.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointer.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointer.h"

namespace CoreTools
{
    class FileBuffer;
	class WriteFileManager;
	class ReadFileManager;	
}

namespace Rendering
{
	class TextureImpl;

    class RENDERING_DEFAULT_DECLARE Texture : public CoreTools::Object
    {
    public:
		using ClassType = Texture;
		using ImplType = TextureImpl;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
		using ParentType = Object;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;
		using FileBuffer = CoreTools::FileBuffer;
        using FileBufferPtr = std::shared_ptr<FileBuffer>;
		using TextureSmartPointer = std::shared_ptr<ClassType>;
		using ConstTextureSmartPointer = std::shared_ptr<const ClassType>;

 	public:
        Texture ();
     
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(Texture);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE; 
        
        virtual TextureFormat GetFormat () const = 0;
        virtual TextureFlags GetTextureType () const = 0;
        virtual BufferUsage GetUsage () const = 0;
        virtual int GetNumLevels () const = 0;
        
        virtual int GetNumDimensions () const = 0;
        virtual int GetDimension (int i, int level) const = 0;
        virtual int GetNumLevelBytes (int level) const = 0;
        virtual int GetNumTotalBytes () const = 0;
        virtual int GetLevelOffset (int level) const = 0;
        
        virtual int GetPixelSize () const = 0;
        static int GetPixelSize (TextureFormat format);
        virtual bool IsCompressed () const = 0;
        virtual bool IsMipmapable () const = 0;

        // 用户字段。这些可能是用于存储特定于应用程序的未知纹理类。
        virtual void SetUserField (int i, int userField) = 0;
        virtual int GetUserField (int i) const = 0;
        
		// 支持mipmap产生。
        virtual void GenerateMipmaps () = 0;
        virtual bool HasMipmaps () const = 0;
        
     	virtual void SaveToFile (WriteFileManager& outFile) const = 0;
		virtual void ReadFromFile (ReadFileManager& inFile) = 0;

		virtual TextureSmartPointer Clone() const = 0;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)     
	CORE_TOOLS_STREAM_REGISTER(Texture);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, Texture); 
}

#endif // RENDERING_RESOURCES_TEXTURE_H
