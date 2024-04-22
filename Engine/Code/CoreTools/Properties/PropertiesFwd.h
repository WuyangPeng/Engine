/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:04)

#ifndef CORE_TOOLS_PROPERTIES_FWD_H
#define CORE_TOOLS_PROPERTIES_FWD_H

namespace CoreTools
{
    template <typename Value, typename ConstReference>
    requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
    class SimplePropertyGetExternal;

    template <typename Value, typename Reference>
    requires(std::is_reference_v<Reference>)
    class SimplePropertySetExternal;

    template <typename T,
              typename ConstReference,
              ConstReference (T::*PropertyFunction)() const>
    requires(std::is_const_v<std::remove_reference_t<ConstReference>> &&
             std::is_reference_v<ConstReference>)
    class PropertyGetExternal;

    template <typename T, typename Reference, void (T::*PropertyFunction)(Reference)>
    requires(std::is_reference_v<Reference>)
    class PropertySetExternal;

    template <typename T,
              typename GetReference,
              GetReference (T::*PropertyGet)() const,
              typename SetReference,
              void (T::*PropertySet)(SetReference)>
    requires(std::is_const_v<std::remove_reference_t<GetReference>> &&
             std::is_reference_v<GetReference> &&
             std::is_reference_v<SetReference>)
    class PropertyGetSetExternal;

    template <typename ConstReference, ConstReference (*PropertyFunction)()>
    requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
    class StaticPropertyGetExternal;

    template <typename Reference, void (*PropertyFunction)(Reference)>
    requires(std::is_reference_v<Reference>)
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