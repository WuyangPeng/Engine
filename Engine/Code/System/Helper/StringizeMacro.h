/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:52)

#ifndef SYSTEM_HELPER_STRINGIZE_MACRO_H
#define SYSTEM_HELPER_STRINGIZE_MACRO_H

#define SYSTEM_STRINGIZE(x) SYSTEM_DO_STRINGIZE(x)
#define SYSTEM_DO_STRINGIZE(x) #x

#define SYSTEM_CONCATENATOR(lhs, rhs) SYSTEM_DO_CONCATENATOR(lhs, rhs)
#define SYSTEM_DO_CONCATENATOR(lhs, rhs) SYSTEM_DO_CONCATENATOR_DETAIL(lhs, rhs)
#define SYSTEM_DO_CONCATENATOR_DETAIL(lhs, rhs) lhs##rhs

#define SYSTEM_MULTIPLE_CONCATENATOR(lhs, mhs, rhs) SYSTEM_CONCATENATOR(lhs, SYSTEM_CONCATENATOR(mhs, rhs))

#endif  // SYSTEM_HELPER_STRINGIZE_MACRO_H
