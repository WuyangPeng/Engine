//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/20 14:00)

// ϵͳ�⣨System����װ�˲���ϵͳ��ص��������󣨰���Window��Linux��Macintosh��Android����
// ϵͳ��λ���������ײ㣬��������������е������⣬���߿�ֻ����ʹ��freeglut��gsl��boost::call_traits��boost::numeric_cast��BOOST_ASSERT���߿⣬��ʹ���������߿⡣
// ʹ�ú�������ľ�̬��Ա��������װ���Ҿ��󲿷ֺ����������noexcept���������ͨ���������ء�
// ����ƽ̨ʹ�õĺ������ϴ�ʱ�����ܻ���ȥ����ֵ�򲿷ֲ���ǿ��ʹ��Ĭ��ֵ������ƽ̨����û����ȷ��ʵ�֡�

#include "System/SystemExport.h"

#include "System/System.h"

#ifndef BUILDING_SYSTEM_STATIC

    #include "DllLib.h"

#else  // BUILDING_SYSTEM_STATIC

namespace System
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_STATIC 