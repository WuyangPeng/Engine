///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:37)

#ifndef CORE_TOOLS_FILE_MANAGER_OF_STREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_OF_STREAM_SEEK_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OFStreamSeekManager final
    {
    public:
        using ClassType = OFStreamSeekManager;

        using MasterType = System::OFileStream;
        using MasterTypeReference = System::OFileStream&;

    public:
        explicit OFStreamSeekManager(MasterTypeReference master);
        ~OFStreamSeekManager() noexcept;

        OFStreamSeekManager(const OFStreamSeekManager& rhs) = delete;
        OFStreamSeekManager operator=(const OFStreamSeekManager& rhs) = delete;
        OFStreamSeekManager(OFStreamSeekManager&& rhs) noexcept = delete;
        OFStreamSeekManager operator=(OFStreamSeekManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        using MasterPosType = MasterType::pos_type;

    private:
        NODISCARD static MasterPosType GetErrorPosition();

        void ResetPosition() noexcept;
        void SeekBeginPosition();

    private:
        MasterTypeReference master;
        MasterPosType currentPosition;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_OF_STREAM_SEEK_MANAGER_H
