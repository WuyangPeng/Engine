///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:24)

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
