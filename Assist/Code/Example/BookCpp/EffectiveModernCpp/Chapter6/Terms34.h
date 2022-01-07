///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/03 19:42)

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
                // 表示时刻的型别typedef
                using Time = std::chrono::steady_clock::time_point;

                enum class Sound
                {
                    Beep,
                    Siren,
                    Whistle
                };

                // 表示时长型别的typedef
                using Duration = std::chrono::steady_clock::duration;

                namespace Example0
                {
                    // 在时刻t，发出声音s,持续时长d
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

                enum class CompLevel  // 压缩等级
                {
                    Low,
                    Normal,
                    High
                };

                class Widget
                {
                };

                Widget Compress(const Widget& w, MAYBE_UNUSED CompLevel lev) noexcept;  // 制作w的压缩副本

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
