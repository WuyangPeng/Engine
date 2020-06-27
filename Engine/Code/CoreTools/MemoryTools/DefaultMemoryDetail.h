// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 17:01)

#ifndef CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_DETAIL_H

#include "DefaultMemory.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

// static
template <typename T>
T* CoreTools::DefaultMemory
	::New1DArray(const int bound)
{
	return new T[bound];
}

// static
template <typename T>
T** CoreTools::DefaultMemory
	::New2DArray(const int bound1, const int bound2)
{
	CORE_TOOLS_ASSERTION_0(0 < bound1, "要生成的数组大小必须大于0！");
	CORE_TOOLS_ASSERTION_0(0 < bound2, "要生成的数组大小必须大于0！");

	const auto bound = bound1 * bound2;
	auto data = new T*[bound2];

	NewArrayUseFailureDelete(data, bound);

	for (auto index = 1; index < bound2; ++index)
	{
		auto position = bound1 * index;
		data[index] = &data[0][position];
	}

	return data;
}

// private
template <typename T>
void CoreTools::DefaultMemory
	::NewArrayUseFailureDelete(T**& data, int bound)
{
	try
	{
		data[0] = new T[bound];
	}
	catch (...)
	{
		delete[] data;
		throw;
	} 
}

// static
template <typename T>
T*** CoreTools::DefaultMemory
	::New3DArray(const int bound1, const int bound2, const int bound3)
{
	const auto innerBound = bound2 * bound3;
	const auto bound = bound1 * innerBound;

	auto data = new T**[bound3];

	NewArrayUseFailureDelete(data, bound, innerBound);

	for (auto index3 = 0; index3 < bound3; ++index3)
	{
		auto position2 = bound2 * index3;
		data[index3] = &data[0][position2];

		for (auto index2 = 0; index2 < bound2; ++index2)
		{
			auto position1 = bound1 * (index2 + position2);
			data[index3][index2] = &data[0][0][position1];
		}
	}

	return data;
}

// private
template <typename T>
void CoreTools::DefaultMemory
	::NewArrayUseFailureDelete(T***& data, int bound, int innerBound)
{
	try
	{
		data[0] = new T*[innerBound];

		NewArrayUseFailureDelete(data[0], bound);
	}
	catch (...)
	{
		delete[] data;
		throw;
	}
}

// static
template <typename T>
T**** CoreTools::DefaultMemory
	::New4DArray(const int bound1, const int bound2, const int bound3, const int bound4)
{
	const auto innermostBound = bound3 * bound4;
	const auto innerBound = bound2 * innermostBound;
	const auto bound = bound1 * innerBound;

	auto data = new T***[bound4];

	NewArrayUseFailureDelete(data, bound, innerBound, innermostBound);

	for (auto index4 = 0; index4 < bound4; ++index4)
	{
		auto position3 = bound3 * index4;
		data[index4] = &data[0][position3];

		for (auto index3 = 0; index3 < bound3; ++index3)
		{
			auto position2 = bound2 * (index3 + position3);
			data[index4][index3] = &data[0][0][position2];

			for (auto index2 = 0; index2 < bound2; ++index2)
			{
				auto position1 = bound1 * (index2 + position2);
				data[index4][index3][index2] = &data[0][0][0][position1];
			}
		}
	}

	return data;
}

// private
template <typename T>
void CoreTools::DefaultMemory
	::NewArrayUseFailureDelete(T****& data, int bound, int innerBound, int innermostBound)
{
	try
	{
		data[0] = new T**[innermostBound];

		NewArrayUseFailureDelete(data[0], bound, innerBound);
	}
	catch (...)
	{
		delete[] data;
		throw;
	}
}

// static
template <typename T>
void CoreTools::DefaultMemory
	::DeleteSingle(T*& data) noexcept
{
	delete data;
	data = nullptr;
}

// static
template <typename T>
void CoreTools::DefaultMemory
	::Delete1DArray(T*& data)
{
	delete[] data;
	data = nullptr;
}

// static
template <typename T>
void CoreTools::DefaultMemory
	::Delete2DArray(T**& data)
{
	if (data != nullptr)
	{
		Delete1DArray(data[0]);
	}	

	delete[] data;
	data = nullptr;
}

// static
template <typename T>
void CoreTools::DefaultMemory
	::Delete3DArray(T***& data)
{
	if (data != nullptr)
	{
		Delete2DArray(data[0]);
	}

	delete[] data;
	data = nullptr;
}

// static
template <typename T>
void CoreTools::DefaultMemory
	::Delete4DArray(T****& data)
{
	if (data != nullptr)
	{
		Delete3DArray(data[0]);
	}

	delete[] data;
	data = nullptr;
}

#endif // CORE_TOOLS_MEMORY_TOOLS_DEFAULT_MEMORY_DETAIL_H

