// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 10:38)

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

		// �û��ֶΡ���Щ���������ڴ洢�ض���Ӧ�ó����δ֪�����ࡣ
		void SetUserField (int index, int userField);
		int GetUserField (int index) const;

		void Load (CoreTools::BufferSource& source);
		void Save (CoreTools::BufferTarget& target) const;
		int GetStreamingSize () const;

		void SaveToFile (WriteFileManager& outFile) const;
		void ReadFromFile (ReadFileManager& inFile);
        
    private:
		// �û��ֶ������洢�ض���Ӧ�ó�������ݡ�
		int m_UserField[TextureMaxUserFields]{};  
    };
}

#endif // RENDERING_RESOURCES_TEXTURE_USER_FIELD_H
