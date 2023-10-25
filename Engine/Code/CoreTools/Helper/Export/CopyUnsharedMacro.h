///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:12)

#ifndef CORE_TOOLS_HELPER_COPY_UNSHARED_MACRO_H
#define CORE_TOOLS_HELPER_COPY_UNSHARED_MACRO_H

#include "CoreTools/Contract/CopyUnsharedImplDetail.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

#ifdef BUILDING_STATIC

    #define EXPORT_COPY_UNSHARED(namespaceName, className, implClassName, exportName)

#else  // !BUILDING_STATIC

    #define EXPORT_COPY_UNSHARED(namespaceName, className, implClassName, exportName) \
        namespace namespaceName                                                       \
        {                                                                             \
            class className;                                                          \
        }                                                                             \
        template class exportName CoreTools::CopyUnsharedImpl<namespaceName::className, namespaceName::implClassName>

#endif  // BUILDING_STATIC

#define COPY_UNSHARED_EXPORT_IMPL(className, implClassName, namespaceName) \
    EXPORT_COPY_IMPL(className, implClassName, namespaceName, COPY_UNSHARED)

#define CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, CORE_TOOLS)

#define NETWORK_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, NETWORK)

#define DATABASE_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, DATABASE)

#define SCRIPT_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, SCRIPT)

#define MATHEMATICS_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, MATHEMATICS)

#define SOUND_EFFECT_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, SOUND_EFFECT)

#define INPUT_OUTPUT_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, INPUT_OUTPUT)

#define RESOURCE_MANAGER_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, RESOURCE_MANAGER)

#define RENDERING_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, RENDERING)

#define PHYSICS_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, PHYSICS)

#define IMAGICS_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, IMAGICS)

#define ANIMATION_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, ANIMATION)

#define ARTIFICIAL_INTELLIGENCE_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, ARTIFICIAL_INTELLIGENCE)

#define USER_INTERFACE_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, USER_INTERFACE)

#define ASSIST_TOOLS_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, ASSIST_TOOLS)

#define FRAMEWORK_COPY_UNSHARED_EXPORT_IMPL(className, implClassName) \
    COPY_UNSHARED_EXPORT_IMPL(className, implClassName, FRAMEWORK)

#define COPY_UNSHARED_TYPE_DECLARE(className)                             \
    TYPE_DECLARE(className);                                              \
    using PackageType = CoreTools::CopyUnsharedImpl<ClassType, ImplType>; \
    using SharedPtr = std::shared_ptr<ImplType>;                          \
    COPY_UNSHARED_CLONE_SELF_DECLARE

#endif  // CORE_TOOLS_HELPER_COPY_UNSHARED_MACRO_H
