///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:34)

#ifndef RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_H
#define RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

namespace Rendering
{
    template <typename PlatformTextureType>
    class TextureLockManager
    {
    public:
        using ClassType = TextureLockManager<PlatformTextureType>;

    public:
        explicit TextureLockManager(PlatformTextureType& manager);
        ~TextureLockManager() noexcept;
        TextureLockManager(const TextureLockManager& rhs) noexcept = delete;
        TextureLockManager& operator=(const TextureLockManager& rhs) noexcept = delete;
        TextureLockManager(TextureLockManager&& rhs) noexcept = delete;
        TextureLockManager& operator=(TextureLockManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD void* Lock(int alevel, BufferLocking mode);
        NODISCARD void* Lock(int aFace, int alevel, BufferLocking mode);

    private:
        PlatformTextureType& manager;
        int level;
        int face;
    };
}

#endif  // RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_H
