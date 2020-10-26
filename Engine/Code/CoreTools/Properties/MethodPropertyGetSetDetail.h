//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:37)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_DETAIL_H

#include "MethodPropertyGetSet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename GetReference, typename SetReference, typename Container,
          ptrdiff_t (*FO)(), GetReference (Container::*FG)() const, void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::MethodPropertyGetSet()
    : m_Value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value, typename GetReference, typename SetReference, typename Container,
          ptrdiff_t (*FO)(), GetReference (Container::*FG)() const, void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::MethodPropertyGetSet(SetReferenceType value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Value, typename GetReference, typename SetReference, typename Container,
          ptrdiff_t (*FO)(), GetReference (Container::*FG)() const, void (Container::*FS)(SetReference)>
bool CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename GetReference, typename SetReference, typename Container,
          ptrdiff_t (*FO)(), GetReference (Container::*FG)() const, void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::operator GetReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<const ContainerType*>(reinterpret_cast<const uint8_t*>(this) - offset);

    return (thisPtr->*FG)();
}

template <typename Value, typename GetReference, typename SetReference, typename Container,
          ptrdiff_t (*FO)(), GetReference (Container::*FG)() const, void (Container::*FS)(SetReference)>
CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>& CoreTools::MethodPropertyGetSet<Value, GetReference, SetReference, Container, FO, FG, FS>::operator=(SetReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto offset = (*FO)();
    auto thisPtr = reinterpret_cast<ContainerType*>(reinterpret_cast<uint8_t*>(this) - offset);

    (thisPtr->*FS)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_DETAIL_H