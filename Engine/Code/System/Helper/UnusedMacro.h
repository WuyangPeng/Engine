// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 23:18)

#ifndef SYSTEM_HELPER_UNUSED_MACRO_H
#define SYSTEM_HELPER_UNUSED_MACRO_H

// 用于消除未使用参数的警告

#define SYSTEM_UNUSED_ARG(arg) do { } while (&arg == nullptr)

#endif // SYSTEM_HELPER_UNUSED_MACRO_H