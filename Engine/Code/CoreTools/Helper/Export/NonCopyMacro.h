///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:12)

#ifndef CORE_TOOLS_HELPER_NON_COPY_MACRO_H
#define CORE_TOOLS_HELPER_NON_COPY_MACRO_H

#include "CoreTools/Contract/NonCopyImplDetail.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

#ifdef BUILDING_STATIC

    #define EXPORT_NON_COPY(namespaceName, implClassName, exportName)

#else  // !BUILDING_STATIC

    #define EXPORT_NON_COPY(namespaceName, implClassName, exportName) \
        template class exportName CoreTools::NonCopyImpl<namespaceName::implClassName>

#endif  // BUILDING_STATIC

#define NON_COPY_EXPORT_IMPL(implClassName, namespaceName) \
    EXPORT_IMPL(implClassName, namespaceName, NON_COPY)

#define CORE_TOOLS_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, CORE_TOOLS)

#define NETWORK_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, NETWORK)

#define DATABASE_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, DATABASE)

#define SCRIPT_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, SCRIPT)

#define MATHEMATICS_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, MATHEMATICS)

#define SOUND_EFFECT_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, SOUND_EFFECT)

#define INPUT_OUTPUT_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, INPUT_OUTPUT)

#define RESOURCE_MANAGER_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, RESOURCE_MANAGER)

#define RENDERING_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, RENDERING)

#define PHYSICS_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, PHYSICS)

#define IMAGICS_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, IMAGICS)

#define ANIMATION_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, ANIMATION)

#define ARTIFICIAL_INTELLIGENCE_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, ARTIFICIAL_INTELLIGENCE)

#define USER_INTERFACE_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, USER_INTERFACE)

#define ASSIST_TOOLS_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, ASSIST_TOOLS)

#define FRAMEWORK_NON_COPY_EXPORT_IMPL(implClassName) \
    NON_COPY_EXPORT_IMPL(implClassName, FRAMEWORK)

#define NON_COPY_TYPE_DECLARE(className) \
    TYPE_DECLARE(className);             \
    using PackageType = CoreTools::NonCopyImpl<ImplType>

#endif  // CORE_TOOLS_HELPER_NON_COPY_MACRO_H
