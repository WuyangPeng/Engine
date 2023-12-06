/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 19:30)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Mathematics::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数学库" }
{
    InitSuite();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, TestingHelper)

void Mathematics::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddBaseSuite();
    AddAlgebraSuite();
    AddObjects2DSuite();
    AddObjects3DSuite();
    AddPrimitivesSuite();
    AddRationalSuite();
    AddNumericalAnalysisSuite();
    AddQuerySuite();
    AddApproximationSuite();
    AddDistanceSuite();
    AddIntersectionSuite();
    AddComputationalGeometrySuite();
    AddContainmentSuite();
    AddCurvesSurfacesVolumesSuite();
    AddInterpolationSuite();
    AddMeshesSuite();
    AddMiscellaneousSuite();
}

void Mathematics::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void Mathematics::TestingHelper::AddBaseSuite()
{
    auto baseSuite = GenerateSuite("基本");

    ADD_TEST(baseSuite, BitHacksTesting);
    ADD_TEST(baseSuite, MathTesting);
    ADD_TEST(baseSuite, FastTrigonometricTesting);
    ADD_TEST(baseSuite, FastNegativeExpTesting);
    ADD_TEST(baseSuite, RandomTesting);
    ADD_TEST(baseSuite, Float1Testing);
    ADD_TEST(baseSuite, Float2Testing);
    ADD_TEST(baseSuite, Float3Testing);
    ADD_TEST(baseSuite, Float4Testing);

    AddSuite(baseSuite);
}

void Mathematics::TestingHelper::AddAlgebraSuite()
{
    auto algebraSuite = GenerateSuite("代数");

    ADD_TEST(algebraSuite, HomogeneousPointTesting);
    ADD_TEST(algebraSuite, BarycentricCoordinatesTesting);
    ADD_TEST(algebraSuite, Vector2Testing);
    ADD_TEST(algebraSuite, Vector3Testing);
    ADD_TEST(algebraSuite, Vector4Testing);
    ADD_TEST(algebraSuite, Vector2OrthonormalizeTesting);
    ADD_TEST(algebraSuite, Vector2OrthonormalBasisTesting);
    ADD_TEST(algebraSuite, Vector3OrthonormalizeTesting);
    ADD_TEST(algebraSuite, Vector3OrthonormalBasisTesting);
    ADD_TEST(algebraSuite, AxesAlignBoundingBox2DTesting);
    ADD_TEST(algebraSuite, AxesAlignBoundingBox3DTesting);
    ADD_TEST(algebraSuite, AxesAlignBoundingBox4DTesting);
    ADD_TEST(algebraSuite, Vector2ToolsTesting);
    ADD_TEST(algebraSuite, Vector3ToolsTesting);
    ADD_TEST(algebraSuite, Vector4ToolsTesting);
    ADD_TEST(algebraSuite, Vector2InformationTesting);
    ADD_TEST(algebraSuite, Vector3InformationTesting);
    ADD_TEST(algebraSuite, APointTesting);
    ADD_TEST(algebraSuite, AVectorOrthonormalizeTesting);
    ADD_TEST(algebraSuite, AVectorOrthonormalBasisTesting);
    ADD_TEST(algebraSuite, AVectorTesting);
    ADD_TEST(algebraSuite, VariableLengthVectorTesting);
    ADD_TEST(algebraSuite, PlaneTesting);
    ADD_TEST(algebraSuite, PolynomialTesting);
    ADD_TEST(algebraSuite, PolynomialDivideTesting);
    ADD_TEST(algebraSuite, Matrix2Testing);
    ADD_TEST(algebraSuite, Matrix2EigenDecompositionTesting);
    ADD_TEST(algebraSuite, Matrix3Testing);
    ADD_TEST(algebraSuite, Matrix3EigenDecompositionTesting);
    ADD_TEST(algebraSuite, Matrix3ExtractTesting);
    ADD_TEST(algebraSuite, EulerTesting);
    ADD_TEST(algebraSuite, Matrix4Testing);
    ADD_TEST(algebraSuite, MatrixTesting);
    ADD_TEST(algebraSuite, VariableMatrixTesting);
    ADD_TEST(algebraSuite, BandedMatrixTesting);
    ADD_TEST(algebraSuite, BandedMatrixSolveTesting);
    ADD_TEST(algebraSuite, QuaternionTesting);
    ADD_TEST(algebraSuite, QuaternionFactorTesting);
    ADD_TEST(algebraSuite, QuaternionConstraintsTesting);
    ADD_TEST(algebraSuite, QuaternionSwingTwistTesting);
    ADD_TEST(algebraSuite, AQuaternionTesting);
    ADD_TEST(algebraSuite, AlgebraStreamSizeTesting);
    ADD_TEST(algebraSuite, AlgebraAggregateTesting);
    algebraSuite.AddSuite(GetTransformSuite());
    ADD_TEST(algebraSuite, BoundingSphereTesting);

    AddSuite(algebraSuite);
}

CoreTools::Suite Mathematics::TestingHelper::GetTransformSuite()
{
    auto transformSuite = GenerateSuite("转换");

    ADD_TEST(transformSuite, IdentityTransformTesting);
    ADD_TEST(transformSuite, UnitScaleTransformTesting);
    ADD_TEST(transformSuite, ScaleTransformTesting);
    ADD_TEST(transformSuite, RotationTransformTesting);
    ADD_TEST(transformSuite, MatrixTransformTesting);
    ADD_TEST(transformSuite, TranslateTransformTesting);

    return transformSuite;
}

void Mathematics::TestingHelper::AddObjects2DSuite()
{
    auto objects2DSuite = GenerateSuite("对象2D");

    ADD_TEST(objects2DSuite, Arc2Testing);
    ADD_TEST(objects2DSuite, Box2Testing);
    ADD_TEST(objects2DSuite, Circle2Testing);
    ADD_TEST(objects2DSuite, Line2Testing);
    ADD_TEST(objects2DSuite, Ray2Testing);
    ADD_TEST(objects2DSuite, Triangle2Testing);
    ADD_TEST(objects2DSuite, Polygon2Testing);
    ADD_TEST(objects2DSuite, Segment2Testing);
    ADD_TEST(objects2DSuite, Ellipse2Testing);
    ADD_TEST(objects2DSuite, Ellipse2CoefficientsTesting);
    ADD_TEST(objects2DSuite, ConvexPolygon2Testing);

    AddSuite(objects2DSuite);
}

void Mathematics::TestingHelper::AddObjects3DSuite()
{
    auto objects3DSuite = GenerateSuite("对象3D");

    ADD_TEST(objects3DSuite, Box3Testing);
    ADD_TEST(objects3DSuite, Circle3Testing);
    ADD_TEST(objects3DSuite, Line3Testing);
    ADD_TEST(objects3DSuite, Ray3Testing);
    ADD_TEST(objects3DSuite, Triangle3Testing);
    ADD_TEST(objects3DSuite, Segment3Testing);
    ADD_TEST(objects3DSuite, Sphere3Testing);
    ADD_TEST(objects3DSuite, Capsule3Testing);
    ADD_TEST(objects3DSuite, Cone3Testing);
    ADD_TEST(objects3DSuite, Cylinder3Testing);
    ADD_TEST(objects3DSuite, Ellipse3Testing);
    ADD_TEST(objects3DSuite, Ellipsoid3Testing);
    ADD_TEST(objects3DSuite, Ellipsoid3CoefficientsTesting);
    ADD_TEST(objects3DSuite, Frustum3Testing);
    ADD_TEST(objects3DSuite, Plane3Testing);
    ADD_TEST(objects3DSuite, Torus3Testing);
    ADD_TEST(objects3DSuite, Torus3ParametersTesting);
    ADD_TEST(objects3DSuite, Tetrahedron3Testing);
    ADD_TEST(objects3DSuite, Rectangle3Testing);
    ADD_TEST(objects3DSuite, Lozenge3Testing);
    ADD_TEST(objects3DSuite, Polyhedron3Testing);
    ADD_TEST(objects3DSuite, ConvexPolyhedron3Testing);

    AddSuite(objects3DSuite);
}

void Mathematics::TestingHelper::AddPrimitivesSuite()
{
    auto primitivesSuite = GenerateSuite("基本体");

    AddSuite(primitivesSuite);
}

void Mathematics::TestingHelper::AddRationalSuite()
{
    auto rationalSuite = GenerateSuite("有理数");

    ADD_TEST(rationalSuite, FloatingPointAnalysisTesting);
    ADD_TEST(rationalSuite, ConversionIntegerTesting);
    ADD_TEST(rationalSuite, IntegerDataTesting);
    ADD_TEST(rationalSuite, IntegerDataAmendTesting);
    ADD_TEST(rationalSuite, IntegerDataAnalysisTesting);
    ADD_TEST(rationalSuite, IntegerDataOperatorTesting);
    ADD_TEST(rationalSuite, IntegerMultiplicationTesting);
    ADD_TEST(rationalSuite, IntegerDivisionModuloTesting);
    ADD_TEST(rationalSuite, IntegerDataConversionTesting);
    ADD_TEST(rationalSuite, IntegerTesting);
    ADD_TEST(rationalSuite, ConversionRationalTesting);
    ADD_TEST(rationalSuite, RationalConversionTesting);
    ADD_TEST(rationalSuite, RationalTesting);
    ADD_TEST(rationalSuite, Int64VectorTesting);
    ADD_TEST(rationalSuite, Int64Vector2Testing);
    ADD_TEST(rationalSuite, Int64Vector3Testing);
    ADD_TEST(rationalSuite, RationalVectorTesting);
    ADD_TEST(rationalSuite, RationalVector2Testing);
    ADD_TEST(rationalSuite, RationalVector3Testing);

    AddSuite(rationalSuite);
}

void Mathematics::TestingHelper::AddNumericalAnalysisSuite()
{
    auto numericalAnalysisSuite = GenerateSuite("数值分析");

    ADD_TEST(numericalAnalysisSuite, EquationResultConstIteratorTesting);
    ADD_TEST(numericalAnalysisSuite, EquationTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect1RootTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect1Testing);
    ADD_TEST(numericalAnalysisSuite, Bisect2RootTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect2NodeTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect2StorageTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect2CalculateTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect2Testing);
    ADD_TEST(numericalAnalysisSuite, Bisect3RootTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect3NodeTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect3StorageTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect3CalculateTesting);
    ADD_TEST(numericalAnalysisSuite, Bisect3Testing);
    ADD_TEST(numericalAnalysisSuite, BrentsMethodRootTesting);
    ADD_TEST(numericalAnalysisSuite, BrentsMethodCalculateTesting);
    ADD_TEST(numericalAnalysisSuite, BrentsMethodTesting);
    ADD_TEST(numericalAnalysisSuite, EigenDecompositionTesting);
    ADD_TEST(numericalAnalysisSuite, GaussianQuadratureTesting);
    ADD_TEST(numericalAnalysisSuite, LinearSystemInverseTesting);
    ADD_TEST(numericalAnalysisSuite, SolveSymmetricConjugateGradientTesting);
    ADD_TEST(numericalAnalysisSuite, SparseMatrixIndexTesting);
    ADD_TEST(numericalAnalysisSuite, SparseMatrixTesting);
    ADD_TEST(numericalAnalysisSuite, SolveBandedTesting);
    ADD_TEST(numericalAnalysisSuite, BandedMatrixInvertTesting);
    ADD_TEST(numericalAnalysisSuite, LinearSystemTesting);
    ADD_TEST(numericalAnalysisSuite, Minimize1DataTesting);
    ADD_TEST(numericalAnalysisSuite, Minimize1Testing);
    ADD_TEST(numericalAnalysisSuite, MinimizeNDataTesting);
    ADD_TEST(numericalAnalysisSuite, MinimizeNTesting);
    ADD_TEST(numericalAnalysisSuite, NoniterativeEigen3x3Testing);
    ADD_TEST(numericalAnalysisSuite, OdeSolverTesting);
    ADD_TEST(numericalAnalysisSuite, OdeEulerTesting);
    ADD_TEST(numericalAnalysisSuite, OdeImplicitEulerTesting);
    ADD_TEST(numericalAnalysisSuite, OdeMidpointTesting);
    ADD_TEST(numericalAnalysisSuite, OdeRungeKutta4Testing);
    ADD_TEST(numericalAnalysisSuite, PolynomialRootsTesting);
    ADD_TEST(numericalAnalysisSuite, PolynomialRootsRationalTesting);
    ADD_TEST(numericalAnalysisSuite, RombergIntegralTesting);
    ADD_TEST(numericalAnalysisSuite, TrapezoidRuleTesting);
    ADD_TEST(numericalAnalysisSuite, SingularValueDecompositionTesting);
    ADD_TEST(numericalAnalysisSuite, Matrix3ToolsTesting);
    ADD_TEST(numericalAnalysisSuite, SingularValueTesting);
    ADD_TEST(numericalAnalysisSuite, PolarDecompositionValueTesting);
    ADD_TEST(numericalAnalysisSuite, QDUDecompositionValueTesting);

    AddSuite(numericalAnalysisSuite);
}

void Mathematics::TestingHelper::AddQuerySuite()
{
    auto querySuite = GenerateSuite("查询");

    ADD_TEST(querySuite, QuerySortToolsTesting);
    ADD_TEST(querySuite, QueryDotToolsTesting);
    ADD_TEST(querySuite, Query2Testing);
    ADD_TEST(querySuite, Query2IntegerTesting);
    ADD_TEST(querySuite, Query2Int64Testing);
    ADD_TEST(querySuite, Query2RationalTesting);
    ADD_TEST(querySuite, Query2FilteredTesting);
    ADD_TEST(querySuite, Query3Testing);
    ADD_TEST(querySuite, Query3IntegerTesting);
    ADD_TEST(querySuite, Query3Int64Testing);
    ADD_TEST(querySuite, Query3RationalTesting);
    ADD_TEST(querySuite, Query3FilteredTesting);

    AddSuite(querySuite);
}

void Mathematics::TestingHelper::AddApproximationSuite()
{
    auto approximationSuite = GenerateSuite("近似");

    ADD_TEST(approximationSuite, QuadraticCircleFit2Testing);
    ADD_TEST(approximationSuite, QuadraticFit2Testing);
    ADD_TEST(approximationSuite, CircleFit2Testing);
    ADD_TEST(approximationSuite, EllipseByArcs2Testing);
    ADD_TEST(approximationSuite, QuadraticSphereFit3Testing);
    ADD_TEST(approximationSuite, QuadraticFit3Testing);
    ADD_TEST(approximationSuite, SphereFit3Testing);
    ADD_TEST(approximationSuite, HeightLineFit2Testing);
    ADD_TEST(approximationSuite, OrthogonalLineFit2Testing);
    ADD_TEST(approximationSuite, OrthogonalLineFit3Testing);
    ADD_TEST(approximationSuite, GaussPointsFit2Testing);
    ADD_TEST(approximationSuite, GaussPointsFit3Testing);
    ADD_TEST(approximationSuite, ParaboloidFit3Testing);
    ADD_TEST(approximationSuite, HeightPlaneFit3Testing);
    ADD_TEST(approximationSuite, OrthogonalPlaneFit3Testing);
    ADD_TEST(approximationSuite, CylinderFit3Testing);
    ADD_TEST(approximationSuite, EllipseFit2Testing);
    ADD_TEST(approximationSuite, EllipsoidFit3Testing);
    ADD_TEST(approximationSuite, GreatCircleFit3Testing);
    ADD_TEST(approximationSuite, GreatArcFit3Testing);
    ADD_TEST(approximationSuite, PolynomialFit2Testing);
    ADD_TEST(approximationSuite, PolynomialFit3Testing);
    ADD_TEST(approximationSuite, PolynomialFit4Testing);
    ADD_TEST(approximationSuite, PolynomialFit2PowersTesting);
    ADD_TEST(approximationSuite, PolynomialFit3PowersTesting);
    ADD_TEST(approximationSuite, PolynomialFit4PowersTesting);

    AddSuite(approximationSuite);
}

void Mathematics::TestingHelper::AddDistanceSuite()
{
    auto distanceSuite = GenerateSuite("距离测试");

    ADD_TEST(distanceSuite, DistanceResultTesting);
    ADD_TEST(distanceSuite, DistanceTesting);
    distanceSuite.AddSuite(GetDistance2DSuite());
    distanceSuite.AddSuite(GetDistance3DSuite());

    AddSuite(distanceSuite);
}

CoreTools::Suite Mathematics::TestingHelper::GetDistance2DSuite()
{
    auto distance2DSuite = GenerateSuite("2D距离测试");

    ADD_TEST(distance2DSuite, DistanceLine2Line2Testing);
    ADD_TEST(distance2DSuite, DistanceRay2Ray2Testing);
    ADD_TEST(distance2DSuite, DistanceSegment2Segment2Testing);
    ADD_TEST(distance2DSuite, DistanceLine2Ray2Testing);
    ADD_TEST(distance2DSuite, DistanceLine2Segment2Testing);
    ADD_TEST(distance2DSuite, DistanceRay2Segment2Testing);
    ADD_TEST(distance2DSuite, DistancePoint2Line2Testing);
    ADD_TEST(distance2DSuite, DistancePoint2Ray2Testing);
    ADD_TEST(distance2DSuite, DistancePoint2Segment2Testing);
    ADD_TEST(distance2DSuite, DistancePoint2Ellipse2Testing);
    ADD_TEST(distance2DSuite, DistancePoint2Box2Testing);
    ADD_TEST(distance2DSuite, DistancePoint2Hyperbola2Testing);

    return distance2DSuite;
}

CoreTools::Suite Mathematics::TestingHelper::GetDistance3DSuite()
{
    auto distance3DSuite = GenerateSuite("3D距离测试");

    ADD_TEST(distance3DSuite, DistancePoint3Ellipsoid3Testing);
    ADD_TEST(distance3DSuite, DistanceLine3Line3Testing);
    ADD_TEST(distance3DSuite, DistanceRay3Ray3Testing);
    ADD_TEST(distance3DSuite, DistanceSegment3Segment3Testing);
    ADD_TEST(distance3DSuite, DistanceLine3Ray3Testing);
    ADD_TEST(distance3DSuite, DistanceRay3Segment3Testing);
    ADD_TEST(distance3DSuite, DistanceLine3Segment3Testing);
    ADD_TEST(distance3DSuite, DistancePoint3Line3Testing);
    ADD_TEST(distance3DSuite, DistancePoint3Ray3Testing);
    ADD_TEST(distance3DSuite, DistancePoint3Segment3Testing);
    ADD_TEST(distance3DSuite, DistancePoint3Box3Testing);
    ADD_TEST(distance3DSuite, DistanceCircle3Circle3Testing);

    return distance3DSuite;
}

void Mathematics::TestingHelper::AddIntersectionSuite()
{
    auto intersectionSuite = GenerateSuite("相交测试");

    intersectionSuite.AddSuite(GetIntersection1DSuite());
    intersectionSuite.AddSuite(GetIntersection2DSuite());
    intersectionSuite.AddSuite(GetIntersection3DSuite());

    AddSuite(intersectionSuite);
}

CoreTools::Suite Mathematics::TestingHelper::GetIntersection1DSuite()
{
    auto intersection1DSuite = GenerateSuite("1D相交测试");

    ADD_TEST(intersection1DSuite, IntersectorTesting);
    ADD_TEST(intersection1DSuite, StaticIntersectorTesting);
    ADD_TEST(intersection1DSuite, DynamicIntersectorTesting);
    ADD_TEST(intersection1DSuite, Intersector1Testing);
    ADD_TEST(intersection1DSuite, StaticTestIntersector1Testing);
    ADD_TEST(intersection1DSuite, StaticFindIntersector1Testing);
    ADD_TEST(intersection1DSuite, DynamicTestIntersector1Testing);
    ADD_TEST(intersection1DSuite, DynamicFindIntersector1Testing);

    return intersection1DSuite;
}

CoreTools::Suite Mathematics::TestingHelper::GetIntersection2DSuite()
{
    auto intersection2DSuite = GenerateSuite("2D相交测试");

    ADD_TEST(intersection2DSuite, StaticFindIntersectorCircle2Circle2Testing);
    ADD_TEST(intersection2DSuite, StaticFindIntersectorArc2Arc2Testing);
    ADD_TEST(intersection2DSuite, StaticFindIntersectorArc2Circle2Testing);
    ADD_TEST(intersection2DSuite, StaticTestIntersectorBox2Box2Testing);
    ADD_TEST(intersection2DSuite, StaticTestIntersectorLine2ClassifyTesting);
    ADD_TEST(intersection2DSuite, StaticTestIntersectorLine2Line2Testing);
    ADD_TEST(intersection2DSuite, StaticFindIntersectorLine2Line2Testing);
    ADD_TEST(intersection2DSuite, StaticTestIntersectorRay2Ray2Testing);
    ADD_TEST(intersection2DSuite, StaticFindIntersectorRay2Ray2Testing);
    ADD_TEST(intersection2DSuite, StaticTestIntersectorSegment2Segment2Testing);
    ADD_TEST(intersection2DSuite, StaticFindIntersectorSegment2Segment2Testing);
    ADD_TEST(intersection2DSuite, StaticTestIntersectorLine2Ray2Testing);
    ADD_TEST(intersection2DSuite, StaticFindIntersectorLine2Ray2Testing);
    ADD_TEST(intersection2DSuite, StaticTestIntersectorLine2Segment2Testing);
    ADD_TEST(intersection2DSuite, StaticFindIntersectorLine2Segment2Testing);
    ADD_TEST(intersection2DSuite, StaticTestIntersectorRay2Segment2Testing);
    ADD_TEST(intersection2DSuite, StaticFindIntersectorRay2Segment2Testing);

    return intersection2DSuite;
}

CoreTools::Suite Mathematics::TestingHelper::GetIntersection3DSuite()
{
    auto intersection3DSuite = GenerateSuite("3D相交测试");

    ADD_TEST(intersection3DSuite, IntersectorLine3Triangle3Testing);
    ADD_TEST(intersection3DSuite, TriangleProjectOntoAxisTesting);
    ADD_TEST(intersection3DSuite, TrianglePlaneRelationsTesting);

    return intersection3DSuite;
}

void Mathematics::TestingHelper::AddComputationalGeometrySuite()
{
    auto computationalGeometrySuite = GenerateSuite("计算几何");

    AddSuite(computationalGeometrySuite);
}

void Mathematics::TestingHelper::AddContainmentSuite()
{
    auto containmentSuite = GenerateSuite("包含");

    ADD_TEST(containmentSuite, ScribeCircle2CircumscribeTesting);
    ADD_TEST(containmentSuite, ScribeCircle2InscribeTesting);
    ADD_TEST(containmentSuite, ContBox2Testing);
    ADD_TEST(containmentSuite, ContBox3Testing);

    AddSuite(containmentSuite);
}

void Mathematics::TestingHelper::AddCurvesSurfacesVolumesSuite()
{
    auto curvesSurfacesVolumesSuite = GenerateSuite("曲线曲面体积");

    AddSuite(curvesSurfacesVolumesSuite);
}

void Mathematics::TestingHelper::AddInterpolationSuite()
{
    auto interpolationSuite = GenerateSuite("插值");

    AddSuite(interpolationSuite);
}

void Mathematics::TestingHelper::AddMeshesSuite()
{
    auto meshesSuite = GenerateSuite("网格测试");

    ADD_TEST(meshesSuite, EdgeKeyTesting);
    ADD_TEST(meshesSuite, TriangleKeyTesting);

    AddSuite(meshesSuite);
}

void Mathematics::TestingHelper::AddMiscellaneousSuite()
{
    auto miscellaneousSuite = GenerateSuite("杂项");

    AddSuite(miscellaneousSuite);
}
