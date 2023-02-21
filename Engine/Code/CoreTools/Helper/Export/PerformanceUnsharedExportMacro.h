///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.2 (2023/02/19 21:02)

#ifndef CORE_TOOLS_HELPER_PERFORMANCE_UNSHARED_EXPORT_MACRO_H
#define CORE_TOOLS_HELPER_PERFORMANCE_UNSHARED_EXPORT_MACRO_H

#include "CoreTools/Contract/PerformanceUnsharedImplDetail.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

#ifdef BUILDING_STATIC

    #define EXPORT_PERFORMANCE_UNSHARED(namespaceName, implClassName, exportName)

#else  // !BUILDING_STATIC

    #define EXPORT_PERFORMANCE_UNSHARED(namespaceName, implClassName, exportName) \
        template class exportName CoreTools::PerformanceUnsharedImpl<namespaceName::implClassName>

#endif  // BUILDING_STATIC

#define PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, namespaceName) \
    EXPORT_CONST_IMPL(implClassName, namespaceName, PERFORMANCE_UNSHARED)

#define CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, CORE_TOOLS)

#define NETWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, NETWORK)

#define DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, DATABASE)

#define SCRIPT_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, SCRIPT)

#define MATHEMATICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, MATHEMATICS)

#define SOUND_EFFECT_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, SOUND_EFFECT)

#define INPUT_OUTPUT_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, INPUT_OUTPUT)

#define RESOURCE_MANAGER_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, RESOURCE_MANAGER)

#define RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, RENDERING)

#define PHYSICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, PHYSICS)

#define IMAGICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, IMAGICS)

#define ANIMATION_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, ANIMATION)

#define ARTIFICIAL_INTELLEGENCE_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, ARTIFICIAL_INTELLEGENCE)

#define USER_INTERFACE_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, USER_INTERFACE)

#define ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, ASSIST_TOOLS)

#define FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName) \
    PERFORMANCE_UNSHARED_EXPORT_IMPL(implClassName, FRAMEWORK)

#define PERFORMANCE_UNSHARED_TYPE_DECLARE(className) \
    TYPE_DECLARE(className);                         \
    using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;

#endif  // CORE_TOOLS_HELPER_PERFORMANCE_UNSHARED_EXPORT_MACRO_H
