///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 14:37)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureDataDetail.h"
#include "OpenGLTextureDataManageDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <>
Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture1D>>::~OpenGLTextureDataManager() noexcept
{
    EXCEPTION_TRY
    {
        if (managerLevel != -1)
        {
            manager.Unlock(managerLevel);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture2D>>::~OpenGLTextureDataManager() noexcept
{
    EXCEPTION_TRY
    {
        if (managerLevel != -1)
        {
            manager.Unlock(managerLevel);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture3D>>::~OpenGLTextureDataManager() noexcept
{
    EXCEPTION_TRY
    {
        if (managerLevel != -1)
        {
            manager.Unlock(managerLevel);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::TextureCube>>::~OpenGLTextureDataManager() noexcept
{
    EXCEPTION_TRY
    {
        if (managerLevel != -1)
        {
            manager.Unlock(managerFace, managerLevel);
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)

    RENDERING_SELF_CLASS_IS_VALID_9;
}
