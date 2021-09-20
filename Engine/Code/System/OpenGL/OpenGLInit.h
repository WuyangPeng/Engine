///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/24 19:59)

#ifndef SYSTEM_OPENGL_OPENGL_INIT_H
#define SYSTEM_OPENGL_OPENGL_INIT_H

#include "System/SystemDll.h"

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE OpenGLInit();

    SYSTEM_DEFAULT_DECLARE void PrintOpenGLInfo();
    SYSTEM_DEFAULT_DECLARE void PrintWglExtensionsInfo();
}

#endif  // SYSTEM_OPENGL_OPENGL_INIT_H
