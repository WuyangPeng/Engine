///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 20:20)

#include "Rendering/RenderingExport.h"

#include "SaveTexture.h"
#include "Texture.h"
#include "CoreTools/FileManager/WriteFileManager.h"

using CoreTools::WriteFileManager;

void Rendering::SaveTexture::SaveToFile(const Texture& texture, const System::String& fileName)
{
    WriteFileManager manager{ fileName };
    texture.SaveToFile(manager);
}
