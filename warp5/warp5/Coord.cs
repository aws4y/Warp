using System;
using System.Collections.Generic;
using System.Text;

namespace warp5
{
    class Coord
    {
        private int hr;
        private int deg;
        private int min;
        private double sec;
        bool raType;              //raType true means use hrs instead of degrees
        //create a cordinate set to 0:0:0.00
        public Coord()
        {
            hr = 0;
            deg = 0;
            min = 0;
            sec = 0.0;
            raType = false;
        }
        //create coordinate with user input deg/hr and min sec set to 0.0
        public Coord(int uDeg, int uMin, bool uRaType)
        {
            if(uRaType)
            {
                hr = uDeg;
            }
            else
            {
                deg = uDeg;
            }
            min = uMin;
            raType = uRaType;
            sec = 0.0;
        }
        public Coord(int uDeg, int uMin, double uSec ,bool uRaType)
        {
            if (uRaType)
            {
                hr = uDeg;
            }
            else
            {
                deg = uDeg;
            }
            min = uMin;
            raType = uRaType;
            sec = uSec;
        }
    }
}
