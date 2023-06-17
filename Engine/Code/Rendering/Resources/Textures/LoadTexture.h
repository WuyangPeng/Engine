///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:24)

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
        // 加载纹理从.trt文件外的流媒体系统。
        // 纹理对象可以是1D, 2D, 3D 或者 cube。
        // 调用者可以查询返回的纹理类型。
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
