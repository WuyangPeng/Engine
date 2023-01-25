///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.0 (2023/01/15 23:35)

#ifndef SYSTEM_OPENGL_OPENGL_POLYGON_H
#define SYSTEM_OPENGL_OPENGL_POLYGON_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE SetGLPolygonMode(RasterizerStateCullFace face, RasterizerStateFillMode mode) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLPolygonOffset(OpenGLFloat factor, OpenGLFloat units) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_POLYGON_H