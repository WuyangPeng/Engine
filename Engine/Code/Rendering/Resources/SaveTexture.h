// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 11:09)

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
        
		// 支持保存原始纹理。
    public:       
		// 保存纹理到.trt文件外的流媒体系统。
		// 纹理对象可以是1D, 2D, 3D or cube。
		static void SaveToFile(const Texture& texture,const System::String& fileName);    
    };
}


#endif // RENDERING_RESOURCES_SAVE_TEXTURE_H
