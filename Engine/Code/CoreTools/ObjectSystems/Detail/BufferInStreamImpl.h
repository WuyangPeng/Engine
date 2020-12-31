//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/21 10:16)

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
    class CORE_TOOLS_HIDDEN_DECLARE BufferInStreamImpl final : private boost::noncopyable
    {
    public:
        using ClassType = BufferInStreamImpl;

    public:
        explicit BufferInStreamImpl(const ConstFileBufferSharedPtr& fileBuffer, int startPoint = 0);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const InTopLevel GetTopLevel() const noexcept;

    private:
        void AnalysisBuffer();
        void IncrementBytesProcessed() noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
        void ReadObject();
        void CreateObject(bool isTopLevel, const std::string& name);
        void DoCreateObject(bool isTopLevel, const std::string& name);
        void Link();
        void PostLink();

    private:
        int m_StartPoint;
        InTopLevel m_TopLevel;
        BufferSourceSharedPtr m_Source;
        ObjectLinkSharedPtr m_ObjectLink;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H
