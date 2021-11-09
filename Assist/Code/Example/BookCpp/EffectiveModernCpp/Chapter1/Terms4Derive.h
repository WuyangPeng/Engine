///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/05 21:59)

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
                class TD;  // ֻ����TD�������壬TD�ǡ��ͱ���ʾ�ࡱ����д

                template <typename T>
                void F(const T& param);  // F �Ǵ�����õĺ���ģ��

                std::vector<Widget> CreateVec();  // ��������

                template <typename T>
                void F(const T& param)
                {
                    using std::cout;

                    cout << "T =     " << typeid(T).name() << '\n';  // ��ʾT
                    cout << "param = " << typeid(param).name() << '\n';  // ��ʾparam���ͱ�
                }

                template <typename T>
                void F13(const T& param)
                {
                    using boost::typeindex::type_id_with_cvr;
                    using std::cout;

                    // ��ʾT���ͱ�
                    cout << "T =     "
                         << type_id_with_cvr<T>().pretty_name()
                         << '\n';

                    // ��ʾparam���ͱ�
                    cout << "param = "
                         << type_id_with_cvr<decltype(param)>().pretty_name()
                         << '\n';
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER1_TERM4_DERIVE_H
