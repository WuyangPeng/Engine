///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/05 21:59)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER1_TERM4_DERIVE_H
#define EFFECTIVE_MODERN_CPP_CHAPTER1_TERM4_DERIVE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "System/Helper/PragmaWarning/TypeIndex.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Example/BookCpp/EffectiveModernCpp/Chapter1/Terms3Derive.h"

#include <iostream>
#include <string>
#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter1
        {
            namespace Terms4
            {
                class Widget
                {
                };

                template <typename T>
                class TD;  // 只声明TD而不定义，TD是“型别显示类”的缩写

                template <typename T>
                void F(const T& param);  // F 是打算调用的函数模板

                std::vector<Widget> CreateVec();  // 工厂函数

                template <typename T>
                void F(const T& param)
                {
                    using std::cout;

                    cout << "T =     " << typeid(T).name() << '\n';  // 显示T
                    cout << "param = " << typeid(param).name() << '\n';  // 显示param的型别
                }

                template <typename T>
                void F13(const T& param)
                {
                    using boost::typeindex::type_id_with_cvr;
                    using std::cout;

                    // 显示T的型别
                    cout << "T =     "
                         << type_id_with_cvr<T>().pretty_name()
                         << '\n';

                    // 显示param的型别
                    cout << "param = "
                         << type_id_with_cvr<decltype(param)>().pretty_name()
                         << '\n';
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM4_DERIVE_H
