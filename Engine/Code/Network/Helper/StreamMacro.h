//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 18:39)

#ifndef NETWORK_NETWORK_HELPER_NETWORK_STREAM_MACRO_H
#define NETWORK_NETWORK_HELPER_NETWORK_STREAM_MACRO_H

#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

#define NETWORK_ABSTRACT_FACTORY_DEFINE(namespaceName, className)                                                         \
    Network::MessageInterfaceSharedPtr namespaceName::className::Factory(const Network::MessageSourceSharedPtr&, int64_t) \
    {                                                                                                                     \
        ASSERTION_0(false, "������û�й�����\n");                                                                         \
        return Network::MessageInterfaceSharedPtr{};                                                                      \
    }

#define NETWORK_FACTORY_DEFINE(namespaceName, className)                                                                                   \
    Network::MessageInterfaceSharedPtr namespaceName::className::Factory(const Network::MessageSourceSharedPtr& source, int64_t messageID) \
    {                                                                                                                                      \
        Network::MessageInterfaceSharedPtr object{ std::make_shared<className>(LoadConstructor::ConstructorLoader, messageID) };           \
        object->Load(source);                                                                                                              \
        return object;                                                                                                                     \
    }

#define NETWORK_BEGIN_STREAM_LOAD(source) \
    const auto beginLoad = source->GetBytesRead()
#define NETWORK_END_STREAM_LOAD(source)                                                                 \
    const auto endLoad = source->GetBytesRead();                                                        \
    const auto usedLoad = endLoad - beginLoad + CoreTools::GetStreamSize<int32_t>();                    \
    const auto usedReported = ClassType::GetStreamingSize();                                            \
    if (usedReported < usedLoad)                                                                        \
    {                                                                                                   \
        CoreTools::Error::Format format{ SYSTEM_TEXT("��ȡ��ƥ����ֽ�������ȡ = %1%������ = %2%\n") }; \
        format % usedLoad % usedReported;                                                               \
        THROW_EXCEPTION(format.str());                                                                  \
    }
#define NETWORK_BEGIN_STREAM_SAVE(target) \
    const auto beginSave = target->GetBytesWritten()
#define NETWORK_END_STREAM_SAVE(target)                                                                 \
    const auto endSave = target->GetBytesWritten();                                                     \
    const auto usedSave = endSave - beginSave;                                                          \
    const auto usedReported = ClassType::GetStreamingSize();                                            \
    if (usedReported < usedSave)                                                                        \
    {                                                                                                   \
        CoreTools::Error::Format format{ SYSTEM_TEXT("���治ƥ����ֽ��������� = %1%������ = %2%\n") }; \
        format % usedSave % usedReported;                                                               \
        THROW_EXCEPTION(format.str());                                                                  \
    }

#define NETWORK_STREAM_DECLARE(className)                                                                                \
public:                                                                                                                  \
    static Network::MessageInterfaceSharedPtr Factory(const Network::MessageSourceSharedPtr& source, int64_t messageID); \
    void Load(const Network::MessageSourceSharedPtr& source) override;                                                   \
    void Save(const Network::MessageTargetSharedPtr& target) const override;                                             \
    int GetStreamingSize() const override;                                                                               \
                                                                                                                         \
public:                                                                                                                  \
    className(LoadConstructor value, int64_t messageID) noexcept

#define NETWORK_DEFAULT_STREAM_DEFINE(namespaceName, className)                              \
    namespaceName::className::className(LoadConstructor value, int64_t messageID) noexcept   \
        : ParentType{ value, messageID }                                                     \
    {                                                                                        \
        SELF_CLASS_IS_VALID_0;                                                               \
    }                                                                                        \
    void namespaceName::className::Load(const Network::MessageSourceSharedPtr& source)       \
    {                                                                                        \
        CLASS_IS_VALID_0;                                                                    \
        NETWORK_BEGIN_STREAM_LOAD(source);                                                   \
        ParentType::Load(source);                                                            \
        NETWORK_END_STREAM_LOAD(source);                                                     \
    }                                                                                        \
    void namespaceName::className::Save(const Network::MessageTargetSharedPtr& target) const \
    {                                                                                        \
        CLASS_IS_VALID_CONST_0;                                                              \
        NETWORK_BEGIN_STREAM_SAVE(target);                                                   \
        ParentType::Save(target);                                                            \
        NETWORK_END_STREAM_SAVE(target);                                                     \
    }                                                                                        \
    int namespaceName::className::GetStreamingSize() const                                   \
    {                                                                                        \
        CLASS_IS_VALID_CONST_0;                                                              \
        return ParentType::GetStreamingSize();                                               \
    }

#endif  // NETWORK_NETWORK_HELPER_NETWORK_STREAM_MACRO_H
