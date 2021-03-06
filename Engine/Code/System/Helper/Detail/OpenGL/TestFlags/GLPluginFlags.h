//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:40)

#ifndef SYSTEM_HELPER_GL_PLUGIN_FLAGS_H
#define SYSTEM_HELPER_GL_PLUGIN_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
    enum class GlPluginFlags
    {
        Enter,
        NonNull,
        NullFunction,
        ExitFunction,
    };
}

#endif  // SYSTEM_HELPER_GL_PLUGIN_FLAGS_H
