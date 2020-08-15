// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 10:38)

#ifndef RENDERING_RESOURCES_TEXTURE_USER_FIELD_H
#define RENDERING_RESOURCES_TEXTURE_USER_FIELD_H

#include "Rendering/RenderingDll.h"

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
    class RENDERING_HIDDEN_DECLARE TextureUserField
    {
    public:
		using ClassType = TextureUserField;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

    public:
        TextureUserField () noexcept;
        
		CLASS_INVARIANT_DECLARE;

		// 用户字段。这些可能是用于存储特定于应用程序的未知纹理类。
		void SetUserField (int index, int userField);
		int GetUserField (int index) const;

		void Load (CoreTools::BufferSource& source);
		void Save (CoreTools::BufferTarget& target) const;
		int GetStreamingSize () const;

		void SaveToFile (WriteFileManager& outFile) const;
		void ReadFromFile (ReadFileManager& inFile);
        
    private:
		// 用户字段用来存储特定于应用程序的数据。
		int m_UserField[TextureMaxUserFields]{};  
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_USER_FIELD_H
