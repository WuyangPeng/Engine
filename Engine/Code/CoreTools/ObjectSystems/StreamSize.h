///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 22:02)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H

#include "Stream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <type_traits>
#include <vector>

namespace CoreTools
{
    // 模板SteamSize被流系统使用
    template <typename T, typename Enable = void>
    struct StreamSize
    {
        NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED T value) noexcept
        {
            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return sizeof(T);
        }
    };

    // 一个独特的ID是一个无符号整数写入8个字节到磁盘上。
    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_pointer_v<T>>>
    {
        NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED T value) noexcept
        {
            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return gObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<ObjectAssociated<T>>
    {
        NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED const ObjectAssociated<T>& value) noexcept
        {
            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return gObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::shared_ptr<T>>
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
        NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED const std::shared_ptr<T>& value) noexcept
#include STSTEM_WARNING_POP
        {
            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return gObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::weak_ptr<T>>
    {
        NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED const std::weak_ptr<T>& value) noexcept
        {
            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return gObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::unique_ptr<T>>
    {
        NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED const std::unique_ptr<T>& value) noexcept
        {
            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return gObjectSize;
        }
    };

    // 一个bool值被写入4字节到磁盘上。
    template <>
    struct StreamSize<bool>
    {
        NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED bool value) noexcept
        {
            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_enum_v<T>>>
    {
        NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED T value) noexcept
        {
            return GetStreamSize();
        }

        NODISCARD constexpr static int GetStreamSize() noexcept
        {
            return sizeof(T);
        }
    };

    template <>
    struct StreamSize<std::string>
    {
        NODISCARD static int GetStreamSize(const std::string& value)
        {
            return Stream::GetStreamingSize(value);
        }

        NODISCARD static int GetStreamSize()
        {
            return GetStreamSize(std::string{});
        }
    };

    template <>
    struct StreamSize<std::string_view>
    {
        NODISCARD static int GetStreamSize(const std::string_view& value)
        {
            return Stream::GetStreamingSize(value);
        }

        NODISCARD static int GetStreamSize()
        {
            return GetStreamSize(std::string_view{});
        }
    };

    template <>
    struct StreamSize<const char*>
    {
        NODISCARD static int GetStreamSize(const char* value)
        {
            return Stream::GetStreamingSize(value);
        }

        NODISCARD static int GetStreamSize()
        {
            return StreamSize<std::string>::GetStreamSize();
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>, typename std::enable_if_t<std::is_arithmetic_v<T>>>
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
    struct StreamSize<std::vector<T>, typename std::enable_if_t<std::is_pointer_v<T>>>
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
    struct StreamSize<std::vector<std::shared_ptr<T>>>
    {
        NODISCARD static int GetStreamSize(const std::vector<std::shared_ptr<T>>& value)
        {
            if (value.empty())
            {
                return gDefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(gDefaultSize + value.size() * StreamSize<std::shared_ptr<T>>::GetStreamSize());
            }
        }

        NODISCARD static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<std::weak_ptr<T>>>
    {
        NODISCARD static int GetStreamSize(const std::vector<std::weak_ptr<T>>& value)
        {
            if (value.empty())
            {
                return gDefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(gDefaultSize + value.size() * StreamSize<std::weak_ptr<T>>::GetStreamSize());
            }
        }

        NODISCARD static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <typename T>
    struct StreamSize<std::vector<std::unique_ptr<T>>>
    {
        NODISCARD static int GetStreamSize(const std::vector<std::unique_ptr<T>>& value)
        {
            if (value.empty())
            {
                return gDefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(gDefaultSize + value.size() * StreamSize<std::unique_ptr<T>>::GetStreamSize());
            }
        }

        NODISCARD static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <>
    struct StreamSize<std::vector<const char*>>
    {
        NODISCARD static int GetStreamSize(const std::vector<const char*>& value)
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
                    size += StreamSize<const char*>::GetStreamSize(single);
                }
                return size;
            }
        }

        NODISCARD static int GetStreamSize() noexcept
        {
            return gDefaultSize;
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

    template <>
    struct StreamSize<std::vector<std::string>>
    {
        NODISCARD static int GetStreamSize(const std::vector<std::string>& value)
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
                    size += StreamSize<std::string>::GetStreamSize(single);
                }
                return size;
            }
        }

        NODISCARD static int GetStreamSize() noexcept
        {
            return gDefaultSize;
        }
    };

    template <typename T>
    NODISCARD int GetStreamSize(T value = T{}) noexcept(noexcept(StreamSize<T>::GetStreamSize(value)))
    {
        return StreamSize<T>::GetStreamSize(value);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
