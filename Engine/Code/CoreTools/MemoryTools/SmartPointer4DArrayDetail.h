//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/20 18:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_DETAIL_H

#include "SmartPointer4DArray.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename T>
CoreTools::SmartPointer4DArray<T>::SmartPointer4DArray(PointerType data)
    : m_Data{ data }
{
    [[maybe_unused]] const auto reference = SMART_POINTER_SINGLETON.IncreaseReference(m_Data);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP
template <typename T>
CoreTools::SmartPointer4DArray<T>::~SmartPointer4DArray() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        const auto reference = SMART_POINTER_SINGLETON.DecreaseReference(m_Data);

        if (reference == 0)
        {
            DELETE4(m_Data);
        }
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

template <typename T>
CoreTools::SmartPointer4DArray<T>::SmartPointer4DArray(const SmartPointer4DArray& rhs)
    : m_Data{ rhs.m_Data }
{
    [[maybe_unused]] const auto reference = SMART_POINTER_SINGLETON.CopyIncreaseReference(m_Data);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointer4DArray<T>& CoreTools::SmartPointer4DArray<T>::operator=(const SmartPointer4DArray& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType temp{ rhs };
    Swap(temp);

    return *this;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename T>
CoreTools::SmartPointer4DArray<T>& CoreTools::SmartPointer4DArray<T>::operator=(PointerType data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType temp{ data };
    Swap(temp);

    return *this;
}
#include STSTEM_WARNING_POP
template <typename T>
CoreTools::SmartPointer4DArray<T>::SmartPointer4DArray(SmartPointer4DArray&& rhs) noexcept
    : m_Data{ std::move(rhs.m_Data) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointer4DArray<T>& CoreTools::SmartPointer4DArray<T>::operator=(SmartPointer4DArray&& rhs) noexcept
{
    m_Data = std::move(rhs.m_Data);

    return *this;
}

// private
template <typename T>
void CoreTools::SmartPointer4DArray<T>::Swap(SmartPointer4DArray& rhs) noexcept
{
    std::swap(m_Data, rhs.m_Data);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SmartPointer4DArray<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename CoreTools::SmartPointer4DArray<T>::ConstPointerType const CoreTools::SmartPointer4DArray<T>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Data;
}

template <typename T>
CoreTools::SmartPointer4DArray<T>::operator ConstPointerType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointer4DArray<T>::ConstReferenceType CoreTools::SmartPointer4DArray<T>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return *GetData();
}

template <typename T>
typename CoreTools::SmartPointer4DArray<T>::PointerType CoreTools::SmartPointer4DArray<T>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(PointerType, GetData);
}

template <typename T>
CoreTools::SmartPointer4DArray<T>::operator PointerType() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointer4DArray<T>::ReferenceType CoreTools::SmartPointer4DArray<T>::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return *GetData();
}

template <typename T>
bool CoreTools::operator==(const SmartPointer4DArray<T>& lhs, T**** data) noexcept
{
    if (lhs.GetData() == data)
        return true;
    else
        return false;
}

template <typename T>
bool CoreTools::operator==(const SmartPointer4DArray<T>& lhs, const SmartPointer4DArray<T>& rhs) noexcept
{
    return lhs.GetData() == rhs.GetData();
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_DETAIL_H
