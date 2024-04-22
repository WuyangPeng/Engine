/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:08)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BufferInStreamImpl final
    {
    public:
        using ClassType = BufferInStreamImpl;

    public:
        explicit BufferInStreamImpl(const ConstFileBufferSharedPtr& fileBuffer, int startPoint = 0);

        ~BufferInStreamImpl() noexcept = default;
        BufferInStreamImpl(const BufferInStreamImpl& rhs) = delete;
        BufferInStreamImpl& operator=(const BufferInStreamImpl& rhs) = delete;
        BufferInStreamImpl(BufferInStreamImpl&& rhs) noexcept = delete;
        BufferInStreamImpl& operator=(BufferInStreamImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD InTopLevel GetTopLevel() const noexcept;

    private:
        void AnalysisBuffer();
        void IncrementBytesProcessed();
        void ReadObject();
        void CreateObject(bool isTopLevel, const std::string& name);
        void DoCreateObject(bool isTopLevel, const std::string& name);
        void Link();
        void PostLink();

    private:
        int startPoint;
        InTopLevel topLevel;
        BufferSourceSharedPtr source;
        ObjectLinkSharedPtr objectLink;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H
