/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 11:00)

/// 成员函数所需要的宏
#ifndef CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H

#include <type_traits>
#include <utility>

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName() const                                   \
    {                                                                                           \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                      \
        return impl->functionName();                                                            \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName() const noexcept                                   \
    {                                                                                                    \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                               \
        return impl->functionName();                                                                     \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter) const                       \
    {                                                                                                             \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                                        \
        return impl->functionName(parameter);                                                                     \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter) const noexcept                       \
    {                                                                                                                      \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                                                 \
        return impl->functionName(parameter);                                                                              \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter) const                             \
    {                                                                                                            \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                                       \
        return impl->functionName(parameter);                                                                    \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter) const noexcept                             \
    {                                                                                                                     \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                                                \
        return impl->functionName(parameter);                                                                             \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter) const                       \
    {                                                                                                             \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                                        \
        return impl->functionName(parameter);                                                                     \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter) const noexcept                       \
    {                                                                                                                      \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                                                 \
        return impl->functionName(parameter);                                                                              \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName()                                             \
    {                                                                                               \
        CORE_TOOLS_CLASS_IS_VALID_1;                                                                \
        return impl->functionName();                                                                \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName() noexcept                                             \
    {                                                                                                        \
        CORE_TOOLS_CLASS_IS_VALID_1;                                                                         \
        return impl->functionName();                                                                         \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter)                                 \
    {                                                                                                                 \
        CORE_TOOLS_CLASS_IS_VALID_1;                                                                                  \
        return impl->functionName(parameter);                                                                         \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter) noexcept                                 \
    {                                                                                                                          \
        CORE_TOOLS_CLASS_IS_VALID_1;                                                                                           \
        return impl->functionName(parameter);                                                                                  \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter)                                       \
    {                                                                                                                \
        CORE_TOOLS_CLASS_IS_VALID_1;                                                                                 \
        return impl->functionName(parameter);                                                                        \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter) noexcept                                       \
    {                                                                                                                         \
        CORE_TOOLS_CLASS_IS_VALID_1;                                                                                          \
        return impl->functionName(parameter);                                                                                 \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter)                                 \
    {                                                                                                                 \
        CORE_TOOLS_CLASS_IS_VALID_1;                                                                                  \
        return impl->functionName(parameter);                                                                         \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter) noexcept                                 \
    {                                                                                                                          \
        CORE_TOOLS_CLASS_IS_VALID_1;                                                                                           \
        return impl->functionName(parameter);                                                                                  \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT                                                                                \
    static_assert(std::is_same_v<ClassShareType::NonConstMember, CoreTools::TrueType>, "Non-const member functions are forbidden"); \
    CORE_TOOLS_CLASS_IS_VALID_1

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT                                                                                    \
    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "Non-const copy member functions are forbidden"); \
    CORE_TOOLS_CLASS_IS_VALID_1;                                                                                                             \
    Copy()

#define IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT \
    static_assert(std::is_same_v<ClassShareType::CopyConstructor, CoreTools::TrueType>, "CopyConstructor functions are forbidden")

#define OPERATOR_SQUARE_BRACKETS(returnType, index) \
    const_cast<returnType&>(static_cast<const ClassType&>(*this)[index])

#define OPERATOR_SQUARE_BRACKETS_TO_POINTER(returnType, index) \
    const_cast<returnType*>(static_cast<const ClassType&>(*this)[index])

#define NON_CONST_MEMBER_CALL_CONST_MEMBER(returnType, function) \
    const_cast<returnType>(static_cast<const ClassType*>(this)->function())

#define NON_CONST_MEMBER_CALL_CONST_MEMBER_USE_PARAMETER(returnType, function, parameter) \
    const_cast<returnType>(static_cast<const ClassType*>(this)->function(parameter))

#endif  // CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H
