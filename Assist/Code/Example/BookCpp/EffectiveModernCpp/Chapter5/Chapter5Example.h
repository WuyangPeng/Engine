///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/13 10:53)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            class Widget;

            // �β�������ֵ����ʹ���ͱ�����ֵ���á�
            void F(Widget&& w);
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_EXAMPLE_H
