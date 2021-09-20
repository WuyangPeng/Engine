// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/16 19:14)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Mathematics, TestingHelper, "数学库")

// private
void Mathematics::TestingHelper ::AddSuites()
{
    AddMacroSuite();
    AddBaseSuite();
    AddAlgebraSuite();
    AddObjects2DSuite();
    AddObjects3DSuite();
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

void Mathematics::TestingHelper ::AddMacroSuite()
{
    ADD_TEST_BEGIN(macroSuite, "宏");

    ADD_TEST_END(macroSuite);
}

// private
void Mathematics::TestingHelper ::AddBaseSuite()
{
    ADD_TEST_BEGIN(baseSuite, "基本");

    ADD_TEST(baseSuite, BitHacksTesting);
    ADD_TEST(baseSuite, MathTesting);
    ADD_TEST(baseSuite, FastTrigonometricTesting);
    ADD_TEST(baseSuite, FastNegativeExpTesting);
    ADD_TEST(baseSuite, RandomTesting);
    ADD_TEST(baseSuite, Float1Testing);
    ADD_TEST(baseSuite, Float2Testing);
    ADD_TEST(baseSuite, Float3Testing);
    ADD_TEST(baseSuite, Float4Testing);

    ADD_TEST_END(baseSuite);
}

// private
void Mathematics::TestingHelper ::AddAlgebraSuite()
{
    ADD_TEST_BEGIN(algebraSuite, "代数");

    ADD_TEST(algebraSuite, HomogeneousPointTesting);
    ADD_TEST(algebraSuite, BarycentricCoordinatesTesting);
    ADD_TEST(algebraSuite, Vector2DTesting);
    ADD_TEST(algebraSuite, Vector3DTesting);
    ADD_TEST(algebraSuite, Vector4DTesting);
    ADD_TEST(algebraSuite, Vector2DOrthonormalizeTesting);
    ADD_TEST(algebraSuite, Vector2DOrthonormalBasisTesting);
    ADD_TEST(algebraSuite, Vector3DOrthonormalizeTesting);
    ADD_TEST(algebraSuite, Vector3DOrthonormalBasisTesting);
    ADD_TEST(algebraSuite, AxesAlignBoundingBox2DTesting);
    ADD_TEST(algebraSuite, AxesAlignBoundingBox3DTesting);
    ADD_TEST(algebraSuite, AxesAlignBoundingBox4DTesting);
    ADD_TEST(algebraSuite, Vector2DToolsTesting);
    ADD_TEST(algebraSuite, Vector3DToolsTesting);
    ADD_TEST(algebraSuite, Vector4DToolsTesting);
    ADD_TEST(algebraSuite, Vector2DInformationTesting);
    ADD_TEST(algebraSuite, Vector3DInformationTesting);
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

    ADD_TEST_END(algebraSuite);
}

// private
void Mathematics::TestingHelper ::AddObjects2DSuite()
{
    ADD_TEST_BEGIN(objects2DSuite, "对象2D");

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

    ADD_TEST_END(objects2DSuite);
}

// private
void Mathematics::TestingHelper ::AddObjects3DSuite()
{
    ADD_TEST_BEGIN(objects3DSuite, "对象3D");

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

    ADD_TEST_END(objects3DSuite);
}

// private
void Mathematics::TestingHelper ::AddRationalSuite()
{
    ADD_TEST_BEGIN(rationalSuite, "有理数");

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

    ADD_TEST_END(rationalSuite);
}

// private
void Mathematics::TestingHelper ::AddNumericalAnalysisSuite()
{
    ADD_TEST_BEGIN(numericalAnalysisSuite, "数值分析");

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

    ADD_TEST_END(numericalAnalysisSuite);
}

void Mathematics::TestingHelper ::AddQuerySuite()
{
    ADD_TEST_BEGIN(querySuite, "查询");

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

    ADD_TEST_END(querySuite);
}

void Mathematics::TestingHelper ::AddApproximationSuite()
{
    ADD_TEST_BEGIN(approximationSuite, "近似");

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

    ADD_TEST_END(approximationSuite);
}

void Mathematics::TestingHelper ::AddDistanceSuite()
{
    ADD_TEST_BEGIN(distanceSuite, "距离测试");

    ADD_TEST(distanceSuite, DistanceResultTesting);
    ADD_TEST(distanceSuite, DistanceTesting);
    AddDistance2DSuite(distanceSuite);
    AddDistance3DSuite(distanceSuite);

    ADD_TEST_END(distanceSuite);
}

void Mathematics::TestingHelper ::AddDistance2DSuite(Suite& suite)
{
    ADD_TEST_BEGIN(distance2DSuite, "2D距离测试");

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

    suite.AddSuite(distance2DSuite);
}

void Mathematics::TestingHelper ::AddDistance3DSuite(Suite& suite)
{
    ADD_TEST_BEGIN(distance3DSuite, "3D距离测试");

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

    suite.AddSuite(distance3DSuite);
}

void Mathematics::TestingHelper ::AddIntersectionSuite()
{
    ADD_TEST_BEGIN(intersectionSuite, "相交测试");

    AddIntersection1DSuite(intersectionSuite);
    AddIntersection2DSuite(intersectionSuite);
    AddIntersection3DSuite(intersectionSuite);

    ADD_TEST_END(intersectionSuite);
}

void Mathematics::TestingHelper ::AddIntersection1DSuite(Suite& suite)
{
    ADD_TEST_BEGIN(intersection1DSuite, "1D相交测试");

    ADD_TEST(intersection1DSuite, IntersectorTesting);
    ADD_TEST(intersection1DSuite, StaticIntersectorTesting);
    ADD_TEST(intersection1DSuite, DynamicIntersectorTesting);
    ADD_TEST(intersection1DSuite, Intersector1Testing);
    ADD_TEST(intersection1DSuite, StaticTestIntersector1Testing);
    ADD_TEST(intersection1DSuite, StaticFindIntersector1Testing);
    ADD_TEST(intersection1DSuite, DynamicTestIntersector1Testing);
    ADD_TEST(intersection1DSuite, DynamicFindIntersector1Testing);

    suite.AddSuite(intersection1DSuite);
}

void Mathematics::TestingHelper ::AddIntersection2DSuite(Suite& suite)
{
    ADD_TEST_BEGIN(intersection2DSuite, "2D相交测试");

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

    suite.AddSuite(intersection2DSuite);
}

void Mathematics::TestingHelper ::AddIntersection3DSuite(Suite& suite)
{
    ADD_TEST_BEGIN(intersection3DSuite, "3D相交测试");

    ADD_TEST(intersection3DSuite, IntersectorLine3Triangle3Testing);
    ADD_TEST(intersection3DSuite, TriangleProjectOntoAxisTesting);
    ADD_TEST(intersection3DSuite, TrianglePlaneRelationsTesting);

    suite.AddSuite(intersection3DSuite);
}

void Mathematics::TestingHelper ::AddComputationalGeometrySuite()
{
    ADD_TEST_BEGIN(computationalGeometrySuite, "计算几何");

    ADD_TEST_END(computationalGeometrySuite);
}

void Mathematics::TestingHelper ::AddContainmentSuite()
{
    ADD_TEST_BEGIN(containmentSuite, "包含");

    ADD_TEST(containmentSuite, ScribeCircle2CircumscribeTesting);
    ADD_TEST(containmentSuite, ScribeCircle2InscribeTesting);
    ADD_TEST(containmentSuite, ContBox2Testing);
    ADD_TEST(containmentSuite, ContBox3Testing);

    ADD_TEST_END(containmentSuite);
}

void Mathematics::TestingHelper ::AddCurvesSurfacesVolumesSuite()
{
    ADD_TEST_BEGIN(curvesSurfacesVolumesSuite, "曲线曲面体积");

    ADD_TEST_END(curvesSurfacesVolumesSuite);
}

void Mathematics::TestingHelper ::AddInterpolationSuite()
{
    ADD_TEST_BEGIN(interpolationSuite, "插值");

    ADD_TEST_END(interpolationSuite);
}

void Mathematics::TestingHelper ::AddMeshesSuite()
{
    ADD_TEST_BEGIN(meshesSuite, "网格测试");

    ADD_TEST(meshesSuite, EdgeKeyTesting);
    ADD_TEST(meshesSuite, TriangleKeyTesting);

    ADD_TEST_END(meshesSuite);
}

void Mathematics::TestingHelper ::AddMiscellaneousSuite()
{
    ADD_TEST_BEGIN(miscellaneousSuite, "杂项");

    ADD_TEST_END(miscellaneousSuite);
}
