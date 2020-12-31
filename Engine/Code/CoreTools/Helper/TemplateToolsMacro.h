//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/09 15:51)

#ifndef CORE_TOOLS_HELPER_TEMPLATE_TOOLS_MACRO_H
#define CORE_TOOLS_HELPER_TEMPLATE_TOOLS_MACRO_H

#define TRIGONOMETRIC_VARIABLE_DEFINE(variableName, radian) \
    extern double variableName;                             \
    double variableName{ radian };

#define SINE_SPECIALIZATION_DEFINE(variableName, radian) \
    extern double variableName;                          \
    double variableName{ radian };                       \
    namespace CoreTools                                  \
    {                                                    \
        template <>                                      \
        struct SineSeries<variableName, 0, 0>            \
        {                                                \
            static double Value()                        \
            {                                            \
                return 1.0;                              \
            }                                            \
        };                                               \
    }

#endif  // CORE_TOOLS_HELPER_TEMPLATE_TOOLS_MACRO_H
