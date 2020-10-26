//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 11:36)

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

    // ģ��SteamSize����ϵͳʹ��
    template <typename T, typename Enable = void>
    struct StreamSize
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] T value = T{}) noexcept
        {
            return sizeof(T);
        }
    };

    // һ�����ص�ID��һ���޷�������д��8���ֽڵ������ϡ�
    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_pointer_v<T>>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] T value) noexcept
        {
            return g_ObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::shared_ptr<T>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] const std::shared_ptr<T>& value = std::shared_ptr<T>{}) noexcept
        {
            return g_ObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::weak_ptr<T>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] const std::weak_ptr<T>& value = std::weak_ptr<T>{}) noexcept
        {
            return g_ObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::unique_ptr<T>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] const std::unique_ptr<T>& value = std::unique_ptr<T>{}) noexcept
        {
            return g_ObjectSize;
        }
    };

    // һ��boolֵ��д��4�ֽڵ������ϡ�
    template <>
    struct StreamSize<bool>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] bool value) noexcept
        {
            return g_DefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_enum_v<T>>>
    {
        [[nodiscard]] constexpr static int GetStreamSize([[maybe_unused]] T value) noexcept
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
    };

    template <>
    struct StreamSize<const char*>
    {
        [[nodiscard]] static int GetStreamSize(const char* value)
        {
            return Stream::GetStreamingSize(value);
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
    };

    template <typename T>
    [[nodiscard]] int GetStreamSize(T value = T{}) noexcept(noexcept(StreamSize<T>::GetStreamSize(value)))
    {
        return StreamSize<T>::GetStreamSize(value);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
