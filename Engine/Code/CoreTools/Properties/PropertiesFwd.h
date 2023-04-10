///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 14:43)

#ifndef CORE_TOOLS_PROPERTIES_FWD_H
#define CORE_TOOLS_PROPERTIES_FWD_H

namespace CoreTools
{
    template <typename Value,
              typename ConstReference>
    class SimplePropertyGetExternal;

    template <typename Value,
              typename Reference>
    class SimplePropertySetExternal;

    template <typename T,
              typename ConstReference,
              ConstReference (T::*PropertyFunction)() const>
    class PropertyGetExternal;

    template <typename T,
              typename Reference,
              void (T::*PropertyFunction)(Reference)>
    class PropertySetExternal;

    template <typename T,
              typename GetReference,
              GetReference (T::*PropertyGet)() const,
              typename SetReference,
              void (T::*PropertySet)(SetReference)>
    class PropertyGetSetExternal;

    template <typename ConstReference,
              ConstReference (*PropertyFunction)()>
    class StaticPropertyGetExternal;

    template <typename Reference,
              void (*PropertyFunction)(Reference)>
    class StaticPropertySetExternal;

    template <typename GetReference,
              typename SetReference,
              GetReference (*PropertyGet)(),
              void (*PropertySet)(SetReference)>
    class StaticPropertyGetSetExternal;

    template <typename Value,
              typename Reference,
              typename Container>
    class DirectPropertyGetInternal;

    template <typename Value,
              typename Reference,
              typename Container>
    class DirectPropertySetInternal;

    template <typename T,
              typename ConstReference,
              ConstReference (T::*PropertyFunction)() const,
              ptrdiff_t (*FunctionOffset)()>
    class PropertyGetExternalOffset;

    template <typename T,
              typename V,
              typename Reference,
              Reference (T::*PropertyFunction)() const,
              ptrdiff_t (*FunctionOffset)()>
    class PropertyGetInternalOffset;

    template <typename Value,
              typename ConstReference,
              typename Container,
              ptrdiff_t (*FunctionOffset)(),
              ConstReference (Container::*FunctionGet)() const>
    class MethodPropertyGet;

    template <typename Value,
              typename Reference,
              typename Container,
              ptrdiff_t (*FunctionOffset)(),
              void (Container::*FunctionSet)(Reference)>
    class MethodPropertySet;

    template <typename Value,
              typename GetReference,
              typename SetReference,
              typename Container,
              ptrdiff_t (*FunctionOffset)(),
              GetReference (Container::*FunctionGet)() const,
              void (Container::*FunctionSet)(SetReference)>
    class MethodPropertyGetSet;

    template <typename ConstReference,
              typename Container,
              ptrdiff_t (*FunctionOffset)(),
              ConstReference (Container::*FunctionGet)() const>
    class MethodPropertyGetExternal;

    template <typename Reference,
              typename Container,
              ptrdiff_t (*FunctionOffset)(),
              void (Container::*FunctionSet)(Reference)>
    class MethodPropertySetExternal;

    template <typename GetReference,
              typename SetReference,
              typename Container,
              ptrdiff_t (*FunctionOffset)(),
              GetReference (Container::*FunctionGet)() const,
              void (Container::*FunctionSet)(SetReference)>
    class MethodPropertyGetSetExternal;

    template <typename V,
              typename GetReference,
              typename SetReference,
              typename Container,
              GetReference (*FunctionGet)(),
              void (*FunctionSet)(SetReference)>
    class StaticPropertyGetSet;

    template <typename Id,
              typename T>
    class PropertyBase;

    template <typename Id,
              typename T,
              typename V,
              typename R,
              void (T::*FunctionSet)(R),
              R (T::*FunctionGet)() const>
    class Property;
}

#endif  // CORE_TOOLS_PROPERTIES_FWD_H