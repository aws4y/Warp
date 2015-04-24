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
	Poinset();
	Pointset(int);
	Pointset(Pointset &);
	int get_count();
};

#endif
