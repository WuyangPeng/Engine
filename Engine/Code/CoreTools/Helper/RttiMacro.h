///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.1 (2021/07/29 15:55)

#ifndef CORE_TOOLS_HELPER_RTTI_MACRO_H
#define CORE_TOOLS_HELPER_RTTI_MACRO_H

#include "CoreTools/ObjectSystems/Rtti.h"

#define CORE_TOOLS_RTTI_DECLARE                                            \
public:                                                                    \
    NODISCARD virtual const CoreTools::Rtti& GetRttiType() const noexcept; \
    NODISCARD static const CoreTools::Rtti& GetCurrentRttiType() noexcept;

#define CORE_TOOLS_RTTI_OVERRIDE_DECLARE                                    \
public:                                                                     \
    NODISCARD const CoreTools::Rtti& GetRttiType() const noexcept override; \
    NODISCARD static const CoreTools::Rtti& GetCurrentRttiType() noexcept;

#define CORE_TOOLS_RTTI_FINAL_DECLARE                                    \
public:                                                                  \
    NODISCARD const CoreTools::Rtti& GetRttiType() const noexcept final; \
    NODISCARD static const CoreTools::Rtti& GetCurrentRttiType() noexcept;

#define CORE_TOOLS_RTTI_DEFINE(namespaceName, className)                                                                                         \
    const CoreTools::Rtti& namespaceName::className::GetRttiType() const noexcept                                                                \
    {                                                                                                                                            \
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
        return GetCurrentRttiType();                                                                                   \
    }                                                                                                                  \
    const CoreTools::Rtti& namespaceName::className::GetCurrentRttiType() noexcept                                     \
    {                                                                                                                  \
        static const CoreTools::Rtti rtti{ SYSTEM_STRINGIZE(namespaceName) "." SYSTEM_STRINGIZE(className), nullptr }; \
        return rtti;                                                                                                   \
    }

#endif  // CORE_TOOLS_HELPER_RTTI_MACRO_H
