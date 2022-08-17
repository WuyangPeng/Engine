///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/17 11:46)

#ifndef RENDERING_RESOURCES_SAVE_TEXTURE_H
#define RENDERING_RESOURCES_SAVE_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Rendering/Resources/ResourcesFwd.h"

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
        static void SaveToFile(const Texture& texture, const System::String& fileName);
    };
}

#endif  // RENDERING_RESOURCES_SAVE_TEXTURE_H
