/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 10:58)

#ifndef CORE_TOOLS_HELPER_RTTI_MACRO_H
#define CORE_TOOLS_HELPER_RTTI_MACRO_H

#include "CoreTools/ObjectSystems/Rtti.h"

#define CORE_TOOLS_RTTI_DECLARE                                            \
    NODISCARD virtual const CoreTools::Rtti& GetRttiType() const noexcept; \
    NODISCARD static const CoreTools::Rtti& GetCurrentRttiType() noexcept

#define CORE_TOOLS_RTTI_OVERRIDE_DECLARE                                    \
    NODISCARD const CoreTools::Rtti& GetRttiType() const noexcept override; \
    NODISCARD static const CoreTools::Rtti& GetCurrentRttiType() noexcept

#define CORE_TOOLS_RTTI_FINAL_DECLARE                                    \
    NODISCARD const CoreTools::Rtti& GetRttiType() const noexcept final; \
    NODISCARD static const CoreTools::Rtti& GetCurrentRttiType() noexcept

#define CORE_TOOLS_RTTI_DEFINE(namespaceName, className)                                                                                         \
    const CoreTools::Rtti& namespaceName::className::GetRttiType() const noexcept                                                                \
    {                                                                                                                                            \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                                                                       \
        return GetCurrentRttiType();                                                                                                             \
    }                                                                                                                                            \
    const CoreTools::Rtti& namespaceName::className::GetCurrentRttiType() noexcept                                                               \
    {                                                                                                                                            \
        static const CoreTools::Rtti rtti{ SYSTEM_STRINGIZE(namespaceName) "." SYSTEM_STRINGIZE(className), &ParentType::GetCurrentRttiType() }; \
        return rtti;                                                                                                                             \
    }

#define CORE_TOOLS_RTTI_BASE_DEFINE(namespaceName, className)                                                          \
    const CoreTools::Rtti& namespaceName::className::GetRttiType() const noexcept                                      \
    {                                                                                                                  \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                                                             \
        return GetCurrentRttiType();                                                                                   \
    }                                                                                                                  \
    const CoreTools::Rtti& namespaceName::className::GetCurrentRttiType() noexcept                                     \
    {                                                                                                                  \
        static const CoreTools::Rtti rtti{ SYSTEM_STRINGIZE(namespaceName) "." SYSTEM_STRINGIZE(className), nullptr }; \
        return rtti;                                                                                                   \
    }

#endif  // CORE_TOOLS_HELPER_RTTI_MACRO_H
