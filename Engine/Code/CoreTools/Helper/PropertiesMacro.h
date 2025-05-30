/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 10:59)

#ifndef CORE_TOOLS_HELPER_PROPERTIES_MACRO_H
#define CORE_TOOLS_HELPER_PROPERTIES_MACRO_H

#include "UserMacro.h"

#if defined(TCRE_USE_METROWERKS)

    #define TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(T) friend class T

#elif defined(TCRE_USE_BORLANDC) || defined(TCRE_USE_COMEAU) || defined(TCRE_USE_DIGITAL_MARS) || \
    (defined(TCRE_USE_GCC) && TCRE_USE_GCC < 3) || defined(TCRE_USE_INTEL) || defined(TCRE_USE_MSVC)

    #define TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(T) friend T

#elif defined(TCRE_USE_GCC) && 3 <= TCRE_USE_GCC

    #define TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(T) \
        struct FriendMaker                           \
        {                                            \
            using MakerT = T;                        \
        };                                           \
        using FriendType = FriendMaker::MakerT;      \
        friend FriendType

#else  // !defined(ALL)

    #error "������δʶ��"

#endif  // defined(TCRE_USE_METROWERKS)

#define TCRE_METHOD_PROPERTY_GET(value, constReference, container, get, property, isNoexcept)                  \
    NODISCARD static ptrdiff_t SYSTEM_MULTIPLE_CONCATENATOR(property, Offset, __LINE__)() noexcept(isNoexcept) \
    {                                                                                                          \
        return offsetof(container, property);                                                                  \
    }                                                                                                          \
    CoreTools::MethodPropertyGet<value, constReference, container, &container::SYSTEM_MULTIPLE_CONCATENATOR(property, Offset, __LINE__), &container::get> property

#define TCRE_METHOD_PROPERTY_SET(value, reference, container, set, property, isNoexcept)                       \
    NODISCARD static ptrdiff_t SYSTEM_MULTIPLE_CONCATENATOR(property, Offset, __LINE__)() noexcept(isNoexcept) \
    {                                                                                                          \
        return offsetof(container, property);                                                                  \
    }                                                                                                          \
    CoreTools::MethodPropertySet<value, reference, container, &container::SYSTEM_MULTIPLE_CONCATENATOR(property, Offset, __LINE__), &container::set> property

#define TCRE_METHOD_PROPERTY_GET_SET(value, getReference, setReference, container, get, set, property, isNoexcept) \
    NODISCARD static ptrdiff_t SYSTEM_MULTIPLE_CONCATENATOR(property, Offset, __LINE__)() noexcept(isNoexcept)     \
    {                                                                                                              \
        return offsetof(container, property);                                                                      \
    }                                                                                                              \
    CoreTools::MethodPropertyGetSet<value, getReference, setReference, container, &container::SYSTEM_MULTIPLE_CONCATENATOR(property, Offset, __LINE__), &container::get, &container::set> property

#define TCRE_DECLARE_PROPERTY(className, type, reference, name, set, get) \
    class SYSTEM_CONCATENATOR(Prop, name)                                 \
    {                                                                     \
    };                                                                    \
    CoreTools::Property<SYSTEM_CONCATENATOR(Prop, name), className, type, reference, &className::set, &className::get> name

#define TCRE_DEFINE_PROPERTY(className, name) \
    const ptrdiff_t CoreTools::PropertyBase<className::SYSTEM_CONCATENATOR(Prop, name), className>::offset = offsetof(className, name)

#ifdef TCRE_USE_BORLANDC

    #define TCRE_PROPERTY_READ(type, name, function) __property type name = { read = function }
    #define TCRE_PROPERTY_WRITE(type, name, function) __property type name = { write = function }
    #define TCRE_PROPERTY_READ_WRITE(type, name, getFunction, setFunction) __property type name = { read = getFunction, write = setFunction }

#elif defined(TCRE_USE_MSVC)

    #define TCRE_PROPERTY_READ(type, name, function) __declspec(property(get = function)) type name
    #define TCRE_PROPERTY_WRITE(type, name, function) __declspec(property(put = function)) type name
    #define TCRE_PROPERTY_READ_WRITE(type, name, getFunction, setFunction) __declspec(property(get = getFunction, put = setFunction)) type name

#else  // !TCRE_USE_BORLANDC && !TCRE_USE_MSVC

    #define TCRE_PROPERTY_READ(type, name, function) CoreTools::PropertyGetExternal<ClassType, const type&, &ClassType::function> name
    #define TCRE_PROPERTY_WRITE(type, name, function) CoreTools::PropertySetExternal<ClassType, const type&, &ClassType::function> name
    #define TCRE_PROPERTY_READ_WRITE(type, name, getFunction, setFunction) CoreTools::PropertyGetSetExternal<ClassType, const type&, &ClassType::getFunction, const type&, &ClassType::setFunction> name

#endif  // TCRE_USE_BORLANDC

#endif  // CORE_TOOLS_HELPER_PROPERTIES_MACRO_H
