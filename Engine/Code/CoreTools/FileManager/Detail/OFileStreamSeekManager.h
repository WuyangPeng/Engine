/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:47)

#ifndef CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_SEEK_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OFileStreamSeekManager final
    {
    public:
        using ClassType = OFileStreamSeekManager;

        using MasterType = System::OFileStream;
        using MasterTypeReference = System::OFileStream&;

    public:
        explicit OFileStreamSeekManager(MasterTypeReference master);
        ~OFileStreamSeekManager() noexcept;

        OFileStreamSeekManager(const OFileStreamSeekManager& rhs) = delete;
        OFileStreamSeekManager operator=(const OFileStreamSeekManager& rhs) = delete;
        OFileStreamSeekManager(OFileStreamSeekManager&& rhs) noexcept = delete;
        OFileStreamSeekManager operator=(OFileStreamSeekManager&& rhs) noexcept = delete;

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

#endif  // CORE_TOOLS_FILE_MANAGER_O_FILE_STREAM_SEEK_MANAGER_H
