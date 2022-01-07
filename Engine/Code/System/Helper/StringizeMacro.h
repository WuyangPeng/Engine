///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 17:50)

#ifndef SYSTEM_HELPER_STRINGIZE_MACRO_H
#define SYSTEM_HELPER_STRINGIZE_MACRO_H

#define SYSTEM_STRINGIZE(x) SYSTEM_DO_STRINGIZE(x)
#define SYSTEM_DO_STRINGIZE(x) #x

#define SYSTEM_CONCATENATOR(lhs, rhs) SYSTEM_DO_CONCATENATOR(lhs, rhs)
#define SYSTEM_DO_CONCATENATOR(lhs, rhs) SYSTEM_DO_CONCATENATOR_DETAIL(lhs, rhs)
#define SYSTEM_DO_CONCATENATOR_DETAIL(lhs, rhs) lhs##rhs

#define SYSTEM_MULTIPLE_CONCATENATOR(lhs, mhs, rhs) SYSTEM_CONCATENATOR(lhs, SYSTEM_CONCATENATOR(mhs, rhs))

#endif  // SYSTEM_HELPER_STRINGIZE_MACRO_H
