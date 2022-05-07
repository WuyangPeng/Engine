///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:37)

#include "Rendering/RenderingExport.h"

#include "TextureLockManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <>
Rendering::TextureLockManager<Rendering::PlatformTexture1D>::~TextureLockManager() noexcept
{
    EXCEPTION_TRY
    {
        if (level != -1)
        {
            manager.Unlock(level);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTexture2D>::~TextureLockManager() noexcept
{
    EXCEPTION_TRY
    {
        if (level != -1)
        {
            manager.Unlock(level);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTexture3D>::~TextureLockManager() noexcept
{
    EXCEPTION_TRY
    {
        if (level != -1)
        {
            manager.Unlock(level);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::TextureLockManager<Rendering::PlatformTextureCube>::~TextureLockManager() noexcept
{
    EXCEPTION_TRY
    {
        if (level != -1)
        {
            manager.Unlock(face, level);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}
