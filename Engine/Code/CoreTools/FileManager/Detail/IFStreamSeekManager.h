///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:37)

#ifndef CORE_TOOLS_FILE_MANAGER_IF_STREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_IF_STREAM_SEEK_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE IFStreamSeekManager final
    {
    public:
        using ClassType = IFStreamSeekManager;

        using MasterType = System::IFileStream;
        using MasterTypeReference = System::IFileStream&;

    public:
        explicit IFStreamSeekManager(MasterTypeReference master);
        ~IFStreamSeekManager() noexcept;

        IFStreamSeekManager(const IFStreamSeekManager& rhs) = delete;
        IFStreamSeekManager operator=(const IFStreamSeekManager& rhs) = delete;
        IFStreamSeekManager(IFStreamSeekManager&& rhs) noexcept = delete;
        IFStreamSeekManager operator=(IFStreamSeekManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        using MasterPosType = MasterType::pos_type;

    private:
        void ResetPosition() noexcept;
        void SeekBeginPosition();

        NODISCARD static MasterPosType GetErrorPosition();

    private:
        MasterTypeReference master;
        MasterPosType currentPosition;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IF_STREAM_SEEK_MANAGER_H
