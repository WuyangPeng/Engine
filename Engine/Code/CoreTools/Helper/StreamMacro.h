//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/09 10:57)

#ifndef CORE_TOOLS_HELPER_STREAM_MACRO_H
#define CORE_TOOLS_HELPER_STREAM_MACRO_H

#include "ExceptionMacro.h"
#include "MemberFunctionMacro.h"
#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

// CORE_TOOLS_STREAM_SIZE宏被流系统使用。
#define CORE_TOOLS_STREAM_SIZE(value) CoreTools::GetStreamSize(value)

#if defined(CORE_TOOLS_USE_ASSERT) && 2 <= ASSERT_LEVEL

    #define CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source) \
        const auto beginLoad = source->GetBytesRead()

    #define CORE_TOOLS_END_DEBUG_STREAM_LOAD(source)                                                 \
        const auto endLoad = source->GetBytesRead();                                                 \
        const auto usedLoad = endLoad - beginLoad + CORE_TOOLS_STREAM_SIZE(GetRttiType().GetName()); \
        const auto usedReported = ClassType::GetStreamingSize();                                     \
        ASSERTION_2(usedLoad == usedReported, "读取不匹配的字节数：读取 = %d，所需 = %d\n", usedLoad, usedReported)

    #define CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target) \
        const auto beginSave = target->GetBytesWritten()

    #define CORE_TOOLS_END_DEBUG_STREAM_SAVE(target)             \
        const auto endSave = target->GetBytesWritten();          \
        const auto usedSave = endSave - beginSave;               \
        const auto usedReported = ClassType::GetStreamingSize(); \
        ASSERTION_2(usedSave == usedReported, "保存不匹配的字节数：保存 = %d，所需 = %d\n", usedSave, usedReported)

#else  // !defined(CORE_TOOLS_USE_ASSERT) || USER_ASSERT_LEVEL < 2

    #define CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source)
    #define CORE_TOOLS_END_DEBUG_STREAM_LOAD(source)
    #define CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target)
    #define CORE_TOOLS_END_DEBUG_STREAM_SAVE(target)

#endif  // defined(CORE_TOOLS_USE_ASSERT) && 2 <= USER_ASSERT_LEVEL

#define CORE_TOOLS_OBJECT_FACTORY_DECLARE(className) \
public:                                              \
    explicit className(LoadConstructor value);       \
                                                     \
public:                                              \
    [[nodiscard]] static bool RegisterFactory();     \
    static void InitializeFactory();                 \
    static void TerminateFactory();                  \
    [[nodiscard]] static CoreTools::ObjectInterfaceSharedPtr Factory(const CoreTools::BufferSourceSharedPtr& source)

#define CORE_TOOLS_OBJECT_STREAM_OVERRIDE_DECLARE                                                     \
    void Load(const CoreTools::BufferSourceSharedPtr& source) override;                               \
    void Link(const CoreTools::ObjectLinkSharedPtr& source) override;                                 \
    void PostLink() override;                                                                         \
    [[nodiscard]] uint64_t Register(const CoreTools::ObjectRegisterSharedPtr& target) const override; \
    void Save(const CoreTools::BufferTargetSharedPtr& target) const override;                         \
    [[nodiscard]] int GetStreamingSize() const override;

#define CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(className) \
    CORE_TOOLS_OBJECT_FACTORY_DECLARE(className);                    \
    CORE_TOOLS_OBJECT_STREAM_OVERRIDE_DECLARE;                       \
    CORE_TOOLS_RTTI_OVERRIDE_DECLARE

#define CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(namespaceName, className)                                               \
    CoreTools::ObjectInterfaceSharedPtr namespaceName::className::Factory(const CoreTools::BufferSourceSharedPtr&) \
    {                                                                                                              \
        THROW_EXCEPTION(SYSTEM_TEXT("抽象类没有工厂！\n"s));                                                       \
    }

#define CORE_TOOLS_FACTORY_DEFINE(namespaceName, className)                                                               \
    CoreTools::ObjectInterfaceSharedPtr namespaceName::className::Factory(const CoreTools::BufferSourceSharedPtr& source) \
    {                                                                                                                     \
        CoreTools::ObjectInterfaceSharedPtr object{ std::make_shared<className>(LoadConstructor::ConstructorLoader) };    \
        object->Load(source);                                                                                             \
        return object;                                                                                                    \
    }

#define CORE_TOOLS_STREAM_REGISTER(className) \
    static auto SYSTEM_MULTIPLE_CONCATENATOR(g_, className, StreamRegistered) = className::RegisterFactory()

#define CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(namespaceName, className)                                                       \
    bool namespaceName::className::RegisterFactory()                                                                            \
    {                                                                                                                           \
        static CoreTools::InitTermRegisterFactory registerFactory{ ClassType::InitializeFactory, ClassType::TerminateFactory }; \
        return true;                                                                                                            \
    }                                                                                                                           \
    void namespaceName::className::InitializeFactory()                                                                          \
    {                                                                                                                           \
        OBJECT_MANAGER_SINGLETON.Insert(GetCurrentRttiType().GetName(), Factory);                                                      \
    }                                                                                                                           \
    void namespaceName::className::TerminateFactory()                                                                           \
    {                                                                                                                           \
        OBJECT_MANAGER_SINGLETON.Remove(GetCurrentRttiType().GetName());                                                               \
    }

#define CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName, className) \
    namespaceName::className::className(LoadConstructor value)                      \
        : ParentType{ value }                                                       \
    {                                                                               \
        SELF_CLASS_IS_VALID_0;                                                      \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName, className) \
    namespaceName::className::className(LoadConstructor value)                        \
        : ParentType{ value }, m_Impl{ std::make_shared<ImplType>() }                 \
    {                                                                                 \
        SELF_CLASS_IS_VALID_0;                                                        \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(namespaceName, className) \
    int namespaceName::className::GetStreamingSize() const                              \
    {                                                                                   \
        CLASS_IS_VALID_CONST_0;                                                         \
        auto size = ParentType::GetStreamingSize();                                     \
        size += m_Impl->GetStreamingSize();                                             \
        return size;                                                                    \
    }

#define CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(namespaceName, className)                             \
    uint64_t namespaceName::className::Register(const CoreTools::ObjectRegisterSharedPtr& target) const \
    {                                                                                                   \
        CLASS_IS_VALID_CONST_0;                                                                         \
        return ParentType::Register(target);                                                            \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_REGISTER_DEFINE(namespaceName, className)                           \
    uint64_t namespaceName::className::Register(const CoreTools::ObjectRegisterSharedPtr& target) const \
    {                                                                                                   \
        CLASS_IS_VALID_CONST_0;                                                                         \
        const auto uniqueID = ParentType::Register(target);                                             \
        if (uniqueID != 0)                                                                              \
        {                                                                                               \
            m_Impl->Register(target);                                                                   \
        }                                                                                               \
        return uniqueID;                                                                                \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(namespaceName, className)                     \
    void namespaceName::className::Save(const CoreTools::BufferTargetSharedPtr& target) const \
    {                                                                                         \
        CLASS_IS_VALID_CONST_0;                                                               \
        CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);                                           \
        ParentType::Save(target);                                                             \
        m_Impl->Save(target);                                                                 \
        CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);                                             \
    }

#define CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(namespaceName, className)               \
    void namespaceName::className::Link(const CoreTools::ObjectLinkSharedPtr& source) \
    {                                                                                 \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                 \
        ParentType::Link(source);                                                     \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_LINK_DEFINE(namespaceName, className)             \
    void namespaceName::className::Link(const CoreTools::ObjectLinkSharedPtr& source) \
    {                                                                                 \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                 \
        ParentType::Link(source);                                                     \
        m_Impl->Link(source);                                                         \
    }

#define CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(namespaceName, className) \
    void namespaceName::className::PostLink()                                \
    {                                                                        \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                        \
        ParentType::PostLink();                                              \
    }

#define CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(namespaceName, className)               \
    void namespaceName::className::Load(const CoreTools::BufferSourceSharedPtr& source) \
    {                                                                                   \
        IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;                                   \
        CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);                                     \
        ParentType::Load(source);                                                       \
        m_Impl->Load(source);                                                           \
        CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);                                       \
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
