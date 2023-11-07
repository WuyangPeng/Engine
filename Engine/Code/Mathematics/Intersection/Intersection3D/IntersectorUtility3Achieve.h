///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 18:21)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_ACHIEVE_H

#include "IntersectorUtility3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
typename Mathematics::IntersectorUtility3<Real>::Container Mathematics::IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(const Vector3& normal, Real constant, const Container& point)
{
    /// �ٶ����붥��Ϊ��ʱ��˳�� ˳���Ǵ˺����Ĳ���ʽ��

    // �����ߵ���һ���Ƕ���
    auto result = point;
    auto quantity = boost::numeric_cast<int>(result.size());
    auto positive = 0;
    auto negative = 0;
    auto index = -1;

    using DotType = std::array<Real, 8>;

    DotType dotProduct{};

    for (auto i = 0; i < quantity; ++i)
    {
        /// ����ʹ��epsilon����Ϊ����͡����������ܱ˴���ȫ��ȣ������ϣ��������ڸ�����������в�ͬ��
        /// ��ˣ��ڲ������ϼ�һ�㣬�Խ�ʵ������ȵ�������������

        // ������һ����Ե����̶ȡ� ���Գ������ܲ���������һ�����ѷ�����
        dotProduct.at(i) = Vector3Tools<Real>::DotProduct(normal, result.at(i)) - constant + Math<Real>::FAbs(constant) * Math<Real>::GetZeroTolerance();

        if (Math<Real>::GetValue(0) <= dotProduct.at(i))
        {
            ++positive;
            if (index < 0)
            {
                index = i;
            }
        }
        else
        {
            ++negative;
        }
    }

    if (quantity == 2)
    {
        // ����Щ��ͬ�������߶��޷������µ��߶Σ�������ö����һ��
        if (0 < positive)
        {
            if (0 < negative)
            {
                auto clip = 0;

                if (index == 0)
                {
                    // vertex0Ϊ����vertex1���ü�
                    clip = 1;
                }
                else  // pIndex == 1
                {
                    // vertex1Ϊ���� vertex0���ü�
                    clip = 0;
                }

                auto t = dotProduct.at(index) / (dotProduct.at(index) - dotProduct.at(clip));
                auto value = result.at(clip);
                value -= result.at(index);
                result.at(clip) = result.at(index) + t * (value);
            }
            // �������߶������ģ�û�вü�
        }
        else
        {
            // ���ԣ������ж��Ѽ��У������ǲ�Ӧ�õ���˴���
            result.clear();
        }
    }
    else
    {
        if (0 < positive)
        {
            if (0 < negative)
            {
                // ƽ���������ཻ
                Container container{};

                if (0 < index)
                {
                    // ���ߵĵ�һ����������
                    auto curIndex = index;
                    auto prvIndex = curIndex - 1;
                    auto t = dotProduct.at(curIndex) / (dotProduct.at(curIndex) - dotProduct.at(prvIndex));
                    container.emplace_back(result.at(curIndex) + t * (result.at(prvIndex) - result.at(curIndex)));

                    // ������Ķ���
                    while (curIndex < quantity && dotProduct.at(curIndex) >= Math<Real>::GetValue(0))
                    {
                        container.emplace_back(result.at(curIndex++));
                    }

                    // �����ϵ����һ����������
                    if (curIndex < quantity)
                    {
                        prvIndex = curIndex - 1;
                    }
                    else
                    {
                        curIndex = 0;
                        prvIndex = quantity - 1;
                    }
                    t = dotProduct.at(curIndex) / (dotProduct.at(curIndex) - dotProduct.at(prvIndex));
                    container.emplace_back(result.at(curIndex) + t * (result.at(prvIndex) - result.at(curIndex)));
                }
                else  // index is 0
                {
                    // ������Ķ���
                    auto curIndex = 0;
                    while (curIndex < quantity && Math<Real>::GetValue(0) <= dotProduct.at(curIndex))
                    {
                        container.emplace_back(result.at(curIndex++));
                    }

                    // �����ϵ����һ����������
                    auto prvIndex = curIndex - 1;
                    auto t = dotProduct.at(curIndex) / (dotProduct.at(curIndex) - dotProduct.at(prvIndex));
                    container.emplace_back(result.at(curIndex) + t * (result.at(prvIndex) - result.at(curIndex)));

                    // �ڸ�����������
                    while (curIndex < quantity && Math<Real>::GetValue(0) < dotProduct.at(curIndex))
                    {
                        curIndex++;
                    }

                    // ���ߵĵ�һ����������
                    if (curIndex < quantity)
                    {
                        prvIndex = curIndex - 1;
                        t = dotProduct.at(curIndex) / (dotProduct.at(curIndex) - dotProduct.at(prvIndex));
                        container.emplace_back(result.at(curIndex) + t * (result.at(prvIndex) - result.at(curIndex)));

                        // ������Ķ���
                        while (curIndex < quantity && Math<Real>::GetValue(0) <= dotProduct.at(curIndex))
                        {
                            container.emplace_back(result.at(curIndex++));
                        }
                    }
                    else
                    {
                        // curIndex = 0
                        prvIndex = quantity - 1;
                        t = dotProduct.at(0) / (dotProduct.at(0) - dotProduct.at(prvIndex));
                        container.emplace_back(result.at(0) + t * (result.at(prvIndex) - result.at(0)));
                    }
                }
                result = container;
            }
            // else �������ȫλ��ƽ������࣬����ִ���κβ���
        }
        else
        {
            // ����β���ƽ��������ཻ����ȫ�����С� �����ȷ���ཻ֮����findintersect���̵��ã�����Զ���ᷢ�����������

            result.clear();
        }
    }

    return result;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::IntersectorUtility3<Real>::GetPointFromIndex(int index, const Box3& box)
{
    auto point = box.GetCenter();

    if (index & 4)
    {
        point += box.GetExtent(2) * box.GetAxis(2);
    }
    else
    {
        point -= box.GetExtent(2) * box.GetAxis(2);
    }

    if (index & 2)
    {
        point += box.GetExtent(1) * box.GetAxis(1);
    }
    else
    {
        point -= box.GetExtent(1) * box.GetAxis(1);
    }

    if (index & 1)
    {
        point += box.GetExtent(0) * box.GetAxis(0);
    }
    else
    {
        point -= box.GetExtent(0) * box.GetAxis(0);
    }

    return point;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_ACHIEVE_H
