///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/29 16:23)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"

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
