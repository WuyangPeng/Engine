/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 19:58)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_FREE_GLUT_H
#define SYSTEM_HELPER_PRAGMA_WARNING_FREE_GLUT_H

#ifdef SYSTEM_USE_GLUT

    #include "System/Helper/PragmaWarning.h"

    #include SYSTEM_WARNING_PUSH

    #include SYSTEM_WARNING_DISABLE(4505)

    #include <gl/freeglut.h>

    #include SYSTEM_WARNING_POP

#endif  // SYSTEM_USE_GLUT

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_FREE_GLUT_H
