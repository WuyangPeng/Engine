// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.1 (2020/01/21 15:40)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H

#include "ObjectInterface.h"
#include "Stream.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/ClassInvariant/Noexcept.h"
#include <type_traits>
#include <vector>

namespace CoreTools
{
    static constexpr int g_DefaultSize = 4;
    static constexpr int g_ObjectSize = 8;

    // ģ��SteamSize����ϵͳʹ��
    template <typename T, typename Enable = void>
    struct StreamSize
    {
        static int GetStreamSize(T value = T{}) noexcept
        {
            SYSTEM_UNUSED_ARG(value);

            return sizeof(T);
        }
    };

    // һ�����ص�ID��һ���޷�������д��8���ֽڵ������ϡ�
    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_pointer_v<T>>>
    {
        static int GetStreamSize(T value) noexcept
        {
            SYSTEM_UNUSED_ARG(value);

            return g_ObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>>>
    {
        static int GetStreamSize(T value) noexcept
        {
            SYSTEM_UNUSED_ARG(value);

            return g_ObjectSize;
        }
    };

    template <typename T>
    struct StreamSize<std::shared_ptr<T>>
    {
        
#include STSTEM_WARNING_PUSH
        #include SYSTEM_WARNING_DISABLE(26418)
        static int GetStreamSize(std::shared_ptr<T> value) noexcept
        {
            SYSTEM_UNUSED_ARG(value);

            return g_ObjectSize;
        }
        #include STSTEM_WARNING_POP
    };

    // һ��boolֵ��д��4�ֽڵ������ϡ�
    template <>
    struct StreamSize<bool>
    {
        constexpr static int GetStreamSize(bool value) noexcept
        {
            SYSTEM_UNUSED_ARG(value);

            return g_DefaultSize;
        }
    };

    // һ��ö��ֵ��д��4�ֽڵ������ϡ�
    template <typename T>
    struct StreamSize<T, typename std::enable_if_t<std::is_enum_v<T>>>
    {
        static int GetStreamSize(T value) noexcept
        {
            SYSTEM_UNUSED_ARG(value);

            return sizeof(T);
        }
    };

    template <>
    struct StreamSize<std::string>
    {
        static int GetStreamSize(const std::string& value)
        {
            return Stream::GetStreamingSize(value);
        }
    };

    template <>
    struct StreamSize<const char*>
    {
        static int GetStreamSize(const char* value)
        {
            return Stream::GetStreamingSize(value);
        }
    };

    template <typename T>
    struct StreamSize<std::vector<T>>
    {
        static int GetStreamSize(const std::vector<T>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                return boost::numeric_cast<int>(g_DefaultSize + value.size() * StreamSize<T>::GetStreamSize(value.at(0)));
            }
        }
    };

    template <>
    struct StreamSize<std::vector<std::string>>
    {
        static int GetStreamSize(const std::vector<std::string>& value)
        {
            if (value.empty())
            {
                return g_DefaultSize;
            }
            else
            {
                auto size = g_DefaultSize;
                for (auto single : value)
                {
                    size += StreamSize<std::string>::GetStreamSize(single);
                }
                return size;
            }
        }
    };

    template <typename T>
    int GetStreamSize(T value)
    {
        CoreTools::DoNothing();

        return StreamSize<T>::GetStreamSize(value);
    }
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
