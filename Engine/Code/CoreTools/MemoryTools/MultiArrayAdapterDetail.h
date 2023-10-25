///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:34)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_DETAIL_H

#include "LatticeDetail.h"
#include "MultiArrayAdapter.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T, bool OrderLToR, int... Sizes>
CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::MultiArrayAdapter(T* container)
    : ParentType{}, container{ container }
{
    if (container == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器必须存在。"))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR, int... Sizes>
bool CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::IsValid() const noexcept
{
    if (ParentType::IsValid() && container != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR, int... Sizes>
void CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::Reset(T* aContainer)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (aContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器必须存在。"));
    }

    container = aContainer;
}

template <typename T, bool OrderLToR, int... Sizes>
const T* CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return container;
}

template <typename T, bool OrderLToR, int... Sizes>
T* CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, bool OrderLToR, int... Sizes>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator[](int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (this->GetSize() <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引无效。"));
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return container[index];

#include SYSTEM_WARNING_POP
}

template <typename T, bool OrderLToR, int... Sizes>
T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator[](int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, bool OrderLToR, int... Sizes>
void CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::Fill(const T& value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    for (auto i = 0; i < this->GetSize(); ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        container[i] = value;

#include SYSTEM_WARNING_POP
    }
}

template <typename T, bool OrderLToR, int... Sizes>
template <typename... IndexTypes>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator()(IndexTypes... tuple) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return container[this->GetIndex(tuple...)];

#include SYSTEM_WARNING_POP
}

template <typename T, bool OrderLToR, int... Sizes>
template <typename... IndexTypes>
T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator()(IndexTypes... tuple) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return container[this->GetIndex(tuple...)];

#include SYSTEM_WARNING_POP
}

template <typename T, bool OrderLToR, int... Sizes>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator()(const std::array<int, sizeof...(Sizes)>& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return container[this->GetIndex(coordinate)];

#include SYSTEM_WARNING_POP
}

template <typename T, bool OrderLToR, int... Sizes>
T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator()(const std::array<int, sizeof...(Sizes)>& coordinate)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return container[this->GetIndex(coordinate)];

#include SYSTEM_WARNING_POP
}

template <typename T, bool OrderLToR, int... Sizes>
bool CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator==(const MultiArrayAdapter& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    for (auto i = 0; i < this->GetSize(); ++i)
    {
        if (container[i] != rhs.container[i])
        {
            return false;
        }
    }

    return true;
}

template <typename T, bool OrderLToR, int... Sizes>
bool CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator<(const MultiArrayAdapter& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    for (auto i = 0; i < this->GetSize(); ++i)
    {
        if (container[i] < rhs.container[i])
        {
            return true;
        }

        if (rhs.container[i] < container[i])
        {
            return false;
        }
    }

    return false;
}

template <typename T, bool OrderLToR>
CoreTools::MultiArrayAdapter<T, OrderLToR>::MultiArrayAdapter(const SizeType& sizes, T* container)
    : ParentType{ sizes }, container{ container }
{
    if (container == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器必须存在。"));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR>
bool CoreTools::MultiArrayAdapter<T, OrderLToR>::IsValid() const noexcept
{
    if (ParentType::IsValid() && container != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR>
void CoreTools::MultiArrayAdapter<T, OrderLToR>::Reset(const SizeType& sizes, T* aContainer)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (aContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器必须存在。"));
    }

    ParentType::Reset(sizes);
    container = aContainer;
}

template <typename T, bool OrderLToR>
const T* CoreTools::MultiArrayAdapter<T, OrderLToR>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container;
}

template <typename T, bool OrderLToR>
T* CoreTools::MultiArrayAdapter<T, OrderLToR>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, bool OrderLToR>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator[](int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (this->GetSize() <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引无效。"));
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return container[index];

#include SYSTEM_WARNING_POP
}

template <typename T, bool OrderLToR>
T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator[](int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, bool OrderLToR>
void CoreTools::MultiArrayAdapter<T, OrderLToR>::Fill(const T& value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto i = 0; i < this->GetSize(); ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        container[i] = value;

#include SYSTEM_WARNING_POP
    }
}

template <typename T, bool OrderLToR>
template <typename... IndexTypes>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator()(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container[this->GetIndex(tuple...)];
}

template <typename T, bool OrderLToR>
template <typename... IndexTypes>
T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator()(IndexTypes... tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return container[this->GetIndex(tuple...)];

#include SYSTEM_WARNING_POP
}

template <typename T, bool OrderLToR>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator()(const SizeType& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container[this->GetIndex(coordinate)];
}

template <typename T, bool OrderLToR>
T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator()(const SizeType& coordinate)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return container[this->GetIndex(coordinate)];

#include SYSTEM_WARNING_POP
}

template <typename T, bool OrderLToR>
bool CoreTools::MultiArrayAdapter<T, OrderLToR>::operator==(const MultiArrayAdapter& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (ParentType::operator!=(rhs))
    {
        return false;
    }

    for (auto i = 0; i < this->GetSize(); ++i)
    {
        if (container[i] != rhs.container[i])
        {
            return false;
        }
    }

    return true;
}

template <typename T, bool OrderLToR>
bool CoreTools::MultiArrayAdapter<T, OrderLToR>::operator<(const MultiArrayAdapter& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (ParentType::operator<(rhs))
    {
        return true;
    }

    if (ParentType::operator>(rhs))
    {
        return false;
    }

    for (auto i = 0; i < this->GetSize(); ++i)
    {
        if (container[i] < rhs.container[i])
        {
            return true;
        }

        if (rhs.container[i] < container[i])
        {
            return false;
        }
    }

    return false;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_DETAIL_H
