/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:53)

#ifndef RENDERING_RESOURCES_TEXTURE_FLAGS_H
#define RENDERING_RESOURCES_TEXTURE_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    enum class TextureFlags
    {
        Texture1D,
        Texture2D,
        Texture3D,
        TextureCube,
        Quantity
    };

    // 产生纹理最大数量的mipmap级别。这在当代显卡足够多。
    // 一个4096 x 40096的图像有一个最大的13等级。
    constexpr auto textureMaximumMipmapLevels = 16;

    // 用户字段。这些可能是用于存储特定于应用程序的未知信息结构类。
    enum
    {
        TextureMaxUserFields = 8
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_FLAGS_H
