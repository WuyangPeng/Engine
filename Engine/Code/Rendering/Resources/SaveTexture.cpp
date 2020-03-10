// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/19 15:39)

#include "Rendering/RenderingExport.h"

#include "SaveTexture.h"
#include "Texture.h"
#include "CoreTools/FileManager/WriteFileManager.h"

using CoreTools::WriteFileManager;

// static
void Rendering::SaveTexture
	::SaveToFile( const Texture& texture, const System::String& fileName )
{
	WriteFileManager manager{ fileName };
	texture.SaveToFile(manager);
}
