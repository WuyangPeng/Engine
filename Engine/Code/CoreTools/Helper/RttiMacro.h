///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 0:52)

#ifndef CORE_TOOLS_HELPER_RTTI_MACRO_H
#define CORE_TOOLS_HELPER_RTTI_MACRO_H

#include "CoreTools/ObjectSystems/Rtti.h"

#define CORE_TOOLS_RTTI_DECLARE                                            \
    NODISCARD virtual const CoreTools::Rtti& GetRttiType() const noexcept; \
    NODISCARD static const CoreTools::Rtti& GetCurrentRttiType() noexcept;

#define CORE_TOOLS_RTTI_OVERRIDE_DECLARE                                    \
    NODISCARD const CoreTools::Rtti& GetRttiType() const noexcept override; \
    NODISCARD static const CoreTools::Rtti& GetCurrentRttiType() noexcept;

#define CORE_TOOLS_RTTI_FINAL_DECLARE                                    \
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
