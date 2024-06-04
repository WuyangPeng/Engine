/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.11 (2024/06/04 20:28)

#ifndef NETWORK_NETWORK_HELPER_NETWORK_STREAM_MACRO_H
#define NETWORK_NETWORK_HELPER_NETWORK_STREAM_MACRO_H

#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

#define NETWORK_ABSTRACT_FACTORY_DEFINE(namespaceName, className)                                                               \
    Network::MessageInterfaceSharedPtr namespaceName::className::Factory(Network::MessageSource&, MessageHeadStrategy, int64_t) \
    {                                                                                                                           \
        ASSERTION_0(false, "抽象类没有工厂！\n");                                                                               \
        return Network::MessageInterfaceSharedPtr{};                                                                            \
    }

#define NETWORK_FACTORY_DEFINE(namespaceName, className)                                                                                                             \
    Network::MessageInterfaceSharedPtr namespaceName::className::Factory(Network::MessageSource& source, MessageHeadStrategy messageHeadStrategy, int64_t messageId) \
    {                                                                                                                                                                \
        auto object = std::make_shared<className>(LoadConstructor::ConstructorLoader, messageHeadStrategy, messageId);                                               \
        object->Load(source);                                                                                                                                        \
        return object;                                                                                                                                               \
    }

#define NETWORK_BEGIN_STREAM_LOAD(source) \
    const auto beginLoad = (source).GetBytesRead()

#define NETWORK_END_STREAM_LOAD(source)                                                                 \
    const auto endLoad = (source).GetBytesRead();                                                       \
    const auto usedLoad = endLoad - beginLoad + GetBaseStreamingSize();                                 \
    const auto usedReported = ClassType::GetStreamingSize();                                            \
    if (usedReported < usedLoad)                                                                        \
    {                                                                                                   \
        CoreTools::Error::Format format{ SYSTEM_TEXT("读取不匹配的字节数：读取 = %1%，所需 = %2%\n") }; \
        format % usedLoad % usedReported;                                                               \
        THROW_EXCEPTION(format.str());                                                                  \
    }

#define NETWORK_BEGIN_STREAM_SAVE(target) \
    const auto beginSave = (target).GetBytesWritten()

#define NETWORK_END_STREAM_SAVE(target)                                                                 \
    const auto endSave = (target).GetBytesWritten();                                                    \
    const auto usedSave = endSave - beginSave;                                                          \
    const auto usedReported = ClassType::GetStreamingSize();                                            \
    if (usedReported < usedSave)                                                                        \
    {                                                                                                   \
        CoreTools::Error::Format format{ SYSTEM_TEXT("保存不匹配的字节数：保存 = %1%，所需 = %2%\n") }; \
        format % usedSave % usedReported;                                                               \
        THROW_EXCEPTION(format.str());                                                                  \
    }

#define NETWORK_STREAM_DECLARE(className)                                                                                                                    \
public:                                                                                                                                                      \
    NODISCARD static Network::MessageInterfaceSharedPtr Factory(Network::MessageSource& source, MessageHeadStrategy messageHeadStrategy, int64_t messageId); \
    void Load(Network::MessageSource& source) override;                                                                                                      \
    void Save(Network::MessageTarget& target) const override;                                                                                                \
    NODISCARD int GetStreamingSize() const override;                                                                                                         \
                                                                                                                                                             \
public:                                                                                                                                                      \
    className(LoadConstructor loadConstructor, MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept

#define NETWORK_DEFAULT_STREAM_DEFINE(namespaceName, className)                                                                               \
    namespaceName::className::className(LoadConstructor loadConstructor, MessageHeadStrategy messageHeadStrategy, int64_t messageId) noexcept \
        : ParentType{ loadConstructor, messageHeadStrategy, messageId }                                                                       \
    {                                                                                                                                         \
        NETWORK_SELF_CLASS_IS_VALID_0;                                                                                                        \
    }                                                                                                                                         \
    void namespaceName::className::Load(Network::MessageSource& source)                                                                       \
    {                                                                                                                                         \
        NETWORK_CLASS_IS_VALID_0;                                                                                                             \
        NETWORK_BEGIN_STREAM_LOAD(source);                                                                                                    \
        ParentType::Load(source);                                                                                                             \
        NETWORK_END_STREAM_LOAD(source);                                                                                                      \
    }                                                                                                                                         \
    void namespaceName::className::Save(Network::MessageTarget& target) const                                                                 \
    {                                                                                                                                         \
        NETWORK_CLASS_IS_VALID_CONST_0;                                                                                                       \
        NETWORK_BEGIN_STREAM_SAVE(target);                                                                                                    \
        ParentType::Save(target);                                                                                                             \
        NETWORK_END_STREAM_SAVE(target);                                                                                                      \
    }                                                                                                                                         \
    int namespaceName::className::GetStreamingSize() const                                                                                    \
    {                                                                                                                                         \
        NETWORK_CLASS_IS_VALID_CONST_0;                                                                                                       \
        return ParentType::GetStreamingSize();                                                                                                \
    }

#endif  // NETWORK_NETWORK_HELPER_NETWORK_STREAM_MACRO_H
