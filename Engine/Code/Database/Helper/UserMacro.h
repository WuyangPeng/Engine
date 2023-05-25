///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 15:07)

#ifndef DATABASE_DATABASE_MACRO_USER_MACRO_H
#define DATABASE_DATABASE_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define DATABASE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_MYSQL (DATABASE_ClOSE_BEGIN)
#define CLOSE_USE_MYSQL_C_API (DATABASE_ClOSE_BEGIN << 1)
#define CLOSE_USE_MYSQL_CPP_CONNECTOR (DATABASE_ClOSE_BEGIN << 2)
#define CLOSE_USE_SQL_SERVER (DATABASE_ClOSE_BEGIN << 3)
#define CLOSE_USE_SQLITE (DATABASE_ClOSE_BEGIN << 4)
#define CLOSE_USE_POSTGRE (DATABASE_ClOSE_BEGIN << 5)
#define CLOSE_USE_ORACLE (DATABASE_ClOSE_BEGIN << 6)
#define CLOSE_USE_MARIADB (DATABASE_ClOSE_BEGIN << 7)
#define CLOSE_USE_MONGO (DATABASE_ClOSE_BEGIN << 8)
#define CLOSE_USE_REDIS (DATABASE_ClOSE_BEGIN << 9)

#define DATABASE_ClOSE_END CLOSE_USE_REDIS

#define CLOSE_DATABASE_MAX (((DATABASE_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x3FF）
#define COMPILE_DATABASE_CLOSE 0x00

static_assert(0 <= COMPILE_DATABASE_CLOSE, "COMPILE_DATABASE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DATABASE_CLOSE <= CLOSE_DATABASE_MAX, "COMPILE_DATABASE_CLOSE Must be less than or equal CLOSE_DATABASE_MAX.");

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL) != CLOSE_USE_MYSQL

    #define DATABASE_USE_MYSQL static_cast<void>(0)

#endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL) != CLOSE_USE_MYSQL

#ifdef DATABASE_USE_MYSQL

    #if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL_C_API) != CLOSE_USE_MYSQL_C_API

        #define DATABASE_USE_MYSQL_C_API static_cast<void>(0)

    #endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL_C_API) != CLOSE_USE_MYSQL_C_API

    #if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL_CPP_CONNECTOR) != CLOSE_USE_MYSQL_CPP_CONNECTOR

        #define DATABASE_USE_MYSQL_CPP_CONNECTOR static_cast<void>(0)

    #endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL_CPP_CONNECTOR) != CLOSE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_USE_MYSQL

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_SQL_SERVER) != CLOSE_USE_SQL_SERVER

    #define DATABASE_USE_SQL_SERVER static_cast<void>(0)

#endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_SQL_SERVER) != CLOSE_USE_SQL_SERVER

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_SQLITE) != CLOSE_USE_SQLITE

    #define DATABASE_USE_SQLITE static_cast<void>(0)

#endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_SQLITE) != CLOSE_USE_SQLITE

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_POSTGRE) != CLOSE_USE_POSTGRE

    #define DATABASE_USE_POSTGRE static_cast<void>(0)

#endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_POSTGRE) != CLOSE_USE_POSTGRE

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_ORACLE) != CLOSE_USE_ORACLE

    #define DATABASE_USE_ORACLE static_cast<void>(0)

#endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_ORACLE) != CLOSE_USE_ORACLE

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MARIADB) != CLOSE_USE_MARIADB

    #define DATABASE_USE_MARIADB static_cast<void>(0)

#endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MARIADB) != CLOSE_USE_MARIADB

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MONGO) != CLOSE_USE_MONGO

    #define DATABASE_USE_MONGO static_cast<void>(0)

#endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MONGO) != CLOSE_USE_MONGO

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_REDIS) != CLOSE_USE_REDIS

    #define DATABASE_USE_REDIS static_cast<void>(0)

#endif  // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_REDIS) != CLOSE_USE_REDIS

#ifdef BUILDING_STATIC

    #define BUILDING_DATABASE_STATIC static_cast<void>(0)

#endif  // BUILDING_STATIC

#endif  // DATABASE_DATABASE_MACRO_USER_MACRO_H
