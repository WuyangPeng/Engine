///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/31 16:32)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_DETAIL_H

#include "ConvexHull1.h"
#include "ConvexHullDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::ConvexHull1<Real>::ConvexHull1(const Vertices& vertices, Real epsilon, QueryType queryType)
    : ParentType{ boost::numeric_cast<int>(vertices.size()), epsilon, queryType }, vertices{ vertices }
{
    const auto numVertices = this->GetNumVertices();
    std::vector<SortedVertex> sortedArray(numVertices);

    for (auto i = 0; i < numVertices; ++i)
    {
        sortedArray.at(i).value = vertices.at(i);
        sortedArray.at(i).index = i;
    }
    std::sort(sortedArray.begin(), sortedArray.end());

    const auto lastIndex = numVertices - 1;

    auto range = sortedArray.at(lastIndex).value - sortedArray.at(0).value;
    if (this->GetEpsilon() <= range)
    {
        this->SetDimension(1);
        this->SetNumSimplices(2);

        this->AddIndex(sortedArray.at(0).index);
        this->AddIndex(sortedArray.at(lastIndex).index);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::ConvexHull1<Real>::ConvexHull1(const String& filename)
    : ParentType{ 0, Math<Real>::GetValue(0), QueryType::Real }, vertices{ 0 }
{
    LoadFile(filename);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ConvexHull1<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::ConvexHull1<Real>::Vertices Mathematics::ConvexHull1<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertices;
}

template <typename Real>
void Mathematics::ConvexHull1<Real>::LoadFile(const String& filename)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    CoreTools::ReadFileManager inFile{ filename };

    if (!ParentType::Load(inFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("加载文件失败\n"));
    }

    const auto numVertices = this->GetNumVertices();

    vertices.resize(numVertices);

    inFile.Read(sizeof(Real), numVertices, vertices.data());
}

template <typename Real>
void Mathematics::ConvexHull1<Real>::SaveFile(const String& filename) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::WriteFileManager outFile{ filename };

    if (!ParentType::Save(outFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("保存文件失败\n"));
    }

    outFile.Write(sizeof(Real), vertices.size(), vertices.data());
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_DETAIL_H