///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/31 14:56)

#ifndef RENDERING_RESOURCES_LOAD_TEXTURE_H
#define RENDERING_RESOURCES_LOAD_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "ResourcesInternalFwd.h"
#include "Texture1D.h"
#include "Texture2D.h"
#include "Texture3D.h"
#include "TextureCube.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LoadTexture
    {
    public:
        using ClassType = LoadTexture;

    public:
        // ���������.trt�ļ������ý��ϵͳ��
        // ������������1D, 2D, 3D ���� cube��
        // �����߿��Բ�ѯ���ص��������͡�
        NODISCARD static TextureSharedPtr LoadFromFile(const System::String& name);
        NODISCARD static Texture1DSharedPtr Load1DFromFile(const System::String& name);
        NODISCARD static Texture2DSharedPtr Load2DFromFile(const System::String& name);
        NODISCARD static Texture3DSharedPtr Load3DFromFile(const System::String& name);
        NODISCARD static TextureCubeSharedPtr LoadCubeFromFile(const System::String& name);

    private:
        using ReadFileManager = CoreTools::ReadFileManager;

    private:
        template <typename TexturePtrType, int WindowSize>
        NODISCARD static TexturePtrType CreateTexture1DPtr(const TextureData& data, ReadFileManager& inFile);

        template <typename TexturePtrType, int WindowSize>
        NODISCARD static TexturePtrType CreateTexture2DPtr(const TextureData& data, ReadFileManager& inFile);

        template <typename TexturePtrType, int WindowSize>
        NODISCARD static TexturePtrType CreateTexture3DPtr(const TextureData& data, ReadFileManager& inFile);

        template <typename TexturePtrType, int WindowSize>
        NODISCARD static TexturePtrType CreateTextureCubePtr(const TextureData& data, ReadFileManager& inFile);
    };
}

#endif  // RENDERING_RESOURCES_LOAD_TEXTURE_H
