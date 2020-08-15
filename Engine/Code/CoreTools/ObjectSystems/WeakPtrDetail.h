// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.4.0.2 (2020/07/31 17:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_WEAK_PTR_DETAIL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_WEAK_PTR_DETAIL_H

#include "WeakPtr.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::WeakPtr<T>::WeakPtr(uint64_t uniqueID)
    : m_UniqueID{ uniqueID }, m_WeakPtr{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::WeakPtr<T>::WeakPtr(const std::shared_ptr<T>& ptr)
    : m_UniqueID{ ptr->GetUniqueID() }, m_WeakPtr{ ptr }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::WeakPtr<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
std::shared_ptr<T> CoreTools::WeakPtr<T>::GetPtr()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_WeakPtr.lock();
}

template <typename T>
uint64_t CoreTools::WeakPtr<T>::GetUniqueID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_UniqueID;
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_WEAK_PTR_DETAIL_H