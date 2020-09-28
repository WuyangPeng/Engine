//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 10:54)

#ifndef SYSTEM_WINDOW_ENGINEERING_H
#define SYSTEM_WINDOW_ENGINEERING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace System
{
    [[nodiscard]] String SYSTEM_DEFAULT_DECLARE GetEngineeringSuffix();
    [[nodiscard]] String SYSTEM_DEFAULT_DECLARE GetEngineeringExeSuffix();
    [[nodiscard]] String SYSTEM_DEFAULT_DECLARE GetEngineeringDirectory();

    // ���ģ��û�ж��壬�����ñ�������ӡĳ���ͱ�����͡�
    template <typename T>
    class TypeDisplayer;
}

#endif  // SYSTEM_WINDOW_ENGINEERING_H
