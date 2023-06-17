///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:22)

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
