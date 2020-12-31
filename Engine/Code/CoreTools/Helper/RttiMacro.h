//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 16:25)

#ifndef CORE_TOOLS_HELPER_RTTI_MACRO_H
#define CORE_TOOLS_HELPER_RTTI_MACRO_H

#include "CoreTools/ObjectSystems/Rtti.h"

#define CORE_TOOLS_RTTI_DECLARE                                                \
public:                                                                        \
    [[nodiscard]] virtual const CoreTools::Rtti& GetRttiType() const noexcept; \
    [[nodiscard]] static const CoreTools::Rtti& GetCurrentRttiType() noexcept;

#define CORE_TOOLS_RTTI_OVERRIDE_DECLARE                                        \
public:                                                                         \
    [[nodiscard]] const CoreTools::Rtti& GetRttiType() const noexcept override; \
    [[nodiscard]] static const CoreTools::Rtti& GetCurrentRttiType() noexcept;

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
