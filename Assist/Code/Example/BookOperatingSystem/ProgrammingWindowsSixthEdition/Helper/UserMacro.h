///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/12 16:56)

#ifndef PROGRAMMING_WINDOWS_SIXTH_EDITION_MACRO_USER_MACRO_H
#define PROGRAMMING_WINDOWS_SIXTH_EDITION_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define PROGRAMMING_WINDOWS_SIXTH_EDITION_ClOSE_BEGIN (0x01)

#define CLOSE_USE_PROGRAMMING_WINDOWS_SIXTH_EDITION (PROGRAMMING_WINDOWS_SIXTH_EDITION_ClOSE_BEGIN)

#define PROGRAMMING_WINDOWS_SIXTH_EDITION_ClOSE_END CLOSE_USE_PROGRAMMING_WINDOWS_SIXTH_EDITION

#define CLOSE_PROGRAMMING_WINDOWS_SIXTH_EDITION_MAX ((PROGRAMMING_WINDOWS_SIXTH_EDITION_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE 0x00

static_assert(0 <= COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE, "COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE <= CLOSE_PROGRAMMING_WINDOWS_SIXTH_EDITION_MAX, "COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE Must be less than or equal CLOSE_PROGRAMMING_WINDOWS_SIXTH_EDITION_MAX.");

#if !defined(COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE) || (COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE & CLOSE_USE_PROGRAMMING_WINDOWS_SIXTH_EDITION) != CLOSE_USE_PROGRAMMING_WINDOWS_SIXTH_EDITION

#endif  // !defined(COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE) || (COMPILE_PROGRAMMING_WINDOWS_SIXTH_EDITION_CLOSE & CLOSE_USE_PROGRAMMING_WINDOWS_SIXTH_EDITION) != CLOSE_USE_PROGRAMMING_WINDOWS_SIXTH_EDITION

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_PROGRAMMING_WINDOWS_SIXTH_EDITION_STATIC
#endif  // BUILDING_STATIC

#endif  // PROGRAMMING_WINDOWS_SIXTH_EDITION_MACRO_USER_MACRO_H
