///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/31 16:32)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_DETAIL_H

#include "ConvexHull1Detail.h"
#include "ConvexHull2.h"
#include "Mathematics/Algebra/Vector2InformationDetail.h"
#include "Mathematics/Query/Query2Filtered.h"
#include "Mathematics/Query/Query2Int64.h"
#include "Mathematics/Query/Query2Integer.h"
#include "Mathematics/Query/Query2Rational.h"

template <typename Real>
Mathematics::ConvexHull2<Real>::ConvexHull2(const Vertices& vertices, Real epsilon, QueryType queryType)
    : ParentType{ boost::numeric_cast<int>(vertices.size()), epsilon, queryType },
      vertices{ vertices },
      sVertices{},
      query{},
      lineOrigin{},
      lineDirection{}
{
    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::Init()
{
    Vector2Information<Real> info{ vertices, this->GetEpsilon() };
    if (info.GetDimension() == 0)
    {
        return;
    }

    if (info.GetDimension() == 1)
    {
        this->SetDimension(1);
        lineOrigin = info.GetOrigin();
        lineDirection = info.GetDirectionX();

        return;
    }

    this->SetDimension(2);

    auto i0 = info.GetMinExtremeIndex();
    auto i1 = info.GetPerpendicularExtremeIndex();
    auto i2 = info.GetMaxExtremeIndex();

    const auto mNumVertices = this->GetNumVertices();
    sVertices.resize(mNumVertices);

    const auto queryType = this->GetQueryType();

    if (queryType != QueryType::Rational && queryType != QueryType::Filtered)
    {
        const auto minValue = info.GetMinExtreme();
        auto scale = MathType::GetValue(1) / info.GetMaxRange();
        for (auto i = 0; i < mNumVertices; ++i)
        {
            sVertices.at(i) = (vertices.at(i) - minValue) * scale;
        }

        Real expand{};
        if (queryType == QueryType::Int64)
        {
            expand = MathType::GetValue(1 << 20);
            query = std::make_shared<Query2Int64<Real>>(sVertices);
        }
        else if (queryType == QueryType::Integer)
        {
            expand = MathType::GetValue(1 << 24);
            query = std::make_shared<Query2Integer<Real>>(sVertices);
        }
        else
        {
            expand = MathType::GetValue(1);
            query = std::make_shared<Query2>(sVertices);
        }

        for (auto i = 0; i < mNumVertices; ++i)
        {
            sVertices.at(i) *= expand;
        }
    }
    else
    {
        sVertices = vertices;

        if (queryType == QueryType::Rational)
        {
            query = std::make_shared<Query2Rational<Real>>(sVertices);
        }
        else
        {
            query = std::make_shared<Query2Filtered<Real>>(sVertices, this->GetEpsilon());
        }
    }

    EdgeSharedPtr edge0{};
    EdgeSharedPtr edge1{};
    EdgeSharedPtr edge2{};

    if (info.IsExtremeCCW())
    {
        edge0 = std::make_shared<Edge>(i0, i1);
        edge1 = std::make_shared<Edge>(i1, i2);
        edge2 = std::make_shared<Edge>(i2, i0);
    }
    else
    {
        edge0 = std::make_shared<Edge>(i0, i2);
        edge1 = std::make_shared<Edge>(i2, i1);
        edge2 = std::make_shared<Edge>(i1, i0);
    }

    edge0->Insert(edge2, edge1);
    edge1->Insert(edge0, edge2);
    edge2->Insert(edge1, edge0);

    auto hull = edge0;
    for (auto i = 0; i < mNumVertices; ++i)
    {
        const auto result = Update(i, hull);
        if (!result.second)
        {
            hull->DeleteAll();
            return;
        }

        hull = result.first;
    }

    this->SetIndex(hull->GetIndices());
    hull->DeleteAll();
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::ConvexHull2<Real>::GetLineOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineOrigin;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::ConvexHull2<Real>::GetLineDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineDirection;
}

template <typename Real>
Mathematics::ConvexHull1<Real> Mathematics::ConvexHull2<Real>::GetConvexHull1() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const int dimension = this->GetDimension();

    if (dimension != 1)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为1。"));
    }

    typename ConvexHull1Type::Vertices projection{};
    for (const auto& value : vertices)
    {
        auto diff = value - lineOrigin;
        projection.emplace_back(Vector2Tools<Real>::DotProduct(lineDirection, diff));
    }

    ConvexHull1Type convexHull1(projection, this->GetEpsilon(), this->GetQueryType());

    return convexHull1;
}

template <typename Real>
Mathematics::ConvexHull2<Real>::ConvexHull2(const String& filename)
    : ParentType{ 0, MathType::GetValue(0), QueryType::Real },
      vertices{},
      sVertices{},
      query{},
      lineOrigin{},
      lineDirection{}
{
    LoadFile(filename);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ConvexHull2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::ConvexHull2<Real>::LoadFile(const String& filename)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    CoreTools::ReadFileManager inFile{ filename };

    if (!ParentType::Load(inFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("加载文件失败\n"));
    }

    query.reset();
    sVertices.resize(0);

    const auto numVertices = this->GetNumVertices();

    vertices.resize(numVertices);
    sVertices.resize(numVertices);

    const auto size = Vector2Type::pointSize * numVertices;

    inFile.Read(sizeof(Real), size, vertices.data());
    inFile.Read(sizeof(Real), size, sVertices.data());
    inFile.Read(sizeof(Real), Vector2Type::pointSize, &lineOrigin);
    inFile.Read(sizeof(Real), Vector2Type::pointSize, &lineDirection);

    switch (this->GetQueryType())
    {
        case QueryType::Int64:
        {
            query = std::make_shared<Query2Int64<Real>>(sVertices);
            break;
        }
        case QueryType::Integer:
        {
            query = std::make_shared<Query2Integer<Real>>(sVertices);
            break;
        }
        case QueryType::Rational:
        {
            query = std::make_shared<Query2Rational<Real>>(sVertices);
            break;
        }
        case QueryType::Real:
        {
            query = std::make_shared<Query2>(sVertices);
            break;
        }
        case QueryType::Filtered:
        {
            query = std::make_shared<Query2Filtered<Real>>(sVertices, this->GetEpsilon());
            break;
        }
    }
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::SaveFile(const String& filename) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::WriteFileManager outFile{ filename };

    if (!ParentType::Save(outFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("保存文件失败\n"));
    }

    const auto numVertices = this->GetNumVertices();

    const auto size = Vector2Type::pointSize * numVertices;

    outFile.Write(sizeof(Real), size, vertices.data());
    outFile.Write(sizeof(Real), size, sVertices.data());
    outFile.Write(sizeof(Real), Vector2Type::pointSize, &lineOrigin);
    outFile.Write(sizeof(Real), Vector2Type::pointSize, &lineDirection);
}

template <typename Real>
typename Mathematics::ConvexHull2<Real>::Result Mathematics::ConvexHull2<Real>::Update(int i, const EdgeSharedPtr& edg)
{
    auto hull = edg;
    EdgeSharedPtr visible{};
    auto current = hull;
    do
    {
        if (0 < System::EnumCastUnderlying(current->GetSign(i, *query)))
        {
            visible = current;
            break;
        }

        current = current->e.at(1).lock();
    } while (current != hull);

    if (!visible)
    {
        return { hull, true };
    }

    auto adj0 = visible->e.at(0).lock();

    if (!adj0)
    {
        return { hull, false };
    }

    auto adj1 = visible->e.at(1).lock();

    if (!adj1)
    {
        return { hull, false };
    }

    visible->DeleteSelf();

    while (0 < System::EnumCastUnderlying(adj0->GetSign(i, *query)))
    {
        hull = adj0;
        adj0 = adj0->e.at(0).lock();

        if (!adj0)
        {
            return { hull, false };
        }

        adj0->e.at(1).lock()->DeleteSelf();
    }

    while (0 < System::EnumCastUnderlying(adj1->GetSign(i, *query)))
    {
        hull = adj1;
        adj1 = adj1->e.at(1).lock();

        if (!adj1)
        {
            return { hull, false };
        }

        adj1->e.at(0).lock()->DeleteSelf();
    }

    auto edge0 = std::make_shared<Edge>(adj0->v.at(1), i);
    auto edge1 = std::make_shared<Edge>(i, adj1->v.at(0));
    edge0->Insert(adj0, edge1);
    edge1->Insert(edge0, adj1);

    return { edge0, true };
}

// ConvexHull2::Edge

template <typename Real>
Mathematics::ConvexHull2<Real>::Edge::Edge(int32_t v0, int32_t v1)
    : v{ v0, v1 }, e{}, sign{ LineQueryType::OnLine }, time{ -1 }
{
}

template <typename Real>
Mathematics::LineQueryType Mathematics::ConvexHull2<Real>::Edge::GetSign(int32_t i, const Query2& query)
{
    if (i != time)
    {
        time = i;
        sign = query.ToLine(i, v.at(0), v.at(1));
    }

    return sign;
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::Edge::Insert(const EdgeSharedPtr& adj0, const EdgeSharedPtr& adj1)
{
    adj0->e.at(1) = this->shared_from_this();
    adj1->e.at(0) = this->shared_from_this();
    e.at(0) = adj0;
    e.at(1) = adj1;
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::Edge::DeleteSelf()
{
    if (e.at(0).lock())
    {
        e.at(0).lock()->e.at(1).reset();
    }

    if (e.at(1).lock())
    {
        e.at(1).lock()->e.at(0).reset();
    }
}

template <typename Real>
void Mathematics::ConvexHull2<Real>::Edge::DeleteAll()
{
    auto adj = e.at(1).lock();
    while (adj && adj != this->shared_from_this())
    {
        auto save = adj->e.at(1).lock();

        adj = save;
    }

    MATHEMATICS_ASSERTION_0(adj == this->shared_from_this(), "意外情况。\n");
}

template <typename Real>
typename Mathematics::ConvexHull2<Real>::IndicesType Mathematics::ConvexHull2<Real>::Edge::GetIndices()
{
    auto numIndices = 0;
    auto current = this->shared_from_this();
    do
    {
        ++numIndices;
        current = current->e.at(1).lock();
    } while (current != this->shared_from_this());

    IndicesType indices(numIndices);

    numIndices = 0;
    current = this->shared_from_this();
    do
    {
        indices.at(numIndices) = current->v.at(0);
        ++numIndices;
        current = current->e.at(1).lock();
    } while (current != this->shared_from_this());

    return indices;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_DETAIL_H