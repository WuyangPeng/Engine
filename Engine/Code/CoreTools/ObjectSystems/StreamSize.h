// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:40)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H

#include "Stream.h"
#include "ObjectInterface.h"
#include "System/Helper/UnusedMacro.h"

#include <boost/numeric/conversion/cast.hpp>
#include <type_traits>
#include <vector>

namespace CoreTools
{
	static constexpr int g_DefaultSize = 4;
	static constexpr int g_ObjectSize = 8;

	// 模板SteamSize被流系统使用
	template <typename T, typename Enable = void>
	struct StreamSize
	{
		static int GetStreamSize(T value)
		{
			SYSTEM_UNUSED_ARG(value);

			return sizeof(T);
		}
	};

	// 一个独特的ID是一个无符号整数写入8个字节到磁盘上。
	template <typename T>
	struct StreamSize<T, typename std::enable_if_t<std::is_pointer_v<T>>>
	{
		static int GetStreamSize(T value)
		{
			SYSTEM_UNUSED_ARG(value);

			return g_ObjectSize;
		}
	};

	template <typename T>
	struct StreamSize<T, typename std::enable_if_t<std::is_base_of_v<ConstObjectInterfaceSmartPointer, T>>>
	{
		static int GetStreamSize(T value)
		{
			SYSTEM_UNUSED_ARG(value);

			return g_ObjectSize;
		}
	};

	template <typename T>
	struct StreamSize<std::shared_ptr<T>>
	{
		static int GetStreamSize(std::shared_ptr<T> value)
		{
			SYSTEM_UNUSED_ARG(value);

			return g_ObjectSize;
		}
	};

	// 一个bool值被写入4字节到磁盘上。
	template <>
	struct StreamSize<bool>
	{
		static int GetStreamSize(bool value)
		{
			SYSTEM_UNUSED_ARG(value);

			return g_DefaultSize;
		}
	};

	// 一个枚举值被写入4字节到磁盘上。
	template <typename T>
	struct StreamSize<T, typename std::enable_if_t<std::is_enum_v<T>>>
	{
		static int GetStreamSize(T value)
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
				return boost::numeric_cast<int>(g_DefaultSize + value.size() * StreamSize<T>::GetStreamSize(value[0]));
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
				for (const auto& single : value)
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
		return StreamSize<T>::GetStreamSize(value);
	}
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_SIZE_H
