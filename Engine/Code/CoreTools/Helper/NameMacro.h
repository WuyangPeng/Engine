///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/31 2:07)

#ifndef CORE_TOOLS_HELPER_NAME_MACRO_H
#define CORE_TOOLS_HELPER_NAME_MACRO_H

#include "MemberFunctionMacro.h"
#include "System/Helper/MarkMacro.h"

#include <vector>

#define CORE_TOOLS_NAMES_DECLARE                                                                          \
public:                                                                                                   \
    using ObjectSharedPtrContainer = std::vector<ObjectSharedPtr>;                                        \
    using ConstObjectSharedPtrContainer = std::vector<ConstObjectSharedPtr>;                              \
    MAYBE_NULLPTR virtual const ObjectSharedPtr GetObjectByName(const std::string& name);                 \
    [[nodiscard]] virtual const ObjectSharedPtrContainer GetAllObjectsByName(const std::string& name);    \
    MAYBE_NULLPTR virtual const ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const; \
    [[nodiscard]] virtual const ConstObjectSharedPtrContainer GetAllConstObjectsByName(const std::string& name) const

#define CORE_TOOLS_NAMES_OVERRIDE_DECLARE                                                                  \
    MAYBE_NULLPTR const ObjectSharedPtr GetObjectByName(const std::string& name) override;                 \
    [[nodiscard]] const ObjectSharedPtrContainer GetAllObjectsByName(const std::string& name) override;    \
    MAYBE_NULLPTR const ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const override; \
    [[nodiscard]] const ConstObjectSharedPtrContainer GetAllConstObjectsByName(const std::string& name) const override

#define CORE_TOOLS_NAMES_FINAL_DECLARE                                                                  \
    MAYBE_NULLPTR const ObjectSharedPtr GetObjectByName(const std::string& name) final;                 \
    [[nodiscard]] const ObjectSharedPtrContainer GetAllObjectsByName(const std::string& name) final;    \
    MAYBE_NULLPTR const ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const final; \
    [[nodiscard]] const ConstObjectSharedPtrContainer GetAllConstObjectsByName(const std::string& name) const final

#define CORE_TOOLS_NAMES_IMPL_DECLARE                                                                        \
public:                                                                                                      \
    using ObjectSharedPtrContainer = std::vector<CoreTools::ObjectSharedPtr>;                                \
    using ConstObjectSharedPtrContainer = std::vector<CoreTools::ConstObjectSharedPtr>;                      \
    MAYBE_NULLPTR const CoreTools::ObjectSharedPtr GetObjectByName(const std::string& name);                 \
    [[nodiscard]] const ObjectSharedPtrContainer GetAllObjectsByName(const std::string& name);               \
    MAYBE_NULLPTR const CoreTools::ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const; \
    [[nodiscard]] const ConstObjectSharedPtrContainer GetAllConstObjectsByName(const std::string& name) const

#define CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(namespaceName, className)                                                                          \
    const CoreTools::ObjectSharedPtr namespaceName::className::GetObjectByName(const std::string& name)                                             \
    {                                                                                                                                               \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                                                               \
        auto found = ParentType::GetObjectByName(name);                                                                                             \
        if (found != nullptr)                                                                                                                       \
        {                                                                                                                                           \
            return found;                                                                                                                           \
        }                                                                                                                                           \
        else                                                                                                                                        \
        {                                                                                                                                           \
            return m_Impl->GetObjectByName(name);                                                                                                   \
        }                                                                                                                                           \
    }                                                                                                                                               \
    const namespaceName::className::ObjectSharedPtrContainer namespaceName::className::GetAllObjectsByName(const std::string& name)                 \
    {                                                                                                                                               \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                                                                               \
        auto parentObjects = ParentType::GetAllObjectsByName(name);                                                                                 \
        auto implObjects = m_Impl->GetAllObjectsByName(name);                                                                                       \
        parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());                                                          \
        return parentObjects;                                                                                                                       \
    }                                                                                                                                               \
    const CoreTools::ConstObjectSharedPtr namespaceName::className::GetConstObjectByName(const std::string& name) const                             \
    {                                                                                                                                               \
        CLASS_IS_VALID_CONST_0;                                                                                                                     \
        auto found = ParentType::GetConstObjectByName(name);                                                                                        \
        if (found != nullptr)                                                                                                                       \
        {                                                                                                                                           \
            return found;                                                                                                                           \
        }                                                                                                                                           \
        else                                                                                                                                        \
        {                                                                                                                                           \
            return m_Impl->GetConstObjectByName(name);                                                                                              \
        }                                                                                                                                           \
    }                                                                                                                                               \
    const namespaceName::className::ConstObjectSharedPtrContainer namespaceName::className::GetAllConstObjectsByName(const std::string& name) const \
    {                                                                                                                                               \
        CLASS_IS_VALID_CONST_0;                                                                                                                     \
        auto parentObjects = ParentType::GetAllConstObjectsByName(name);                                                                            \
        auto implObjects = m_Impl->GetAllConstObjectsByName(name);                                                                                  \
        parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());                                                          \
        return parentObjects;                                                                                                                       \
    }

#endif  // CORE_TOOLS_HELPER_RTTI_MACRO_H
