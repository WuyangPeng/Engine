///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

namespace Rendering
{
    template <typename ManageType>
    class OpenGLTextureDataManager
    {
    public:
        using ClassType = OpenGLTextureDataManager<ManageType>;

    public:
        explicit OpenGLTextureDataManager(ManageType& manager) noexcept;
        ~OpenGLTextureDataManager() noexcept;
        OpenGLTextureDataManager(const OpenGLTextureDataManager& rhs) = delete;
        OpenGLTextureDataManager& operator=(const OpenGLTextureDataManager& rhs) = delete;
        OpenGLTextureDataManager(OpenGLTextureDataManager&& rhs) noexcept = delete;
        OpenGLTextureDataManager& operator=(OpenGLTextureDataManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD void* Lock(int level, BufferLocking mode) noexcept;
        NODISCARD void* Lock(int face, int level, BufferLocking mode) noexcept;

    private:
        ManageType& manager;
        int managerLevel;
        int managerFace;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_H
