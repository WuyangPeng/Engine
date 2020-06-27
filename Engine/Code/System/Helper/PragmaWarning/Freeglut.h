// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/08 19:26)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_FREEGLUT_H
#define SYSTEM_HELPER_PRAGMA_WARNING_FREEGLUT_H 

#ifdef SYSTEM_USE_GLUT

	#include "System/Helper/PragmaWarning.h"

	#include STSTEM_WARNING_PUSH

		#include SYSTEM_WARNING_DISABLE(4505) 

		#include <gl/freeglut.h>

	#include STSTEM_WARNING_POP

#endif // SYSTEM_USE_GLUT

#endif // SYSTEM_HELPER_PRAGMA_WARNING_FREEGLUT_H
