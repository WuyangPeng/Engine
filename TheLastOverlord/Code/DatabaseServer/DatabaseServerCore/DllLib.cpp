///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 20:46)

#include "DatabaseServerCoreExport.h"

#include "DllLib.h"
#include "DatabaseServerCore.h"

#ifdef BUILDING_DATABASE_SERVER_CORE_STATIC
 
namespace DatabaseServerCore
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // BUILDING_DATABASE_SERVER_CORE_STATIC