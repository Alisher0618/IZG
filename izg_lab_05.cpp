/******************************************************************************
 * Laborator 04 Krivky - Zaklady pocitacove grafiky - IZG
 * ihulik@fit.vutbr.cz
 *
 *
 * Popis: Hlavicky funkci pro funkce studentu
 *
 * Opravy a modifikace:
 * - isvoboda@fit.vutbr.cz
 * - ireich@fit.vutbr.cz
 */

#include "student.h"
#include "globals.h"
#include "main.h"

#include <time.h>
#include <math.h>

 //Viz hlavicka vector.h
USE_VECTOR_OF(Point2d, point2d_vec)
#define point2d_vecGet(pVec, i) (*point2d_vecGetPtr((pVec), (i)))

/* Secte dva body Point2d a vysledek vrati v result (musi byt inicializovan a alokovan)*/
void	addPoint2d(const Point2d* a, const Point2d* b, Point2d* result)
{
	IZG_ASSERT(result);
	result->x = a->x + b->x;
	result->y = a->y + b->y;
}

/* Vynasobi bod Point2d skalarni hodnotou typu double a vysledek vrati v result (musi byt inicializovan a alokovan)*/
void	mullPoint2d(double val, const Point2d* p, Point2d* result)
{
	IZG_ASSERT(result);
	result->x = p->x * val;
	result->y = p->y * val;
}

/**
 * Inicializace ridicich bodu horni trajektorie ve vykreslovacim okne.
 * Pocatek souradnicove soustavy je v levem hornim rohu okna. Xova souradnice
 * roste smerem doprava, Y smerem dolu.
 * @param points vystup, kam se pridavaji ridici body
 * @param offset_x posun vsech ridicich bodu v horizontalnim smeru (aby se mohli souradnice zadavat s pocatkem [0,0])
 * @param offset_y posun vsech ridicich bodu ve vertikalnim smeru
 */
void initControlPointsUp(S_Vector** points, int offset_x, int offset_y) {
	*points = vecCreateEmpty(sizeof(Point2d));
	Point2d p;
	p.x = 0;   p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 40;  p.y = -250; point2d_vecPushBack(*points, p);
	p.x = 160; p.y = -250; point2d_vecPushBack(*points, p);

	p.x = 200; p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 210; p.y = -180; point2d_vecPushBack(*points, p);
	p.x = 350; p.y = -180; point2d_vecPushBack(*points, p);

	p.x = 360; p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 390; p.y = -120;  point2d_vecPushBack(*points, p);
	p.x = 430; p.y = -120;  point2d_vecPushBack(*points, p);

	p.x = 460; p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 470; p.y = -70;  point2d_vecPushBack(*points, p);
	p.x = 525; p.y = -70;  point2d_vecPushBack(*points, p);

	p.x = 535; p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 545; p.y = -40;  point2d_vecPushBack(*points, p);
	p.x = 575; p.y = -40;  point2d_vecPushBack(*points, p);

	p.x = 585; p.y = 0;    point2d_vecPushBack(*points, p);

	Point2d offset = { static_cast<double>(offset_x), static_cast<double>(offset_y), 1.0 };
	for (int i = 0; i < (*points)->size; i++) {
		addPoint2d(point2d_vecGetPtr(*points, i), &offset, point2d_vecGetPtr(*points, i));
	}
}

void initControlPointsDown(S_Vector** points, int offset_x, int offset_y) {
	/* == TODO ==
	 * Uloha c.2
	 * Nasledujuci volanni funkce initControlPointsUp(.) zmazte a nahradte vlastnim kodem,
	 * ktery inicializuje ridici body tak, aby byla trajektorie spojita (C1). Muzete zkopirovat
	 * kod funkce initControlPointsUp(.) a upravit primo souradnice bodu v kodu. 
         * POCITEJTE S -Y SOURADNICEMI RIDICICH BODU A MENTE JEJICH X SLOĹ˝KU!
	 */

	*points = vecCreateEmpty(sizeof(Point2d));
	Point2d p;
	p.x = 0;   p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 40;  p.y = -250; point2d_vecPushBack(*points, p);
	p.x = 160; p.y = -250; point2d_vecPushBack(*points, p);

	p.x = 200; p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 228/*210*/; p.y = 180; point2d_vecPushBack(*points, p);
	p.x = 315/*350*/; p.y = 180; point2d_vecPushBack(*points, p);		//0 = 200k + q     180 = 210k + q     -180 = 10k    k = -18

	p.x = 360; p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 390; p.y = -120;  point2d_vecPushBack(*points, p);
	p.x = 430; p.y = -120;  point2d_vecPushBack(*points, p);

	p.x = 460; p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 477/*470*/; p.y = 70;  point2d_vecPushBack(*points, p);
	p.x = 527/*525*/; p.y = 70;  point2d_vecPushBack(*points, p);

	p.x = 535; p.y = 0;    point2d_vecPushBack(*points, p);

	p.x = 545; p.y = -40;  point2d_vecPushBack(*points, p);
	p.x = 575; p.y = -40;  point2d_vecPushBack(*points, p);

	p.x = 585; p.y = 0;    point2d_vecPushBack(*points, p);

	Point2d offset = { static_cast<double>(offset_x), static_cast<double>(offset_y), 1.0 };
	for (int i = 0; i < (*points)->size; i++) {
		addPoint2d(point2d_vecGetPtr(*points, i), &offset, point2d_vecGetPtr(*points, i));
	}
	//initControlPointsUp(points, offset_x, offset_y);
}

/**
 * Implementace vypoctu Bezierove kubiky.
 * @param P1,P2,P3,P4 ridici body kubiky
 * @param precision pocet bodu na krivke, ktere chceme vypocitat
 * @param trajectory_points vystupni vektor bodu kubiky (nemazat, jen pridavat body)
 */
void bezierCubic(const Point2d* P1, const Point2d* P2, const Point2d* P3, const Point2d* P4,
	const int precision, S_Vector* trajectory_points) {

	/* == TODO ==
	 * Soucast Ulohy c.1:
	 * Sem pridejte kod vypoctu Bezierove kubiky. Body krivky pridavejte do trajectory_points.
	 */
	Point2d point;

	for (double i = 0; i < 1; i += 1.0 / precision)
	{
		double b_03 = pow(1 - i, 3);
		double b_13 = 3 * i * pow(1 - i, 2);
		double b_23 = 3 * i * i * (1 - i);
		double b_33 = i * i * i;

		point.weight = 1.0;
		point.x = P1->x * b_03 + P2->x * b_13 + P3->x * b_23 + P4->x * b_33;
		point.y = P1->y * b_03 + P2->y * b_13 + P3->y * b_23 + P4->y * b_33;

		point2d_vecPushBack(trajectory_points, point);
	}


}

/*
 * Implementace vypoctu trajektorie, ktera se sklada z Bezierovych kubik.
 * @param precision pocet bodu krivky, ktere mame urcit
 * @param control_points ridici body krivky
 * @param trajectory_points vystupni body zakrivene trajektorie
 */
void	bezierCubicsTrajectory(int precision, const S_Vector* control_points, S_Vector* trajectory_points) {
	// Toto musi byt na zacatku funkce, nemazat.
	point2d_vecClean(trajectory_points);

	/* == TODO ==
	 * Uloha c.1
	 * Ziskejte postupne 4 ridici body a pro kazdou ctverici vypocitejte body Bezierovy kubiky.
	 *
	 * Kostra:
	 *  for(...; ...; ...) {
	 *    Point2d *P1 = ...
	 *    Point2d *P2 = ...
	 *    Point2d *P3 = ...
	 *    Point2d *P4 = ...
	 *    bezierCubic(P1, P2, P3, P4, precision, trajectory_points);
	 *  }
	 * Nasledujici volani funkce getLinePoints(.) zmazte - je to jen ilustrace hranate trajektorie.
	 */
	for (int i = 0; i + 3 < point2d_vecSize(control_points);) {
		Point2d* P1 = point2d_vecGetPtr(control_points, i++);
		Point2d* P2 = point2d_vecGetPtr(control_points, i++);
		Point2d* P3 = point2d_vecGetPtr(control_points, i++);
		Point2d* P4 = point2d_vecGetPtr(control_points, i);
		bezierCubic(P1, P2, P3, P4, precision, trajectory_points);
	}

	//getLinePoints(control_points, trajectory_points);
}