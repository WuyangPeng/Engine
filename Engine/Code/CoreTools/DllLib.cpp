//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/09/28 11:52)

// ���Ĺ��߿⣨CoreTools����װ������ĺ��Ĺ��ߡ���ʵ�� RAII����Դ��ȡ����ʼ������RRID����Դ�ͷż���������
// ���Ĺ��߿�λ������ĵڶ��㣬ֻ������������е�System�⣬��ʹ��boost��stlsoft���߿⡣
// ��Ҫ���಻��ʽ�����ԡ��������ࡢ�쳣���ļ�������־����͵�Ԫ���Կ�ܵȹ����ࡣ

#include "CoreToolsExport.h"

#include "CoreTools.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CORE_TOOLS_STATIC

namespace CoreTools
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // BUILDING_CORE_TOOLS_STATIC