///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:46)

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
