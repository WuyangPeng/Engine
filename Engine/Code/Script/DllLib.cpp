//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 14:34)

// �ű��⣨Script��λ������ĵ����㣬ֻ������������е�System��CoreTools�⣬��ʹ��boost��stlsoft�������ű���صĹ��߿⡣
// ��Ҫ�Խű��ĵ��ýӿڽ��з�װ��

#include "Script/ScriptExport.h"

#include "Script/Script.h"

#ifndef BUILDING_SCRIPT_STATIC

    #include "DllLib.h"

#else  // BUILDING_SCRIPT_STATIC

namespace Script
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SCRIPT_STATIC