//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 17:06)

// ����⣨Network����װ��������������á�
// �����λ������ĵ����㣬ֻ������������е�System��CoreTools�⣬��ʹ��boost��stlsoft��ACE���߿⡣

#include "Network/NetworkExport.h"

#ifndef BUILDING_NETWORK_STATIC

    #include "DllLib.h"

#else  // BUILDING_NETWORK_STATIC

namespace Network
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_NETWORK_STATIC