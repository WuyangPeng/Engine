/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:17)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectType.h"
#include "Stream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/Tools.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <type_traits>
#include <vector>

namespace CoreTools
{
    /// 模板SteamSize被流系统使用
    template <typename T, typename Enable = void>
    struct StreamSize
    {
        NODISCARD constexpr static int GetStreamSize(T value) noexcept
        {
            System::UnusedFunction(value);

            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return sizeof(T);
        }
    };

    /// 一个独特的Id是一个有符号整数写入8个字节到磁盘上。
    template <typename T>
    struct StreamSize<T, std::enable_if_t<IsObjectAssociated<T>::result>>
    {
        NODISCARD constexpr static int GetStreamSize(const T& value) noexcept
        {
            System::UnusedFunction(value);

            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return gObjectSize;
        }
    };

    /// 一个bool值被写入4字节到磁盘上。
    template <>
    struct StreamSize<bool>
    {
        NODISCARD constexpr static int GetStreamSize(bool value) noexcept
        {
            System::UnusedFunction(value);

            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<T, std::enable_if_t<std::is_enum_v<T>>>
    {
        NODISCARD constexpr static int GetStreamSize(T value) noexcept
        {
            System::UnusedFunction(value);

            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return sizeof(T);
        }
    };

    template <typename T>
    struct StreamSize<T, std::enable_if_t<IsString<T>::result>>
    {
        NODISCARD static int GetStreamSize(const T& value)
        {
            return Stream::GetStreamingSize(value);
        }

        NODISCARD static int GetStreamSize()
        {
            return GetStreamSize(std::string{});
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>, std::enable_if_t<std::is_arithmetic_v<T>>>
    {
        NODISCARD static int GetStreamSize(const std::vector<T>& value)
        {
            if (value.empty())
            {
                return gDefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(gDefaultSize + value.size() * StreamSize<T>::GetStreamSize());
            }
        }

        NODISCARD static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>, std::enable_if_t<IsObjectAssociated<T>::result>>
    {
        NODISCARD static int GetStreamSize(const std::vector<T>& value)
        {
            if (value.empty())
            {
                return gDefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(gDefaultSize + value.size() * StreamSize<T>::GetStreamSize());
            }
        }

        NODISCARD static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>, std::enable_if_t<IsString<T>::result>>
    {
        NODISCARD static int GetStreamSize(const std::vector<T>& value)
        {
            if (value.empty())
            {
                return gDefaultSize;
            }
            else
            {
                auto size = gDefaultSize;
                for (const auto& single : value)
                {
                    size += StreamSize<T>::GetStreamSize(single);
                }
                return size;
            }
        }

        NODISCARD static int GetStreamSize()
        {
            return GetStreamSize(std::string{});
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>, std::false_type>
    {
        NODISCARD static int GetStreamSize(const std::vector<T>& value)
        {
            if (value.empty())
            {
                return gDefaultSize;
            }
            else
            {
                auto size = gDefaultSize;
                for (const auto& single : value)
                {
                    size += StreamSize<T>::GetStreamSize(single);
                }
                return size;
            }
        }

        NODISCARD static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <typename T, int Size>
    requires(0 < Size)
    struct StreamSize<std::array<T, Size>>
    {
        NODISCARD constexpr static int GetStreamSize(const std::array<T, Size>& value) noexcept
        {
            System::UnusedFunction(value);

            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return StreamSize<T>::GetStreamSize(T{}) * Size;
        }
    };

    template <typename T>
    NODISCARD int GetStreamSize(const T& value = T{}) noexcept(noexcept(StreamSize<T>::GetStreamSize(value)))
    {
        return StreamSize<std::remove_cv_t<T>>::GetStreamSize(value);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
