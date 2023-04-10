///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/29 16:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "StreamConstant.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Stream final
    {
    public:
        using ClassType = Stream;

    public:
        // 这个函数返回存储字符串所需的字节数。字符串长度首先作为一个int32被存储，后面跟着它的字符。
        // 该字符串用零填充，使总存储数使用四个字节的倍数。
        template <typename T, std::enable_if_t<std::is_constructible_v<std::decay_t<T>, const char*>>* = nullptr>
        NODISCARD static int GetStreamingSize(T&& input)
        {
            auto length = boost::numeric_cast<int>(input.size());

            return GetStreamingSize(length);
        }

        NODISCARD static int GetStreamingSize(const char* input);

        NODISCARD static constexpr int GetPadding(const int length) noexcept
        {
            auto padding = 0;
            if (0 < length)
            {
                padding = (length % gDefaultSize);
                if (0 < padding)
                {
                    padding = gDefaultSize - padding;
                }
            }

            return padding;
        }

    private:
        NODISCARD static int GetStreamingSize(int length) noexcept;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H
