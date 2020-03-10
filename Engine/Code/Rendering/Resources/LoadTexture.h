// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 10:53)

#ifndef RENDERING_RESOURCES_LOAD_TEXTURE_H
#define RENDERING_RESOURCES_LOAD_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "Texture1D.h"
#include "Texture2D.h"
#include "Texture3D.h"
#include "TextureCube.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointer.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointer.h"

#include <string>

namespace CoreTools
{
	class ReadFileManager;
}

namespace Rendering
{
    class TextureData;

    class RENDERING_DEFAULT_DECLARE LoadTexture
    {
    public:
		using ClassType = LoadTexture;
		
    public:   
		// ���������.trt�ļ������ý��ϵͳ��
		// ������������1D, 2D, 3D ���� cube��
		// �����߿��Բ�ѯ���ص��������͡�
		static TextureSmartPointer LoadFromFile(const System::String& name);
		static Texture1DSmartPointer Load1DFromFile(const System::String& name);
		static Texture2DSmartPointer Load2DFromFile(const System::String& name);
		static Texture3DSmartPointer Load3DFromFile(const System::String& name);
		static TextureCubeSmartPointer LoadCubeFromFile(const System::String& name);
               
	private:
		using ReadFileManager = CoreTools::ReadFileManager;

	private:
		template<typename TexturePtrType,int WindowSize>
		static TexturePtrType CreateTexture1DPtr(const TextureData& data,ReadFileManager& inFile);
		template<typename TexturePtrType,int WindowSize>
		static TexturePtrType CreateTexture2DPtr(const TextureData& data,ReadFileManager& inFile);

		template<typename TexturePtrType,int WindowSize>
		static TexturePtrType CreateTexture3DPtr(const TextureData& data,ReadFileManager& inFile);

		template<typename TexturePtrType,int WindowSize>
		static TexturePtrType CreateTextureCubePtr(const TextureData& data,ReadFileManager& inFile);        
    };
}
#endif // RENDERING_RESOURCES_LOAD_TEXTURE_H
