/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 10:55)

#ifndef CORE_TOOLS_HELPER_STREAM_MACRO_H
#define CORE_TOOLS_HELPER_STREAM_MACRO_H

#include "ExceptionMacro.h"
#include "InitializeTerminatorMacro.h"
#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"

#if defined(CORE_TOOLS_USE_ASSERT) && 2 <= ASSERT_LEVEL

    #define CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source) \
        const auto beginLoad = source.GetBytesRead()

    #define CORE_TOOLS_END_DEBUG_STREAM_LOAD(source)                                                   \
        const auto endLoad = source.GetBytesRead();                                                    \
        const auto usedLoad = endLoad - beginLoad + CoreTools::GetStreamSize(GetRttiType().GetName()); \
        const auto usedReported = ClassType::GetStreamingSize();                                       \
        CORE_TOOLS_ASSERTION_0(usedLoad == usedReported, "读取不匹配的字节数：读取 = %d，所需 = %d\n", usedLoad, usedReported)

    #define CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target) \
        const auto beginSave = target.GetBytesWritten()

    #define CORE_TOOLS_END_DEBUG_STREAM_SAVE(target)             \
        const auto endSave = target.GetBytesWritten();           \
        const auto usedSave = endSave - beginSave;               \
        const auto usedReported = ClassType::GetStreamingSize(); \
        CORE_TOOLS_ASSERTION_0(usedSave == usedReported, "保存不匹配的字节数：保存 = %d，所需 = %d\n", usedSave, usedReported)

#else  // !defined(CORE_TOOLS_USE_ASSERT) || USER_ASSERT_LEVEL < 2

    #define CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source) static_cast<void>(0)
    #define CORE_TOOLS_END_DEBUG_STREAM_LOAD(source) static_cast<void>(0)
    #define CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target) static_cast<void>(0)
    #define CORE_TOOLS_END_DEBUG_STREAM_SAVE(target) static_cast<void>(0)

#endif  // defined(CORE_TOOLS_USE_ASSERT) && 2 <= USER_ASSERT_LEVEL

#define CORE_TOOLS_OBJECT_FACTORY_DECLARE(className)     \
public:                                                  \
    explicit className(LoadConstructor loadConstructor); \
                                                         \
public:                                                  \
    CORE_TOOLS_INITIALIZE_TERMINATE_DECLARE(false);      \
    NODISCARD static CoreTools::ObjectInterfaceSharedPtr Factory(CoreTools::BufferSource& source)

#define CORE_TOOLS_OBJECT_STREAM_OVERRIDE_DECLARE                                 \
    void Load(CoreTools::BufferSource& source) override;                          \
    void Link(CoreTools::ObjectLink& source) override;                            \
    void PostLink() override;                                                     \
    NODISCARD int64_t Register(CoreTools::ObjectRegister& target) const override; \
    void Save(CoreTools::BufferTarget& target) const override;                    \
    NODISCARD int GetStreamingSize() const override;

#define CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(className) \
    CORE_TOOLS_OBJECT_FACTORY_DECLARE(className);                    \
    CORE_TOOLS_OBJECT_STREAM_OVERRIDE_DECLARE;                       \
    CORE_TOOLS_RTTI_OVERRIDE_DECLARE

#define CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(namespaceName, className)                                \
    CoreTools::ObjectInterfaceSharedPtr namespaceName::className::Factory(CoreTools::BufferSource&) \
    {                                                                                               \
        THROW_EXCEPTION(SYSTEM_TEXT("抽象类没有工厂！\n"s))                                         \
    }

#define CORE_TOOLS_FACTORY_DEFINE(namespaceName, className)                                                \
    CoreTools::ObjectInterfaceSharedPtr namespaceName::className::Factory(CoreTools::BufferSource& source) \
    {                                                                                                      \
        auto object = std::make_shared<className>(LoadConstructor::ConstructorLoader);                     \
        object->Load(source);                                                                              \
        return object;                                                                                     \
    }

#define CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(namespaceName, className)         \
    CORE_TOOLS_INITIALIZE_TERMINATE_DEFINE(namespaceName, className)              \
    void namespaceName::className::InitializeFactory()                            \
    {                                                                             \
        OBJECT_MANAGER_SINGLETON.Insert(GetCurrentRttiType().GetName(), Factory); \
    }                                                                             \
    void namespaceName::className::TerminateFactory()                             \
    {                                                                             \
        OBJECT_MANAGER_SINGLETON.Remove(GetCurrentRttiType().GetName());          \
    }

#define CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName, className) \
    namespaceName::className::className(LoadConstructor loadConstructor)            \
        : ParentType{ loadConstructor }                                             \
    {                                                                               \
        CORE_TOOLS_SELF_CLASS_IS_VALID_1;                                           \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName, className)                 \
    namespaceName::className::className(LoadConstructor loadConstructor)                              \
        : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default } \
    {                                                                                                 \
        CORE_TOOLS_SELF_CLASS_IS_VALID_1;                                                             \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(namespaceName, className) \
    int namespaceName::className::GetStreamingSize() const                              \
    {                                                                                   \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                              \
        auto size = ParentType::GetStreamingSize();                                     \
        size += impl->GetStreamingSize();                                               \
        return size;                                                                    \
    }

#define CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(namespaceName, className)             \
    int64_t namespaceName::className::Register(CoreTools::ObjectRegister& target) const \
    {                                                                                   \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                              \
        return ParentType::Register(target);                                            \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_REGISTER_DEFINE(namespaceName, className)           \
    int64_t namespaceName::className::Register(CoreTools::ObjectRegister& target) const \
    {                                                                                   \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                              \
        const auto registerId = ParentType::Register(target);                           \
        if (registerId != 0)                                                            \
        {                                                                               \
            impl->Register(target);                                                     \
        }                                                                               \
        return registerId;                                                              \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(namespaceName, className)      \
    void namespaceName::className::Save(CoreTools::BufferTarget& target) const \
    {                                                                          \
        CORE_TOOLS_CLASS_IS_VALID_CONST_1;                                     \
        CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);                            \
        ParentType::Save(target);                                              \
        impl->Save(target);                                                    \
        CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);                              \
    }

#define CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(namespaceName, className) \
    void namespaceName::className::Link(CoreTools::ObjectLink& source)  \
    {                                                                   \
        CORE_TOOLS_CLASS_IS_VALID_1;                                    \
        ParentType::Link(source);                                       \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_LINK_DEFINE(namespaceName, className) \
    void namespaceName::className::Link(CoreTools::ObjectLink& source)    \
    {                                                                     \
        CORE_TOOLS_CLASS_IS_VALID_1;                                      \
        ParentType::Link(source);                                         \
        impl->Link(source);                                               \
    }

#define CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(namespaceName, className) \
    void namespaceName::className::PostLink()                                \
    {                                                                        \
        CORE_TOOLS_CLASS_IS_VALID_1;                                         \
        ParentType::PostLink();                                              \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(namespaceName, className) \
    void namespaceName::className::Load(CoreTools::BufferSource& source)  \
    {                                                                     \
        CORE_TOOLS_CLASS_IS_VALID_1;                                      \
        CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);                       \
        ParentType::Load(source);                                         \
        impl->Load(source);                                               \
        CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);                         \
    }

#define CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(namespaceName, className)     \
    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName, className)   \
    CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(namespaceName, className) \
    CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(namespaceName, className)             \
    CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(namespaceName, className)               \
    CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(namespaceName, className)                 \
    CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(namespaceName, className)            \
    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(namespaceName, className)

#define CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(namespaceName, className)         \
    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName, className)   \
    CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(namespaceName, className) \
    CORE_TOOLS_WITH_IMPL_OBJECT_REGISTER_DEFINE(namespaceName, className)           \
    CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(namespaceName, className)               \
    CORE_TOOLS_WITH_IMPL_OBJECT_LINK_DEFINE(namespaceName, className)               \
    CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(namespaceName, className)            \
    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(namespaceName, className)

#endif  // CORE_TOOLS_HELPER_STREAM_MACRO_H
