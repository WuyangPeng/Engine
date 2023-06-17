///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:02)

#include "Rendering/RenderingExport.h"

#include "TextureManagementLockEncapsulationDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture1D>>::~TextureManagementLockEncapsulation() noexcept
{
    EXCEPTION_TRY
    {
        if (texture != nullptr)
        {
            manager.Unlock(texture, level);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture2D>>::~TextureManagementLockEncapsulation() noexcept
{
    EXCEPTION_TRY
    {
        if (texture != nullptr)
        {
            manager.Unlock(texture, level);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <> 
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture3D>>::~TextureManagementLockEncapsulation() noexcept
{
    EXCEPTION_TRY
    {
        if (texture != nullptr)
        {
            manager.Unlock(texture, level);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTextureCube>>::~TextureManagementLockEncapsulation() noexcept
{
    EXCEPTION_TRY
    {
        if (texture != nullptr)
        {
            manager.UnlockCube(texture, face, level);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}
