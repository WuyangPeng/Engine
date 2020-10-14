//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/07 18:58)

#ifndef CORE_TOOLS_HELPER_RTTI_MACRO_H
#define CORE_TOOLS_HELPER_RTTI_MACRO_H

#include "CoreTools/ObjectSystems/Rtti.h"

#define CORE_TOOLS_RTTI_DECLARE                                                \
public:                                                                        \
    [[nodiscard]] virtual const CoreTools::Rtti& GetRttiType() const noexcept; \
    static const CoreTools::Rtti sm_Type;

#define CORE_TOOLS_RTTI_OVERRIDE_DECLARE                                        \
public:                                                                         \
    [[nodiscard]] const CoreTools::Rtti& GetRttiType() const noexcept override; \
    static const CoreTools::Rtti sm_Type;

#define CORE_TOOLS_RTTI_DEFINE(namespaceName, className)                          \
    const CoreTools::Rtti& namespaceName::className::GetRttiType() const noexcept \
    {                                                                             \
        return sm_Type;                                                           \
    }                                                                             \
    const CoreTools::Rtti namespaceName::className::sm_Type{ SYSTEM_STRINGIZE(namespaceName) "." SYSTEM_STRINGIZE(className), &ParentType::sm_Type };

#define CORE_TOOLS_RTTI_BASE_DEFINE(namespaceName, className)                     \
    const CoreTools::Rtti& namespaceName::className::GetRttiType() const noexcept \
    {                                                                             \
        return sm_Type;                                                           \
    }                                                                             \
    const CoreTools::Rtti namespaceName::className::sm_Type{ SYSTEM_STRINGIZE(namespaceName) "." SYSTEM_STRINGIZE(className), nullptr };

#endif  // CORE_TOOLS_HELPER_RTTI_MACRO_H
