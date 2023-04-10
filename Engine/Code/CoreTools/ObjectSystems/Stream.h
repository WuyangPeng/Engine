///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/29 16:38)

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
        // ����������ش洢�ַ���������ֽ������ַ�������������Ϊһ��int32���洢��������������ַ���
        // ���ַ���������䣬ʹ�ܴ洢��ʹ���ĸ��ֽڵı�����
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
