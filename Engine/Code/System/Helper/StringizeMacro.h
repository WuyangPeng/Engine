//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 1:02)

#ifndef SYSTEM_HELPER_STRINGIZE_MACRO_H
#define SYSTEM_HELPER_STRINGIZE_MACRO_H

#define SYSTEM_STRINGIZE(x) SYSTEM_DO_STRINGIZE(x)
#define SYSTEM_DO_STRINGIZE(x) #x

#define SYSTEM_CONCATENATOR(lhs, rhs) SYSTEM_DO_CONCATENATOR(lhs, rhs)
#define SYSTEM_DO_CONCATENATOR(lhs, rhs) SYSTEM_DO_CONCATENATOR_DETAIL(lhs, rhs)
#define SYSTEM_DO_CONCATENATOR_DETAIL(lhs, rhs) lhs##rhs

#define SYSTEM_MULTIPLE_CONCATENATOR(lhs, mhs, rhs) SYSTEM_CONCATENATOR(lhs, SYSTEM_CONCATENATOR(mhs, rhs))

#endif  // SYSTEM_HELPER_STRINGIZE_MACRO_H
