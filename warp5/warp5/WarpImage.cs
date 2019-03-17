using System;
using System.Collections.Generic;
using System.Text;

namespace warp5
{
    class WarpImage<T>
    {
        private Coord RA;       // object RA (Right Ascention)
        private Coord DEC;      //object Dec (declination)
        private uint width;     //image width
        private uint height;    //image height
        private string oName;   //object name
        private string notes;   //fits notes
        private T[][] data;     //image data
    }
}
