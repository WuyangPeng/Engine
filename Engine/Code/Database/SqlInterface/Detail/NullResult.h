///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 13:57)

#ifndef DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H
#define DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H

#include "Database/DatabaseDll.h"

#include "ResultImpl.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullResult final : public ResultImpl
    {
    public:
        using ClassType = NullResult;
        using ParentType = ResultImpl;

    public:
        explicit NullResult(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_DOC_RESULT_H
