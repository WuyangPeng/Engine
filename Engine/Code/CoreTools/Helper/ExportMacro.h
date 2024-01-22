/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:14)

#ifndef CORE_TOOLS_HELPER_EXPORT_MACRO_H
#define CORE_TOOLS_HELPER_EXPORT_MACRO_H

#include "UserMacro.h"

#include <memory>

#if defined(BUILDING_STATIC) || defined(TCRE_USE_GCC)

    #define EXPORT_SHARED_PTR(namespaceName, implClassName, exportName) \
        namespace namespaceName                                         \
        {                                                               \
            class implClassName;                                        \
        }

    #define EXPORT_CONST_SHARED_PTR(namespaceName, implClassName, exportName) \
        namespace namespaceName                                               \
        {                                                                     \
            class implClassName;                                              \
        }

    #define EXPORT_UNIQUE_PTR(namespaceName, implClassName, exportName) \
        namespace namespaceName                                         \
        {                                                               \
            class implClassName;                                        \
        }

#else  // !BUILDING_STATIC && !TCRE_USE_GCC

    #define EXPORT_SHARED_PTR(namespaceName, implClassName, exportName) \
        namespace namespaceName                                         \
        {                                                               \
            class implClassName;                                        \
        }                                                               \
        template class exportName std::shared_ptr<namespaceName::implClassName>

    #define EXPORT_CONST_SHARED_PTR(namespaceName, implClassName, exportName) \
        namespace namespaceName                                               \
        {                                                                     \
            class implClassName;                                              \
        }                                                                     \
        template class exportName std::shared_ptr<const namespaceName::implClassName>

    #if defined(SYSTEM_PLATFORM_WIN32)

        #define EXPORT_UNIQUE_PTR(namespaceName, implClassName, exportName)                                                                    \
            namespace namespaceName                                                                                                            \
            {                                                                                                                                  \
                class implClassName;                                                                                                           \
            }                                                                                                                                  \
            template class exportName std::_Compressed_pair<std::default_delete<namespaceName::implClassName>, namespaceName::implClassName*>; \
            template class exportName std::unique_ptr<namespaceName::implClassName>

    #else  // !SYSTEM_PLATFORM_WIN32

        #define EXPORT_UNIQUE_PTR(namespaceName, implClassName, exportName) \
            namespace namespaceName                                         \
            {                                                               \
                class implClassName;                                        \
            }                                                               \
            template class exportName std::unique_ptr<namespaceName::implClassName>

    #endif  // SYSTEM_PLATFORM_WIN32

#endif  // defined(BUILDING_STATIC) || defined(TCRE_USE_GCC)

// Export
#define CORE_TOOLS_EXPORT(implClassName, type) \
    EXPORT_##type(CoreTools, implClassName, CORE_TOOLS_DEFAULT_DECLARE)

#define NETWORK_EXPORT(implClassName, type) \
    EXPORT_##type(Network, implClassName, NETWORK_DEFAULT_DECLARE)

#define DATABASE_EXPORT(implClassName, type) \
    EXPORT_##type(Database, implClassName, DATABASE_DEFAULT_DECLARE)

#define SCRIPT_EXPORT(implClassName, type) \
    EXPORT_##type(Script, implClassName, SCRIPT_DEFAULT_DECLARE)

#define MATHEMATICS_EXPORT(implClassName, type) \
    EXPORT_##type(Mathematics, implClassName, MATHEMATICS_DEFAULT_DECLARE)

#define SOUND_EFFECT_EXPORT(implClassName, type) \
    EXPORT_##type(SoundEffect, implClassName, SOUND_EFFECT_DEFAULT_DECLARE)

#define INPUT_OUTPUT_EXPORT(implClassName, type) \
    EXPORT_##type(InputOutput, implClassName, INPUT_OUTPUT_DEFAULT_DECLARE)

#define RESOURCE_MANAGER_EXPORT(implClassName, type) \
    EXPORT_##type(ResourceManager, implClassName, RESOURCE_MANAGER_DEFAULT_DECLARE)

#define RENDERING_EXPORT(implClassName, type) \
    EXPORT_##type(Rendering, implClassName, RENDERING_DEFAULT_DECLARE)

#define PHYSICS_EXPORT(implClassName, type) \
    EXPORT_##type(Physics, implClassName, PHYSICS_DEFAULT_DECLARE)

#define IMAGICS_EXPORT(implClassName, type) \
    EXPORT_##type(Imagics, implClassName, IMAGICS_DEFAULT_DECLARE)

#define ANIMATION_EXPORT(implClassName, type) \
    EXPORT_##type(Animation, implClassName, ANIMATION_DEFAULT_DECLARE)

#define ARTIFICIAL_INTELLIGENCE_EXPORT(implClassName, type) \
    EXPORT_##type(ArtificialIntelligence, implClassName, ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE)

#define USER_INTERFACE_EXPORT(implClassName, type) \
    EXPORT_##type(UserInterface, implClassName, USER_INTERFACE_DEFAULT_DECLARE)

#define ASSIST_TOOLS_EXPORT(implClassName, type) \
    EXPORT_##type(AssistTools, implClassName, ASSIST_TOOLS_DEFAULT_DECLARE)

#define FRAMEWORK_EXPORT(implClassName, type) \
    EXPORT_##type(Framework, implClassName, FRAMEWORK_DEFAULT_DECLARE)

// Copy Export
#define CORE_TOOLS_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(CoreTools, className, implClassName, CORE_TOOLS_DEFAULT_DECLARE)

#define NETWORK_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Network, className, implClassName, NETWORK_DEFAULT_DECLARE)

#define DATABASE_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Database, className, implClassName, DATABASE_DEFAULT_DECLARE)

#define SCRIPT_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Script, className, implClassName, SCRIPT_DEFAULT_DECLARE)

#define MATHEMATICS_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Mathematics, className, implClassName, MATHEMATICS_DEFAULT_DECLARE)

#define SOUND_EFFECT_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(SoundEffect, className, implClassName, SOUND_EFFECT_DEFAULT_DECLARE)

#define INPUT_OUTPUT_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(InputOutput, className, implClassName, INPUT_OUTPUT_DEFAULT_DECLARE)

#define RESOURCE_MANAGER_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(ResourceManager, className, implClassName, RESOURCE_MANAGER_DEFAULT_DECLARE)

#define RENDERING_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Rendering, className, implClassName, RENDERING_DEFAULT_DECLARE)

#define PHYSICS_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Physics, className, implClassName, PHYSICS_DEFAULT_DECLARE)

#define IMAGICS_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Imagics, className, implClassName, IMAGICS_DEFAULT_DECLARE)

#define ANIMATION_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Animation, className, implClassName, ANIMATION_DEFAULT_DECLARE)

#define ARTIFICIAL_INTELLIGENCE_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(ArtificialIntelligence, className, implClassName, ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE)

#define USER_INTERFACE_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(UserInterface, className, implClassName, USER_INTERFACE_DEFAULT_DECLARE)

#define ASSIST_TOOLS_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(AssistTools, className, implClassName, ASSIST_TOOLS_DEFAULT_DECLARE)

#define FRAMEWORK_COPY_EXPORT(className, implClassName, type) \
    EXPORT_##type(Framework, className, implClassName, FRAMEWORK_DEFAULT_DECLARE)

// Export Unique
#define CORE_TOOLS_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(CoreTools, implClassName, CORE_TOOLS_DEFAULT_DECLARE)

#define NETWORK_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Network, implClassName, NETWORK_DEFAULT_DECLARE)

#define DATABASE_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Database, implClassName, DATABASE_DEFAULT_DECLARE)

#define SCRIPT_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Script, implClassName, SCRIPT_DEFAULT_DECLARE)

#define MATHEMATICS_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Mathematics, implClassName, MATHEMATICS_DEFAULT_DECLARE)

#define SOUND_EFFECT_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(SoundEffect, implClassName, SOUND_EFFECT_DEFAULT_DECLARE)

#define INPUT_OUTPUT_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(InputOutput, implClassName, INPUT_OUTPUT_DEFAULT_DECLARE)

#define RESOURCE_MANAGER_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(ResourceManager, implClassName, RESOURCE_MANAGER_DEFAULT_DECLARE)

#define RENDERING_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Rendering, implClassName, RENDERING_DEFAULT_DECLARE)

#define PHYSICS_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Physics, implClassName, PHYSICS_DEFAULT_DECLARE)

#define IMAGICS_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Imagics, implClassName, IMAGICS_DEFAULT_DECLARE)

#define ANIMATION_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Animation, implClassName, ANIMATION_DEFAULT_DECLARE)

#define ARTIFICIAL_INTELLIGENCE_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(ArtificialIntelligence, implClassName, ARTIFICIAL_INTELLIGENCE_DEFAULT_DECLARE)

#define USER_INTERFACE_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(UserInterface, implClassName, USER_INTERFACE_DEFAULT_DECLARE)

#define ASSIST_TOOLS_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(AssistTools, implClassName, ASSIST_TOOLS_DEFAULT_DECLARE)

#define FRAMEWORK_EXPORT_UNIQUE_PTR(implClassName) \
    EXPORT_UNIQUE_PTR(Framework, implClassName, FRAMEWORK_DEFAULT_DECLARE)

// Export Impl
#define EXPORT_IMPL(implClassName, namespaceName, classShareType) \
    namespaceName##_EXPORT(implClassName, SHARED_PTR);            \
    namespaceName##_EXPORT(implClassName, classShareType)

#define EXPORT_COPY_IMPL(className, implClassName, namespaceName, classShareType) \
    namespaceName##_EXPORT(implClassName, SHARED_PTR);                            \
    namespaceName##_COPY_EXPORT(className, implClassName, classShareType)

#define EXPORT_CONST_IMPL(implClassName, namespaceName, classShareType) \
    namespaceName##_EXPORT(implClassName, CONST_SHARED_PTR);            \
    namespaceName##_EXPORT(implClassName, classShareType)

// Type Declare
#define TYPE_DECLARE(className)  \
    using ClassType = className; \
    using ImplType = SYSTEM_CONCATENATOR(className, Impl)

// Clone
#define COPY_UNSHARED_CLONE_SELF_DECLARE \
    NODISCARD static SharedPtr Clone(const ImplType& impl)

#define COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(namespaceName, className)                   \
    namespaceName::className::SharedPtr namespaceName::className::Clone(const ImplType& impl) \
    {                                                                                         \
        return impl.Clone();                                                                  \
    }

#define COPY_UNSHARED_CLONE_SELF_DEFINE(namespaceName, className)                             \
    namespaceName::className::SharedPtr namespaceName::className::Clone(const ImplType& impl) \
    {                                                                                         \
        return std::make_shared<ImplType>(impl);                                              \
    }

#endif  // CORE_TOOLS_HELPER_EXPORT_MACRO_H
