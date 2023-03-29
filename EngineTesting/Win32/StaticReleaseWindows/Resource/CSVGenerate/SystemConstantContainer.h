/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_SYSTEM_CONSTANT_CONTAINER_H
#define C_S_V_CONFIGURE_SYSTEM_CONSTANT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace CSVConfigure
{
    class SystemConstantContainer final
    {
    public:
        using ClassType = SystemConstantContainer;
        using ConstSystemConstantSharedPtr = std::shared_ptr<const SystemConstant>;

    public:
        explicit SystemConstantContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSystemConstantSharedPtr GetSystemConstant() const noexcept;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        ConstSystemConstantSharedPtr systemConstant;
    };
}

#endif  // C_S_V_CONFIGURE_SYSTEM_CONSTANT_CONTAINER_H
