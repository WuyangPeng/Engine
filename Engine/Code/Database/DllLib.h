///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/24 17:24)

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