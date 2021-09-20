///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:03)

#ifndef DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_HELPER_USER_MACRO_H
#define DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_ClOSE_BEGIN (0x01)

#define CLOSE_USE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION (DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_ClOSE_BEGIN)

#define DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_ClOSE_END CLOSE_USE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION

#define CLOSE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_MAX ((DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE 0x00

static_assert(0 <= COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE, "COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE <= CLOSE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_MAX, "COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE Must be less than or equal CLOSE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_MAX.");

#if !defined(COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE) || (COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE & CLOSE_USE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION) != CLOSE_USE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION

#endif  // !defined(COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE) || (COMPILE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_CLOSE & CLOSE_USE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION) != CLOSE_USE_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_STATIC
#endif  // BUILDING_STATIC

#endif  // DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_HELPER_USER_MACRO_H
