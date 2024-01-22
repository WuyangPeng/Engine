///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:35)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_DETAIL_H

#include "ConvexHull3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3InformationDetail.h"
#include "Mathematics/Query/Query3Filtered.h"
#include "Mathematics/Query/Query3Int64.h"
#include "Mathematics/Query/Query3Integer.h"
#include "Mathematics/Query/Query3Rational.h"

#include <map>
#include <stack>

template <typename Real>
Mathematics::ConvexHull3<Real>::ConvexHull3(const Vertices& vertices, Real epsilon, QueryType queryType)
    : ParentType{ boost::numeric_cast<int>(vertices.size()), epsilon, queryType },
      vertices{ vertices },
      sVertices{},
      query{},
      lineOrigin{},
      lineDirection{},
      planeOrigin{},
      planeDirection{},
      hull{}
{
    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::ConvexHull3<Real>::Init()
{
    Vector3Information<Real> info{ vertices, this->GetEpsilon() };
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

    if (info.GetDimension() == 2)
    {
        this->SetDimension(2);
        planeOrigin = info.GetOrigin();
        planeDirection.at(0) = info.GetDirectionX();
        planeDirection.at(1) = info.GetDirectionY();

        return;
    }

    this->SetDimension(3);

    const auto i0 = info.GetMinExtremeIndex();
    const auto i1 = info.GetPerpendicularExtremeIndex();
    const auto i2 = info.GetTetrahedronExtremeIndex();
    const auto i3 = info.GetMaxExtremeIndex();

    const auto mNumVertices = this->GetNumVertices();
    const auto eQueryType = this->GetQueryType();
    sVertices.resize(mNumVertices);

    if (eQueryType != QueryType::Rational && eQueryType != QueryType::Filtered)
    {
        const auto minValue = info.GetMinExtreme();
        const auto scale = Math::GetValue(1) / info.GetMaxRange();
        for (auto i = 0; i < mNumVertices; ++i)
        {
            sVertices.at(i) = (vertices.at(i) - minValue) * scale;
        }

        Real expand{};
        if (eQueryType == QueryType::Int64)
        {
            expand = Math::GetValue(1 << 20);
            query = std::make_shared<Query3Int64<Real>>(sVertices);
        }
        else if (eQueryType == QueryType::Integer)
        {
            expand = Math::GetValue(1 << 24);
            query = std::make_shared<Query3Integer<Real>>(sVertices);
        }
        else
        {
            expand = Math::GetValue(1);
            query = std::make_shared<Query3>(sVertices);
        }

        for (auto i = 0; i < mNumVertices; ++i)
        {
            sVertices.at(i) *= expand;
        }
    }
    else
    {
        sVertices = vertices;

        if (eQueryType == QueryType::Rational)
        {
            query = std::make_shared<Query3Rational<Real>>(sVertices);
        }
        else
        {
            query = std::make_shared<Query3Filtered<Real>>(sVertices, this->GetEpsilon());
        }
    }

    TriangleSharedPtr tri0{};
    TriangleSharedPtr tri1{};
    TriangleSharedPtr tri2{};
    TriangleSharedPtr tri3{};

    if (info.IsExtremeCCW())
    {
        tri0 = std::make_shared<Triangle>(i0, i1, i3);
        tri1 = std::make_shared<Triangle>(i0, i2, i1);
        tri2 = std::make_shared<Triangle>(i0, i3, i2);
        tri3 = std::make_shared<Triangle>(i1, i2, i3);
        tri0->AttachTo(tri1, tri3, tri2);
        tri1->AttachTo(tri2, tri3, tri0);
        tri2->AttachTo(tri0, tri3, tri1);
        tri3->AttachTo(tri1, tri2, tri0);
    }
    else
    {
        tri0 = std::make_shared<Triangle>(i0, i3, i1);
        tri1 = std::make_shared<Triangle>(i0, i1, i2);
        tri2 = std::make_shared<Triangle>(i0, i2, i3);
        tri3 = std::make_shared<Triangle>(i1, i3, i2);
        tri0->AttachTo(tri2, tri3, tri1);
        tri1->AttachTo(tri0, tri3, tri2);
        tri2->AttachTo(tri1, tri3, tri0);
        tri3->AttachTo(tri0, tri2, tri1);
    }

    hull.clear();
    hull.insert(tri0);
    hull.insert(tri1);
    hull.insert(tri2);
    hull.insert(tri3);

    for (auto i = 0; i < mNumVertices; ++i)
    {
        if (!Update(i))
        {
            DeleteHull();
            return;
        }
    }

    ExtractIndices();
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::ConvexHull3<Real>::GetLineOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineOrigin;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::ConvexHull3<Real>::GetLineDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineDirection;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::ConvexHull3<Real>::GetPlaneOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return planeOrigin;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::ConvexHull3<Real>::GetPlaneDirection(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return planeDirection.at(i);
}

template <typename Real>
Mathematics::ConvexHull1<Real> Mathematics::ConvexHull3<Real>::GetConvexHull1() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 1)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为1。"));
    }

    const auto mNumVertices = this->GetNumVertices();
    typename ConvexHull1::Vertices projection{};
    for (auto i = 0; i < mNumVertices; ++i)
    {
        auto diff = vertices.at(i) - lineOrigin;
        projection.emplace_back(Vector3Tools<Real>::DotProduct(lineDirection, diff));
    }

    return ConvexHull1{ projection, this->GetEpsilon(), this->GetQueryType() };
}

template <typename Real>
Mathematics::ConvexHull2<Real> Mathematics::ConvexHull3<Real>::GetConvexHull2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为2。"));
    }

    const auto numVertices = this->GetNumVertices();
    typename ConvexHull2::Vertices projection(numVertices);
    for (auto i = 0; i < numVertices; ++i)
    {
        auto diff = vertices.at(i) - planeOrigin;
        projection.at(i)[0] = Vector3Tools<Real>::DotProduct(planeDirection.at(0), diff);
        projection.at(i)[1] = Vector3Tools<Real>::DotProduct(planeDirection.at(1), diff);
    }

    return ConvexHull2{ projection, this->GetEpsilon(), this->GetQueryType() };
}

template <typename Real>
Mathematics::ConvexHull3<Real>::ConvexHull3(const String& filename)
    : ParentType{ 0, Math::GetValue(0), QueryType::Real },
      vertices{},
      sVertices{},
      query{},
      lineOrigin{},
      lineDirection{},
      planeOrigin{},
      planeDirection{},
      hull{}
{
    LoadFile(filename);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ConvexHull3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::ConvexHull3<Real>::LoadFile(const String& filename)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    CoreTools::ReadFileManager inFile{ filename };

    if (!ParentType::Load(inFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("加载文件失败\n"));
    }

    const auto numVertices = this->GetNumVertices();
    vertices.resize(numVertices);
    sVertices.resize(numVertices);

    const auto size = Vector3::pointSize * numVertices;

    inFile.Read(sizeof(Real), size, vertices.data());
    inFile.Read(sizeof(Real), size, sVertices.data());
    inFile.Read(sizeof(Real), Vector3::pointSize, &lineOrigin);
    inFile.Read(sizeof(Real), Vector3::pointSize, &lineDirection);
    inFile.Read(sizeof(Real), Vector3::pointSize, &planeOrigin);
    inFile.Read(sizeof(Real), Vector3::pointSize * 2, planeDirection.data());

    switch (this->GetQueryType())
    {
        case QueryType::Int64:
        {
            query = std::make_shared<Query3Int64<Real>>(sVertices);
            break;
        }
        case QueryType::Integer:
        {
            query = std::make_shared<Query3Integer<Real>>(sVertices);
            break;
        }
        case QueryType::Rational:
        {
            query = std::make_shared<Query3Rational<Real>>(sVertices);
            break;
        }
        case QueryType::Real:
        {
            query = std::make_shared<Query3>(sVertices);
            break;
        }
        case QueryType::Filtered:
        {
            query = std::make_shared<Query3Filtered<Real>>(sVertices, this->GetEpsilon());
            break;
        }
    }
}

template <typename Real>
void Mathematics::ConvexHull3<Real>::SaveFile(const String& filename) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::WriteFileManager outFile{ filename };

    if (!ParentType::Save(outFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("保存文件失败\n"));
    }

    const auto numVertices = this->GetNumVertices();

    const auto size = Vector3::pointSize * numVertices;

    outFile.Write(sizeof(Real), size, vertices.data());
    outFile.Write(sizeof(Real), size, sVertices.data());
    outFile.Write(sizeof(Real), Vector3::pointSize, &lineOrigin);
    outFile.Write(sizeof(Real), Vector3::pointSize, &lineDirection);
    outFile.Write(sizeof(Real), Vector3::pointSize, &planeOrigin);
    outFile.Write(sizeof(Real), Vector3::pointSize * 2, planeDirection.data());
}

template <typename Real>
bool Mathematics::ConvexHull3<Real>::Update(int32_t i)
{
    TriangleSharedPtr visible{};

    for (const auto& tri : hull)
    {
        if (0 < System::EnumCastUnderlying(tri->GetSign(i, *query)))
        {
            visible = tri;
            break;
        }
    }

    if (!visible)
    {
        return true;
    }

    std::stack<TriangleSharedPtr> visibleSet{};
    std::map<int, TerminatorData> terminator{};
    visibleSet.emplace(visible);
    visible->onStack = true;

    while (!visibleSet.empty())
    {
        TriangleSharedPtr tri = visibleSet.top();
        visibleSet.pop();
        tri->onStack = false;
        for (auto j = 0; j < 3; ++j)
        {
            auto adj = tri->triangle.at(j).lock();
            if (adj)
            {
                const auto nullIndex = tri->DetachFrom(j, adj);

                if (0 < System::EnumCastUnderlying(adj->GetSign(i, *query)))
                {
                    if (!adj->onStack)
                    {
                        visibleSet.emplace(adj);
                        adj->onStack = true;
                    }
                }
                else
                {
                    auto v0 = tri->v.at(j);
                    auto v1 = tri->v.at((j + 1) % 3);
                    terminator[v0] = TerminatorData{ v0, v1, nullIndex, adj };
                }
            }
        }

        hull.erase(tri);
    }

    const auto size = boost::numeric_cast<int>(terminator.size());
    MATHEMATICS_ASSERTION_0(3 <= size, "Terminator必须至少是一个三角形。\n");

    auto edge = terminator.begin();
    auto v0 = edge->second.v.at(0);
    auto v1 = edge->second.v.at(1);
    auto tri = std::make_shared<Triangle>(i, v0, v1);
    hull.emplace(tri);

    auto saveV0 = edge->second.v.at(0);
    auto saveTri = tri;

    tri->triangle.at(1) = edge->second.t;
    edge->second.t.lock()->triangle.at(edge->second.nullIndex) = tri;
    for (auto j = 1; j < size; ++j)
    {
        edge = terminator.find(v1);
        if (edge == terminator.cend())
        {
            THROW_EXCEPTION(SYSTEM_TEXT("意外情况\n"));
        }

        v0 = v1;
        v1 = edge->second.v.at(1);
        auto next = std::make_shared<Triangle>(i, v0, v1);
        hull.emplace(next);

        next->triangle.at(1) = edge->second.t.lock();
        edge->second.t.lock()->triangle.at(edge->second.nullIndex) = next;

        next->triangle.at(0) = tri;
        tri->triangle.at(2) = next;

        tri = next;
    }

    MATHEMATICS_ASSERTION_0(v1 == saveV0, "期望初始顶点\n");

    saveTri->triangle.at(0) = tri;
    tri->triangle.at(2) = saveTri;

    return true;
}

template <typename Real>
void Mathematics::ConvexHull3<Real>::ExtractIndices()
{
    this->SetNumSimplices(boost::numeric_cast<int>(hull.size()));

    for (const auto& tri : hull)
    {
        for (int j = 0; j < 3; ++j)
        {
            this->AddIndex(tri->v.at(j));
        }
    }
    hull.clear();
}

template <typename Real>
void Mathematics::ConvexHull3<Real>::DeleteHull() noexcept
{
    hull.clear();
}

// ConvexHull3::Triangle

template <typename Real>
Mathematics::ConvexHull3<Real>::Triangle::Triangle(int32_t v0, int32_t v1, int32_t v2)
    : v{ v0, v1, v2 }, triangle{}, sign{ 0 }, time{ -1 }, onStack{ false }
{
}

template <typename Real>
Mathematics::PlaneQueryType Mathematics::ConvexHull3<Real>::Triangle::GetSign(int32_t i, const Query3& query)
{
    if (i != time)
    {
        time = i;
        sign = query.ToPlane(i, v.at(0), v.at(1), v.at(2));
    }

    return sign;
}

template <typename Real>
void Mathematics::ConvexHull3<Real>::Triangle::AttachTo(const TriangleSharedPtr& adj0, const TriangleSharedPtr& adj1, const TriangleSharedPtr& adj2)
{
    triangle.at(0) = adj0;
    triangle.at(1) = adj1;
    triangle.at(2) = adj2;
}

template <typename Real>
int Mathematics::ConvexHull3<Real>::Triangle::DetachFrom(int32_t adjIndex, const TriangleSharedPtr& adj)
{
    MATHEMATICS_ASSERTION_0(0 <= adjIndex && adjIndex < 3 && triangle.at(adjIndex).lock() == adj, "无效输入。\n");

    triangle.at(adjIndex).reset();
    for (auto i = 0; i < 3; ++i)
    {
        if (adj->triangle.at(i).lock() == this->shared_from_this())
        {
            adj->triangle.at(i).reset();
            return i;
        }
    }

    return -1;
}

// ConvexHull3::TerminatorData

template <typename Real>
Mathematics::ConvexHull3<Real>::TerminatorData::TerminatorData() noexcept
    : v{ -1, -1 }, nullIndex{ -1 }, t{}
{
}

template <typename Real>
Mathematics::ConvexHull3<Real>::TerminatorData::TerminatorData(int32_t v0, int32_t v1, int32_t nullIndex, const TriangleWeakPtr& tri) noexcept
    : v{ v0, v1 }, nullIndex{ nullIndex }, t{ tri }
{
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_DETAIL_H