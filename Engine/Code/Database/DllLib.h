///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 14:58)

#ifndef DATABASE_DLL_LIB_H
#define DATABASE_DLL_LIB_H

#include "Helper/UserMacro.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#if defined(_MSC_VER)

    #ifdef DATABASE_USE_MYSQL

        #ifdef DATABASE_USE_MYSQL_C_API

            #pragma comment(lib, "mysqlclient.lib")

        #endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        #ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

            #pragma comment(lib, "mysqlcppconn8.lib")

        #endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        #ifdef DATABASE_USE_MONGO

            #pragma comment(lib, "bsoncxx.lib")
            #pragma comment(lib, "mongocxx.lib")

        #endif  // DATABASE_USE_MONGO

        #ifdef DATABASE_USE_REDIS

            #ifdef _DEBUG

                #pragma comment(lib, "hiredisd.lib")

            #else  // !_DEBUG

                #pragma comment(lib, "hiredis.lib")

            #endif  // _DEBUG

        #endif  // DATABASE_USE_REDIS

    #endif  // DATABASE_USE_MYSQL

#endif  // _MSC_VER

#endif  // DATABASE_DLL_LIB_H