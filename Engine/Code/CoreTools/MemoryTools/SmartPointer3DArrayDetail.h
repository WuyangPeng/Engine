//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/20 18:37)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_DETAIL_H

#include "SmartPointer3DArray.h"
#include "SmartPointerManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename T>
CoreTools::SmartPointer3DArray<T>::SmartPointer3DArray(PointerType data)
    : m_Data{ data }
{
    [[maybe_unused]] const auto reference = SMART_POINTER_SINGLETON.IncreaseReference(m_Data);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP
template <typename T>
CoreTools::SmartPointer3DArray<T>::~SmartPointer3DArray() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        const auto reference = SMART_POINTER_SINGLETON.DecreaseReference(m_Data);

        if (reference == 0)
        {
            DELETE3(m_Data);
        }
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

template <typename T>
CoreTools::SmartPointer3DArray<T>::SmartPointer3DArray(const SmartPointer3DArray& rhs)
    : m_Data{ rhs.m_Data }
{
    [[maybe_unused]] const auto reference = SMART_POINTER_SINGLETON.CopyIncreaseReference(m_Data);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointer3DArray<T>& CoreTools::SmartPointer3DArray<T>::operator=(const SmartPointer3DArray& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType temp{ rhs };
    Swap(temp);

    return *this;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename T>
CoreTools::SmartPointer3DArray<T>& CoreTools::SmartPointer3DArray<T>::operator=(PointerType data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ClassType temp{ data };
    Swap(temp);

    return *this;
}
#include STSTEM_WARNING_POP


// private
template <typename T>
void CoreTools::SmartPointer3DArray<T>::Swap(SmartPointer3DArray& rhs) noexcept
{
    std::swap(m_Data, rhs.m_Data);
}

template <typename T>
CoreTools::SmartPointer3DArray<T>::SmartPointer3DArray(SmartPointer3DArray&& rhs) noexcept
    : m_Data{ std::move(rhs.m_Data) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::SmartPointer3DArray<T>& CoreTools::SmartPointer3DArray<T>::operator=(SmartPointer3DArray&& rhs) noexcept
{
    m_Data = std::move(rhs.m_Data);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SmartPointer3DArray<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename CoreTools::SmartPointer3DArray<T>::ConstPointerType CoreTools::SmartPointer3DArray<T>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Data;
}

template <typename T>
CoreTools::SmartPointer3DArray<T>::operator ConstPointerType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointer3DArray<T>::ConstReferenceType CoreTools::SmartPointer3DArray<T>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return *GetData();
}

template <typename T>
typename CoreTools::SmartPointer3DArray<T>::PointerType CoreTools::SmartPointer3DArray<T>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(PointerType, GetData);
}

template <typename T>
CoreTools::SmartPointer3DArray<T>::operator PointerType() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetData();
}

template <typename T>
typename CoreTools::SmartPointer3DArray<T>::ReferenceType CoreTools::SmartPointer3DArray<T>::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return *GetData();
}

template <typename T>
bool CoreTools::operator==(const SmartPointer3DArray<T>& lhs, T*** data) noexcept
{
    if (lhs.GetData() == data)
        return true;
    else
        return false;
}

template <typename T>
bool CoreTools::operator==(const SmartPointer3DArray<T>& lhs, const SmartPointer3DArray<T>& rhs) noexcept
{
    return lhs.GetData() == rhs.GetData();
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_DETAIL_H
