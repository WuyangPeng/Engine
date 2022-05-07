///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 15:36)

#ifndef RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H
#define RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace Rendering
{
    using UInt = System::OpenGLUInt;
    using Int = System::OpenGLInt;

    // ֧�ְ󶨺����°󶨡� BindTexture�����������ָ����Ŀ�겢������ǰ�󶨵�Ŀ������
    // GetBoundTexture����ָ��Ŀ��ĵ�ǰ�󶨵�����
    NODISCARD RENDERING_DEFAULT_DECLARE UInt BindTexture(ShaderFlags::SamplerType target, UInt texture);
    NODISCARD RENDERING_DEFAULT_DECLARE UInt GetBoundTexture(ShaderFlags::SamplerType target);
}

#endif  // RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H
