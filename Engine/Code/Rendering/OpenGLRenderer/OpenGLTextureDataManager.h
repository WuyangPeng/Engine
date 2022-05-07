///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/23 14:34)

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
