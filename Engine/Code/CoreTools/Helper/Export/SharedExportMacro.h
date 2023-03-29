///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:46)

#ifndef CORE_TOOLS_HELPER_SHARED_EXPORT_MACRO_H
#define CORE_TOOLS_HELPER_SHARED_EXPORT_MACRO_H

#include "CoreTools/Contract/SharedImplDetail.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

#ifdef BUILDING_STATIC

    #define EXPORT_SHARED(namespaceName, implClassName, exportName)

#else  // !BUILDING_STATIC

    #define EXPORT_SHARED(namespaceName, implClassName, exportName) \
        template class exportName CoreTools::SharedImpl<namespaceName::implClassName>

#endif  // BUILDING_STATIC

#define SHARED_EXPORT_IMPL(implClassName, namespaceName) \
    EXPORT_IMPL(implClassName, namespaceName, SHARED)

#define CORE_TOOLS_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, CORE_TOOLS)

#define NETWORK_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, NETWORK)

#define DATABASE_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, DATABASE)

#define SCRIPT_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, SCRIPT)

#define MATHEMATICS_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, MATHEMATICS)

#define SOUND_EFFECT_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, SOUND_EFFECT)

#define INPUT_OUTPUT_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, INPUT_OUTPUT)

#define RESOURCE_MANAGER_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, RESOURCE_MANAGER)

#define RENDERING_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, RENDERING)

#define PHYSICS_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, PHYSICS)

#define IMAGICS_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, IMAGICS)

#define ANIMATION_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, ANIMATION)

#define ARTIFICIAL_INTELLIGENCE_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, ARTIFICIAL_INTELLIGENCE)

#define USER_INTERFACE_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, USER_INTERFACE)

#define ASSIST_TOOLS_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, ASSIST_TOOLS)

#define FRAMEWORK_SHARED_EXPORT_IMPL(implClassName) \
    SHARED_EXPORT_IMPL(implClassName, FRAMEWORK)

#define SHARED_TYPE_DECLARE(className) \
    TYPE_DECLARE(className);           \
    using PackageType = CoreTools::SharedImpl<ImplType>

#endif  // CORE_TOOLS_HELPER_SHARED_EXPORT_MACRO_H
