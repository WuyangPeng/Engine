///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/16 22:01)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_FREEGLUT_H
#define SYSTEM_HELPER_PRAGMA_WARNING_FREEGLUT_H

#ifdef SYSTEM_USE_GLUT

    #include "System/Helper/PragmaWarning.h"

    #include STSTEM_WARNING_PUSH

    #include SYSTEM_WARNING_DISABLE(4505)

    #include <gl/freeglut.h>

    #include STSTEM_WARNING_POP

#endif  // SYSTEM_USE_GLUT

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_FREEGLUT_H
