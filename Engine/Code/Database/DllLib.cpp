//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 19:27)

// ���ݿ⣨Database��λ������ĵ����㣬ֻ������������е�System��CoreTools�⣬��ʹ��boost��stlsoft���������ݿ���صĹ��߿⡣
// ��Ҫ��MySQL��SQL Server��һ��ƽ���ļ����ݿ���з�װ��

#include "Database/DatabaseExport.h"

#include "Database/Database.h"

#ifndef BUILDING_DATABASE_STATIC

    #include "DllLib.h"

#else  // BUILDING_DATABASE_STATIC

namespace Database
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DATABASE_STATIC
