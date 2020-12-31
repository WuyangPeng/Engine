///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/02 10:27)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H

#include "Stream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include <type_traits>
#include <vector>

namespace CoreTools
{
    static constexpr auto g_DefaultSize = 4;
    static constexpr auto g_ObjectSize = 8;

    // 模板SteamSize被流系统使用
    template <typename T, typename Enable = void>
    struct StreamSize
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] T value) noexcept
        {
            return GetStreamSize();
        }

        [[nodiscard]] constexpr static int GetStreamSize() noexcept
        {
            return sizeof(T);
        }
    };

    // 一个独特的ID是一个无符号整数写入8个字节到磁盘上。
    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_pointer_v<T>>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] T value) noexcept
        {
            return GetStreamSize();
        }

        [[nodiscard]] constexpr static int GetStreamSize() noexcept
        {
            return g_ObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::shared_ptr<T>>
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] const std::shared_ptr<T>& value) noexcept
        {
            return GetStreamSize();
        }
#include STSTEM_WARNING_POP

        [[nodiscard]] constexpr static int GetStreamSize() noexcept
        {
            return g_ObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::weak_ptr<T>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] const std::weak_ptr<T>& value) noexcept
        {
            return GetStreamSize();
        }

        [[nodiscard]] constexpr static int GetStreamSize() noexcept
        {
            return g_ObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::unique_ptr<T>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] const std::unique_ptr<T>& value) noexcept
        {
            return GetStreamSize();
        }

        [[nodiscard]] constexpr static int GetStreamSize() noexcept
        {
            return g_ObjectSize;
        }
    };

    // 一个bool值被写入4字节到磁盘上。
    template <>
    struct StreamSize<bool>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] bool value) noexcept
        {
            return GetStreamSize();
        }

        [[nodiscard]] constexpr static int GetStreamSize() noexcept
        {
            return g_DefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_enum_v<T>>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] T value) noexcept
        {
            return GetStreamSize();
        }

        [[nodiscard]] constexpr static int GetStreamSize() noexcept
        {
            return sizeof(T);
        }
    };

    template <>
    struct StreamSize<std::string>
    {
        [[nodiscard]] static int GetStreamSize(const std::string& value)
        {
            return Stream::GetStreamingSize(value);
        }

        [[nodiscard]] static int GetStreamSize()
        {
            return GetStreamSize(std::string{});
        }
    };

    template <>
    struct StreamSize<const char*>
    {
        [[nodiscard]] static int GetStreamSize(const char* value)
        {
            return Stream::GetStreamingSize(value);
        }

        [[nodiscard]] static int GetStreamSize()
        {
            return StreamSize<std::string>::GetStreamSize();
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>, typename std::enable_if_t<std::is_arithmetic_v<T>>>
    {
        [[nodiscard]] static int GetStreamSize(const std::vector<T>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(g_DefaultSize + value.size() * StreamSize<T>::GetStreamSize());
            }
        }

        [[nodiscard]] static int GetStreamSize() noexcept
        {
            return g_DefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>, typename std::enable_if_t<std::is_pointer_v<T>>>
    {
        [[nodiscard]] static int GetStreamSize(const std::vector<T>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(g_DefaultSize + value.size() * StreamSize<T>::GetStreamSize());
            }
        }

        [[nodiscard]] static int GetStreamSize() noexcept
        {
            return g_DefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<std::shared_ptr<T>>>
    {
        [[nodiscard]] static int GetStreamSize(const std::vector<std::shared_ptr<T>>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(g_DefaultSize + value.size() * StreamSize<std::shared_ptr<T>>::GetStreamSize());
            }
        }

        [[nodiscard]] static int GetStreamSize() noexcept
        {
            return g_DefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<std::weak_ptr<T>>>
    {
        [[nodiscard]] static int GetStreamSize(const std::vector<std::weak_ptr<T>>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(g_DefaultSize + value.size() * StreamSize<std::weak_ptr<T>>::GetStreamSize());
            }
        }

        [[nodiscard]] static int GetStreamSize() noexcept
        {
            return g_DefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<std::unique_ptr<T>>>
    {
        [[nodiscard]] static int GetStreamSize(const std::vector<std::unique_ptr<T>>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(g_DefaultSize + value.size() * StreamSize<std::unique_ptr<T>>::GetStreamSize());
            }
        }

        [[nodiscard]] static int GetStreamSize() noexcept
        {
            return g_DefaultSize;
        }
    };

    template <>
    struct StreamSize<std::vector<const char*>>
    {
        [[nodiscard]] static int GetStreamSize(const std::vector<const char*>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                auto size = g_DefaultSize;
                for (const auto& single : value)
                {
                    size += StreamSize<const char*>::GetStreamSize(single);
                }
                return size;
            }
        }

        [[nodiscard]] static int GetStreamSize() noexcept
        {
            return g_DefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>, std::false_type>
    {
        [[nodiscard]] static int GetStreamSize(const std::vector<T>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                auto size = g_DefaultSize;
                for (const auto& single : value)
                {
                    size += StreamSize<T>::GetStreamSize(single);
                }
                return size;
            }
        }

        [[nodiscard]] static int GetStreamSize() noexcept
        {
            return g_DefaultSize;
        }
    };

    template <typename T>
    [[nodiscard]] int GetStreamSize(T value = T{}) noexcept(noexcept(StreamSize<T>::GetStreamSize(value)))
    {
        return StreamSize<T>::GetStreamSize(value);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
