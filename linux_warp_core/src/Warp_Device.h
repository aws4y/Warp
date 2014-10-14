#ifndef WARP_DEVICE_H
#define WARP_DEVICE_H
#include <vector>
#include <string>
using namespace std;

class  WarpDevice
{
private:
    vector <string> metaData;
public:
    string * returnMetadata();
};


#endif