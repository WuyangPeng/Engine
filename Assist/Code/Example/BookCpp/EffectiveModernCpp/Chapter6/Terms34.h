///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/03 19:42)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER6_TERM34_H
#define EFFECTIVE_MODERN_CPP_CHAPTER6_TERM34_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <chrono>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter6
        {
            namespace Terms34
            {
                // ��ʾʱ�̵��ͱ�typedef
                using Time = std::chrono::steady_clock::time_point;

                enum class Sound
                {
                    Beep,
                    Siren,
                    Whistle
                };

                // ��ʾʱ���ͱ��typedef
                using Duration = std::chrono::steady_clock::duration;

                namespace Example0
                {
                    // ��ʱ��t����������s,����ʱ��d
                    void SetAlarm(MAYBE_UNUSED Time t, MAYBE_UNUSED Sound s, MAYBE_UNUSED Duration d) noexcept;
                }

                enum class Volume
                {
                    Normal,
                    Loud,
                    LoudPlusPlus
                };

                namespace Example1
                {
                    void SetAlarm(MAYBE_UNUSED Time t, MAYBE_UNUSED Sound s, MAYBE_UNUSED Duration d) noexcept;

                    void SetAlarm(MAYBE_UNUSED Time t, MAYBE_UNUSED Sound s, MAYBE_UNUSED Duration d, MAYBE_UNUSED Volume v) noexcept;
                }

                enum class CompLevel  // ѹ���ȼ�
                {
                    Low,
                    Normal,
                    High
                };

                class Widget
                {
                };

                Widget Compress(const Widget& w, MAYBE_UNUSED CompLevel lev) noexcept;  // ����w��ѹ������

                class PolyWidget
                {
                public:
                    template <typename T>
                    void operator()(MAYBE_UNUSED const T& param) noexcept
                    {
                    }

                    // ...
                };
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER6_TERM34_H
