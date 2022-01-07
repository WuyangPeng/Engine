///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/06 21:22)

#ifndef COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_MACRO_USER_MACRO_H
#define COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS (COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_ClOSE_BEGIN)

#define COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_ClOSE_END CLOSE_USE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS

#define CLOSE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_MAX ((COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE 0x00

static_assert(0 <= COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE, "COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE <= CLOSE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_MAX, "COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE Must be less than or equal CLOSE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_MAX.");

#if !defined(COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE) || (COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE & CLOSE_USE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS) != CLOSE_USE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS

#endif  // !defined(COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE) || (COMPILE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_CLOSE & CLOSE_USE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS) != CLOSE_USE_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_STATIC
#endif  // BUILDING_STATIC

#endif  // COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_MACRO_USER_MACRO_H
