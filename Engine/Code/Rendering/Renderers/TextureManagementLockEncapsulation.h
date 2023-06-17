///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:38)

#ifndef RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_H
#define RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

namespace Rendering
{
    template <typename TextureManagementType>
    class TextureManagementLockEncapsulation
    {
    public:
        using ClassType = TextureManagementLockEncapsulation<TextureManagementType>;
        using ConstTextureSharedPtr = typename TextureManagementType::ConstTextureSharedPtr;

    public:
        explicit TextureManagementLockEncapsulation(TextureManagementType& manager) noexcept;
        ~TextureManagementLockEncapsulation() noexcept;
        TextureManagementLockEncapsulation(const TextureManagementLockEncapsulation& rhs) = delete;
        TextureManagementLockEncapsulation& operator=(const TextureManagementLockEncapsulation& rhs) = delete;
        TextureManagementLockEncapsulation(TextureManagementLockEncapsulation&& rhs) noexcept = delete;
        TextureManagementLockEncapsulation& operator=(TextureManagementLockEncapsulation&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD void* Lock(ConstTextureSharedPtr aTexture, int aLevel, BufferLocking mode);
        NODISCARD void* LockCube(ConstTextureSharedPtr aTexture, int aFace, int aLevel, BufferLocking mode);

    private:
        TextureManagementType& manager;
        ConstTextureSharedPtr texture;
        int level;
        int face;
    };
}

#endif  // RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_H
