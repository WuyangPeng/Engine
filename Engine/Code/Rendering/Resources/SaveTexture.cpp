///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 15:00)

#include "Rendering/RenderingExport.h"

#include "SaveTexture.h"
#include "Texture.h"
#include "CoreTools/FileManager/WriteFileManager.h"

using CoreTools::WriteFileManager;

// static
void Rendering::SaveTexture::SaveToFile(const Texture& texture, const System::String& fileName)
{
    WriteFileManager manager{ fileName };
    texture.SaveToFile(manager);
}
