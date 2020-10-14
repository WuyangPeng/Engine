//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:14)

#ifndef CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H

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

        IFStreamSeekManager(const IFStreamSeekManager&) = delete;
        IFStreamSeekManager operator=(const IFStreamSeekManager&) = delete;
        IFStreamSeekManager(IFStreamSeekManager&&) noexcept = delete;
        IFStreamSeekManager operator=(IFStreamSeekManager&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        void SeekBeginPosition();

    private:
        using MasterPosType = MasterType::pos_type;

    private:
        [[nodiscard]] static MasterPosType GetErrorPosition();

    private:
        MasterTypeReference m_Master;
        MasterPosType m_CurrentPosition;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H
