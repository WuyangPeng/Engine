///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/17 15:06)

#ifndef RENDERING_RESOURCES_LOAD_TEXTURE_H
#define RENDERING_RESOURCES_LOAD_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "Texture1D.h"
#include "Texture2D.h"
#include "Texture3D.h"
#include "TextureCube.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "Rendering/Resources/ResourcesInternalFwd.h"

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
        template <typename TextureType, int NumDimensions>
        NODISCARD static TextureType CreateTexture1D(ReadFileManager& inFile);

        template <typename TextureType, int NumDimensions, typename ActualType>
        NODISCARD static TextureType CreateTexture2D(ReadFileManager& inFile);

        template <typename TextureType, int NumDimensions>
        NODISCARD static TextureType CreateTexture3D(ReadFileManager& inFile);

        template <typename TextureType, int NumDimensions>
        NODISCARD static TextureType CreateTextureCube(ReadFileManager& inFile);

        template <typename TextureType, int NumDimensions>
        NODISCARD static TextureType CreateTexture1DArray(ReadFileManager& inFile);

        template <typename TextureType, int NumDimensions>
        NODISCARD static TextureType CreateTexture2DArray(ReadFileManager& inFile);

        template <typename TextureType, int NumDimensions>
        NODISCARD static TextureType CreateTextureCubeArray(ReadFileManager& inFile);
    };

}

#endif  // RENDERING_RESOURCES_LOAD_TEXTURE_H
