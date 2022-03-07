///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 0:53)

#ifndef CORE_TOOLS_HELPER_NAME_MACRO_H
#define CORE_TOOLS_HELPER_NAME_MACRO_H

#include "MemberFunctionMacro.h"

#include <vector>

#define CORE_TOOLS_NAMES_DECLARE                                                                    \
public:                                                                                             \
    using ObjectSharedPtrContainer = std::vector<ObjectSharedPtr>;                                  \
    using ConstObjectSharedPtrContainer = std::vector<ConstObjectSharedPtr>;                        \
    MAYBE_NULLPTR virtual ObjectSharedPtr GetObjectByName(const std::string& name);                 \
    NODISCARD virtual ObjectSharedPtrContainer GetAllObjectsByName(const std::string& name);        \
    MAYBE_NULLPTR virtual ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const; \
    NODISCARD virtual ConstObjectSharedPtrContainer GetAllConstObjectsByName(const std::string& name) const

#define CORE_TOOLS_NAMES_OVERRIDE_DECLARE                                                            \
    MAYBE_NULLPTR ObjectSharedPtr GetObjectByName(const std::string& name) override;                 \
    NODISCARD ObjectSharedPtrContainer GetAllObjectsByName(const std::string& name) override;        \
    MAYBE_NULLPTR ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const override; \
    NODISCARD ConstObjectSharedPtrContainer GetAllConstObjectsByName(const std::string& name) const override

#define CORE_TOOLS_NAMES_FINAL_DECLARE                                                            \
    MAYBE_NULLPTR ObjectSharedPtr GetObjectByName(const std::string& name) final;                 \
    NODISCARD ObjectSharedPtrContainer GetAllObjectsByName(const std::string& name) final;        \
    MAYBE_NULLPTR ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const final; \
    NODISCARD ConstObjectSharedPtrContainer GetAllConstObjectsByName(const std::string& name) const final

#define CORE_TOOLS_NAMES_IMPL_DECLARE                                                                  \
    using ObjectSharedPtrContainer = std::vector<CoreTools::ObjectSharedPtr>;                          \
    using ConstObjectSharedPtrContainer = std::vector<CoreTools::ConstObjectSharedPtr>;                \
    MAYBE_NULLPTR CoreTools::ObjectSharedPtr GetObjectByName(const std::string& name);                 \
    NODISCARD ObjectSharedPtrContainer GetAllObjectsByName(const std::string& name);                   \
    MAYBE_NULLPTR CoreTools::ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const; \
    NODISCARD ConstObjectSharedPtrContainer GetAllConstObjectsByName(const std::string& name) const

#define CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(namespaceName, className)                                                                    \
    CoreTools::ObjectSharedPtr namespaceName::className::GetObjectByName(const std::string& name)                                             \
    {                                                                                                                                         \
        CLASS_IS_VALID_0;                                                                                                                     \
        const auto found = ParentType::GetObjectByName(name);                                                                                 \
        if (found != nullptr)                                                                                                                 \
        {                                                                                                                                     \
            return found;                                                                                                                     \
        }                                                                                                                                     \
        else                                                                                                                                  \
        {                                                                                                                                     \
            return impl->GetObjectByName(name);                                                                                               \
        }                                                                                                                                     \
    }                                                                                                                                         \
    namespaceName::className::ObjectSharedPtrContainer namespaceName::className::GetAllObjectsByName(const std::string& name)                 \
    {                                                                                                                                         \
        CLASS_IS_VALID_0;                                                                                                                     \
        auto parentObjects = ParentType::GetAllObjectsByName(name);                                                                           \
        const auto implObjects = impl->GetAllObjectsByName(name);                                                                             \
        parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());                                                    \
        return parentObjects;                                                                                                                 \
    }                                                                                                                                         \
    CoreTools::ConstObjectSharedPtr namespaceName::className::GetConstObjectByName(const std::string& name) const                             \
    {                                                                                                                                         \
        CLASS_IS_VALID_CONST_0;                                                                                                               \
        const auto found = ParentType::GetConstObjectByName(name);                                                                            \
        if (found != nullptr)                                                                                                                 \
        {                                                                                                                                     \
            return found;                                                                                                                     \
        }                                                                                                                                     \
        else                                                                                                                                  \
        {                                                                                                                                     \
            return impl->GetConstObjectByName(name);                                                                                          \
        }                                                                                                                                     \
    }                                                                                                                                         \
    namespaceName::className::ConstObjectSharedPtrContainer namespaceName::className::GetAllConstObjectsByName(const std::string& name) const \
    {                                                                                                                                         \
        CLASS_IS_VALID_CONST_0;                                                                                                               \
        auto parentObjects = ParentType::GetAllConstObjectsByName(name);                                                                      \
        const auto implObjects = impl->GetAllConstObjectsByName(name);                                                                        \
        parentObjects.insert(parentObjects.end(), implObjects.begin(), implObjects.end());                                                    \
        return parentObjects;                                                                                                                 \
    }

#endif  // CORE_TOOLS_HELPER_RTTI_MACRO_H
