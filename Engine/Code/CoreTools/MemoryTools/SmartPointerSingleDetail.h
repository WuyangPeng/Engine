//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/20 18:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_DETAIL_H

#include "SmartPointerManager.h"
#include "SmartPointerSingle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"

template <typename T>
CoreTools::SmartPointerSingle<T>::SmartPointerSingle(PointerType data)
    : m_Data{ data }
{
    SMART_POINTER_SINGLETON.IncreaseReference(m_Data);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointerSingle<T>::~SmartPointerSingle() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        auto reference = SMART_POINTER_SINGLETON.DecreaseReference(m_Data);

        if (reference == 0)
        {
            DELETE0(m_Data);
        }
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

template <typename T>
CoreTools::SmartPointerSingle<T>::SmartPointerSingle(const SmartPointerSingle& rhs)
    : m_Data{ rhs.m_Data }
{
    [[maybe_unused]] const auto reference = SMART_POINTER_SINGLETON.CopyIncreaseReference(m_Data);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointerSingle<T>& CoreTools::SmartPointerSingle<T>::operator=(const SmartPointerSingle& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType temp{ rhs };
    Swap(temp);

    return *this;
}

template <typename T>
CoreTools::SmartPointerSingle<T>& CoreTools::SmartPointerSingle<T>::operator=(PointerType data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType temp{ data };
    Swap(temp);

    return *this;
}

// private
template <typename T>
void CoreTools::SmartPointerSingle<T>::Swap(SmartPointerSingle& rhs) noexcept
{
    std::swap(m_Data, rhs.m_Data);
}

template <typename T>
CoreTools::SmartPointerSingle<T>::SmartPointerSingle(SmartPointerSingle&& rhs) noexcept
    : m_Data{ std::move(rhs.m_Data) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointerSingle<T>& CoreTools::SmartPointerSingle<T>::operator=(SmartPointerSingle&& rhs) noexcept
{
    m_Data = std::move(rhs.m_Data);

    return *this;
}
#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SmartPointerSingle<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename CoreTools::SmartPointerSingle<T>::ConstPointerType CoreTools::SmartPointerSingle<T>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Data;
}

template <typename T>
CoreTools::SmartPointerSingle<T>::operator ConstPointerType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointerSingle<T>::ConstReferenceType CoreTools::SmartPointerSingle<T>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return *GetData();
}

template <typename T>
typename CoreTools::SmartPointerSingle<T>::ConstPointerType CoreTools::SmartPointerSingle<T>::operator->() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointerSingle<T>::PointerType CoreTools::SmartPointerSingle<T>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(PointerType, GetData);
}

template <typename T>
CoreTools::SmartPointerSingle<T>::operator PointerType() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointerSingle<T>::ReferenceType CoreTools::SmartPointerSingle<T>::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return *GetData();
}

template <typename T>
typename CoreTools::SmartPointerSingle<T>::PointerType CoreTools::SmartPointerSingle<T>::operator->() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetData();
}

template <typename T>
bool CoreTools::operator==(const SmartPointerSingle<T>& lhs, T* data) noexcept
{
    if (lhs.GetData() == data)
        return true;
    else
        return false;
}

template <typename T>
bool CoreTools::operator==(const SmartPointerSingle<T>& lhs, const SmartPointerSingle<T>& rhs) noexcept
{
    return lhs.GetData() == rhs.GetData();
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_DETAIL_H
