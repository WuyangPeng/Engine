//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/20 11:10)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_DETAIL_H

#include "SmartPointer2DArray.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename T>
CoreTools::SmartPointer2DArray<T>::SmartPointer2DArray(PointerType data)
    : m_Data{ data }
{
    [[maybe_unused]] const auto reference = SMART_POINTER_SINGLETON.IncreaseReference(m_Data);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP
template <typename T>
CoreTools::SmartPointer2DArray<T>::~SmartPointer2DArray() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        const auto reference = SMART_POINTER_SINGLETON.DecreaseReference(m_Data);

        if (reference == 0)
        {
            DELETE2(m_Data);
        }
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

template <typename T>
CoreTools::SmartPointer2DArray<T>::SmartPointer2DArray(const SmartPointer2DArray& rhs)
    : m_Data{ rhs.m_Data }
{
    [[maybe_unused]] const auto reference = SMART_POINTER_SINGLETON.CopyIncreaseReference(m_Data);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointer2DArray<T>& CoreTools::SmartPointer2DArray<T>::operator=(const SmartPointer2DArray& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType temp{ rhs };
    Swap(temp);

    return *this;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455) 
#include SYSTEM_WARNING_DISABLE(26434)
template <typename T>
CoreTools::SmartPointer2DArray<T>& CoreTools::SmartPointer2DArray<T>::operator=(PointerType data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType temp{ data };
    Swap(temp);

    return *this;
}
#include STSTEM_WARNING_POP

// private
template <typename T>
void CoreTools::SmartPointer2DArray<T>::Swap(SmartPointer2DArray& rhs) noexcept
{
    std::swap(m_Data, rhs.m_Data);
}

template <typename T>
CoreTools::SmartPointer2DArray<T>::SmartPointer2DArray(SmartPointer2DArray&& rhs) noexcept
    : m_Data{ std::move(rhs.m_Data) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointer2DArray<T>& CoreTools::SmartPointer2DArray<T>::operator=(SmartPointer2DArray&& rhs) noexcept
{
    m_Data = std::move(rhs.m_Data);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SmartPointer2DArray<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename CoreTools::SmartPointer2DArray<T>::ConstPointerType CoreTools::SmartPointer2DArray<T>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Data;
}

template <typename T>
CoreTools::SmartPointer2DArray<T>::operator ConstPointerType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointer2DArray<T>::ConstReferenceType CoreTools::SmartPointer2DArray<T>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return *GetData();
}

template <typename T>
typename CoreTools::SmartPointer2DArray<T>::PointerType CoreTools::SmartPointer2DArray<T>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(PointerType, GetData);
}

template <typename T>
CoreTools::SmartPointer2DArray<T>::operator PointerType() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointer2DArray<T>::ReferenceType CoreTools::SmartPointer2DArray<T>::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return *GetData();
}

template <typename T>
bool CoreTools::operator==(const SmartPointer2DArray<T>& lhs, T** data) noexcept
{
    if (lhs.GetData() == data)
        return true;
    else
        return false;
}

template <typename T>
bool CoreTools::operator==(const SmartPointer2DArray<T>& lhs, const SmartPointer2DArray<T>& rhs) noexcept
{
    return lhs.GetData() == rhs.GetData();
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_DETAIL_H
