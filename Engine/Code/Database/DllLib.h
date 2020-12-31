//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 19:26)

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

    #endif  // DATABASE_USE_MYSQL

#endif  // _MSC_VER

#endif  // DATABASE_DLL_LIB_H