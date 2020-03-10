// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 11:09)

#ifndef RENDERING_RESOURCES_SAVE_TEXTURE_H
#define RENDERING_RESOURCES_SAVE_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace Rendering
{
    class Texture;
    
    class RENDERING_DEFAULT_DECLARE SaveTexture
    {
    public:
		using ClassType = SaveTexture;
        
		// ֧�ֱ���ԭʼ����
    public:       
		// ��������.trt�ļ������ý��ϵͳ��
		// ������������1D, 2D, 3D or cube��
		static void SaveToFile(const Texture& texture,const System::String& fileName);    
    };
}


#endif // RENDERING_RESOURCES_SAVE_TEXTURE_H
