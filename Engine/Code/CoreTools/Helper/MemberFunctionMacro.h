//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/09/30 9:44)

// 成员函数所需要的宏
#ifndef CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H

#include <type_traits>
#include <utility>

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName() const                                   \
    {                                                                                           \
        CLASS_IS_VALID_CONST_0;                                                                 \
        return m_Impl->functionName();                                                          \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter) const                       \
    {                                                                                                             \
        CLASS_IS_VALID_CONST_0;                                                                                   \
        return m_Impl->functionName(parameter);                                                                   \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter) const                             \
    {                                                                                                            \
        CLASS_IS_VALID_CONST_0;                                                                                  \
        return m_Impl->functionName(parameter);                                                                  \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter) const                       \
    {                                                                                                             \
        CLASS_IS_VALID_CONST_0;                                                                                   \
        return m_Impl->functionName(parameter);                                                                   \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName() const noexcept                                   \
    {                                                                                                    \
        CLASS_IS_VALID_CONST_0;                                                                          \
        return m_Impl->functionName();                                                                   \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter) const noexcept                       \
    {                                                                                                                      \
        CLASS_IS_VALID_CONST_0;                                                                                            \
        return m_Impl->functionName(parameter);                                                                            \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter) const noexcept                             \
    {                                                                                                                     \
        CLASS_IS_VALID_CONST_0;                                                                                           \
        return m_Impl->functionName(parameter);                                                                           \
    }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter) const noexcept                       \
    {                                                                                                                      \
        CLASS_IS_VALID_CONST_0;                                                                                            \
        return m_Impl->functionName(parameter);                                                                            \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT                                                                                \
    static_assert(std::is_same_v<ClassShareType::NonConstMember, CoreTools::TrueType>, "Non-const member functions are forbidden"); \
    CLASS_IS_VALID_0

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT                                                                                    \
    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "Non-const copy member functions are forbidden"); \
    CLASS_IS_VALID_0;                                                                                                                        \
    Copy()

#define IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT \
    static_assert(std::is_same_v<ClassShareType::CopyConstructor, CoreTools::TrueType>, "CopyConstructor functions are forbidden")

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName()                                             \
    {                                                                                               \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                               \
        return m_Impl->functionName();                                                              \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter)                                 \
    {                                                                                                                 \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                                 \
        return m_Impl->functionName(parameter);                                                                       \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter)                                       \
    {                                                                                                                \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                                \
        return m_Impl->functionName(parameter);                                                                      \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter)                                 \
    {                                                                                                                 \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                                 \
        return m_Impl->functionName(parameter);                                                                       \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName() noexcept                                             \
    {                                                                                                        \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                        \
        return m_Impl->functionName();                                                                       \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter) noexcept                                 \
    {                                                                                                                          \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                                          \
        return m_Impl->functionName(parameter);                                                                                \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter) noexcept                                       \
    {                                                                                                                         \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                                         \
        return m_Impl->functionName(parameter);                                                                               \
    }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter) noexcept                                 \
    {                                                                                                                          \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                                          \
        return m_Impl->functionName(parameter);                                                                                \
    }

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(namespaceName, className, functionName, returnType) \
    returnType namespaceName::className::functionName()                                                  \
    {                                                                                                    \
        IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;                                               \
        return m_Impl->functionName();                                                                   \
    }

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType& parameter)                                      \
    {                                                                                                                      \
        IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;                                                                 \
        return m_Impl->functionName(parameter);                                                                            \
    }

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(parameterType parameter)                                            \
    {                                                                                                                     \
        IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;                                                                \
        return m_Impl->functionName(parameter);                                                                           \
    }

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CP(namespaceName, className, functionName, parameterType, returnType) \
    returnType namespaceName::className::functionName(const parameterType* parameter)                                      \
    {                                                                                                                      \
        IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;                                                                 \
        return m_Impl->functionName(parameter);                                                                            \
    }

#define OPERATOR_SQUARE_BRACKETS(returnType, index) \
    const_cast<returnType&>(static_cast<const ClassType&>(*this)[index]);

#define OPERATOR_SQUARE_BRACKETS_TO_POINTER(returnType, index) \
    const_cast<returnType*>(static_cast<const ClassType&>(*this)[index]);

#define NON_CONST_MEMBER_CALL_CONST_MEMBER(returnType, function) \
    const_cast<returnType>(static_cast<const ClassType*>(this)->function())

#define NON_CONST_MEMBER_CALL_CONST_MEMBER_USE_PARAMETER(returnType, function, parameter) \
    const_cast<returnType>(static_cast<const ClassType*>(this)->function(parameter))

#define COPY_CONSTRUCTION_DEFINE(namespaceName, className)                                  \
    namespaceName::className::className(const className& rhs)                               \
        : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }                                 \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        className temp{ rhs };                                                              \
        Swap(temp);                                                                         \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                       \
        std::swap(m_Impl, rhs.m_Impl);                                                      \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : m_Impl{ std::move(rhs.m_Impl) }                                                   \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        m_Impl = std::move(rhs.m_Impl);                                                     \
        return *this;                                                                       \
    }

#define COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE(namespaceName, className)                  \
    namespaceName::className::className(const className& rhs)                               \
        : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }                                 \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        m_Impl = std::make_shared<ImplType>(*rhs.m_Impl);                                   \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                       \
        std::swap(m_Impl, rhs.m_Impl);                                                      \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : m_Impl{ std::move(rhs.m_Impl) }                                                   \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        m_Impl = std::move(rhs.m_Impl);                                                     \
        return *this;                                                                       \
    }

#define COPY_CONSTRUCTION_DEFINE_WITH_PARENT(namespaceName, className)                      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }              \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        className temp{ rhs };                                                              \
        Swap(temp);                                                                         \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                       \
        std::swap(m_Impl, rhs.m_Impl);                                                      \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, m_Impl{ std::move(rhs.m_Impl) }                     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        m_Impl = std::move(rhs.m_Impl);                                                     \
        return *this;                                                                       \
    }

#define COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE_WITH_PARENT(namespaceName, className)      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }              \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(rhs);                                                         \
        m_Impl = std::make_shared<ImplType>(*rhs.m_Impl);                                   \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                       \
        std::swap(m_Impl, rhs.m_Impl);                                                      \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, m_Impl{ std::move(rhs.m_Impl) }                     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        m_Impl = std::move(rhs.m_Impl);                                                     \
        return *this;                                                                       \
    }

#define COPY_CONSTRUCTION_CLONE_DEFINE(namespaceName, className)                            \
    namespaceName::className::className(const className& rhs)                               \
        : m_Impl{ rhs.m_Impl->Clone() }                                                     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        m_Impl = rhs.m_Impl->Clone();                                                       \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                       \
        std::swap(m_Impl, rhs.m_Impl);                                                      \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : m_Impl{ std::move(rhs.m_Impl) }                                                   \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        m_Impl = std::move(rhs.m_Impl);                                                     \
        return *this;                                                                       \
    }

#define COPY_CONSTRUCTION_CLONE_DEFINE_WITH_PARENT(namespaceName, className)                \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, m_Impl{ rhs.m_Impl->Clone() }                                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(rhs);                                                         \
        m_Impl = rhs.m_Impl->Clone();                                                       \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                       \
        std::swap(m_Impl, rhs.m_Impl);                                                      \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ rhs }, m_Impl{ std::move(rhs.m_Impl) }                                \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        m_Impl = std::move(rhs.m_Impl);                                                     \
        return *this;                                                                       \
    }

#define DELAY_COPY_CONSTRUCTION_DEFINE(namespaceName, className)                                                                                                               \
    void namespaceName::className::Copy()                                                                                                                                      \
    {                                                                                                                                                                          \
        static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "It is not allowed to define the Copy function used for copy delayed."); \
        CLASS_IS_VALID_0;                                                                                                                                                      \
        if (1 < m_Impl.use_count())                                                                                                                                            \
        {                                                                                                                                                                      \
            m_Impl = std::make_shared<ImplType>(*m_Impl);                                                                                                                      \
        }                                                                                                                                                                      \
    }

#define DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(namespaceName, className)                                                                                                         \
    void namespaceName::className::Copy()                                                                                                                                      \
    {                                                                                                                                                                          \
        static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "It is not allowed to define the Copy function used for copy delayed."); \
        CLASS_IS_VALID_0;                                                                                                                                                      \
        if (1 < m_Impl.use_count())                                                                                                                                            \
        {                                                                                                                                                                      \
            m_Impl = m_Impl->Clone();                                                                                                                                          \
        }                                                                                                                                                                      \
    }

#endif  // CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H
