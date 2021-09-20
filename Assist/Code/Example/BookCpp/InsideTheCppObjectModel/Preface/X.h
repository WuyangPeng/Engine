///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/12 21:17)

#ifndef INSIDE_THE_CPP_OBJECT_MODEL_PREFACE_X_H
#define INSIDE_THE_CPP_OBJECT_MODEL_PREFACE_X_H

#include "Example/BookCpp/InsideTheCppObjectModel/InsideTheCppObjectModelDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <iosfwd>

namespace BookAdvanced
{
    namespace InsideTheCppObjectModel
    {
        class INSIDE_THE_CPP_OBJECT_MODEL_DEFAULT_DECLARE X final
        {
        public:
            using ClassType = X;

        public:
            explicit X(int sz = 1024);
            ~X() noexcept;
            X(const X& rhs) = delete;
            X& operator=(const X& rhs) = delete;
            X(X&& rhs) = delete;
            X& operator=(X&& rhs) = delete;

            CLASS_INVARIANT_DECLARE;

        private:
            friend std::istream& operator>>(std::istream&, X&);

            char* ptr;
        };

        std::istream& operator>>(std::istream& is, X& rhs);
    }
}

#endif  // INSIDE_THE_CPP_OBJECT_MODEL_PREFACE_X_H
