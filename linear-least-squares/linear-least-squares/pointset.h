#ifndef POINT_SET
#define POINT_SET

typedef struct
{
	double x;
	double y;
}point;

class Pointset
{
private:
	int count;
	point *points;
public:
	Pointset();
	Pointset(int);
	Pointset(int, double[][]);
	Pointset(Pointset &);
	int get_count();
};

#endif
